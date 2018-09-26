#include <bits/stdc++.h>
using namespace std;

int maxHist(int arr[], int n){
    if(n==0) return 0;
    stack<int> st;
    int max_area = arr[0], area, i=0;
    while(i<n){
        if(st.empty() || arr[i]>=arr[st.top()]){
            st.push(i++);
        }else{
            int top = st.top();
            st.pop();

            area = arr[top] * (st.empty()? i: i-st.top()-1);
            max_area = max(max_area, area);
        }
    }
    while(!st.empty()){
        int top = st.top();
        st.pop();

        area = arr[top] * (st.empty() ? i: i-st.top()-1);
        max_area = max(max_area, area);
    }
    return max_area;
}

int main(){
    int arr[] = {2,1,5,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<maxHist(arr, n)<<endl;
}
