//header for standard input output library
#include <stdio.h>

/* the main function; every program must contain a main
   function as every program starts here */
main() //no args
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
