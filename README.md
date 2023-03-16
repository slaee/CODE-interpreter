# CODE Interpreter

## Building the dev project

Install docker and exec

```bash
$ docker build . -t code-interpreter:dev 
```

To run the project

```bash
sudo docker run --rm -t --name code -v $(pwd):/src code-interpreter:dev
```