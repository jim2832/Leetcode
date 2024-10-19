class Solution {
public:
    string reverse_string(string bitString){
        reverse(bitString.begin(), bitString.end());
        return bitString;
    }

    string invert(string bitString) {
        for (char &c : bitString) c = (c == '0') ? '1' : '0';
        return bitString;
    }

    string gene_str(int n){
        if(n == 1) return "0";
        string prev = gene_str(n-1);
        return prev + "1" + reverse_string(invert(prev));
    }

    char findKthBit(int n, int k) {
        return gene_str(n)[k-1];
    }
};