class Solution {
public:
     long long int b_search(int n) {
        
        int s = 0;
        int e = n/2;
        long long int mid = s + (e-s)/2;
        
        long long int ans = -1;
        while(s<=e) {
            
            long long int square = mid*mid;
            
            if(square == n)
                return mid;
            
            if(square < n ){
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

    int mySqrt(int x) {
        if (x==0)
        {
            return 0;
        }
        else if (x==1)
        {
            return 1;
        }
        else
        {
            return b_search(x);
        }
    }
};