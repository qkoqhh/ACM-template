struct edge{int t;bool f,v;edge*next,*rev;}e[nm],*h[NM],*o=e;
void _add(int x,int y,bool v){o->t=y;o->v=v;o->next=h[x];h[x]=o++;}
void add(int x,int y){
    _add(x,y,1);_add(y,x,0);h[x]->rev=h[y];h[y]->rev=h[x];
}
int n,_x,_y,c[NM],f[NM],tot,cnt,sz[NM],b[NM],ans1,_t,s;
bool v[NM];
ll ans2;
 
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
 
void dfs1(int x){
    link(x)if(f[x]!=j->t){
	f[j->t]=x;
	dfs1(j->t);
	if(!j->v)cnt++;
    }
}
void dfs2(int x){
    if(cnt<s)s=cnt,_t=1;else if(cnt==s)_t++;
    link(x)if(f[x]!=j->t){
	if(j->v)cnt++;else cnt--;
	dfs2(j->t);
	if(j->v)cnt--;else cnt++;
    }
}
void cir(int x){
    v[x]++;
    link(x)if(!j->f){
	j->f=j->rev->f=true;
	if(v[j->t]){_x=j->t;c[++tot]=x;break;}
	else cir(j->t);
	if(_x){c[++tot]=x;break;}
    }
    if(_x==x)_x=0;
}
 
int main(){
    //freopen("data.in","r",stdin);
    int _=read();while(_--){
	mem(e);mem(h);o=e;mem(sz);mem(b);mem(v);
	n=read();ans1=0;ans2=1;
	inc(i,1,2*n)f[i]=i;
	inc(i,1,n){
	    _x=read();_y=read();add(_y,_x);
	    b[_x]++;b[_y]++;
	    int x=find(_x),y=find(_y);
	    if(x==y)continue;
	    f[x]=y;
	}
	inc(i,1,2*n)if(find(i)!=i)b[f[i]]+=b[i],sz[f[i]]++;
	inc(i,1,2*n)if(f[i]==i){
	    sz[i]++;s=inf;cnt=0;_t=0;
	    if(b[i]/2==sz[i]-1){
		dfs1(i);
		dfs2(i);
	    }else if(b[i]/2==sz[i]){
		cnt=tot=_x=0;cir(i);c[tot+1]=c[1];c[0]=c[tot];
		inc(k,1,tot)link(c[k])
		    if(j->t==c[k+1]&&j->v){cnt++;break;}
		cnt=min(cnt,tot-cnt);_t=1;if(cnt*2==tot)_t=2;
		inc(k,1,tot)link(c[k])
		    if(j->t!=c[k-1]&&j->t!=c[k+1]){
			f[j->t]=c[k];
			dfs1(j->t);
			if(!j->v)cnt++;
		    }
		s=cnt;
	    }
	    if(s<inf)ans2*=_t,ans1+=s,ans2%=inf;
	    else{ans1=ans2=-1;break;}
	}
	printf("%d %lld\n",ans1,ans2);
    }
    return 0;
}
