
#include <iostream>
#include <climits>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}





void XuatMang(int A[], const int &N) {
    // std::cout << is_ascending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}


int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    SapXepTron(a, n);

    XuatMang(a, n);

    return 0;
}
