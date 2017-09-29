#include <string>
#include <vector>
#include <iostream>

using namespace std;

// globals
unordered_set<char> numerical_chars({'0','1','2','3','4','5','6','7','8','9'});
unordered_set<char> terminals({']','}',',','\"'});
unordered_set<char> initializers({'[','{','\"'});
unordered_set<char> whitespace({'\n','\t','\r',' '})

bool validList(vector<char>& stack, const string& listStr, int& currInd) {
  if (listStr[currInd] != '[') { return false; } // invalid input
  stack.push_back(listStr[currInd]);

  currInd++;
  while (currInd < listStr.length()) {
    // check for special chars
    if (listStr[currInd] == ',') {
      // valid separator?
    }
    else if (listStr[currInd] == '{') {
      // valid dict?
    }
    else if (listStr[currInd] == '[') {
      // valid list?
    }
    else if (listStr[currInd] == '\"') {
      // valid string?
    }
    else if (digits.find(listStr[currInd]) != digits.end() || s[currInd] == '-') {
      // valid numerical type?
    }

    i++;
  }
  return true;
}

bool validComma(const string& str, int& currInd) {
  if (currInd == 0) { return false; }
  int tmp = currInd;
  currInd--;
  while (currInd > 0) {
    if (whitespace.find(str[currInd]) == whitespace.end()) {
        if (terminals.find(str[currInd]) == terminals.end() && digits.find(str[currInd]) == digits.end()) { return false; }
        else { return true; }
    }
    else {
        currInd--;
    }
  }
}

// int or float
bool validNumerical(const string& integer, int& currInd) {

  // validate input
  bool seenDec = false;
  if (digits.find(s[currInd])) == digits.end()) {
    // is it a minus sign at the very beginning?
    if (s[currInd] == '.') {
      seenDec = true;
    }
    else if (s[currInd] != '-' && digits.find(s[currInd]) == digits.end()) {
      return false;
    }
  }

  currInd++;
  while ( currInd < integer.length() ) {
    if ( digits.find(s[currInd]) == s[currInd] ) {
      currInd++;
    }
    else if ( s[currInd] == '.' && !seenDec) {
      currInd++;
    }
    else {
      return false;
    }
  }
  return true;
}

bool validString(vector<char>& stack, const string& s, int& currInd) {
  if (s[currInd] != '\"') { return false; } // invalid input
  stack.push_back(s[currInd]);

  currInd++;
  while (currInd < s.length()) {
    if (s[currInd] == '\"') {
      stack.pop_back();
      return true;
    }
    i++;
  }
  return false;
}

int main() {
  string sValid = "\"asdkfdjkfd\"";
  string sInvalid = "\"asdfjkdfkdl";
  vector<char> stack;
  bool y1 = validString(stack, sValid, 0);
  bool y2 = validString(stack, sInvalid, 0);
  cout << sValid << " is a valid string: " << y1 << endl;
  cout << sInvalid << " is an invalid string: " << y2 << endl;
}
