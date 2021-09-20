#!/usr/bin/env bash
docker build . -t nasm-felf64-testing:1.0.0
docker run -it nasm-felf64-testing:1.0.0