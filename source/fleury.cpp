void _add(int x,int y,int v){o->t=y;o->v=v;o->next=h[x];h[x]=o++;}
void add(int x,int y,int v){_add(x,y,v);_add(y,x,-v);h[x]->rev=h[y];h[y]->rev=h[x];}
int n,m,_x,_y,cnt,b[NM],s;
bool v[NM];
vector<int>a[NM];
 
void dfs(int x){
    v[x]=true;
    link(x)if(!j->f){
	j->rev->f=j->f=true;
	dfs(j->t);
	if(j->v==0)a[++cnt].clear();else a[cnt].push_back(-j->v);
    }
}
 
int main(){
    while(~scanf("%d%d",&n,&m)){
	mem(e);mem(h);o=e;mem(b);s=0;mem(v);cnt=0;
	inc(i,1,m){
	    _x=read();_y=read();
	    add(_x,_y,i);
	    b[_x]++;b[_y]++;
	}
	_x=0;
	inc(i,1,n)if(b[i]&1){
		if(_x)add(_x,i,0),_x=0;
		else _x=i;
	}
	inc(i,1,n)if(!v[i]&&b[i]%2)a[++cnt].clear(),dfs(i),cnt--;
	inc(i,1,n)if(!v[i]&&b[i])a[++cnt].clear(),dfs(i);
	printf("%d\n",cnt);
	inc(i,1,cnt){
	    printf("%d ",m=a[i].size());
	    inc(j,0,m-2)printf("%d ",a[i][j]);
	    printf("%d\n",a[i][m-1]);}
    }
    return 0;
}
