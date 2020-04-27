struct edge{int t;edge*next;}e[nm],*h[NM],*o=e;
void add(int x,int y){o->t=y;o->next=h[x];h[x]=o++;}
int n,m,_x,_y,_f[NM],g[NM];
int F[NM][21],f[NM],d[NM],size[NM],son[NM],top[NM],TOP;
int low[NM],cnt,c[NM],tot,v[NM],b[NM];
int find(int x){return _f[x]==x?x:_f[x]=find(_f[x]);}
 
 
void tar(int x){
    low[x]=_x;
    link(x)if(low[j->t]==_x)
	for(int y=x;y!=f[j->t];y=f[y])c[++tot]=y,v[y]=tot;
    else if(!low[j->t])f[j->t]=x,tar(j->t);
}
 
void dfs1(int x){
    link(x)if(!v[j->t])
	F[j->t][0]=x,d[j->t]=d[x]+1,dfs1(j->t);
    g[x]=_x;
}
void dfs3(int x){
    for(int i=1;i<=20;i++)F[x][i]=F[F[x][i-1]][i-1];
    link(x)if(!v[j->t])dfs3(j->t);
}
int Lca(int u,int v){
    if(d[u]<d[v])swap(u,v);
    int tmp=d[u]-d[v];
    for(int i=0;i<=20;i++)if(tmp&(1<<i))u=F[u][i];
    if(u==v)return u;
    for(int i=20;i>=0;i--){
	if(F[u][i]!=F[v][i]){
	    u=F[u][i];v=F[v][i];
	}
    }
    return F[u][0];
}
 
int main(){
    freopen("data.in","r",stdin);
    n=read();m=read();
    inc(i,1,n)_f[i]=i;
    inc(i,1,n){
	_x=read();add(_x,i);
	int x=find(i),y=find(_x);
	if(x==y)continue;
	_f[x]=y;
    }
    inc(i,1,n)if(!low[i]){
	int t=tot;
	tar(_x=i);
	inc(j,t+1,tot)b[j]=tot-t;
    }
    inc(i,1,tot)dfs1(_x=F[c[i]][0]=c[i]),dfs3(c[i]);
    while(m--){
	_x=read();_y=read();
	int x=find(_x),y=find(_y);
	if(x!=y){printf("-1 -1\n");continue;}
	x=g[_x];y=g[_y];
	if(x==y){
	    int t=Lca(_x,_y);
	    printf("%d %d\n",d[_x]-d[t],d[_y]-d[t]);
	    continue;
	}
	int  _f=0;
	x=v[x];y=v[y];
	if(x>y)swap(x,y),swap(_x,_y),_f^=1;
	int s1=y-x+d[_x],s2=d[_y];
	int t1=d[_x],t2=b[y]-(y-x)+d[_y];
	if(max(s1,s2)>max(t1,t2))s1=t1,s2=t2;
	else if(max(s1,s2)==max(t1,t2))
	    if(min(s1,s2)>min(t1,t2))s1=t1,s2=t2;
	else if(min(s1,s2)==min(t1,t2))
	    if((s1<s2)^_f)s1=t1,s2=t2;
	if(_f)swap(s1,s2);
	printf("%d %d\n",s1,s2);
    }
    return 0;
}
