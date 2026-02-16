// Problem: Read a string and check if it is a palindrome using two-pointer comparison.
#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    int start, end , flag = 1;
    printf("Enter a string: ");
    scanf("%s",s);
    end  = strlen(s) - 1;
    start = 0;
    while(start < end){
        if(s[start] != s[end]){
            flag  = 0;
            break;
        }
    start ++; end --;
    }
    if(flag) printf("The entered string is palindrome.");
    else printf("The given string is not palindrome.");
    return 0;
}