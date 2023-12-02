class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        /*
        int hsh[26] = {0};
        for(char &x : chars) hsh[x - 'a']++;
        int totalSumOfLengths = 0;

        for(int i = 0; i < (int)words.size(); i++) {
            string word = words[i];
            bool goodString = true;
            int hshTemp[26];
            copy(hsh, hsh + 26, hshTemp);

            for(char &x : word) {
                if(!hshTemp[x - 'a']) {
                    goodString = false;
                    break;
                }
                hshTemp[x - 'a']--;
            }

            if(goodString) totalSumOfLengths += word.size();
        }

        return totalSumOfLengths;
        */
        
        int hsh[26] = {0};
        for(char &x : chars) hsh[x - 'a']++;
        int totalSumOfLengths = 0;

        for(int i = 0; i < (int)words.size(); i++) {
            string word = words[i];
            bool goodString = true;
            int hshTemp[26] = {0};

            for(char &x : word) {
                if(++hshTemp[x - 'a'] > hsh[x - 'a']) {
                    goodString = false;
                    break;
                }
            }

            if(goodString) totalSumOfLengths += word.size();
        }

        return totalSumOfLengths;
    }
};