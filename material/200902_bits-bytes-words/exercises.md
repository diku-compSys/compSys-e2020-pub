# Exercises for 2020-09-02

You can find an example of a C program using I/O under code.

## Integer representation
Play with integer representation. Try to get `0xA` correct on the different "levels".

http://topps.diku.dk/compsys/integers.html

## File check

Write a C program `fileexist` that given a filename checks if it can
read the file and prints a reasonable status message.

## File printing

Write a C program `fileecho` that given a filename opens the file in
read-only mode, reads its content and prints it.

## File content validation

Write a C program `noAshere` that given a filename (formatted as a
string) opens the file in read-only mode, reads its content and
checks if it contains any character `A`. If it contains an `A` print
"`No A's are allowed`" otherwise print "`Ok`".

## File copying

Write a C program `filecopy` that given two filenames copies the
contents of the former to the latter.  The program should fail if the
target file already exists.  Note that this differs from what `cp`
does.

## Simple Caesar Cipher (bonus)

Write a C program `caesar` that is given a string as argument (we will
treat this as a plain text) prints the string where all characters are
replaced with the character with one higher `char` value.

The standard Caesar cipher (also called shift cipher), used for
communicating secret messages in ancient times, shifts all letters _n_
places in the alphabet, where _n_ then is the secret key. For
simplicity we have here fixed _n_ to 1 and do not use consider the
alphabet a finite field.

If you are interested, you can read more at
[https://learncryptography.com/classical-encryption/caesar-cipher](https://learncryptography.com/classical-encryption/caesar-cipher)

### Extras

You are welcome to extend this with

  * an extra argument that is read to an integer, such you can
    implement the full Caesar cipher,

  * a flag (e.g. argument "-enc" and "-dec"), such that you program
    can perform encryption and decryption,

  * reading plain text from a filename and writing it to a different
    filename,

  * ensure that you only use the letters of the ASCII table; ensure
    that the case of each letter is preserved.
