#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Book {
  string title, author;
  bool borrowed;
  bool returned;
  Book() {
    borrowed = false;
    returned = false;
  }
  Book(string title, string author): title(title), author(author) {
    borrowed = false;
    returned = false;
  }
  bool operator < (const Book& rhs) const {
    return author < rhs.author || !(author > rhs.author) && title < rhs.title;
  }
};

vector<Book> shelves;

void borrow(string& title) {
  for (int i = 0; i < shelves.size(); i++)
    if (shelves[i].title == title) {
      shelves[i].borrowed = true;
      return;
    }
}

void ret(string& title) {
  for (int i = 0; i < shelves.size(); i++)
    if (shelves[i].title == title) {
      shelves[i].returned = true;
      return;
    }
}

void shelve() {
  for (int i = 0; i < shelves.size(); i++) {
    if (shelves[i].returned) {
      cout << "Put " << shelves[i].title << " ";
      int j;
      for (j = i - 1; j >= 0; --j)
        if (!shelves[j].borrowed)
          break;
      if (j == -1) cout << "first" << endl;
      else cout << "after " << shelves[j].title << endl;
      shelves[i].borrowed = shelves[i].returned = false;
    }
  }
  cout << "END" << endl;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva230.in", "r", stdin);
  #endif
  string line, cmd;
  while (getline(cin, line) && line != "END") {
    Book book;
    int pos = line.find_last_of('\"'), len = line.length();
    book.title = line.substr(0, pos + 1);
    book.author = line.substr(pos + 5, len - pos - 6);
    shelves.push_back(book);
  }
  sort(shelves.begin(), shelves.end());
  while (cin >> cmd && cmd != "END") {
    if (cmd == "SHELVE") shelve();
    else {
      string title;
      getline(cin, title);
      title = title.substr(1);
      if (cmd == "BORROW") borrow(title);
      else if (cmd == "RETURN") ret(title);
    }
  }
  return 0;
}
