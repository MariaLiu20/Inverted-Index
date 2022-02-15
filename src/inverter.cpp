#include <map>
#include <queue>
#include <set>
#include <string>
#include <fstream>
#include <inverter.h>

using namespace std;

string build_inverted_index(string filename) {
  map<string, set<int>> invertedIndex;
  fstream inFile;
  inFile.open(filename, fstream::in);
  string txtFileName;
  int fileIndex = 0;
  while (getline(inFile, txtFileName)) {
    fstream txtFile;
    txtFile.open(txtFileName, fstream::in);
    char c;
    string word = "";
    while (txtFile >> noskipws >> c) {
      if (isalpha(c)) {
        word += c;
      }
      else {
        if (word != "") {
          invertedIndex[word].insert(fileIndex);
          word = "";
        }
      }
    }
    fileIndex++;
  }
  inFile.close();

  string result = "";
  for (auto w = invertedIndex.begin(); w != invertedIndex.end(); w++) {
    result += w->first + ":";
    for (auto it = (w->second).begin(); it != (w->second).end(); it++) {
      result += " " + to_string(*it);
    }
    result += "\n";
  }
  return result;
}
