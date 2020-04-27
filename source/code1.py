n=int(input());
a=[[0]*105 for i in range(105)];
if n<=1:
    print(1);
    exit();
elif n==2:
    print(5);
    exit();
for i in range(n):
    a[i][i]=3;
    a[i][0]=a[0][i]=a[i][i+1]=a[i+1][i]=-1;
ans=1;a[0][0]=n;
for i in range(n):
    for j in range(i+1,n):
        x,y=i,j;
        while(a[y][i]!=0):
            t=a[x][i]/a[y][i];
            for k in range(i,n):
                a[x][k]-=t*a[y][k];
            x,y=y,x;
        if a[i][i]==0:
            for k in range(i,n):
                a[i][k],a[j][k]=a[j][k],a[i][k];
for i in range(n):
    ans*=a[i][i];
if ans<0:
    ans=-ans
print(ans);
