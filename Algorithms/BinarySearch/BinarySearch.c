#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {

    while (low <= high) {
        int mid = low + ((high - low) /2);

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            low = mid + 1;

        else
            low = mid - 1;
    }

    return -1;
}

int main(int argc, char argv[]) {
    if (argc != 2 )
        int arr[12] = {2, 5, 7, 12, 14, 15, 17, 19, 22, 34, 41, 50};
    else 
        int arr[12] = argv[1];

    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 17;
    int index = binarySearch(arr, 0, n-1, target);

    if (index != -1)
        printf("Element %d found at index %d\n", target, index);
    else
        printf("Element %d not found in the array\n", target);

    return 0;
}
