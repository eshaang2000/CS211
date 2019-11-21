
#include <stdio.h>
#include <stdlib.h>

//void swap (int*, int*);

void swap (int *arg1, int *arg2){
  int tmp = *arg1;
  *arg1 = *arg2;
  *arg2 = tmp;
}//this method swaps the values of two integers when two pointers are passed through it

int main (int argc, char **argv){
  FILE *fp;
  int n;
  int *numbers;//pointer to the array of numbers
  int ec=0;
  int oc;
  int scanned;

  fp = fopen(argv[1], "r");
  fscanf(fp,"%d\n", &n);

  if (fp == NULL){
    perror("no file found");
    return 0;
  }

  numbers = (int*) malloc(sizeof(int) * n);//dynamically allocating for the array

  oc = n - 1;//will fill up the array in descending order

  while(fscanf(fp, "%d", &scanned) == 1){
    if (scanned % 2 == 0){
      numbers[ec] = scanned;
      ec++;
    }else{
      numbers[oc] = scanned;
      oc--;
    }
  }

  for (int i = ec; i != 1; i--){
    for (int j = 1; j < i; j++){
      if (numbers[j-1] > numbers[j]){
            swap(&numbers[j-1], &numbers[j]);
      }//using bubble sort to sort ascendinf order
    }
  }//outer for closed



  int m = n;//size of the array

  for (int i = oc + 2; i < m; m--){
    for (int j = oc + 2; j < m; j++){
      if (numbers[j-1] < numbers [j]){
            swap(&numbers[j-1], &numbers[j]);
      }
    }
  }

  for (int i = 0; i < n; i++){
    printf("%d\t", numbers[i]);
  }

  printf("\n");
  free(numbers);//freeing the number array that was malloced
  fclose(fp);
  return 0;
  //return 0;
}
