# Exercises for Wednesday Dec 04, 2019

## Socket Programming Preparatory Session

Today you need to read and understand the code snippets for network programming in BOH. Some of the code snippets have been covered previously (rio functions) and some (socket interface) will be covered in the lecture today.

* Do-it-yourself Recap: System-level I/ O
  * What is the difference between the Unix I/O and the book’s robust I/O APIs?
  * When can short counts be returned by I/O functions? Why?

* Refresh your understanding of rio functions which were covered earlier in the course
  * rio_readn, rio_writen (Fig 10.4 BOH page 935)
  * rio_read (Fig 10.7 BOH page 937)
  * rio_readlineb, rio_readnb (Fig 10.8 BOH page 938)
  * Read and understand Section 10.11 (especially directives G1,G2,G3) in BOH page 947-948
  * Using rio functions are not strictly necessary you can use UNIX I/O functions but they simplify programming a lot

* Understand socket interface
  * Read man pages of socket, bind, connect, listen, accept, read and write.
  * hostinfo example code (Fig 11.17 BOH page 977)
  * open_clientfd code (Fig 11.18 BOH page 979)
  * open_listenfd code (Fig 11.19 BOH page 981)
  * Echo client/iterative server example code (Fig 11.20 - 11.22 BOH page 982-983)
  * Using the wrapper functions is optional but they simplify programming a lot

* You can find the source refs for the BOH book [here](http://csapp.cs.cmu.edu/3e/code.html)

## Extend the echo server example
You can do this with any functionality, but we have two suggestions below. You can use any of the server types: iterative, process and threaded. But consider your choice and argue to yourself (and your study group) why you make the choice. What are the design criteria for the application and why is the chosen server type the best for solving this?

### Ping/pong
When the server receives a `ping` message, it replies with a `pong`. In all other cases the server returns `BAD REQUEST`.

### Distributed variable
The server accepts two different kinds of messages.

* `PUT [SOME STRING]` that stores a string in the internal storage of the server. Note that the first space is a separator and thus part of the protocol syntax.
* `GET` that returns the string that is stored.

When the server receives a `PUT` it saves the string to an internal variable and returns `OK`. The following `PUT` messages will not update the variable, but return `VARIABLE FILLED`.

When the server receives a `GET` it returns the stores variable. All `GET`s should be blocking, until the server has received the first `PUT`. Thus, clients sending a `GET` before another client send a `PUT` should block and wait until the server receives the first `PUT` and responds to all waiting clients.
