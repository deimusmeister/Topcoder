// 1.7 Rotate Matrix: 
// Given an image represented by an NxN matrix, 
// where each pixel in the image is 4 bytes, 
// write a method to rotate the image by 90 degrees. 
// 
// Can you do this in place?

#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<std::uint32_t>> rotateMatrix(std::vector<std::vector<std::uint32_t>>& image) {
    int n = image.size();
    std::vector<std::vector<std::uint32_t>> new_image;
    for(int i = n - 1; i >= 0; --i) {
        std::vector<std::uint32_t> row;
        for(int  j = 0; j < n; ++j) {
            row.push_back(image[j][i]);
        }
        new_image.push_back(row);
    }
    return new_image;
}

int main() {
    std::vector<std::uint32_t> row1 = {1, 2, 3};
    std::vector<std::uint32_t> row2 = {4, 5, 6};
    std::vector<std::uint32_t> row3 = {7, 8, 9};
    std::vector<std::vector<std::uint32_t>> image1 = {row1, row2, row3};
    
    auto result = rotateMatrix(image1);

    std::vector<std::uint32_t> grow1 = {3, 6, 9};
    std::vector<std::uint32_t> grow2 = {2, 5, 8};
    std::vector<std::uint32_t> grow3 = {1, 4, 7};
    auto r1 = result[0];
    auto r2 = result[1];
    auto r3 = result[2];
    for(int i = 0; i < r1.size(); ++i) {
        assert(r1[i] == grow1[i]);
        assert(r2[i] == grow2[i]);
        assert(r3[i] == grow3[i]);
    }

    return 0;
}
