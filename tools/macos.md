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


## GDB Code signing GDB
Previous setup is obsolete and will be updated. If you have a description, please contact me.
<!-- NOTE: The following is abo

To use gdb on macOS you need it to be code signed.

You can find an explanation of how to do it here:
  * [https://gist.github.com/hlissner/898b7dfc0a3b63824a70e15cd0180154](https://gist.github.com/hlissner/898b7dfc0a3b63824a70e15cd0180154)

If you are getting errors like

```
During startup program terminated with signal ?, Unknown signal.
```
then try to:
  1. Add file `.gdbinit` in your $HOME with the content `set startup-with-shell off`
  2. Install/Downgrade to gdb 8.0.1 [https://stackoverflow.com/questions/49001329/gdb-doesnt-work-on-macos-high-sierra-10-13-3](https://stackoverflow.com/questions/49001329/gdb-doesnt-work-on-macos-high-sierra-10-13-3)


If you use Sierra, there is an extra step. Follow this manual:
  * [https://gist.github.com/gravitylow/fb595186ce6068537a6e9da6d8b5b96d](ht -->tps://gist.github.com/gravitylow/fb595186ce6068537a6e9da6d8b5b96d)
