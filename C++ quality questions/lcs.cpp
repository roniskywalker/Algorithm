#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lcs(string pattern_1, string pattern_2, int len_1, int len_2)
{
    if (len_1 == 0 || len_2 == 0)
        return 0;
    if (pattern_1[len_1 - 1] == pattern_2[len_2 - 1])
    {
        return 1 + lcs(pattern_1, pattern_2, len_1 - 1, len_2 - 1);
    }
    else
    {
        return max(lcs(pattern_1, pattern_2, len_1 - 1, len_2), lcs(pattern_1, pattern_2, len_1, len_2 - 1));
    }
}
int main()
{
    string pattern_1, pattern_2;
    pattern_1 = "RGBGARGA";
    pattern_2 = "BGRARG";
    cout << "Length of LCS is: " << lcs(pattern_1, pattern_2, pattern_1.size(), pattern_2.size()) << endl;
}