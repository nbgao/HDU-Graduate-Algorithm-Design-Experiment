// 6-5 释放结点空间的优先队列式分支限界法
// 0-1背包问题
template<class Typew, class Typep>
Typep Knap<Typew, Typep>::MaxKnapsack(){
    H = new Max<HeapNode<Typep, Typew>> (1000);
    Queue<bbnode *> Q;
    bestx = new int[n+1];
    int i=1;
    E = 0;
    cw = wp = 0;
    Typep bestp = 0;
    Typep up = Bound(1);
    while(i!=n+1){
        Typew wt = cw + w[i];
        if(wt<=c){
            if(cp+p[i]>bestp)
                bestp = cp + p[i];
            AddLiveNode(up, cp+p[i], cw+w[i], true, i+1);
        }
        up = Bound(i+1);
        if(up>=bestp)
            AddLiveNode(up, cp, cw, false, i+1);
        HeapNode<Typep, Typew> N;
        H->DeleteMax(N);
        E = N.ptr;
        Q.push(E);
        cw = N.w;
        cp = N.p;
        up = N.up;
        i = N.level;
    }
    for(int j=n;j>0;j--){
        bestx[j] = E->LChild;
        E = E->parent;
    }
    HeapNode<Typep, Typew> N;
    while(True){
        try{
            H->DeleteMax(N);
        }catch(OutOfBounds){
            break;
        }
        Q.push(N.ptr);
    }
    while(!Q.empty()){
        bbnode *b;
        Q.Delete(b);
        delete b;
    }
    return cp;
}


// 装载问题
template<class T>
T MaxLoading(T *w, T c, int n, int *bestx){
    MaxHeap<HeapNode<T>> H(1000);
    Queue<bbnode *>> Q;
    T *r = new T[n+1];
    r[n] = 0;
    for(int j=n-1;j>0;j--)
        r[j] = r[j+1] + w[j+1];
    int i=1;
    bbnode *E = 0;
    int Ew = 0;
    while(i != n+1){
        if(Ew + w[i] <= c)
            AddLiveNode(H, E, Ew+w[i]+r[i], true, i+1);
        AddLiveNode(H, E, Ew+r[i], false, i+1);
        HeapNode<T> N;
        H.DeleteMax(N);
        i = N.level;
        E = N.ptr;
        Q.push(E);
        Ew = N.up - r[i-1];
    }
    for(int j=n;j>0;j--){
        bestx[j] = E->LChild;
        E = E->parent;
    }
    HeapNode<T> N;
    while(true){
        try{
            H.DeleteMax(N);
        }catch(OutOfBound){
            break;
        }
        Q.push(N.ptr);
    }
    while(!Q.empty()){
        bbnode *b;
        Q.Delete(b);
        delete b;
    }
    return Ew;
}