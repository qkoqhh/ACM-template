char s1[NM],s2[NM]; 
int a[NM],b[NM],next[NM],t,n,m,cnt,s; 
int main(){ 
    //freopen("data.in","r",stdin); 
    scanf("%s",s1);scanf("%s",s2); 
    n=strlen(s1)‐1;m=strlen(s2)‐1; 
    next[0]=‐1; 
    for(int i=0,j=‐1;i<m;) 
    if(j==‐1||s2[i]==s2[j])next[++i]=++j; 
    else j=next[j]; 
    for(int i=0,j=0;i<=n;){ 
        if(j==‐1||s1[i]==s2[j])i++,j++; 
        else j=next[j]; 
        if(j==m+1)cnt++,a[cnt]=i‐m+1,b[cnt]=i; 
    } 
    inc(i,1,cnt)if(a[i]>t){ 
        s++;t=b[i]; 
    } 
    printf("%d\n",s); 
    return 0; 
} 
