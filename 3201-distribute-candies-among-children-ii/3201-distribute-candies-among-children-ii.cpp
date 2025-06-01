class Solution {
public:
    // C^x_2
    long long solve(int x) {
        if(x < 0) return 0;
        return (long)x * (x - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        long long all = solve(n + 2);
        long long one_exceed = 3 * solve(n - (limit + 1) + 2);
        long long two_exceed = 3 * solve(n - 2 * (limit + 1) + 2);
        long long three_exceed = solve(n - 3 * (limit + 1) + 2);

        return all - one_exceed + two_exceed - three_exceed;
    }
};