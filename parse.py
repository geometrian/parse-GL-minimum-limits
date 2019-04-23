import sys


versions = [
    (2,0), (2,1),
    (3,0), (3,1), (3,2), (3,3),
    (4,0), (4,1), (4,2), (4,3), (4,4), (4,5), (4,6)
]
versions_str = "2.0,2.1, 3.0,3.1,3.2,3.3, 4.0,4.1,4.2,4.3,4.4,4.5,4.6"
versions_count = "2+4+7"


constants = {}

class Constant(object):
    def __init__(self, param, T,get):
        assert len(param) > 2
        self.param = param
        self.T = T
        self.get = get
        self.minvals = [None]*len(versions)
    def _get_index(self, major,minor):
        index = 0
        for version in versions:
            if version[0]==major and version[1]==minor:
                return index
            index += 1
        assert False
    def get_value(self, major,minor):
        index = self._get_index(major,minor)
        return self.minvals[index]
    def update(self, major,minor, minval):
        if type(minval)==type(""):
            assert minval is not "–"
            assert minval[-1] != "\n"

        index = self._get_index(major,minor)
        if self.minvals[index] == None:
            self.minvals[index] = minval
        else:
            #This can happen; e.g. `GL_MAX_VERTEX_UNIFORM_COMPONENTS` is specified twice in GL 3.1; once as a footnote that gets misparsed as `1`.
            self.minvals[index] = max([minval,self.minvals[index]])
    def combine_with(self, other):
        for i in range(len(self.minvals)):
##            try:
            assert self.minvals[i]==None or other.minvals[i]==None
##            except:
##                print(self.param)
##                raise
            if self.minvals[i] == None:
                self.minvals[i] = other.minvals[i]
    def set_defaults_c(self):
        for i in range(len(const.minvals)):
            if const.minvals[i] == None:
                if   self.T=="B": s="B"
                elif self.T=="E": s="E"
                elif self.T in ["R","R+"]: s="F"
                elif self.T in ["Z","Z+","0*×Z+"]: s="I"
                elif self.T=="2×Z+": s="{I,I}"
                elif self.T=="3×Z+": s="{I,I,I}"
                elif self.T in ["2×R","2×R+"]:
                    if i<7: s="{F,   F   }"
                    else:   s="{F,        F       }"
                else:
                    print(self.T)
                    assert False
                const.minvals[i] = s
    def output(self, file):
        s = self.param + " "*(48-len(self.param)) + " (" + self.T + " " + self.get + "):" + " "*(37-len(self.T+self.get)) + " {   "+\
            str(self.minvals[0])+","+str(self.minvals[1])+",   "+\
            str(self.minvals[2])+","+str(self.minvals[3])+","+str(self.minvals[4])+","+str(self.minvals[5])+",   "+\
            str(self.minvals[6])+","+str(self.minvals[7])+","+str(self.minvals[8])+","+str(self.minvals[9])+","+str(self.minvals[10])+","+str(self.minvals[11])+\
        "   }"
        print(s,file=file)
    def output_c_getws(self):
        l = [len(self.param)]
        for minval in self.minvals:
            l.append(len(minval))
        return l
    def output_c(self, file, ls, with_comma):
        s = "\t{ "+self.param+","+" "*(ls[0]-len(self.param))+" {   "
        for i in range(len(self.minvals)):
            s += self.minvals[i]
            s += ","
            s += " "*(ls[1+i]-len(self.minvals[i]))
            if i in [1,5]: s+="   "
        s = s[:-1] + "   } }"
        if with_comma: s+=","
        print(s,file=file)

def load(major,minor):
    #Load file
    file = open("gl"+str(major)+"."+str(minor)+".txt","rb")
    data = file.read()
    data = data.decode("utf-8")
    file.close()

    #Get the relevant lines
    lines = []
    for line in data.split("\n"):
        if "Get" in line:
            #   Replace awful characters with better ones along the way
            line = line.strip() #in-particular, for "\r".
            line = line.replace("\x02","×")
            line = line.replace("\x03","*")
            line = line.replace("–","-")
            line = line.replace("GetIntegeri v","GetIntegeri_v")
            line = line.replace("GetFramebufferParameteri ","GetFramebufferParameteriv ") #This appears to be a typo; the function doesn't exist
            line = line.replace("GetInteger ","GetIntegerv ") #This appears to be a typo; the function doesn't exist
            line = line.replace("232","0xFFFFFFFF")#"232 \xF4\x80\x80\x80 1","0xFFFFFFFF")
            line = line.replace("1024 (x, y), 64 (z)","{1024,1024,64}")
            line = line.replace("Z16*","Z")
            line = line.replace("18 * ×Z+","Z")
            line = line.replace("0 * ×Z+","Z")
            line = line.replace("Z2","Z")
            line = line.replace("256y","256")
            lines.append(line)

    #Get the constants
    for temp in lines:
        tokens = temp.split(" ")

        #   Parse the parameter
        if tokens[0] == "-":
            #       Empty parameter means I don't care
