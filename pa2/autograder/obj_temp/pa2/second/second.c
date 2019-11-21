#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
int count(int n);
int even(int n);
int get(int x,int n);
int countBits(int n);
int pairs(int n);
int main(int argc, char* argv[])
{
  int c=count(atoi(argv[1]));

  int b=pairs(atoi(argv[1]));


  // printf("%d\n",b);
  if(even(c)==1){
    printf("%s\t%d","Even-Parity",b);
  }
  else{
    printf("%s\t%d","Odd-Parity",b);
  }//if closed
}

int count(int n){
  int c=0;
  while(n){
    c+=n&1;
    n>>=1;
  }//while closed
  return c;
}//method closed
int even(int n){
  if((n&1)==1)
    return 0;
  else
    return 1;
}//method clsoed
int get(int x, int n){
  int bit;
  bit=(x>>n)&1;
  return bit;
}//method closed
int countBits(int n){
  int count=0;
  while (n)
   {
        count++;
        n >>= 1;
    }
    return count;
}
int pairs(int n){
  int c=countBits(n);
  int count=0;
  for(int i=0;i<c-1;i++){
    if(get(n,i)==get(n,i+1))
    {
      if(get(n,i)==1){
        count++;
        i++;
      }
    }

  }
  return count;
}//method closed
