int n,x,y,_x,_y,_t,a[NM][NM];
void add(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))a[i][j]+=_t;
}
int sum(int x,int y){
	int s=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))s+=a[i][j];
	return s;
}
int main(){
	n=read();n=read()+1;
	while((_t=read())!=3){
		x=read()+1;y=read()+1;
		if(_t==1){
			_t=read();
			add(x,y);
		}else{
			_x=read()+1;_y=read()+1;
			printf("%d\n",sum(_x,_y)-sum(_x,y-1)-sum(x-1,_y)+sum(x-1,y-1));
		}
	}
	return 0;
}
