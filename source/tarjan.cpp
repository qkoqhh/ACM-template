struct edge{int t;edge*next;}e[nm],*h[NM],*o=e;
void add(int x,int y){o->t=y;o->next=h[x];h[x]=o++;}
int n,m,_x,_y,ans;
int d[NM],low[NM],suc[NM],cnt,tot,c[NM];
bool v[NM];
stack<int>s;
 
 
void tar(int x){
	d[x]=low[x]=++tot;s.push(x);
	link(x)if(!d[j->t]){tar(j->t);low[x]=min(low[x],low[j->t]);}
	else if(!suc[j->t])low[x]=min(low[x],low[j->t]);
	if(low[x]==d[x]){
		int t;cnt++;
		do{
			t=s.top();s.pop();
			suc[t]=cnt;c[cnt]++;
		}while(x!=t);
	}
}
 
 
 
int main(){
	while(~scanf("%d%d",&n,&m)){
		mem(d);mem(low);mem(suc);cnt=tot=0;mem(c);ans=0;
		mem(e);mem(h);o=e;mem(v);
		inc(i,1,m){_x=read();_y=read();add(_x+n,_y+n);}
		inc(i,n+1,n<<1)if(!d[i])tar(i);
		inc(i,n+1,n<<1)link(i)
		    if(suc[i]!=suc[j->t])v[suc[i]]=true;
		inc(i,1,cnt)if(!v[i])if(ans)ans=-1;else ans=i;
		if(ans==-1)ans=0;
		printf("%d\n",c[ans]);
	}
	return 0;
}
