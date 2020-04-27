struct edge{int t;ll v,w;edge*next,*rev;}e[nm],*h[NM],*o=e,*p[NM];
void _add(int x,int y,int w,int v){o->t=y;o->v=v;o->w=w;o->next=h[x];h[x]=o++;}
void add(int x,int y,int w,int v){_add(x,y,w,v);_add(y,x,0,-v);h[x]->rev=h[y];h[y]->rev=h[x];}
int n,m,_x,_y,_t,_w;
ll ans,s,d[NM],w[NM];
bool v[NM];
queue<int>q;
 
int spfa(){
	mem(d);mem(v);mem(w);mem(p);
	inc(i,1,n)d[i]=inf;
	d[1]=0;v[1]++;w[1]=inf;q.push(1);
	while(!q.empty()){
		int t=q.front();q.pop();v[t]=false;
		link(t)if(j->w&&d[j->t]>d[t]+j->v){
			d[j->t]=d[t]+j->v;w[j->t]=min(w[t],j->w);
			p[j->t]=j;
			if(!v[j->t])v[j->t]++,q.push(j->t);
		}
	}
	return w[n];
}
 
 
int main(){
	n=read();m=read();
	inc(i,1,m){
	    _x=read();_y=read();_w=read();_t=read();
	    add(_x,_y,_w,_t);
	}
	while(spfa()){
		ans+=w[n];s+=w[n]*d[n];
		for(int x=n;p[x];x=p[x]->rev->t)
		    p[x]->w-=w[n],p[x]->rev->w+=w[n];
	}
	return 0*printf("%lld %lld\n",ans,s);
}
