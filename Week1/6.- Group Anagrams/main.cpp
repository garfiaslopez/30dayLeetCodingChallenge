// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector< vector<string> > groupAnagrams(vector<string>& words) {
    map< string, vector<string> > groupMap;
    vector< vector<string> > result;

    for (string word : words) {
        string key = word;
        sort(key.begin(), key.end());
        if (groupMap[key].size() != 0) {
            groupMap[key].push_back(word);
        } else {
            vector<string> tmp;
            tmp.push_back(word);
            groupMap[key] = tmp;
        }
    }

    map<string, vector<string> >::iterator it;
    for (it=groupMap.begin(); it!=groupMap.end(); it++) {
        result.push_back(it->second);
    }
    return result;
}

int main() {
    vector<string> words;
    string w;
    while(cin>>w) {
        words.push_back(w);
    }
    vector< vector<string> > groupedAnagrams = groupAnagrams(words);
    
    // PRINT
    for (int i=0; i<groupedAnagrams.size(); i++) {
        for (int j=0; j<groupedAnagrams[i].size(); j++) {
            cout<<groupedAnagrams[i][j]<<", ";
        }
        cout<<endl;
    }
    return (0);
}
