#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef pair<int, int> pii;

void printVec(vector<pii> area){
    int n = area.size();
    for(int i=0; i<n; i++){
        cout<<area[i].F<<" "<<area[i].S<<endl;
    }
}

int maxHeight(vector<vector<int>> &boxes){
    vector<pii> area;
    for(int i=0; i<boxes.size(); i++){
        int l = boxes[i][0];
        int b = boxes[i][1];
        int h = boxes[i][2];
        area.pb(mp(l*b, h));
        area.pb(mp(b*h, l));
        area.pb(mp(l*h, b));
    }
    sort(area.begin(), area.end());
    printVec(area);
    int n = area.size();
    vector<int> dp(n, 0);
    int max_h = 0;
    for(int i=0; i<n; i++){
        dp[i] = area[i].S;
        for(int j=0; j<i; j++){
            if(area[i].F>area[j].F){
                dp[i] = max(dp[i], area[i].S + dp[j]);
            }
        }
        max_h = max(max_h, dp[i]);
    }
    return max_h;
}

int main(){
    int arr[4][3] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    vector<vector<int>> boxes;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        vector<int> tmp;
        tmp.pb(arr[i][0]);
        tmp.pb(arr[i][1]);
        tmp.pb(arr[i][2]);
        boxes.pb(tmp);
    }
    cout<<maxHeight(boxes)<<endl;
}
