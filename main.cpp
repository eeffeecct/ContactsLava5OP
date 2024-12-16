#include <iostream>

using namespace std;

const int MAX_NAME_LEN = 100;
const int MAX_ADDRESS_PHONE_LEN = 100;

// Структура контакта
struct Contact {
    char fullName[MAX_NAME_LEN];
    char address[MAX_ADDRESS_PHONE_LEN];
    char phone[MAX_ADDRESS_PHONE_LEN];
    int age;
    char gender; // M/W
    int height;
};

bool checkName(Contact contact, const char search[]) {
    for (int i = 0; contact.fullName[i] != '\0'; i++) {
        if (contact.fullName[i] != search[i]) {
            return false;
        }
    }
    return true;
}

bool checkPhone(Contact contact, const char search[]) {
    for (int i = 0; contact.phone[i] != '\0'; i++) {
        if (contact.phone[i] != search[i]) {
            return false;
        }
    }
    return true;
}

bool checkAddress(Contact contact, const char search[]) {
    for (int i = 0; contact.address[i] != '\0'; i++) {
        if (contact.address[i] != search[i]) {
            return false;
        }
    }
    return true;
}

void findAddressAndPhoneByName(Contact* contacts, char search[], int sizeContact) {
    for (int i = 0; i < sizeContact; i++) {
        if (checkName(contacts[i], search)) {
            cout << contacts[i].address << "\n" << contacts[i].phone << endl;
            return;
        }
    }
    cout << "Nothing found" << endl;
}

void findFIO(Contact* contacts, char search[], int sizeContact) {
    for (int i = 0; i < sizeContact; i++) {
        if (checkAddress(contacts[i], search) || checkPhone(contacts[i], search)) {
            cout << contacts[i].fullName << endl;
            return;
        }
    }
    cout << "Nothing found" << endl;
}

// c I
void averageHeight(Contact* contacts, int sizeContact) {
    double height = 0;
    int countPeopleByAge = 0;

    for (int i = 0; i < sizeContact; i++) {
        if (contacts[i].age >= 15 && contacts[i].age <= 20) {
            height += contacts[i].height;
            countPeopleByAge++;
        }
    }
    if (countPeopleByAge > 0) {
        height /= countPeopleByAge;
        cout << "1. Average height of males and females in the 15-20 years group: " << height << endl;
    } else {
        cout << "1. There are no people in the 15-20 year old group." << endl;
    }

    height = 0;
    countPeopleByAge = 0;
    for (int i = 0; i < sizeContact; i++) {
        if (contacts[i].age >= 21 && contacts[i].age <= 25) {
            height += contacts[i].height;
            countPeopleByAge++;
        }
    }
    if (countPeopleByAge > 0) {
        height /= countPeopleByAge;
        cout << "2. Average height of males and females in the 21-25 years group: " << height << endl;
    } else {
        cout << "2. There are no people in the 21-25 year old group. " << endl;
    }

    height = 0;
    countPeopleByAge = 0;
    for (int i = 0; i < sizeContact; i++) {
        if (contacts[i].age >= 26 && contacts[i].age <= 30) {
            height += contacts[i].height;
            countPeopleByAge++;
        }
    }
    if (countPeopleByAge > 0) {
        height /= countPeopleByAge;
        cout << "3. Average height of males and females in the 26-30 years group: " << height << endl;
    } else {
        cout << "3. There are no people in the 26-30 year old group." << endl;
    }
}

// c II
void highestLowest(Contact* contacts, int sizeContact) {
    int highest = 0;
    int lowest = 200;
    for (int i = 0; i < sizeContact; i++) {
        if (contacts[i].height > highest) {
            highest = contacts[i].height;
        }
        if (contacts[i].height < lowest) {
            lowest = contacts[i].height;
        }
    }
    cout << "The highest height: " << highest << endl;
    cout << "The lowest height: " << lowest << endl;
}

// c III
void sameHeightAndAge(Contact* contacts, int sizeContact) {
    for (int i = 0; i < sizeContact; i++) {
        for (int j = i + 1; j < sizeContact; j++) {
            if (contacts[i].age == contacts[j].age &&
                contacts[i].height == contacts[j].height &&
                contacts[i].gender != contacts[j].gender) {
                cout << "Match found:" << endl;
                cout << "1. " << contacts[i].fullName << " (Age: " << contacts[i].age
                     << ", Height: " << contacts[i].height << ", Gender: " << contacts[i].gender << ")" << endl;
                cout << "2. " << contacts[j].fullName << " (Age: " << contacts[j].age
                     << ", Height: " << contacts[j].height << ", Gender: " << contacts[j].gender << ")" << endl;
            }
        }
    }
}

int main() {
    int contactCount = 10;

    // массив типа Contact
    Contact* contacts = new Contact[contactCount] {
    {"Timofey Tereschenko Tereschenko", "Russia, Samara, Samarskaya street, 63", "+79390000000", 18, 'M', 175},
    {"George Poletaev Denisovich", "Argentina, Buenos Aires, Av. Sta. Fe 1960", "+5493517078534", 17, 'M', 180},
    {"Saveliy Zimin Alexandrovich", "Slovenia, Ljubljana, Jamova cesta 38", "+38618785969", 18, 'M', 173},
    {"Ivan Ivanov Ivanovich", "Russia, Moscow, Tverskaya street, 22", "+74950000000", 30, 'M', 184},
    {"Petr Petrov Petrovich", "Russia, Saint Petersburg, Nevsky prospect, 10", "+78120000000", 26, 'M', 169},
    {"Olga Smirnova Alexeevna", "Kazakhstan, Almaty, Dostyk avenue, 45", "+77270000000", 21, 'W', 170},
    {"Niklas Schneider Johannesson", "Germany, Berlin, Friedrichstrasse 101", "+491700000000", 25, 'M', 185},
    {"John Smith Williamovich", "USA, New York, 5th Avenue, 678", "+12120000000", 22, 'M', 198},
    {"Marie Dubois Clairette", "France, Paris, Rue de Rivoli, 34", "+33170000000", 28, 'W', 165},
    {"Hiroshi Tanaka Harutoshi", "Japan, Tokyo, Chiyoda, 1-1", "+81300000000", 18, 'W', 173}};


    cout << "Enter your full name for the search:";
    char findAddressAndPhone[MAX_NAME_LEN];
    cin.getline(findAddressAndPhone, MAX_NAME_LEN);
    findAddressAndPhoneByName(contacts, findAddressAndPhone, contactCount);
    cout << endl;



    cout << "Enter phone number or address for the search:";
    char findFIObyAddressOrPhone[MAX_ADDRESS_PHONE_LEN];
    cin.getline(findFIObyAddressOrPhone, MAX_ADDRESS_PHONE_LEN);
    findFIO(contacts, findFIObyAddressOrPhone, contactCount);
    cout << endl;

    averageHeight(contacts, contactCount);
    cout << endl;
    highestLowest(contacts, contactCount);
    cout << endl;
    sameHeightAndAge(contacts, contactCount);

    delete[] contacts;
    return 0;
}
