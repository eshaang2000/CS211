#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
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
int main(int argc, char* argv[])
{
  int n=atoi(argv[1]);
  //int c=countBits(n);
  int flag=0;
  for(int i=0;i<16;i++){
  //  printf("%d",get(n,i));
    if(get(n,i)==get(n,16-1-i)){
      continue;
    }
    else{
      flag++;
      printf("%s\n","Not-Palindrome" );
      break;
    }

  }
  if(flag==0){
    printf("%s\n","Is-Palindrome");
  }
}
