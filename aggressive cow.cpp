/*
https://paste.ubuntu.com/p/ZtGjSfVwTV/
https://ide.codingblocks.com/s/16346
https://www.youtube.com/watch?v=TC6snf6KPdE
*/

/*
You are given an array of integers which represents positions available and an integer c(cows).
Now you have to choose c positions such that minimum difference between cows is maximized.
For example,
1 3 5 8 10
c=3

Output: 4
1 5 10
*/

private:
    bool isPossible(int mid, vector<int> &stalls, int &k){
        int countcows= 1;
        int pos= stalls[0];
        for (int i=0; i<stalls.size(); i++){
            if(stalls[i]- pos>= mid){
                countcows++;
                if(countcows== k){
                    return true;
                }
                pos= stalls[i];
                
            }
            
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
    
      //sort the stalls
      sort(stalls.begin(), stalls.end());
      int maxi= INT_MIN;
      for (int i=0; i<stalls.size(); i++){
          maxi= max(maxi, stalls[i]);
          
      }
      int s=0;
      int e= maxi;
      int ans= -1;
      while(s<=e){
          int mid= s+(e-s)/2;
          if(isPossible(mid, stalls, k)){
              s= mid+1;
              ans= mid;
          }
          else{
              e= mid-1;
          }
      }
      
      return ans;
      
    }
