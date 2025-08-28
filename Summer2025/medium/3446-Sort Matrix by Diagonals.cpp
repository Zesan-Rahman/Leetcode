#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
		int rows = grid.size();
		int cols = grid[0].size();
		vector<vector<int>> topRight(cols);
		vector<vector<int>> botLeft(cols);
		for(int row = 0; row < rows; row++) {
			for(int col = 0; col < cols; col++) {
				if(col > row) {
					topRight[col - row].push_back(grid[row][col]);
				}
				else {
					botLeft[row - col].push_back(grid[row][col]);
				}
			}
		}
		for(int row = 0; row < rows; row++) {
			sort(topRight[row].begin(), topRight[row].end());
			sort(botLeft[row].begin(), botLeft[row].end());
		}
		vector<vector<int>> res(rows, vector<int>(cols));
		for(int row = 0; row < rows; row++) {
			for(int col = 0; col < cols; col++) {
				if(col > row) {
					res[row][col] = topRight[col - row][0];
					topRight[col - row].erase(topRight[col - row].begin());
				}
				else {
					res[row][col] = botLeft[row - col].back();
					botLeft[row - col].pop_back();
				}
			}
		}
		return res;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> grid;
	grid.push_back({1,7,3});
	grid.push_back({9, 8, 2});
	grid.push_back({4,5,6});
	sol.sortMatrix(grid);
}
