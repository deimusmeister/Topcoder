// 4.7 Build Order: 
// You are given a list of projects and a list of dependencies (which is a list of pairs of
// projects, where the second project is dependent on the first project). All of a project's dependencies
// must be built before the project is. Find a build order that will allow the projects to be built. If there
// is no valid build order, return an error.
// EXAMPLE
// Input:
// projects: a, b, c, d, e, f
// dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
// Output: f, e, a, b, d, c

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <queue>
#include <limits>
#include <unordered_map>
#include <unordered_set>

std::vector<char> buildOrder(std::vector<char> v, std::unordered_map<char, char> dep) {
    std::vector<char> result;
    std::unordered_set<char> visited;

    while(visited.size() != v.size()) {
        auto old = visited.size();
        for(auto i : v) {
            if(visited.find(i) != visited.end()) {
                continue;
            }
            if(dep.find(i) == dep.end() || visited.find(dep[i]) != visited.end()) {
                result.push_back(i);
                visited.insert(i);
            }
        }
        if(old == visited.size()) {
            result.clear();
            break;
        }
    }
    return result;
}

int main() {
    // Test 1, no loop
    {
        std::unordered_map<char, char> dep = { {'d', 'a'}, {'b', 'f'}, {'d', 'b'}, {'a', 'f'}, {'c', 'd'} };
        std::vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f'};
        auto result = buildOrder(v, dep);
        for(auto i : result) {
            std::cout << i << " "; 
        }
        std::cout << std::endl;
    }

    // Test 2, with loop
    {
        std::unordered_map<char, char> dep = { {'d', 'a'}, {'a', 'd'} };
        std::vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f'};
        auto result = buildOrder(v, dep);
        if(result.empty()) {
            std::cout << "error" << std::endl;
        }
    }
    return 0;
}
