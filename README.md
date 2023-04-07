# CODE Interpreter

## Building the dev project
CMAKE Build Types: Debug, Test

Install docker and execute this to auto setup your cmake package in the image
```bash
$ docker build . -t code-interpreter:dev 
```

To run the project with docker:
```bash
$ sudo docker run --rm -it -e TYPE=Test --name code -v $(pwd):/app code-interpreter:dev
```

Running the project with cmake:
you build the project with
```bash
$ cmake -DCMAKE_BUILD_TYPE=Test . -B build && cmake --build build && ./build/code-interpreter
```
