void rotateArr(int arr[], int d, int n){
    d%=n;
    int x = __gcd(d,n);
    for(int i=0;i<x;i++)
    {
        int j = i;
        int temp = arr[i];
        while(true)
        {
            int k = j+d;
            if(k>=n)
            k-=n;
            if(k==i)
            break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

GFG solution : 
if gcd not 1 then slot rotation where slot  len = gcd
else 
5 2
1 2 3 4 5
temp=1
3 2 3 4 5
3 2 5 4 5
3 2 5 4 2
3 4 5 4 2
3 4 5 1 2