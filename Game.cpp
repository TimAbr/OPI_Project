#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <stdlib.h>

using namespace std;

const int TotalWordsCount = 5;
const int TotalGenWords = 400;
const string EndMess[2] = {"выход", "новое начало игры"};
const string LoadLine{"--------------------"};

string Processed_Words[TotalGenWords]{};
int Num_Word{0};

string Return_Word(int, int);
string Reverse(string);
vector <string> Split(string);

int ComplexLevel();
bool InputCheckFirstStep(string, string);
bool InputCheckSecondStep(vector<string>, vector <string>);
bool InputCheckThirdStep(vector<string>, vector <string>);
bool InputCheckForthStep(vector<string>, vector <string>);
bool InputCheckFifthStep(vector<string>, vector <string>);
void CorrInputMess(int, int, string, vector <string>);
void CorrInputMess(int, int, string, string);
void ErrorMess(int, string);
void ErrorMess(int, vector <string>);
void CleanArr(string[]);
void UpperCase(string&);
void Prepare();

int main(){
    
    srand(time(NULL));
    int CorrectInputs{0};
    int TimeMemory[5][2] {{7000, 15000}, {5000, 10000}, {3000, 7000}, {1500, 5000}, {1000, 3000}};
    int HardLevel{0};
    int CorrIntInput{0};
    int Stage{1};
    string InputData{};
    string FirstStageWord{};
    vector<string> UsersWordsList{}; 
    vector<string> GeneratedWords{};
    bool GameOver{false};

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    HardLevel = ComplexLevel();
    CorrectInputs = 0;
    while (!GameOver){   
        
        switch(Stage){
            // --------------------------------------------------------------------------------
            case 1:
                // generation the word
                FirstStageWord = "";
                do{
                    srand(time(NULL));
                    FirstStageWord = Return_Word(5 + CorrectInputs / 3, 1 + rand()%(100));
                }while (FirstStageWord == "");

                // message to the user
                cout << Stage << " ЭТАП "<< CorrectInputs / 3 + 1 << " СТАДИЯ. Правильно введено: " 
                    << CorrectInputs % 3 << endl;
                cout << "Сгенерированное слово: " << FirstStageWord << endl;

                // pause and block to input
                Sleep(TimeMemory[HardLevel][0]);
                system("cls");
                while (_kbhit()){_getch();}

                // entering users word
                cout << "1 ЭТАП "<< CorrectInputs / 3 + 1 << " СТАДИЯ. Правильно введено: " 
                << CorrectInputs % 3 << endl;
                cout << "Ваше слово: ";
                getline(cin,InputData);
                UpperCase(InputData);

                // correctness input checking
                if (Reverse(InputData) == FirstStageWord){          
                    CorrInputMess(Stage, CorrectInputs, InputData, FirstStageWord);
                    CorrectInputs++;
                    if (CorrectInputs == 12){
                        Stage++;
                        Prepare();
                        CorrectInputs = 0;
                    }
                }
                else {
                    ErrorMess(Stage, FirstStageWord);
                    CorrectInputs = 0;
                    GameOver = true;
                }

                break;
            //---------------------------------------------------------------------------
            case 2:
                // generation of the sequence
                GeneratedWords.clear();
                GeneratedWords.resize(TotalWordsCount + CorrectInputs / 3);
                for (int i = 0;i < TotalWordsCount + CorrectInputs / 3;  i++){
                    do{
                        GeneratedWords[i] = Return_Word(5 + rand()%(4), 1 + rand()%(100));
                    }while (GeneratedWords[i] == "");    
                    Processed_Words[Num_Word++] = GeneratedWords[i];
                }

                // message to the user
                cout << Stage << " ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированная последовательность: ";
                for (string word: GeneratedWords) cout << word << " ";

                // pause and block to input
                Sleep(TimeMemory[HardLevel][1]);
                system("cls");
                while(_kbhit()){_getch();}

                //  entering users sequence
                cout << Stage << " ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Ваша последовательность: ";
                getline(cin, InputData);
                UpperCase(InputData);
                UsersWordsList = Split(InputData);

                // correctness input checking
                if (InputCheckSecondStep(UsersWordsList, GeneratedWords)){
                    CorrInputMess(Stage, CorrectInputs, InputData, GeneratedWords);
                    CorrectInputs++;
                    if (CorrectInputs == 12){
                        Stage++;
                        Prepare();
                        CorrectInputs = 0;
                    }
                }
                else {
                    ErrorMess(Stage, GeneratedWords);
                    CorrectInputs = 0;
                    GameOver = true;
                }
                break;
            //-------------------------------------------------------------------------------
            case 3:
                // generation of the sequence
                GeneratedWords.clear();
                GeneratedWords.resize(TotalWordsCount + CorrectInputs / 3);
                for (int i = 0;i < TotalWordsCount + CorrectInputs / 3;  i++){
                    do{
                        GeneratedWords[i] = Return_Word(5 + rand()%(4), 1 + rand()%(100));
                    }while (GeneratedWords[i] == "");    
                    Processed_Words[Num_Word++] = GeneratedWords[i];
                }

                // message to the user
                cout << Stage << " ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированная последовательность: ";
                for (string word: GeneratedWords) cout << word << " ";

                // pause and block to input
                Sleep(TimeMemory[HardLevel][1]);
                system("cls");
                while(_kbhit()){_getch();}

                //  entering users sequence
                cout << Stage << " ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Ваша последовательность: ";
                getline(cin, InputData);
                UpperCase(InputData);
                UsersWordsList = Split(InputData);

                // correctness input checking
                if (InputCheckThirdStep(UsersWordsList, GeneratedWords)){
                    CorrInputMess(Stage, CorrectInputs, InputData, GeneratedWords);
                    CorrectInputs++;
                    if (CorrectInputs == 12){
                        Stage++;
                        Prepare();
                        CorrectInputs = 0;
                    }
                }
                else {
                    ErrorMess(Stage, GeneratedWords);
                    CorrectInputs = 0;
                    GameOver = true;
                }
                break;
            //------------------------------------------------------------------------------------------
            case 4:
                // generation of the sequence
                GeneratedWords.clear();
                GeneratedWords.resize(TotalWordsCount + CorrectInputs / 3);
                for (int i = 0;i < TotalWordsCount + CorrectInputs / 3;  i++){
                    do{
                        GeneratedWords[i] = Return_Word(5 + rand()%(4), 1 + rand()%(100));
                    }while (GeneratedWords[i] == "");    
                    Processed_Words[Num_Word++] = GeneratedWords[i];
                }

                // message to the user
                cout << Stage << " ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированная последовательность: ";
                for (string word: GeneratedWords) cout << word << " ";

                // pause and block to input
                Sleep(TimeMemory[HardLevel][1]);
                system("cls");
                while(_kbhit()){_getch();}

                //  entering users sequence
                cout << Stage << " ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Ваша последовательность: ";
                getline(cin, InputData);
                UpperCase(InputData);
                UsersWordsList = Split(InputData);

                // correctness input checking
                if (InputCheckForthStep(UsersWordsList, GeneratedWords)){
                    CorrInputMess(Stage, CorrectInputs, InputData, GeneratedWords);
                    CorrectInputs++;
                    if (CorrectInputs == 12){
                        Stage++;
                        Prepare();
                        CorrectInputs = 0;
                    }
                }
                else {
                    ErrorMess(Stage, GeneratedWords);
                    CorrectInputs = 0;
                    GameOver = true;
                }
                break;
            //------------------------------------------------------------------------------------------
            case 5:
                // generation of the sequence
                GeneratedWords.clear();
                GeneratedWords.resize(TotalWordsCount + CorrectInputs / 3);
                for (int i = 0;i < TotalWordsCount + CorrectInputs / 3;  i++){
                    do{
                        GeneratedWords[i] = Return_Word(5 + rand()%(4), 1 + rand()%(100));
                    }while (GeneratedWords[i] == "");    
                    Processed_Words[Num_Word++] = GeneratedWords[i];
                }

                // message to the user
                cout << Stage << " ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированная последовательность: ";
                for (string word: GeneratedWords) cout << word << " ";

                // pause and block to input
                Sleep(TimeMemory[HardLevel][1]);
                system("cls");
                while(_kbhit()){_getch();}

                //  entering users sequence
                cout << Stage << " ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Ваша последовательность: ";
                getline(cin, InputData);
                UpperCase(InputData);
                UsersWordsList = Split(InputData);

                // correctness input checking
                if (InputCheckFifthStep(UsersWordsList, GeneratedWords)){
                    CorrInputMess(Stage, CorrectInputs, InputData, GeneratedWords);
                    CorrectInputs++;
                    if (CorrectInputs == 12){
                        Stage++;
                        Prepare();
                        CorrectInputs = 0;
                    }
                }
                else {
                    ErrorMess(Stage, GeneratedWords);
                    CorrectInputs = 0;
                    GameOver = true;
                }
                break;

        }

        if (GameOver){
            cout << "Чтобы полностью завершить работу программы нажмите ESC." << endl;
            cout << "Введите 1, если желаете начать заново на этом этапе, или 0, если желаете начать с самого начала: ";
            
            CorrIntInput = 0;
            int TempStage{0};

            do{
                if (_kbhit()){
                    CorrIntInput = _getch();
                    if (CorrIntInput == 27){
                        GameOver = true;
                        break;
                    }
                    else if ('0' == CorrIntInput || '1' == CorrIntInput){
                        GameOver = false;
                        TempStage = ('1' == CorrIntInput) ? Stage: -1;

                        system("cls");
                        cout << "Чтобы полностью завершить работу программы нажмите ESC." << endl;
                        cout << "Введите 1, если желаете начать заново на этом этапе с тем же уровнем сложности,"<< endl 
                            << "или 0, если желаете начать с самого начала: " << CorrIntInput - 48;
                        cout << "\nПоддтвердите ваш выбор, нажав клавишу ENTER." << endl;
                    }
                }
            }while(CorrIntInput != 13 || TempStage == 0);
            system("cls");
            
            Stage = TempStage;
            if (Stage == -1 && CorrIntInput != 27){ 
                HardLevel = ComplexLevel();
                Stage = 1;
            }
            else if (CorrIntInput != 27) Prepare();
        }
    }

    cout << "ИГРА ОКОНЧЕНА." << endl;

    //чтобы консоль не закрывалась сразу. Аналог Readln; в делфи
    system("pause");
    return 0;
}

