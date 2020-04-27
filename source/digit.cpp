int _x,_y,k,n,b[NM],d[11][NM][NM];
bool V[11][NM][NM];
int dfs(int i,bool f,int t,int v){
	if(!i)return !t&&!v;
	if(!f&&V[i][t][v])return d[i][t][v];
	int m=f?b[i]:9,ans=0;
	inc(j,0,m)ans+=dfs(i-1,f&&j==m,(t*10+j)%k,(v+j)%k);
	if(!f)d[i][t][v]=ans,V[i][t][v]++;
	return ans;
}
 
int solve(int x){
	n=0;
	for(int t=x;t;t/=10)b[++n]=t%10;
	return dfs(n,1,0,0);
}
 
int main(){
	int _=read();
	inc(T,1,_){
		_x=read();_y=read();k=read();
		if(k>82){printf("Case %d: 0\n",T);continue;}
		mem(V);mem(d);
		printf("Case %d: %d\n",T,solve(_y)-solve(_x-1));
	}
	return 0;
}
