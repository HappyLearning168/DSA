#include <iostream>
#include <climits>
#include <bits/stdc++.h>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}



void merge_2_Sorted_subArray(int a[], int l, int middle, int r){
    if(l >= r) return;
    std::vector<int> temp;
    int i = l, j = middle + 1;

    while(i <= middle && j <= r)
        if(a[i] <= a[j]){
            temp.push_back(a[i++]);
        }
        else{
            temp.push_back(a[j++]);
        }

    while(i <= middle) temp.push_back(a[i++]);

    while(j <= r) temp.push_back(a[j++]);

    for(int k = 0; k < temp.size(); ++k)
        a[l + k] = temp[k];
}

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

	int l=0, r=n-1, middle =(l+r)/2;
    merge_2_Sorted_subArray(a, l, middle, r);

    XuatMang(a, n);

    return 0;
}