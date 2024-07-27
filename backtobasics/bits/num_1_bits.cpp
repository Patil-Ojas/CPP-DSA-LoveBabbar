class Solution {
public:
    string getBinary(int n)
    {
        string binn = "";
        while (n>0)
        {
            binn = to_string(n%2) + binn;
            n = n/2;
        }
        return binn;
    }

    int checkOnes(string binn)
    {
        int count = 0;
        for (int i=0; i<binn.length(); i++)
        {
            if (binn[i]=='1')
                count++;
        }
        return count;
    }

    int hammingWeight(int n) {
        string bin_n = getBinary(n);
        int ans = checkOnes(bin_n);
        return ans;
    }
};