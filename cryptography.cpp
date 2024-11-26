#include <Windows.h>
#include <iostream>
#include <vector>
#include <conio.h>

    std::string encrypt(std::string input, int key) {
        std::vector<char> word(input.begin(), input.end());
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890";

    for (int i = 0; i < (int)input.length(); i++) {
        int shift = key;
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j + shift) % alphabet.length()];
                break;
            }
        }
    }

    std::string str(word.begin(), word.end());
    return str;
}

    std::string decrypt(std::string input, int key) {
        std::vector<char> word(input.begin(), input.end());
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890";

        for (int i = 0; i < (int)input.length(); i++) {
            int shift =  key;
            for (int j = 0; j < (int)alphabet.length(); j++) {
                if (word[i] == alphabet[j]) {
                    word[i] = alphabet[(j - shift + alphabet.length()) % alphabet.length()];
                    break;
                }
            }
        }

        std::string str(word.begin(), word.end());
        return str;
    }
int main() {

    int key = 10;
    std::string text = "";
    std::cin >> text;
    std::cout << text << std::endl;

    std::string url = encrypt("google.com", key);
    std::cout << url << std::endl;

    std::string textencrypt = encrypt(text, key);
    std::cout << textencrypt << std::endl;

    std::string textdecrypt = decrypt(textencrypt, key);
    std::cout << textdecrypt << std::endl;

    _getch(); // if program instantly closed
    return 0;
}