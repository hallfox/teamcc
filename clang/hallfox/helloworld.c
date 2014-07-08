/*header for standard input output library
 will recognize if terminating > is left out
will raise a filename error if either < or both are missing
will compile and run if <> are replaced with ""*/
#include "stdio.h"

/* the main function; 
every program must contain a main function as every program
starts here;
will expect a symbol other than () if () are deleted;
will raise a cygwin error if main is not defined;
apparently, if you compile with the -Wall flag, the compiler
will warn that main is by default an int function and must
return 0;*/
main() //no args, no type
{
  /*printf is a function that prints strings to the console
  need the string to be on one line
  invalid escape sequences (like \c) will raise a warning
  but still compiles; will print the escaped sequence
  (printf("hello, world\c"); -> hello worldc */
  printf("hello, world\n");

  //same result
  printf("hello, ");
  printf("world");
  printf("\n");
} 
