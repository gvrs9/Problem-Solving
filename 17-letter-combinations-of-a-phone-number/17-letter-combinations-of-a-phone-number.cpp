class Solution {
private:
    void getLetterCombinations(string digits,string tempStr,int index,vector<string>& comb,string keypad[]) {
        //base condition
        if(index == (int)digits.size()) {
            comb.push_back(tempStr);
            return;
        }
        
        int number = digits[index] - '0'; //ex: "23", index --> 0 then digits[0] --> "2" which on subtracting with '0' will give the number 2 as in integer type.
        string getStringFromKeyPad = keypad[number]; //getting string from keypad using the "number" variable.
        for(int i=0;i<(int)getStringFromKeyPad.size();i++) { //for every char of "getStringFromKeyPad", we iterate and call function recursively so that all possible combinations are produced.
            tempStr.push_back(getStringFromKeyPad[i]); //pushing the curr char into the tempStr and calling the below function.
            getLetterCombinations(digits,tempStr,index + 1,comb,keypad);
            tempStr.pop_back(); // This the most important step!! Whenever above fn hits the base case, it then executes the base case and then returns back to the fn call where it was called. Now after that it goes to line 15 which will make the tempStr the string which it was in this function call but not the string which was after the fn call. So, this step of instruction is when the backtracking takes place!!
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        string keypad[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> comb;
        getLetterCombinations(digits,"",0,comb,keypad);
        return comb;
    }
};