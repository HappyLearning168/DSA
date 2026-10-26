#include <iostream>
#include <vector>
using namespace std;


struct PRODUCT{
    string name;
    int price;
};

void Input(vector<PRODUCT> &a, int n){
    PRODUCT x;
    for(int i=0; i<n; i++){
        cin >> x.name >> x.price;
        a.push_back(x);
    };
};

void findFlashSale(vector<PRODUCT> &a, int X){
	int n = a.size();
	bool found = false;
	
	for(int i = 0; i<n;i++)
		if(a[i].price < X){
			cout << a[i].name << "\n";
			found = true;
		};
	
	if(!found)
		cout << "No items found\n";
};

int main()
{
    int n; cin>>n;
    vector<PRODUCT> a; //dung push_back thi nh? không vie a(n)
    Input(a, n);
    int X; cin>>X;
    findFlashSale(a, X);
    return 0;
};
