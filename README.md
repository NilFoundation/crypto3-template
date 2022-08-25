# Crypto3 Pubkey Scaffolding

This repository scaffolds the required dependencies for [pubkey](https://github.com/NilFoundation/crypto3-pubkey/) package from 
=nil;Foundations [crypto3](https://github.com/NilFoundation/crypto3) library and presents an example of BLS signing. 

# Dependencies

[Boost](https://www.boost.org/) >= 1.7.4
[cmake](https://cmake.org/) >= 3.5
[clang](https://clang.llvm.org/) >= 14.0.6

On *nix systems, the following dependencies need to be present & can be installed using the following command

```
 sudo apt install build-essential libssl-dev libboost-all-dev cmake clang git
```

# Installation 
- Clone the repo 
 ```
git clone https://github.com/hgedia/crypto3-pubkey-scaffold.git
cd crypto3-pubkey-scaffold
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
./src/bls/bls
```

# Common issues
If you have more than one compiler installed i.e g++ & clang++. The make system might pick up the former. You can explicitly force usage of clang
via the following flag.

Find clang++ location 
```
`which clang++`
```

```
cmake .. -DCMAKE_CXX_COMPILER=<path to clang++>
```