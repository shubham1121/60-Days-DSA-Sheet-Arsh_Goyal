// T.C -: O(NLogN) S.C -: O(1)
bool findPair(int a[], int size, int n){
    sort(a,a+size);
    for(int i=0;i<size;i++)
    { 
        if(binary_search(a+i+1,a+size,n+a[i]))
        {
            return true;
        }
    }
    return false;
}