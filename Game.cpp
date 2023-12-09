#include <iostream>
#include <string>
using namespace std;

bool InputCheckFirstStep(string UsersWord, string CorrectWord){

    int StartCheck{UsersWord.find_first_not_of(' ')}, EndCheck{UsersWord.find_last_not_of(' ')};
    
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

int main(){
    
    return 0;
}