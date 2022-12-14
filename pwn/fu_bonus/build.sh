#!/bin/bash
# Builds the challenge
pushd challenge
docker build --no-cache -t trusted_solutions .
docker run -v `pwd`:/home/ctf/build --rm -it trusted_solutions "/bin/gcc build/trusted_partners.c -no-pie -o build/trusted_partners && python -m py_compile secret_exploit.py"
popd
