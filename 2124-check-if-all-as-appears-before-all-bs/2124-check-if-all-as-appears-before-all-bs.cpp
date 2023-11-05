class Solution {
public:
    bool checkString(string s) {
        // appraoch 1
        // bool encounter = false; // if we have encountered "b"
        // for(int i=0; i<s.size(); i++){
        //     if(s[i] == 'a'){
        //         if(encounter){
        //             return false;
        //         }
        //         else{
        //             continue;
        //         }
        //     }
        //     else{ //s[i] == b
        //         encounter = true;
        //     }
        // }

        // return true;

        // approach 2
        string temp = s;
        sort(s.begin(), s.end());
        return s == temp;
    }
};