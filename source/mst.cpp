struct edge{int t,v;edge*next;}e[nm],*h[NM],*o=e;
void add(int x,int y,int v){o->t=y;o->v=v;o->next=h[x];h[x]=o++;}
int n,m,p,tot,d[NM][NM],_x,_y,_t,g[NM],b[NM];
pair<int,int>c[NM];
queue<int>q;
bool v[NM];
 
 
void spfa(int k){
    while(!q.empty()){
	int t=q.front();q.pop();v[t]=false;
	link(t)if(d[k][j->t]>d[k][t]+j->v){
	    d[k][j->t]=d[k][t]+j->v;
	    if(!v[j->t])v[j->t]++,q.push(j->t);
	}
    }
}
 
int main(){
    freopen("data.in","r",stdin);
    n=read();m=read();p=read();tot=succ(p)-1;
    inc(i,1,m){
	_x=read();_y=read();_t=read();
	add(_x,_y,_t);add(_y,_x,_t);
    }
    inc(i,1,p)c[i].first=read(),c[i].second=read();
    sort(c+1,c+1+p);
    inc(i,1,p)if(c[i].first-c[i-1].first>1){
	int t=c[i].first,j=i;
	while(c[j].first==t)c[j++].first=c[i-1].first+1;
	i=j-1;
    }
    inc(i,1,tot)inc(j,1,n)d[i][j]=inf;
    inc(i,1,p)d[succ(i-1)][c[i].second]=0;
    inc(i,1,tot){
	mem(v);
	inc(j,1,n){
	    for(int k=i&(i-1);k;k=(k-1)&i)
		d[i][j]=min(d[i][j],d[k][j]+d[k^i][j]);
	    if(d[i][j]<inf)q.push(j),v[j]++;
	}
	spfa(i);
    }
    inc(i,1,p){
	int j=i;
	while(c[j].first==c[i+1].first)i++;
	b[c[j].first]=succ(i)-succ(j-1);
    }
    p=c[p].first;tot=succ(p)-1;
    inc(i,1,tot){
	int t=0;
	g[i]=inf;
	inc(j,1,p)if(succ(j-1)&i)t^=b[j];
	inc(j,1,n)g[i]=min(g[i],d[t][j]);
    }
    inc(i,1,tot)
	for(int j=i&(i-1);j;j=(j-1)&i)
	    g[i]=min(g[i],g[j]+g[j^i]);
    return 0*printf("%d\n",g[tot]);
}
