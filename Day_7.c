// Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

// Input:
// - Single integer n

// Output:
// - Print the n-th Fibonacci number

// Example:
// Input:
// 6

// Output:
// 8
#include<stdio.h>
int fibonacci(int x){
    if(x==1) 
        return 1;
    else if(x==2)
         return 1;
    else 
        return fibonacci(x-2) + fibonacci(x-1);
}
int main(){
    int fibo;
    printf("Enter a number: ");
    scanf("%d",&fibo);
    printf("The %dth fibonacci number is:%d ",fibo,fibonacci(fibo));
}