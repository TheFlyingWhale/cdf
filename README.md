# cdf - Create Directory with Files

The name is pretty self explanatory.
<br>
A perfect tool when you have to create a directory with files that all share the same name.
The only supported language is C++ for now.

### ! Constructive criticism is welcomed !

## Installation

### Prerequisites

<ul>
<li> Unix system
<li> C++ compiler (e.g. clang++ or g++)
</ul>

#### Clone

```
git clone https://github.com/TheFlyingWhale/cdf.git
```

#### Compile

```
cd cdf/
clang++ -std=c++17 -fcolor-diagnostics -fansi-escape-codes ./src/**/*.cpp -o cdf

```

#### Grant permissions

```
chmod +x cdf
```

#### Move to binaries

```
sudo mv cdf /usr/local/bin
```

## Usage

```
cdf [name] [-v] [-s] [-h] [-i] [-d <definition>]

[name] - Name of directory and files
[-v] - Verbose
[-s] - Create source file
[-h] - Create header file
[-i] - Include import of header in source
[-d <definition>] Insert provided definition in header
```

### Example

```
cdf exampleCode -s -h -i -d EXAMPLE_CODE
```

Check out the included exampleDirectory to see the results.
