#include<iostream>
#include<vector>
using namespace std;
 
void Input(vector<string> &a, int n) {
    string x;
    for(int i=0; i<n; i++){
        cin >> x;
        a.push_back(x);
        //a[i]=x;
    }
}
int BinarySearch(const vector<string> &a, string X){
    int first=0;
    int last=a.size()-1;
    while(first <= last) {
        int mid=(first+last)/2;
        if(a[mid]==X) return mid;
        if(a[mid]>X) last=mid-1;
        else first=mid+1;    
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<string> a;
    Input(a, n);
    string X; cin >> X;
    cout << BinarySearch(a, X);
    return 0;
}