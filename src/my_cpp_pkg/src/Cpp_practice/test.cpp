#include <iostream>
#include <string>
#include <sstream> 

using namespace std;

class User {
private:
    int age;
    string name;
    User* next;

    friend class ListOfUsers;
public:
    User() : age(0), name(""), next(nullptr) {}
     ~User() {}
};

class ListOfUsers {
private:
    User* head;

public:
    ListOfUsers() : head(nullptr) {}

    void insert_front();
    void printList();
    ~ListOfUsers() {
         User* current = head;
        User* nextNode;
         while(current != nullptr){
             nextNode = current->next;
             delete current;
             current = nextNode;
        }
    }
};

void ListOfUsers::insert_front() {
    User* newUser = new User();

    cout << "Enter user name:";
    cin >> newUser->name;


    string input;
    while (true) {
        cout << "Enter userage: ";
        cin >> input;

         stringstream ss(input);
        if (ss >> newUser->age) {
            if (ss.eof()) {
                break; 
             }
        }

        cout << "Invalid input. Please enter an integer for age." << endl;
        cin.clear(); 
    }
  

    newUser->next = head;
    head = newUser;
}


void ListOfUsers::printList() {
    User* current = head;

    while (current != nullptr) {
        cout << "Name: " << current->name << ", age: " << current->age << endl;
        current = current->next;
    }
}

int main() {
    ListOfUsers MyList;

    MyList.insert_front();
    MyList.insert_front();

    cout << "\nUsers in the linked list:" << endl;
    MyList.printList();

    return 0;
}