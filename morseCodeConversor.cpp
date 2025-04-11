#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

int main(){
std::unordered_map<char, std::string> morseMap = {
  {'A', ".-"},
  {'B', "-..."},
  {'C', "-.-."},
  {'D', "-.."},
  {'E', "."},
  {'F', "..-."},
  {'G', "--."},
  {'H', "...."},
  {'I', ".."},
  {'J', ".---"},
  {'K', "-.-"},
  {'L', ".-.."},
  {'M', "--"},
  {'N', "-."},
  {'O', "---"},
  {'P', ".--."},
  {'Q', "--.-"},
  {'R', ".-."},
  {'S', "..."},
  {'T', "-"},
  {'U', "..-"},
  {'V', "...-"},
  {'W', ".--"},
  {'X', "-..-"},
  {'Y', "-.--"},
  {'Z', "--.."},
  {'1', ".----"},
  {'2', "..---"},
  {'3', "...--"},
  {'4', "....-"},
  {'5', "....."},
  {'6', "-...."},
  {'7', "--..."},
  {'8', "---.."},
  {'9', "----."},
  {'0', "-----"}
};
  std::string word;
  std::cout << "Write a word: ";
  std::getline(std::cin, word);

  for(int i = 0; i < word.length(); ++i){
    char c = word[i];
    c = toupper(c);
    if (morseMap.count(c)) {
      std::cout << morseMap[c] << " ";
    } else if (c == ' '){
      std::cout << "/ ";
    }
  }
  std::cout << std::endl;
  return 0;
}
