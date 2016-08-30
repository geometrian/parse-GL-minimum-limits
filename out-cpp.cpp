#define B false
#define E GL_INVALID_ENUM
#define I std::numeric_limits<GLint>::max()
#define F std::numeric_limits<GLfloat>::quiet_NaN()
#define L std::numeric_limits<GLint64>::max()
struct LimitsBoolean final { //glGetBooleanv(...)
	GLenum param;
	GLboolean vers[2+4+6];
} limits_boolean[] = {
	{ GL_SHADER_COMPILER, {   B,B,   B,B,B,B,   B,B,B,B,B,GL_TRUE   } }
};
struct LimitsConvParam2 final { //glGetConvolutionParameteriv(...)
	GLenum param;
	GLint vers[2+4+6][2];
} limits_convparam2[] = {
	{ GL_MAX_CONVOLUTION_HEIGHT, {   {3,3},{3,3},   {3,3},{I,I},{I,I},{I,I},   {I,I},{I,I},{I,I},{I,I},{I,I},{I,I}   } }
};
struct LimitsConvParam3 final { //glGetConvolutionParameteriv(...)
	GLenum param;
	GLint vers[2+4+6][3];
} limits_convparam3[] = {
	{ GL_MAX_CONVOLUTION_WIDTH, {   {3,3,3},{3,3,3},   {3,3,3},{I,I,I},{I,I,I},{I,I,I},   {I,I,I},{I,I,I},{I,I,I},{I,I,I},{I,I,I},{I,I,I}   } }
};
struct LimitsFloat2 final { //glGetFloatv(...)
	GLenum param;
	GLfloat vers[2+4+6][2];
} limits_float2[] = {
	{ GL_VIEWPORT_BOUNDS_RANGE,    {   {   F,   F},{   F,   F},   {   F,   F},{   F,   F},{   F,   F},{   F,   F},   {   F,   F},{-32768.0f,32767.0f},{-32768.0f,32767.0f},{-32768.0f,32767.0f},{-32768.0f,32767.0f},{-32768.0f,32767.0f}   } },
	{ GL_ALIASED_LINE_WIDTH_RANGE, {   {1.0f,1.0f},{1.0f,1.0f},   {1.0f,1.0f},{1.0f,1.0f},{1.0f,1.0f},{1.0f,1.0f},   {1.0f,1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f}   } },
	{ GL_ALIASED_POINT_SIZE_RANGE, {   {1.0f,1.0f},{1.0f,1.0f},   {1.0f,1.0f},{   F,   F},{   F,   F},{   F,   F},   {   F,   F},{        F,       F},{        F,       F},{        F,       F},{        F,       F},{        F,       F}   } },
	{ GL_POINT_SIZE_RANGE,         {   {   F,   F},{   F,   F},   {   F,   F},{1.0f,1.0f},{1.0f,1.0f},{1.0f,1.0f},   {1.0f,1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f}   } },
	{ GL_SMOOTH_LINE_WIDTH_RANGE,  {   {1.0f,1.0f},{1.0f,1.0f},   {1.0f,1.0f},{1.0f,1.0f},{1.0f,1.0f},{1.0f,1.0f},   {1.0f,1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f},{     1.0f,    1.0f}   } },
	{ GL_SMOOTH_POINT_SIZE_RANGE,  {   {1.0f,1.0f},{1.0f,1.0f},   {1.0f,1.0f},{   F,   F},{   F,   F},{   F,   F},   {   F,   F},{        F,       F},{        F,       F},{        F,       F},{        F,       F},{        F,       F}   } }
};
struct LimitsFloat final { //glGetFloatv(...)
	GLenum param;
	GLfloat vers[2+4+6];
} limits_float[] = {
	{ GL_MAX_FRAGMENT_INTERPOLATION_OFFSET, {      F,   F,      F,   F,   F,   F,   +0.5f,+0.5f,+0.5f,+0.5f,+0.5f,+0.5f   } },
	{ GL_MIN_FRAGMENT_INTERPOLATION_OFFSET, {      F,   F,      F,   F,   F,   F,   -0.5f,-0.5f,-0.5f,-0.5f,-0.5f,-0.5f   } },
	{ GL_MAX_TEXTURE_LOD_BIAS,              {   2.0f,2.0f,   2.0f,2.0f,2.0f,2.0f,    2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f   } }
};
struct LimitsFBOAttachParam final { //glGetFramebufferAttachmentParameteriv(...)
	GLenum param;
	GLint vers[2+4+6];
} limits_fbo_attach_param[] = {
	{ GL_FRAMEBUFFER_ATTACHMENT_LAYERED,               {   B,B,   B,B,B,B,   B,B,B,B,GL_FALSE,GL_FALSE   } },
	{ GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE,           {   E,E,   E,E,E,E,   E,E,E,E, GL_NONE, GL_NONE   } },
	{ GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE, {   E,E,   E,E,E,E,   E,E,E,E, GL_NONE, GL_NONE   } },
	{ GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER,         {   I,I,   I,I,I,I,   I,I,I,I,       0,       0   } },
	{ GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME,           {   I,I,   I,I,I,I,   I,I,I,I,       0,       0   } },
	{ GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL,         {   I,I,   I,I,I,I,   I,I,I,I,       0,       0   } }
};
struct LimitsFBOParam final { //glGetFramebufferParameteriv(...)
	GLenum param;
	GLint vers[2+4+6];
} limits_fbo_param[] = {
	{ GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS, {   B,B,   B,B,B,B,   B,B,B,B,GL_FALSE,GL_FALSE   } },
	{ GL_FRAMEBUFFER_DEFAULT_HEIGHT,                 {   I,I,   I,I,I,I,   I,I,I,I,       0,       0   } },
	{ GL_FRAMEBUFFER_DEFAULT_LAYERS,                 {   I,I,   I,I,I,I,   I,I,I,I,       0,       0   } },
	{ GL_FRAMEBUFFER_DEFAULT_SAMPLES,                {   I,I,   I,I,I,I,   I,I,I,I,       0,       0   } },
	{ GL_FRAMEBUFFER_DEFAULT_WIDTH,                  {   I,I,   I,I,I,I,   I,I,I,I,       0,       0   } }
};
struct LimitsInt64 final { //glGetInteger64v(...)
	GLenum param;
	GLint64 vers[2+4+6];
} limits_int64[] = {
	{ GL_MAX_ELEMENT_INDEX,             {   I,I,   I,I,I,I,   I,I,I,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF   } },
	{ GL_MAX_SERVER_WAIT_TIMEOUT,       {   I,I,   I,I,0,0,   0,0,0,         0,         0,         0   } },
	{ GL_MAX_SHADER_STORAGE_BLOCK_SIZE, {   I,I,   I,I,I,I,   I,I,I,       224,       224,       227   } }
};
struct LimitsIntv final { //glGetIntegeri_v(...)
	GLenum param;
	GLint vers[2+4+6];
} limits_intv[] = {
	{ GL_MAX_COMPUTE_WORK_GROUP_COUNT, {   {I,I,I},{I,I,I},   {I,I,I},{I,I,I},{I,I,I},{I,I,I},   {I,I,I},{I,I,I},{I,I,I},{65535,65535,65535},{65535,65535,65535},{65535,65535,65535}   } },
	{ GL_MAX_COMPUTE_WORK_GROUP_SIZE,  {   {I,I,I},{I,I,I},   {I,I,I},{I,I,I},{I,I,I},{I,I,I},   {I,I,I},{I,I,I},{I,I,I},{ 1024, 1024,   64},{ 1024, 1024,   64},{ 1024, 1024,   64}   } }
};
struct LimitsInt final { //glGetIntegerv(...)
	GLenum param;
	GLint vers[2+4+6];
} limits_int[] = {
	{ GL_IMPLEMENTATION_COLOR_READ_FORMAT,              {     E,  E,      E,    E,    E,    E,       E,    E,    E,         GL_RGBA,         GL_RGBA,    E   } },
	{ GL_IMPLEMENTATION_COLOR_READ_TYPE,                {     E,  E,      E,    E,    E,    E,       E,    E,    E,GL_UNSIGNED_BYTE,GL_UNSIGNED_BYTE,    E   } },
	{ GL_MAX_IMAGE_SAMPLES,                             {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_PROGRAM_TEXEL_OFFSET,                      {     I,  I,      7,    7,    7,    7,       7,    7,    7,               7,               7,    7   } },
	{ GL_MAX_VERTEX_ATTRIB_BINDINGS,                    {     I,  I,      I,    I,    I,    I,       I,    I,    I,              16,              16,   16   } },
	{ GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET,             {     I,  I,      I,    I,    I,    I,       I,    I,    I,            2047,            2047, 2047   } },
	{ GL_MAX_VERTEX_ATTRIB_STRIDE,                      {     I,  I,      I,    I,    I,    I,       I,    I,    I,               I,            2048, 2048   } },
	{ GL_MIN_PROGRAM_TEXEL_OFFSET,                      {     I,  I,     -8,   -8,   -8,   -8,      -8,   -8,   -8,              -8,              -8,   -8   } },
	{ GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET,             {     I,  I,      I,    I,    I,    I,      -8,   -8,   -8,              -8,              -8,   -8   } },
	{ GL_NUM_COMPRESSED_TEXTURE_FORMATS,                {     0,  0,      0,    4,    4,    4,       4,    4,    0,               0,              18,   18   } },
	{ GL_NUM_PROGRAM_BINARY_FORMATS,                    {     I,  I,      I,    I,    I,    I,       I,    0,    0,               0,               0,    0   } },
	{ GL_SAMPLE_BUFFERS,                                {     0,  0,      0,    0,    0,    0,       0,    0,    0,               0,               0,    0   } },
	{ GL_AUX_BUFFERS,                                   {     0,  0,      0,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_FRAGMENT_INTERPOLATION_OFFSET_BITS,            {     I,  I,      I,    I,    I,    I,       4,    4,    4,               4,               4,    4   } },
	{ GL_MAJOR_VERSION,                                 {     I,  I,      I,    I,    3,    3,       3,    3,    I,               I,               I,    I   } },
	{ GL_MAX_3D_TEXTURE_SIZE,                           {    16, 16,    256,  256,  256,  256,     256, 2048, 2048,            2048,            2048, 2048   } },
	{ GL_MAX_ARRAY_TEXTURE_LAYERS,                      {     I,  I,    256,  256,  256,  256,     256, 2048, 2048,            2048,            2048, 2048   } },
	{ GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS,            {     I,  I,      I,    I,    I,    I,       I,    I,    1,               1,               1,    1   } },
	{ GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE,                {     I,  I,      I,    I,    I,    I,       I,    I,   32,              32,              32,   32   } },
	{ GL_MAX_ATTRIB_STACK_DEPTH,                        {    16, 16,     16,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_CLIENT_ATTRIB_STACK_DEPTH,                 {    16, 16,     16,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_CLIP_DISTANCES,                            {     I,  I,      I,    6,    8,    8,       8,    8,    8,               8,               8,    8   } },
	{ GL_MAX_CLIP_PLANES,                               {     6,  6,      6,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_COLOR_ATTACHMENTS,                         {     I,  I,      8,    8,    8,    8,       8,    8,    8,               8,               8,    8   } },
	{ GL_MAX_COLOR_MATRIX_STACK_DEPTH,                  {     2,  2,      2,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_COLOR_TEXTURE_SAMPLES,                     {     I,  I,      I,    I,    1,    1,       1,    1,    1,               1,               1,    1   } },
	{ GL_MAX_COMBINED_ATOMIC_COUNTERS,                  {     I,  I,      I,    I,    I,    I,       I,    I,    8,               8,               8,    8   } },
	{ GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS,           {     I,  I,      I,    I,    I,    I,       I,    I,    1,               1,               1,    1   } },
	{ GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES,          {     I,  I,      I,    I,    I,    I,       I,    I,    I,               I,               I,    8   } },
	{ GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS,      {     I,  I,      I,    1,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_COMBINED_IMAGE_UNIFORMS,                   {     I,  I,      I,    I,    I,    I,       I,    I,    8,               8,               8,    8   } },
	{ GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS, {     I,  I,      I,    I,    I,    I,       I,    I,    8,               I,               I,    I   } },
	{ GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES,          {     I,  I,      I,    I,    I,    I,       I,    I,    I,               8,               8,    8   } },
	{ GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS,            {     I,  I,      I,    I,    I,    I,       I,    I,    I,               8,               8,    8   } },
	{ GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,              {     2,  2,     16,   32,   48,   48,      80,   80,   80,              96,              80,   80   } },
	{ GL_MAX_COMBINED_UNIFORM_BLOCKS,                   {     I,  I,      I,   24,   24,   36,      60,   60,   60,              70,              70,   70   } },
	{ GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS,        {     I,  I,      I,    1,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_COMPUTE_ATOMIC_COUNTERS,                   {     I,  I,      I,    I,    I,    I,       I,    I,    I,               8,               8,    8   } },
	{ GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS,            {     I,  I,      I,    I,    I,    I,       I,    I,    I,               8,               8,    8   } },
	{ GL_MAX_COMPUTE_IMAGE_UNIFORMS,                    {     I,  I,      I,    I,    I,    I,       I,    I,    I,               8,               8,    8   } },
	{ GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS,             {     I,  I,      I,    I,    I,    I,       I,    I,    I,               8,               8,    8   } },
	{ GL_MAX_COMPUTE_SHARED_MEMORY_SIZE,                {     I,  I,      I,    I,    I,    I,       I,    I,    I,           32768,           32768,32768   } },
	{ GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS,               {     I,  I,      I,    I,    I,    I,       I,    I,    I,              16,              16,   16   } },
	{ GL_MAX_COMPUTE_UNIFORM_BLOCKS,                    {     I,  I,      I,    I,    I,    I,       I,    I,    I,              14,              14,   14   } },
	{ GL_MAX_COMPUTE_UNIFORM_COMPONENTS,                {     I,  I,      I,    I,    I,    I,       I,    I,    I,             512,             512, 1024   } },
	{ GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS,            {     I,  I,      I,    I,    I,    I,       I,    I,    I,            1024,            1024, 1024   } },
	{ GL_MAX_CUBE_MAP_TEXTURE_SIZE,                     {    16, 16,   1024, 1024, 1024, 1024,    1024,16384,16384,           16384,           16384,16384   } },
	{ GL_MAX_CULL_DISTANCES,                            {     I,  I,      I,    I,    I,    I,       I,    I,    I,               I,               I,    8   } },
	{ GL_MAX_DEBUG_GROUP_STACK_DEPTH,                   {     I,  I,      I,    I,    I,    I,       I,    I,    I,              64,              64,   64   } },
	{ GL_MAX_DEBUG_LOGGED_MESSAGES,                     {     I,  I,      I,    I,    I,    I,       I,    I,    I,               1,               1,    1   } },
	{ GL_MAX_DEBUG_MESSAGE_LENGTH,                      {     I,  I,      I,    I,    I,    I,       I,    I,    I,               1,               1,    1   } },
	{ GL_MAX_DEPTH_TEXTURE_SAMPLES,                     {     I,  I,      I,    I,    1,    1,       1,    1,    1,               1,               1,    1   } },
	{ GL_MAX_DRAW_BUFFERS,                              {     1,  1,      8,    8,    8,    8,       8,    8,    8,               8,               8,    8   } },
	{ GL_MAX_DUAL_SOURCE_DRAW_BUFFERS,                  {     I,  I,      I,    I,    I,    1,       1,    1,    1,               1,               1,    1   } },
	{ GL_MAX_EVAL_ORDER,                                {     8,  8,      8,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_FRAGMENT_ATOMIC_COUNTERS,                  {     I,  I,      I,    I,    I,    I,       I,    I,    8,               8,               8,    8   } },
	{ GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS,           {     I,  I,      I,    I,    I,    I,       I,    I,    1,               1,               1,    1   } },
	{ GL_MAX_FRAGMENT_IMAGE_UNIFORMS,                   {     I,  I,      I,    I,    I,    I,       I,    I,    8,               8,               8,    8   } },
	{ GL_MAX_FRAGMENT_INPUT_COMPONENTS,                 {     I,  I,      I,    I,  128,  128,     128,  128,  128,             128,             128,  128   } },
	{ GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS,            {     I,  I,      I,    I,    I,    I,       I,    I,    I,               8,               8,    8   } },
	{ GL_MAX_FRAGMENT_UNIFORM_BLOCKS,                   {     I,  I,      I,   12,   12,   12,      12,   12,   12,              14,              14,   14   } },
	{ GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,               {    64, 64,   1024, 1024, 1024, 1024,    1024, 1024, 1024,            1024,            1024, 1024   } },
	{ GL_MAX_FRAGMENT_UNIFORM_VECTORS,                  {     I,  I,      I,    I,    I,    I,       I,  256,  256,             256,             256,  256   } },
	{ GL_MAX_FRAMEBUFFER_HEIGHT,                        {     I,  I,      I,    I,    I,    I,       I,    I,    I,               I,           16384,16384   } },
	{ GL_MAX_FRAMEBUFFER_LAYERS,                        {     I,  I,      I,    I,    I,    I,       I,    I,    I,               I,            2048, 2048   } },
	{ GL_MAX_FRAMEBUFFER_SAMPLES,                       {     I,  I,      I,    I,    I,    I,       I,    I,    I,               I,               4,    4   } },
	{ GL_MAX_FRAMEBUFFER_WIDTH,                         {     I,  I,      I,    I,    I,    I,       I,    I,    I,               I,           16384,16384   } },
	{ GL_MAX_GEOMETRY_ATOMIC_COUNTERS,                  {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS,           {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_GEOMETRY_IMAGE_UNIFORMS,                   {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_GEOMETRY_INPUT_COMPONENTS,                 {     I,  I,      I,    I,   64,   64,      64,   64,   64,              64,              64,   64   } },
	{ GL_MAX_GEOMETRY_OUTPUT_COMPONENTS,                {     I,  I,      I,    I,  128,  128,     128,  128,  128,             128,             128,  128   } },
	{ GL_MAX_GEOMETRY_OUTPUT_VERTICES,                  {     I,  I,      I,    I,  256,  256,     256,  256,  256,             256,             256,  256   } },
	{ GL_MAX_GEOMETRY_SHADER_INVOCATIONS,               {     I,  I,      I,    I,    I,    I,      32,   32,   32,              32,              32,   32   } },
	{ GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS,            {     I,  I,      I,    I,    I,    I,       I,    I,    I,               0,               0,    0   } },
	{ GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS,              {     I,  I,      I,    I,   16,   16,      16,   16,   16,              16,              16,   16   } },
	{ GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS,          {     I,  I,      I,    I, 1024, 1024,    1024, 1024, 1024,            1024,            1024, 1024   } },
	{ GL_MAX_GEOMETRY_UNIFORM_BLOCKS,                   {     I,  I,      I,    I,   12,   12,      12,   12,   12,              14,              14,   14   } },
	{ GL_MAX_GEOMETRY_UNIFORM_COMPONENTS,               {     I,  I,      I,    I,    I,    I,       I,    I,  512,             512,             512, 1024   } },
	{ GL_MAX_IMAGE_UNITS,                               {     I,  I,      I,    I,    I,    I,       I,    I,    8,               8,               8,    8   } },
	{ GL_MAX_INTEGER_SAMPLES,                           {     I,  I,      I,    I,    1,    1,       1,    1,    1,               1,               1,    1   } },
	{ GL_MAX_LABEL_LENGTH,                              {     I,  I,      I,    I,    I,    I,       I,    I,    I,             256,             256,  256   } },
	{ GL_MAX_LIGHTS,                                    {     8,  8,      8,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_LIST_NESTING,                              {    64, 64,     64,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_MODELVIEW_STACK_DEPTH,                     {    32, 32,     32,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_NAME_STACK_DEPTH,                          {    64, 64,     64,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_PATCH_VERTICES,                            {     I,  I,      I,    I,    I,    I,      32,   32,   32,              32,              32,   32   } },
	{ GL_MAX_PIXEL_MAP_TABLE,                           {    32, 32,     32,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET,             {     I,  I,      I,    I,    I,    I,       7,    7,    7,               7,               7,    7   } },
	{ GL_MAX_PROJECTION_STACK_DEPTH,                    {     2,  2,      2,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_RECTANGLE_TEXTURE_SIZE,                    {     I,  I,      I, 1024, 1024, 1024,    1024,16384,16384,           16384,           16384,16384   } },
	{ GL_MAX_RENDERBUFFER_SIZE,                         {     I,  I,   1024, 1024, 1024, 1024,    1024,16384,16384,           16384,           16384,16384   } },
	{ GL_MAX_SAMPLES,                                   {     I,  I,      4,    4,    4,    4,       4,    4,    4,               4,               4,    4   } },
	{ GL_MAX_SAMPLE_MASK_WORDS,                         {     I,  I,      I,    I,    1,    1,       1,    1,    1,               1,               1,    1   } },
	{ GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS,            {     I,  I,      I,    I,    I,    I,       I,    I,    I,               8,               8,    8   } },
	{ GL_MAX_SUBROUTINES,                               {     I,  I,      I,    I,    I,    I,     256,  256,  256,             256,             256,  256   } },
	{ GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS,              {     I,  I,      I,    I,    I,    I,    1024, 1024, 1024,            1024,            1024, 1024   } },
	{ GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS,              {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS,       {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS,               {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_TESS_CONTROL_INPUT_COMPONENTS,             {     I,  I,      I,    I,    I,    I,     128,  128,  128,             128,             128,  128   } },
	{ GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS,            {     I,  I,      I,    I,    I,    I,     128,  128,  128,             128,             128,  128   } },
	{ GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS,        {     I,  I,      I,    I,    I,    I,       I,    I,    I,               0,               0,    0   } },
	{ GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS,          {     I,  I,      I,    I,    I,    I,      16,   16,   16,              16,              16,   16   } },
	{ GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS,      {     I,  I,      I,    I,    I,    I,    4096, 4096, 4096,            4096,            4096, 4096   } },
	{ GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS,               {     I,  I,      I,    I,    I,    I,      12,   12,   12,              14,              14,   14   } },
	{ GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS,           {     I,  I,      I,    I,    I,    I,    1024, 1024, 1024,            1024,            1024, 1024   } },
	{ GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS,           {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS,    {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS,            {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS,          {     I,  I,      I,    I,    I,    I,     128,  128,  128,             128,             128,  128   } },
	{ GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS,         {     I,  I,      I,    I,    I,    I,     128,  128,  128,             128,             128,  128   } },
	{ GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS,     {     I,  I,      I,    I,    I,    I,       I,    I,    I,               0,               0,    0   } },
	{ GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS,       {     I,  I,      I,    I,    I,    I,      16,   16,   16,              16,              16,   16   } },
	{ GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS,            {     I,  I,      I,    I,    I,    I,      12,   12,   12,              14,              14,   14   } },
	{ GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS,        {     I,  I,      I,    I,    I,    I,    1024, 1024, 1024,            1024,            1024, 1024   } },
	{ GL_MAX_TESS_GEN_LEVEL,                            {     I,  I,      I,    I,    I,    I,      64,   64,   64,              64,              64,   64   } },
	{ GL_MAX_TESS_PATCH_COMPONENTS,                     {     I,  I,      I,    I,    I,    I,     120,  120,  120,             120,             120,  120   } },
	{ GL_MAX_TEXTURE_BUFFER_SIZE,                       {     I,  I,      I,65536,65536,65536,   65536,65536,65536,           65536,           65536,65536   } },
	{ GL_MAX_TEXTURE_COORDS,                            {     2,  2,      8,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_TEXTURE_IMAGE_UNITS,                       {     2,  2,     16,   16,   16,   16,      16,   16,   16,              16,              16,   16   } },
	{ GL_MAX_TEXTURE_SIZE,                              {    64, 64,   1024, 1024, 1024, 1024,    1024,16384,16384,           16384,           16384,16384   } },
	{ GL_MAX_TEXTURE_STACK_DEPTH,                       {     2,  2,      2,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_TEXTURE_UNITS,                             {     2,  2,      2,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_TRANSFORM_FEEDBACK_BUFFERS,                {     I,  I,      I,    I,    I,    I,       4,    4,    4,               4,               4,    4   } },
	{ GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS, {     I,  I,      I,    I,    I,   64,      64,   64,   64,              64,              64,   64   } },
	{ GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS,       {     I,  I,      I,    I,    I,    4,       4,    4,    4,               4,               4,    4   } },
	{ GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS,    {     I,  I,      I,    I,    I,    4,       4,    4,    4,               4,               4,    4   } },
	{ GL_MAX_UNIFORM_BLOCK_SIZE,                        {     I,  I,      I,16384,16384,16384,   16384,16384,16384,           16384,           16384,16384   } },
	{ GL_MAX_UNIFORM_BUFFER_BINDINGS,                   {     I,  I,      I,   24,   24,   36,      60,   60,   60,              72,              84,   84   } },
	{ GL_MAX_UNIFORM_LOCATIONS,                         {     I,  I,      I,    I,    I,    I,       I,    I,    I,            1024,            1024, 1024   } },
	{ GL_MAX_VARYING_COMPONENTS,                        {     I,  I,     64,   64,   60,   60,      60,   60,   60,              60,              60,   60   } },
	{ GL_MAX_VARYING_FLOATS,                            {    32, 32,      I,    I,    I,    I,       I,    I,    I,               I,               I,    I   } },
	{ GL_MAX_VARYING_VECTORS,                           {     I,  I,      I,    I,    I,    I,       I,   15,   15,              15,              15,   15   } },
	{ GL_MAX_VERTEX_ATOMIC_COUNTERS,                    {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS,             {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_VERTEX_ATTRIBS,                            {    16, 16,     16,   16,   16,   16,      16,   16,   16,              16,              16,   16   } },
	{ GL_MAX_VERTEX_IMAGE_UNIFORMS,                     {     I,  I,      I,    I,    I,    I,       I,    I,    0,               0,               0,    0   } },
	{ GL_MAX_VERTEX_OUTPUT_COMPONENTS,                  {     I,  I,      I,    I,   64,   64,      64,   64,   64,              64,              64,   64   } },
	{ GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS,              {     I,  I,      I,    I,    I,    I,       I,    I,    I,               0,               0,    0   } },
	{ GL_MAX_VERTEX_STREAMS,                            {     I,  I,      I,    I,    I,    I,       4,    4,    4,               4,               4,    4   } },
	{ GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,                {     0,  0,     16,   16,   16,   16,      16,   16,   16,              16,              16,   16   } },
	{ GL_MAX_VERTEX_UNIFORM_BLOCKS,                     {     I,  I,      I,   12,   12,   12,      12,   12,   12,              14,              14,   14   } },
	{ GL_MAX_VERTEX_UNIFORM_COMPONENTS,                 {   512,512,   1024, 1024, 1024, 1024,    1024, 1024, 1024,            1024,            1024, 1024   } },
	{ GL_MAX_VERTEX_UNIFORM_VECTORS,                    {     I,  I,      I,    I,    I,    I,       I,  256,  256,             256,             256,  256   } },
	{ GL_MAX_VIEWPORTS,                                 {     I,  I,      I,    I,    I,    I,       I,   16,   16,              16,              16,   16   } },
	{ GL_MIN_MAP_BUFFER_ALIGNMENT,                      {     I,  I,      I,    I,    I,    I,       I,    I,   64,              64,              64,   64   } },
	{ GL_NUM_EXTENSIONS,                                {     I,  I,      I,    I,    I,    I,       I,    I,    I,               0,               0,    0   } },
	{ GL_NUM_SHADER_BINARY_FORMATS,                     {     I,  I,      I,    I,    I,    I,       I,    0,    0,               0,               0,    0   } },
	{ GL_NUM_SHADING_LANGUAGE_VERSIONS,                 {     I,  I,      I,    I,    I,    I,       I,    I,    I,               3,               3,    3   } },
	{ GL_SAMPLES,                                       {     0,  0,      0,    0,    0,    0,       0,    0,    0,               0,               0,    0   } },
	{ GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT,        {     I,  I,      I,    I,    I,    I,       I,    I,    I,             256,             256,  256   } },
	{ GL_SUBPIXEL_BITS,                                 {     4,  4,      4,    4,    4,    4,       4,    4,    4,               4,               4,    4   } },
	{ GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT,               {     I,  I,      I,    I,    I,    I,       I,    I,    I,               1,               1,  256   } },
	{ GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT,               {     I,  I,      I,    1,    1,    1,       1,    1,    1,               1,               1,  256   } },
	{ GL_VIEWPORT_SUBPIXEL_BITS,                        {     I,  I,      I,    I,    I,    I,       I,    0,    0,               0,               0,    0   } }
};
struct LimitsInternalFmt final { //glGetInternalformativ(...)
	GLenum param;
	GLint vers[2+4+6];
} limits_intfmt[] = {
	{ GL_SAMPLES,           {   I,I,   I,I,I,I,   I,I,1,I,I,I   } },
	{ GL_NUM_SAMPLE_COUNTS, {   I,I,   I,I,I,I,   I,I,1,1,1,1   } }
};
#undef L
#undef I
#undef F
#undef E
#undef B
