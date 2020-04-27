ll Sqrt(ll t,ll inf){
    ll a=0,w;
    if(qpow(t,inf-1>>1)+1==inf)return -1;
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
	_x=x*x%inf+y*y%inf*w%inf;
	_y=2*x*y%inf;
	x=_x%inf;y=_y%inf;
    }
    return ans;
}
