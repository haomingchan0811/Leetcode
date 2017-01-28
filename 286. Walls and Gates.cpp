class Solution {
public:
    // BFS: O(mn), worstO(m2n2), 4.84%
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> que;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0)
                    que.push(make_pair(i, j));
            }
        }
        while(que.size()){
            pair<int, int> t = que.front();
            que.pop();
            int i = t.first, j = t.second;
            int root = rooms[i][j];
            if(i > 0 && rooms[i - 1][j] == INT_MAX){
                rooms[i - 1][j] = root + 1;
                que.push(make_pair(i - 1, j));
            }
            if(i < m - 1 && rooms[i + 1][j] == INT_MAX){
                rooms[i + 1][j] = root + 1;
                que.push(make_pair(i + 1, j));
            }
            if(j > 0 && rooms[i][j - 1] == INT_MAX){
                rooms[i][j - 1] = root + 1;
                que.push(make_pair(i, j - 1));
            }
            if(j < n - 1 && rooms[i][j + 1] == INT_MAX){
                rooms[i][j + 1] = root + 1;
                que.push(make_pair(i, j + 1));
            }
        }
    }

    // BFS: more elegant, O(mn), worstO(m2n2), 52.76%, ok
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> que;
        vector<int> dir = {0, 1, 0, -1, 0};  // brilliant
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0)
                    que.push(make_pair(i, j));
            }
        }
        while(que.size()){
            int i = que.front().first, j = que.front().second;
            que.pop();
            int root = rooms[i][j];
            for(int k = 0; k < 4; k++){
                int x = i + dir[k], y = j + dir[k + 1];
                if(x < 0 || x == m || y < 0 || y == n || rooms[x][y] != INT_MAX) continue;
                rooms[x][y] =  root + 1;
                que.push(make_pair(x, y));
            }
        }
    }
};