##            param = "-"
##            tokens = tokens[1:]
            continue
        else:
            #       Parse the parameter (e.g. "GL_READ_BUFFER")
            param = "GL"
            while tokens[0].isupper() or tokens[0].endswith("i"):
                if tokens[0] in ["B","E","R","R+","S","Z","Z4","Z16","Z+"]: break
                param += "_" + tokens[0]
                tokens = tokens[1:]
            try:
                assert len(param) > 2 #If fails, probably means copy+paste had a "Get Value" that spans more than one line.  See docs.
            except:
                print(temp)
                raise
        #   Remove optional parenthetical string; some params seem to have one to indicate ancient versions of them.
        for i in range(0,len(tokens),1):
            if "(" in tokens[i]:
                for j in range(i+1,len(tokens),1):
                    if ")" in tokens[j]:
                        tokens = tokens[:i] + tokens[j+1:]
                        break
                break
        #   Concatenate dimensions, which may have gotten split
        while len(tokens) >= 3 and tokens[1] in ["×","*"]:
            tokens = [tokens[0]+tokens[1]+tokens[2]] + tokens[3:]
        #   Constant information
        T = tokens[0]
        get = tokens[1][3:]
        minval = tokens[2]
        #   Remove stuff we don't care about
        #       No defined minimum.  TODO: define based on type, if possible
        if   minval == "-": continue
        #       No defined minimum.  TODO: define based on type, if possible
        elif minval == "N/A" and param=="GL_PROGRAM_BINARY_FORMATS": continue
        #       I don't know what these parameters mean, and I don't think they're important
        elif param.startswith("GL_TEXTURE_BINDING_"): continue
        #       Supposed to be calculated from something else
        elif minval == "y" and param in [
            "GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS",
            "GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS",
            "GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS",
            "GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS",
            "GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS",
            "GL_IMPLEMENTATION_COLOR_READ_FORMAT",
            "GL_IMPLEMENTATION_COLOR_READ_TYPE",
            "GL_SAMPLES"
        ]: continue
        elif minval=="*" and param=="GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS": continue
        elif minval in ["see","See"]: continue
        elif param == "GL_MAX_SHADER_STORAGE_BLOCK_SIZE":
            if   minval=="224": minval="1<<24"
            elif minval=="227": minval="1<<27"
        #   Fix/Update values
        if   minval in ["NONE","FALSE","TRUE","RGBA","UNSIGNED_BYTE"]: minval="GL_"+minval
        elif param=="GL_VIEWPORT_BOUNDS_RANGE": minval="{-32768.0f,32767.0f}"
        elif param=="GL_MAX_CONVOLUTION_HEIGHT": minval="{3,3}"
        elif param=="GL_MAX_CONVOLUTION_WIDTH": minval="{3,3,3}" #Yes, it seems weird to me too that this is 3D.
        elif param=="GL_MAX_COMPUTE_WORK_GROUP_COUNT": minval="{"+minval+","+minval+","+minval+"}"
        elif minval=="1,1":
            if major<4 or minor<1: minval="{1.0f,1.0f}"
            else:                  minval="{1.0f,     1.0f    }"
        elif minval=="{1024,1024,64}": minval="{ 1024, 1024,   64}"
        elif "." in minval: minval+="f"
        elif minval in ["8*","14*","70*","1+"]: minval=minval[:-1]
        elif minval.startswith("+"): minval=minval[1:]

        key = get+" "+T
        if key not in constants.keys():
            constants[key] = {}
        if param not in constants[key].keys():
            constants[key][param] = Constant(param,T,get)
        try:
            assert T==constants[key][param].T
            assert get==constants[key][param].get

            constants[key][param].update(major,minor, minval)
            #constants.append(Constant(param,[T,get,minval]))#+tokens[3:]))
        except:
            #print(T)
            print(get)
            print(minval)
            #print(constants[key][param].T)
            print(constants[key][param].get)
            print(constants[key][param].get_value(major,minor))
            constants[key][param].output()
            raise
        if key in [
            "String S",
            "Stringi n×S"
        ]:
            #Probably no "minimum" value will ever be provided, so assume it wasn't.
            del constants[key]

##        def get_s(s,max_len):
##            return "\""+s+"\"," + " "*(1+max_len-len(s))
##        s = get_s(param,49)
##        s += "["
##        s += get_s(tokens[0], 9)
##        s += get_s(tokens[1],35)
##        for token in tokens[2:]:
##            s += "\""+token+"\","
##        s = s[:-1]+"]"
##        print(s)
for major,minor in versions:
    print("Parsing %d.%d . . ."%(major,minor))
    load(major,minor)
print()

##f = sys.stdout
f = open("out-cpp.cpp","w")

