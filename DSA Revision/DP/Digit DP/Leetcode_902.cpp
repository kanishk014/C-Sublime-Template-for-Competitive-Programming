// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/?envType=problem-list-v2&envId=50vtbd3v

class Solution {
public:
    int dp[12][2][2];

    int helper(vector<string> &digits, string &num, int ind, bool isTight, bool formed, string curr = "") {
        if (ind == num.size()) {
            cout << curr << endl;
            return 1;
        }

        if (dp[ind][isTight][formed] != -1) {
            return dp[ind][isTight][formed];
        }

        int limit = isTight ? (num[ind] - '0') : 9;
        int ans = 0;

        if (formed == false) {
            ans += helper(digits, num, ind + 1, false, false, curr + '0');
        }

        for (int i = 0; i < digits.size(); i++) {
            int digit = stoi(digits[i]);            
            bool new_tight = isTight && (digit == limit);

            if (digit <= limit) {
                if (formed) {
                    ans += helper(digits, num, ind + 1, new_tight, true, curr + to_string(digit));
                }
                else {
                    if (digit > 0) {
                        ans += helper(digits, num, ind + 1, new_tight, true, curr + to_string(digit));
                    }
                    else {
                        ans += helper(digits, num, ind + 1, new_tight, false, curr + to_string(digit));
                    }
                }
            }
        }

        return dp[ind][isTight][formed] = ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp, -1, sizeof(dp));
        string N = to_string(n);

        return helper(digits, N, 0, true, false) - 1;
    }
};
