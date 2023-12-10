#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool InputCheckFirstStep(string UsersWord, string CorrectWord){

    int StartCheck = UsersWord.find_first_not_of(' ');
    int EndCheck = UsersWord.find_last_not_of(' ');

    if (EndCheck - StartCheck != size(CorrectWord) - 1){
        return false;
    }
    else{
        for (int i = 0; i < size(CorrectWord); i++)
            if (UsersWord[StartCheck + i] != CorrectWord[size(CorrectWord) - i - 1])
                return false;
    }
    return true;
}

bool InputCheckSecondStep(string UsersLine, string GenWords[5]){

    int StartCheck = UsersLine.find_first_not_of(' ');
    vector <string> UsersEnteredWords(5);
    for (int i = 0;i < 5; i ++){
        if (StartCheck == -1) return false;
        UsersEnteredWords[i] = UsersLine.substr(StartCheck,(UsersLine.find_first_of(' ', StartCheck) - StartCheck));
        StartCheck = UsersLine.find_first_not_of(' ', UsersLine.find_first_of(' ', StartCheck));
    }

    if (StartCheck != -1) return false;

    for (int i = 0;i < 5;i++){

        bool flag = false;
        for (int j = 0;!flag && j < 5;j++){

            if (UsersEnteredWords.back() == GenWords[j]){
                UsersEnteredWords.pop_back();
                flag = true;
            }

        }

        if (!flag)
            return false;
    }
    
    return true;
}

int main(){

    return 0;
}