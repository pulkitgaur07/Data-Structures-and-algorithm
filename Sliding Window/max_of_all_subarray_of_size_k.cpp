#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> MaxOfAllSubarrayOfSizeK(vector<int>& arr, int k){
    int n = arr.size();
    int i = 0, j = 0;
    vector<int>ans;
    list<int>l;
    while(j < n){
        while(l.size()>0 && l.back()<arr[j]){
            l.pop_back();
        }
        l.push_back(arr[j]);
        if((j-i+1)<k){
            j++;
        }
        else if((j-i+1)==k){
            ans.push_back(l.front());
            if(arr[i] == l.front()){
                l.pop_front();
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
    vector<int> ans = MaxOfAllSubarrayOfSizeK(arr,k);
    cout<<"Max Of All Subarray Of Size K : ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}