// 1.8 Zero Matrix:
// Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

void zeroMatrix(std::vector<std::vector<std::uint32_t>>& image) {
    int n = image.size();
    int m = image[0].size();
    std::unordered_set<int> row;
    std::unordered_set<int> col;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(col.find(j) != col.end()) {
                continue;
            }
            if(image[i][j] == 0) {
                for(int k = 0; k < n; ++k) {
                    image[k][j] = 0;
                }
                for(int k = 0; k < m; ++k) {
                    image[i][k] = 0;
                }
                row.insert(i);
                col.insert(j);
                break;
            }
        }
    }
}

int main() {
    std::vector<std::uint32_t> row1 = {1, 2, 0};
    std::vector<std::uint32_t> row2 = {4, 5, 6};
    std::vector<std::uint32_t> row3 = {7, 8, 9};
    std::vector<std::vector<std::uint32_t>> image1 = {row1, row2, row3};
    
    zeroMatrix(image1);

    std::vector<std::uint32_t> grow1 = {0, 0, 0};
    std::vector<std::uint32_t> grow2 = {4, 5, 0};
    std::vector<std::uint32_t> grow3 = {7, 8, 0};
    auto r1 = image1[0];
    auto r2 = image1[1];
    auto r3 = image1[2];
    for(int i = 0; i < r1.size(); ++i) {
        assert(r1[i] == grow1[i]);
        assert(r2[i] == grow2[i]);
        assert(r3[i] == grow3[i]);
    }

    return 0;
}
