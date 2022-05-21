#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>>activity;
    int n,s,e;
    cout<<"Enter the activities:";
    cout<<"\n";
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cout<<"Enter the start and end time of each activity:"<<"\n";
        cin>>s>>e;
        activity.push_back(make_pair(e,s));
    }
    sort(activity.begin(),activity.end());
    int count=0;
    int currentEnd=-1;
    for(int i=0;i<n;++i)
    {
        if(activity[i].second>currentEnd)
        {
            count++;
        currentEnd=activity[i].first;
        }
    }
    cout<<"\n";
    cout<<"ANSWER:";
    cout<<"Minimum no of processor that we need to run all the activities:\t"<<count;
}