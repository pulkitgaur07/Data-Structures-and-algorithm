#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> ProductArrayPuzzle(vector<int>& arr){
    int n = arr.size();
    vector<int>ans(n,1);
    int pro = 1;
    for(int i=n-1;i>=0;i--){
        ans[i] = pro;
        pro = pro*arr[i];
    }
    pro = 1;
    for(int i=0;i<n;i++){
        ans[i] = ans[i]*pro;
        pro = pro*arr[i];
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans = ProductArrayPuzzle(arr);
    cout<<"Product Array Puzzle is : ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}