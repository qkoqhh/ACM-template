inline void reduce(ll&x){x+=x>>63&inf;}

int n,m,cnt[NM];
ll a[nm][NM],b[nm][NM],c[nm][NM];

void ifmt(ll*a){
    for(int i=0;succ(i)<n;i++)
	inc(j,0,n-1)if(j>>i&1)
	    reduce(a[j]-=a[j^1<<i]);
}
void fmt(ll*a){
    for(int i=0;succ(i)<n;i++)
	inc(j,0,n-1)if(j>>i&1)
	    reduce(a[j]+=a[j^1<<i]-inf);
}


int main(){
    m=read();n=1<<m;
    inc(i,0,n-1)cnt[i]=__builtin_popcount(i);
    inc(i,0,n-1)a[cnt[i]][i]=read();
    inc(i,0,n-1)b[cnt[i]][i]=read();
    inc(i,0,m)fmt(a[i]),fmt(b[i]);
    inc(j,0,m)inc(k,0,j)
	inc(i,0,n-1)(c[j][i]+=a[k][i]*b[j-k][i])%=inf;
    inc(i,0,m)ifmt(c[i]);
    inc(i,0,n-1)printf("%lld%c",c[cnt[i]][i]," \n"[i==n-1]);
    return 0;
}
