struct P{ 
    double x,y; 
    P(double x=0,double y=0):x(x),y(y){} 
    P operator‐(const P&o){return P(x‐o.x,y‐o.y);} 
    double operator*(const P&o){return x*o.y‐y*o.x;} 
    bool operator<(const P&o){return x<o.x||(x==o.x&&y<o.y);} 
}p[NM]; 
double dis(P o){return sqrt(sqr(o.x)+sqr(o.y));} 
bool cmp(int x,int y){return p[x].y<p[y].y;} 
int n,m,tmp[NM]; 
double ans; 
double part(int x,int y){ 
    double d=inf; 
    if(x==y)return d; 
    if(x+1==y)return dis(p[x]‐p[y]); 
    d=min(part(x,mid),part(mid+1,y)); 
    int tot=0; 
    inc(i,x,y)if(fabs(p[mid].x‐p[i].x)+eps<d)tmp[++tot]=i; 
    sort(tmp+1,tmp+1+tot,cmp); 
    inc(i,1,tot)inc(j,i+1,tot) 
        if(p[tmp[j]].y‐p[tmp[i]].y+eps<d)d=min(d,dis(p[tmp[i]]‐p[tmp[j]])); 
        else break; 
    return d; 
} 
int main(){ 
    //freopen("data.in","r",stdin); 
    while(n=read()){ 
        inc(i,1,n)scanf("%lf%lf",&p[i].x,&p[i].y); 
        sort(p+1,p+1+n); 
        printf("%.2lf\n",part(1,n)/2); 
    } 
} 
