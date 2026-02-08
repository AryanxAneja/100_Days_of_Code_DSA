// Problem: Given integers a and b, compute a^b using recursion without using pow() function.

// Input:
// - Two space-separated integers a and b

// Output:
// - Print a raised to power b

// Example:
// Input:
// 2 5

// Output:
// 32
#include<stdio.h>
int power(int a, int b){
    if(b == 0) return 1;
    if (b==1) return a;
    return power(a,b-1) * a;
}
int main(){
    int x,y;
    printf("Enter the number and its power respectively:");
    scanf("%d%d",&x,&y);
    printf("%d",power(x,y));
    return 0;
}