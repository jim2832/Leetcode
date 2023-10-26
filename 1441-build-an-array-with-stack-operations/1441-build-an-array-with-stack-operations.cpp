class Solution {
public:
    //vector模擬stack: push_back & pop_back
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int index = 0;
        int num = 1;

        while(index < target.size()){
            operations.push_back("Push");
            if(num == target[index]){
                index++;
            }
            else{
                operations.push_back("Pop");
            }
            num++;
        }

        return operations;
    }
};