  int maxProduct(vector<int>& ar) {
      int maxi=ar[0],mini=ar[0],prod=ar[0],ans=ar[0];
      for(int i=1;i<ar.size();i++)
      {
          if(ar[i]<0)
              swap(maxi,mini);
          maxi=max(maxi*ar[i],ar[i]);
          mini=min(mini*ar[i],ar[i]);
          ans=max(ans,maxi);
      }
      return ans;
  }
