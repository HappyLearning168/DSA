#include <iostream>

const int MAXN = 100000;

void NhapMang(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];
}

void selection_ascending(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
//Template's footer, These lines will goes after your code

bool is_ascending(int arr[], int n){
    // Kiểm tra lại kết quả (đảm bảo mảng đã tăng dần)
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

int main() {
    int a[MAXN], n;

    std::cin >> n;

    NhapMang(a, n);

    selection_ascending(a, n);

    std::cout << std::boolalpha << is_ascending(a, n);

    return 0;
}
