struct P{ 
    double x,y; 
    P(double x=0,double y=0):x(x),y(y){} 
    P operator+(const P&o){return P(x+o.x,y+o.y);} 
    P operator‐(const P&o){return P(x‐o.x,y‐o.y);} 
    double operator*(const P&o){return x*o.y‐y*o.x;} 
    P operator/(const double&t){return P(x/t,y/t);} 
}p[NM],c; 
double dis(P o){return sqrt(sqr(o.x)+sqr(o.y));} 
int n; 
double r; 
P cir(P a,P b,P c){ 
    P p1=b‐a,p2=c‐a; 
    double t=p1*p2,t1=(sqr(p1.x)+sqr(p1.y))/2,t2=(sqr(p2.x)+sqr(p2.y))/2;
    if(fabs(t)<eps){ 
        t=dis(b‐c);t1=dis(p1);t2=dis(p2); 
        if(t1>t2&&t1>t)return (a+b)/2; 
        if(t2>t)return (a+c)/2; 
        return (b+c)/2; 
    } 
    return a+P(t1*p2.y‐t2*p1.y,t2*p1.x‐t1*p2.x)/t; 
} 
void mcc(){ 
    random_shuffle(p,p+n); 
    c=p[1];r=0; 
    inc(i,2,n)if(dis(p[i]‐c)>r+eps){ 
        c=p[i];r=0; 
        inc(j,1,i‐1)if(dis(p[j]‐c)>r+eps){ 
            c=(p[i]+p[j])/2;r=dis(p[i]‐c); 
            inc(k,1,j‐1)if(dis(p[k]‐c)>r+eps){ 
                c=cir(p[i],p[j],p[k]); 
                r=dis(p[i]‐c); 
            } 
        } 
    } 
} 
int main(){ 
    //freopen("data.in","r",stdin); 
    while(n=read()){ 
        inc(i,1,n)scanf("%lf%lf",&p[i].x,&p[i].y); 
        mcc(); 
        printf("%.2lf %.2lf %.2lf\n",c.x,c.y,r);     
    } 
    return 0; 
} 
