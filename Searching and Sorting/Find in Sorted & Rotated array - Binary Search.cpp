int findMid(vector<int> ar, int n)
{
    int f=0,l=n-1;
    while(f<=l)
    {
        int mid = (f+l)>>1;
        if(mid==0 || mid==n-1 || ar[mid]>ar[mid+1])
        return mid;
        if(ar[mid] > ar[n-1])
        f=mid+1;
        else
        l=mid-1;
    }
}

int Search(vector<int> vec, int K) {
    int x = findMid(vec,vec.size());
    int f=0,l=vec.size()-1;
    if(K>vec.back())
    l=x;
    else if(x!=vec.size()-1)
    f=x+1;
    
    while(f<=l)
    {
        int mid = (f+l)/2;
        if(vec[mid] == K)
        return mid;
        else if(vec[mid] > K)
        l=mid-1;
        else
        f=mid+1;
    }
    
    return -1;
}

// log N => find pivot with BS and again search in divided 2 arrays respectively