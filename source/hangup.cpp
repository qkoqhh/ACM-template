int n,m,a[NM][NM],l[NM][NM],r[NM][NM],up[NM][NM],ans;
 
int main(){
    n=read();m=read();
    inc(i,1,n)inc(j,1,m)a[i][j]=read();
    inc(i,1,n)inc(j,1,m)up[i][j]=1,l[i][j]=r[i][j]=j;
    inc(i,1,n){
	inc(j,2,m)if(a[i][j]&&a[i][j-1])l[i][j]=l[i][j-1];
	dec(j,m-1,1)if(a[i][j]&&a[i][j+1])r[i][j]=r[i][j+1];
    }
    inc(i,2,n)inc(j,1,m)if(a[i][j]&&a[i-1][j]){
	up[i][j]=up[i-1][j]+1;
	l[i][j]=max(l[i][j],l[i-1][j]);
	r[i][j]=min(r[i][j],r[i-1][j]);
    }
    inc(i,1,n)inc(j,1,m)
	ans=max(ans,min(up[i][j],r[i][j]-l[i][j]+1));
    return 0*printf("%d\n",ans);
}
