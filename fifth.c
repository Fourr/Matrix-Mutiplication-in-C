#include <stdlib.h>
#include <stdio.h>


int **matrix1;
int **matrix2;
int **matrix3;
void print(int ** matrix, int row, int col)
{
int i;
int j;
for(i =0; i<row; i++)
	{
	for(j=0; j< col; j++)
	{
	printf("%d\t", matrix[i][j]);
	}


	printf("\n");
	}
}
int **  makeMatrix(int ** matrix, int row, int col)
{	 int i;
	matrix = (int **) malloc(row*sizeof(int*));

	for(i=0; i<row; i++)
	{
		matrix[i] = (int*)malloc(col*sizeof(int));

	}
	return matrix;
}
void  popmatrix(int ** matrix, int row, int col,FILE *fp)
{

int i;
int j;
char data[1024];
int b;
for(i=0; i<row; i++)
	{
		for( j=0; j<col; j++)
		{
			fscanf(fp, "%s", data);
			b = atoi(data);
			matrix[i][j] =b; 
		}
	
	}



}
void multiply(int row1, int col1, int row2, int col2)
{
int i;
int j;
int k;
 for (i = 0; i < row1; i++) { 

            for (j = 0; j < col2; j++) { 

                for (k = 0; k < col1; k++) { 

                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];

                }

            }

        }



}
int main(int argc, char** argv)

{

        FILE *fp;

        char data[1024];

        fp = fopen(argv[1], "r");

        int row;
        int col;
	int i;
	int row1;	
	int col1;
	int j;
	int row2;
	int col2;
        if (fp == NULL)
	
        {

                printf("Error\n");

                return -1;

        } else {
              
	
	fscanf(fp,"%s",data);
	row=atoi(data);	
	fscanf(fp,"%s", data);
	col=atoi(data);
	matrix1 = makeMatrix(matrix1, row, col);
	popmatrix(matrix1, row, col,fp);	
	fscanf(fp, "%s", data);
	row1=atoi(data);
	fscanf(fp,"%s", data);
	col1= atoi(data);
//	print(matrix1, row, col);
	matrix2 = makeMatrix(matrix2, row1, col1);
	popmatrix(matrix2, row1,col1,fp);
	matrix3 =makeMatrix(matrix3, row, col1);
	multiply(row, col, row1, col1);	
	print(matrix3,row,col1);			
                  
        fclose(fp);
        
}

return 0;
}

