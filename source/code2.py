n,m=map(int,input().split())
a=[0]
b=[0]
for i in range(n):
    b.append(int(input()))
for i in range(n):
    a.append(int(input()))
a=sorted(a)
b=sorted(b)
d=[0]*(n+1)
d[0]=1
cnt=0
for i in range(1,n+1):
    while cnt<=n and a[i]>b[cnt]:
        cnt+=1
    for j in range(i,0,-1):
        if cnt-j>0:
	        d[j]+=d[j-1]*(cnt-j)

p=[1]
for i in range(n):
    p.append(p[i]*(i+1))

for i in range(n+1):
    d[i]=d[i]*p[n-i]


c=[[0]*(n+1) for i in range(n+1)]
c[0][0]=1
for i in range(n):
    for j in range(i+1):
        c[i+1][j]+=c[i][j]
        c[i+1][j+1]+=c[i][j]

f=[0]*(n+1)
for i in range(0,n+1):
    for j in range(i,n+1):
        if (j-i)&1:
            f[i]-=d[j]*c[j][i]
        else:
            f[i]+=d[j]*c[j][i]
ans=0
for i in range(0,m+1):
    ans+=f[i]
print(ans)
