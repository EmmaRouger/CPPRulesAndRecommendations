//Use valid references, pointers, and iterators to reference elements of a basic_string
//Mason Myre
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

  string s = "The cake is a lie";

  cout << s << "\n";

  replace(s.begin(), s.end(), 'c', 'l'); //loop through safely

  cout << s << endl;



  return 0;


}
