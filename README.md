# Engine Development Kit
A set of cross platform, low level tools and modules to build game engines from scratch!

## Why EDK?
EDK provides almost all the common tools required to build a fully functional game engine. It is true that you can use multiple third party libraries to build one, but when using the EDK,
- All of the modules and tools under one license.
- Seamless data sharing between modules.
- Ease the burden of updating and maintaining multiple libraries.

## Structure
The EDK is made up of multiple modules. Some of them are stand-alone but most of them depend one or more modules to operate. For example, Graphics Backend modules require the Core module for exception handling and so on. Each module is made up of headers and source files. 
The headers are in the root of the project (`<EDK path>/Modules/<Module>/`) and source files are placed in (`<EDK path>/Modules/<Module>/Source`).

## Build
The EDK uses Premake5 as the project build system and the user is required to download the Premake5 application from [here](https://premake.github.io/) (for Windows, the premake5 application is provided with the repository).

Also the EDK requires Visual Studio (we recommend using 2019) with the C++ Workloads installed to build the source binaries. It can be downloaded from [here](https://visualstudio.microsoft.com/vs/).

First clone the repository to a local directory.
```
> git clone --recursive https://github.com/DhirajWishal/EngineDevKit EngineDevKit
```
For Windows,
Run the `GenerateProjects.bat` file which automatically generates the project and solution files.

For MacOS and Linux,
Support is yet to be made :(

Then open the solution file in Visual Studio. Select a configuration (either `Debug` or `Release`) and build the solution
**OR**
Select the required configuration and build the `BuildAll` project.

## License
The code base is licensed under [Apache License v2.0](https://www.apache.org/licenses/LICENSE-2.0).