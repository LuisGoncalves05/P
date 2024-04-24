#include <iostream>

using namespace std;

void trim(char s[]);
int batatalen(char* batata);


int main()
{
    { char s[] = " abc! def? ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //" abc! def? " => "abc! def?"
    { char s[] = "#abc";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"#abc" => "#abc"
    { char s[] = "    abc def";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"    abc def" => "abc def"
    { char s[] = "abc def.   ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"abc def.   " => "abc def."
    { char s[] = "   ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"   " => ""
    { char s[] = "";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"" => ""
    { char s[] = " abc  _  def  _  ghi ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //" abc  _  def  _  ghi " => "abc  _  def  _  ghi"
    { char s[] = "a           ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }
    //"a           " => "a"
    return 0;
}


void trim(char s[])
{   
    bool flag = true;
    int initial = 0;
    int final = batatalen(s); 
    for (int i = 0; i < batatalen(s); i++)
    {
        if (flag && s[i] == ' ')
        {
            initial = i+1;
        }
        else
        {
            flag = false;
        }
    }

    flag = true;
    for (int j = 0; j < batatalen(s); j++)
    {   
        int k = batatalen(s) - 1 - j;
        if (flag && s[k] == ' ')
        {
            final = k;
        }
        else
        {
            flag = false;
        }
    }
    
    if (initial > final)
    {
        s[0] = 0;
    } 
    else
    {
        for (int k = 0; k <= final - initial; k++)
        {
            int idx = initial + k;
            s[k] = s[idx];
        }
        s[final - initial] = '\0';
    }
}


int batatalen(char* original)
{
    int i = 0;
    while (original[i])
    {
        i++;
    }
    return i;
}
