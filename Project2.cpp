/* 
* Ben De Jong
* CS-220-02
* P02: Painting supplies
* This program takes 2 user inputs, wall height and wall length, and calculates how many 
* gallons of paint is  needed to paint the user-defined wall.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {

  //declaring variables
  double wallHeight;
  double wallLength;
  const double oneGallon = 350;

  std::cout << "*** P02: Painting Supplies ***" << std::endl << std::endl;

  //taking user inputs.
  std::cout << "Enter wall height (feet): ";
  std::cin >> wallHeight;

  std::cout << "Enter wall length (feet): ";
  std::cin >> wallLength;

  std::cout << std::endl;

  //calculating and printing wallArea
  double wallArea = wallHeight*wallLength;
  std::cout << "Wall area: " <<  wallArea << " square feet" << std::endl;

  //calculating and printing how much paint is needed
  double paintNeeded = wallArea / oneGallon;
  std::cout << "Paint needed: " << std::fixed << std::setprecision(2) << paintNeeded << " gallons" << std::endl;

  //rounding up, because you cannot buy a decimal amount of paint.
  //ceil is used to round up, static_cast is used to get rid of the decimal.
  //you could also use setprecision(0) here, but static cast is just neater.
  std::cout << "Cans needed: " << static_cast<int>(ceil(paintNeeded)) << " can(s)";

  return 0;
}
