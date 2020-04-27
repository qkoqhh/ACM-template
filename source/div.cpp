int n,m,cnt,a[NM],_x,_y;
ll ans;
unsigned short d[NM][1024];
int size[NM],smin,s,tot,root;
bool v[NM];
void dfs1(int x,int f){
    size[x]=1;
    link(x)if(!v[j->t]&&j->t!=f)dfs1(j->t,x),size[x]+=size[j->t];
}
void getroot(int x,int f){
    int s=tot-size[x];
    link(x)if(!v[j->t]&&j->t!=f)getroot(j->t,x),s=max(s,size[j->t]);
    if(s<smin)smin=s,root=x;
}
 
void dfs(int x,int f,int t){
    inc(k,0,cnt){if((k|t)==cnt)ans+=d[root][k];d[x][k]=0;}
    link(x)if(!v[j->t]&&j->t!=f){
	dfs(j->t,x,t|succ(a[j->t]));
	inc(k,0,cnt)d[x][succ(a[x])|k]+=d[j->t][k];
    }
    d[x][succ(a[x])]++;
}
 
void div(int x){
    dfs1(x,0);
    tot=size[x];smin=n;
    getroot(x,0);
    v[root]++;mem(d[root]);d[root][succ(a[root])]=1;
    link(root)if(!v[j->t]){
	dfs(j->t,root,succ(a[j->t]));
	inc(k,0,cnt)d[root][succ(a[root])|k]+=d[j->t][k];
    }
    link(root)if(!v[j->t])div(j->t);
}
 
int main(){
    while(~scanf("%d%d",&n,&m)){
	mem(e);mem(h);o=e;mem(v);ans=0;
	cnt=succ(m)-1;
	inc(i,1,n)a[i]=read()-1;
	inc(i,1,n-1){_x=read();_y=read();add(_x,_y);add(_y,_x);}
	div(1);ans*=2;if(m==1)ans+=n;
	printf("%lld\n",ans);
    }
    return 0;
}
