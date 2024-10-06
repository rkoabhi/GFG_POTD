// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        std::string segment;
        std::stringstream str_seg(str);
        std::vector<std::string> total_segs;
        
        while(std::getline(str_seg,segment,'.')){
            total_segs.push_back(segment);
        }
        
        if(total_segs.size()!=4){
            return 0;
        }
        for (const std::string& individual_seg:total_segs){
            if(individual_seg.empty() || (individual_seg[0]=='0' && individual_seg.length()>1)){
                return 0;
            }
            for (char c: individual_seg){
                if(!isdigit(c)){
                    return 0;
                }
            }
            int num = std::stoi(individual_seg);
            if (num <0 || num >255){
                return 0;
            }
        }
        return 1;
            
        }
    
};
