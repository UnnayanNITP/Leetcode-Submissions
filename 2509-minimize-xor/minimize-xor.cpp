class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // num1 and num2 
        // x same number of bits as num2 
        // x XOR  num1 is minimal
        // return x 
         
         // convert num 1 and num 2 into bitwise
         ///
           int bits_needed = __builtin_popcount(num2);
           int x = 0;
            for (int i = 31; i >= 0; --i) {
        if (bits_needed > 0 && (num1 & (1 << i))) {
            x |= (1 << i);
            --bits_needed;
        }
    }

    for (int i = 0; i < 32 && bits_needed > 0; ++i) {
        if (!(x & (1 << i))) {
            x |= (1 << i);
            --bits_needed;
        }
    }

    return x;
    }
};