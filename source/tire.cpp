const int m=31;
int n,a[NM],ans,_t,l[NM],r[NM];
struct node{
    node *c[2];
}N[(m+1)*NM],*o=N,*root;
void ins(int x){
    node *r=root;
    dec(i,m,0){
        int t=(1<<i)&x?1:0;
        if(!r->c[t])r->c[t]=++o;
        r=r->c[t];
    }
}
int find(int x){
    int s=0;node *r=root;
    dec(i,m,0){
        int t=(1<<i)&x?0:1;
        if(r->c[t]){
            s+=1<<i;
            r=r->c[t];
        }else r=r->c[t^1];
    }
    return s;
}
int main(){
    freopen("data.in","r",stdin);
    n=read();
    inc(i,1,n)a[i]=read();
    root=++o;ins(_t);
    inc(j,1,n){
    //    node *t=o;
        _t^=a[j];
        l[j]=max(l[j-1],find(_t));
        ins(_t);
    //    printf("%d ",o-N);
    }
    mem(N);root=o=N;_t=0;ins(_t);
    dec(i,n,1){
        _t^=a[i];
        r[i]=max(r[i-1],find(_t));
        ins(_t);
    }
    //inc(i,1,n)printf("%d ",l[i]);printf("\n");
    //inc(i,1,n)printf("%d ",r[i]);printf("\n");
    inc(i,1,n-1)ans=max(ans,l[i]+r[i+1]);
    printf("%d\n",ans);
    return 0;
}
