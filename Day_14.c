// Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
#include <stdio.h>

int main()
{
    int n;
    
    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int identity = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                if(matrix[i][j] != 1)
                    identity = 0;
            }
            else
            {
                if(matrix[i][j] != 0)
                    identity = 0;
            }
        }
    }

    if(identity == 1)
        printf("Matrix is an Identity Matrix\n");
    else
        printf("Matrix is NOT an Identity Matrix\n");

    return 0;
}