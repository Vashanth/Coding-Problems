int findMissing(int ar[], int n) { 
    
    for(int i=0;i<n;i++)
    if(ar[i]<0 || ar[i]>n)
    ar[i] = 0;
    
    for(int i=0;i<n;i++)
    {
        if(ar[i]!=0)
        {
            if(ar[abs(ar[i])] == 0)
            ar[abs(ar[i])] = -abs(ar[i]);
            else
            ar[abs(ar[i])] = -abs(ar[abs(ar[i])]);
        }
    }
    
    for(int i=1;i<=n;i++)
    if(ar[i]>=0)
    return i;
    return n+1;
}

1 3 5 7 9 _
1 3 5 0 0 0
1 -3 5 0 0 0
1 -3 5 -3 0 0
1 -3 5 -3 -5 0
=> first +ve is at 5 => missing(index) => 2

(or)

int findMissing(int ar[], int n) { 
    for(int i=0;i<n;i++)
    while(ar[i]>0 && ar[i]<=n && ar[i]!=ar[ar[i]-1])
    swap(ar[i],ar[ar[i]-1]);
    
    for(int i=0;i<n;i++)
    if(ar[i]!=i+1)
    return i+1;
    return n+1;
}

1 3 4 5
1 4 3 5
1 5 3 5 => 2 is missing
Swap to correct positions => at last if not in right pos => missing