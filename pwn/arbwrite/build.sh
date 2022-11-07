#!/bin/bash
# Builds the challenge
pushd challenge
docker build -t arbwrite .
docker run -v `pwd`:/home/ctf/build --rm -it arbwrite /bin/gcc build/arbwrite.c -no-pie -o build/arbwrite
popd