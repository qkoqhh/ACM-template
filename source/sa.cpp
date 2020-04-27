char st[NM];
int n,sa[NM],rank[NM],tmp[NM],top[NM],h[NM],ans,_t;
void getsa(){
    int m=256;int j;
    inc(i,0,n)top[rank[i]=(int)st[i]]++;
    inc(i,1,m)top[i]+=top[i-1];
    inc(i,0,n)sa[--top[rank[i]]]=i;
    for(int k=1;k<=n;k<<=1){
        inc(i,0,n){
            j=sa[i]-k;
            if(j<0)j+=n+1;
            tmp[top[rank[j]]++]=j;
        }
        sa[tmp[top[0]=0]]=j=0;
        inc(i,1,n){
            if(rank[tmp[i]]!=rank[tmp[i-1]]||rank[tmp[i]+k]!=rank[tmp[i-1]+k])
            top[++j]=i;
            sa[tmp[i]]=j;
        }
        memcpy(rank,sa,sizeof sa);memcpy(sa,tmp,sizeof tmp);
    }
    j=0;
    inc(i,0,n)if(rank[i]){
        if(j)j--;
        while(st[i+j]==st[sa[rank[i]-1]+j])j++;
        h[rank[i]]=j;
    }
}
int main(){
    freopen("data.in","r",stdin);
    scanf("%s",st);
    _t=n=strlen(st);st[n]='$';
    scanf("%s",st+n+1);
    n=strlen(st);st[n]='$';
    getsa();
    inc(i,1,n)
    if((ll)(sa[i]-_t)*(sa[i-1]-_t)<0)ans=max(ans,h[i]);
    printf("%d\n",ans);
    return 0;
}
