class Solution{
public:
    string longestDiverseString(int a, int b, int c){
        string result;
        priority_queue<pair<int, char>> pq;
        
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        
        while(!pq.empty()){
            auto [count1, char1] = pq.top();
            pq.pop();
            
            // If the last two characters are the same as char1, we need to use the second most frequent character
            if(result.size() >= 2 && result[result.size() - 1] == char1 && result[result.size() - 2] == char1){
                if(pq.empty()){
                    // No other characters available, terminate the loop
                    break;
                }
                
                // Get the second most frequent character
                auto [count2, char2] = pq.top();
                pq.pop();
                
                // Append char2 and reduce its count
                result += char2;
                count2--;
                
                // Re-insert char2 into the heap if there are remaining occurrences
                if(count2 > 0){
                    pq.push({count2, char2});
                }
                
                // Re-insert char1 into the heap for future use
                pq.push({count1, char1});
            }
            else{
                // Append char1 and reduce its count
                result += char1;
                count1--;
                
                // Re-insert char1 into the heap if there are remaining occurrences
                if(count1 > 0){
                    pq.push({count1, char1});
                }
            }
        }
        
        return result;
    }
};
