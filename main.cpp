#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s)
{
    vector<int> freq(26,0);
    
    for(int i = 0; i < s.length(); i++)
    {
        int temp = s[i] - 97;
        freq[temp] ++;
    }
    
    int maxnum = *max_element(freq.begin(), freq.end());
    int zeronum = count(freq.begin(), freq.end(), 0);
    int Mfreq = count(freq.begin(), freq.end(), maxnum);
    int numoneless = count(freq.begin(), freq.end(), maxnum-1);
    if((26-zeronum) == Mfreq)
    {
        return "YES";
    }else 
    {
        int nonzero = 26-zeronum;
        if(nonzero-numoneless == 1)
        {
            if(Mfreq == 1)
            return "YES";
        }else
        {
            if(count(freq.begin(), freq.end(), 1) == 1 && nonzero-1 == Mfreq)
            return "YES";
        }
        //if((first == 1 && second != 1) || (first != 1 && second == 1))
        //{
            
        //}
    }
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
