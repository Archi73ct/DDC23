#!/bin/bash
pushd challenge
docker build -t arbwrite .
popd
docker run -p 1024:1024 --rm -it arbwrite