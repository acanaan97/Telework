#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
//This program converts array elements as the sum of the element plus six modulus 10

int main()
{
    int num;
    string line;
    vector<int> collection, output;

    cout << "Enter the elements in the collection: " << endl;
    getline(cin, line);
    istringstream iss(line);

    while (iss >> num)
        collection.push_back(num);

    for (auto i : collection)
        output.push_back((i + 6) % 10);

    for (auto x : output)
        cout << x << " ";

    return 0;
}