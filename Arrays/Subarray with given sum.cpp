vector<int> subarraySum(int arr[], int n, int s){
    int start=0,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        while(sum>s)
        sum-=arr[start++];
        if(sum==s)
        return vector<int> {start+1,i+1};
    }
    return vector<int> {-1};
}

// Sliding Window