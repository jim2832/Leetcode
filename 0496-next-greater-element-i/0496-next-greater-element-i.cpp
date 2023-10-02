class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        stack<int> s;
        unordered_map<int, int> map;

        // construct the hash table for every element in nums2 vector
        for(int i=0; i<nums2.size(); i++){
            int element = nums2[i];

            while(!s.empty() && element > s.top()){
                map[s.top()] = element;
                s.pop();
            }

            s.push(element);
        }

        // find the element in nums1 vector
        for(int i=0; i<nums1.size(); i++){
            int target = nums1[i];

            // found
            if(map.find(target) != map.end()){
                result[i] = map[target];
            }
        }

        return result;
    }
};