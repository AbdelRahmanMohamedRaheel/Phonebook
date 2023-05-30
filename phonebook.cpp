#include <iostream>
#include <string>
using namespace std;

struct Contact {      
    string name;
    string phone;
    string email;
};

struct Node {           
    Contact data;
    Node* next;
};

class Stack {                    
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void push(Contact contact) {
        Node* newNode = new Node;
        newNode->data = contact;
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        }
        else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    Contact topElement() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return Contact();
        }
        else {
            return top->data;
        }
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(Contact contact) {
        Node* newNode = new Node;
        newNode->data = contact;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        }
        else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    Contact frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return Contact();
        }
        else {
            return front->data;
        }
    }
    bool isEmpty() {
        return front == nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    void add(Contact contact) {
        Node* newNode = new Node;
        newNode->data = contact;               // awl node data:contact(name,phone,email)   
        newNode->next = nullptr;               // next bta3etha null pointer
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;                         //head tey4awer 3la el temp
            while (temp->next != nullptr) {
                temp = temp->next;                 //temp by3ml shift lwa7da
            } 
            temp->next = newNode;                       //temp hay4awr 3la node el gdeda
        }
    }
    void remove(string name) {              // such masalan abdelrahman
        Node* curr = head;
        Node* prev = nullptr;
        while (curr != nullptr && curr->data.name != name) {      //tol ma e7na mal2ena4 abdelrahman haybos 3la eli b3dha
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {                                
            cout << "Contact not found!" << endl;
        }
        else {
            if (prev == nullptr) {
                head = curr->next;           // head hay4awer 3la eli b3d el curr
            }
            else {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Contact removed!" << endl;
        }
    }
    Contact* search(string name) {               //return pointer    // mslan abdelrahman
        Node* curr = head;
        while (curr != nullptr && curr->data.name != name) {      
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Contact not found!" << endl;
            return nullptr;
        }
        else {
            return &(curr->data);              // hay3ml return address of object
        }
    }
    void showContacts() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "No contacts found!" << endl;
        }
        else {
            cout << "Contacts:" << endl;
            while (temp != nullptr) {
                cout << "Name: " << temp->data.name << endl;
                cout << "Phone: " << temp->data.phone << endl;
                cout << "Email: " << temp->data.email << endl;
                cout << "------------------------" << endl;
                temp = temp->next;
            }
        }
    }
};

class PhoneBook {
private:
    LinkedList contacts;
    Stack undoStack;
    Queue redoQueue;
public:
    void addContact(Contact contact) {
        contacts.add(contact);
        undoStack.push(contact);
        cout << "Contact added!" << endl;
    }
    void removeContact(string name) {
        Contact* contact = contacts.search(name);
        if (contact != nullptr) {
            undoStack.push(*contact);
            contacts.remove(name);
        }
    }
    void editContact(string name) {
        Contact* contact = contacts.search(name);
        if (contact != nullptr) {
            Contact updatedContact = *contact;
            cout << "Enter new phone: ";
            cin >> updatedContact.phone;
            cout << "Enter new email: ";
            cin >> updatedContact.email;
            undoStack.push(*contact);
            contacts.remove(name);
            contacts.add(updatedContact);
            cout << "Contact updated!" << endl;
        }
    }
    void undo() {
        if (!undoStack.isEmpty()) {
            Contact contact = undoStack.topElement();
            redoQueue.enqueue(contact);
            undoStack.pop();
            contacts.remove(contact.name);
            cout << "Undo operation performed!" << endl;
        }
        else {
            cout << "No more undo operations!" << endl;
        }
    }
    void redo() {
        if (!redoQueue.isEmpty()) {
            Contact contact = redoQueue.frontElement();
            undoStack.push(contact);
            redoQueue.dequeue();
            contacts.add(contact);
            cout << "Redo operation performed!" << endl;
        }
        else {
            cout << "No more redo operations!" << endl;
        }
    }
    void showAllContacts() {
        contacts.showContacts();
    }
};

int main() {
    PhoneBook phoneBook;

    {
        system("CLS");              //clear the console 
    cout << "\n\n\t\t\t============================================================";
    cout << "\n\n\t\t\t=================Welcome To Our Phone book =================";
    cout << "\n\n\t\t\t============================================================\n";

    for (int i = 0; i <= 4; i++)
    {
        system("COLOR 03");
        system("COLOR 04");
        system("COLOR 05");
        system("COLOR 06");
       
    }
    system("pause");      //Pause the program 
    system("cls");
    }
    while (true) {
        
            
        cout << "1. Add contact" << endl;
        cout << "2. Remove contact" << endl;
        cout << "3. Edit contact" << endl;
        cout << "4. Undo" << endl;
        cout << "5. Redo" << endl;
        cout << "6. Show all contacts" << endl;
        cout << "7. Exit" << endl;
        system("pause");
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Contact contact;
            cout << "Enter name: ";
            cin >> contact.name;
            cout << "Enter phone: ";
            cin >> contact.phone;
            cout << "Enter email: ";
            cin >> contact.email;
            phoneBook.addContact(contact);

        }
        else if (choice == 2) {
            string name;
            cout << "Enter name: ";
            cin >> name;
            phoneBook.removeContact(name);

        }
        else if (choice == 3) {
            string name;
            cout << "Enter name: ";
            cin >> name;
            phoneBook.editContact(name);

        }
        else if (choice == 4) {
            phoneBook.undo();

        }
        else if (choice == 5) {
            phoneBook.redo();

        }
        else if (choice == 6) {
            phoneBook.showAllContacts();

        }
        else if (choice == 7) {
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }

        cout << "--------------------------" << endl;
    }

    return 0;
}
