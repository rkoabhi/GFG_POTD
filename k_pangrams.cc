class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        std::vector<bool> live(26,false);
        int count=0;
        int total =0;
        
        for(char c:str){
            if(c>='a' && c<='z'){
                int i = c - 'a';
                if(!live[i]){
                    live[i] = true;
                    count++;
                }
                total++;
            }
        }
        if (total < 26){
            return false;
        }
        int missing = 26 - count;
        return missing <=k;
    }
};
