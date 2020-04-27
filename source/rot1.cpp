struct P{ 
    int x,y; 
    P(int x=0,int y=0):x(x),y(y){} 
    int operator*(const P&o){return x*o.y‐y*o.x;}; 
    P operator‐(const P&o){return P(x‐o.x,y‐o.y);} 
    bool operator<(const P&o){return x<o.x||(x==o.x&&y<o.y);} 
}p[NM],s[NM]; 
int dis(P o){return sqr(o.x)+sqr(o.y);} 
int n,m,ans; 
void hull(){ 
    sort(p+1,p+1+n); 
    inc(i,1,n){ 
        while(m>1&&(s[m]‐s[m‐1])*(p[i]‐s[m‐1])<=0)m‐‐; 
        s[++m]=p[i]; 
    } 
    int k=m; 
    dec(i,n‐1,1){ 
        while(m>k&&(s[m]‐s[m‐1])*(p[i]‐s[m‐1])<=0)m‐‐; 
        s[++m]=p[i]; 
    } 
    m‐‐; 
} 
void rorate(){ 
    int t=2; 
    inc(i,1,m){ 
        while((s[i+1]‐s[i])*(s[t+1]‐s[i])>(s[i+1]‐s[i])*(s[t]‐s[i]))t=t%m+1; 
        ans=max(ans,dis(s[i]‐s[t]));ans=max(ans,dis(s[i+1]‐s[t])); 
    } 
} 
int main(){ 
    //freopen("data.in","r",stdin); 
    n=read(); 
    inc(i,1,n)p[i].x=read(),p[i].y=read(); 
    hull(); 
    //inc(i,1,m)printf("%d %d\n",s[i].x,s[i].y); 
    rorate(); 
    return 0*printf("%d\n",ans); 
} 
