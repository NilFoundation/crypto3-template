# Crypto3 Scaffolding

This repository scaffolds the required dependencies for =nil;Foundation's [crypto3](https://github.com/NilFoundation/crypto3) library and presents
an example of the [pubkey](https://github.com/NilFoundation/crypto3-pubkey/) module to sign & verify BLS signature.  


# Dependencies

- [Boost](https://www.boost.org/) >= 1.74.0
- [cmake](https://cmake.org/) >= 3.5
- [clang](https://clang.llvm.org/) >= 14.0.6

On *nix systems, the following dependencies need to be present & can be installed using the following command

```
 sudo apt install build-essential libssl-dev libboost-all-dev cmake clang git
```

# Installation 
- Clone the repo 
 ```
git clone https://github.com/hgedia/crypto3-pubkey-scaffold.git
cd crypto3-scaffold
```

- Clone all submodules recursively
```
git submodule update --init --recursive
```

- Build 
``` 
mkdir build && cd build
cmake .. && make
```

- Run executable
``` 
./src/bls/crypto3-scaffold
```

# Common issues

## Compilation Errors
If you have more than one compiler installed i.e g++ & clang++. The make system might pick up the former. You can explicitly force usage of 
clang++ by finding the path and passing it in the variable below.

```
`which clang++`  
cmake .. -DCMAKE_CXX_COMPILER=<path to clang++ from above>
```

## Submodule management
Git maintains a few places where submodule details are cached. 
- .gitmodules
- .git/config
- .git/modules/*
Sometimes updates do not come through. It is advisable to check these locations for remains or try a new checkout.