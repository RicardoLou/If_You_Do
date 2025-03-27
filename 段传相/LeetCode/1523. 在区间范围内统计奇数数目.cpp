class Solution {
public:
    int countOdds(int low, int high) {
        int x = 0;
        if (low == high) {
            if (low % 2 == 1) {
                x++;
            }
            return x;
        }
        if (low % 2 == 1) {
            x++;
        }
        if (high % 2 == 1) {
            x++;
        }
        if (low % 2 == 1 && high % 2 == 1) {
            x += (high - low - 1) / 2;
        }
        else {
            x += (high - low) / 2;
        }

        return x;
    }
};