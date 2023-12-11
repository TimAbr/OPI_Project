#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

const int TotalWordsCount = 5;
string Generated_Words[65]{};
int Num_Word{0};

int GetRandomNumber(int min,int max){
    return min+rand()%(max-min+1);
} 

string Return_Word(int);
vector <string> Split(string);

bool InputCheckFirstStep(string, string);
bool InputCheckSecondStep(vector<string>, string[TotalWordsCount]);

int main(){
    int CorrectInputs{0};
    string FirstStageWord{};
    string SecondStageWords[TotalWordsCount]{};
    string InputData{};// Users input 
    vector<string> UsersWordsList{}; 

    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    while (true){   
        switch ((int)(CorrectInputs / 3)){
            // ÏÅÐÂÀß ÑÒÀÄÈß ÂÂÎÄÀ 5 ÑËÎÂ
            case 0:
                FirstStageWord = Return_Word(5);
                cout << "Generated word: " << FirstStageWord << endl;
                getline(cin, InputData);
                if (InputCheckFirstStep(InputData, FirstStageWord)){ 
                    cout << "Correct entering" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "Inorrect entering" << endl;
                    CorrectInputs = 0;
                }
                        
                break;

            // ÏÅÐÂÀß ÑÒÀÄÈß ÂÂÎÄÀ 6 ÑËÎÂ
            case 1:
                FirstStageWord = Return_Word(6);
                cout << "Generated word: " << FirstStageWord << endl;
                getline(cin, InputData);
                if (InputCheckFirstStep(InputData, FirstStageWord)){ 
                    cout << "Correct entering" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "Inorrect entering" << endl;
                    CorrectInputs = 0;
                }
                        
                break;

            // ÏÅÐÂÀß ÑÒÀÄÈß ÂÂÎÄÀ 7 ÑËÎÂ
            case 2:
                FirstStageWord = Return_Word(7);
                cout << "Generated word: " << FirstStageWord << endl;
                getline(cin, InputData);
                if (InputCheckFirstStep(InputData, FirstStageWord)){ 
                    cout << "Correct entering" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "Inorrect entering" << endl;
                    CorrectInputs = 0;
                }
                        
                break;

            // ÏÅÐÂÀß ÑÒÀÄÈß ÂÂÎÄÀ 8 ÑËÎÂ
            case 3:
                FirstStageWord = Return_Word(8);
                cout << "Generated word: " << FirstStageWord << endl;
                getline(cin, InputData);
                if (InputCheckFirstStep(InputData, FirstStageWord)){ 
                    cout << "Correct entering" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "Inorrect entering" << endl;
                    CorrectInputs = 0;
                }
                    
                break;
                
            //  ÂÒÎÐÀß ÑÒÀÄÈß ÂÂÎÄÀ
            case 4:
                for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
                
                cout << "Stage 2. Generated word: ";
                for (string word: SecondStageWords) cout << word << " ";
                cout << endl;
                getline(cin, InputData);
                UsersWordsList = Split(InputData);
                if (size(UsersWordsList) == TotalWordsCount){
                    if (InputCheckSecondStep(UsersWordsList, SecondStageWords)){
                        cout << "Correct entering" << endl;
                        CorrectInputs++;
                    }
                    else{
                        cout << "CHMOOOOOOOOOOOOOOOO" << endl << endl;
                        CorrectInputs = 0;
                    }
                }
                // Error
                else{
                    cout << "CHMOOOOOOOOOOOOOOOO" << endl << endl;
                    CorrectInputs = 0;
                }
                
                break;
        }
    }

    // Check the first stage with the first word from the second stage

    return 0;
}

string Return_Word(int letters){

    string Word;
    fstream file;

    bool Flag = false;
    do{

        int Word_Index = GetRandomNumber(1,100);

        switch (letters){
            case 5: 
                file.open("5_letters.txt");
                break;
            case 6: 
                file.open("6_letters.txt"); 
                break;
            case 7: 
                file.open("7_letters.txt"); 
                break;
            case 8: 
                file.open("8_letters.txt"); 
                break;
        }

        
        if (file.is_open()) {
            for (int lineno = 1; (lineno <= Word_Index) && getline(file,Word); lineno++);
            for (int i = 0; !Flag && i<Num_Word; i++)
                Flag = (Generated_Words[i] == Word);
        }
        else{    
            cout<<"Error. Cannot open file"<<endl;
        }

        file.close();
    }
    while(Flag);

    return Word.substr(0, letters);
}

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

vector <string> Split(string UsersLine){

    vector <string> UsersEnteredWords;
    int StartCheck = UsersLine.find_first_not_of(' ');
    while (StartCheck != -1){
        UsersEnteredWords.push_back(
            UsersLine.substr(StartCheck,(UsersLine.find_first_of(' ', StartCheck) - StartCheck)));

        StartCheck = UsersLine.find_first_not_of(' ', UsersLine.find_first_of(' ', StartCheck));
    }
    return UsersEnteredWords;
}

bool InputCheckSecondStep(vector<string> UsersWords, string GenWords[TotalWordsCount]){
    
    for (int i = 0;i < TotalWordsCount;i++){
        bool flag = false;
        for (int j = 0;!flag && j < TotalWordsCount;j++){
            if (UsersWords.back() == GenWords[j]){
                UsersWords.pop_back();
                flag = true;
            }
        }
        if (!flag)
            return false;
    }
    return true;
}