// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/?envType=problem-list-v2&envId=50vtbd3v

class Solution {
public:    
    int dp[32][2][2];

    int helper(string &num, int ind, bool tight, bool prevOneUsed) {
        if (ind == num.size()) {
            return 1;
        }

        if (dp[ind][tight][prevOneUsed] != -1) {
            return dp[ind][tight][prevOneUsed];
        }

        char limit = tight ? num[ind] : '1';

        int ans = 0;
        for (char digit = '0'; digit <= limit; digit++) {
            bool new_tight = tight && (digit == limit);

            if (digit == '0') {
                ans += helper(num, ind + 1, new_tight, false);
            }
            else {
                if (prevOneUsed == false) {
                    ans += helper(num, ind + 1, new_tight, true);
                }                
            }
        }

        return dp[ind][tight][prevOneUsed] = ans;
    }

    int findIntegers(int n) {    
        memset(dp, -1, sizeof(dp));    
        bitset<32> b(n);
        string temp = "";

        for (int i = 31; i >= 0; i--) {
            temp += (b[i] + '0');
        }        

        cout << temp << endl;

        return helper(temp, 0, true, false);
    }
};
