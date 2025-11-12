#include <bits/stdc++.h>
using namespace std;


bool compare(pair<double,int> p1, pair<double,int> p2){
    return p1.first>p2.first;
}
void fractknapsack(vector<int> &val, vector<int> &wt, double W){
    int n = val.size();
   vector<pair<double,int>> ratio(n,make_pair(0.0,0));

   for(int i=0;i<n;i++){
    double r=val[i]/(double)wt[i];
    ratio[i]=make_pair(r,i);
   }

   sort(ratio.begin(),ratio.end(),compare);
   int ans=0;
   for(int i=0;i<n;i++){
    int idx=ratio[i].second;
    if(wt[idx]<=W){
        ans+=val[idx];
        W-=wt[idx];
    }else{
        ans+=ratio[idx].first*W;
        W=0;
        break;
    }
   }
   cout<<ans<<endl;
}




int main(){
    // vector<int> val = {60, 100, 120};
    // vector<int> wt = {10, 20, 30};
    // double W = 50;
    int W;
    cout<<"Enter Capacity Of Bag"<<endl;
    cin>>W;
    int n; cout<<"Enter No. Of Weight Readings"<<endl;
    cin>>n;
    vector<int>val(n);
    vector<int>wt(n); 
    cout<<"Enter Value And Weight"<<endl;
    for(int i=0;i<n;i++){
        cin>>val[i]>>wt[i];
    }
    cout<<"Maximum Profit:";
    fractknapsack(val, wt, W);
}
