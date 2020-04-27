int main(){
    n=read();m=read();
    inc(i,1,n)a[i]=read(),s+=a[i];
    inc(i,1,n)a[i]*=m,a[i]+=a[i-1];
    inc(i,0,m)inc(j,1,n)d[i][j]=inf;
    d[0][0]=0;
    inc(i,1,m){
	q[qh=qt=1]=i-1;mem(f);mem(v);f[i]=i-1;
	inc(j,i,n){
	    f[j]=max(f[j],f[j-1]);
	    while(qh<=qt&&f[j]!=q[qh])qh++;
	    d[i][j]=d[i-1][q[qh]]+sqr(a[j]-a[q[qh]]-s);
	    int cnt=j+1;
	    while(qh<=qt){
#define fun(t) d[i-1][t]+sqr(a[mid]-a[t]-s)
		cnt=n+1;
		for(int x=j+1,y=n;x<=y;)
		    if(fun(q[qt])>fun(j))cnt=mid,y=mid-1;
		    else x=mid+1;
		if(cnt<=v[q[qt]])qt--;else break;
	    }
	    if(cnt<=n)v[j]=cnt,f[cnt]=j,q[++qt]=j;
	}
    }
    return 0*printf("%lld\n",d[m][n]/m);
}
