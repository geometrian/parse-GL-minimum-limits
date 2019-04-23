# parse-GL-minimum-limits

_Hacky parser and exporter for minimum values of implementation-defined constants in GL._

## Summary

I parsed the OpenGL specifications to generate [a cpp file](out-cpp.cpp) containing implementation-defined minimum values for various constants.  If you want to tweak it (good luck), the parser that generates it is [here](parse.py).

## Description

OpenGL has various implementation-defined constants that have minimum values.  Unfortunately, this information is buried within the OpenGL specifications in tables that are hard to find and copy from.  At any rate, they're not convenient.  Yet, it is sometimes necessary to expect at least a certain functionality from a given implementation and to know what must, at minimum, be supported.  Or maybe, your driver [lies](http://www.gamedev.net/topic/681636-my-properly-created-opengl-context-is-lying-to-me) to [you](http://stackoverflow.com/questions/28130349/glgetstring-returning-null-on-valid-linux-context-in-vm), and you can't depend on the driver giving you reliable values.

This project does all the hard work for you.  By hand, I painstakingly copied the tables that contain minimum values, from the following OpenGL specifications into the following raw files:

- [OpenGL 2.0](https://www.khronos.org/registry/OpenGL/specs/gl/glspec20.pdf) -> [gl2.0.txt](gl2.0.txt)
- [OpenGL 2.1](https://www.khronos.org/registry/OpenGL/specs/gl/glspec21.pdf) -> [gl2.1.txt](gl2.1.txt)
- [OpenGL 3.0](https://www.khronos.org/registry/OpenGL/specs/gl/glspec30.pdf) -> [gl3.0.txt](gl3.0.txt)
- [OpenGL 3.1](https://www.khronos.org/registry/OpenGL/specs/gl/glspec31.pdf) -> [gl3.1.txt](gl3.1.txt)
- [OpenGL 3.2](https://www.khronos.org/registry/OpenGL/specs/gl/glspec32.core.pdf) -> [gl3.2.txt](gl3.2.txt)
- [OpenGL 3.3](https://www.khronos.org/registry/OpenGL/specs/gl/glspec33.core.pdf) -> [gl3.3.txt](gl3.3.txt)
- [OpenGL 4.0](https://www.khronos.org/registry/OpenGL/specs/gl/glspec40.core.pdf) -> [gl4.0.txt](gl4.0.txt)
- [OpenGL 4.1](https://www.khronos.org/registry/OpenGL/specs/gl/glspec41.core.pdf) -> [gl4.1.txt](gl4.1.txt)
- [OpenGL 4.2](https://www.khronos.org/registry/OpenGL/specs/gl/glspec42.core.pdf) -> [gl4.2.txt](gl4.2.txt)
- [OpenGL 4.3](https://www.khronos.org/registry/OpenGL/specs/gl/glspec43.core.pdf) -> [gl4.3.txt](gl4.3.txt)
- [OpenGL 4.4](https://www.khronos.org/registry/OpenGL/specs/gl/glspec44.core.pdf) -> [gl4.4.txt](gl4.4.txt)
- [OpenGL 4.5](https://www.khronos.org/registry/OpenGL/specs/gl/glspec45.core.pdf) -> [gl4.5.txt](gl4.5.txt)
- [OpenGL 4.6](https://www.khronos.org/registry/OpenGL/specs/gl/glspec46.core.pdf) -> [gl4.6.txt](gl4.6.txt)

Many tables didn't copy over well from the PDFs, so I had to manually adjust/fix them.

From here, I wrote an extremely crufty purpose-built "parser" that operates on raw strings.  It gradually creates order from the chaos.  At the end, a raw representation of each constant along with minimums for each GL version is generated.

From here, the result can be copied into, say, [a cpp file](out-cpp.cpp) for easy use.  This will be the way most users will want to interact with this project.

## Contributing

Contributions are welcome!  The parser _mostly_ works and _mostly_ outputs sane data, yet there are still major areas where help is needed:

- More GL versions (in particular, add raw files for GLs 1.0, 1.1, 1.2, 1.2.1, 1.3, 1.4, and 1.5).  I didn't bother adding these, since they're probably irrelevant today--but doing so should be relatively easy for a newcomer if my experience with the other specifications is representative.
- A few constants are incorrectly parsed.  This happens when the "value" was actually a footnote.  The result is typically a small number, and later occurrences of the constant tend to give it a real, larger value.  So the results (probably?) aren't _very_ wrong.  But this still shouldn't happen.
- Support for more constants.  If the value is not easy to find, then the entire constant is ignored.  This is sortof bad.  For example, if the type is listed as "Z+", then we ought to be able to assume the value is at least 1, even if there's no other information in the specification at all.  As another example, some constants are defined in terms of other constants.  Figuring out the values for these would (only) require finding the minimum values of those dependencies and then doing the calculation.
- One might like to expand this project to handle initial values too, or perhaps other interesting information, like maximum value or notes given in the specifications.
- Code cleanup.  Boy does it need it.

If you'd rather help support development of similar projects, you can [donate](https://geometrian.com/).

## License

The parser is licensed under the MIT license.  The output is licensed under MIT or the public domain, whichever you prefer.  If you use this project, starring it will help me keep track of roughly how many people found it helpful!  Thanks!