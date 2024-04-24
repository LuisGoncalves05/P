#include <iostream>
#include <cmath>


using namespace std;
void rle_encode(const char str[], char rle[]);


int main()
{
    { char rle[1] = { -1 }; 
      rle_encode("", rle);
      cout << rle << endl; }
    { char rle[2 + 1] = { -1, -1, -1 }; 
      rle_encode("a", rle);
      cout << rle << endl; }
    //1a
    { char rle[10 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; 
      rle_encode("abcde", rle);
      cout << rle << endl; }
    //1a1b1c1d1e
    { char rle[9 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; 
      rle_encode("aaaaabbbbbbbbbbbcccd", rle);
      cout << rle << endl; }
    //5a11b3c1d
    { char rle[3 + 1] = { -1, -1, -1, -1 }; 
      rle_encode("xxxxxxxxxxxxxxxxxxxx", rle);
      cout << rle << endl; }
    //20x
    return 0;
}

void rle_encode(const char str[], char rle[])
{
    int i = 0, k = 0;
    int counter;
    while(true)
    {   
        if (i == 0)
        {
            if (str[i] == '\0')
            {
                rle[k] = '\0';
                break;
            }
            counter = 1;
        }
        else
        {
            if (str[i] == '\0')
            {
                int l = 0;
                int copy_counter = counter;
                while (copy_counter)
                {
                    l++;
                    copy_counter /= 10;
                }
                while (l >= 1)
                {
                    rle[k] = (counter / pow(10, l-1)) + 48;
                    counter %= (int) pow(10, l-1);
                    l--;
                    k++;
                }
                rle[k] = str[i-1];
                k++;
                rle[k] = '\0';
                break;
            }
            if (str[i] == str[i-1])
            {
                counter++;
            }
            else
            {   
                int l = 0;
                int copy_counter = counter;
                while (copy_counter)
                {
                    l++;
                    copy_counter /= 10;
                }
                while (l >= 1)
                {
                    rle[k] = (counter / pow(10, l-1)) + 48;
                    counter %= (int) pow(10, l-1);
                    l--;
                    k++;
                }
                rle[k] = str[i-1];
                k++;
                counter = 1;
            }
        }
        i++;
    }
}
