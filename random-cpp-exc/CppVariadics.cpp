#include <iostream>
#include <vector>
using namespace std;

int t = 0;
vector <int> array_x;
vector <int> array_y;

// Enter your code for reversed_binary_value<bool...>()
void receive_data() {
    std::cin >> t;

    array_x.resize(t);
    array_y.resize(t);

    for (int i = 0; i <= t-1;i++) {
        cin >> array_x[i];
        cin >> array_y[i];
    }
}

template <bool first>
int reversed_binary_value() {
    return first;
}

template <bool first, bool second, bool... rest>
int reversed_binary_value() {
    return (first ? 1 : 0) + 2 * reversed_binary_value<second, rest...>();
}


int main() {
    receive_data();
    for (int i = 0; i <= t - 1; i++) {
        int valor_inicial = 64 * array_y[i];
        for (int j= 0; j <= 63;j++){
            if (array_x[i] == valor_inicial + j) {
                cout << "1";// ponemos uno
            } else { cout << "0"; }
        }
        cout << endl;
    }
    return 0;
}