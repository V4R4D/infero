for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    t = list(map(int,input().split()))
    c = [l[i]/t[i] for i in range(n)]
    d=[i[0] for i in sorted(enumerate(c), key=lambda x:x[1], reverse=True)]
    for i in range(n):
        print(d[i], end=" ")
    print()    