void fwt(ll*a,int f){
    if(f==-1)f=inf+1>>1;
    for(int k=1;k<n;k<<=1)
	for(int i=0;i<n;i+=k<<1)
	    for(int j=0;j<k;j++){
		ll x=a[i+j],y=a[i+j+k];
		a[i+j]=f*(x+y)%inf;
		a[i+j+k]=f*(x-y+inf)%inf;
	    }
}
