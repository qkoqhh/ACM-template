struct edge{int t;edge*next;}e[nm],*h[NM],*o=e;
void add(int x,int y){o->t=y;o->next=h[x];h[x]=o++;}
int top[NM],TOP,size[NM],son[NM],d[NM],f[NM],tot,id[NM];
int n,m,_x,_y,a[NM];
char _s[10];
void dfs1(int x){
	link(x)if(!f[j->t]){
		f[j->t]=x;d[j->t]=d[x]+1;
		dfs1(j->t);
		if(size[j->t]>size[son[x]])son[x]=j->t;
		size[x]+=size[j->t];
	}
	size[x]++;
}
void dfs2(int x){
	top[x]=TOP;id[x]=++tot;
	if(son[x])dfs2(son[x]);
	link(x)if(!top[j->t])dfs2(TOP=j->t);
}
 
struct info{
	ll s;int m,size;
	info operator+(const info&o){
		info f;f.s=s+o.s;
		f.size=size+o.size;
		f.m=max(m,o.m);
		return f;
	}
}T[4*NM];
 
void build(int i,int x,int y){
	int t=x+y>>1;
	if(x==y){op.s=op.m=a[x];op.size=1;return;}
	build(i<<1,x,t);build(i<<1|1,t+1,y);
	op=rs+ls;
}
void mod(int i,int x,int y){
	int t=x+y>>1;
	if(x==y){op.s=op.m=_y;return;}
	if(_x<=t)mod(i<<1,x,t);else mod(i<<1|1,t+1,y);
	op=ls+rs;
}
ll sum(int i,int x,int y){
	int t=x+y>>1;
	if(_y<x||y<_x)return 0;
	if(_x<=x&&y<=_y)return op.s;
	return sum(i<<1,x,t)+sum(i<<1|1,t+1,y);
}
int query(int i,int x,int y){
	int t=x+y>>1;
	if(_y<x||y<_x)return -inf;
	if(_x<=x&&y<=_y)return op.m;
	return max(query(i<<1,x,t),query(i<<1|1,t+1,y));
}
 
int  _query1(int x,int y){
	int s=-inf;
	for(;top[x]!=top[y];x=f[top[x]]){
		if(d[top[x]]<d[top[y]])swap(x,y);
		_x=id[top[x]];_y=id[x];s=max(s,query(1,1,n));
	}
	if(d[x]>d[y])swap(x,y);
	_x=id[x];_y=id[y];s=max(s,query(1,1,n));
	return s;
}
 
ll _query2(int x,int y){
	ll s=0;
	for(;top[x]!=top[y];x=f[top[x]]){
		if(d[top[x]]<d[top[y]])swap(x,y);
		_x=id[top[x]];_y=id[x];s+=sum(1,1,n);
	}
	if(d[x]>d[y])swap(x,y);
	_x=id[x];_y=id[y];s+=sum(1,1,n);
	return s;
}
 
int main(){
	freopen("data.in","r",stdin);
	n=read();
	inc(i,1,n-1){_x=read();_y=read();add(_x,_y);add(_y,_x);}
	dfs1(f[1]=1);dfs2(TOP=1);
	inc(i,1,n)a[id[i]]=read();
	build(1,1,n);
	m=read();
	while(m--){
		scanf("%s",_s);
		_x=read();_y=read();
		if(_s[0]=='C'){
			_x=id[_x];mod(1,1,n);
		}else if(_s[1]=='M')printf("%d\n",_query1(_x,_y));
		else printf("%lld\n",_query2(_x,_y));
	}
	return 0;
}
