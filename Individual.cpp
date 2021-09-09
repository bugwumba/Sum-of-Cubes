//Individual.cpp
#include "Individual.h"

Individual::Individual()
: SumOfCubes() {}

inline void Individual::produceCombinations(int arr[], int data[], const int &start, const int &end, const int &index, const int &combinations){}

//Function to set k value
inline void Individual::kSetter(int arr[]){
    cout << "Please enter a value for k: ";
    cin >> this->k;
    cout << endl;
    xSetter(arr);
}

//Function to set x value
inline void Individual::xSetter(int arr[]){
    cout << "Please enter a value for x: ";
    cin >> this->x;
    cout << endl;
    nSetter(arr);
}

//Function to set n value
inline void Individual::nSetter(int arr[]){
    cout << "Please enter a value for n: ";
    cin >> this->n;
    cout << endl;
    while(calc_NBoundaries() == false){
        cout << "n does not work! Please enter a new n: ";
        cin >> this->n;
        cout << endl;
    }
    if(Boundaries() == true){
        checkEquality();
    }
    else{
        kSetter(arr);
    } 
}

//Function to test if n is possible
inline bool Individual::calc_NBoundaries(){
    int count(0);
    int q = (GetN_value()*GetN_value() + GetN_value() + 1);
    if(q == 0){
        cout << "q cannot be equal to 0:\n";
        return false;
    }
    if(q == 3){
        cout << "q cannot be equal to 3:\n";
        return false;
    }
    if(q % 3 == 0){
        cout << "q cannot be divisible by 3:\n";
        return false;
    }
    // for(unsigned int i = 2; i < q; ++i){
    //     if(q % i == 0){
    //         count++;
    //     }
    // }   
    // if(count > 1){
    //     cout << "q is not prime:\n";
    //     return false;
    // }
    else{
        return true;
    }
}

//Function to test if numbers are correct
bool Individual::Boundaries(){

    long double p = (GetX_value() + GetK_value() - GetN_value());
        if(GetK_value() != GetN_value()){
            //Removed stipulation that x <= n for testing purposes
            if(GetX_value() != GetN_value()){ //&& GetX_value() <= GetN_value()){
                long double xPlus_K = GetX_value() + GetK_value();
                if(xPlus_K > GetN_value()){
                    if(GetK_value() >= 3){
                        if(GetX_value() >= 5){
                            long double nMinusOne = GetN_value() - 1;
                            if(GetK_value() != nMinusOne){
                                if( p >= 2){
                                    cout << "These values work!\n";
                                    return true;
                                }
                                else{
                                    cout << " p, which is the sum of (k,x,n) is not greater than or equal to 2.\n";
                                    return false;
                                }

                            }
                            else{
                                cout << "k value is equal to n value minus 1.\n";
                                return false;
                            }
                        }
                        else{
                            cout << "x value is not greater than or equal to 5.\n";
                            return false;
                        }
                    }
                    else{
                        cout << "k value is not greater than or equal to 3.\n";
                        return false;
                    }
                }
                else{
                    cout << "x + K is less than n value.\n";
                    return false;
                }
             }
             else{
                 if(GetX_value() == GetN_value()){
                     cout << "x value is equal to n value.\n";
                     return false;
                 }
                 else{
                     cout << "x value is not less than or equal to n value.\n";
                     return false;
                 }
             }
        }
        else{
            cout << "k value is equal to n value.\n";
            return false;
        }

    return false;
}

inline bool Individual::checkEquality(){

    long double LHS = (Summation_KLS() + X_valueLS() + Summation_NLS());
    if(LHS == Right_HSquare()){
        cout << "The combination of this (k,x,n) - (";
        cout << GetK_value() <<", " << GetX_value() << ", " << GetN_value() << ") works!\n";
        return true;
    }
    else{
    cout << "The combination of this (k,x,n) - (";
    cout << GetK_value() <<", " << GetX_value() <<", " << GetN_value() << ") does not work!\n";
    return false;
    }
}

//Function to calculate the sum of k left side
inline unsigned long long int Individual::Summation_KLS(){
    sumK_LS = 0;
    for(unsigned int j = 1; j < GetK_value(); ++j){
        sumK_LS += j*j*j;
    }
    cout << "The summation of " << GetK_value() << " on the left-hand side is: " << sumK_LS << endl;
    return sumK_LS;
}

//Function to calculate x to thrid power
inline unsigned long long int Individual::X_valueLS(){
    long double x_cubed(GetX_value()*GetX_value()*GetX_value());
    cout << GetX_value() << " raised to the third power on the left-hand side is: " << x_cubed << endl;
    return x_cubed;
}

//Function to calculate the sum of n left-hand side
inline unsigned long long int Individual::Summation_NLS(){
    sumN_LS = 0;
    unsigned int begin(GetK_value() + 1);
    unsigned int condition(GetN_value() + 1);
    for(unsigned int j = begin; j < condition; ++j){
        sumN_LS += j*j*j;
    }
    cout << "The summation of " << GetN_value() << " on the left-hand side is: " << sumN_LS << endl;
    return sumN_LS;
}

//Function to calculate the sum of K right-hand side
inline unsigned long long int Individual::Summation_KRS(){
    sumK_RS = 0;
    for(unsigned int j = 1; j < GetK_value(); ++j){
        sumK_RS += j;
    }
    cout << "The summation of " << GetK_value() << " on the right-hand side is: " << sumK_RS << endl;
    cout << "The value of x on the right hand side is: " << GetX_value() << endl;
    return sumK_RS;
}

//Function to calculate the sum of N right-hand Side
inline unsigned long long int Individual::Summation_NRS(){
    sumN_RS = 0;
    unsigned int begin(GetK_value() + 1);
    unsigned int condition(GetN_value() + 1);
    for(unsigned int j = begin; j < condition; ++j){
        sumN_RS += j;
    }
    cout << "The summation of " << GetN_value() << " on the right-hand side is: " << sumN_RS << endl;
    return sumN_RS;
}

//Function to square right-hand side
unsigned long long int Individual::Right_HSquare(){
    long double RHS(Summation_KRS() + GetX_value() + Summation_NRS());
    RHS *= RHS;
    cout << "The right-hand side summation squared is: " << RHS << endl;
    return RHS;
}