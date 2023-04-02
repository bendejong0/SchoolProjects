// Ben DeJong
// CS-220-02
// P04: Air Travel Cost Calculator.
// This program takes user defined conditions and calculates the cost of their flight.


#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "*** P04: Air Travel Cost Calculator ***" << endl << endl;
    
    int age;
    int flightCost;
    int bags;
    int totalCost;
    const int secondBag = 25;
    const int thirdBag = 60;
    
    cout << "Flight Cost: ";
    cin >> flightCost;
    cout << "Passenger age: ";
    cin >> age;
    cout << "Number of checked bags: ";
    cin >> bags;
    
    if(age <= 2){
   	 flightCost =0;
    }
    else if(age > 2 && age < 13){
   	 flightCost = flightCost*.9;
    }
    else if(age >= 60){
   	 flightCost = flightCost*.8;
    }
    else{
   	 flightCost = flightCost;
    }
    
    if(bags<=1){
   	 totalCost = flightCost;
    //first bag is free, therefore the cost remains the same.
    //have to assign value to totalCost so it can be printed later.
    //otherwise the cost will be 0.
    }
    else if(bags ==2){
   	 totalCost=flightCost+secondBag;
    }
    else if(bags >2){
   	 totalCost=flightCost+secondBag+(thirdBag*(bags-2));
   	 //-2 because you subtract the first bag (free) and second bag ($25)
    }
    
    cout << endl << "Travel cost: $" << totalCost << endl;

    return 0;
}
