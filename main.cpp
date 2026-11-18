#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Contact {
public:
    string name;
    string phone;
    int age;

    Contact(string n, string p, int a) {
        name = n;
        phone = p;
        age = a;
    }
};

void listContacts(const vector<Contact>& contacts) {
    for (const Contact& contact : contacts) {
        cout << "==========\n";
        cout << "Name: " << contact.name << endl;
        cout << "Phone: " << contact.phone << endl;
        cout << "Age: " << contact.age << endl;
    }
}

void addContact(vector<Contact>& contacts) {
    // if (contacts.size() < 5) {
        string name;
        string phone;
        int age;

        cout << "Please specify user's name: ";
        cin >> name;

        cout << "Please specify user's phone number: ";
        cin >> phone;

        while (true) {
            cout << "Please specify user's age: ";

            if (!(cin >> age)) {
                cout << "Please enter the age as a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (age >= 18 && age <= 120) {
                break;
            }
            else {
                cout << "Please enter an age between 18 and 120.\n";
            }
        }

        contacts.emplace_back(name, phone, age);
    // }
    // else {
    //     cout << "We are sorry, the contact list is full.\n";
    // }
}

void searchContact(const vector<Contact>& contacts) {
    string search;

    cout << "Welcome to our simple filter. Search by name.\n";
    cout << "Please enter the contact's name: ";
    cin >> search;

    for (const Contact& contact : contacts) {
        if (contact.name == search) {
            cout << "==========\n";
            cout << "Name: " << contact.name << endl;
            cout << "Phone: " << contact.phone << endl;
            cout << "Age: " << contact.age << endl;
            return;
        }
    }

    cout << "No contact found with the name " << search << endl;
}

void deleteContact(vector<Contact>& contacts) {
    string search;

    cout << "Please enter the name of the contact you want to delete: ";
    cin >> search;

    for (size_t i = 0; i < contacts.size(); i++) {
        if (contacts[i].name == search) {
            contacts.erase(contacts.begin() + i);
            cout << "Contact deleted.\n";
            return;
        }
    }

    cout << "No contact found with the name " << search << endl;
}

int main() {
    vector<Contact> contacts = {
        Contact("Alice", "041395655", 23),
        Contact("Khatchig", "091234567", 24),
        Contact("David", "077654321", 31),
        Contact("Anna", "055123456", 28)
    };

    int choice;

    do {
        cout << "\n===== CONTACT MANAGEMENT =====\n";
        cout << "1. List contacts\n";
        cout << "2. Add contact\n";
        cout << "3. Search contact\n";
        cout << "4. Delete contact\n";
        cout << "5. Exit\n";
        cout << "\nChoose an option: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                listContacts(contacts);
                break;

            case 2:
                addContact(contacts);
                break;

            case 3:
                searchContact(contacts);
                break;

            case 4:
                deleteContact(contacts);
                break;

            case 5:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid option. Please choose again.\n";
        }

    } while (choice != 5);

    return 0;
}
