// 6-4 用最大堆存储活结点的优先队列式分支限界法
// 0-1背包问题

template<class Tw, class Tp>
class HeapNode{
    friend Knap<Tw, Tp>;
    private:
        Tp p,up;
        Tw w;
        int level, *x;
    public:
        operator Tp() const{
            return up;
        }
};

// 修改后算法
template<class Tw, class Tp>
class Knap{
    friend Tp Knapsack(Tp*, Tw*, int, int *);
    private:
        int n;  //物品总数
        Tw c;   //背包容量
        Tw *w;  //物品重量数组
        Tp *p;  //物品价值数组
        Tw cw;  //当前装包重量
        Tp cp;  //当前装包价值
        int *bestx; //最优解
        MaxHeap<HeapNode<Tw, Tp>> *H;
        Tp Bound(int i);
        void AddLiveNode(Tp up, Tp cp, Tw cw, bool ch, int level, int *x);
    public:
        Tp MaxKnapsack(Tp*, Tw*, int, int*);
};

template<class Tw, class Tp>
Tp Knap<Tw, Tp>::Bound(int i){
    Tw cleft = c - cw;
    Tp b = cp;
    while(i<=n && w[i]<=cleft){
        cleft -= w[i];
        b += p[i];
        i++;
    }
    if(i<=n)
        b += p[i]/w[i]*cleft;
    return b;
}

template<class Tw, class Tp>
void Knap<Tw, Tp>::AddLiveNode(Tp up, Tp cp, Tw cw, bool ch, int level, int *x){
    HeapNode<Tw, Tp> N;
    N.x = new int[n+1];
    for(int i=0;i<=n;i++)
        N.x[i] = x[i];
    N.up = up;
    N.p = cp;
    N.w = cw;
    N.level = level;
    N.x[level-1] = ch;
    H.push(N);
}

template<class Tw, class Tp>
Tp Knap<Tw, Tp>::MaxKnapsack(){
    H = new MaxHeap<HeapNode<Tw, Tp>> (1000);
    HeapNode<Tw, Tp> N;
    N.x = new int[n+1];
    bestx = new int[n+1];
    for(int i=0;i<=n;i++)
        bestx[i] = 0;
    int k=1;
    cw = cp = 0;
    Tp bestp = 0;
    Tp up = Bound(1);
    while(k != n+1){
        Tw wt = cw + w[i];
        if(wt <= c){
            if(cp+p[i]>bestp)
                bestp = cp+p[i];
            AddLiveNode(up, cp+p[i], cw+w[i], true, i+1, bestx);
        }
        up = Bound(k+1);
        if(up >= bestp)
            AddLiveNode(up, cp, cw, false, i+1, bestx);
        H->DeleteMax(N);
        cw = N.w;
        cp = N.p;
        up = N.up;
        k = N.level;
        for(int i=0;i<=n;i++)
            bestx[i] = N.x[i];
    }
    for(int i=0;i<=n;i++)
        bestx[i] = N.x[i];
    while(true){
        try
            H->DeleteMax(N);
        catch(OutOfBound)
            break;
    }
    return cp;
}

//物品单位重量价值降序排序
template<class Tw, class Tp>
Tp Knapsack(Tp *p, Tw *w, Tw c, int n, int *x){
    Tw W = 0;
    Tp P = 0;
    Object *A = new Object[n];
    for(int i=1;i<=n;i++){
        A[i-1].id = i;
        A[i-1].d = 1.0*p[i]/w[i];
        P += p[i];
        W += w[i];
    }
    if(W<=c)
        return P;
    MergeSort(Q, n);
    Knap<Tw, Tp> K;
    K.p = new Tp[n+1];
    K.w = new Tw[n+1];
    for(int i=1;i<=n;i++){
        K.p[i] = p[A[i-1].id];
        K.w[i] = w[A[i-1].id];
    }
    K.cp = 0;
    K.cw = 0;
    K.c = c;
    K.n = n;
    Tp bestp = K.MaxKnapsack();
    for(int i=1;i<=n;i++)
        bestx[A[i-1].id] = K.bestx[i];
    delete []A;
    delete []K;
    return bestp;
}