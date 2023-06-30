#include <iostream>
#include <string>
#include <vector>

using namespace std;

void splitSentence(string &sen , vector<string> &result){
    string word;
    for(int i = 0 ;  i < sen.length() ; i++){
        auto ch = sen[i];
        if(ch == ' '){
            if(!word.empty()){
                result.push_back(word);
            }
            word = "";
        }else{
            word += ch;
        }
    }//end for i

    if(!word.empty()){
        result.push_back(word);
    }
}

bool isCircularSentence(string sentence) {
    vector<string> result;
    splitSentence(sentence , result);

    for(int i = 1; i < result.size() ;i++){
        string preWord = result[i - 1];
        string curWord = result[i];

        if(preWord[preWord.size() - 1] != curWord[0]){
            return false;
        }
    }//end for i

    string lastWord = result[result.size() - 1];
    string firstWord = result[0];

    if(lastWord[lastWord.size() - 1] != firstWord[0]){
        return false;
    }

    return true;        
}

int main(){
    vector<string> result;
    string sen = "Leetcode is cool";
    splitSentence(sen , result);

    for(auto v : result){
        cout << v << endl;
    }

    cout << "is circel: " << isCircularSentence(sen) << endl;
    return 0;
}