#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge *j=h[x];j;j=j->next)
#define _link(x) for(edge *j=_h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define inf 1e9
#define ll long long
#define succ(x) (1<<x)
#define lowbit(x) (x&(-x))
#define NM 1005
#define nm 200005
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct edge{
    int t,v;
    edge *next;
}e[nm],*h[NM],*_h[NM],*o=e;
void add(int x,int y,int v){
    o->t=y;o->v=v;o->next=h[x];h[x]=o++;
}
void _add(int x,int y,int v){
    o->t=y;o->v=v;o->next=_h[x];_h[x]=o++;
}
 
struct node{
    int g,t,f;
}N[6*nm],*p=N;
struct cmp{
    bool operator()(node*x,node*y){
	return x->f==y->f?x->g>y->g:x->f>y->f;
    }
};
 
int n,m,d[NM];
bool v[NM];
int _x,_y,_t,S,T,K,cnt;
void spfa(){
    mem(d);mem(v);queue<int >q;
    inc(i,1,n)d[i]=inf;
    v[T]++;d[T]=0;q.push(T);
    while(!q.empty()){
	int t=q.front();q.pop();v[t]=false;
	_link(t)if(d[j->t]>d[t]+j->v){
	    d[j->t]=d[t]+j->v;
	    if(!v[j->t])v[j->t]++,q.push(j->t);
	}
    }
}
 
int bfs(){
    priority_queue<node*,vector<node*>,cmp>q;
    p->g=0;p->f=d[S];p->t=S;K+=S==T;
    q.push(p);
    while(!q.empty()){
	node *k=q.top();q.pop();
	if(k->t==T)
	if(++cnt==K)return k->f;
	link(k->t){
	    ++p;
	    p->t=j->t;
	    p->g=k->g+j->v;
	    p->f=p->g+d[p->t];
	    q.push(p);
	}
    }
    return -1;
}
 
int main(){
    while(~scanf("%d%d",&n,&m)){
	mem(v);mem(d);mem(e);mem(h);mem(_h);mem(N);p=N;o=e;
	inc(i,1,m){
	    _x=read();_y=read();_t=read();
	    add(_x,_y,_t);_add(_y,_x,_t);
	}
	S=read();T=read();K=read();
	spfa();
	if(d[S]==inf)printf("-1\n");else printf("%d\n",bfs());
    }
    return 0;
}
