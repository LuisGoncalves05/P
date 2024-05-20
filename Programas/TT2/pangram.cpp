#include <string>
#include <cctype>

using namespace std;

bool pangram(const string &s, string &m) {
    bool arr[26] = {0};
    for (char c : s) {
        if (c != ' ') arr[tolower(c) - 'a'] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (!arr[i]) m += i + 'a';
    }
    return (m == "");
}