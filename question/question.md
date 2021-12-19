You own a construction firm which has a lot of active projects, but due to unavoidable circumstances you can only work on one project at once now. You are given the number of active projects, the penalty of completing each project late by a day is given. The extra time it would take to complete each project is given.
### Input
The first line is the number of test cases $t$, $1 \leq t \leq 100$, the next line contains a single integer $n$ which is the number of active projects. $1 \leq n \leq 100$. The next line contains $n$ integers $\{ a_1,a_2,\dots,a_n\}$ separated by a space, representing the penalty of delaying the project by one day in thousands, $1 \leq a_i \leq 1000$. The next line contains $n$ integers $\{ b_1,b_2,\dots,b_n\}$ separated by a space, representing the time it would take to complete each project, $1 \leq b_i \leq 1000$. 

### Output
You have to output $n$ integers separated by a space, the order of completing the projects to minimise the penalty, if there are multiple possible answers print the one which has those projects in same order as in the input.

### Input
> 1   
5   
2 3 7 120 8   
4 6 10 12 4  
### Output
> 0 1 2 4 3

