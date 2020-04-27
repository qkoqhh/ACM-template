struct P{ 
    double x,y; 
    P(double x=0,double y=0):x(x),y(y){} 
    double operator*(const P&o){return x*o.y‐y*o.x;} 
    P operator‐(const P&o){return P(x‐o.x,y‐o.y);} 
}p[NM]; 
double dis(P o){return sqrt(sqr(o.x)+sqr(o.y));} 
struct L{double k;P a,b;}l[NM]; 
int n,m,q[NM],qt,qh,tmp[NM]; 
double A,B,C,v[NM],u[NM],w[NM]; 
bool cmp(int x,int y){ 
    if(fabs(l[x].k‐l[y].k)<eps)return (l[y].b‐l[x].a)*(l[x].b‐l[x].a)>eps; 
    return l[x].k<l[y].k; 
} 
P intersect(L x,L y){ 
    double t1=(x.b‐y.a)*(x.a‐y.a),t2=(y.b‐x.b)*(x.a‐x.b); 
    return P((y.a.x*t2+y.b.x*t1)/(t1+t2),(y.a.y*t2+y.b.y*t1)/(t1+t2)); 
} 
bool judge(L a,L b,L c){return (a.b‐a.a)*(intersect(b,c)‐a.a)+eps<0;} 
void cut(){ 
    sort(tmp+1,tmp+1+n+3,cmp);m=1; 
    inc(i,2,n+3)if(fabs(l[tmp[i]].k‐l[tmp[m]].k)>eps)tmp[++m]=tmp[i]; 
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
    n=read(); 
    inc(i,1,n)u[i]=read(),w[i]=read(),v[i]=read(); 
    inc(i,1,n){ 
        bool f=true; 
        inc(j,1,n)if(i!=j){ 
            A=(u[j]‐u[i])/u[i]/u[j]; 
            B=(w[j]‐w[i])/w[i]/w[j]; 
            C=(v[j]‐v[i])/v[i]/v[j];
	    if(fabs(u[i]‐u[j])>eps)l[j].a=P(‐C/A,0); 
            else if(fabs(w[i]‐w[j])>eps)l[j].a=P(0,‐C/B); 
            else{ 
                if(C+eps>0){f=false;break;} 
                l[j].k=0;l[j].a=P(0,0);l[j].b=P(1,0);continue; 
            } 
            if(eps+u[j]>u[i]&&eps+w[j]>w[i]&&eps+v[j]>v[i]){f=false;break;} 
            l[j].k=atan2(A,‐B); 
            l[j].b=P(l[j].a.x+cos(l[j].k),l[j].a.y+sin(l[j].k)); 
        } 
        if(!f){puts("No");continue;} 
        l[i].a=P(0,0);l[i].b=P(1,0);l[i].k=0; 
        l[n+1].a=P(inf,0);l[n+1].b=P(inf,1);l[n+1].k=atan2(1.0,0.0); 
        l[n+2].a=P(1,inf);l[n+2].b=P(0,inf);l[n+2].k=atan2(0.0,‐1.0); 
        l[n+3].a=P(0,1);l[n+3].b=P(0,0);l[n+3].k=atan2(‐1.0,0.0); 
        inc(i,1,n+3)tmp[i]=i; 
        cut(); 
        //printf("%d %d %d\n",m,qh,qt); 
        if(qt<=qh+1){puts("No");continue;} 
        q[qt+1]=q[qh];m=0;double ans=0; 
        inc(j,qh,qt)p[++m]=intersect(l[q[j]],l[q[j+1]]); 
        inc(j,1,m)inc(k,j+1,m)ans=max(ans,dis(p[j]‐p[k])); 
        //printf("%lf\n",ans); 
        if(ans>eps)puts("Yes");else puts("No"); 
    } 
    return 0; 
} 
