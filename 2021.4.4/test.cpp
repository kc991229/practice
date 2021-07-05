#include <iostream>
#include <vector>

using namespace std;

//丢失的数字
int missingNumber(vector<int>& nums) {
    int res=0;
    for (int i=0;i<(int)nums.size();i++){
        res=res^i^nums[i];
    }
    res^=nums.size();
    return res;
}

//计数质数
int countPrimes(int n) {
    vector<int> primes;
    vector<int> isPrime(n, 1);
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j <(int) primes.size() && i * primes[j] < n; ++j) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    return primes.size();
}
