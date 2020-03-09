
#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    
    vector<int> result;
    unordered_map<char, int> mp;
    
    for(char c : p)
        mp[c]++;

    size_t begin = 0, end = 0, counter = mp.size();
    cout<<"counter size - "<<counter<<"\n";

    for(auto it = mp.begin(); it != mp.end(); it++){
        cout<<it->first<<it->second<<"\n";
    }
    
    while(end < s.size()){ 
        char c = s[end];
        cout<<"\nCurrent end character "<<c<<"\t";
        if(mp.find(c) != mp.end()){
            mp[c]--;
            if(mp[c] == 0) {
                cout<<"incremented counter - "<<c<<mp[c];
                counter--;
            }
        }
        end++;
        
        while(counter == 0){
            char b = s[begin];
            cout<<"\nCurrent begin character - "<<b<<"\t";
            if(mp.find(b) != mp.end()){
                mp[b]++;
                if(mp[b] >= 0){
                    cout<<"decremented counter - "<<b<<mp[b];
                    counter++;
                }
            }
            if(end - begin == p.size()){
                cout<<"pushed index =:"<<begin<<"\n";
                result.push_back(begin);
            }
            begin++;
        }
    }
    return result;
}


/*
string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}*/

/*
string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}*/

int main() {
    
    /*
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        vector<int> ret = Solution().findAnagrams(s, p);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }*/
    string s, p;
    cin>>s>>p;

    vector<int> result = findAnagrams(s, p);


    return 0;
}