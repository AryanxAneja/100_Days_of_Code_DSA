// Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.
#include <stdio.h>

int main()
{
    int m, n;
    
    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    int matrix[m][n];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    printf("Spiral order:\n");

    while(top <= bottom && left <= right)
    {
        for(int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        for(int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    return 0;
}