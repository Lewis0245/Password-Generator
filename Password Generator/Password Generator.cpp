#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

class Characters
{
public:
    string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string special = "!@#$%^&*<>?/~\"\\";
};

string Preferences()
{
    Characters characters;
    int wantLowerCase, wantUpperCase, wantNumbers, wantSpecial, length;
    string characterPool = "";

    cout << "Do you want lowercase Letters? (1 for yes, 0 for no)\n";
    cin >> wantLowerCase;
    if (wantLowerCase) {
        characterPool += characters.lowerCase;
    }

    cout << "Do you want uppercase Letters? (1 for yes, 0 for no)\n";
    cin >> wantUpperCase;
    if (wantUpperCase) {
        characterPool += characters.upperCase;
    }

    cout << "Do you want numbers? (1 for yes, 0 for no)\n";
    cin >> wantNumbers;
    if (wantNumbers) {
        characterPool += characters.numbers;
    }

    cout << "Do you want special characters? e.g %@ (1 for yes, 0 for no)\n";
    cin >> wantSpecial;
    if (wantSpecial) {
        characterPool += characters.special;
    }

    cout << "Enter the length of your password: \n";
    cin >> length;

    string password = "";
    srand(time(0));
    for (int i = 0; i < length; i++) {
        password += characterPool[rand() % characterPool.size()];
    }

    return password;
}

int main()
{
    string password = Preferences();
    cout << "Your password is: " << password << "\n";


    cout << "\nPress Enter to exit...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}
