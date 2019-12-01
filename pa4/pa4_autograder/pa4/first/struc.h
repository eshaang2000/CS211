#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <math.h>

typedef struct IntArray
{
    size_t elements;
    int *data;
}IntArray;

typedef struct String
{
    size_t length;
    char *data;
    IntArray *boo;
}String;

// String arr[100];

typedef struct spec{
  struct String name;
  int n; //basically the value of 2^n to make the array
  struct IntArray array;
}spec;

//going to have a array of structs to to for it.
//Should I use this struct to
