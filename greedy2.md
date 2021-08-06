# Greedy Algorithm
Greedy algorithm is any algorithm that uses the approach of finding the locally optimal choice at each stage in problem solving.    
Greedy algorithm **does not** always result in the optimal solution, we shall see such an example in the later part of this blog.    
Let us take a look at a few standard problems to understand greedy algorithm.    

## Problem (Fractional Knapsack Problem)
> You have been blessed with the power to predict the prices of shares of $n$ companies a day later. You want to make maximum profit out of this oppurtunity. You can buy fraction of a share like in mutual funds, but you cannot buy more than one share of any company. Assume that you don't have to share your profit with brocker. You have $x$ rupees to begin with, your goal is to maximise the profit.   
> ### Input   
> An integer $t$ representing the number of test cases $(1 \leq t \leq 100)$. The next line contains the number of companies $n$, $(1 \leq n \leq 100)$ and the amount you have $x$, $(1 \leq x 1000)$.. The next line is a sequence of $n$ integers reprsenting the current prices of listed shares.
> ### Output
> One single integer denoting the maximum profit. (If the answer is a decimal number truncate it).
> ### Input
>> 1   
>> 4 150   
>> 60 50 80 100   
>> 120 40 200 110   
> ### Output
>> 181
> ### Explanation
> you will buy $1$ share of first company, $1$ for third company, and $0.1$ for fourth company.      

Lets discuss an approach to the problem.   
We will sort the arrays in descending order of profit ratio, that would be $80\ 50\ 100\ 50$. Then, we would start buying the shares in descending order until we run out of money. Notice that we would never buy a share which doesn't result in profit. The code for this problem is given below.
``` c++
#include <bits/stdc++.h>
using namespace std;

struct vals
{
  int a;
  int b;
};
typedef struct vals val;

bool cmpfunc(val l1, val l2)
{
  return (double)l1.b/l1.a>(double)l2.b/l2.a;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,x; cin>>n>>x;
    val l[n];
    for(int i=0;i<n;i++) cin>>l[i].a;
    for(int i=0;i<n;i++) cin>>l[i].b;
    sort(l,l+n,cmpfunc);
    int i=0,profit=0;
    while(x>=l[i].a && l[i].b-l[i].a>0 && i<n)
    {
      profit+=l[i].b-l[i].a;
      x-=l[i].a;
      i++;
    }
    if(x>0 && i<n && l[i].b-l[i].a>0)
    {
      profit+=x*(double)(l[i].b-l[i].a)/l[i].a;
    }
    cout<<profit<<'\n';
  }
}
```
You can read for fractional knasack problem [here](https://www.geeksforgeeks.org/fractional-knapsack-problem/)

## Problem (Job Sequence)
> You are a working as a freelancer, you find $n$ tasks, each task takes you a day to complete and has certain profit. Your client wants the task to be completed in certain time range. Pick the tasks to maximise your profit.
> ### Input
> An integer $n\ (n \leq 10)$ representing the number of tasks available, the next line contains $n$ integers representing the profit generated from each (Sum being less than $10^6$), followed by $n$ integers representing the deadline for each task $(\leq n)$  
> ### Output
> A single integer representing the maximum profit
> ### Input
>> 6      
>> 10 20 30 40 50 100    
>> 1 1 3 3 4 4
> ### Output
>> 220    
> ### Explanation
> The tasks that are picked are such that the profit is maximised, we will pick the tasks with profit $30, \, 40,\, 50,\, 100$ 

### Solution
Since, we want the maximum profit, we'll try to do all the tasks that result in higher profit. First arrange the tasks in descending order of profit, Now start checking if a task can be done or not. For that assign each task that is being done to a particular day. Assign it to the day that is still not occupied with another task such that it is close to deadline.

``` c++
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

  // arranging the taks in descending order of profit
  sort(data,data+n,cmpfunc);   
  int max_deadline=0;
  for(int i=0;i<n;i++)
    if(max_deadline<data[i].deadline)
      max_deadline=data[i].deadline;

  // at max max_deadline tasks can be completed
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
```
