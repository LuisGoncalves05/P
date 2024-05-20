#include "Page.h"
#include "Book.h"
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

void Book::build_index(const set<string>& words) {
    map<string, set<size_t>> index;
    for (string s: words) {
        //percorrer páginas
        for (size_t i = 0; i < book_.size(); i++) {
            Page p = book_[i];
            //percorrer linhas
            for (size_t j = 0; j < p.get_num_lines(); j++) {
                string line = p.get_line(j);
                string word;
                istringstream iss_l(line);
                //percorrer palavras
                while (iss_l >> word) {
                    if (word == s) index[s].insert(i+1); 
                }
            }
        }
    }
    index_ = index;
}