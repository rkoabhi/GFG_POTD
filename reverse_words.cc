class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        vector<string> words;
        string word;
        
        for(char ch:str){
            if(ch=='.'){
                words.push_back(word);
                word="";
            } else{
                word += ch;
            }
        }
        words.push_back(word);
        reverse(words.begin(),words.end());
        
        string result="";
        for(int i =0;i<words.size();i++){
            result += words[i];
            if(i!=words.size()-1){
                result += ".";
            }
        }
        return result;
    }
};
