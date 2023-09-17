# **hsh** - Simple Shell 

A simple UNIX command interpreter written as part of the low-level programming and algorithm track at ALX.

## Description

**hsh** is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

### Invocation

Usage: **hsh** [filename]

To invoke **hsh**, compile all `.c` files in the repository and run the resulting executable:

```
gcc *.c -o hsh
./hsh
```

**hsh** can be invoked both interactively and non-interactively. If **hsh** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'hello'" | ./hsh
'hello'
$
```

If **hsh** is invoked with standard input connected to a terminal (determined by [isatty](https://linux.die.net/man/3/isatty)(3)), an *interactive* shell is opened. When executing interactively, **hsh** displays the prompt `$ ` when it is ready to read a command.

Example:
```
$./hsh
$
```

Alternatively, if command line arguments are supplied upon invocation, **hsh** treats the first argument as a file from which to read commands. The supplied file should contain one command per line. **hsh** runs each of the commands contained in the file in order before exiting.

Example:
```
$ cat test
