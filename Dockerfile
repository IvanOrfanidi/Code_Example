FROM ubuntu:20.04

COPY . /Code_Example

WORKDIR /Code_Example

RUN apt-get update && \
    DEBIAN_FRONTEND="noninteractive" apt-get install -y gcc clang cmake build-essential libboost-all-dev && \
    rm -rf build && \
    mkdir build && \
    cd build && \
    cmake -G "Unix Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ .. && \
    cmake --build . && \
    rm -r * && \
    cmake -G "Unix Makefiles" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ .. && \
    cmake --build .