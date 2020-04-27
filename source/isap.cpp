struct edge{int t,v;edge*next,*rev;}e[nm],*h[NM],*o=e;
void _add(int x,int y,int v){o->t=y;o->v=v;o->next=h[x];h[x]=o++;}
void add(int x,int y,int v){_add(x,y,v);_add(y,x,0);h[x]->rev=h[y];h[y]->rev=h[x];}
int n,m,S,T,_x,_y,_t;
 
ll maxflow(){
	ll flow=0;int tot=n,d[NM],cnt[NM];edge*j,*p[NM],*tmp[NM];
	mem(d);mem(cnt);mem(p);mem(tmp);
	inc(i,1,n)tmp[i]=h[i];
	cnt[0]=tot;
	for(int x=S,s=inf;d[x]<tot;){
		for(j=tmp[x];j;j=j->next)
		    if(j->v&&d[j->t]+1==d[x])break;
		if(j){
			s=min(j->v,s);tmp[x]=p[j->t]=j;
			if((x=j->t)==T){
				for(;x!=S;x=p[x]->rev->t)
				    p[x]->v-=s,p[x]->rev->v+=s;
				flow+=s;s=inf;
			}
		}else{
			if(!--cnt[d[x]])break;d[x]=tot;
			link(x)if(j->v&&d[x]>d[j->t]+1)
			    d[x]=d[j->t]+1,tmp[x]=j;
			cnt[d[x]]++;
			if(p[x])x=p[x]->rev->t;
		}
	}
	return flow;
}
 
int main(){
	n=read();m=read();S=read();T=read();
	inc(i,1,m){_x=read();_y=read();_t=read();add(_x,_y,_t);}
	return 0*printf("%lld\n",maxflow());
}
