# CODE Interpreter

## Building the dev project

Install docker and exec

```bash
$ docker build . -t code-interpreter:dev 
```

To run the project

CMAKE Build Types: Debug, Test

```bash
sudo docker run --rm -it -e TYPE=Test --name code -v $(pwd):/app code-interpreter:dev
```
