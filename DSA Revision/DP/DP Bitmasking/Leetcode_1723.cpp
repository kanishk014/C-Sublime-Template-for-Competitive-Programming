// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/?envType=problem-list-v2&envId=50vt8ied

class Solution {
public:    
    int dp[13][5000];

    vector<int> result;

    int helper(vector<int> &jobs, int k, int usedMask) {
        int n = jobs.size();

        if (k == 0) {
            if (usedMask == ((1 << n) - 1)) {                
                return 0;
            }        
            
            return INT_MAX;
        }        

        if (dp[k][usedMask] != -1) {
            return dp[k][usedMask];
        }        

        int ans = INT_MAX;

        // Trick to generate submasks from usedMask
        int notTakenMask = 0;

        for (int i = 0; i < n; i++) {
            if (((1 << i) & usedMask) == 0) {
                notTakenMask = notTakenMask | (1 << i);
            }
        }

        int new_mask = notTakenMask;

        while (new_mask > 0) {
            int sum = result[new_mask];            
            ans = min(ans, max(sum, helper(jobs, k - 1, new_mask | usedMask)));
            new_mask = (new_mask - 1) & notTakenMask;
        }        

        return dp[k][usedMask] = ans;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();     

        memset(dp, -1, sizeof(dp));  
        result.resize(1 << n);   

        for (int mask = 0; mask < (1 << n); mask++) {
            for (int j = 0; j < n; j++) {
                if ((1 << j) & mask) {
                    result[mask] += jobs[j];
                }
            }
        }

        return helper(jobs, k, 0);
    }
};
