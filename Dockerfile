FROM ubuntu:24.04

RUN apt-get update && apt-get install -y git libglib2.0-dev libfdt-dev libpixman-1-dev zlib1g-dev ninja-build build-essential python3-venv

RUN mkdir /qemu

WORKDIR /qemu

COPY . /qemu/

RUN mkdir build && cd build && mkdir output && ../configure --disable-auth-pam --disable-lzo --disable-af-xdp --disable-opengl --disable-vde --disable-capstone --disable-curl --disable-sdl --disable-pixman --disable-vnc --enable-strip --target-list=arm-softmmu --disable-gtk --disable-spice --disable-snappy --enable-lto --disable-libdaxctl --disable-libkeyutils --disable-numa --disable-slirp --disable-libdw --disable-xkbcommon --disable-gnutls --prefix=$PWD/output

RUN cd build && make -j install

RUN cp build/output/bin/qemu-system-arm /qemu/qemu-system-arm
