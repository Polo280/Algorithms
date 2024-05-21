// 29/04/24
#include <iostream>
#include <string>

/**
 * @brief This function detects if a number is a palindrome 
*/
bool isPalindrome(int x){
    std::string straux = std::to_string(x);
    uint8_t len = straux.length() - 1;
    for(uint8_t i = len; i > 0; i--){
        if(straux[i] != straux[len - i])
            return false;
    }
    return true;
}

int main(void){
    int testCases[] = {121, 3483, 123454321};

    for(auto i: testCases){
        std::cout << "The number " << i << " is a palindrome: " << isPalindrome(i) << "\n";
    }
}