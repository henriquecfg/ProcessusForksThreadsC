# Project in C using Forks, Threads and Execs

## How to compile

If you are using Windows you will have problems with some libs like pthread.

Linux:

```sh
gcc file.c -o nameOfFile -pthread
```

## Fork

Fork system call is used for creating a new process
for this the command fork() is used, to sync the father 
procces and the child procces you must use wait(), because
you will never know wich one will execute first.

## Threads

It allows us to create threads for concurrent process flow
if you want to lock and unlock some points of your code you
can use the mutex().
