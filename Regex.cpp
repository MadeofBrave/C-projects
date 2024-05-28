#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <regex>

int main() {

    printf("Alfabeyi giriniz S={");
    std::string alphabet;
    std::getline(std::cin, alphabet);

    printf("Düzenli ifadeyi giriniz: ");
    std::string regexStr;
    std::getline(std::cin, regexStr);

    std::regex alphabetRegex("\\{([a-zA-Z],?)+\\}");
    if (!std::regex_match(alphabet, alphabetRegex)) {
        std::cerr << "Hatalý alfabe formatý!" << std::endl;
        return 1;
    }

    try {
        std::regex regexPattern(regexStr);
    } catch (std::regex_error& e) {
        std::cerr << "Hatalý düzenli ifade: " << e.what() << std::endl;
        return 1;
    }

    int numWords;
    printf("L dilinin kaç kelimesini görmek istiyorsunuz? : ");
    scanf("%d", &numWords);

    std::vector<char> alphabetSet;
    for (char c : alphabet) {
        if (isalpha(c)) {
            alphabetSet.push_back(c);
        }
    }

    printf("Düzenli ifade S alfabesinden üretilebilir. Kelimeleriniz listeleniyor..\n");
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
        printf("Bu kelime L diline ait deðildir.\n");
    }

    return 0;
}
