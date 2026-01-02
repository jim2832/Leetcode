class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        hashMap = defaultdict(int)
        start = 0
        max_len = 0
        max_freq = 0

        for end in range(len(s)):
            hashMap[s[end]] += 1
            max_freq = max(max_freq, hashMap[s[end]])

            while (end - start + 1) - max_freq > k:
                hashMap[s[start]] -= 1
                start += 1

            max_len = max(max_len, end - start + 1)

        return max_len