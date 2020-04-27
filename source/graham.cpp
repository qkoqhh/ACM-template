struct P{ 
    double x,y; 
    P(double x=0,double y=0):x(x),y(y){} 
    double operator*(const P&o){return x*o.y‐y*o.x;} 
    P operator‐(const P&o){return P(o.x‐x,o.y‐y);} 
    bool operator<(const P&o){return x<o.x||(x==o.x&&y<o.y);} 
}p[NM],s[NM]; 
double dis(P o){return sqrt(o.x*o.x+o.y*o.y);} 
int n,m,k;
double ans; 
int main(){ 
//    freopen("data.in","r",stdin); 
    freopen("fc.in","r",stdin); 
    freopen("fc.out","w",stdout); 
    n=read(); 
    inc(i,1,n)scanf("%lf%lf",&p[i].x,&p[i].y); 
    sort(p+1,p+1+n); 
    m=0; 
    inc(i,1,n){ 
        while(m>1&&(s[m‐1]‐s[m‐2])*(p[i]‐s[m‐2])<0)m‐‐; 
        s[m++]=p[i]; 
    } 
    k=m; 
    dec(i,n‐1,1){ 
        while(m>1&&(s[m‐1]‐s[m‐2])*(p[i]‐s[m‐2])<0)m‐‐; 
        s[m++]=p[i]; 
    } 
    m‐‐; 
    inc(i,1,m)ans+=dis(s[i]‐s[i‐1]); 
    printf("%.2lf\n",ans); 
    return 0; 
} 
