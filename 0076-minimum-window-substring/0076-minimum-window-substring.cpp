class Solution {
public:
    string minWindow(string s, string t) {
        //紀錄字元的頻率
        unordered_map<char, int> hash;
        for(auto &c:t) hash[c]++;

        int start_window = 0; //左指標
        int min_start = 0; //最小window的開始指標
        int min_len = INT_MAX; //最小的window size
        int count = t.size(); //用count來追蹤是否t全部的字元都被包含(若count=0則代表都找到了)
        char current_char; //當前字元

        for(int end_window=0; end_window<s.size(); end_window++){
            // 如果end_window的字元有包含在t，找到一個
            current_char = s[end_window];
            if(hash[current_char] > 0){
                count--; //多找到一個，因此count
            }
            hash[current_char]--; //更新hash table

            //如果t內的元素都已經找到，則收縮左指標
            while(count == 0){
                //更新最小window size和其開始位置
                if(end_window - start_window + 1 < min_len){
                    min_len = end_window - start_window + 1;
                    min_start = start_window;
                }
                //更新hash table
                current_char = s[start_window];
                hash[current_char]++;
                if(hash[current_char] > 0){
                    count++;
                }
                start_window++;
            }
        }

        if(min_len == INT_MAX){
            return "";
        }
        return s.substr(min_start, min_len);;
    }
};