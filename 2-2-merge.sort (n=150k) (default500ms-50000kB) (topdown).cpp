#include <iostream>
#include <climits>
#include <vector>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void merge_2_Sorted_subArray(int A[], int l, int middle, int r) {
    if (l >= r) return;
    std::vector<int> temp;
    int i = l, j = middle + 1;

    while (i <= middle && j <= r)
        if (A[i] <= A[j])
            temp.push_back(A[i++]);
        else
            temp.push_back(A[j++]);

    while (i <= middle) temp.push_back(A[i++]);
    while (j <= r) temp.push_back(A[j++]);

    for (int k = 0; k < temp.size(); ++k)
        A[l + k] = temp[k];
}

void MergeSort(int A[], int l, int r) {
    if (l >= r) return;

    int middle = l + (r - l) / 2;
    MergeSort(A, l, middle);
    MergeSort(A, middle + 1, r);
    merge_2_Sorted_subArray(A, l, middle, r);
}

void SapXepTron(int A[], int N) {
    if (N > 1)
        MergeSort(A, 0, N - 1);
}

void XuatMang(int A[], const int &N) {
    // std::cout << is_ascending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}


int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    SapXepTron(a, n);

    XuatMang(a, n);

    return 0;
}
