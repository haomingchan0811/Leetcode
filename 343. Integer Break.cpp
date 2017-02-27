class Solution {
public:
    // dp: pro[i]->largest product of i
    // O(N2)time, O(N)space, 43.67%, ok
    int integerBreak(int n) {
        vector<int> pro(n + 1, 1);
        for(int i = 3; i <= n; i++){
            for(int j = 1; j <= i / 2; j++){
                pro[i] = max(pro[i], max(j, pro[j]) * max(i - j, pro[i - j]));
            }
        }
        return pro[n];
    }

    // math solution
};
