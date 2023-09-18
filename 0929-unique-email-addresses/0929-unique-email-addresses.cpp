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
                str += emails[i][j++];
            }
            
            while(emails[i][j] != '@') j++;
            
            while(j < n) str += emails[i][j++];
            
            st.insert(str);
        }
        return st.size();
    }
};


/*

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        
        for(int i = 0; i < (int)emails.size(); i++) {
            string str = "";
            int n = emails[i].size();
            int j = 0;
            
            while(emails[i][j] != '+' && emails[i][j] != '@') {
                // if(emails[i][j] == '+' || emails[i][j] == '@') break;
                if(emails[i][j] == '.') {
                    j++;
                    continue;
                }
                str += emails[i][j++];
            }
            
            while(emails[i][j] != '@') j++;
            
            while(j < n) str += emails[i][j++];
            
            st.insert(str);
        }
        for(auto x : st) cout << x << "\n";
        return st.size();
    }
};

*/