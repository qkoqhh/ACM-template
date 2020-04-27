int st[NM][32],_st[NM][32],a[NM],_x,_y,n,m,mn[NM];
 
void init(){
	inc(i,2,n)mn[i]=mn[i/2]+1;
	inc(i,1,n)st[i][0]=_st[i][0]=a[i];
	for(int j=1;succ(j)<=n;j++)
		for(int i=1;i+succ(j)-1<=n;i++)
			st[i][j]=max(st[i][j-1],st[i+succ(j-1)][j-1]),
			_st[i][j]=min(_st[i][j-1],_st[i+succ(j-1)][j-1]);
}
 
int rmq(int x,int y){int k=mn[y-x];return max(st[x][k],st[y-succ(k)+1][k]);}
int _rmq(int x,int y){int k=mn[y-x];return min(_st[x][k],_st[y-succ(k)+1][k]);}
 
int main(){
	n=read();m=read();
	inc(i,1,n)a[i]=read();
	init();
	while(m--){
		_x=read();_y=read();
		printf("%d\n",rmq(_x,_y)-_rmq(_x,_y));
	}
	return 0;
}
