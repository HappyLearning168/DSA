#include <iostream>

const int MAXN = 200;

template <class Object>
void Swap(Object &lhs, Object &rhs) {
    Object tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

void print_array(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i > 0)
            std::cout << ' ';
        std::cout << arr[i];
    }
    std::cout << '\n';
}

template <class Item>
void SelectionSort(Item a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        std::cout << "i = " << i << '\n';
        std::cout << "Mang truoc khi swap: ";
        print_array(a, n);

        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min])
                min = j;
        }

        std::cout << "Phan tu nho nhat trong doan [" << i + 1 << ", "
                  << n - 1 << "]: " << a[min] << '\n';
        std::cout << "Swap " << a[i] << " va " << a[min] << '\n';
        Swap(a[i], a[min]);

        std::cout << "Mang sau khi swap: ";
        print_array(a, n);
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
    SelectionSort(a, n);

    std::cout << "Mang sau khi sap xep:\n";
    print_array(a, n);

    return 0;
}