namespace Poly{
    int lim,bit,rev[NM],w[NM],W[NM];
    ll invn;
    void clear(ll*a,ll*b){if(a<b)memset(a,0,sizeof(ll)*(b-a));}
    void init(int m){
	for(lim=1,bit=0;lim<m;lim<<=1)bit++;invn=qpow(lim,inf-2);
	inc(i,1,lim-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	ll t=qpow(3,(inf-1)/lim);W[0]=1;
	inc(i,1,lim)W[i]=W[i-1]*t%inf;
    }
    void fft(ll*a,int f=0){
	int n=lim;
	inc(i,1,n-1)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int k=1;k<n;k<<=1){
	    int t=n/k>>1;
	    for(int i=0,j=0;i<k;i++,j+=t)w[i]=W[f?n-j:j];
	    for(int i=0;i<n;i+=k<<1)
		for(int j=0;j<k;j++){
		    ll x=a[i+j],y=w[j]*a[i+j+k]%inf;
		    reduce(a[i+j]=x+y-inf);reduce(a[i+j+k]=x-y);
		}
	}
	if(f)inc(i,0,n-1)a[i]=a[i]*invn%inf;
    }
    ll _a[NM];
    void inv(ll*b,ll*a,int m){
	if(m==1){b[0]=qpow(a[0],inf-2);return;}
	inv(b,a,m+1>>1);init(m<<1);
	copy(a,a+m,_a);clear(_a+m,_a+lim);clear(b+(m+1)/2,b+lim);
	fft(b);fft(_a);
	inc(i,0,lim-1)b[i]=b[i]*(2-_a[i]*b[i]%inf+inf)%inf;
	fft(b,1);
    }
    ll _b[NM];
    void div(ll*c,ll*a,ll*b,int n,int m){
	reverse_copy(a,a+n,c);reverse(b,b+m);
	clear(b+m,b+n-m+1);
	inv(_b,b,n-m+1);reverse(b,b+m);
	init(n-m+1<<1);
	clear(c+n-m+1,c+lim);clear(_b+n-m+1,_b+lim);
	fft(_b);fft(c);
	inc(i,0,lim-1)c[i]=c[i]*_b[i]%inf;
	fft(c,1);
	reverse(c,c+n-m+1);
    }
    void mod(ll*c,ll*a,ll*b,int n,int m){
	div(c,a,b,n,m);
	init(n);
	clear(c+n-m+1,c+lim);
	copy(b,b+m,_b);clear(_b+m,_b+lim);m--;
	fft(_b);fft(c);
	inc(i,0,lim-1)c[i]=c[i]*_b[i]%inf;
	fft(c,1);
	inc(i,0,m-1)reduce(c[i]=a[i]-c[i]);
	clear(c+m,c+lim);clear(_b,_b+lim);
    }
    ll tmp[NM],_c[NM];
    //线性递推专用
    void pow(ll*c,ll*a,ll*b,int m,ll t){
	copy(a,a+m,_c);c[0]=1;clear(c+1,c+m);
	for(;t;t>>=1){
	    if(t&1){
		init(m<<1);clear(_c+m,_c+lim);clear(c+m,c+lim);
		fft(c);fft(_c);
		inc(i,0,lim-1)c[i]=c[i]*_c[i]%inf;
		fft(c,1);fft(_c,1);
		mem(tmp);
		mod(tmp,c,b,m<<1,m);
		copy(tmp,tmp+m,c);
	    }
	    init(m<<1);clear(_c+m,_c+lim);
	    fft(_c);
	    inc(i,0,lim-1)_c[i]=sqr(_c[i])%inf;
	    fft(_c,1);
	    mem(tmp);
	    mod(tmp,_c,b,m<<1,m);
	    copy(tmp,tmp+m,_c);
	}
    }
}
/*
   testdata
   6 4
   3 -1 0 4
   -2 3 1 5
   output
   73
 */
int n;
ll m,a[NM],b[NM],c[NM],ans;


int main(){
    m=read();n=read();
    inc(i,0,n-1)reduce(a[i]=-read());
    reverse(a,a+n);a[n]=1;
    inc(i,0,n-1)reduce(b[i]=read());
    c[1]=1;
    Poly::pow(c,c,a,n+1,m);
    inc(i,0,n-1)reduce(ans+=c[i]*b[i]%inf-inf);
    printf("%lld\n",ans);
    return 0;
}
