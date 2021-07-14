# Greedy Algorithm
Greedy algorithm is any algorithm that uses the approach of finding the locally optimal choice at each stage in problem solving.    
Greedy algorithm **does not** always result in the optimal solution, we shall see such an example in the later part of this blog.    
Let us take a look at a problems before moving on to the theory part.    

## Problem
> You're given two binary strings $a$ and $b$ of length $n$, your goal is to make them equal. You can perform the following two operations.     
>&nbsp; &nbsp; 1). swap any two adjacent bits, it costs 1 unit.          
> &nbsp; &nbsp; 2). flip the bit of the string, it costs 1 unit.              
> your goal is to minimise the cost of the total process
> ### Input
> The first line contains one integer that denotes the length of both strings. The next two lines take two strings $a$ and $b$ of length  as an input.
> ### Output
> Print one integer representing the minimal cost of the total operation.
> ### Sample Input
>> 4   
>> 1101    
>> 0011      
> ### Sample Output
>> 2

Now, lets try to solve this question.       
Lets say for some i, $i^{th}$ bit in both strings don't match. If the $i+1^{th}$ bit matches then we can just flip the $i^{th}$ bit. We shall consider only the $i+1^{th}$ bit because we would check for mis matches in increasing order of $i$, it is unreasonable to swap any non adjacent bits because it take $2|i-j|-1$ units for distinct $i$ and $j$, while it takes only $2$ units to flip the bits. From this comparison, it can be seen that swap only requires 1 unit for adjacent bits while flip requires 2. So, it is optimal to swap adjacent bits if $a_i \neq b_i$ , $a_{i+1} \neq b_{i+1}$ and $a_i \neq a_{i+1}$.

The code is given below
``` c++
#include <bits/stdc++.h>
using namespace std

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n,cost=0;
  cin>>n;
  string a,b;
  cin>>a>>b;
  a[n]=b[n]='0';
  for(int i=0;i<n;i++)
  {
    if(a[i]!=b[i])
    {
      cost++;
      if(a[i]!=a[i+1] && b[i+1]!=a[i+1])i++;
    }
  }
      cout<<cost<<'\n';

}
 ```  




## Some content goes here
>Raju and Farhan are two firends, they are working on a program together. Raju spends n minutes working on code, while Farhan spends m minutes working on the code. At any minute only one of them works on the code. The can perform one of the following two operations at in one minute.    
&nbsp; &nbsp; 1. Write a new line of code at the end.    
&nbsp; &nbsp; 2. modify $x^{th}$ line, given that $x^{th}$ line exists.   
> There are $k$ lines of code already when they start working.
> We are given the sequence of operations made by the friends, Raju performs $[a_1,\ a_2,... ,\ a_n]$, if $a_i=0$ then Raju adds a new line to the code, else he modifies the $a_i^{th}$ line. Similarly, for Farhan you are given a sequence $[b_1,\ b_2,...,\ b_m]$. It is known that the sequence of operationa made by both Raju and Farhan are in order, i.e; $a_i$ is done before $a_j$ if $j>i$ and $b_i$ is done before $b_j$ if $j>i$. They can replace each other at the computer any number of times. Your goal is to find any one of the correct sequence of operations (if there exists one), a sequence is considered correct if there are no changes to the lines which do not exist then.       
> ### Input 
> The number of test cases t $(1\leq t \leq 1000)$, for each test case your are given three integers $k$, $n$ and $m$, followed by the sequences $[a_1,\ a_2,... ,\ a_n]$ and $[b_1,\ b_2,...,\ b_m]$, &nbsp; $(0\leq a_i,b_i\leq 300)$
> ### Output
> For each test case print any correct common sequence of Raju's and Farhan's actions of length n+m or -1 if such sequence doesn't exist
> ### &nbsp; &nbsp;Input  
>> 5
>>
>>3 2 2   
>>2 0   
>>0 5   
>>   
>>4 3 2   
>>2 0 5   
>>0 6   
>>  
>>0 2 2   
>>1 0   
>>2 3  
>>   
>>5 4 4   
>>6 0 8 0   
>>0 7 0 9   
>>   
>>5 4 1   
>>8 7 8 0   
>>0
> ### &nbsp; &nbsp; Output
>> 2 0 0 5     
>>0 2 0 6 5    
>>-1    
>>0 6 0 7 0 8 0 9    
>>-1    
> ### Explanation
> For fourth test case, Raju cannot work in the beginning because the sixth line doesn't exist as of yet, So first Farhan will write a new line followed by Raju editing 6th line and then adding a new line, followed by Farhan editing the seventh line and so on. It is easy to understand that this is the only possible sequence of operation. 

Let us discuss the approach for solving this problem.









