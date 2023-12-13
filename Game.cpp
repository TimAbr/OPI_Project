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
const int TotalGenWords = 72;
const string EndMess[2] = {"выход", "новое начало игры"};
const string LoadLine{"--------------------"};

string Processed_Words[TotalGenWords]{};
int Num_Word{0};

string Return_Word(int, int);
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
    
    srand(time(NULL));
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
        srand(time(NULL));
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
        HardLevel--;
        // ПЕРВЫЙ ЭТАП
        while (!GameOver && CorrectInputs < 12){

            GeneratedWords[0] = Return_Word(5 + CorrectInputs / 3, 1 + rand()%(100));
            cout << "1 ЭТАП "<< CorrectInputs / 3 + 1 << " СТАДИЯ. Правильно введено: " 
                << CorrectInputs % 3 << endl;
            cout << "Сгенерированное слово: " << GeneratedWords[0] << endl;

            Sleep(TimeMemory[HardLevel][0]);
            system("cls");
            while (_kbhit()){_getch();}

            cout << "1 ЭТАП "<< CorrectInputs / 3 + 1 << " СТАДИЯ. Правильно введено: " 
                << CorrectInputs % 3 << endl;
            cout << "Ваше слово: ";
            getline(cin,InputData);

            UpperCase(InputData);
            if (Reverse(InputData) == GeneratedWords[0]){ 
                // Сообщение о корректном вводе           
                CorrInputMess(Stage, CorrectInputs, InputData, GeneratedWords);
                CorrectInputs++;
            }

            else {
                ErrorMess(Stage, GeneratedWords);
                GameOver = true;
            }
        }
        
        (!GameOver) ? Stage++: 0;
        // ВТОРОЙ ЭТАП
        while (!GameOver && CorrectInputs < 15){
            
            for (int i = 0;i < TotalWordsCount;  i++)
                GeneratedWords[i] = Return_Word(5 + rand()%(4), 1 + rand()%(100));

            cout << "2 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
            cout << "Сгенерированная последовательность: ";
            for (string word: GeneratedWords) cout << word << " ";

            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            //блокировка ввода символов пока консоль не обновлена
            while(_kbhit()){_getch();}

            cout << "2 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
            cout << "Ваша последовательность: ";
            getline(cin, InputData);

            UpperCase(InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){

                if (InputCheckSecondStep(UsersWordsList, GeneratedWords)){
                    // Сообщение о корректном вводе
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
        // ТРЕТИЙ ЭТАП
        while (!GameOver && CorrectInputs < 18){

            for (int i = 0;i < TotalWordsCount; i++)
                GeneratedWords[i] = Return_Word(5 + rand()%(4), 1 + rand()%(100));

            cout << "3 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
            cout << "Сгенерированная последовательность: ";
            for (string word: GeneratedWords) cout << word << " ";

            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            //блокировка ввода символов пока консоль не обновлена
            while(_kbhit()){_getch();}

            cout << "3 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
            cout << "Ваша последовательность: ";
            getline(cin, InputData);

            UpperCase(InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){

                if (InputCheckThirdStep(UsersWordsList, GeneratedWords)){
                    // Сообщение о корректном вводе
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
        // ЧЕТВЕРТЫЙ ЭТАП
        while (!GameOver && CorrectInputs < 21){

            for (int i = 0;i < TotalWordsCount; i++)
                GeneratedWords[i] = Return_Word(5 + rand()%(4), 1 + rand()%(100));

            cout << "4 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
            cout << "Сгенерированная последовательность: ";
            for (string word: GeneratedWords) cout << word << " ";

            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            //блокировка ввода символов пока консоль не обновлена
            while(_kbhit()){_getch();}

            cout << "4 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
            cout << "Ваша последовательность: ";
            getline(cin, InputData);

            UpperCase(InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){

                if (InputCheckForthStep(UsersWordsList, GeneratedWords)){
                    // Сообщение о корректном вводе
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
        // ПЯТЫЙ ЭТАП   
        while (!GameOver && CorrectInputs < 24){

            for (int i = 0;i < TotalWordsCount; i++)
                GeneratedWords[i] = Return_Word(5 + rand()%(4), 1 + rand()%(100));

            cout << "5 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
            cout << "Сгенерированная последовательность: ";
            for (string word: GeneratedWords) cout << word << " ";

            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            //блокировка ввода символов пока консоль не обновлена
            while(_kbhit()){_getch();}

            cout << "5 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
            cout << "Ваша последовательность: ";
            getline(cin, InputData);

            UpperCase(InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){

                if (InputCheckFifthStep(UsersWordsList, GeneratedWords)){
                    // Сообщение о корректном вводе
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

            cout << "Введите 1, если желаете начать заново. В противном случае введите 0: ";
            
            bool Flag{true};
            CorrIntInput = 0;
            do{
                if (_kbhit()){
                    CorrIntInput = _getch();
                    if ('0' == CorrIntInput || '1' == CorrIntInput){
                        Flag = false;
                        GameOver = !(CorrIntInput - 48);

                        system("cls");
                        ErrorMess(Stage, GeneratedWords);
                        cout << "Введите 1, если желаете начать заново. В противном случае введите 0: " << CorrIntInput - 48 << endl;
                        cout << "Поддтвердите " << EndMess[CorrIntInput - 48] << ", нажав клавишу ENTER." << endl;
                   
                    }
                }
            }while(CorrIntInput != 13 || Flag);

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
    do{

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
        Sleep(100);
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
        if ('а' <= Str[i] && Str[i] <= 'я')
            Str[i] = (unsigned char)Str[i] - 32;
    }
}
void CorrInputMess(int Stage, int CorrInputs, string UsersLine, string GenWords[TotalGenWords]){

    
    if (Stage == 1){
        for (int i = 19; i >= 0; i --){
            system("cls");

            cout << "1 ЭТАП "<< CorrInputs / 3 + 1 << " СТАДИЯ. Правильно введено: " 
                << CorrInputs % 3 << endl;
            cout << "Ваше слово: " << UsersLine << endl;
            cout << "Сгенерированное слово: " << GenWords[0] << endl;
            cout << "ОТВЕТ ВЕРНЫЙ!" << endl;
            cout << LoadLine.substr(0,i);

            Sleep(100);
        }
        system("cls");
    }
    else{
        for (int i = 19; i >= 0; i --){
            system("cls");

            cout << Stage << " ЭТАП. Правильно введено: " << CorrInputs % 3 << endl;
            cout << "Ваша последовательность: " << UsersLine << endl;
            cout << "Сгенерированная последовательность: ";
            for (int i = 0; i < TotalGenWords; cout << GenWords[i++] << " ");
            cout << "ОТВЕТ ВЕРНЫЙ!" << endl;
            cout << LoadLine.substr(0,i);

            Sleep(100);
        }
        system("cls");
    }
}
void ErrorMess(int Stage, string GenWords[TotalGenWords]){

    if (Stage == 1){
        cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
        cout << "Начальное слово: " << GenWords[0] + "\n" << endl;
    }

    else{
        cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
        cout << "Сгенерированная последовательность: ";
        for (int i = 0; i < TotalGenWords; cout << GenWords[i++] << " ");
        cout << endl;
    }
}
void MessageAboutChooseHard(){
    system("cls");
    cout << "Введите номер уровня сложности:\n";
    cout << "1) Самый легкий.\n";
    cout << "2) Простой.\n";
    cout << "3) Средний.\n";
    cout << "4) Сложный.\n";
    cout << "5) Эксперт.\n"; 
}

