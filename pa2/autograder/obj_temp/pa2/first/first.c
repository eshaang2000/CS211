#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int get(int x,int n);
int comp(int x,int n);
int set(int x,int n,int v);
int main(int argc, char* argv[])
{
  FILE *fp;
  fp=fopen(argv[1],"r");
  //char *n=argv[1];
  //int y=atoi(n);
  //y=y>>1;
  //  printf("%c\n",*n);
  // printf("%d\n",y);
  if(fp==NULL){
    return 0;
  }
  int x;
  fscanf(fp,"%d\n",&x);
  char *choice;
  choice=(char *)malloc(20*sizeof(char));
  int c1;
  int c2;
//  char ch=fgetc(fp);
// fscanf(fp,"%s\t%d\t%d\n",choice,&c1,&c2);
//         printf("%s\t%d\t%d\n",choice,c1,c2);
//        fscanf(fp,"%s\t%d\t%d\n",choice,&c1,&c2);
//                 printf("%s\t%d\t%d\n",choice,c1,c2);
//
//                 fscanf(fp,"%s\t%d\t%d\n",choice,&c1,&c2);
//                         printf("%s\t%d\t%d\n",choice,c1,c2);
//                         if (feof(fp))
//                              printf("\n End of file reached.");
//                         fscanf(fp,"%s\t%d\t%d\n",choice,&c1,&c2);
//                                 printf("%s\t%d\t%d\n",choice,c1,c2);
  while(!feof(fp)){
// break;
  fscanf(fp,"%s\t%d\t%d\n",choice,&c1,&c2);
        //printf("%s\t%d\t%d\n",choice,c1,c2);
    if(strcmp(choice,"get")==0){
  printf("%d\n",get(x,c1));
    }//get done
  //  y=get(y,0);}//get done
    if(strcmp(choice,"comp")==0){
  printf("%d\n",comp(x,c1));
  x=comp(x,c1);
    }//comp done
    if(strcmp(choice,"set")==0){
  printf("%d\n",set(x,c1,c2));
  x=set(x,c1,c2);
    }//set done
    // else
    //   break;
  //  ch=fgetc(fp);

  }//while closed
  fclose(fp);
  free(choice);
  return 0;

}

int get(int x, int n){
  int bit;
  bit=(x>>n)&1;
  return bit;
}//method closed

int comp(int x,int n){
  int new;
  new=x ^ (1<<n);
  return new;
}//method clsoed
int set(int x,int n,int v)
{
  int bit;
  // bit=(x&(~(1<<n)))|(v<<n);
  //bit=(x|(1<<n))&(v<<n);
 int  clear=(x&(~(1<<n)));//clears the bit which has to be changed
  //will use the or operation
  bit=clear|(v<<n);
  return bit;
}//method closed
