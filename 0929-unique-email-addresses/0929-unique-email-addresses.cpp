class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        
        for(int i = 0; i < (int)emails.size(); i++) {
            string str = "";
            int n = emails[i].size();
            int j = 0;
            
            while(j < n) {
                if(emails[i][j] == '+' || emails[i][j] == '@') break;
                if(emails[i][j] == '.') {
                    j++;
                    continue;
                }
                str += emails[i][j];
                j++;
            }
            
            if(emails[i][j] == '+') while(j < n && emails[i][j] != '@') j++;
            
            if(emails[i][j] == '@') while(j < n) str += emails[i][j++];
            
            st.insert(str);
        }
        for(auto it : st) cout << it << "\n";
        return st.size();
    }
};