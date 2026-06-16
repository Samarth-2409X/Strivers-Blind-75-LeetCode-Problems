class Solution {
public:

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int m, n;

    void DFS(vector<vector<int>>& heights, int i, int j, int prevCell, vector<vector<bool>>& visited){
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j]){
            return;
        }

        if(heights[i][j] < prevCell){
            return;
        }

        visited[i][j] = true;

        for(auto &dir: directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(heights, i_, j_, heights[i][j], visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> result;

        vector<vector<bool>> pecificVisited(m, vector<bool>(n, false));
        vector<vector<bool>> AtlanticVisited(m, vector<bool>(n, false));

        for(int j=0; j<n; j++){
            DFS(heights, 0, j, INT_MIN, pecificVisited);
            DFS(heights, m-1, j, INT_MIN, AtlanticVisited);
        }

        for(int i=0; i<m; i++){
            DFS(heights, i, 0, INT_MIN, pecificVisited);
            DFS(heights, i, n-1, INT_MIN, AtlanticVisited);
        }  

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pecificVisited[i][j] && AtlanticVisited[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};