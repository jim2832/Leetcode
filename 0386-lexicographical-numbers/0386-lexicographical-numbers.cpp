class Solution {
public:
    void DFS(int current, int &n, vector<int> &result){
        if(current > n) return;
        if(current) result.emplace_back(current);
        
        current *= 10;
        for(int num=current; num<=current+9; num++){
            if(0 < num && num <= n){
                DFS(num, n, result);
            }
        }
    }

    vector<int> lexicalOrder(int n){
        vector<int> result;
        for(int i=1; i<= 9; i++){
            DFS(i, n, result);
        }
        return result;
    }
};
