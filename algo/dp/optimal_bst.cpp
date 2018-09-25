#include <bits/stdc++.h>
using namespace std;

int optimalCost(int freq[], int n){
    int cost[n][n];
    int pSum[n];
    memset(pSum, 0, sizeof(pSum));
    pSum[0] = freq[0];
    for(int i=1; i<n; i++){
        pSum[i] = freq[i] + pSum[i-1];
    }
    for(int i=0; i<n; i++){
        cost[i][i] = freq[i];
    }
    for(int l=2; l<=n; l++){
        for(int i=0; i<n-l+1; i++){
            int j = i+l-1;
            int fsum = pSum[j];
            if(i>0) fsum-= pSum[i-1];
            cost[i][j] = INT_MAX;
            for(int k=i; k<=j; k++){
                int tmp = 0;
                if(k-1>=i) tmp+= cost[i][k-1];
                if(j>=k+1) tmp+= cost[k+1][j];
                cost[i][j] = min(cost[i][j], fsum+tmp);
            }
        }
    }
    return cost[0][n-1];
}

int main(){
    // Assuming keys are in sorted order
    // and therefore corresponding frequencies
    int keys[] = {10, 12, 20, 40};
    int freq[] = {34, 8, 50, 23};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout<<optimalCost(freq, n)<<endl;
}
