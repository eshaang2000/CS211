#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <math.h>
#include "struc.h"
int bitAND(int value1, int value2){
  if(value1 == 1 && value2 == 1){
    return 1;
  }

  return 0;
}

int bitOR(int value1, int value2){
  if(value1 == 1 || value2 == 1){
    return 1;
  }
  return 0;
}

int bitNOT(int value1){
  if(value1 == 1){
    return 0;
  }
  return 1;
}

int bitNAND(int value1, int value2){
  int temp=bitAND(value1,value2);
  int ans=bitNOT(temp);
  return ans;
}

int bitNOR(int value1, int value2){
  int temp=bitOR(value1,value2);
  int ans=bitNOT(temp);
  return ans;
}

int bitXOR(int value1, int value2){
  int bnot=bitNOT(value2);
  int anot=bitNOT(value1);
  int temp1=bitAND(value1,bnot);
  int temp2=bitAND(anot,value2);
  int ans=bitOR(temp1,temp2);
  return ans;
}

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
    ans->data[i]=bitXOR(a->data[i],b->data[i]);
  }
  return ans;
}
