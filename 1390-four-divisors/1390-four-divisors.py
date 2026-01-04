class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0

        def factors(n):
            factor = []
            for i in range(1, int(math.sqrt(n)) + 1):
                if n % i == 0:
                    factor.append(i)
                    if n // i != i:
                        factor.append(n // i)
            return factor
        
        for num in nums:
            temp = factors(num)
            if(len(temp) == 4):
                ans += sum(temp)
        
        return ans