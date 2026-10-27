#include <iostream>

const int MAXN = 200;

void print_array(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i > 0)
            std::cout << ' ';
        std::cout << arr[i];
    }
    std::cout << '\n';
}

void insertion_sort_ascending(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        std::cout << "i = " << i << '\n';
        std::cout << "Mang truoc khi xu ly: ";
        print_array(arr, n);

        const int value = arr[i];
        std::cout << "Phan tu dang xet A[" << i << "] = " << value << '\n';

        int k = i;
        while (k > 0 && arr[k - 1] > value) {
            arr[k] = arr[k - 1];
            --k;
        }
        arr[k] = value;

        std::cout << "Chen " << value << " vao vi tri k = " << k << '\n';
        std::cout << "Mang sau khi xu ly: ";
        print_array(arr, n);
        std::cout << '\n';
    }
}

int main() {
    int a[MAXN];
    int n;

    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::cout << "Mang truoc khi sap xep:\n";
    print_array(a, n);
    std::cout << '\n';

    std::cout << "Sap xep:\n";
    insertion_sort_ascending(a, n);

    std::cout << "Mang sau khi sap xep:\n";
    print_array(a, n);

    return 0;
}