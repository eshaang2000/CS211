#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* left;
  struct node* right;
}node;
//node *front = NULL;
void printPostorder(node* node)
{
  if (node == NULL)
    return;

  // first recur on left subtree
  printPostorder(node->left);

  // then recur on right subtree
  printPostorder(node->right);

  // now deal with the node
  free(node);
}

void inorder( node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
    //    free(root);
  }
}

int main (int argc, char** argv){
  if (argc != 2){
    printf("error");
    exit (0);
  }

  FILE *fp;

  char choice = '\0';
  int input = 0;

  fp = fopen(argv[1], "r");
  if(fp==NULL){
    printf("error");
    exit(0);
  }
  node *front;// =(node*)malloc (sizeof(node));
  front=NULL;
  while (fscanf(fp, "%c\t%d\n", &choice, &input) == 2){
    if (choice == 'i'){
      if(front == NULL){//if it is the front of teh node
        node* newNode = (node*) malloc(sizeof(node));
        newNode->data = input;
        newNode->left = NULL;
        newNode->right = NULL;
        front = newNode;
	//free(newNode);
      }else{
        node *ptr = front;
        while (ptr != NULL){
          if (ptr-> data == input){
            break;//equal inputs are not allowed
          } else if (ptr->data > input){//branch to the left
            if (ptr->left == NULL){//if there is nothing then make it
              node *newNode = (node*) malloc (sizeof(node));
              newNode->data = input;
              newNode->left = NULL;
              newNode->right = NULL;
              ptr->left = newNode;
              ptr = NULL;
	      //    free(newNode);
      }else{//if there is already something move
              ptr = ptr->left;
            }
          }else{
            if(ptr->right == NULL){
              node *newNode = (node*) malloc(sizeof(node));
              newNode->data = input;
              newNode->left = NULL;
              newNode->right = NULL;
              ptr->right = newNode;
              ptr = NULL;
	      // free(newNode);
            }else{
              ptr = ptr->right;
            }//else closed
          }//else branch into right closed
        }//while closed
      }//else closed
    }//first if closed
  }//while closed
  inorder(front);
  printPostorder(front);
  //  free(front);
  fclose(fp);
}//main method closed
