class Solution {
public:
    int add(int a, int b) {
    while (b != 0) {
            // Calculate carry
            int carry = a & b;

            // Sum of bits of a and b where at least one of the bits is not set
            a = a ^ b;

            // Carry is shifted by one so that adding it to a gives the correct sum
            b = carry << 1;
        }

        return a;
    }

    int getSum(int a, int b) {
        // return add(a, b);

        return log2(pow(2,a) * pow(2,b));
    }
};