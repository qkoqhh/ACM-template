ll inf,_x,_y;

ll qpow(ll x,ll t){return t?qpow(sqr(x)%inf,t>>1)*(t&1?x:1ll)%inf:1ll;}
ll exgcd(ll a,ll b,ll&x,ll&y){
    if(b==0){x=1;y=0;return a;}
    ll t=exgcd(b,a%b,y,x);y-=a/b*x;return t;
}



//保证n一定存在原根
int gen(int n){
    int m=n-1,cnt=m,tot=0,c[30];
    for(int i=2;i*i<m;i++)if(m%i==0){
	c[++tot]=cnt/i;
	while(m%i==0)m/=i;
    }
    if(m>2)c[++tot]=cnt/m;
    inc(i,1,n){
	bool f=true;
	inc(j,1,tot)if(qpow(i,c[j])==1){f=false;break;}
	if(f)return i;
    }
}

ll bsgs(ll a,ll b){
    map<int,int>v;int n=sqrt(inf)+1,ans=inf;
    ll inv=qpow(a,inf-2),t=qpow(a,n);
    for(int i=0;i<n;i++,b=b*inv%inf)if(!v.count(b))v[b]=i;
    for(int i=0,k=1;i<n;i++,k=k*t%inf)
	if(v.count(k))ans=min(ans,v[k]+i*n);
    return ans;
}


//inf为质数
void solve(int a,int b){
    if(_y==0){printf("1\n0\n");return;}
    int g=gen(inf),indb=bsgs(g,b);
    ll x,y;ll t=exgcd(a,inf-1,x,y);x%=(inf-1)/t;if(x<0)x+=(inf-1)/t;
    if(indb%t){printf("0\n");return;}
    x*=indb/t;x%=(inf-1)/t;
    int tot=0,c[100005];//答案个数
    if(b==1)c[++tot]=0;
    for(;x<inf-1;x+=(inf-1)/t)c[++tot]=qpow(g,x);
    sort(c+1,c+1+tot);
    printf("%d\n",tot);inc(i,1,tot)printf("%d ",c[i]);putchar('\n');
}

int main(){
    inf=read();_x=read();_y=read();
    solve(_x,_y);
    return 0;
}
