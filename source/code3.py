n,s=map(int,input().split())
x=[]
for i in range(n):
 line=input().split()
 x.append((int(line[1]),line[0]))
x=sorted(x)
x=list(reversed(x))
 
ans=[]
 
for i in range(n):
 if s>=x[i][0]:
  s=s-x[i][0]
  ans.append(x[i][1])
 
if s==0:
 print(len(ans))
 for i in range(len(ans)):
  print(ans[i])
else:
  print(0)
