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
    cout << "Ничего не найдено";
}

void findFIO(Contact* contacts, char search[], int sizeContact) {
    for (int i = 0; i < sizeContact; i++) {
        if (checkAddress(contacts[i], search) || checkPhone(contacts[i], search)) {
            cout << contacts[i].fullName;
            return;
        }
    }
    cout << "Ничего не найдено";
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
    {"Hiroshi Tanaka Harutoshi", "Japan, Tokyo, Chiyoda, 1-1", "+81300000000", }
};

/* A:
    cout << "Введите Ф.И.О для поиска:";
    char findAddressAndPhone[MAX_NAME_LEN];
    cin.getline(findAddressAndPhone, MAX_NAME_LEN);

    findAddressAndPhoneByName(contacts, findAddressAndPhone, contactCount);
*/
//eprjflkekrjf
/* B:
    cout << "Введите телефон или адресс для поиска:";
    char findFIObyAddressOrPhone[MAX_ADDRESS_PHONE_LEN];
    cin.getline(findFIObyAddressOrPhone, MAX_ADDRESS_PHONE_LEN);

    findFIO(contacts, findFIObyAddressOrPhone, contactCount);
*/

    delete[] contacts;
    return 0;
}

