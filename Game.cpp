#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

const int TotalWordsCount = 5;
string Processed_Words[32]{};
int Num_Word{0};

int GetRandomNumber(int min,int max){
    return min+rand()%(max-min+1);
} 

string Return_Word(int);
string Reverse(string);
vector <string> Split(string);

bool InputCheckFirstStep(string, string);
bool InputCheckSecondStep(vector<string>, string[TotalWordsCount]);
bool InputCheckThirdStep(vector<string>, string[TotalWordsCount]);
bool InputCheckForthStep(vector<string>, string[TotalWordsCount]);
bool InputCheckFifthStep(vector<string>, string[TotalWordsCount]);

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
            // ������ ������ ����� 5 ����
            case 0:
                FirstStageWord = Return_Word(5);
                cout << "1 ���� 1 ������. ��������� �������: " << CorrectInputs % 3 << endl;
                cout << "��������������� �����: " << FirstStageWord << endl;
                cout << "���� �����: ";
                getline(cin, InputData);
                if (Reverse(InputData) == FirstStageWord){ 
                    cout << "����� ������!" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "���� ���� �������� ������." << endl;
                    CorrectInputs = 0;
                }
                        
                break;

            // ������ ������ ����� 6 ����
            case 1:
                FirstStageWord = Return_Word(6);
                cout << "1 ���� 2 ������. ��������� �������: " << CorrectInputs % 3 << endl;
                cout << "��������������� �����: " << FirstStageWord << endl;
                cout << "���� �����: ";
                getline(cin, InputData);
                if (Reverse(InputData) == FirstStageWord){ 
                    cout << "����� ������!" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "���� ���� �������� ������." << endl;
                    CorrectInputs = 0;
                }
                        
                break;

            // ������ ������ ����� 7 ����
            case 2:
                FirstStageWord = Return_Word(7);
                cout << "1 ���� 3 ������. ��������� �������: " << CorrectInputs % 3 << endl;
                cout << "��������������� �����: " << FirstStageWord << endl;
                cout << "���� �����: ";
                getline(cin, InputData);
                if (Reverse(InputData) == FirstStageWord){ 
                    cout << "����� ������!" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "���� ���� �������� ������." << endl;
                    CorrectInputs = 0;
                }
                        
                break;

            // ������ ������ ����� 8 ����
            case 3:
                FirstStageWord = Return_Word(8);
                cout << "1 ���� 4 ������. ��������� �������: " << CorrectInputs % 3 << endl;
                cout << "��������������� �����: " << FirstStageWord << endl;
                cout << "���� �����: ";
                getline(cin, InputData);
                if (Reverse(InputData) == FirstStageWord){ 
                    cout << "����� ������!" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "���� ���� �������� ������." << endl;
                    CorrectInputs = 0;
                }
                    
                break;
                
            //  ������ ������ �����
            case 4:
                for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);

                cout << "2 ����. ��������� �������: " << CorrectInputs % 3 << endl;
                cout << "��������������� ������������������: ";
                for (string word: SecondStageWords) cout << word << " ";
                cout << "\n���� ������������������: ";
                getline(cin, InputData);
                UsersWordsList = Split(InputData);
                if (size(UsersWordsList) == TotalWordsCount){
                    if (InputCheckSecondStep(UsersWordsList, SecondStageWords)){
                        cout << "����� ������!" << endl;
                        CorrectInputs++;
                    }
                    else{
                        cout << "���� ���� �������� ������." << endl << endl;
                        CorrectInputs = 0;
                    }
                }
                // Error
                else{
                    cout << "���� ���� �������� ������." << endl << endl;
                    CorrectInputs = 0;
                }
                
                break;
            
            //  ������ ������ �����
            case 5:
                for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
                
                cout << "3 ����. ��������� �������: " << CorrectInputs % 3 << endl;
                cout << "��������������� ������������������: ";
                for (string word: SecondStageWords) cout << word << " ";
                cout << "\n���� ������������������: ";
                getline(cin, InputData);
                UsersWordsList = Split(InputData);
                if (size(UsersWordsList) == TotalWordsCount){
                    if (InputCheckThirdStep(UsersWordsList, SecondStageWords)){
                        cout << "����� ������!" << endl;
                        CorrectInputs++;
                    }
                    else{
                        cout << "���� ���� �������� ������." << endl << endl;
                        CorrectInputs = 0;
                    }
                }
                // Error
                else{
                    cout << "���� ���� �������� ������." << endl << endl;
                    CorrectInputs = 0;
                }
                
                break;

            //  ��������� ������ �����
            case 6:
                for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
                
                cout << "4 ����. ��������� �������: " << CorrectInputs % 3 << endl;
                cout << "��������������� ������������������: ";
                for (string word: SecondStageWords) cout << word << " ";
                cout << "\n���� ������������������: ";
                getline(cin, InputData);
                UsersWordsList = Split(InputData);
                if (size(UsersWordsList) == TotalWordsCount){
                    if (InputCheckForthStep(UsersWordsList, SecondStageWords)){
                        cout << "����� ������!" << endl;
                        CorrectInputs++;
                    }
                    else{
                        cout << "���� ���� �������� ������." << endl << endl;
                        CorrectInputs = 0;
                    }
                }
                // Error
                else{
                    cout << "���� ���� �������� ������." << endl << endl;
                    CorrectInputs = 0;
                }
                
                break;

            //  ����� ������ �����
            case 7:
                for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
                
                cout << "5 ����. ��������� �������: " << CorrectInputs % 3 << endl;
                cout << "��������������� ������������������: ";
                for (string word: SecondStageWords) cout << word << " ";
                cout << "\n���� ������������������: ";
                getline(cin, InputData);
                UsersWordsList = Split(InputData);
                if (size(UsersWordsList) == TotalWordsCount){
                    if (InputCheckFifthStep(UsersWordsList, SecondStageWords)){
                        cout << "����� ������!" << endl;
                        CorrectInputs++;
                    }
                    else{
                        cout << "���� ���� �������� ������." << endl << endl;
                        CorrectInputs = 0;
                    }
                }
                // Error
                else{
                    cout << "���� ���� �������� ������." << endl << endl;
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
                Flag = (Processed_Words[i] == Word);
        }
        else{    
            cout<<"Error. Cannot open file"<<endl;
        }

        file.close();
    }
    while(Flag);
    Processed_Words[Num_Word++] = Word;
    return Word.substr(0, letters);
}

string Reverse(string Line){
    string Result{};
    int StartCheck = Line.find_first_not_of(' ');
    int EndCheck = Line.find_last_not_of(' ');
    for (int i = EndCheck;i >= StartCheck;Result += Line[i--]);
        
    return Result;
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
bool InputCheckThirdStep(vector<string> UsersWords, string GenWords[TotalWordsCount]){
    
    for (int i = 0;i < TotalWordsCount;i++){
        if (UsersWords[i] != GenWords[i]) return false;
    }
    return true;
}
bool InputCheckForthStep(vector<string> UsersWords, string GenWords[TotalWordsCount]){
    
    for (int i = 0;i < TotalWordsCount;i++){
        bool flag = false;
        for (int j = 0;!flag && j < TotalWordsCount;j++){
            if (Reverse(UsersWords.back()) == GenWords[j]){
                UsersWords.pop_back();
                flag = true;
            }
        }
        if (!flag)
            return false;
    }
    return true;
}
bool InputCheckFifthStep(vector<string> UsersWords, string GenWords[TotalWordsCount]){
    for (int i = 0;i < TotalWordsCount;i++){
        if (Reverse(UsersWords[i]) != GenWords[i]) return false;
    }
    return true;
}
