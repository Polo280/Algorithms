// 16/05/26
#include <iostream>
#include <string>
#include <math.h>

/**
 * @brief This function converts integer to Roman
*/
std::string IntToRoman(int num) {
    std::string romanNum = "";
    char letters[4][3] = {{'I', 'V', 'X'}, {'X', 'L', 'C'}, {'C', 'D', 'M'}, {'M', '\0', '\0'}};
    for(int i=3; i>=0; i--){
        int aux = (num / (int)pow(10, i)) % 10;  // Get a digit in each iter
        if(aux == 4){
            romanNum += letters[i][0];
            romanNum += letters[i][1];}
        else if(aux == 9){
            romanNum += + letters[i][0];
            romanNum += letters[i][2];}
        else{
            char auxchar = (aux >= 5)? letters[i][1] : '\0';
            if(auxchar != '\0') 
                romanNum += auxchar;
            for(int j=0; j<aux % 5; j++){
                romanNum += letters[i][0];
            }
        }
    }  
    return romanNum;
}

int main(void){
    int testCases[] = {3749, 58, 1994};  // "LVIII", "MCMXCIV"

    for(auto i: testCases){
        std::cout << "Case " << i << " result: " <<  IntToRoman(i) << "\n";
    }
}