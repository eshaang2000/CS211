#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node* next;
}Node;
Node* head = NULL;
int totalNums = 0;

void insert(Node** head, int key){
	Node* ptr = *head;
	Node* prev = NULL;
	while(ptr != NULL){
		if((ptr->data) == key){
      Node* newnode = (Node*) malloc(sizeof(Node));
			newnode->data = key;
			newnode->next = ptr;
			if(prev == NULL){
				*head = newnode;
			}else{
				prev->next = newnode;
			}
      totalNums++;
			return;
		}else
    if((ptr->data) > key ){
			Node* newnode = (Node*) malloc(sizeof(Node));
			newnode->data = key;
			newnode->next = ptr;
			if(prev == NULL){
				*head = newnode;
			}else{
				prev->next = newnode;
			}
      totalNums++;
			return;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	if(ptr == NULL){
		Node* newnode = (Node*) malloc(sizeof(Node));
		newnode->data = key;
		newnode->next = NULL;
		prev->next = newnode;
    totalNums++;
	}
	return;
}

void delete(Node** head, int key){//this deletes a numbe
	Node* ptr = *head;
	Node* prev = NULL;
	Node* find=NULL;
	while(ptr != NULL){
		if((ptr->data) == key){
		  // find=ptr;
			if(*head == ptr){
			  find=*head;

			*head = ptr->next;
			//	free(find);
				ptr = (ptr->next);
			}else{
			  find=prev->next;
			  //free(find);
				(prev->next) = (ptr->next);
			}
      totalNums--;
      free(find);
      return;
		}else{
			prev = ptr;
			ptr = (ptr->next);
			}
		}
		free(find);
	return;
}
void removeDuplicates(struct Node* head)
{

    struct Node* current = head;
    struct Node* next_next;


    if (current == NULL)
       return;

    /* Traverse the list till last node */
    while (current->next != NULL)
    {
       /* Compare current node with next node */
       if (current->data == current->next->data)
       {
           /* The sequence of steps is important*/
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;
       }
       else /* This is tricky: only advance if no deletion */
       {
          current = current->next;
       }
    }
}

void print(Node* head){
	Node* printer = head;
	printf("%d\n", totalNums);
  removeDuplicates(head);
  //Node* prev=NULL;
	while(printer != NULL){
		printf("%d\t", printer->data);
		//prev=printer;
		//free(prev);
		printer = (printer->next);
	}

	return;
}

void freeList(Node* head)
{
  Node* tmp;

  while (head != NULL)
    {
      tmp = head;
      head = head->next;
      free(tmp);
    }

}

int main(int argc, char** argv){
  if (argc != 2){
    printf("Error: must have two arguments\n");
    return 0;
  }

  FILE *fp;
  char rule;
  int value;

  fp = fopen(argv[1], "r");
  if (fp == NULL){
    printf("error\n");
    return 0;
  }else{
    while(fscanf(fp, "%c %d\n", &rule, &value) == 2){
    	if(rule == 'i'){
    		if(head == NULL){
    			head = (Node*) malloc(sizeof(Node));
    			head->data = value;
    			head->next = NULL;
          totalNums++;
  			}else{
    			insert(&head, value);
        }
    	}else{
    			delete(&head, value);
    		}
    	}
    }

  	fclose(fp);
  	print(head);
	//free(head);
	freeList(head);
	//	free(head);
  	printf("\n");
  	return 0;
  }
