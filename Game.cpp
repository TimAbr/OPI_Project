#include <iostream>
#include <fstream>
#include <ctime>
#include <Windows.h>

using namespace std;

const int TotalWordsCount = 5;
string Generated_Words[TotalWordsCount]{};
int Num_Word{0};

int GetRandomNumber(int min,int max){
    return min+rand()%(max-min+1);
} 

void Return_Word(int);

int main(){
    int Letters_Amount;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    for (int n=1;n<=TotalWordsCount;n++){
        Letters_Amount = GetRandomNumber(5,8);
        Return_Word(Letters_Amount);
    }

    for (auto word: Generated_Words) cout << word;
    cout << endl;

    return 0;
}

void Return_Word(int letter){
    string Word;
    fstream file;
    int Flag = false;
    do{

        int Word_Index = GetRandomNumber(1,100);

        switch (letter){
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

    Generated_Words[Num_Word]=Word;
    Num_Word++;
}
