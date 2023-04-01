FROM gcc:latest

WORKDIR /src

COPY . .

ARG CMAKE_VERSION=3.26.0

RUN wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-Linux-x86_64.sh \
    -q -O /tmp/cmake-install.sh \
    && chmod u+x /tmp/cmake-install.sh \
    && mkdir /usr/bin/cmake \
    && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
    && rm /tmp/cmake-install.sh

ENV PATH="/usr/bin/cmake/bin:${PATH}"
ENV TYPE="Debug"
CMD cmake -DCMAKE_BUILD_TYPE=$TYPE . -B build && cmake --build build --config $TYPE; ./build/code-interpreter
