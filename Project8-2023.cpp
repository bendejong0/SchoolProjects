// Ben DeJong
// CS 220-02
// P:08
// This program uses vectors to keep track of player data including jerseys and ratings.

#include <iostream>
#include <vector>
using namespace std;

int main() {
  char menuInput; // input for our loop to work

  vector<int> jersey; // vector containing all the data for the jerseys
  vector<int> rating; // vector containing all the ratings for the players

  int userRatingInput; // int that allows us to store a rating before adding it
                       // to the vector
  int userJerseyNum; // int that allows us to store a jersey before adding it to
                     // the vector

  unsigned int i; // standard variable for loops that i wrote out because i dont
                  // want to have to do it over and over

  bool jerseyIsntTaken; // boolean val that will be updated it the jersey number
                        // is taken

  bool jerseyDoesntExist; // becomes true if the program cannot find
                          // the jersey number

  int tempVal; // values that are used when we need to update a player's rating
  int tempVal2;

  do {
    jerseyIsntTaken = true; // new loop so reset the value
    jerseyDoesntExist = true;

    cout << "--Menu--" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option: ";

    cin >> menuInput;
    cout << endl;

    switch (menuInput) {
    case 'a':
      cout << "Enter a player's jersey number: ";
      cin >> userJerseyNum;
      cout << endl;

      for (unsigned int i = 0; i < jersey.size(); i++) {
        if (jersey.at(i) == userJerseyNum) {
          cout << endl
               << "  >>> Jersey number " << userJerseyNum
               << " is already in use! <<< " << endl
               << endl;
          jerseyIsntTaken = false; // that way it wont ask the user to input
          break;                   // a rating
        }
      }
      if (jerseyIsntTaken) {
        cout << "Enter player rating: ";
        cin >> userRatingInput;
        cout << endl;
        jersey.push_back(userJerseyNum);
        rating.push_back(userRatingInput);
        cout << "  >>> Jersey number " << userJerseyNum << " added! <<< "
             << endl
             << endl;
      }

      break;

    // case for if the user wants to delete some info
    case 'd':
      if (jersey.size() == 0) {
        cout << " <<< You have not entered any players! >>>" << endl << endl;
        break;
      }
      cout << "Enter a jersey number: " << endl;
      cin >> userJerseyNum;
      for (int i = 0; i < jersey.size(); i++) {
        if (jersey.at(i) == userJerseyNum) {
          jersey.erase(jersey.begin() + i);
          rating.erase(rating.begin() + i);
          cout << endl
               << "  >>> Jersey number " << userJerseyNum << " deleted! <<< "
               << endl
               << endl;
          jerseyDoesntExist = false;
        }
      }
      if (jerseyDoesntExist) {
        cout << endl
             << " >>> Jersey number " << userJerseyNum << " not found! <<<"
             << endl
             << endl;
        break;
      }
      break;

	// if the user wants to output the roster
    case 'o':
      if (menuInput == 'o' && jersey.size() != 0) {
        cout << "<<< Full Roster >>>" << endl;
        for (i = 0; i < jersey.size(); i++) {
          cout << "Player " << i + 1 << " -- Jersey number: " << jersey.at(i)
               << ", Rating: " << rating.at(i) << endl;
        }
        cout << endl << endl;
      }
      if (jersey.size() == 0) {
        cout << " <<< You have not entered any players! >>>" << endl << endl;
        break;
      }
      break;

    // incase the user wants to update the data.
    case 'u':
      if (jersey.size() == 0) {
        cout << " <<< You have not entered any players! >>>" << endl << endl;
        break;
      }
      cout << "Enter player you wish to update: ";
      cin >> tempVal;
      cout << endl;
      for (i = 0; i < jersey.size(); i++) {
        if (tempVal == jersey.at(i)) {
          cout << "Enter the new rating: ";
          cin >> tempVal2;
          rating.at(i) = tempVal2;
          jerseyDoesntExist = false;
        }
      }
      if (jerseyDoesntExist) {
        cout << " >>> Jersey number " << tempVal << " not found! <<<" << endl
             << endl;
        break;
      }
      cout << "  >>> Jersey number " << tempVal << " rating updated! <<<"
           << endl
           << endl;
      break;

    // if the user wants to see scores above a certain threshhold.
    case 'r':
      if (jersey.size() == 0) {
        cout << " <<< You have not entered any players! >>>" << endl << endl;
        break;
      }
      cout << "Enter a rating: ";
      cin >> tempVal;
      cout << endl << "<<< Ranking above " << tempVal << " >>> " << endl;
      tempVal2 = 0;
      for (i = 0; i < jersey.size(); i++) {
        if (rating.at(i) > tempVal) {
          cout << "Player " << i + 1 << " -- Jersey number: " << jersey.at(i)
               << ", Rating: " << rating.at(i) << endl;
          tempVal2++;
        }
      }
      if (tempVal2 == 0) {
        cout << "No players rated above " << tempVal << "!" << endl;
      }
      cout << endl;
      break;

    case 'q':
      break;

    default:
      cout << endl << "Please select a valid option." << endl << endl;
      break;
    }

  } while (menuInput != 'q');
}