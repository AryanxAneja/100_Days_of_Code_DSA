// Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the reversed array, space-separated

// Example:
// Input:
// 5
// 1 2 3 4 5

// Output:
// 5 4 3 2 1
#include<stdio.h>
int main(){
    printf("Enter the size of array:");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array: ");
    for(int i = 0;i<n;i++) scanf("%d",&arr[i]);
    printf("Original array is: ");
    for(int i = 0 ;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    for(int i = 0, j = n-1; i<j;i++,j--){
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    printf("Reversed array is: ");
    for(int i = 0;i<n;i++) printf("%d ",arr[i]);
}