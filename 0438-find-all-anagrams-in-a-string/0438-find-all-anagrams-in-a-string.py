class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        hashMapP = defaultdict(int)
        hashMapS = defaultdict(int)
        start = 0
        ans = []

        for c in p:
            hashMapP[c] += 1
        
        for end in range(len(s)):
            hashMapS[s[end]] += 1

            while(end - start + 1 > len(p)):
                hashMapS[s[start]] -= 1
                if hashMapS[s[start]] == 0:
                    del hashMapS[s[start]]
                start += 1
            
            if(hashMapS == hashMapP):
                ans.append(start)

        return ans