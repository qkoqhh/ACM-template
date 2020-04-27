ll sum[105];//k次幂的前n项和
ll fun(ll x){
    ll pre[105],suc[105];
    int n=k+2;
    mem(pre);mem(suc);
    pre[0]=1;
    inc(i,1,n)pre[i]=pre[i-1]*(x-i)%inf;
    suc[n+1]=1;
    dec(i,n,1)suc[i]=suc[i+1]*(x-i)%inf;
    ll ans=0;
    inc(i,1,n)if((n-i)&1){
	ans-=pre[i-1]*suc[i+1]%inf*invp[i-1]%inf
	    *invp[n-i]%inf*sum[i]%inf;
	ans+=inf;ans%=inf;
    }else{ 
	ans+=pre[i-1]*suc[i+1]%inf*invp[i-1]%inf
	    *invp[n-i]%inf*sum[i]%inf;
	ans+=inf;ans%=inf;
    }
    return ans;
}
inc(i,1,k+2)sum[i]=(sum[i-1]+qpow(i,k))%inf;