#Combine keys with similar types for simplicity
def combine(keys_old, key_new):
    assert key_new not in constants
    constants[key_new] = {}
    for key_old in keys_old:
        if key_old in constants.keys():
            for const in constants[key_old].values():
                if const.param in constants[key_new].keys():
                    constants[key_new][const.param].combine_with(const)
                else:
                    constants[key_new][const.param] = const
            del constants[key_old]
    if len(constants[key_new]) == 0:
        del constants[key_new]
combine(["Floatv 2×R","Floatv 2×R+"], "Floatv 2r")
combine(["Floatv R","Floatv R+"], "Floatv r")
combine(
    ["FramebufferAttachmentParameteriv B","FramebufferAttachmentParameteriv E","FramebufferAttachmentParameteriv Z","FramebufferAttachmentParameteriv Z+"],
    "FramebufferAttachmentParameteriv i"
)
combine(["FramebufferParameteriv B","FramebufferParameteriv Z+"], "FramebufferParameteriv i")
combine(["Integerv E","Integerv Z","Integerv Z+"], "Integerv i")
combine(["Internalformativ 0*×Z+","Internalformativ Z","Internalformativ Z+"], "Internalformativ i")

#Fill empty slots with default values (for echoing C later; so optional)
for key in sorted(constants.keys()):
    for const in constants[key].values():
        const.set_defaults_c()

#Output internal representation; useful for checking/debugging
##for key in sorted(constants.keys()):
##    s = constants[key].values()
##    for const in sorted(s,key=lambda c:(c.T,c.param)):
##        const.output(f)
##    print(file=f)

#Output C-style arrays
info = {
    "Booleanv B"                         : ("boolean",         "Boolean",       "GLboolean vers["+versions_count+"]", "B"),
    "ConvolutionParameteriv 2×Z+"        : ("convparam2",      "ConvParam2",    "GLint vers["+versions_count+"][2]",  "I"),
    "ConvolutionParameteriv 3×Z+"        : ("convparam3",      "ConvParam3",    "GLint vers["+versions_count+"][3]",  "I"),
    "Floatv 2r"                          : ("float2",          "Float2",        "GLfloat vers["+versions_count+"][2]","F"),
    "Floatv r"                           : ("float",           "Float",         "GLfloat vers["+versions_count+"]",   "F"),
    "FramebufferAttachmentParameteriv i" : ("fbo_attach_param","FBOAttachParam","GLint vers["+versions_count+"]",     "I"),
    "FramebufferParameteriv i"           : ("fbo_param",       "FBOParam",      "GLint vers["+versions_count+"]",     "I"),
    "Integer64v Z+"                      : ("int64",           "Int64",         "GLint64 vers["+versions_count+"]",   "L"),
    "Integeri_v 3×Z+"                    : ("intv",            "Intv",          "GLint vers["+versions_count+"][3]",  "I"),
    "Integerv i"                         : ("int",             "Int",           "GLint vers["+versions_count+"]",     "I"), #But you should cast to `GLenum`
    "Internalformativ i"                 : ("intfmt",          "InternalFmt",   "GLint vers["+versions_count+"]",     "I")
}
print("""//Autogenerated file containing minimum values for certain OpenGL constants.  Values are given in arrays,
//	corresponding to OpenGL { """+versions_str+""" }.  See generator:
//	https://github.com/imallett/parse-GL-minimum-limits
""",file=f)
print("#define B false",file=f)
print("#define E GL_INVALID_ENUM",file=f)
print("#define F std::numeric_limits<GLfloat>::quiet_NaN()",file=f)
print("#define I std::numeric_limits<GLint  >::max      ()",file=f)
print("#define L std::numeric_limits<GLint64>::max      ()\n",file=f)
keys = sorted(constants.keys())
for key in keys:
    if key != keys[0]: print("};\n#endif\n",file=f)
    lowername = info[key][0]
    uppername = info[key][1]
    data      = info[key][2]
    default   = info[key][3]
    print("""#if 1\nstruct Limits"""+uppername+""" final { //`glGet"""+key.split(" ")[0]+"""(...)`
	GLenum param;
	"""+data+"; //GL "+versions_str+"""
} limits_"""+lowername+"""[] = {""",file=f)
    s = constants[key].values()
    consts = sorted(s,key=lambda c:(c.T,c.param))
    ls = [0] * (len(consts[0].minvals)+1)
    for const in consts:
        temp = const.output_c_getws()
        for i in range(len(consts[0].minvals)+1):
            ls[i] = max([ls[i],temp[i]])
    for const in consts:
        const.output_c(f,ls,const!=consts[-1])
print("};\n#endif\n\n#undef L",file=f)
print("#undef I",file=f)
print("#undef F",file=f)
print("#undef E",file=f)
print("#undef B",file=f)

if f != sys.stdout:
    f.close()
