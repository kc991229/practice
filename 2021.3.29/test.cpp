#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;

//最长连续序列
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> myset;
    for (auto n : nums){
        myset.insert(n);
    }
    int longer=0;
    for (auto n : myset){
        if (!myset.count(n-1)){
            int tmpnum=n;
            int tmplonger=1;
            while (myset.count(tmpnum+1)){
                tmpnum++;
                tmplonger++;
            }
            longer=max(tmplonger,longer);
        }
    }
    return longer;
}


