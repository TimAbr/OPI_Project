#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

const int TotalWordsCount = 5;
const int TotalGenWords = 32;

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

void CleanArr(string[]);
void UpperCase(string&);

int main(){
    int CorrectInputs{0};
    int TimeMemory[5][2] {{7000, 15000}, {5000, 10000}, {3000, 7000}, {1500, 5000}, {1000, 3000}};
    int HardLevel{2};
    int FirstStageStep {0};
    string LoadLine{"--------------------"};
    string FirstStageWord{};
    string SecondStageWords[TotalWordsCount]{};
    string InputData{};// Users input 
    vector<string> UsersWordsList{}; 

    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    while (CorrectInputs < 24){   
        CleanArr(Processed_Words);
        CorrectInputs = 0;
        cout << "Ââåäèòå óðîâåíü ñëîæíîñòè:\n";
        cout << "1) Ñàìûé ëåãêèé. Âûäåëÿåòñÿ áîëüøå âñåãî âðåìåíè.\n";
        cout << "2) Ïðîñòîé.\n";
        cout << "3) Ñðåäíèé.\n";
        cout << "4) Ñëîæíûé.\n";
        cout << "5) Ýêñïåðò.\n";
        getline(cin, InputData);
        HardLevel = stoi(InputData) - 1;
        system("cls");

        // ÏÅÐÂÛÉ ÝÒÀÏ
        while (CorrectInputs < 12){
            FirstStageWord = Return_Word(5 + CorrectInputs / 3);
            cout << "1 ÝÒÀÏ "<< CorrectInputs / 3 + 1 << " ÑÒÀÄÈß. Ïðàâèëüíî ââåäåíî: " 
                << CorrectInputs % 3 << endl;
            cout << "Ñãåíåðèðîâàííîå ñëîâî: " << FirstStageWord << endl;
            Sleep(TimeMemory[HardLevel][0]);
            system("cls");
            cout << "1 ÝÒÀÏ "<< CorrectInputs / 3 + 1 << " ÑÒÀÄÈß. Ïðàâèëüíî ââåäåíî: " 
                << CorrectInputs % 3 << endl;
            cout << "Âàøå ñëîâî: ";
            getline(cin,InputData);
            if (Reverse(InputData) == FirstStageWord){ 
                // Ñîîáùåíèå î êîððåêòíîì ââîäå
                for (int i = 19; i >= 0; i --){
                    system("cls");
                    cout << "1 ÝÒÀÏ "<< CorrectInputs / 3 + 1 << " ÑÒÀÄÈß. Ïðàâèëüíî ââåäåíî: " 
                        << CorrectInputs % 3 << endl;
                    cout << "Âàøå ñëîâî: " << InputData << endl;
                    cout << "ÎÒÂÅÒ ÂÅÐÍÛÉ!" << endl;
                    cout << LoadLine.substr(0,i);
                    Sleep(300);
                }
                system("cls");

                CorrectInputs++;
            }
            else {
                cout << "ÂÀÌÈ ÁÛËÀ ÄÎÏÓÙÅÍÀ ÎØÈÁÊÀ!" << endl;
                cout << "Íà÷àëüíîå ñëîâî: " << FirstStageWord + "\n" << endl;
            }
        }

        // ÂÒÎÐÎÉ ÝÒÀÏ
        while (12 <= CorrectInputs && CorrectInputs < 15){
            
            for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);

            cout << "2 ÝÒÀÏ. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
            cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
            for (string word: SecondStageWords) cout << word << " ";
            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            cout << "2 ÝÒÀÏ. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
            cout << "\nÂàøà ïîñëåäîâàòåëüíîñòü: ";
            getline(cin, InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){
                if (InputCheckSecondStep(UsersWordsList, SecondStageWords)){
                    // Ñîîáùåíèå î êîððåêòíîì ââîäå
                    for (int i = 19; i >= 0; i --){
                        system("cls");
                        cout << "1 ÝÒÀÏ 1 ÑÒÀÄÈß. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
                        cout << "Âàøå ñëîâî: " << InputData << endl;
                        cout << "ÎÒÂÅÒ ÂÅÐÍÛÉ!" << endl;
                        cout << LoadLine.substr(0,i);
                        Sleep(300);
                    }
                    system("cls");

                    CorrectInputs++;
                }
                else {
                    cout << "ÂÀÌÈ ÁÛËÀ ÄÎÏÓÙÅÍÀ ÎØÈÁÊÀ!" << endl;
                    cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
                    for (string word: SecondStageWords) cout << word << " ";
                    cout << endl;
                }
            }
            // Error
            else {
                cout << "ÂÀÌÈ ÁÛËÀ ÄÎÏÓÙÅÍÀ ÎØÈÁÊÀ!" << endl;
                cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
                for (string word: SecondStageWords) cout << word << " ";
                cout << endl;
            }
        }

        // ÒÐÅÒÈÉ ÝÒÀÏ
        while (15 <= CorrectInputs && CorrectInputs < 18){
            for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
            
            cout << "3 ÝÒÀÏ. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
            cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
            for (string word: SecondStageWords) cout << word << " ";
            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            cout << "3 ÝÒÀÏ. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
            cout << "\nÂàøà ïîñëåäîâàòåëüíîñòü: ";
            getline(cin, InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){
                if (InputCheckThirdStep(UsersWordsList, SecondStageWords)){
                    // Ñîîáùåíèå î êîððåêòíîì ââîäå
                    for (int i = 19; i >= 0; i --){
                        system("cls");
                        cout << "3 ÝÒÀÏ. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
                        cout << "Âàøå ñëîâî: " << InputData << endl;
                        cout << "ÎÒÂÅÒ ÂÅÐÍÛÉ!" << endl;
                        cout << LoadLine.substr(0,i);
                        Sleep(300);
                    }
                    system("cls");

                    CorrectInputs++;
                }
                else {
                    cout << "ÂÀÌÈ ÁÛËÀ ÄÎÏÓÙÅÍÀ ÎØÈÁÊÀ!" << endl;
                    cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
                    for (string word: SecondStageWords) cout << word << " ";
                    cout << endl;
                }
            }
            // Error
            else {
                cout << "ÂÀÌÈ ÁÛËÀ ÄÎÏÓÙÅÍÀ ÎØÈÁÊÀ!" << endl;
                cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
                for (string word: SecondStageWords) cout << word << " ";
                cout << endl;
            }           
        }

        // ×ÅÒÂÅÐÒÛÉ ÝÒÀÏ
        while (18 <= CorrectInputs && CorrectInputs < 21){
            for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
            
            cout << "4 ÝÒÀÏ. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
            cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
            for (string word: SecondStageWords) cout << word << " ";
            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            cout << "4 ÝÒÀÏ. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
            cout << "\nÂàøà ïîñëåäîâàòåëüíîñòü: ";
            getline(cin, InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){
                if (InputCheckForthStep(UsersWordsList, SecondStageWords)){
                    // Ñîîáùåíèå î êîððåêòíîì ââîäå
                    for (int i = 19; i >= 0; i --){
                        system("cls");
                        cout << "1 ÝÒÀÏ 1 ÑÒÀÄÈß. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
                        cout << "Âàøå ñëîâî: " << InputData << endl;
                        cout << "ÎÒÂÅÒ ÂÅÐÍÛÉ!" << endl;
                        cout << LoadLine.substr(0,i);
                        Sleep(300);
                    }
                    system("cls");

                    CorrectInputs++;
                }
                else {
                    cout << "ÂÀÌÈ ÁÛËÀ ÄÎÏÓÙÅÍÀ ÎØÈÁÊÀ!" << endl;
                    cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
                    for (string word: SecondStageWords) cout << word << " ";
                    cout << endl;
                }
            }
            // Error
            else {
                cout << "ÂÀÌÈ ÁÛËÀ ÄÎÏÓÙÅÍÀ ÎØÈÁÊÀ!" << endl;
                cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
                for (string word: SecondStageWords) cout << word << " ";
                cout << endl;
            }
        }

        // ÏßÒÛÉ ÝÒÀÏ   
        while (21 <= CorrectInputs && CorrectInputs < 24){

            for (int i = 0;i < TotalWordsCount; SecondStageWords[i] = Return_Word(GetRandomNumber(5,8)), i++);
            
            cout << "5 ÝÒÀÏ. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
            cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
            for (string word: SecondStageWords) cout << word << " ";
            Sleep(TimeMemory[HardLevel][1]);
            system("cls");
            cout << "5 ÝÒÀÏ. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
            cout << "\nÂàøà ïîñëåäîâàòåëüíîñòü: ";
            getline(cin, InputData);
            UsersWordsList = Split(InputData);
            if (size(UsersWordsList) == TotalWordsCount){
                if (InputCheckFifthStep(UsersWordsList, SecondStageWords)){
                    // Ñîîáùåíèå î êîððåêòíîì ââîäå
                    for (int i = 19; i >= 0; i --){
                        system("cls");
                        cout << "1 ÝÒÀÏ 1 ÑÒÀÄÈß. Ïðàâèëüíî ââåäåíî: " << CorrectInputs % 3 << endl;
                        cout << "Âàøå ñëîâî: " << InputData << endl;
                        cout << "ÎÒÂÅÒ ÂÅÐÍÛÉ!" << endl;
                        cout << LoadLine.substr(0,i);
                        Sleep(300);
                    }
                    system("cls");

                    CorrectInputs ++;
                }
                else {
                    cout << "ÂÀÌÈ ÁÛËÀ ÄÎÏÓÙÅÍÀ ÎØÈÁÊÀ!" << endl;
                    cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
                    for (string word: SecondStageWords) cout << word << " ";
                    cout << endl;
                }
            }
            // Error
            else {
                cout << "ÂÀÌÈ ÁÛËÀ ÄÎÏÓÙÅÍÀ ÎØÈÁÊÀ!" << endl;
                cout << "Ñãåíåðèðîâàííàÿ ïîñëåäîâàòåëüíîñòü: ";
                for (string word: SecondStageWords) cout << word << " ";
                cout << endl;
            }
        }
    }

    cout << "ÈÃÐÀ ÎÊÎÍ×ÅÍÀ.";
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

void CleanArr(string Arr[]){
    for (int i = 0;i < TotalGenWords; Arr[i++] = "");
}
