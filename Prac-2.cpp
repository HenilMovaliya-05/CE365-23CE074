#include<bits/stdc++.h>

using namespace std;

vector<string> splitStringBySpace(const string& str) {
    stringstream ss(str);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }
    
    return words;
}

int main() {
    
    int n,m,st,t;
    cout << "Number of inpute symbols : "; cin >> n;
    cout << "Input symbols : "; 
    char input[n];
    for (int i=0;i<n;i++) {
        cin >> input[i];
    }
    cout << "Enter number of states : "; cin >> m;
    cout << "initial state : "; cin >> st;
    st--;
    cout << "Number of Accepting  states : "; cin >> t;
    int acc[t];
    cout << "Accepting states : ";
    for (int i=0;i<t;i++) {
        cin >> acc[i];
        acc[i]--;
    }
    cout << "Transition table : ";
    int table[m][n];
    unordered_map<char,int> mp;
    for (int i=0;i<m;i++) {
        mp[input[i]] = i;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i=0;i<n*m;i++) {
        cout << i << " "<< n*m << endl; 
        string entry;
        getline(cin, entry);
        vector<string> tokens = splitStringBySpace(entry);
        int from = stoi(tokens[0]) - 1;
        char symbol = tokens[2][0];
        int to = stoi(tokens[4]) - 1;
    
        table[from][mp[symbol]] = to;
    }
    string s; 
    cout << "Input String : "; cin >> s;
    
    for (char c : s) {
        for(char ch : input) {
            if(c == ch) {
                st = table[st][mp[c]];
            }
        }
    }
    for (int i : acc) {
        if(i==st) {
            cout << "Valid String.";
            return 0;
        }
    }
    cout << "Invalid String.";
}