string Return_Word(int letters, int Word_Index){

    string Word{};
    fstream file;

    bool Flag = false;
    
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
    if (Flag) return "";

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

bool InputCheckSecondStep(vector<string> UsersWords, vector <string> GenWords){
    
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
bool InputCheckThirdStep(vector<string> UsersWords, vector <string> GenWords){
    
    for (int i = 0;i < TotalWordsCount;i++){
        if (UsersWords[i] != GenWords[i]) return false;
    }
    return true;
}
bool InputCheckForthStep(vector<string> UsersWords, vector <string> GenWords){
    
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
bool InputCheckFifthStep(vector<string> UsersWords, vector <string> GenWords){
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
        if ('а' <= Str[i] && Str[i] <= 'я')
            Str[i] = (unsigned char)Str[i] - 32;
    }
}

void CorrInputMess(int Stage, int CorrInputs, string UsersLine, string GenWord){

    for (int i = 19; i >= 0; i --){
        system("cls");

        cout << Stage << " ЭТАП "<< CorrInputs / 3 + 1 << " СТАДИЯ. Правильно введено: " 
            << CorrInputs % 3 << endl;
        cout << "Ваше слово: " << UsersLine << endl;
        cout << "Сгенерированное слово: " << GenWord << endl;
        cout << "ОТВЕТ ВЕРНЫЙ!" << endl;
        cout << LoadLine.substr(0,i);

        Sleep(100);
    }
    system("cls");
    
}
void CorrInputMess(int Stage, int CorrInputs, string UsersLine, vector <string> GenWords){

    for (int i = 19; i >= 0; i --){
        system("cls");

        cout << Stage << " ЭТАП. Правильно введено: " << CorrInputs % 3 << endl;
        cout << "Ваша последовательность: " << UsersLine << endl;
        cout << "Сгенерированная последовательность: ";
        for (string word: GenWords) cout << word << " ";
        cout << "\nОТВЕТ ВЕРНЫЙ!" << endl;
        cout << LoadLine.substr(0,i);

        Sleep(100);
    }
    system("cls");  
}

void ErrorMess(int Stage, string GenWord){
    cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
    cout << "Начальное слово: " << GenWord + "\n" << endl;
}
void ErrorMess(int Stage, vector <string> GenWords){
    cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
    cout << "Сгенерированная последовательность: ";
    for (string word: GenWords) cout << word << " ";
    cout << "\n" << endl;
}

int ComplexLevel(){
    system("cls");
    cout << "Введите номер уровня сложности:\n";
    cout << "1) Самый легкий.\n";
    cout << "2) Простой.\n";
    cout << "3) Средний.\n";
    cout << "4) Сложный.\n";
    cout << "5) Эксперт.\n"; 
    int CorrIntInput = 0;
    int HardLevel = 0;
    CleanArr(Processed_Words);
    do{
        if (_kbhit()){

            CorrIntInput = _getch();
            if ('1' <= CorrIntInput && CorrIntInput <= '5'){
                HardLevel = CorrIntInput - 48;system("cls");
                cout << "Введите номер уровня сложности:\n";
                cout << "1) Самый легкий.\n";
                cout << "2) Простой.\n";
                cout << "3) Средний.\n";
                cout << "4) Сложный.\n";
                cout << "5) Эксперт.\n";
                cout << "Был выбран " << HardLevel << " уровень сложности. \nПодтвердите свой выбор, нажав ENTER." << endl;
            }
        }
    }while(CorrIntInput != 13 || HardLevel == 0);
    for (int i = 19; i >= 0; i --){
        system("cls");
        cout << "УРОВЕНЬ СЛОЖНОСТИ: " << HardLevel << endl << "ПРИГОТОВЬТЕСЬ!" << endl;
        cout << LoadLine.substr(0,i);
        Sleep(100);
    }
    system("cls");
    return HardLevel - 1;
}

void Prepare(){
    for (int i = 19; i >= 0; i --){
        system("cls");
        
        cout << "Будьте готовы!" << endl;
        cout << LoadLine.substr(0,i);

        Sleep(100);
    }
    system("cls");
}


