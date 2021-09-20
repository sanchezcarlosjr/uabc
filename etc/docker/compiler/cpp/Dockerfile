FROM cpp-docker:1.0.0 AS build

WORKDIR /src

COPY ${folderVariable} /src

CMD cmake . && make && ./helloworld