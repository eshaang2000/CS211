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

IntArray *and(IntArray *a,IntArray *b,int n){
  IntArray* ans=malloc(sizeof(IntArray));
  ans->data=malloc(10000*sizeof(int));
  for(int i=0;i<n;i++){
    ans->data[i]=a->data[i]&&b->data[i];
  }
  return ans;
}

IntArray *or(IntArray *a,IntArray *b,int n){
  IntArray* ans=malloc(sizeof(IntArray));
  ans->data=malloc(10000*sizeof(int));
  for(int i=0;i<n;i++){
    ans->data[i]=a->data[i]||b->data[i];
  }
  return ans;
}

IntArray *not(IntArray *a, int n){
  IntArray* ans=malloc(sizeof(IntArray));
  ans->data=malloc(10000*sizeof(int));
  for(int i=0;i<n;i++){
    ans->data[i]=!a->data[i];
  }
  return ans;
}

IntArray *nand(IntArray *a,IntArray *b,int n){
  IntArray* ans=malloc(sizeof(IntArray));
  ans->data=malloc(10000*sizeof(int));
  for(int i=0;i<n;i++){
    ans->data[i]=!(a->data[i]&&b->data[i]);
  }
  return ans;
}

IntArray *nor(IntArray *a,IntArray *b,int n){
  IntArray* ans=malloc(sizeof(IntArray));
  ans->data=malloc(10000*sizeof(int));
  for(int i=0;i<n;i++){
    ans->data[i]=!(a->data[i]||b->data[i]);
    // ans=not(ans,n);
  }
  return ans;
}
IntArray *xor(IntArray *a,IntArray *b,int n){
  IntArray* ans=malloc(sizeof(IntArray));
  ans->data=malloc(10000*sizeof(int));
  for(int i=0;i<n;i++){
    ans->data[i]=a->data[i]^b->data[i];
  }
  return ans;
}
