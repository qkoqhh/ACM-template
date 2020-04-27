struct edge{int t;edge*next;}e[nm],*h[NM],*o=e;
void add(int x,int y){o->t=y;o->next=h[x];h[x]=o++;}
int n,m,match[NM],_x,s,v[NM];
 
bool dfs(int x){
    link(x)if(v[j->t]!=_x){
	v[j->t]=_x;
	if(!match[j->t]||dfs(match[j->t])){match[j->t]=x;return true;}
    }
    return false;
}
 
int main(){
    n=read();m=read();
    for(_x=read();_x>=0;_x=read())add(_x,read());
    inc(i,1,n)if(dfs(_x=i))s++;
    if(!s)return 0*printf("No Solution!\n");
    printf("%d\n",s);
    inc(i,n+1,m)if(match[i])printf("%d %d\n",match[i],i);
    return 0;
}
