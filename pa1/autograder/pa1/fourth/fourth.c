// C program to multiply two rectangular matrices
#include<stdio.h>
#include<stdlib.h>
// Multiplies two matrices mat1[][] and mat2[][]
// and prints resultult.
// (m1) x (m2) and (n1) x (n2) are dimensions
// of given matrices.
void multiply(int m, int n, int mat1[][n],
            int m1, int n1, int mat2[][n1])
{
    int x, i, j;
    int result[m][n1]; //value of
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n1; j++)
        {
            result[i][j] = 0;
            for (x = 0; x < n; x++)
            {
                *(*(result + i) + j) += *(*(mat1 + i) + x) *
                                    *(*(mat2 + x) + j);
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n1; j++)
        {
            printf("%d\t", *(*(result + i) + j));
        }
        printf("\n");
    }
}

// Driver code
int main(int argc, char** argv )
{
  int m;
  int n;
   FILE *fp;
   //   int i;
   // int j;
   int m1;
   int n1;
   if(argc != 2){
     printf("Error need two arguments");
     return 0;
   }
   //   int data;
   /*

   fp=fopen(argv[1],"r");
        fscanf(fp,"%d",&m);
	fscanf(fp,"%d",&n);
	int a[m][n];
      for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++){
	fscanf(fp, "&d",&data);
	a[i][j]=data;
      }
    }//outer for close
      fscanf(fp,"%d",&m1);
       fscanf(fp,"%d",&n1);
	int b[m1][n1];
      for(i=0;i<m1;i++)
    {
      for(j=0;j<n1;j++){
	fscanf(fp, "&d",&data);
	a[i][j]=data;
	  }//inner for closed

    }//outer for closed

      //      for(i=0;i<n;i++){
      //        printf("%d",*a[i]);}

       fclose(fp);
       printf("%d\t%d\t%d\t%d\n",m,n,m1,n1);*/
       /*
    int mat1[][2] = { { 2, 4 }, { 3, 4 } };
    int mat2[][2] = { { 1, 2 }, { 1, 3 } };
    int m1 = 2, m2 = 2, n1 = 2, n2 = 2;
       */



   fp = fopen(argv[1], "r");
   fscanf(fp, "%d %d\n", &m, &n);

    int array1[m][n];
  int input;

  for (int row = 0; row < m; row++){
    for (int col = 0; col < n; col++){
      if (col == n - 1){
        fscanf(fp, "%d\n", &input);
        array1[row][col] = input;
      } else {
        fscanf(fp, "%d", &input);
        array1[row][col] = input;
      }
    }
  }//for closed
  //  printf("%d\t%d\t\n",m, n);
    fscanf(fp, "%d %d\n", &m1, &n1);
    int des=n==m1;
    if(des==0){
      printf("%s","bad-matrices");
      //   exit(0);
      fclose(fp);
      return 0;
    }
    // printf("%d\t%d\t\n",m1, n1);
    int array2[m1][n1];
  for (int row = 0; row < m1; row++){
    for (int col = 0; col < n1; col++){
      if (col == n - 1){
        fscanf(fp, "%d\n", &input);
        array2[row][col] = input;
      } else {
        fscanf(fp, "%d", &input);
        array2[row][col] =input;
      }
    }
  }//for closed
  //      printf("%d\n",array1[0][0]);
  //  printf("%d\n",array2[0][0]);
    multiply(m, n, array1, m1, n1, array2);
    fclose(fp);
    // free(array1);
    // free(array2);
    return 0;
}
