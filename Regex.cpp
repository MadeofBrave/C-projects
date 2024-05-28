#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <regex>

int main() {

    printf("Alfabeyi giriniz S={");
    std::string alphabet;
    std::getline(std::cin, alphabet);

    printf("D�zenli ifadeyi giriniz: ");
    std::string regexStr;
    std::getline(std::cin, regexStr);

    std::regex alphabetRegex("\\{([a-zA-Z],?)+\\}");
    if (!std::regex_match(alphabet, alphabetRegex)) {
        std::cerr << "Hatal� alfabe format�!" << std::endl;
        return 1;
    }

    try {
        std::regex regexPattern(regexStr);
    } catch (std::regex_error& e) {
        std::cerr << "Hatal� d�zenli ifade: " << e.what() << std::endl;
        return 1;
    }

    int numWords;
    printf("L dilinin ka� kelimesini g�rmek istiyorsunuz? : ");
    scanf("%d", &numWords);

    std::vector<char> alphabetSet;
    for (char c : alphabet) {
        if (isalpha(c)) {
            alphabetSet.push_back(c);
        }
    }

    printf("D�zenli ifade S alfabesinden �retilebilir. Kelimeleriniz listeleniyor..\n");
    for (int i = 0; i < numWords; ++i) {
        std::string word;
        for (int j = 0; j < 5; ++j) {
            word += alphabetSet[rand() % alphabetSet.size()];
        }
        printf("L={%s}\n", word.c_str());
    }

    
    printf("BONUS: Kontrol edilecek kelimeyi giriniz: ");
    std::string testWord;
    std::cin >> testWord;

    std::regex matchRegex(regexStr);
    if (std::regex_match(testWord, matchRegex)) {
        printf("Bu kelime L diline aittir.\n");
    } else {
        printf("Bu kelime L diline ait de�ildir.\n");
    }

    return 0;
}
