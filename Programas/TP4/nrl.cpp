#include <iostream>

using namespace std;

int nrl(const char s[], char low[]);

int main()
{
    { const char s[] = "";
      char l[27] = { -1 };
      int r = nrl(s, l);
      cout << '\"' << s << "\" "
           << r << " \"" << l << "\"\n"; }
    //"" 0 ""
    { const char s[] = "  F C U P  F E U P  Porto  ";
      char l[27] = { -1 };
      int r = nrl(s, l);
      cout << '\"' << s << "\" "
           << r << " \"" << l << "\"\n"; }
    //"  F C U P  F E U P  Porto  " 4 "cert"
    { const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
      char l[27] = { -1 };
      int r = nrl(s, l);
      cout << '\"' << s << "\" "
           << r << " \"" << l << "\"\n"; }
    //" abC dEf GhI jKl MnO pQr StU vWx yZ " 26 "abcdefghijklmnopqrstuvwxyz"
    { const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ABc DeF gHi JkL mNo PqR sTu VwX Yz";
      char l[27] = { -1 };
      int r = nrl(s, l);
      cout << '\"' << s << "\" "
           << r << " \"" << l << "\"\n"; }
    //" abC dEf GhI jKl MnO pQr StU vWx yZ ABc DeF gHi JkL mNo PqR sTu VwX Yz" 0 ""
    { const char s[] = "The quick brown fox jumps over the lazy dog";
      char l[27] = { -1 };
      int r = nrl(s, l);
      cout << '\"' << s << "\" "
           << r << " \"" << l << "\"\n"; }
    return 0;
}


int nrl(const char s[], char low[])
{
    int i = 0, k = 0;
    int arr[26] = {};
    while (s[i] != '\0')
    {
        int idx = -1;
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            idx = s[i] - 'A';
        }
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            idx = s[i] - 'a';
        }
        if (idx >= 0)
        {
            arr[idx]++;
        }
        i++;
    }
    for (int j = 0; j < 26; j++)
    {   
        if (arr[j] == 1)
        {
            low[k] = j + 'a';
            k++;
        }
    }
    low[k] = '\0';
    return k;
}