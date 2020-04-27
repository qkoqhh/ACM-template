struct edge{int t;edge*next;}e[nm],*h[NM],*o=e;
void add(int x,int y){o->t=y;o->next=h[x];h[x]=o++;}
bool v[NM];
int d[NM];
queue<int>q;

void bfs(int u){
    inc(i,1,n)d[i]=inf;
    d[u]=0;v[u]++;q.push(u);
    while(!q.empty()){
	int t=q.front();q.pop();v[t]=false;
	link(t)if(d[j->t]>d[t]+j->v){
	    d[j->t]=d[t]+j->v;
	    if(!v[j->t])q.push(j->t),v[j->t]++;
	}
    }
}
