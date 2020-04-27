struct BigInteger{ // 仅支持非负整数
    static const int N = 150;
    static const int base = 1e6; // 修改它时记得修改输入输出格式
  
    int a[N];
    int length;
  
    BigInteger():length(0){memset(a, 0, sizeof(a));}
  
    BigInteger(ll p){
        memset(a, 0, sizeof(a));
        length = 0;
        if (!p) return;
        for (ll x = std::abs(p); x; x /= base){
            a[length ++] = x % base;
        }
    }
  
    int &operator [](int sit){return a[sit];}
  
    bool operator < (const BigInteger &q)const{
        if (length != q.length) return length < q.length;
        for (int i = length - 1; ~i; -- i){
            if (a[i] != q.a[i]) return a[i] < q.a[i];
        }
        return false;
    }
  
    BigInteger operator + (const BigInteger &p)const{
        BigInteger ret;
        ret.length = std::max(length, p.length) + 1;
        for (int i = 0; i < ret.length; ++ i){
            ret.a[i] += a[i] + p.a[i];
            if (ret.a[i] >= base) ret.a[i] -= base, ++ ret.a[i + 1];
        }
        for ( ; ret.length && !ret.a[ret.length - 1]; -- ret.length)
            ;
        return ret;
    }
  
    BigInteger operator - (const BigInteger &p)const{
        BigInteger ret;
        ret.length = length;
        for (int i = 0; i < ret.length; ++ i){
            ret.a[i] += a[i] - p.a[i];
            if (ret.a[i] < 0) ret.a[i] += base, -- ret.a[i + 1];
        }
        for ( ; ret.length && !ret.a[ret.length - 1]; -- ret.length)
            ;
        return ret;
    }
  
    BigInteger operator * (const BigInteger &p)const{
        static ll aux[N << 1];
        memset(aux, 0, sizeof(ll) * (length + p.length));
        for (int i = 0; i < length; ++ i){
            for (int j = 0; j < p.length; ++ j){
                aux[i + j] += (ll) a[i] * p.a[j];
            }
        }
        BigInteger ret;
        ret.length = p.length + length;
        for (int i = 0; i < ret.length; ++ i){
            aux[i + 1] += aux[i] / base;
            aux[i] %= base;
        }
        for ( ; ret.length && !aux[ret.length - 1]; -- ret.length)
            ;
        for (int i = 0; i < ret.length; ++ i) ret.a[i] = aux[i];
        return ret;
    }
  
    void write(){
        if (!length) return (void) printf("0");
        printf("%d", a[length - 1]);
        for (int i = length - 2; ~i; -- i){
            printf("%06d", a[i]);
        }
    }
};
