ll _x,_y,inf;
int p;

ll qpow(ll x,ll t){return t?qpow(sqr(x)%inf,t>>1)*(t&1?x:1ll)%inf:1ll;}

ll exgcd(ll a,ll b,ll&x,ll&y){
    if(b==0){x=1;y=0;return a;}
    ll t=exgcd(b,a%b,y,x);y-=a/b*x;return t;
}

//a^x=b(mod inf)
//try a=2 b=1111111 inf=12345701 output=9584351
ll bsgs(ll a,ll b){
    map<int,int>v;int n=sqrt(inf)+1,ans=inf;
    ll inv=qpow(a,inf-2),t=qpow(a,n);
    for(int i=0;i<n;i++,b=b*inv%inf)if(!v.count(b))v[b]=i;
    for(int i=0,k=1;i<=n;i++,k=k*t%inf)if(v.count(k))ans=min(ans,v[k]+i*n);
    return ans;
}
