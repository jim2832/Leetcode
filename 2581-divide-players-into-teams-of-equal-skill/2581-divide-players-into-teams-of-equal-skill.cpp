class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int i = 0, j = skill.size() - 1;
        long long target = skill[i] + skill[j], sum = 0;

        while(i <= j){
            if(skill[i] + skill[j] != target) return -1;
            sum += (skill[i] * skill[j]);
            i++;
            j--;
        }

        return sum;
    }
};