#include <bits/stdc++.h>
using namespace std;

vector<int> LIS(vector<int> &nums){
    vector<int> dp(nums.size(), 1);
    for(int i=1; i<nums.size(); i++){
        for(int j=0; j<i; j++){
            if(nums[j]<nums[i]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }
    return dp;
}

int lbs(vector<int> &nums){
    vector<int> lis = LIS(nums);
    reverse(nums.begin(), nums.end());
    vector<int> lis_rev = LIS(nums);
    reverse(lis_rev.begin(), lis_rev.end());
    int res = 1;
    for(int i=0; i<lis.size(); i++){
        res = max(res, lis[i]+lis_rev[i]-1);
    }
    return res;
}

int main(){
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
    cout<<lbs(nums)<<endl;
}
