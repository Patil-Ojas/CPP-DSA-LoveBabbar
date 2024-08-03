void helper(string s, int i, string &subset, vector<string> &ans)
{
    if (i >= s.size())
    {
        if (!subset.empty())
        {
            ans.push_back(subset);
        }
        return;
    }
    // take element
    subset.push_back(s[i]);
    helper(s, i + 1, subset, ans);
    // notake element
    subset.pop_back();
    helper(s, i + 1, subset, ans);
}
vector<string> AllPossibleStrings(string s)
{
    string subset = "";
    vector<string> ans;
    helper(s, 0, subset, ans);
    sort(ans.begin(), ans.end());
    return ans;
}