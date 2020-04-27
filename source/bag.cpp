int main(){
    n=read();m=read();
    inc(i,1,n)c[i]=read(),w[i]=read(),b[i]=read();
    inc(i,1,n){
	inc(j,0,c[i]-1){
	    qh=1;qt=0;
	    for(int k=0;j+k*c[i]<=m;k++){
		while(qh<=qt&&q[qh]<k-b[i])qh++;
		while(qh<=qt&&f[j+q[qt]*c[i]]-q[qt]*w[i]<=f[j+k*c[i]]-k*w[i])qt--;
		q[++qt]=k;
		d[j+k*c[i]]=f[j+q[qh]*c[i]]-q[qh]*w[i]+k*w[i];
	    }
	}
	inc(i,1,m)f[i]=d[i];
    }
    return 0*printf("%d\n",d[m]);
}
