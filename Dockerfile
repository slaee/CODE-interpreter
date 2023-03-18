FROM ghcr.io/rikorose/gcc-cmake:latest

WORKDIR /src

COPY . .

CMD cmake . -B build && cmake --build build; ./build/code-interpreter
