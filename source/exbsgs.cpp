int x,y;
ll inf;
ll qpow(ll x,ll t){return t?qpow(sqr(x)%inf,t>>1)*(t&1?x:1ll)%inf:1ll;}
void exgcd(ll a,ll b,ll&x,ll&y){if(b==0)x=1,y=0;else exgcd(b,a%b,y,x),y-=a/b*x;}


//try a=4560 b=848750 inf=1203550 ans=783
ll bsgs(ll a,ll b){
    int s=0;ll x,y;
    a%=inf;b%=inf;
    for(int i=0,t=1%inf;succ(i)<=inf;i++,t=t*a%inf)if(t==b)return i;
    for(int t=__gcd(a,inf);t>1;t=__gcd(a,inf)){
	if(b%t)return -1;
	s++;b/=t;inf/=t;
	exgcd(a/t,inf,x,y);x%=inf;if(x<0)x+=inf;
	b*=x;b%=inf;
    }
    map<int,int>v;int n=sqrt(inf)+1,ans=inf;a%=inf;
    ll inv,t=qpow(a,n);
    exgcd(a,inf,inv,y);
    inv%=inf;
    if(inv<0)inv+=inf;
    for(int i=0;i<n;i++,b=b*inv%inf)
	if(!v.count(b))v[b]=i;
    for(int i=0,k=1;i<n;i++,k=k*t%inf)
	if(v.count(k))ans=min(ans,v[k]+i*n);
    if(ans==inf)return -1;else return ans+s;
}

int main(){
    while(~scanf("%d%lld%d",&x,&inf,&y)&&(x||y||inf)){
	if(y>=inf){puts("No Solution");continue;}
	int t=bsgs(x,y);
	if(t==-1)puts("No Solution");else printf("%d\n",t);
    }
    return 0;
}
