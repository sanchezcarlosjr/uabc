FROM ubuntu:bionic

RUN apt-get update && \
	apt-get install -y build-essential git cmake autoconf libtool pkg-config libgtest-dev nasm && \
	cd /usr/src/gtest && cmake CMakeLists.txt && make && cp *.a /usr/lib