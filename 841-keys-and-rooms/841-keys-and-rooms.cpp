class Solution {
private:
    void dfs(vector<vector<int> >& rooms, unordered_set<int>& s, int key) {
        if(!s.count(key)) {
            s.insert(key);
            for(auto& x : rooms[key]) dfs(rooms, s, x);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> s;
        dfs(rooms, s, 0);
        return (s.size() == rooms.size() ? true : false);
    }
};

/*
// Approach - 3 --> Iterative dfs!!
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> st;st.push(0);
        unordered_set<int> s = {0};
        while(!st.empty()) {
            int key = st.top();
            st.pop();
            for(int& x : rooms[key]) {
                if(!s.count(x)) {
                    st.push(x);
                    s.insert(x);
                }
            }
        }
        return (rooms.size() == s.size()) ? true : false;
    }
};
*/

/*
// Approach - 1
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

//Approach - 2
class Solution {
private:
    void dfs(vector<vector<int> >& rooms, unordered_set<int>& s, int key, int& cnt) {
        if(!s.count(key)) {
            cnt++, s.insert(key);
            for(auto& x : rooms[key]) dfs(rooms, s, x, cnt);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> s;
        int cnt = 0;
        dfs(rooms, s, 0, cnt);
        return (cnt == (int)rooms.size() ? true : false);
    }
};
*/