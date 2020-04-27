int n,m,p,_x,_y,a[NM][NM];
ll ans;

int pre[NM],match[NM],_match[NM];
int b[NM],lx[NM],ly[NM];
int v[NM];
void km(int n){
    inc(i,1,n)inc(j,1,n)lx[i]=max(lx[i],a[i][j]);
    inc(i,1,n){
	int y=0;
	match[0]=i;
	inc(j,1,n)b[j]=inf;
	for(int t;match[y];y=t){
	    int s=inf,x=match[y];v[y]=i;
	    inc(j,1,n)if(v[j]!=i){
		if(b[j]>lx[x]+ly[j]-a[x][j])
		    b[j]=lx[x]+ly[j]-a[x][j],pre[j]=y;
		if(s>b[j])s=b[j],t=j;
	    }
	    inc(j,0,n)if(v[j]==i)lx[match[j]]-=s,ly[j]+=s;
	    else b[j]-=s;
	}
	for(;y;y=pre[y])match[y]=match[pre[y]];
    }
}

int main(){
    n=read();m=read();p=read();
    while(p--){_x=read();_y=read();a[_x][_y]=read();}
    km(max(n,m));
    inc(j,1,m)if(match[j]){
	ans+=ly[j]+lx[match[j]];
	if(a[match[j]][j])_match[match[j]]=j;
    }
    printf("%lld\n",ans);
    inc(i,1,n)printf("%d%c",_match[i]," \n"[i==n]);
    return 0;
}
