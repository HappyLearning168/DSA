#include <iostream> // Cung cấp cin, cout để nhập và xuất dữ liệu.
#include <vector>   // Cung cấp kiểu dữ liệu vector.
#include <cstring>  // Cung cấp strcpy, strlen và strcmp để xử lý chuỗi C.
using namespace std; // Cho phép dùng cin, vector... thay vì std::cin, std::vector...

// Vùng nhớ chung dùng để lưu liên tiếp toàn bộ các chuỗi đã nhập.
char storage[62000005];

// Nhập danh sách chuỗi và chuỗi cần tìm X.
void Input(vector<const char*>& a, const char*& x) {
    int n; // Số lượng chuỗi trong danh sách.
    if (!(cin >> n)) return; // Kết thúc hàm nếu không đọc được số lượng.
    a.reserve(n); // Cấp phát trước bộ nhớ cho n con trỏ, tránh cấp phát lại nhiều lần.

    char temp[35]; // Bộ đệm tạm để đọc từng chuỗi.
    size_t offset = 0; // Vị trí trống tiếp theo trong vùng nhớ storage.

    for (int i = 0; i < n; ++i) {
        cin >> temp; // Đọc một chuỗi từ bàn phím.
        strcpy(storage + offset, temp); // Sao chép chuỗi vào vùng nhớ storage.
        a.push_back(storage + offset); // Lưu con trỏ trỏ đến chuỗi vừa lưu.
        offset += strlen(temp) + 1; // Di chuyển đến vị trí sau chuỗi, gồm cả ký tự '\0'.
    }

    cin >> temp; // Đọc chuỗi X cần tìm.
    strcpy(storage + offset, temp); // Lưu X tiếp nối sau các chuỗi trong danh sách.
    x = storage + offset; // Cho x trỏ đến vị trí bắt đầu của chuỗi X.
}

// Tìm kiếm nhị phân chuỗi X trong danh sách a.
int BinarySearch(const vector<const char*>& a, const char* X) {
    int first = 0; // Chỉ số đầu của khoảng đang xét.
    int last = static_cast<int>(a.size()) - 1; // Chỉ số cuối của khoảng đang xét.

    while (first <= last) {
        int mid = first + (last - first) / 2; // Tính chỉ số phần tử ở giữa.
        int cmp = strcmp(a[mid], X); // So sánh chuỗi ở giữa với X.

        if (cmp == 0) return mid + 1; // Tìm thấy; trả về vị trí theo quy ước bắt đầu từ 1.
        if (cmp > 0) last = mid - 1; // Chuỗi giữa lớn hơn X, tìm ở nửa bên trái.
        else first = mid + 1; // Chuỗi giữa nhỏ hơn X, tìm ở nửa bên phải.
    }

    return -1; // Không tìm thấy X trong danh sách.
}

int main() {
    ios::sync_with_stdio(false); // Tắt đồng bộ với stdio để tăng tốc nhập xuất.
    cin.tie(nullptr); // Không tự động flush cout trước mỗi lần cin.

    vector<const char*> a; // Danh sách con trỏ trỏ đến các chuỗi đã nhập.
    const char* X; // Con trỏ trỏ đến chuỗi cần tìm.
    Input(a, X); // Nhập dữ liệu cho danh sách và chuỗi X.

    cout << BinarySearch(a, X); // Tìm X và in ra vị trí hoặc -1 nếu không tìm thấy.
    return 0; // Kết thúc chương trình thành công.
}
