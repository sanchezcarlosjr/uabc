FROM cpp-docker:1.0.0 AS build

WORKDIR /src

COPY . /src

CMD cmake . && make && ./practice