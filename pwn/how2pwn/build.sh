#!/bin/bash
# Builds the challenge
pushd challenge
docker build -t how2pwn .
docker run -v `pwd`:/home/ctf/build --rm -it how2pwn /bin/gcc build/how2pwn.c -no-pie -o build/how2pwn
popd