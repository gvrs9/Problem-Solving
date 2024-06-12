#include "iostream"
using namespace std;

int main() {
    // The new operator returns the address of the allocated memory. This address is of type int* (a pointer to an int).
    cout << (new int) << "\n"; // some address like Ex: 0x5965eb00a2b0

    int *p = new int;

    cout << typeid(p).name() << "\n";

    delete p;
}
