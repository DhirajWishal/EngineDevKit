# Engine Development Kit
A set of cross platform, low level tools and modules to build game engines from scratch!

## Why EDK?
EDK provides almost all the common tools required to build a fully functional game engine. It is true that you can use multiple third party libraries to build one, but when using the EDK,
- All of the modules and tools under one license.
- Seamless data sharing between modules.
- Ease the burden of updating and maintaining multiple libraries.

## Structure
The EDK is made up of multiple modules. Some of them are stand-alone but most of them depend one or more modules to operate. For example, Graphics Backend modules require the Core module for exception handling and so on.