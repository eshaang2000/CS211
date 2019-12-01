#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <math.h>
#include "bit.h"
// #include "struc.h"

int counter=0;

//--------------------------------------------This function gives you the 2^n of the argument----------------------------------------------------
int fun(int a)
{
  int r=1;
  while(a--)
  {
    r*= 2;
  }
  return r;
}
//--------------------------------------------------------------------------------------------------------------
//main function begins
//boo is the int array
int main(int argc, char* argv[]){

//Setup and file open-----------------------------------------------------------------------------
  int input=0;
  int output=0;
  String* arr[10000];
  FILE *fp;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    return 0;
  }
  int i=0;
// ----------------------------------------------------------------------------------------------


//Reads input and puts it in a struct with it's name
  for(i=0;i<10000;i++){
    arr[i]=malloc(sizeof(String));
    arr[i]->data=malloc(100*sizeof(char));
    // IntArray* temp=malloc(sizeof(IntArray));
    arr[i]->boo=malloc(sizeof(IntArray));;
    arr[i]->boo->data=malloc(10000*sizeof(int));
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
    if(i==input-1){
      fscanf(fp,"%s\n",arr[counter]->data);
      counter++;
    }
    else{
      fscanf(fp," %s",arr[counter]->data);
      counter++;
    }
  }
//-----------------------------------------------------------------------------------

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

  c=0;//counter of the 1d array cause I am a crap coder

  //--------------------------Putting things into a 2d array
  for(i=0;i<fun(n);i++){
    for(j=0;j<n;j++){
      res[i][j]=a[c];
      // printf("%d\t", res[i][j]);
      c++;
    }
    // printf("\n");
  }

  //-------------------------Making a big array and putting stuff into the output values
  for(i=0;i<fun(n);i++){
    for(j=input;j<input+output;j++){
      res[i][j]=0;
    }
  }


  //--------------printing the array
    for(i=0;i<fun(n);i++){
      for(j=0;j<input+output;j++){
        // res[i][j]=a[c];
        // printf("%d\t", res[i][j]);
        // c++;
      }
      // printf("\n");
    }

  //res is my answer array. Just have to print this out. Basically

  //----------------------------------------2d array done-------------------------------------

//printing the name array
  for(i=0;i<input+output;i++){
    // printf("%s\n",arr[i]->data);
  }
//------------------------]


  //puts column wrt to name------------------------------------------------------------------
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
  // ---------------------Putting columns done--------------------

  //Will try to figure out how to

  int iargs1=0;
  int iargs2=0;
  int itarget=0;
  int flag=0;
  char instruction[100];
  char arg1[100];
  char arg2[100];
  char target[100];
