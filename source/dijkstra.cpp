struct edge{int t;ll v;edge*next;}e[nm],*h[NM],*o=e;
void add(int x,int y,ll v){o->t=y;o->v=v;o->next=h[x];h[x]=o++;}
struct tmp{
	int x;ll d;
	bool operator<(const tmp&o)const{return d>o.d;}
};
priority_queue<tmp>q;
ll d[NM];
bool v[NM];

 
void dij(){
	inc(i,1,n)d[i]=inf;q.push(tmp{0,0});
	while(!q.empty()){
		int t=q.top().x;q.pop();
		link(t)if(d[j->t]>d[t]+j->v)q.push(tmp{j->t,d[j->t]=d[t]+j->v});
	}
}
