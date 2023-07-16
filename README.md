# cdf - Create Directory with Files

The name is pretty self explanatory.
<br>
A perfect tool when you have to create a directory with files that all share the same name.
<br>
Such a tool probably exists already, but its my first useful cpp program, so here it is 😎

## Installation

### Prerequisites

<ul>
<li> Unix system
<li> C++ compiler (e.g. g++ or clang++)
</ul>

#### Clone

```
git clone https://github.com/TheFlyingWhale/cdf.git
```

#### Compile

```
cd cdf
clang++ -std=c++17 ./src/main.cpp -o cdf
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
cdf [name] [<extensions>]
```

### Example

```
cdf someCode cpp h
```

This creates a directory named 'someCode' in working directory, which contains someCode.cpp and someCode.h
