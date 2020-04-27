int tot,m;
ll w[NM],pre[NM],f[NM],h[NM],prime[NM],n;
bool v[NM];

inline void reduce(ll&x){x+=x>>63&inf;}
inline int id(ll x){return x<=m/2?m-x+1:n/x;}

void init(){
    m=sqrt(n);
    inc(i,2,m)if(!v[i]){
	prime[++tot]=i;
	for(int j=i<<1;j<=m;j+=i)v[j]++;
    }
    inc(i,1,tot)pre[i]=(pre[i-1]+prime[i])%inf;
    inc(i,1,m)w[i]=n/i;
    while(w[m]>1)w[m+1]=w[m]-1,m++;
}

ll S(ll n,int m){
    if(n<prime[m])return 0;
    ll ans=(f[id(n)]-pre[m-1]+inf)%inf;
    for(int i=m;i<=tot&&prime[i]*prime[i]<=n;i++){
	ll t=prime[i];
	for(int j=1;t*prime[i]<=n;t*=prime[i],j++)
	    reduce(ans+=(prime[i]^j)*S(n/t,i+1)%inf-inf),
	    reduce(ans+=(prime[i]^(j+1))-inf);
    }
    return ans;
}

int main(){
    n=read();
    init();
    inc(i,1,m)
	f[i]=w[i]%inf*((w[i]+1)%inf)%inf*(inf+1)/2%inf-1,
	h[i]=(w[i]-1)%inf;
    inc(j,1,tot){
	inc(i,1,m)if(w[i]>=prime[j]*prime[j]){
	    int k=id(w[i]/prime[j]);
	    reduce(f[i]-=prime[j]*(f[k]-pre[j-1]+inf)%inf);
	    reduce(h[i]-=h[k]-j+1);
	}else break;
    }
    inc(i,1,m-1)f[i]+=2;
    inc(i,1,m)reduce(f[i]-=h[i]);
    inc(i,1,tot)pre[i]=(pre[i-1]+(prime[i]^1))%inf;
    printf("%lld\n",S(n,1)+1);
    return 0;
}
