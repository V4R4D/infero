#include <bits/stdc++.h>
using namespace std;

typedef struct Data
{
  int profit;
  int deadline;
} Data;

bool cmpfunc(Data a, Data b)
{
  return a.profit>b.profit;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n; cin>>n;
  Data data[n];
  for(int i=0;i<n;i++) cin>>data[i].profit;
  for(int i=0;i<n;i++) cin>>data[i].deadline;

  sort(data,data+n,cmpfunc);
  int max_deadline=0;
  for(int i=0;i<n;i++)if(max_deadline<data[i].deadline)max_deadline=data[i].deadline;
  bool booked[max_deadline];
  for(int i=0;i<max_deadline;i++)booked[i]=false;
  int profit=0;
  for(int i=0;i<n;i++)
  {
    int j=data[i].deadline-1;
    while(booked[j] && j>-1)j--;
    if(j!=-1){profit+=data[i].profit; booked[j]=true;}
  }
  cout<<profit<<'\n';
}
