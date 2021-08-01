class Solution {
public:
    void dfs(vector<vector<int>>& ar, vector<vector<int>>& v, unordered_map<int,int> &um, int n, int x, int  y, int counter) {
        if (x<0 || y<0 || x>=n || y>=n || v[x][y]!=0 || ar[x][y]==0) {
            return;
        }
        
        v[x][y] = counter;
        um[counter]++;

        dfs(ar, v, um, n, x+1, y, counter);
        dfs(ar, v, um, n, x-1, y, counter);
        dfs(ar, v, um, n, x, y+1, counter);
        dfs(ar, v, um, n, x, y-1, counter);
    }
    
    int findCombinedArea(vector<vector<int>>& ar, vector<vector<int>>& v, unordered_map<int,int> &um, int x, int y) {
        int n = ar.size();
        set<int> uniqueAreas;
        if(y-1>=0 && ar[x][y-1]==1)  uniqueAreas.insert(v[x][y-1]);
        if(y+1<n && ar[x][y+1]==1)  uniqueAreas.insert(v[x][y+1]);
        if(x-1>=0 && ar[x-1][y]==1)  uniqueAreas.insert(v[x-1][y]);
        if(x+1<n && ar[x+1][y]==1)  uniqueAreas.insert(v[x+1][y]);
        
        int totalArea = 0;
        for(int i:uniqueAreas) {
            totalArea += um[i];
        }
        
        return totalArea+1;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), counter = 1, maxi = 0;
        unordered_map<int, int> um;
        vector<vector<int>> v(n, vector<int> (n, 0));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (grid[i][j] == 1){
                    dfs(grid, v, um, n, i, j, counter++);
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0) {
                    maxi = max(maxi, findCombinedArea(grid, v, um, i, j));
                }
            }
        }
        
        return maxi == 0 ? n*n : maxi;
    }
};
