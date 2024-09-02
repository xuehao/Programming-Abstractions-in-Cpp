/**
 * File: BinarySearch.cpp
 * ----------------------
 * Implementation of binary search.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "vector.h"
using namespace std;

/* Function prototypes */

void initCityNames(Vector<string>& cities);
int findInSortedVector(string key, Vector<string>& vec);
int binarySearch(string key, Vector<string>& vec, int p1, int p2);

/* Main program */

int main() {
    Vector<string> cities;
    initCityNames(cities);
    for (const string& city : cities) {
        int index = findInSortedVector(city, cities);
        cout << city << " == " << cities[index] << endl;
    }
    return 0;
}

/**
 * Function: initCityNames
 * Usage: initCityNames(cities);
 * -----------------------------
 * Initializes the cities vector to the cities in the board game Ticket
 * to Ride Europe by Alan Moon.
 */

void initCityNames(Vector<string>& cities) {
    cities += "Amsterdam", "Angora", "Athina", "Barcelona", "Berlin", "Brest", "Brindisi",
        "Bruxelles", "Bucuresti", "Budapest", "Cadiz", "Constantinople", "Danzig", "Dieppe",
        "Edinburgh", "Erzurum", "Essen", "Frankfurt", "Kharkov", "Kobenhavn", "Kyiv", "Lisboa",
        "London", "Madrid", "Marseille", "Moskva", "Munchen", "Palermo", "Pamplona", "Paris",
        "Petrograd", "Riga", "Roma", "Rostov", "Sarajevo", "Sevastopol", "Smolensk", "Smyrna",
        "Sochi", "Sofia", "Stockholm", "Venezia", "Warszawa", "Wien", "Wilno", "Zagrab", "Zurich";
};

/**
 * Function: findInSortedVector
 * Usage: int index = findInSortedVector(key, vec);
 * ------------------------------------------------
 * Searches for the specified key in the Vector<string> vec, which
 * must be sorted in lexicographic (character code) order.  If the
 * key is found, the function returns the index in the vector at
 * which that key appears. (If the key appears more than once in
 * the vector, any of the matching indices may be returned).  If the
 * key does not exist in the vector, the function returns -1.  This
 * implementation is simply a wrapper function; all of the real work
 * is done by the more general binarySearch function.
 */

int findInSortedVector(string key, Vector<string>& vec) {
    return binarySearch(key, vec, 0, vec.size() - 1);
}

/**
 * Function: binarySearch
 * Usage: int index = binarySearch(key, vec, p1, p2);
 * --------------------------------------------------
 * Searches for the specified key in the Vector<string> vec, looking
 * only at indices between p1 and p2, inclusive.  The function returns
 * the index of a matching element, or -1 if no match is found.
 */

int binarySearch(string key, Vector<string>& vec, int p1, int p2) {
    if (p1 > p2)
        return -1;
    int mid = (p1 + p2) / 2;
    if (key == vec[mid])
        return mid;
    if (key < vec[mid]) {
        return binarySearch(key, vec, p1, mid - 1);
    } else {
        return binarySearch(key, vec, mid + 1, p2);
    }
}
