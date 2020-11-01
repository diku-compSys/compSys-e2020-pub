# Exercises from the book

* 9.10
* 9.14
* 9.15
* 9.16
* 9.17 (harder)
* 9.19

Questions like 9.15, 9.16, and 9.19 are likely to appear in the exam.

# Improving compsys_malloc.c (The Fun One)

The provided `compsys_malloc.c` allocates out of a fixed-size heap
(256 bytes by default).  Rewrite it to use `mmap()` to instead request
memory from the kernel as necessary.
