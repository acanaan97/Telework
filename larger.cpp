#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

std::vector<int> compare(std::vector<int> elements);

//This program compares the first and last, second and second to last etc integers in a collection, storing the larger and outputting the results.
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

    output = compare(collection);

    for (auto &i : output)
        cout << i;

    return 0;
}

std::vector<int> compare(std::vector<int> elements)
{
    vector<int> result;
    const int length = elements.size();
    const int mid = length / 2;

    if (length % 2 == 0)
    {
        // store the larger
        for (int x = 0; x < length / 2; x++)
        {
            if (elements.at(x) > elements.at(length - x - 1))
                result.push_back(elements.at(x));
            else
                result.push_back(elements.at(length - x - 1));
        }
    }

    else
    {
        // store the larger, and grab the middle element
        int y = 0;
        for (y; y < length / 2; y++)
        {
            if (elements.at(y) > elements.at(length - y - 1))
                result.push_back(elements.at(y));
            else
                result.push_back(elements.at(length - y - 1));
        }
        result.push_back(elements.at(mid));
    }

    return result;
}