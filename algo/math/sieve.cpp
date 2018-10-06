#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define pb push_back

int spf[MAX];

void sieve(){
    spf[1] = 1;
    for(int i=2; i<MAX; i++) spf[i] = i;
    for(int i=4; i<MAX; i+=2) spf[i] = 2;
    for(int i=3; i*i<MAX; i++){
        if(spf[i]==i){
            for(int j=i*i; j<MAX; j+=i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> getFactors(int x){
    vector<int> ret;
    while(x!=1){
        ret.pb(spf[x]);
        x /= spf[x];
    }
    return ret;
}

void printPrimes(){
    for(int i=2; i<MAX; i++){
        if(spf[i]==i) cout<<spf[i]<<" ";
    }
    cout<<endl;
}

void printVec(vector<int> vec){
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
    cout<<endl;
}

int main(){
    sieve();
    int x = 12246;
    vector<int> tmp = getFactors(x);
    //printPrimes();
    printVec(tmp);
}
