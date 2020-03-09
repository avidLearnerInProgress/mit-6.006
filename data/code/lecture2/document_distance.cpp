#include<bits/stdc++.h>
using namespace std;

vector<string> readFromFile(fstream &f, string word, string file){
    f.open(file.c_str());
    vector<string> wordlist;
    while(f >> word)
        wordlist.push_back(word);
    f.close();
    return wordlist;
}

map<string, int> countFrequency(vector<string> data){

        map<string, int> m;

        for(const auto word : data){
            m[word]++;
        }
        return m;
}

int calculateDocumentDistance(map<string, int> fA, map<string, int> fB){
    
    long long int distance = 0, dA = 0, dB = 0;
    for(auto it = fB.begin(); it != fB.end(); it++){
        if(fA.find(it->first) != fB.end()){
            distance += (it->second * fA[it->first]);
            dA += (fA[it->first] * fA[it->first]);
            dB += (it->second * it->second);
        }
    }
    return acos(distance / (sqrt(dA) * sqrt(dB)));
}


int main(){

    fstream f;
    string word, t, q, fileA, fileB;

    fileA = "doc1.txt", fileB = "doc2.txt";
    vector<string> dataA = readFromFile(f, word, fileA);
    vector<string> dataB = readFromFile(f, word, fileB);
    
    map<string, int>frequencyA = countFrequency(dataA);
    map<string, int>frequencyB = countFrequency(dataB);
    for(auto &[key, value] : frequencyA)
        cout<<key<<" "<<value<<endl;

    for(auto &[key, value] : frequencyB)
        cout<<key<<" "<<value<<endl;

    cout<<calculateDocumentDistance(frequencyA, frequencyB)<<"\n";

}