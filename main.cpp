#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List <int> list;
    int n;
    std::cout << "n = ";
    std::cin >> n;
    list = List<int>();

    // Citirea si adaugarea a n elemente.
    for ( int i = 0; i < n; i++ ) {
        int x; // al i-lea element citit de la tastatura
        std::cin >> x;
        list.insert(x,i);
    }

    // Afisare continut vector
    list.print();

    list.remove(n/2);

    list.print();

	cout << "Give me something to continue";
	cin >> n;

    return 0;
}
