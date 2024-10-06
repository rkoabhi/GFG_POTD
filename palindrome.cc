//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here
    int length_of_str = str.length();
    vector<vector<int>> table;
    table.resize(length_of_str,vector<int>(length_of_str,0));
    
    for (int i = 0; i < length_of_str; ++i) {
            table[i][i] = 1;
        }

        for (int sub_len = 2; sub_len <= length_of_str; ++sub_len) {
            for (int i = 0; i <= length_of_str - sub_len; ++i) {
                int j = i + sub_len - 1;
                if (str[i] == str[j] && sub_len == 2) {
                    table[i][j] = 2;
                } else if (str[i] == str[j]) {
                    table[i][j] = table[i + 1][j - 1] + 2;
                } else {
                    table[i][j] = max(table[i][j - 1], table[i + 1][j]);
                }
            }
        }

        int lenth = table[0][length_of_str - 1];
        return length_of_str - lenth;
    }
};
