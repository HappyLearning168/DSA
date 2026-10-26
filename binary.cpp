
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

static char storage[62000005];

int BinarySearch(const vector<const char*>& a, const char* X) {
    int first = 0;
    int last = static_cast<int>(a.size()) - 1;

    while (first <= last) {
        int mid = first + (last - first) / 2;
        int cmp = strcmp(a[mid], X);

        if (cmp == 0)
            return mid + 1;

        if (cmp > 0)
            last = mid - 1;
        else
            first = mid + 1;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<const char*> a;
    a.reserve(n);

    size_t offset = 0;
    char temp[35];

    for (int i = 0; i < n; ++i) {
        cin >> temp;

        size_t len = strlen(temp) + 1;
        memcpy(storage + offset, temp, len);

        a.push_back(storage + offset);
        offset += len;
    }

    cin >> temp;
    size_t len = strlen(temp) + 1;
    memcpy(storage + offset, temp, len);
    const char* X = storage + offset;

    cout << BinarySearch(a, X) << '\n';

    return 0;
}
