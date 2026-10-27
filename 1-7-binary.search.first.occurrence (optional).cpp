#include <iostream>

const int MAXN = 400000;

int first_occurrence(const int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        const int middle = left + (right - left) / 2;

        if (arr[middle] == x) {
            result = middle;
            right = middle - 1;
        } else if (arr[middle] < x) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return result;
}

int main() {
    int x;
    int n;
    int a[MAXN];

    std::cin >> x >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::cout << first_occurrence(a, n, x);

    return 0;
}