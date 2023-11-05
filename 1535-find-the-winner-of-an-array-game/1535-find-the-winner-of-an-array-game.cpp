class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        vector<int>::iterator maxElement = max_element(arr.begin(), arr.end());
        if(k >= arr.size()){
            return *maxElement;
        }

        int the_last_winner = arr[0];
        int consecutive_wins = 0;
        
        for(int i=1; i<arr.size(); i++){
            // the_last_winner remains
            if(the_last_winner > arr[i]){
                consecutive_wins++;
            }
            // the_last_winner loses
            else{
                the_last_winner = arr[i];
                consecutive_wins = 1;
            }
            cout << the_last_winner << endl;
            // the_last_winner wins consecutive k times
            if(consecutive_wins == k){
                return the_last_winner;
            }
        }

        return the_last_winner;
    }
};