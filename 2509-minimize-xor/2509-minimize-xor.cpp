class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int targetBits = __builtin_popcount(num2); // num2 的 set bits 數量
        bitset<32> binary(num1);

        // 優先保留 num1 中的高位 1
        for (int i = binary.size() - 1; i >= 0; i--) {
            if (targetBits == 0) {
                binary[i] = 0; // 多餘的高位 1 設為 0
            }
            else if (binary[i] == 1) {
                targetBits--; // 保留高位 1
            }
        }

        // 如果目標 set bits 還不夠，從低位開始補充
        for (int i = 0; i < binary.size(); i++) {
            if (targetBits == 0) break;
            if (binary[i] == 0) {
                binary[i] = 1; // 補充低位 1
                targetBits--;
            }
        }

        return (int)(binary.to_ulong());
    }
};