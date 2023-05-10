// Ben DeJong
// CS 220-02
// P:07
// This program uses a brute force method to solving algebraic linear equations.

#include <iostream>
using namespace std;
int main() {
  cout << "*** Brute Force Equation Solver ***" << endl << endl;

  cout << "Enter coefficients (a, b, c) for the first equation separated by spaces: ";
	
  int var1a; 
  int var2a;
  int ansa;
  cin >> var1a >> var2a >> ansa;

  cout << "Enter coefficients (a, b, c) for the second equation separated by spaces: ";

  int var1b;
  int var2b;
  int ansb;
  cin >> var1b >> var2b >> ansb; //asking for inputs

  for (int i = -10; i <= 10; i++) {
    for (int j = -10; j <= 10; j++) {
      if (((i * var1a + j * var2a) == ansa) && //checks if both statements will give
          ((i * var1b + j * var2b) == ansb)) { //the correct answer
        cout << "x = " << i << ", y = " << j << endl;
        return 0;
      }
    }
  }
  cout << "There is no solution" << endl; //statement if there is no solution
										  //within the range of -10 to 10.

  return 0;
}