#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,amount+1);
    dp[0]=0;
    for (int i=1;i<=amount;i++){
        for (int j=0;j<(int)coins.size();j++){
            if (coins[j]<=i){
                dp[i]=min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int hammingWeight(uint32_t n) {
    int count=0;
    for (int i=0;i<32;i++){
        if (n & 1 == 1)
            count++;
        n=n>>1;
    }
    return count;
}
