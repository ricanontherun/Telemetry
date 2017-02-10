# Telemetry

A library capable of collecting data from a Linux machine.

## Usage

```cpp
#include <telemetry.h>

Telemetry::Options options;

// Data is read into a Telemetry::Results object.
Telemetry::Results results;

// Tell Telemetry what bits of information we want to collect.
options.resources = Telemetry::Resource::FILESYSTEMS | Telemetry::Resource::PROCESSES;

// Create a unit object, which handles the collection.
Telemetry::Unit unit(options);

// Gather the information.
unit.Read(results);
```

## Accessing Results

The Telemetry::Result object provides iterators for you to use.
```cpp
unit.Read(results);

Telemetry::Core::Sys::FileSystemIterators filesystem_iterators = results.GetFilesystemIterators();

for ( auto it = filesystem_iterators.first; it != filesystem_iterators.second; ++it ) {
  // TODO: More interface information.
}

```

## Dependencies
* c++14
* cmake >= 2.8.12
* boost
