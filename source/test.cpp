/**
 *　　　　　　  　　┏┓　　 　┏┓
 * 　　　　　  　　┏┛┗━━━━━━━┛┗━━━┓
 * 　　　　　  　　┃　　　　　　　┃ 　
 * 　　　　　  　　┃　　　━　　 　┃
 * 　　　　　  　　┃　＞　　　＜　┃
 * 　　　　　  　　┃　　　　　　　┃
 * 　　　　　  　　┃...　⌒　... 　┃
 * 　　　　　　  　┃              ┃
 * 　　　　　　  　┗━┓          ┏━┛
 * 　　　　　　　　　┃          ┃　Code is far away from bug with the animal protecting　　　　　　　　　　
 * 　　　　　　　　　┃          ┃   神兽保佑,代码无bug
 * 　　　　　　　　　┃          ┃　　　　　　　　　　　
 * 　　　　　　　　　┃          ┃  　　　　　　
 * 　　　　　　　　　┃          ┃
 * 　　　　　　　　　┃          ┃　　　　　　　　　　　
 * 　　　　　　　　　┃          ┗━━━┓
 * 　　　　　　　　　┃              ┣┓
 * 　　　　　　　　　┃              ┏┛
 * 　　　　　　　　　┗┓┓┏━━━━━━━━┳┓┏┛
 * 　　　　　　　　　　┃┫┫       ┃┫┫
 * 　　　　　　　　　　┗┻┛       ┗┻┛
 */ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<bitset>
#include<cmath>
#include<assert.h>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge *j=h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define ll long long
#define eps 1e-8
#define succ(x) (1<<x)
#define lowbit(x) (x&(-x))
#define sqr(x) ((x)*(x))
#define mid (x+y>>1)
#define NM 100005
#define nm 200005
using namespace std;
const double pi=acos(-1);
const double eps=1e-8;
const ll inf=1e9+7;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f*x;
}
 
 



int n,a[NM][2],ans,d[NM];
struct P{
    int x,y;
    bool operator<(const P&o)const{return a[x][y]<a[o.x][o.y];}
}_t;
struct cmp1{
    bool operator()(int x,int y){
	return a[x][0]+a[x][1]<a[y][0]+a[y][1];
    }
    bool operator()(P x,P y){
	return a[x.x][x.y]>a[y.x][y.y];
    }
};
priority_queue<P>q;
priority_queue<P,vector<P>,cmp1>now;
priority_queue<int,vector<int>,cmp1>t;


int main(){
    int _=read();while(_--){
	n=read();ans=0;
	while(!q.empty())q.pop();
	while(!t.empty())t.pop();
	while(!now.empty())now.pop();
	inc(i,1,n)a[i][0]=read(),a[i][1]=read(),d[i]=0;
	inc(i,1,n)q.push(P{i,0}),t.push(i);
	inc(i,1,n*2){
	    while(d[q.top().x]!=q.top().y)q.pop();
	    int t1=-1,t2=-1;
	    _t=q.top();
	    t1=a[_t.x][_t.y];
	    while(!now.empty()&&d[now.top().x]!=now.top().y+1)now.pop();
	    while(!t.empty()&&d[t.top()])t.pop();
	    if(!t.empty()&&!now.empty()){
		_t=now.top();
		t2=-a[_t.x][_t.y];
		int k=t.top();
		t2+=a[k][0]+a[k][1];
	    }
	    if(t1>t2){
		ans+=t1;
		_t=q.top();q.pop();
		if(_t.y==0)q.push(P{_t.x,_t.y+1});
		now.push(_t);
		d[_t.x]++;
	    }else{
		ans+=t2;
		int k=t.top();t.pop();
		d[k]=2;

		_t=now.top();now.pop();
		d[_t.x]--;
		if(_t.y==1){
		    now.push(P{_t.x,_t.y-1});
		}
		q.push(_t);
		if(_t.y==0)t.push(_t.x);
	    }
	    printf("%d%c",ans," \n"[i==2*n]);
	}
    }
    return 0;
}
