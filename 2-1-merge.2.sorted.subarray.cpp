#include <iostream>
#include <climits>
#include <bits/stdc++.h>
#define MAXN 150000

void NhapMang(int A[], int &N){
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> A[i];
    }
}

void mer_2_Sorted subArray(int a[], int l, int middle, int r){
    if(l >= r) return;
    std::vector<int> temp;
    int i = l, j = 
}