int n,l,q[NM],qh,qt;
ll f[NM],b[NM];
double slope(int x,int y){
    return 1.0*(f[x]-f[y])/(x-y+b[x]-b[y])+b[x]+b[y]+x+y;
}
 
int main(){
    n=read();l=read();
    inc(i,1,n)b[i]=b[i-1]+read();
    qh=qt=1;
    inc(i,1,n){
	while(qh<qt&&slope(q[qh],q[qh+1])<2*i+2*b[i]-2-2*l)qh++;
	f[i]=f[q[qh]]+sqr(i-q[qh]-1+b[i]-b[q[qh]]-l);
	while(qh<=qt&&slope(q[qt-1],q[qt])>slope(q[qt],i))qt--;
	q[++qt]=i;
    }
    return 0*printf("%lld\n",f[n]);
}
