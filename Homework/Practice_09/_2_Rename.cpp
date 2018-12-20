#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Node {
    Node* letters[26];
};

Node* getNewEmptyNode() {
    Node* current =  new Node;
    for (int i = 0; i < 26; i++) {
        current->letters[i] = nullptr;
    }

    return current;
}

bool search(Node *root, std::string key) {
    Node* current = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!current->letters[index]) {
            return false;
        }

        current = current->letters[index];
    }

    return (current != nullptr);
}

void insert(Node* root, std::string key) {
    Node* current = root;

    std::string currentSubstring;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!current->letters[index]) {
            current->letters[index] = getNewEmptyNode();
        }

        current = current->letters[index];

        currentSubstring += key[i];
    }
}

int main() {
    int numberOfStrings = 0;

    std::cin >> numberOfStrings;
    std::cin.ignore();

    std::map<std::string, int> nameOccurrences;

    Node* trieRoot = getNewEmptyNode();
    for (int i = 0; i < numberOfStrings; i++) {
        std::string inputName;
        std::getline(std::cin, inputName);

        if(nameOccurrences.find(inputName) != nameOccurrences.end()) {
            std::cout << inputName << " " << ++nameOccurrences[inputName] << "\n";
            continue;
        } else {
            nameOccurrences.insert(std::pair<std::string, int>(inputName, 1));
        }

        std::string subName;

        bool doesExist = false;
        for (int j = 0; j < inputName.length(); j++) {
            subName += inputName[j];
            if (!search(trieRoot, subName)) {
                std::cout << subName << "\n";
                doesExist = true;
                break;
            }
        }

        if (!doesExist) {
            std::cout << subName << "\n";
        }

        insert(trieRoot, inputName);
    }

    return 0;
}