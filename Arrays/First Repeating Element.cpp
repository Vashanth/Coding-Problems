int firstRepeated(int arr[], int n) {
    unordered_map<int,int> m;
    int ans=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(m.find(arr[i]) == m.end())
        m[arr[i]] = 1;
        else
        ans=i+1;
    }
    return ans;
}

//Hash map => O(N)
//O(N) complexity 

//(or)

bool fun(int temp[], int s, int n)
{
    int f = 0,l = n-1;
    while(f<=l)
    {
        int m = (f+l)/2;
        if(temp[m] == s)
        {
            return m==0 ? (temp[m+1]==s) : 
                    (m==n-1 ? temp[m-1]==s : (temp[m+1]==s||temp[m-1]==s));
        }
        else if(temp[m] > s)
        l=m-1;
        else
        f=m+1;
    }
}

int firstRepeated(int arr[], int n) {
    if(n==1)
    return -1;
    int temp[n];
    for(int i=0;i<n;i++)
    temp[i] = arr[i];
    
    sort(temp,temp+n);
    
    for(int i=0;i<n;i++)
    {
        int x = arr[i];
        bool freq = fun(temp,x,n);
        if(freq)
        return i+1;
    }
    return -1;
}

//O(NlogN) complexity

//(or)

bool fun(int temp[], int s, int n)
{
    int m = lower_bound(temp,temp+n,s)-temp;
    return m==0 ? (temp[m+1]==s) : 
            (m==n-1 ? temp[m-1]==s : (temp[m+1]==s||temp[m-1]==s));
}

int firstRepeated(int arr[], int n) {
    if(n==1)
    return -1;
    int temp[n];
    for(int i=0;i<n;i++)
    temp[i] = arr[i];
    
    sort(temp,temp+n);
    
    for(int i=0;i<n;i++)
    {
        int x = arr[i];
        bool freq = fun(temp,x,n);
        if(freq)
        return i+1;
    }
    return -1;
}

