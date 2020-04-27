struct edge{int x,t;edge*next;}e[nm],*h[NM];
int n,m,s,b[NM],v[NM];

int main(){
    int _=read();while(_--){
	inc(i,1,n)v[i]=0,h[i]=0,b[i]=0;
	s=0;
	n=read();m=read();
	inc(i,1,m)
	    e[i].x=read(),e[i].t=read(),b[e[i].x]++,b[e[i].t]++;
	inc(i,1,m){
	    if(b[e[i].x]>b[e[i].t]||(b[e[i].x]==b[e[i].t]&&e[i].x>e[i].t))swap(e[i].x,e[i].t);
	    e[i].next=h[e[i].x];h[e[i].x]=e+i;
	}
	inc(i,1,n){
	    link(i)v[j->t]=i;
	    link(i)for(edge*k=h[j->t];k;k=k->next)if(v[k->t]==i)s++;
	}
	printf("%d\n",s);
    }
    return 0;
}
