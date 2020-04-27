ll exgcd(ll a,ll b,ll&x,ll&y){
    if(b==0){x=1;y=0;return a;}
    ll t=exgcd(b,a%b,y,x);y-=a/b*x;return t;
}
