//Implement a problem of activity selection problem with K persons. 
//Statement: Given two arrays S[] and E[] of size N denoting starting and closing time
//of the shops and an integer value K denoting the number of people, the task is to 
//find out the maximum number of shops they can visit in total if they visit each shop
//optimally based on the following conditions:
//1. A shop can be visited by only one person.
//2. A person cannot visit another shop if its timing collides with i

#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cout<<"enter the number of shops:";
    cin>>N;
    cout<<"enter the number of people:";
    cin>>K;
    vector<int>S(N),E(N);
    cout<<"Enter start time of shopes:";
    for( int i=0;i<N;i++){
        cin>>S[i];
    }
    cout<<"Enter the end time of shopes:";
    for(int i=0;i<N;i++){
        cin>>E[i];
    }
    vector<pair<int,int>>shops;
    for(int i=0;i<N;i++){
        shops.push_back({S[i],E[i]});
    }
    sort(shops.begin(),shops.end(),[](const pair<int,int>& a,const pair<int,int>& b){
        return a.second<b.second;
    });
    vector<int> free_time(K,0);
    int total=0;
    for(auto&shop:shops){
        for(int p=0;p<K;p++){
            if(free_time[p]<=shop.first){
                free_time[p]=shop.second;
                total++;
                break;
            }
        }
    }
    cout<<"max shops visited:"<<total<<endl;
    return 0;
}