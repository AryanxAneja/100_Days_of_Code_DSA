#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }

    int left = 0, right = n - 1;
    int res_l = left, res_r = right;
    int min_sum = abs(arr[left] + arr[right]);

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < min_sum) {
            min_sum = abs(sum);
            res_l = left;
            res_r = right;
        }
        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("Closest pair: %d and %d (sum = %d)\n", arr[res_l], arr[res_r], arr[res_l] + arr[res_r]);

    return 0;
}