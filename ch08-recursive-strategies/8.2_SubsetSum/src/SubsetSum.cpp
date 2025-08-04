/*
 * File: SubsetSum.cpp
 * -------------------
 * This file tests the subsetSumExists function.
 */

#include <iostream>
#include "console.h"
#include "set.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

bool subsetSumExists(Set<int> & set, int target);
int minSum(Set<int> & set);
int maxSum(Set<int> & set);
string toString(Set<int> & set);

/* Test program */

int main() {
   Set<int> set;
   set += -2, 1, 3, 8;
   cout << "set = " << toString(set) << endl;
   int min = minSum(set);
   int max = maxSum(set);
   cout << boolalpha;
   for (int i = min; i <= max; i++) {
      cout << "subsetSumExists(set, " << i << ") = "
           << subsetSumExists(set, i) << endl;
   }
   return 0;
}

bool subsetSumExists(Set<int> & set, int target) {
   if (set.isEmpty()) {
      return target == 0;
   } else {
      int element = set.first();
      Set<int> rest = set - element;
      return subsetSumExists(rest, target)
          || subsetSumExists(rest, target - element);
   }
}

int minSum(Set<int> & set) {
   int total = 0;
   for (int element: set) {
      if (element < 0) total += element;
   }
   return total;
}

int maxSum(Set<int> & set) {
   int total = 0;
   for (int element: set) {
      if (element > 0) total += element;
   }
   return total;
}

/*
 * Function: toString
 * Usage: string str = toString(set);
 * ----------------------------------
 * Returns the string representation of the set using the
 * conventional curly-brace representation.
 */

string toString(Set<int> & set) {
   string str = "{";
   for (int element: set) {
      if (str.length() > 1) str += ",";
      str += " " + integerToString(element);
   }
   return str + " }";
}
