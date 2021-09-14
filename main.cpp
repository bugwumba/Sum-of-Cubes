//main.cpp
#include "SumOfCubes.h"
#include "Individual.h"
#include "NonTrivial.h"

using namespace std;

inline void WelcomeScreen(){
    cout << "\nWelcome to Sum of Cubes!\n";
    cout << "Created for: Obiamaka Agu\n";
    cout << "\nThe purpose of this program\n"; 
    cout << "is to find combinations (k, x, n)\n";
    cout << "\nWhat would you like to do?\n\n";  
}

inline void Menu(){
    cout <<"---------------------------------------------------------------------\n";
    cout << "1. Enter (k, x, n) individually\n";
    cout << "2. Find non-trivial solutions for (k, x, n) within a given range\n";
    cout << "3. Quit\n";
    cout << "--------------------------------------------------------------------\n";
}

int main(){

    int option(0);
    char choice;
    int fileAppendage2(0);
    int fileAppendage3(0);
    int iterator(0);
    int iterator2(0);
    int Emptyarr[3];
    string NonTrivialSolutions;
    string example;
    ostringstream fileName2;
    ostringstream fileName3;

    Individual Individual;
    NonTrivial NonTrivial;
    
    ofstream outFS;

    WelcomeScreen();
    Menu();
    cin >> option;
    while(option != 3){ 
        if(option == 1){
            Individual.kSetter(Emptyarr);
            Menu();
            cin >> option;
        }
        else if (option == 2){
            NonTrivial.DefineRange();
            NonTrivial.deletePointerArray();
            NonTrivial.Print();
            cout << "\nWould you like to save this data? (Y/N) ";
            cin >> choice;
            while(choice != 'Y' || choice != 'y' || choice != 'N' || choice != 'n'){
                cout << "Invalid entry!\n";
                cout << "Please enter a valid entry\n\n";
                cout << "Would you like to save this data? (Y/N) ";
                cin >> choice;
            }
            if(choice == 'Y' || choice == 'y'){
                fileName2 << "Non-Trivial Solutions" << fileAppendage2 << ".txt";
                NonTrivialSolutions = fileName2.str();
                outFS.open(NonTrivialSolutions);
                if(!outFS.is_open()){
                    cout << "could not open file!\n";
                }
                else{
                    iterator2 = NonTrivial.Amount2();
                    iterator = NonTrivial.Amount();
                    outFS << "The total number of solutions from " << NonTrivial.GetBeginRange() - NonTrivial.GetEndRange();
                    outFS << " to " << NonTrivial.GetEndRange() << " are: " << iterator2;
                    outFS << endl;
                    outFS << NonTrivial.Saved(0) << endl; 
                }
            }
            ++fileAppendage2;
            fileName2.str(string());
            outFS.close();
            NonTrivial.EmptyVector();
            Menu();
            cin >> option;
        }
        else{
            cout << "\nInvalid Entry!\n";
            cout << "Please select one of the three options:\n";
            Menu();
        }
        while(!(cin >> option)){
            cout << "\nInvalid Entry!\n";
            cout << "Please select one of the three options\n";
            cin.clear();
            cin.ignore(123, '\n');
            Menu();
        }
    }
    cout << "\nThank you for using Sum of Cubes!\n\n";
    return 0;
}
