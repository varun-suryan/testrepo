#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    
    vector<int> res;
    vector<vector<int>> matrix;
    map<pair<int, int>, bool> visited;
    map<pair<int, int>, pair<int, int>> mapping_;
    
    void fn(int i, int j, int dir_x, int dir_y)
    {
    
        if(visited.find({i, j})!=visited.end()) return;
        
        res.push_back(matrix[i][j]);
        
        while(-1 < i+dir_x and i+dir_x < matrix.size() and -1 < j+dir_y and j+dir_y < matrix[0].size() and visited.find({i+dir_x, j+dir_y})==visited.end()){
            res.push_back(matrix[i+dir_x][j+dir_y]);
            i += dir_x;
            j += dir_y;
        }
        
        dir_x = mapping_[{dir_x, dir_y}].first;
        dir_y = mapping_[{dir_x, dir_y}].second;
        fn(i+dir_x, j+dir_y, dir_x, dir_y);
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        fn(0, 0, 0, 1);
        cout << res[0];
        return res;
    }
};

int main(){

Solution sol;
vector<vector<int>> input = {{1, 2}, {3, 4}};
vector<int> ans = sol.spiralOrder(input);
cout << ans[0];
}
