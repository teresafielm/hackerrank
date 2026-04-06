#include <iostream>
#include <vector>

using namespace std;


/*
 * Complete the 'chiefHopper' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int chiefHopper(vector<int> arr) {
    int initial_energy = 1;
    int new_energy = 0;
    bool min_found = false;
    int i = 0;

    while (min_found == false) {
        while (i <= arr.size() - 1) {
            std::cout << "i: "<<i<<" initial_energy: "<<initial_energy<<" new_energy: "<<new_energy << endl;
            if (initial_energy < arr[i]) {
                new_energy = initial_energy - (arr[i] - initial_energy);
                i += 1;
                std::cout << "1), new energy: " << new_energy<<endl;
            }
            else {
                new_energy = initial_energy + (initial_energy - arr[i]);
                i += 1;
                std::cout << "2), new energy: " << new_energy << endl;
            }
            if (new_energy < 1) { // Nos quedamos sin energia
                std::cout << "==No energy left===" << endl;
                initial_energy += 1;
                i = 0;
                new_energy = 0;
            }
        }
        if (new_energy > 0) { // Encontramos el minimo de energia inicial
            min_found = true;
        }
    }

    return initial_energy;
}

int main()
{
    vector<int> arr = {3,4,3,2,4};

    int result = chiefHopper(arr);

    cout << result << "\n";

    return 0;
}