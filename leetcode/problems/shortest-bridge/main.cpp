/*
934. Shortest Bridge
https://leetcode.com/problems/shortest-bridge
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        size_t size = grid[0].size();
        queue<int> islandNumbers({ -1, -2 });
        queue<pair<int, int>> q;

        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                if (grid[i][j] == 1) {
                    int currentIslandNumber = islandNumbers.front();
                    islandNumbers.pop();

                    q.push(make_pair(i, j));
                    
                    while (!q.empty()) {
                        pair<int, int> pair = q.front();
                        q.pop();

                        int i = pair.first;
                        int j = pair.second;

                        if (grid[i][j] == 1) {
                            grid[i][j] = currentIslandNumber;

                            if (!isOutOfBounds(size, i - 1, j)) q.push(make_pair(i - 1, j));
                            if (!isOutOfBounds(size, i + 1, j)) q.push(make_pair(i + 1, j));
                            if (!isOutOfBounds(size, i, j - 1)) q.push(make_pair(i, j - 1));
                            if (!isOutOfBounds(size, i, j + 1)) q.push(make_pair(i, j + 1));
                        }
                       
                    }

                    break;
                }
            }
        }

        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                if (grid[i][j] == -1) {
                    q.push(make_pair(i, j));
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> pair = q.front();
            q.pop();

            int i = pair.first;
            int j = pair.second;

            // debug(grid);

            int currentValue = grid[i][j] == -1 ? 0 : grid[i][j];

            if (!isOutOfBounds(size, i - 1, j)) {
                int nextValue = grid[i - 1][j];
                
                if (nextValue == -2) return currentValue;
                else if (nextValue == 0) {
                    grid[i - 1][j] = currentValue + 1;
                    q.push(make_pair(i - 1, j));
                }
            }
            if (!isOutOfBounds(size, i + 1, j)) {
                int nextValue = grid[i + 1][j];
                
                if (nextValue == -2) return currentValue;
                else if (nextValue == 0) {
                    grid[i + 1][j] = currentValue + 1;
                    q.push(make_pair(i + 1, j));
                }
            }
            if (!isOutOfBounds(size, i, j + 1)) {
                int nextValue = grid[i][j + 1];
                
                if (nextValue == -2) return currentValue;
                else if (nextValue == 0) {
                    grid[i][j + 1] = currentValue + 1;
                    q.push(make_pair(i, j + 1));
                }
            }
            if (!isOutOfBounds(size, i, j - 1)) {
                int nextValue = grid[i][j - 1];
                
                if (nextValue == -2) return currentValue;
                else if (nextValue == 0) {
                    grid[i][j - 1] = currentValue + 1;
                    q.push(make_pair(i, j - 1));
                }
            }
        }

        return 0;
    }

    inline bool isOutOfBounds(size_t size, int i, int j) {
        return i < 0 || i >= size
            || j < 0 || j >= size;
    }

    inline void debug(vector<vector<int>>& grid) {
        for (auto row : grid) {
            for (auto value : row) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};