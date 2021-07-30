#include <array>
#include <mutex>
#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <iomanip>
const int N = 5;
std::mutex gLock;
std::atomic<bool> tableReady = false;

struct fork
{
    std::mutex mutex;
};

struct table
{
    std::atomic<bool> ready{false};
    std::array<fork, N> forks;
};

class member
{
private:
    std::string const name;
    table const &dinnertable;
    fork &left_fork;
    fork &right_fork;
    std::thread pThread;

public:
    member(std::string const n, table const &t, fork &l, fork &r) : name(n), dinnertable(t), left_fork(l), right_fork(r), pThread(&member::dine, this) {}

    ~member() { pThread.join(); }

    void think()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // thinking...

        {
            std::lock_guard<std::mutex> cout_lock(gLock);
            std::cout << this->name << " is thinking " << std::endl;
        }
    }

    void eat()
    {
        std::lock(left_fork.mutex, right_fork.mutex); // protect the forks

        std::lock_guard<std::mutex> left_lock(left_fork.mutex, std::adopt_lock);
        std::lock_guard<std::mutex> right_lock(right_fork.mutex, std::adopt_lock);

        {
            std::lock_guard<std::mutex> cout_lock(gLock);
            std::cout << this->name << " started eating." << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // eating

        {
            std::lock_guard<std::mutex> cout_lock(gLock);
            std::cout << this->name << " finished eating." << std::endl;
        }
    }

    void dine()
    {
        while (!tableReady)
        {
        } // wait until flag is true

        do
        {
            think();
            eat();
        } while (tableReady);
    }
};

int main()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));

    table table;
    std::array<member, N> philosophers{
        {
            {"Seth", table, table.forks[0], table.forks[1]},
            {"Matt", table, table.forks[1], table.forks[2]},
            {"Chris", table, table.forks[2], table.forks[3]},
            {"Jacob", table, table.forks[3], table.forks[4]},
            {"eliee", table, table.forks[4], table.forks[0]},
        }};

    std::cout << "Dinner is served." << std::endl;

    tableReady = true;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    tableReady = false;

    return 0;
}