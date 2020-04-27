void stling(int n){
    if(n==0){st[0]=1;return;}
    if(n==1){st[0]=0;st[1]=1;return;}
    int m=n>>1;
    stling(m);
    inc(i,0,m)a[i]=st[i]*p[i]%inf;
    b[m]=1;dec(i,m-1,0)b[i]=b[i+1]*m%inf*inv[m-i]%inf;
    init(n+1);
    clear(a+m+1,a+lim);clear(b+1+m,b+lim);
    fft(b);fft(a);
    inc(i,0,lim-1)b[i]=a[i]*b[i]%inf;
    fft(b,1);
    copy(b+m,b+lim,b);clear(b+lim-m,b+lim);
    inc(i,0,m)b[i]=b[i]*invp[i]%inf;
    fft(b);fft(st);
    inc(i,0,lim-1)st[i]=st[i]*b[i]%inf;;
    fft(st,1);
    if(n&1)dec(i,n,1)reduce(st[i]=(n-1)*st[i]%inf-inf+st[i-1]);
}
