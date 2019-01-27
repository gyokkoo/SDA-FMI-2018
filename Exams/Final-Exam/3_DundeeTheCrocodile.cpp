/*
Дадени са ви две изречения A и B.
Думите в изреченията са само с малки букви и всяка дума е разделена с точно един знак за празен символ.
Освен малки букви и празно място между тях, други символи няма да същестуват като вход.
Една дума ще наричаме 'Крокодил от Австралия' ако се среща точно един път в едно от изреченията
и не се среща в другото изречение.

От вас се иска да изведете по дума на нов ред всички такива думи които са 'Крокодил от Австралия'.
Тъй като може да има много възможни наредби за изход, то първо сортирайте всички тези думи спрямо тяхната
лексикографка наредба и след това ги отпечатайте, всяка на нов ред.

Пример:
a b c
b a d

Двете думи които отговарят на условието са: d,c

Примерен Изход:

c
d

Пояснение:
d
c

Не е коректен отговор, защото трябва да изведете всяка дума на нов ред като започнем от лексикографски най-малката.

Input Format
Две изречения, всяко на нов ред

Constraints
Дължината на A и B не е по-голяма от 500 символа.

Output Format
Всички думи които отговарят на условието, като на всеки ред трябва да имате по една дума.

Sample Input 0
hello world
world bye

Sample Output 0
bye
hello

Sample Input 1
ha ha ha ha
not

Sample Output 1
not
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int getOccurrences(const std::vector<std::string>& words, const std::string& searchTarget) {
    int occurrences = 0;
    for (const auto &word : words) {
        if (word == searchTarget) {
            occurrences++;
        }
    }

    return occurrences;
}

std::vector<std::string> splitBySpace(const std::string& str) {
    const char splitSymbol = ' ';
    std::vector<std::string> result;

    std::string wordBuilder;

    for (int i = 0; i < str.length(); i++) {
        if (i == str.length() - 1 && str[i] != ' ') {
            wordBuilder += str[i];
            result.push_back(wordBuilder);
            wordBuilder = "";
        } else if (str[i] != splitSymbol) {
            wordBuilder += str[i];
        } else if (str[i] == splitSymbol) {
            result.push_back(wordBuilder);
            wordBuilder = "";
        }
    }

    return result;
}

int main() {
    std::string firstInput;
    std::string secondInput;

    std::getline(std::cin, firstInput);
    std::getline(std::cin, secondInput);

    std::vector<std::string> firstWords = splitBySpace(firstInput);
    std::vector<std::string> secondWords = splitBySpace(secondInput);

    std::vector<std::string> result;
    for (const auto &word : firstWords) {
        int firstOccurrences = getOccurrences(firstWords, word);
        int secondOccurrences = getOccurrences(secondWords, word);
        if (firstOccurrences == 1 && secondOccurrences == 0) {
            result.push_back(word);
        }
    }

    for (const auto &word : secondWords) {
        int secondOccurrences = getOccurrences(secondWords, word);
        int doNotOccur = getOccurrences(firstWords, word);
        if (secondOccurrences == 1 && doNotOccur == 0) {
            result.push_back(word);
        }
    }

    std::sort(result.begin(), result.end());

    for (const auto &word : result) {
        std::cout << word << "\n";
    }

    return 0;
}