// https://leetcode.com/problems/numbers-with-repeated-digits/description/?envType=problem-list-v2&envId=50vtbd3v

class Solution {
public:
    int dp[10][2][1025][2];

    int helper(string &digits, int ind, bool isRepeat, int mask, bool isTight) {
        if (ind == digits.size()) {
            return isRepeat ? 1 : 0;
        }

        if (dp[ind][isRepeat][mask][isTight] != -1) {
            return dp[ind][isRepeat][mask][isTight];
        }
        
        char limit = isTight ? digits[ind] : '9';

        int ans = 0;

        for (char digit = '0'; digit <= limit; digit++) {
            bool newTight = isTight && (digit == limit);     
            bool newRepeat = isRepeat;       

            if (digit == '0' and mask == 0) {
                ans += helper(digits, ind + 1, newRepeat, mask, newTight);
                continue;
            }

            if (mask & (1 << (digit - '0'))) {
                newRepeat = true;
            }
            
            int new_mask = mask | (1 << (digit - '0'));
            ans += helper(digits, ind + 1, newRepeat, new_mask, newTight);            
        }   

        return dp[ind][isRepeat][mask][isTight] = ans;     
    }

    int numDupDigitsAtMostN(int n) {          
        string N = to_string(n);        

        memset(dp, -1, sizeof(dp));
        
        return helper(N, 0, false, 0, true);        
    }
};
