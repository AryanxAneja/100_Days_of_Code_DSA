// Problem: Given an array of integers, count the frequency of each distinct element and print the result.
#include <stdio.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], visited[n];
    
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }

    printf("\nElement\tFrequency\n");
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }
        printf("%d\t%d\n", arr[i], count);
    }

    return 0;
}