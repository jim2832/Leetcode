class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        ans = 0
        for word in words:
            if(word[:len(pref)] == pref and len(word) >= len(pref)):
                ans += 1
        return ans