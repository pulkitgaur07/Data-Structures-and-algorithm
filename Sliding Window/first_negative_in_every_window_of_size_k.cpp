#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> FirstNegativeInEveryWindowOfSizeK(vector<int>& arr, int k){
    int n = arr.size();
    int i = 0, j = 0;
    int sum = 0, maxSum = INT_MIN;
    vector<int>ans;
    list<int>l;
    while(j < n){
        if(arr[j]<0){
            l.push_back(arr[j]);
        }
        if((j-i+1) < k){
            j++;
        }
        else if((j-i+1) == k){
            if(l.size()==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(l.front());
                if(arr[i]==l.front()){
                    l.pop_front();
                }
            }
            i++; j++;
        }
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
    int k;
    cin>>k;
    vector<int> ans = FirstNegativeInEveryWindowOfSizeK(arr,k);
    cout<<"First Negative In Every Window Of Size K : ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}