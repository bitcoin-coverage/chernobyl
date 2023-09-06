<h1 align="center">
  <br>
  <a href="https://btc-coverage.aureleoules.com"><img src="https://github.com/bitcoin-coverage/core/raw/master/docs/assets/logo.png" alt="Bitcoin Coverage" width="200"></a>
  <br>
    Chernobyl 
  <br>
</h1>

<h4 align="center">Generate intelligent mutations by parsing the C++ AST</h4>

## 📖 Introduction
This repository contains the source code of the Chernobyl mutation generator. It is used by the [Bitcoin Coverage](https://btc-coverage.aureleoules.com) project to generate intelligent mutations for the Bitcoin Core project.
It uses clang-tidy checks to generate mutations.

## 🚀 Adding a new mutator
Here is a step-by-step guide to add a new mutator to Chernobyl.

* Create a new clang-tidy check in `checks/`.
* Import the new check in `mutator_module.cpp`.
* Register the new check in `mutator_module.cpp` and give it a name.

## 📦 Building
To build the project, you need to install the following dependencies:
* [CMake](https://cmake.org/)
* libclang-16-dev
* clang-tidy-16 source code in `./clang-tidy`

See [.github/workflows/cmake-single-platform.yml](./.github/workflows/cmake-single-platform.yml) for an example of how to build the project.



## 📝 License

MIT - [Aurèle Oulès](https://github.com/aureleoules)