#include<bits/stdc++.h>
#define vi vector<int> 
#define pb push_back
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vs vector<string>
#define vp vector<pair<int,int>> 
#define fio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
int main()
{
    fio;
    int t,x,y,m,low,high,ans;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>m>>x>>y;
        x*=y;
        vi ar(m);
        stack<pair<int,int>> st;
        
        for(int i=0;i<m;i++)
        cin>>ar[i];
        
        sort(ar.begin(), ar.end());
        
        for(int i=0;i<m;i++)
        {
            low = ar[i]-x<1 ? 1 : ar[i]-x;
            high = ar[i]+x>100 ? 100 : ar[i]+x; 
            
            if(st.empty())
            st.push({low, high});
            else
            {
                if(low > st.top().second)
                st.push({low, high});
                else if(high > st.top().second)
                {
                    pair<int,int> temp = st.top();
                    st.pop();
                    st.push({temp.first, high});
                }
            }
        }
        
        pair<int,int> prev = st.top();
        st.pop();
        
        ans+=100-prev.second;
        
        while(!st.empty())
        {
            ans+=prev.first-st.top().second-1;
            prev = st.top();
            st.pop();
        }
        
        ans+=prev.first-1;
        
        cout<<ans<<"\n";
    }
	return 0;
}