class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=1,l=0,h=1,count=1;
        map<int,int> mp;
        mp[nums[l]]++;
        
        while(h<nums.size()){
            mp[nums[h]]++;
            count++; //counting the number of elements in map
            
            if(prev(mp.end())->first - mp.begin()->first <= limit){ // checking the diff 
                ans=max(ans,count); // giving the size of subarray that may make our answer
            }else{
                // If diff is more than limit then we'll start deleting the indexes from left side until we get the max and minimum value such that diff is in range
                while(prev(mp.end())->first - mp.begin()->first > limit && l<h){
                    if(mp[nums[l]]>1)mp[nums[l]]--;
                    else mp.erase(nums[l]);
                    count--;
                    l++;
                }
            }
            h++;
        }
        return ans;
    }
};