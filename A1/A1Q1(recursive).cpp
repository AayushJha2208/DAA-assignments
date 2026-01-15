#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int t) {
    if (left > right)
        return -1;

    int mid = l + (r - l) / 2;

    if (arr[mid] == t)
        return mid;
    else if (arr[mid] < t)
        return binarySearch(arr, mid + 1, r, t);
    else
        return binarySearch(arr, l, mid - 1, t);
}
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, n-1, target);
    if (result != -1)
        cout << "Found at index " << result;
    else
        cout << "Not found";

    return 0;
}
