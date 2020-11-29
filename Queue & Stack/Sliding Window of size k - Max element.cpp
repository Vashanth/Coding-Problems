    vector<int> maxSlidingWindow(vector<int>& ar, int k) {
        deque<int> d;
        vector<int> ans;
        for(int i=0;i<ar.size();i++)
        {
            if(d.empty())
                d.push_back(i);
            else
            {
                if(ar[i]<=ar[d.back()])
                    d.push_back(i);
                else if(ar[i]>ar[d.back()])
                {
                    while(!d.empty() && ar[i]>ar[d.back()])
                        d.pop_back();
                    d.push_back(i);
                }
                while(d.size()>k || d.front()<=(i-k))
                    d.pop_front();
            }
            if(i>=k-1)
            ans.push_back(ar[d.front()]);
        }
        return ans;
    }

// Decreasing deque and keep k elements always => O(N)