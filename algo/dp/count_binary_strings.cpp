#include <bits/stdc++.h>
using namespace std;

int countStrings(int n){
    int a[n];
    int b[n];
    a[0] = 1;
    b[0] = 1;
    for(int i=1; i<n; i++){
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1] + b[n-1];
}

int main(){
    cout<<countStrings(3)<<endl;
    cout<<countStrings(7)<<endl;
    cout<<countStrings(9)<<endl;
}
