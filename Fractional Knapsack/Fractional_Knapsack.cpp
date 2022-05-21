#include<bits/stdc++.h>
using namespace std;

bool compare(pair<float,int>a,pair<float,int>b)
{
    return a.first>b.first;
}
int Fractional_Knapsack(vector<int>weight,vector<int>value,int capacity)
{
    int length=weight.size();
    int total=0;

    vector<pair<float,int>>profit(length,make_pair(0.0,0));
    for(int i=0;i<length;++i)
        profit[i]=make_pair(value[i]/weight[i],i);
        sort(profit.begin(),profit.end(),compare);

        for(int i=0;i<length;++i)
        {
            if(capacity==0)break;
            int index=profit[i].second;
            if(weight[index]<=capacity)
            {
                capacity-=weight[index];
                total+=value[index];
            }
            else
            {
                int considered_value=value[index]*(float(capacity)/float(weight[index]));
                
                total+=considered_value;
                capacity=0;
            }
        }
    return total;
}


int main()
{
    cout<<"Enter the weight of the items:STOP THE PROGRAM PRESS -1"<<"\n";
    cout<<"\n";

    vector<int>weights;
    while(true)
    {
        int weight;cin >> weight;
 
        if(weight == -1)break;
        weights.push_back(weight);
    }
 
    cout<<"Enter the values of each item:STOP THE PROGRAM PRESS -1"<<"\n";
    cout<<"\n";
     
    vector<int>values;
    while(true)
    {
        int value;cin >> value;

        if(value == -1)break;
        values.push_back(value);
    }
 
    cout<<"Enter the capacity of the knapsack"<<"\n";
    int capacity;cin>>capacity;
 
    cout <<"The maximum profit is :"<< Fractional_Knapsack(weights, values, capacity)<<"\n";
}
