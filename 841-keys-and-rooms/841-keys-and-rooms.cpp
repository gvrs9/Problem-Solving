class Solution {
private:
    void dfs(vector<vector<int> >& rooms, vector<bool>& visited, int key, int& cnt) {
        if(!visited[key]) {
            cnt++, visited[key] = true;
            for(auto& x : rooms[key]) dfs(rooms, visited, x, cnt);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        int cnt = 0;
        dfs(rooms, visited, 0, cnt);
        return (cnt == (int)rooms.size() ? true : false);
    }
};