#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

const int TotalWordsCount = 5;
const int TotalGenWords = 32;
const string EndMess[2] = {"�����", "����� ������ ����"};
const string LoadLine{"--------------------"};

string Processed_Words[TotalGenWords]{};
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
void CorrInputMess(int, int, string, string[TotalGenWords]);
void ErrorMess(int, string[TotalGenWords]);
void CleanArr(string[]);
void UpperCase(string&);
void MessageAboutChooseHard();

int main(){
    int CorrectInputs{0};
    int TimeMemory[5][2] {{7000, 15000}, {5000, 10000}, {3000, 7000}, {1500, 5000}, {1000, 3000}};
    int HardLevel;
    int CorrIntInput;
    int Stage{1};
    string GeneratedWords[TotalWordsCount]{};
    string InputData{};// Users input 
    vector<string> UsersWordsList{}; 
    bool GameOver{false};

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (!GameOver){   

        CleanArr(Processed_Words);
        CorrectInputs = 0;
        HardLevel = 0;
        MessageAboutChooseHard();
        do{
            if (_kbhit()){

                CorrIntInput = _getch();
                if ('1' <= CorrIntInput && CorrIntInput <= '5'){

                    HardLevel = CorrIntInput - 48;
                    MessageAboutChooseHard();
                    cout << "��� ������ " << HardLevel << " ������� ���������. \n����������� ���� �����, ����� ENTER." << endl;
                
                }
            }
        }while(CorrIntInput != 13 || HardLevel == 0);

        for (int i = 19; i >= 0; i --){
            system("cls");
            cout << "������� ���������: " << HardLevel << endl << "�������������!" << endl;
            cout << LoadLine.substr(0,i);
            Sleep(100);
        }

        system("cls");
        HardLevel--;
        // ������ ����
        while (!GameOver && CorrectInputs < 12){

            GeneratedWords[0] = Return_Word(5 + CorrectInputs / 3);
            cout << "1 ���� "<< CorrectInputs / 3 + 1 << " ������. ��������� �������: " 
                << CorrectInputs % 3 << endl;
            cout << "��������������� �����: " << GeneratedWords[0] << endl;

            Sleep(TimeMemory[HardLevel][0]);
            system("cls");
            while (_kbhit()){_getch();}

            cout << "1 ���� "<< CorrectInputs / 3 + 1 << " ������. ��������� �������: " 
                << CorrectInputs % 3 << endl;
            cout << "���� �����: ";
            getline(cin,InputData);

            UpperCase(InputData);
            if (Reverse(InputData) == GeneratedWords[0]){ 
                // ��������� � ���������� �����           
                CorrInputMess(Stage, CorrectInputs, InputData, GeneratedWords);
                CorrectInputs++;
            }

            else {
                ErrorMess(Stage, GeneratedWords);
                GameOver = true;
            }
        }
        
        (!GameOver) ? Stage++: 0;
        // ������ ����
        while (!GameOver && CorrectInputs < 15){
            
            for (int i = 0;i < TotalWordsCount; GeneratedWords[i] = Return_Word(GetRandomNumber(5,8)), i++);

            cout << "2 ����. ��������� �������: " << CorrectInputs % 3 << endl;
            cout << "��������������� ������������������: ";
            for (string word: GeneratedWords) cout << word << " ";

            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            //���������� ����� �������� ���� ������� �� ���������
            while(_kbhit()){_getch();}

            cout << "2 ����. ��������� �������: " << CorrectInputs % 3 << endl;
            cout << "���� ������������������: ";
            getline(cin, InputData);

            UpperCase(InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){

                if (InputCheckSecondStep(UsersWordsList, GeneratedWords)){
                    // ��������� � ���������� �����
                    CorrInputMess(Stage, CorrectInputs, InputData, GeneratedWords);
                    CorrectInputs++;
                }

                else {
                    ErrorMess(Stage, GeneratedWords);
                    GameOver = true;
                }
            }
            // Error
            else {
                ErrorMess(Stage, GeneratedWords);
                GameOver = true;
            }
        }

        (!GameOver) ? Stage++: 0;
        // ������ ����
        while (!GameOver && CorrectInputs < 18){

            for (int i = 0;i < TotalWordsCount; GeneratedWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
            
            cout << "3 ����. ��������� �������: " << CorrectInputs % 3 << endl;
            cout << "��������������� ������������������: ";
            for (string word: GeneratedWords) cout << word << " ";

            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            //���������� ����� �������� ���� ������� �� ���������
            while(_kbhit()){_getch();}

            cout << "3 ����. ��������� �������: " << CorrectInputs % 3 << endl;
            cout << "���� ������������������: ";
            getline(cin, InputData);

            UpperCase(InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){

                if (InputCheckThirdStep(UsersWordsList, GeneratedWords)){
                    // ��������� � ���������� �����
                    CorrInputMess(Stage, CorrectInputs, InputData, GeneratedWords);
                    CorrectInputs++;
                }

                else {
                    ErrorMess(Stage, GeneratedWords);
                    GameOver = true;
                }
            }
            // Error
            else {
                ErrorMess(Stage, GeneratedWords);
                GameOver = true;
            }           
        }

        (!GameOver) ? Stage++: 0;
        // ��������� ����
        while (!GameOver && CorrectInputs < 21){

            for (int i = 0;i < TotalWordsCount; GeneratedWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
            
            cout << "4 ����. ��������� �������: " << CorrectInputs % 3 << endl;
            cout << "��������������� ������������������: ";
            for (string word: GeneratedWords) cout << word << " ";

            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            //���������� ����� �������� ���� ������� �� ���������
            while(_kbhit()){_getch();}

            cout << "4 ����. ��������� �������: " << CorrectInputs % 3 << endl;
            cout << "���� ������������������: ";
            getline(cin, InputData);

            UpperCase(InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){

                if (InputCheckForthStep(UsersWordsList, GeneratedWords)){
                    // ��������� � ���������� �����
                    CorrInputMess(Stage, CorrectInputs, InputData, GeneratedWords);
                    CorrectInputs++;
                }

                else {
                    ErrorMess(Stage, GeneratedWords);
                    GameOver = true;
                }
            }
            // Error
            else {
                ErrorMess(Stage, GeneratedWords);
                GameOver = true;
            }
        }

        (!GameOver) ? Stage++: 0;
        // ����� ����   
        while (!GameOver && CorrectInputs < 24){

            for (int i = 0;i < TotalWordsCount; GeneratedWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
            
            cout << "5 ����. ��������� �������: " << CorrectInputs % 3 << endl;
            cout << "��������������� ������������������: ";
            for (string word: GeneratedWords) cout << word << " ";

            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            //���������� ����� �������� ���� ������� �� ���������
            while(_kbhit()){_getch();}

            cout << "5 ����. ��������� �������: " << CorrectInputs % 3 << endl;
            cout << "���� ������������������: ";
            getline(cin, InputData);

            UpperCase(InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){

                if (InputCheckFifthStep(UsersWordsList, GeneratedWords)){
                    // ��������� � ���������� �����
                    CorrInputMess(Stage, CorrectInputs, InputData, GeneratedWords);
                    CorrectInputs ++;

                }

                else {
                    ErrorMess(Stage, GeneratedWords);
                    GameOver = true;
                }
            }
            // Error
            else {
                ErrorMess(Stage, GeneratedWords);
                GameOver = true;
            }
        }

        if (GameOver){

            cout << "������� 1, ���� ������� ������ ������. � ��������� ������ ������� 0: ";
            
            CorrIntInput = 0;
            do{
                if (_kbhit()){
                    CorrIntInput = _getch();
                    if ('0' == CorrIntInput || '1' == CorrIntInput){

                        GameOver = !(CorrIntInput - 48);

                        system("cls");
                        ErrorMess(Stage, GeneratedWords);
                        cout << "������� 1, ���� ������� ������ ������. � ��������� ������ ������� 0: " << CorrIntInput - 48 << endl;
                        cout << "������������ " << EndMess[CorrIntInput - 48] << ", ����� ������� ENTER." << endl;
                   
                    }
                }
            }while(CorrIntInput != 13 || CorrIntInput == 0);

        }
    }

    cout << "���� ��������." << endl;

    //����� ������� �� ����������� �����. ������ Readln; � �����
    system("pause");
    return 0;
}

string Return_Word(int letters){
    srand(time(NULL));

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

void CleanArr(string Arr[]){
    for (int i = 0;i < TotalGenWords; Arr[i++] = "");
}
void UpperCase(string &Str){
    for (int i = 0;i < Str.length();i++){
        if ('�' <= Str[i] && Str[i] <= '�')
            Str[i] = (unsigned char)Str[i] - 32;
    }
}
void CorrInputMess(int Stage, int CorrInputs, string UsersLine, string GenWords[TotalGenWords]){

    
    if (Stage == 1){
        for (int i = 19; i >= 0; i --){
            system("cls");

            cout << "1 ���� "<< CorrInputs / 3 + 1 << " ������. ��������� �������: " 
                << CorrInputs % 3 << endl;
            cout << "���� �����: " << UsersLine << endl;
            cout << "��������������� �����: " << GenWords[0] << endl;
            cout << "����� ������!" << endl;
            cout << LoadLine.substr(0,i);

            Sleep(100);
        }
        system("cls");
    }
    else{
        for (int i = 19; i >= 0; i --){
            system("cls");

            cout << Stage << " ����. ��������� �������: " << CorrInputs % 3 << endl;
            cout << "���� ������������������: " << UsersLine << endl;
            cout << "��������������� ������������������: ";
            for (int i = 0; i < TotalGenWords; cout << GenWords[i++] << " ");
            cout << "����� ������!" << endl;
            cout << LoadLine.substr(0,i);

            Sleep(100);
        }
        system("cls");
    }
}
void ErrorMess(int Stage, string GenWords[TotalGenWords]){

    if (Stage == 1){
        cout << "���� ���� �������� ������!" << endl;
        cout << "��������� �����: " << GenWords[0] + "\n" << endl;
    }

    else{
        cout << "���� ���� �������� ������!" << endl;
        cout << "��������������� ������������������: ";
        for (int i = 0; i < TotalGenWords; cout << GenWords[i++] << " ");
        cout << endl;
    }
}
void MessageAboutChooseHard(){
    system("cls");
    cout << "������� ����� ������ ���������:\n";
    cout << "1) ����� ������.\n";
    cout << "2) �������.\n";
    cout << "3) �������.\n";
    cout << "4) �������.\n";
    cout << "5) �������.\n"; 
}

