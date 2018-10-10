#include <bits/stdc++.h>
using namespace std;

string fract(int a, int b){
    int i = a/b;
    string res = "";
    int rem = a%b;
    res+=to_string(i);
    if(rem==0) return res;
    unordered_map<int, int> rems;
    string nr="", r = ""; int itr=0;
    while(rem!=0 && rems.find(rem)==rems.end()){
        rems[rem] = itr++;
        rem = rem*10;
        i = rem/b;
        rem = rem%b;
        nr+=to_string(i);
    }
    if(rem!=0){
        nr.insert(nr.begin() + rems[rem], '(');
        nr.push_back(')');
    }
    res+="."+nr;
    return res;
}

int main() {
	//code
	int t; cin>>t;
	while(t--){
	    int a, b; cin>>a>>b;
	    cout<<fract(a, b)<<endl;
	}
	return 0;
}
