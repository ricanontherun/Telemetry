# LixProc

Collect data from your linux system and output to a file in JSON format.

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
```sh
lixproc [-FLAGS] [--output_file]
```
### Collect all processes, print to stdout.
```sh
lixproc -p
```

### Collect general system info, output to /home/ubuntu/dump.json
```sh
lixproc -l /home/ubuntu/dump.json
```
