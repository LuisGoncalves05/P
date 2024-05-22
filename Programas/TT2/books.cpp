#include "Page.h"
#include "Book.h"
#include <sstream>
#include <string>
#include <set>

void Book::build_index(const set<string>& words) {
    for (int i = 0; i < (int) book_.size(); i++) {
        Page p = book_[i];
        for (int j = 0; j < (int) p.get_num_lines(); j++) {
            string t;
            istringstream iss(p.get_line(j));
            while (iss >> t) {
                for (string w: words) {
                    if (w == t) {
                        index_[w].insert(i + 1);
                        break;
                    }
                }
            }
        }
    }
}