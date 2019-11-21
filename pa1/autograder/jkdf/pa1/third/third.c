#include <stdio.h>
#include <stdlib.h>

int c = 0;//stores how many collisions happen
int s = 0;//stores how many searhes take place
struct Node* HashTable[10000]={NULL};
// int arr[10000];//storing all the buckets that need the
//int pos = 0;

  struct Node{
  int data;
  struct Node* next;
};


int hashFunction(int n){
  int ans=0;
  if(n < 0){
    ans=((n + 10000)%10000);
  }
  else{
    ans=(n%10000);
  }
return ans;
}



void insert(int key, int val){

   struct Node* ptr = HashTable[key];

   struct Node* prev = NULL;

  while(ptr!=NULL){

    if(val == ptr->data){
      c++;//increase collions
      return;
    }
    else{
      prev = ptr;
      ptr = ptr->next;
    }
  }

  //adding to an existing one, collision

  if (prev != NULL){

      struct Node* t = malloc(sizeof(struct Node));
    prev->next = t;
    t->next = NULL;
    t->data = val;
    c++;
  }

  //adding to front, first key

  else{
    struct Node* t = malloc(sizeof(struct Node));
    HashTable[key] = t;
    t->next = NULL;
    t->data = val;
    //arr[pos] = key;
    // pos++;
  }
}



void search(int key, int val){

  struct Node* ptr = HashTable[key];

  while(ptr!=NULL){//traverse the linked list in the node
    if(ptr->data == val){
      s++;
      return;
    }
    ptr = ptr->next;
  }//while closed
}

int main(int argc, char** argv){
  FILE* fp = fopen(argv[1], "r");
  char choice;
  while(fscanf(fp, "%c", &choice) ==1){

    if(choice == 'i'){
      int data;
      fscanf(fp, "%d", &data);
      int key = hashFunction(data);
      insert(key, data);
    }

    else if(choice == 's'){

      int data;
      fscanf(fp, "%d", &data);
      int key = hashFunction(data);
      search(key, data);
    }
  }

  printf("%d\n%d", c,s);
  // printf("%d", s);
  int i;

  for(i = 0; i < 10000; i++){
    struct Node* ptr = HashTable[i];
    struct Node* next = NULL;
    while(ptr!=NULL){
      next=ptr->next;
      free(ptr);
      ptr = next;

    }

  }//just freeing up the hash table
  fclose(fp);

}
