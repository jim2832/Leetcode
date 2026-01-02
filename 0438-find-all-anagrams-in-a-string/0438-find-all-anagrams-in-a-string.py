class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []

        p = "".join(sorted(p))
        n = len(p)

        for i in range(len(s) - n + 1):
            substr = s[i:i + n]
            substr = "".join(sorted(substr))
            if(substr == p):
                ans.append(i)

        return ans