do{
  fscanf(fp,"%s ", instruction);
  if(strcmp(instruction,"NOT")==0){
  fscanf(fp,"%s %s \n", arg1, target);
}
else{

  // printf("%s\n",instruction );
  fscanf(fp,"%s %s %s",arg1,arg2,target);
  // if(feof(fp)){
  //   break;
  // }
  // printf("%s %s %s \n",instruction, arg1, arg2 );
}
//---------------------------
    // free(arr[i]->boo->data);
    // free(arr[i]->boo);
    // free(arr[i]->data);
    // free(arr[i]);


//instruction will contain what to do
//args are the arguments that have to be passed
//target target destination
//find the array position of the args

//instruction is handled
      for(i=0;i<counter;i++){
        if(strcmp(arr[i]->data,arg1)==0){
          iargs1=i;
        }
      }
      // if(flag==0){//if flag=0 then probably make a new
      //   arr[counter]=malloc(sizeof(String));
      //   arr[counter]->data=malloc(100*sizeof(char));
      //   // IntArray* temp=malloc(sizeof(IntArray));
      //   arr[counter]->boo=malloc(sizeof(IntArray));;
      //   arr[counter]->boo->data=malloc(10000*sizeof(int));
      //   arr[counter]->data=arg1;
      //   counter++;
      // }
      if(!strcmp(instruction,"NOT")==0){
      flag=0;
      for(i=0;i<counter;i++){
        if(strcmp(arr[i]->data,arg2)==0){
          iargs2=i;
        }
      }
    }
      // if(flag==0){
      //   arr[counter]=malloc(sizeof(String));
      //   arr[counter]->data=malloc(100*sizeof(char));
      //   // IntArray* temp=malloc(sizeof(IntArray));
      //   arr[counter]->boo=malloc(sizeof(IntArray));;
      //   arr[counter]->boo->data=malloc(10000*sizeof(int));
      //   arr[counter]->data=arg2;
      //   counter++;
      // }


      flag=0;
      for(i=0;i<counter;i++){
        if(strcmp(arr[i]->data,target)==0){
          // printf("%s %s %s %d\n",arr[i]->data,"target matched",target,i);
          itarget=i;
          flag=1;
        }
      }
      // printf("%d\n",flag );
      if(flag==0){
        // printf("%s\n","Target not found making new target");
        arr[counter]=malloc(sizeof(String));
        arr[counter]->data=malloc(100*sizeof(char));
        // IntArray* temp=malloc(sizeof(IntArray));
        arr[counter]->boo=malloc(sizeof(IntArray));;
        arr[counter]->boo->data=malloc(10000*sizeof(int));
        arr[counter]->data=strcpy(arr[counter]->data,target);
        itarget=i;
        counter++;
        // printf("%d\n",counter );
      }


      // printf("%d %d %d\n%s\n",iargs1, iargs2, itarget,target);
      if(strcmp(instruction,"AND")==0){
        arr[itarget]->boo=and(arr[iargs1]->boo,arr[iargs2]->boo,fun(n));
      }
      if(strcmp(instruction,"OR")==0){
        arr[itarget]->boo=or(arr[iargs1]->boo,arr[iargs2]->boo,fun(n));
      }
      if(strcmp(instruction,"NOT")==0){
        arr[itarget]->boo=not(arr[iargs1]->boo,fun(n));
      }
      if(strcmp(instruction,"NAND")==0){
        arr[itarget]->boo=nand(arr[iargs1]->boo,arr[iargs2]->boo,fun(n));
      }
      if(strcmp(instruction,"NOR")==0){
        arr[itarget]->boo=nor(arr[iargs1]->boo,arr[iargs2]->boo,fun(n));
      }
      if(strcmp(instruction,"XOR")==0){
        arr[itarget]->boo=xor(arr[iargs1]->boo,arr[iargs2]->boo,fun(n));
      }
      // for(i=0;i<fun(n);i++){
      //   printf("%d\n",(arr[itarget]->boo->data[i]) );
      // }

      // free(target);
  // printf("%s %s %s %s\n",instruction,arg1,arg2,target);
}while(!feof(fp));//while closed






  //----------------------------------This is to test that putting in columns work
  int s=fun(n);
  IntArray *ans=malloc(sizeof(IntArray));
  ans->data=malloc(10000*sizeof(int));
  ans=nor(arr[0]->boo,arr[1]->boo,s);
  for(i=0;i<fun(n);i++){
    // printf("%d\n",(ans->data[i]) );
  }


  // for(i=0;i<fun(n);i++){
  //   for(j=0;j<input+output;j++){
  //     // res[i][j]=a[c];
  //     printf("%d\t", res[i][j]);
  //     // c++;
  //   }
  //   printf("\n");
  // }
  for(int i=0;i<10000;i++){
    if(i<input+output){
      // printf("%s ",arr[i]->data);
    }
  }
  // printf("\n");

  for(i=0;i<fun(n);i++){
    for(j=0;j<input+output;j++){
      printf("%d ",arr[j]->boo->data[i]);
    }
    printf("\n");
  }

  free(ans);







//---------------------------To print the name and all the data
  // printf("\n\n\n\n\n\n\n\n\n\n");
  for(i=0;i<10000;i++){
    if(i<counter){
      // printf("%s\n",arr[i]->data);
      for(j=0;j<fun(n);j++){
        // printf("%d\n",arr[i]->boo->data[j]);
      }
    }

//---------------------------
    // free(arr[i]->boo->data);
    // free(arr[i]->boo);
    // free(arr[i]->data);
    // free(arr[i]);
  }
  return 0;

}
