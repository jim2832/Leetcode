// equilateral: 正三角形
// isosceles: 等腰三角形
// scalene: 其他

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        auto [a, b, c] = tie(nums[0], nums[1], nums[2]);

        if(a + b <= c) return "none";
        if(a == b && b == c) return "equilateral";
        if((a == b) || (b == c)) return "isosceles";

        return "scalene";
    }
};