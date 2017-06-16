# Test_parser #

Toy project to test the use of Boost program_options library and the build system generation with CMake.
This little program simply print in the terminal the parameters name and their value contained in param.ini.


## Use ##

### Generate the build system ###
Create a build directory, go in it and launch CMake with the path of the project as argument: 
``` sh
cd test_parser
mkdir build && cd build
cmake ..
```

### Build and Install ###
+ Visual Studio (Windows)

	Open the project and build the project ALL_BUILD first and then INSTALL. We encountered troubles with Windows 10 and Visual Studio 2015/2017 at building the INSTALL project, so you can do it this way too:
	``` sh
	cmake -P cmake_install.cmake
	```
	
+ Make (Unix)
``` sh
make .
make install
```

In both cases you should end with bin/, lib/ and include folders at the top-level of the project, containing respectively test_parser.exe, parser.lib and parser.h.

### Run ###
+ On Linux
``` sh
./bin/test_parser param.ini
```

+ On Windows
``` sh
bin\test_parser.exe param.ini
```