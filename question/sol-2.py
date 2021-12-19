for _ in range(int(input())):
    n,r = map(int,input().split())
    n = n%10
    count = 1
    while (n*count)%10 not in [0,r]:
        count = count+1
    print(count)