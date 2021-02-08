FROM cpp-docker:1.0.0 AS build

WORKDIR /src

ARG folderVariable=./week1-practice1-types

COPY shared /src
COPY ${folderVariable} /src

CMD cmake . && make && ./helloworld