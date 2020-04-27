struct P{ 
    double x,y; 
    P(double x=0,double y=0):x(x),y(y){} 
    double operator*(const P&o){return x*o.y‐y*o.x;} 
    P operator‐(const P&o){return P(x‐o.x,y‐o.y);} 
}p[NM]; 
struct L{P a,b;double k;}l[NM]; 
int n,tmp[NM],q[NM],qh,qt,m; 
bool cmp(int x,int y){ 
    if(fabs(l[x].k‐l[y].k)<eps)return (l[y].b‐l[x].a)*(l[x].b‐l[x].a)>eps; 
    else return l[x].k<l[y].k; 
} 
void intersect(L x,L y,P&p){ 
    double t1=(x.b‐y.a)*(x.a‐y.a),t2=(y.b‐x.b)*(x.a‐x.b); 
    p.x=(y.a.x*t2+y.b.x*t1)/(t1+t2); 
    p.y=(y.a.y*t2+y.b.y*t1)/(t1+t2); 
} 
bool judge(L a,L b,L c){ 
    P p; 
    intersect(b,c,p); 
    return (a.b‐a.a)*(p‐a.a)+eps<0; 
} 
void solve(){ 
    sort(tmp+1,tmp+1+n,cmp);m=1; 
    inc(i,2,n)if(fabs(l[tmp[i]].k‐l[tmp[m]].k)>eps)tmp[++m]=tmp[i]; 
    mem(q);qh=1;qt=0; 
    inc(k,1,m){ 
        int i=tmp[k]; 
        while(qh<qt&&judge(l[i],l[q[qt‐1]],l[q[qt]]))qt‐‐; 
        while(qh<qt&&judge(l[i],l[q[qh+1]],l[q[qh]]))qh++; 
        q[++qt]=i; 
    } 
    while(qh<qt&&judge(l[q[qt]],l[q[qh+1]],l[q[qh]]))qh++; 
    while(qh<qt&&judge(l[q[qh]],l[q[qt‐1]],l[q[qt]]))qt‐‐; 
} 
int main(){ 
    //freopen("data.in","r",stdin); 
    while(n=read()){ 
        inc(i,1,n)p[i].x=read(),p[i].y=read(); 
        p[n+1]=p[1]; 
        inc(i,1,n){             
	    l[i].a=p[i];l[i].b=p[i+1]; 
            l[i].k=atan2(p[i+1].y‐p[i].y,p[i+1].x‐p[i].x); 
            tmp[i]=i; 
        } 
        solve(); 
        //printf("%d %d\n",qh,qt); 
        printf("%d\n",qt>qh+1); 
    } 
    return 0; 
} 
