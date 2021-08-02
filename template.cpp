#include <iostream>

template <class T>
class Table
{
private:
    T *pT;
    int size;

public:
    Table(int N) : size(N) { pT = new T[size];  }
    ~Table() { delete[] pT; }
    T &operator[](int indice) { return pT[indice]; }
    void printCollection(T const *collection, int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << collection[i] << " ";
        }
    }
};

int main() {
    return 0;
}