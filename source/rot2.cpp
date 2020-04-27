struct P{ 
    double x,y; 
    P(double x=0,double y=0):x(x),y(y){} 
    P operator‐(const P&o){return P(x‐o.x,y‐o.y);} 
    double operator*(const P&o){return x*o.y‐y*o.x;} 
    double operator%(const P&o){return x*o.x+y*o.y;} 
}a[NM],b[NM]; 
double dis(P o){return sqrt(sqr(o.x)+sqr(o.y));} 
int n,m; 
double ans; 
double getd(P a,P b,P c){ 
    if((b‐c)%(a‐c)<‐eps)return dis(a‐c); 
    if((c‐b)%(a‐b)<‐eps)return dis(a‐b); 
    return fabs((a‐b)*(c‐b))/dis(b‐c); 
} 
double lined(P a,P b,P c,P d){return 
min(min(getd(a,c,d),getd(b,c,d)),min(getd(c,a,b),getd(d,a,b)));} 
void rorate(P a[],P b[],int n,int m){ 
    int i=1,j=1,tmp; 
    a[n+1]=a[i];b[m+1]=b[1]; 
    inc(k,1,n)if(a[k].y<a[i].y)i=k; 
    inc(k,1,m)if(b[k].y>b[j].y)j=k; 
    inc(k,1,n){ 
        while(tmp=(b[j+1]‐a[i])*(a[i+1]‐a[i])‐(b[j]‐a[i])*(a[i+1]‐
a[i])>eps)j=j%m+1; 
        if(tmp<‐eps)ans=min(ans,getd(b[j],a[i],a[i+1])); 
        else ans=min(ans,lined(b[j],b[j+1],a[i],a[i+1])); 
        //printf("%lf\n",ans); 
        i=i%n+1; 
    } 
} 
int main(){ 
    //freopen("data.in","r",stdin); 
    while(n=read()){ 
        m=read();ans=inf; 
        dec(i,n,1)scanf("%lf%lf",&a[i].x,&a[i].y); 
        dec(i,m,1)scanf("%lf%lf",&b[i].x,&b[i].y); 
        rorate(a,b,n,m); 
        rorate(b,a,m,n); 
        printf("%lf\n",ans);     
    } 
    return 0; 
} 
