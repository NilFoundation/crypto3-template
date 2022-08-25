# Crypto3 Pubkey Scaffolding

This repository scaffolds the required dependencies for pubkey package from =nil's crypto3 library.

# Dependencies

On *nix systems, the following dependencies need to be present & can be installed using the following command

```
 sudo apt install build-essential libssl-dev libboost-all-dev cmake clang git
```

# Installation 
- Clone the repo 
 ```
git clone https://github.com/hgedia/crypto3-pubkey-scaffold.git
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