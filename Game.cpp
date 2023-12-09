#include <iostream>
#include <fstream>
#include <ctime>
#include <Windows.h>

using namespace std;

string Entered_Words[65];
int Num_Word{0};

int GetRandomNumber(int min,int max){
    srand(time(NULL));
    int num = min+rand()%(max-min+1);
    return num;
} 

string Return_Word(int);

int main(){
    int Letters_Amount;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    for (int n =1;n<=10;n++){
        cout<<" Введите количество букв в "<< (Num_Word+1) << " слове: ";
        cin>>Letters_Amount;
        cout<<"\n Ваше случайное слово: "<<Return_Word(Letters_Amount)<<endl;
    }
    cin>>Letters_Amount;
    return 0;
}

string Return_Word(int letter){
    string Word;
    fstream file;
    int Flag =false;
    if ((letter >8) or (letter<5)){
        Flag=true;
        cout<<"\n некорректное значение";
    }
    while(!Flag){

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
                Flag = true;
                for (int lineno = 1; (lineno <= Word_Index) && getline(file,Word); lineno++);
                for(int i = 0; i<=Num_Word; i++){ 
                    if (Entered_Words[i] == Word){
                        Flag=false;
                    }
                }

        }
        else{    
            cout<<"Error. Cannot open file"<<endl;
        }

        file.close();
    }

    Num_Word++;
    Entered_Words[Num_Word]=Word;
    return Word;
}
