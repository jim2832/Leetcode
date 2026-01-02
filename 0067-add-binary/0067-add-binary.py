class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry = 0
        ans = ""

        idxA = len(a) - 1
        idxB = len(b) - 1

        while idxA >= 0 or idxB >= 0 or carry:
            if idxA >= 0:
                carry += int(a[idxA])
                idxA -= 1
            if idxB >= 0:
                carry += int(b[idxB])
                idxB -= 1
            ans += str(carry % 2)
            carry //= 2
        
        return ans[::-1]