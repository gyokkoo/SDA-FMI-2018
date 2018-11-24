/*
Реализирайте едносвързан списък, който има следните операции:

* add(X,pos) - добавя числото X на позиция pos в писъка, като ако няма възможност да се добави на такава позиция
добавя елемента в края на списъка и извежда след това съобщение на стандартният изход add_last.

* remove(pos) - премахва елемента, който е на позиция pos, ако няма възможност да се премахне на такава позиция
не се премахва елемент, а на стандартният изход се извежда текста remove_failed

* print() - изкарва на стандартният изход числата от списъка, като след всяко число се принтира символа #.
При празен списък не се изкарва нищо на стандартният изход.

* reverse() - обръща списъка на обратно, т.е. последният елемент става вече първи,предпоследният втори и т.н.

* is _palindrom() - проверява дали списъка е палиндром(поредица,която се чете еднакво отпред назад и отзад напред),
като ако е палиндром принтира на стандартният изход true, а ако не е false

* count(X) - преброява, колко пъти се среща числото Х в списъка и извежда резултата на стандартният изход

* remove_all(X)-премахва всички срещания на числото Х в списъка

* group(startPos,endPos)-сумира елементите между подадените две позиции(включително позициите) и ги замества в масива със сумата им.

(Пример: при масив 1,2,3,4,5,6,7,8,9 и group(2,4) получаваме списък 1,2,12,6,7,8,9) Ако позициите не са валидни операцията не се изпълнява,
 а на стандартният изход се принтира fail_grouping
*/

#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    int size = 0;

    LinkedList() {
        this->head = nullptr;
        this->size = 0;
    }

    void add(int val, int pos) {
        Node* newNode = new Node(val);
        this->size++;
        if (pos < 0 || pos >= this->size) {
            std::cout << "add_last";
            Node* currentHead = this->head;
            if (currentHead == nullptr) {
                this->head = newNode;
            } else {
                while (currentHead->next) {
                    currentHead = currentHead->next;
                }
                currentHead->next = newNode;
            }
        } else if (pos == 0) {
            newNode->next = this->head;
            this->head = newNode;
        } else if (head == nullptr) {
            this->head = newNode;
        } else {
            Node* current = this->head;
            for (int i = 1; i < pos; i++) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void print() {
        Node* current = this->head;
        while (current != nullptr) {
            std::cout << current->data << "#";
            current = current->next;
        }
    }

    void remove(int pos) {
        if (pos < 0 || pos >= this->size) {
            std::cout << "remove_failed";
            return;
        }

        if (pos == 0) {
            Node* nodeToDelete = this->head;
            this->head = this->head->next;
            delete nodeToDelete;
        } else {
            Node* current = this->head;
            for (int i = 1; i < pos; i++) {
                current = current->next;
            }
            Node* nodeToDelete = current->next;
            delete nodeToDelete;

            current->next = nodeToDelete->next;
        }

        this->size--;
    }

    void reverse() {
        Node* current = this->head;
        Node* prev = nullptr;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }

        this->head = prev;
    }

    void remove_all(int val) {
        while (this->head && this->head->data == val) {
            Node* node = this->head;
            this->head = this->head->next;
            delete node;
            this->size--;
        }

        if (this->head == 0) {
            return;
        }

        Node* current = this->head;
        while (current->next) {
            if (current->next->data == val) {
                Node* nodeToDelete = current->next;
                current->next = nodeToDelete->next;
                delete nodeToDelete;
                this->size--;
            } else {
                current = current->next;
            }
        }
    }

    void group(int a, int b) {
        if (a < 0 || a >= this->size ||
            b < 0 || b >= this->size || a > b) {
            std::cout << "fail_grouping";
            return;
        }

        Node* current = this->head;
        for (int i = 1; i <= a; i++) {
            current = current->next;
        }

        int sum = 0;
        for (int i = a; i <= b; i++) {
            sum += current->data;
            remove(a);
            current = current->next;
        }

        add(sum, a);
    }

    void count(int val) {
        int counter = 0;
        Node* current = this->head;
        while (current != nullptr) {
            if (current->data == val) {
                counter++;
            }
            current = current->next;
        }

        std::cout << counter;
    }

    void is_palindrome() {
        Node* current = this->head;
        std::stack<int> stack;
        while (current) {
            stack.push(current->data);
            current = current->next;
        }

        current = this->head;
        while (current) {
            if (current->data != stack.top()) {
                std::cout << "false";
                return;
            }

            stack.pop();
            current = current->next;
        }

        if (stack.empty()) {
            std::cout << "true";
        } else {
            std::cout << "false";
        }
    }

    ~LinkedList() {
        while (this->head) {
            Node* nodeToDelete = this->head;
            delete nodeToDelete;
            this->head = this->head->next;
        }
    }
};

int main() {
    int cases;
    std::cin >> cases;
    for (int i = 0; i < cases; i++) {
        LinkedList ll;
        int ops;
        std::string op;
        std::cin >> ops;
        for (int j = 0; j < ops; j++) {
            std::cin >> op;

            if (op == "count") {
                int arg1;
                std::cin >> arg1;
                ll.count(arg1);
            }

            if (op == "add") {
                int arg1, arg2;
                std::cin >> arg1 >> arg2;
                ll.add(arg1, arg2);
            }

            if (op == "print") {
                ll.print();
            }

            if (op == "remove") {
                int arg1;
                std::cin >> arg1;
                ll.remove(arg1);
            }

            if (op == "reverse") {
                ll.reverse();
            }

            if (op == "remove_all") {
                int arg1;
                std::cin >> arg1;
                ll.remove_all(arg1);
            }

            if (op == "group") {
                int arg1, arg2;
                std::cin >> arg1 >> arg2;
                ll.group(arg1, arg2);
            }

            if (op == "is_palindrom") {
                ll.is_palindrome();
            }
        }

        std::cout << std::endl;

    }
    return 0;
}