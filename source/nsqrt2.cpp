int _x,_y,b[40],c[40],_t,p,tot;
ll inf,ans;
ll qpow(ll x,ll t){return t?qpow(sqr(x)%inf,t>>1)*(t&1?x:1ll)%inf:1ll;}
ll exgcd(ll a,ll b,ll&x,ll&y){
    if(b==0){x=1;y=0;return a;}
    ll t=exgcd(b,a%b,y,x);y-=a/b*x;return t;
}

int gen(int n){
    //m=phi(n)
    int m=n/_t*(_t-1),cnt=m,tot=0,c[40];
    for(int i=2;i*i<=m;i++)if(m%i==0){
	c[++tot]=cnt/i;
	while(m%i==0)m/=i;
    }
    if(m>1)c[++tot]=cnt/m;
    inc(i,1,n){
	bool f=true;
	inc(j,1,tot)if(qpow(i,c[j])==1){f=false;break;}
	if(f)return i;
    }
}

ll bsgs(ll a,ll b){
    map<int,int>v;int n=sqrt(inf)+1,ans=inf;
    ll inv,t;exgcd(a,inf,inv,t);inv%=inf;if(inv<0)inv+=inf;t=qpow(a,n);
    for(int i=0;i<n;i++,b=b*inv%inf)if(!v.count(b))v[b]=i;
    for(int i=0,k=1;i<=n;i++,k=k*t%inf)if(v.count(k))ans=min(ans,v[k]+i*n);
    return ans;
}

ll solve(ll a,ll b){
    int s=0;
    if(b==0){
	while(inf>1)s++,inf/=_t;
	inf=1e9;
	return qpow(_t,s-1-(s-1)/a);
    }
    while(b%_t==0){
	b/=_t;inf/=_t;s++;
    }
    if(s%a)return -1;
    int g=gen(inf),indb=bsgs(g,b);
    ll x,y;ll t=exgcd(a,inf/_t*(_t-1),x,y);
    if(indb%t)return -1;
    inf=1e9;t*=qpow(_t,s-s/a);return t;
}

int main(){
    int _=read();while(_--){
	_x=read();_y=read();p=read()<<1|1;tot=0;
	for(int i=3;i*i<=p;i++)if(p%i==0)
	    for(c[++tot]=1,b[tot]=i;p%i==0;p/=i)c[tot]*=i;
	if(p>2)c[++tot]=p,b[tot]=p;
	ans=1;
	inc(i,1,tot){
	    inf=c[i];_t=b[i];
	    ll t=solve(_x,_y%inf);
	    if(t==-1){ans=-1;break;}
	    ans*=t;
	}
	if(ans==-1)printf("0\n");else printf("%lld\n",ans);
    }
    return 0;
}
