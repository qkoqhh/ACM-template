int lim,bit,rev[NM];
void init(int m){
    for(lim=1,bit=0;lim<m;lim<<=1)bit++;
    inc(i,0,lim-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
}
#define cp complex<double>
cp A[NM],B[NM];
void fft(cp*a,int f=0){
    int n=lim;f=f?-1:1;
    inc(i,0,n-1)if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int k=1;k<n;k<<=1){
	cp t(cos(pi/k),f*sin(pi/k));
	for(int i=0;i<n;i+=k<<1){
	    cp w(1,0);
	    for(int j=0;j<k;j++,w*=t){
		cp x=a[i+j],y=w*a[i+j+k];
		a[i+j]=x+y;a[i+j+k]=x-y;
	    }
	}
    }
    if(f==-1)inc(i,0,n-1)a[i]/=n;
}

int n,m;
int a[NM],b[NM];

int main(){
    n=read()+1;m=read()+1;
    inc(i,0,n-1)a[i]=read();
    inc(i,0,m-1)b[i]=read();
    copy(a,a+n,A);copy(b,b+m,B);
    init(n+m-1);fft(A);fft(B);
    inc(i,0,lim-1)A[i]*=B[i];
    fft(A,1);
    inc(i,0,n+m-2)a[i]=A[i].real()+0.5;
    inc(i,0,n+m-2)printf("%d ",a[i]);putchar('\n');
    return 0;
}
