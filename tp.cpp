#include "iostream"
using namespace std;

class temp {
public:
    int t;
    void hey();
};

void temp::hey() { cout << "hey!!\n"; }

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << n << "\n";
    }
}