int n,cnt,tot;
ll f[NM],a[NM],b[NM],p[NM],inv[NM];
ll qpow(ll x,ll t){return t?qpow(sqr(x)%inf,t>>1)*(t&1?x:1ll)%inf:1ll;}

struct FFT{
    int n,bit,rev[NM];
    ll b[NM],invn;
    void fft(ll*a,int f){
	inc(i,0,n-1)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int k=1;k<n;k<<=1){
	    ll t=qpow(3,(inf-1)/k/2);if(f==-1)t=qpow(t,inf-2);
	    for(int i=0;i<n;i+=k<<1){
		ll w=1;
		for(int j=0;j<k;j++,w=w*t%inf){
		    ll x=a[i+j],y=w*a[i+j+k]%inf;
		    a[i+j]=(x+y)%inf;a[i+j+k]=(x-y+inf)%inf;
		}
	    }
	}
    }
    int plu(ll*a,ll*_b,int p,int m){
	inc(i,0,m)b[i]=_b[i];
	for(n=p+m+1,bit=0;succ(bit)<n;bit++);n=succ(bit);
	invn=qpow(n,inf-2);
	inc(i,0,n-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	fft(a,1);fft(b,1);inc(i,0,n-1)a[i]=a[i]*b[i]%inf;
	fft(a,-1);inc(i,0,n-1)a[i]=a[i]*invn%inf;
	inc(i,0,n-1)b[i]=0;
	return m+p;
    }
}fft;

void cdq(int l,int r){
    if(l==r){f[l]=f[l]*inv[l]%inf;return;}
    int mid=l+r>>1,cnt=r-l,tot=mid-l;
    cdq(l,mid);
    inc(i,l,mid)a[i-l]=f[i];
    inc(i,1,cnt)b[i]=1ll*i*i%inf;
    tot=fft.plu(a,b,tot,cnt);
    inc(i,mid+1,r)f[i]+=a[i-l];
    inc(i,0,tot)a[i]=0;
    inc(i,1,cnt)b[i]=0;
    cdq(mid+1,r);
}

int main(){
    n=1e5;inv[1]=p[1]=p[0]=inv[0]=f[0]=1;
    inc(i,2,n)inv[i]=inv[inf%i]*(inf-inf/i)%inf,p[i]=p[i-1]*i%inf;
    cdq(0,n);
    inc(i,1,n)f[i]=f[i]*p[i]%inf;
    while(~scanf("%d",&n))printf("%lld\n",f[n]);
    return 0;
}
