#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

std::vector<int> keepThird(std::vector<int> elements);

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

    output = keepThird(collection);

    for (auto &i : output)
        cout << i;

    return 0;
}

std::vector<int> keepThird(std::vector<int> elements) {
    vector<int> res;

    for (int i = 2; i < elements.size(); i = i + 3)
        res.push_back(elements.at(i));

    return res;

}