#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define F first
#define S second
#define pb push_back

typedef pair<int, int> pii;

int maxLenChain(vector<pii> &nums){
    int n = nums.size();
    vector<int> dp(n, 1);
    int max_len = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[j].S<nums[i].F){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        max_len = max(max_len, dp[i]);
    }
    return max_len;
}

int main(){
    vector<pii> arr;
    arr.pb(mp(5, 24));
    arr.pb(mp(15, 25));
    arr.pb(mp(27, 40));
    arr.pb(mp(50, 60));
    cout<<maxLenChain(arr)<<endl;
}
