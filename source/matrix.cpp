inline void reduce(ll&x){x+=x>>63&inf;}
inline ll qpow(ll x,ll t){
    ll s=1;
    for(;t;t>>=1,x=x*x%inf)if(t&1)s=s*x%inf;
    return s;
}
int n,tot,_x,_y;
ll a[NM][NM];
struct P{int x,y;};
vector<P>vec[NM];
ll ans;


ll cal(){
    ll s=1;
    int cnt=0;
    inc(i,1,n)inc(j,1,n)reduce(a[i][j]);
    inc(i,1,n)inc(j,i+1,n){
	for(int x=i,y=j;a[y][i];swap(x,y)){
	    ll t=a[x][i]*qpow(a[y][i],inf-2)%inf;
	    inc(k,i,n)reduce(a[x][k]-=t*a[y][k]%inf);
	}
	if(!a[i][i])swap(a[i],a[j]),cnt^=1;
    }
    inc(i,1,n)s=s*a[i][i]%inf;
    if(cnt)reduce(s=-s);
    return s;
}

int main(){
    n=read()-1;tot=succ(n)-1;
    inc(i,1,n){
	int m=read();
	while(m--){
	    _x=read();_y=read();
	    vec[i].push_back({_x,_y});
	}
    }
    inc(i,0,tot){
	mem(a);
	inc(j,1,n)if(i>>(j-1)&1)for(auto&k:vec[j]){
	    a[k.x][k.y]--;a[k.y][k.x]--;
	    a[k.x][k.x]++;a[k.y][k.y]++;
	}
	if(__builtin_popcount(i^tot)&1)reduce(ans-=cal());
	else reduce(ans+=cal()-inf);
    }
    printf("%lld\n",ans);
    return 0;
}
