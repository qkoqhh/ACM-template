int n,m,v[NM],q[NM],qh,qt,f[NM];
ll a[NM];
ll d[NM],ans;
 
inline ll cost(int x,int y){
    if((y-x+1)&1)return a[y]-a[mid]-a[mid-1]+a[x-1];
    return a[y]-a[mid]-a[mid]+a[x-1];
}
 
inline int check(ll t){
    mem(f);q[qh=qt=1]=0;
    inc(i,1,n){
	f[i]=max(f[i],f[i-1]);
	while(qh<=qt&&f[i]!=q[qh])qh++;
	d[i]=d[q[qh]]+cost(q[qh]+1,i)+t;
	while(qh<=qt&&v[q[qt]]>i&&d[q[qt]]+cost(q[qt]+1,v[q[qt]])>=d[i]+cost(i+1,v[q[qt]]))qt--;
	int s=n+1;
	if(qh>qt)s=i+1;else
	for(int x=max(i+1,v[q[qt]]),y=n;x<=y;)
	    if(d[q[qt]]+cost(q[qt]+1,mid)>=d[i]+cost(i+1,mid))
		s=mid,y=mid-1;
	    else x=mid+1;
	if(s<=n)v[i]=s,f[s]=i,q[++qt]=i;
    }
    int s=0;
    for(int x=n;x;x=f[x])s++;
    //printf("%lld %d\n",t,s);
    //inc(i,1,n)printf("%lld ",d[i]);putchar('\n');
    //inc(i,1,n)printf("%d ",f[i]);putchar('\n');
    return s;
}
 
 
int main(){
    //freopen("data.in","r",stdin);
    n=read();m=read();
    inc(i,1,n)a[i]=read()+a[i-1];
    for(ll x=0,y=inf;x<=y;)
	if(check(mid)>=m){
	    ans=d[n]-mid*m;
	    x=mid+1;
	}else y=mid-1;
    return 0*printf("%lld\n",ans);
}
