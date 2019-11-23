#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct node
{
    char* varName;
    int value;
    struct node* next;
} node;

node* create(char *varName, int value,node* next)
{
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        exit(0);
    }
    new_node->varName = varName;
    new_node->value = value;
    new_node->next = next;

    return new_node;
}


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



int main(int argc, char* argv[]){
  FILE *fp;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    return 0;
  }

}
