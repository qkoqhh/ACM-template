int n,m,p,_x,_t;
int a[NM],b[NM],ans;

struct node{
    int x,y,s,tag;
    node*l,*r;
    node(int x,int y,node*l=0,node*r=0):x(x),y(y),l(l),r(r),s(0){if(l)upd();else s=-x;}
    void upd(){s=min(l->s,r->s);}
    void push(){
	if(tag){
	    l->s+=tag;l->tag+=tag;
	    r->s+=tag;r->tag+=tag;
	    tag=0;
	}
    }
    void mod(){
	if(_x<=x){s+=_t;tag+=_t;return;}
	push();if(_x<=mid)l->mod();r->mod();upd();
    }
}*root;
node*build(int x,int y){return x==y?new node(x,y):new node(x,y,build(x,mid),build(mid+1,y));}

void ins(int x){
    _x=lower_bound(b+1,b+1+m,p-x)-b;
    if(_x<=m)root->mod();
}

int main(){
    n=read();m=read();p=read();
    inc(i,1,m)b[i]=read();
    inc(i,1,n)a[i]=read();
    sort(b+1,b+1+m);
    root=build(1,m);
    inc(i,1,m)_t=1,ins(a[i]);
    if(root->s>=0)ans++;
    inc(i,m+1,n){
	_t=1;ins(a[i]);
	_t=-1;ins(a[i-m]);
	if(root->s>=0)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
