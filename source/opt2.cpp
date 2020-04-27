int n,m,a[NM],_x;
ll d[NM][NM],s;
 
void solve(int x,int y,int l,int r){
    if(x>y||l>r)return;
    int s=inf,m=min(mid-1,r),pos=0;
    inc(i,l,m)if(d[_x-1][i]+sqr(a[mid]-a[i])<s)
	s=d[_x-1][i]+sqr(a[mid]-a[i]),pos=i;
    d[_x][mid]=s;solve(x,mid-1,l,pos);solve(mid+1,y,pos,r);
}
 
int main(){
    n=read();m=read();
    inc(i,1,n)a[i]=read(),s+=a[i],a[i]+=a[i-1];
    inc(i,1,n)d[0][i]=inf;
    for(_x=1;_x<=m;_x++)solve(1,n,0,n-1);
    return 0*printf("%lld\n",d[m][n]*m-sqr(s));
}
