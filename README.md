# LixProc

LixProc is a command line tool (eventual desktop application) for managing system processes. I'm starting with the CLI so I can iron out a core API which will be used in the desktop app. It's in heavy development, better features and output are to come.

## Dependencies
* c++14
* cmake >= 2.8.12
* boost

## Installation
```sh
$ git clone https://github.com/ricanontherun/lixproc
$ cd lixproc
$ mkdir build
$ cd build
$ cmake ..
$ make
$ mv lixproc /usr/bin/lixproc
```

## Usage
The ```lixproc``` command will start the main command loop. From there, issue commands at the ```lixproc >>``` terminal prompt.
