#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

const int TotalWordsCount = 5;
string Processed_Words[32]{}, EmptyArr[32]{};
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
    int TimeMemory[5][2] {{7000, 15000}, {5000, 10000}, {3000, 7000}, {1500, 5000}, {1000, 3000}};
    int HardLevel{2};
    string FirstStageWord{};
    string SecondStageWords[TotalWordsCount]{};
    string InputData{};// Users input 
    vector<string> UsersWordsList{}; 

    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    cout << "Введите уровень сложности:\n";
    cout << "1) Самый легкий. Выделяется больше всего времени.\n";
    cout << "2) Простой.\n";
    cout << "3) Средний.\n";
    cout << "4) Сложный.\n";
    cout << "5) Эксперт.\n";
    cin >> HardLevel;

    while (true){   
        switch ((int)(CorrectInputs / 3)){
            // пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ 5 пїЅпїЅпїЅпїЅ
            case 0:
                FirstStageWord = Return_Word(5);
                cout << "1 ЭТАП 1 СТАДИЯ. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированное слово: " << FirstStageWord << endl;
                Sleep(TimeMemory[HardLevel][0]);
                system("cls");
                cout << "1 ЭТАП 1 СТАДИЯ. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Ваше слово: ";
                getline(cin, InputData);
                if (Reverse(InputData) == FirstStageWord){ 
                    cout << "ОТВЕТ ВЕРНЫЙ!" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                    cout << "Начальное слово: " << FirstStageWord + "/n" << endl;
                    for (int i = 0;i < 32; Processed_Words[i++] = "");
                    CorrectInputs = 0;

                    cout << "\nВведите уровень сложности:\n";
                    cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                    cout << "2) Простой.\n";
                    cout << "3) Средний.\n";
                    cout << "4) Сложный.\n";
                    cout << "5) Эксперт.\n";
                    cin >> HardLevel;
                    system("cls");
                }
                        
                break;

            // пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ 6 пїЅпїЅпїЅпїЅ
            case 1:
                FirstStageWord = Return_Word(6);
                cout << "1 ЭТАП 2 СТАДИЯ. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированное слово: " << FirstStageWord << endl;
                Sleep(TimeMemory[HardLevel][0]);
                system("cls");
                cout << "1 ЭТАП 2 СТАДИЯ. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Ваше слово: ";
                getline(cin, InputData);
                if (Reverse(InputData) == FirstStageWord){ 
                    cout << "ОТВЕТ ВЕРНЫЙ!" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                    cout << "Начальное слово: " << FirstStageWord + "/n" << endl;
                    for (int i = 0;i < 32; Processed_Words[i++] = "");
                    CorrectInputs = 0;

                    cout << "\nВведите уровень сложности:\n";
                    cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                    cout << "2) Простой.\n";
                    cout << "3) Средний.\n";
                    cout << "4) Сложный.\n";
                    cout << "5) Эксперт.\n";
                    cin >> HardLevel;
                    system("cls");
                }
                        
                break;

            // пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ 7 пїЅпїЅпїЅпїЅ
            case 2:
                FirstStageWord = Return_Word(7);
                cout << "1 ЭТАП 3 СТАДИЯ. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированное слово: " << FirstStageWord << endl;
                Sleep(TimeMemory[HardLevel][0]);
                system("cls");
                cout << "1 ЭТАП 3 СТАДИЯ. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Ваше слово: ";
                getline(cin, InputData);
                if (Reverse(InputData) == FirstStageWord){ 
                    cout << "ОТВЕТ ВЕРНЫЙ!" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                    cout << "Начальное слово: " << FirstStageWord + "/n" << endl;
                    for (int i = 0;i < 32; Processed_Words[i++] = "");
                    CorrectInputs = 0;

                    cout << "\nВведите уровень сложности:\n";
                    cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                    cout << "2) Простой.\n";
                    cout << "3) Средний.\n";
                    cout << "4) Сложный.\n";
                    cout << "5) Эксперт.\n";
                    cin >> HardLevel;
                    system("cls");
                }
                        
                break;

            // пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ 8 пїЅпїЅпїЅпїЅ
            case 3:
                FirstStageWord = Return_Word(8);
                cout << "1 ЭТАП 4 СТАДИЯ. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированное слово: " << FirstStageWord << endl;
                Sleep(TimeMemory[HardLevel][0]);
                system("cls");
                cout << "1 ЭТАП 4 СТАДИЯ. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Ваше слово: ";
                getline(cin, InputData);
                if (Reverse(InputData) == FirstStageWord){ 
                    cout << "ОТВЕТ ВЕРНЫЙ!" << endl;
                    CorrectInputs ++;
                }
                else {
                    cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                    cout << "Начальное слово: " << FirstStageWord + "/n" << endl;
                    for (int i = 0;i < 32; Processed_Words[i++] = "");
                    CorrectInputs = 0;

                    cout << "\nВведите уровень сложности:\n";
                    cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                    cout << "2) Простой.\n";
                    cout << "3) Средний.\n";
                    cout << "4) Сложный.\n";
                    cout << "5) Эксперт.\n";
                    cin >> HardLevel;
                    system("cls");
                }
                    
                break;
                
            //  пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ
            case 4:
                for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);

                cout << "2 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированная последовательность: ";
                for (string word: SecondStageWords) cout << word << " ";
                Sleep(TimeMemory[HardLevel][1]);
                system("cls");
                cout << "2 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "\nВаша последовательность: ";
                getline(cin, InputData);
                UsersWordsList = Split(InputData);
                if (size(UsersWordsList) == TotalWordsCount){
                    if (InputCheckSecondStep(UsersWordsList, SecondStageWords)){
                        cout << "ОТВЕТ ВЕРНЫЙ!" << endl;
                        CorrectInputs++;
                    }
                    else {
                        cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                        cout << "Сгенерированная последовательность: ";
                        for (string word: SecondStageWords) cout << word << " ";
                        cout << endl;
                        for (int i = 0;i < 32; Processed_Words[i++] = "");
                        CorrectInputs = 0;

                        cout << "\nВведите уровень сложности:\n";
                        cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                        cout << "2) Простой.\n";
                        cout << "3) Средний.\n";
                        cout << "4) Сложный.\n";
                        cout << "5) Эксперт.\n";
                        cin >> HardLevel;
                        system("cls");
                    }
                }
                // Error
                else {
                    cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                    cout << "Сгенерированная последовательность: ";
                    for (string word: SecondStageWords) cout << word << " ";
                    cout << endl;
                    for (int i = 0;i < 32; Processed_Words[i++] = "");
                    CorrectInputs = 0;

                    cout << "\nВведите уровень сложности:\n";
                    cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                    cout << "2) Простой.\n";
                    cout << "3) Средний.\n";
                    cout << "4) Сложный.\n";
                    cout << "5) Эксперт.\n";
                    cin >> HardLevel;
                    system("cls");
                }
                
                break;
            
            //  пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ
            case 5:
                for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
                
                cout << "3 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированная последовательность: ";
                for (string word: SecondStageWords) cout << word << " ";
                Sleep(TimeMemory[HardLevel][1]);
                system("cls");
                cout << "3 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "\nВаша последовательность: ";
                getline(cin, InputData);
                UsersWordsList = Split(InputData);
                if (size(UsersWordsList) == TotalWordsCount){
                    if (InputCheckThirdStep(UsersWordsList, SecondStageWords)){
                        cout << "ОТВЕТ ВЕРНЫЙ!" << endl;
                        CorrectInputs++;
                    }
                    else {
                        cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                        cout << "Сгенерированная последовательность: ";
                        for (string word: SecondStageWords) cout << word << " ";
                        cout << endl;
                        for (int i = 0;i < 32; Processed_Words[i++] = "");
                        CorrectInputs = 0;

                        cout << "\nВведите уровень сложности:\n";
                        cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                        cout << "2) Простой.\n";
                        cout << "3) Средний.\n";
                        cout << "4) Сложный.\n";
                        cout << "5) Эксперт.\n";
                        cin >> HardLevel;
                        system("cls");
                    }
                }
                // Error
                else {
                    cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                    cout << "Сгенерированная последовательность: ";
                    for (string word: SecondStageWords) cout << word << " ";
                    cout << endl;
                    for (int i = 0;i < 32; Processed_Words[i++] = "");
                    CorrectInputs = 0;

                    cout << "\nВведите уровень сложности:\n";
                    cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                    cout << "2) Простой.\n";
                    cout << "3) Средний.\n";
                    cout << "4) Сложный.\n";
                    cout << "5) Эксперт.\n";
                    cin >> HardLevel;
                    system("cls");
                }
                
                break;

            //  пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ
            case 6:
                for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
                
                cout << "4 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированная последовательность: ";
                for (string word: SecondStageWords) cout << word << " ";
                Sleep(TimeMemory[HardLevel][1]);
                system("cls");
                cout << "4 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "\nВаша последовательность: ";
                getline(cin, InputData);
                UsersWordsList = Split(InputData);
                if (size(UsersWordsList) == TotalWordsCount){
                    if (InputCheckForthStep(UsersWordsList, SecondStageWords)){
                        cout << "ОТВЕТ ВЕРНЫЙ!" << endl;
                        CorrectInputs++;
                    }
                    else {
                        cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                        cout << "Сгенерированная последовательность: ";
                        for (string word: SecondStageWords) cout << word << " ";
                        cout << endl;
                        for (int i = 0;i < 32; Processed_Words[i++] = "");
                        CorrectInputs = 0;

                        cout << "\nВведите уровень сложности:\n";
                        cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                        cout << "2) Простой.\n";
                        cout << "3) Средний.\n";
                        cout << "4) Сложный.\n";
                        cout << "5) Эксперт.\n";
                        cin >> HardLevel;
                        system("cls");
                    }
                }
                // Error
                else {
                    cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                    cout << "Сгенерированная последовательность: ";
                    for (string word: SecondStageWords) cout << word << " ";
                    cout << endl;
                    for (int i = 0;i < 32; Processed_Words[i++] = "");
                    CorrectInputs = 0;

                    cout << "\nВведите уровень сложности:\n";
                    cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                    cout << "2) Простой.\n";
                    cout << "3) Средний.\n";
                    cout << "4) Сложный.\n";
                    cout << "5) Эксперт.\n";
                    cin >> HardLevel;
                    system("cls");
                }
                
                break;

            //  пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ
            case 7:
                for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
                
                cout << "5 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "Сгенерированная последовательность: ";
                for (string word: SecondStageWords) cout << word << " ";
                Sleep(TimeMemory[HardLevel][1]);
                system("cls");
                cout << "5 ЭТАП. Правильно введено: " << CorrectInputs % 3 << endl;
                cout << "\nВаша последовательность: ";
                getline(cin, InputData);
                UsersWordsList = Split(InputData);
                if (size(UsersWordsList) == TotalWordsCount){
                    if (InputCheckFifthStep(UsersWordsList, SecondStageWords)){
                        cout << "ОТВЕТ ВЕРНЫЙ!" << endl;
                        CorrectInputs++;
                    }
                    else {
                        cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                        cout << "Сгенерированная последовательность: ";
                        for (string word: SecondStageWords) cout << word << " ";
                        cout << endl;
                        for (int i = 0;i < 32; Processed_Words[i++] = "");
                        CorrectInputs = 0;

                        cout << "\nВведите уровень сложности:\n";
                        cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                        cout << "2) Простой.\n";
                        cout << "3) Средний.\n";
                        cout << "4) Сложный.\n";
                        cout << "5) Эксперт.\n";
                        cin >> HardLevel;
                        system("cls");
                    }
                }
                // Error
                else {
                    cout << "ВАМИ БЫЛА ДОПУЩЕНА ОШИБКА!" << endl;
                    cout << "Сгенерированная последовательность: ";
                    for (string word: SecondStageWords) cout << word << " ";
                    cout << endl;
                    for (int i = 0;i < 32; Processed_Words[i++] = "");
                    CorrectInputs = 0;

                    cout << "\nВведите уровень сложности:\n";
                    cout << "1) Самый легкий. Выделяется больше всего времени.\n";
                    cout << "2) Простой.\n";
                    cout << "3) Средний.\n";
                    cout << "4) Сложный.\n";
                    cout << "5) Эксперт.\n";
                    cin >> HardLevel;
                    system("cls");
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

