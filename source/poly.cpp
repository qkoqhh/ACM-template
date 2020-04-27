inline void reduce(ll&x){x+=x>>63&inf;}
inline ll qpow(ll x,ll t){
    ll s=1;
    for(;t;t>>=1,x=x*x%inf)if(t&1)s=s*x%inf;
    return s;
}
ll inv[NM];

//solve x^2=t(mod inf)
ll Sqrt(ll t){
    ll a=0,w;
    if(qpow(t,inf-1>>1)+1==inf)return -1;
    srand(time(0));
    do{
	a=rand()%inf;
	w=(sqr(a)-t+inf)%inf;
    }while(qpow(w,inf-1>>1)+1!=inf);
    ll ans=1,_ans=0,_x,_y;
    for(ll n=inf+1>>1,x=a,y=1;n;n>>=1){
	if(n&1){
	    _x=ans*x%inf+_ans*y%inf*w%inf;
	    _y=ans*y%inf+_ans*x%inf;
	    ans=_x%inf;_ans=_y%inf;
	}
	_x=sqr(x)%inf+sqr(y)%inf*w%inf;
	_y=2*x*y%inf;
	x=_x%inf;y=_y%inf;
    }
    return ans;
}
/*
   testdata
   1154323
   inf=998244353
   output
   570381804 or 427862549
 */

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
    /*
       testdata
       3 4
       7741211 4563131 231354345 78784213
       4611513 153131531 44132112 431314040 111
       output
       478854610 284047680 956908296 279654258 728967858 167332085 24933137 759092819 
     */

    ll _a[NM];//used in inv/sqrt/ln

    void inv(ll*b,ll*a,int m){
	if(m==1){b[0]=qpow(a[0],inf-2);return;}
	inv(b,a,m+1>>1);init(m<<1);
	copy(a,a+m,_a);clear(_a+m,_a+lim);clear(b+(m+1)/2,b+lim);
	fft(b);fft(_a);
	inc(i,0,lim-1)b[i]=b[i]*(2-_a[i]*b[i]%inf+inf)%inf;
	fft(b,1);//clear(b+m,b+lim);
    }
    /*
       testdata
       5
       1 6 3 4 9
       output
       1 998244347 33 998244169 1020
     */

    ll _b[NM];//used in div/sqrt/exp

    //c=a/b,d=a%b
    void div(ll*c,ll*d,ll*a,ll*b,int n,int m){
	reverse_copy(a,a+n,c);reverse_copy(b,b+m,d);
	clear(d+m,d+n-m+1);
	inv(_b,d,n-m+1);reverse(d,d+m);
	init(n-m+1<<1);
	clear(c+n-m+1,c+lim);clear(_b+n-m+1,_b+lim);
	fft(_b);fft(c);
	inc(i,0,lim-1)c[i]=c[i]*_b[i]%inf;
	fft(c,1);
	reverse(c,c+n-m+1);clear(c+n-m+1,c+lim);
	init(n);
	copy(c,c+n-m+1,_b);clear(_b+n-m+1,_b+lim);
	m--;clear(d+m,d+lim);
	fft(_b);fft(d);
	inc(i,0,lim-1)d[i]=d[i]*_b[i]%inf;
	fft(d,1);
	clear(d+m,d+lim);clear(_b,_b+lim);
	inc(i,0,m-1)reduce(d[i]=a[i]-d[i]);
    }
    /*
       testdata
       5 1
       1 9 2 6 0 8
       1 7
       output
       c::237340659 335104102 649004347 448191342 855638018
       d::760903695
     */
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
	clear(c+n-m+1,c+lim);clear(_b,_b+lim);
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

    //b should be clean
    void sqrt(ll*b,ll*a,int m){
	if(m==1){b[0]=Sqrt(a[0]);b[0]=min(b[0],inf-b[0]);return;}
	int len=m+1>>1;sqrt(b,a,len);
	inv(_b,b,m);
	init(m<<1);
	ll t=inf+1>>1;
	copy(a,a+m,_a);clear(_a+m,_a+lim);
	fft(_a);fft(_b);
	inc(i,0,lim-1)_b[i]=_a[i]*_b[i]%inf*t%inf;
	fft(_b,1);
	copy(_b+len,_b+m,b+len);
    }
    /*
       tessdata
       7
       1 8596489 489489 4894 1564 489 35789489 
       output
       1 503420421 924499237 13354513 217017417 707895465 411020414
     */

    void ln(ll*b,ll*a,int m){
	inv(b,a,m);
	inc(i,0,m-2)_a[i]=a[i+1]*(i+1)%inf;
	init(m<<1);
	clear(_a+m-1,_a+lim);clear(b+m,b+lim);
	fft(_a);fft(b);
	inc(i,0,lim-1)b[i]=b[i]*_a[i]%inf;
	fft(b,1);
	dec(i,m-1,1)b[i]=b[i-1]*::inv[i]%inf;b[0]=0;
    }
    /*
       testdata
       6
       1 927384623 878326372 3882 273455637 998233543
       output
       0 927384623 817976920 427326948 149643566 610586717
     */

    void exp(ll*b,ll*a,int m){
	if(m==1){b[0]=1;return;}
	exp(b,a,m+1>>1);
	clear(b+(m+1)/2,b+m);
	ln(_b,b,m);
	inc(i,0,m-1)reduce(_b[i]=a[i]-_b[i]);_b[0]++;
	clear(_b+m,_b+lim);clear(b+m,b+lim);
	fft(_b);fft(b);
	inc(i,0,lim-1)b[i]=b[i]*_b[i]%inf;
	fft(b,1);
    }
    /*
       testdata
       6
       0 927384623 817976920 427326948 149643566 610586717
       output
       1 927384623 878326372 3882 273455637 998233543
     */

    vector<ll>p[NM],q[NM];ll _c[NM];//used in build/DIV
    void build(int i,int x,int y,const ll*a){
	if(x==y){p[i].push_back(inf-a[x]);p[i].push_back(1);return;}
	build(i<<1,x,mid,a);build(i<<1|1,mid+1,y,a);
	int n=p[i<<1].size(),m=p[i<<1|1].size();
	init(n+m-1);
	copy(p[i<<1].begin(),p[i<<1].end(),_a);clear(_a+n,_a+lim);
	copy(p[i<<1|1].begin(),p[i<<1|1].end(),_b);clear(_b+m,_b+lim);
	fft(_a);fft(_b);
	inc(j,0,lim-1)_c[j]=_a[j]*_b[j]%inf;
	fft(_c,1);p[i].assign(_c,_c+n+m-1);
    }
    ll _d[NM],ret[NM];//used in DIV
    void DIV(int x,int y){
	if(q[x].size()<p[y].size()){q[y]=q[x];return;}
	copy(q[x].begin(),q[x].end(),_c);copy(p[y].begin(),p[y].end(),_d);
	mod(ret,_c,_d,q[x].size(),p[y].size());
	q[y].assign(ret,ret+p[y].size()-1);
	while(!q[y].back())q[y].pop_back();
    }
    void cal(int i,int x,int y,ll*a){
	if(x==y){a[x]=q[i][0];return;}
	DIV(i,i<<1);DIV(i,i<<1|1);
	cal(i<<1,x,mid,a);cal(i<<1|1,mid+1,y,a);
    }
    //look test() for usage
    /*
       testdata
       10 10
       18 2 6 17 7 19 17 6 2 12 14
       4 15 5 20 2 6 20 12 16 5
     */

    void out(ll*a,int m){inc(i,0,m-1)printf("%lld%c",a[i]," \n"[i==m-1]);}
}



int n,m;
ll a[NM],b[NM],c[NM],d[NM];

void test(){
    n=read()+1;m=read();
    inc(i,0,n-1)a[i]=read();
    inc(i,1,m)b[i]=read();
    Poly::build(1,1,m,b);
    Poly::q[0].assign(a,a+n);
    Poly::DIV(0,1);
    Poly::cal(1,1,m,c);
    inc(i,1,m)printf("%lld\n",c[i]);
}

int main(){
    test();
    return 0;
}
