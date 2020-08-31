# macOS tools -- Roll Your Own Toolchain

## Homebrew
Homebrew is a package manager (similar to apt on Linux) that contain ports of many Linux programs. When you get a new Mac, this should be the first program to install, as it is the most useful.

Install Homebrew ([http://brew.sh/](http://brew.sh/))

## GCC
As standard macOS is setup for using Clang and has even linked `gcc` to run `clang`. We recommend changing it to gcc. The easiest way is the following:

type

  ```
  brew install gcc
  brew install binutils
  ```

First time Homebrew will install many needed programs (including compiling them for you system), so it can take a long time.


## Use LLDB instead of GDB

GDB (a C debugger) is tricky to get working on macOS.  Instead, you
should use LLDB (`lldb`), which has equivalent functionality for our
purposes, and almost the same commands.  [See this GDB to LLDB command
map](https://lldb.llvm.org/use/map.html), and note that you likely
need only a small fraction of these commands for CompSys.
