#include <iostream>
#include <string>

using namespace std;

struct Count
{
    Count() : letters(0), digits(0), special(0) {}
    int letters, digits, special;
    void countStuff(string line);
};

void Count::countStuff(string line) {
    int test = 0;

    for (auto c : line)
    {
        test = static_cast<int>(c);

        if (isalpha(test))
            this->letters = this->letters + 1;

        else if (isdigit(test))
            this->digits = this->digits + 1;

        else
            this->special = this->special + 1;
    }
}

int main()
{
    string line;
    struct Count count;

    cout << "Enter a sentence: " << endl;
    getline(cin, line);

    count.countStuff(line);

    cout << "Num letters: " << count.letters << "\nNum digits: " << count.digits << "\nNum special chars: " << count.special << endl;

    return 0;
}
