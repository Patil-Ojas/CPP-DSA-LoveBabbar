class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1;
        int sum=0;

        while (n>0)
        {
            int dig = n%10;
            prod = prod*dig;
            sum = sum + dig;
            n = (n-dig)/10;
        }
        return prod-sum;
    }
};