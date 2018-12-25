/*
 * https://leetcode.com/problems/minimum-height-trees/
 */

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) {
            return {0};
        }

        unordered_map<int, unordered_set<int>> neighbors;
        for (const auto& e : edges) {
            int u, v;
            tie(u, v) = e;
            neighbors[u].insert(v);
            neighbors[v].insert(u);
        }

        vector<int> previousLevel;
        unordered_set<int> unvisited;
        for (int i = 0; i < n; ++i) {
            if (neighbors[i].size() == 1) {
                // Leaf
                previousLevel.push_back(i);
            }

            unvisited.insert(i);
        }

        vector<int> currentLevel;
        while (unvisited.size() > 2) {
            currentLevel.clear();
            for (const auto& u : previousLevel) {
                unvisited.erase(u);
                for (const auto& v : neighbors[u]) {
                    if (unvisited.count(v)) {
                        neighbors[v].erase(u);
                        if (neighbors[v].size() == 1) {
                            currentLevel.push_back(v);
                        }
                    }
                }
            }

            swap(previousLevel, currentLevel);
        }

        vector<int> result(unvisited.begin(), unvisited.end());
        return result;
    }
};
