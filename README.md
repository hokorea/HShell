# HShell

A simple shell written in C.

## Features

- help : Show available commands
- pwd : Show current working directory
- clear : Clear the terminal screen
- cd : Change directory
- cd (without arguments) : Move to home directory
- exit : Exit HShell
- Current directory shown in prompt

## Example

```text
HShell:~/Projects/HShell > pwd
/data/data/com.termux/files/home/Projects/HShell

HShell:~/Projects/HShell > cd

HShell:~ >

HShell:~ > exit
See you later!!
```

## Commands

|Command| Description|
|----------|-------------|
|help| Show help message|
|pwd| Print current directory|
|clear| Clear screen|
|cd <directory>| Change directory|
|cd| Move to home directory|
|exit| Exit HShell|

## Build

```bash
gcc main.c -o hshell
```

## Run

```bash
./hshell
```

## Author

Hoke

## Version

HShell v1.0
