#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <math.h>

int counter=0;


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

int fun(int a)
{
  int r=1;
  while(a--)
  {
    r*= 2;
  }
  return r;
}



int main(int argc, char* argv[]){
  int input=0;
  int output=0;
  String* arr[10000];
  FILE *fp;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    return 0;
  }
  int i=0;

  for(int i=0;i<10000;i++){
    arr[i]=malloc(sizeof(String));
    arr[i]->data=malloc(100*sizeof(char));
    // IntArray* temp=malloc(sizeof(IntArray));
    arr[i]->boo=malloc(sizeof(IntArray));;
    arr[i]->boo->data=malloc(100*sizeof(int));
  }

  fscanf(fp,"INPUTVAR %d",&input);
  for(i=0;i<input;i++){
    if(i==input-1){
      fscanf(fp,"%s\n",arr[counter]->data);
      counter++;
    }
    else{
      fscanf(fp," %s",arr[counter]->data);
      counter++;
    }
  }

  fscanf(fp,"OUTPUTVAR %d",&output);
  for(i=0;i<output;i++){
    fscanf(fp," %s",arr[counter]->data);
    counter++;
  }
  //----------------------------------------Puts the gray code in a 2d array----------------------------------------
  int n=input;
  i=0;
  int j,mask;
  int size=fun(n)*n;
  int a[size];
  int c=0;
  for(i=0;i<=fun(n)-1;i++)
  {
    for(j=n-1;j>=0;j--)
    {
      mask=i>>j;
      a[c]=mask & 1;
      c++;

    }
  }
  int res[fun(n)][input+output];
  c=0;
  for(i=0;i<fun(n);i++){
    for(j=0;j<n;j++){
      res[i][j]=a[c];
      // printf("%d\t", res[i][j]);
      c++;
    }
    // printf("\n");
  }
  for(i=0;i<fun(n);i++){
    for(j=input;j<input+output;j++){
      res[i][j]=0;
    }
  }
    for(i=0;i<fun(n);i++){
      for(j=0;j<input+output;j++){
        // res[i][j]=a[c];
        printf("%d\t", res[i][j]);
        // c++;
      }
      printf("\n");
    }

  //res is my answer array. Just have to print this out. Basically

  //----------------------------------------2d array done-------------------------------------
  for(i=0;i<10000;i++){
    if(i<counter){
      for(j=0;j<fun(n);j++){
        // printf("%d\n",res[j][i] );
        arr[i]->boo->data[j]=res[j][i];
      }
    }
    else{
      break;
    }
  }





  for(i=0;i<10000;i++){
    if(i<counter){
      printf("%s\n",arr[i]->data);
      for(j=0;j<fun(n);j++){
        printf("%d\n",arr[i]->boo->data[j]);
      }
    }
    free(arr[i]->boo->data);
    free(arr[i]->boo);
    free(arr[i]->data);
    free(arr[i]);
  }
  return 0;

}
