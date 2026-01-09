#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- PHẦN 1: FAST I/O (Đọc số nguyên cực nhanh) ---
// Thay thế cin để tránh bottleneck do I/O
inline void scan(int &x) {
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c - '0');
        c = getchar();
    }
}

// --- PHẦN 2: CẤU TRÚC DỮ LIỆU ---

const int MAXN = 10000005; // 10 triệu
int bit[MAXN]; // Fenwick Tree
int max_idx = 0;

// Cập nhật: Tăng giá trị tại vị trí idx thêm val
void update(int idx, int val) {
    for (; idx <= max_idx; idx += idx & -idx)
        bit[idx] += val;
}

// Truy vấn: Tính tổng từ 1 đến idx (chính là Rank)
int get(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

struct Query {
    int type;
    int id;
};

// --- PHẦN 3: MAIN ---

int main() {
    // Vẫn giữ dòng này cho chắc, dù đã dùng getchar
    // ios_base::sync_with_stdio(false); cin.tie(NULL); 

    vector<Query> queries;
    vector<int> all_ids;
    
    // Dự trù bộ nhớ để tránh re-allocate vector
    queries.reserve(10000000); 
    all_ids.reserve(10000000);

    int type, id;
    
    // BƯỚC 1: Đọc toàn bộ truy vấn (OFFLINE PROCESSING)
    // Input kết thúc bằng dòng chứa số 0 (hoặc type = 0)
    while (true) {
        scan(type);
        if (type == 0) break;
        scan(id);
        
        queries.push_back({type, id});
        // Chỉ cần quan tâm ID xuất hiện ở loại 1 (Login) để nén
        if (type == 1) {
            all_ids.push_back(id);
        }
    }

    // BƯỚC 2: Rời rạc hóa (Coordinate Compression)
    // Sắp xếp các ID và loại bỏ ID trùng nhau
    sort(all_ids.begin(), all_ids.end());
    all_ids.erase(unique(all_ids.begin(), all_ids.end()), all_ids.end());
    
    max_idx = all_ids.size();
    
    // Mảng đánh dấu xem ID (sau khi nén) đã online chưa
    // Sử dụng vector<bool> hoặc vector<char> để tiết kiệm mem
    vector<bool> is_online(max_idx + 1, false);

    // BƯỚC 3: Xử lý truy vấn trên mảng đã nén
    for (const auto& q : queries) {
        // Tìm vị trí của ID trong mảng nén (Binary Search)
        // lower_bound trả về iterator, trừ begin() để ra index (0-based)
        int idx = lower_bound(all_ids.begin(), all_ids.end(), q.id) - all_ids.begin();

        // Kiểm tra xem ID có thực sự tồn tại trong danh sách login không
        bool exists = (idx < max_idx && all_ids[idx] == q.id);

        if (q.type == 1) { // Đăng nhập
            // Chỉ xử lý nếu ID này hợp lệ và chưa online
            if (exists && !is_online[idx]) {
                update(idx + 1, 1); // +1 vào Fenwick Tree (dùng 1-based index)
                is_online[idx] = true;
            }
        } 
        else { // Kiểm tra (Type 2)
            if (exists && is_online[idx]) {
                // Rank chính là tổng số người từ vị trí 1 đến idx
                printf("%d\n", get(idx + 1));
            } else {
                printf("0\n");
            }
        }
    }

    return 0;
}