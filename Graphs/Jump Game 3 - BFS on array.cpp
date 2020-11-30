    bool bfs(vector<int> arr, int start, vector<bool> &visited)
    {
        if(start>=arr.size() || arr.size()<0 || visited[start])
            return false;
        visited[start] = true;
        if(arr[start] == 0)
            return true;
        return bfs(arr, start+arr[start], visited) || 
            bfs(arr, start-arr[start], visited);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(),false);
        return bfs(arr, start, visited);
    }