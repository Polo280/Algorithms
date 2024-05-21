// 29/04/24
#include <iostream>
#include <string>
#include <unordered_map>

/**
 * @brief This function translates Roman numbers to integer
*/
int romanToInt(std::string s) {
    int accum = 0; 
    std::unordered_map <char, int> romanDict = {{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}};
    
    // Iterate backwards
    for(int i=s.length()-1; i>=0; i--){
        if(i != 0){
            if(romanDict.at(s[i]) > romanDict.at(s[i-1])){
                accum += (romanDict.at(s[i]) -  romanDict.at(s[i-1]));    
                i--;
            }else{
                accum += romanDict.at(s[i]);
            }
        }else{
            accum += romanDict.at(s[i]);
        }
    }
    return accum;
}

int main(void){
    std::string testCases[] = {"III", "LVIII", "MCMXCIV"};

    for(auto i: testCases){
        std::cout << "Case " << i << " result: " <<  romanToInt(i) << "\n";
    }
}