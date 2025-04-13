#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

bool isRunning = true;

std::unordered_map<char, std::string> morseMap = {
  {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},  {'E', "."},
  {'F', "..-."}, {'G', "--."},  {'H', "...."}, {'I', ".."},   {'J', ".---"},
  {'K', "-.-"},  {'L', ".-.."}, {'M', "--"},   {'N', "-."},   {'O', "---"},
  {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
  {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"}, {'Y', "-.--"},
  {'Z', "--.."}, {'1', ".----"},{'2', "..---"},{'3', "...--"},{'4', "....-"},
  {'5', "....."},{'6', "-...."},{'7', "--..."},{'8', "---.."},{'9', "----."},
  {'0', "-----"}
};

std::unordered_map<std::string, char> wordMap = {
  {".-", 'A'},   {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},  {".", 'E'},
  {"..-.", 'F'}, {"--.", 'G'},  {"....", 'H'}, {"..", 'I'},   {".---", 'J'},
  {"-.-", 'K'},  {".-..", 'L'}, {"--", 'M'},   {"-.", 'N'},   {"---", 'O'},
  {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'},  {"...", 'S'},  {"-", 'T'},
  {"..-", 'U'},  {"...-", 'V'}, {".--", 'W'},  {"-..-", 'X'}, {"-.--", 'Y'},
  {"--..", 'Z'}, {".----", '1'},{"..---", '2'},{"...--", '3'},{"....-", '4'},
  {".....", '5'},{"-....", '6'},{"--...", '7'},{"---..", '8'},{"----.", '9'},
  {"-----", '0'}
};

void morseToWord() {
  std::string word;
  std::cin.ignore();
  std::cout << "Write a word: ";
  std::getline(std::cin, word);

  for (int i = 0; i < word.length(); ++i) {
    char c = word[i];
    c = std::toupper(c);
    if (morseMap.count(c)) {
      std::cout << morseMap[c] << " ";
    } else if (c == ' ') {
      std::cout << "/ ";
    }
  }
  std::cout << std::endl;
}

void wordToMorse() {
  std::string morseInput;
  std::cin.ignore();
  std::cout << "Write Morse code (use space between letters, / between words): ";
  std::getline(std::cin, morseInput);

  std::istringstream iss(morseInput);
  std::string token;
  while (iss >> token) {
    if (token == "/") {
      std::cout << " ";
    } else if (wordMap.count(token)) {
      std::cout << wordMap[token];
    } else {
      std::cout << "?";
    }
  }
  std::cout << std::endl;
}

void interface() {
  int res;
  std::cout << "Welcome to the conversor of morse code\n";
  std::cout << "Do you want to convert word to morse code (1) or the opposite (2): ";
  std::cin >> res;
  switch (res) {
    case 1:
      morseToWord();
      break;
    case 2:
      wordToMorse();
      break;
    default:
      std::cout << "Invalid option.\n";
  }
}

void playAgain() {
    char res;
    while (true) {
        std::cout << "Do you want to convert again? (Y/N): ";
        std::cin >> res;
        res = std::toupper(res);

        if (res == 'Y') {
            isRunning = true;
            std::cin.ignore(1000, '\n');
            break;
        } else if (res == 'N') {
            isRunning = false;
            break;
        } else {
            std::cout << "Invalid answer.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }
}

int main() {
  while (isRunning) {
    interface();
    playAgain();
    std::cout << "Bye, see you again later\n";
  }
  return 0;
}
