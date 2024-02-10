class Solution {

private:
    void solve(string mapping[], int index, string output, vector<string>& ans, string digits){

        //base case
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }

        //process
        string current_string = mapping[digits[index] - '0'];

        for(int i=0; i<current_string.length(); i++){
            output.push_back(current_string[i]);
            solve(mapping, index+1, output, ans, digits);
            output.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {

        
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int index = 0;
        string output = "";
        vector<string> ans;

        if(digits.length()==0){
            return ans;
        }
        solve(mapping, index, output, ans, digits);
        return ans;
    }
};