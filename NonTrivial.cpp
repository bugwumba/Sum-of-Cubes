//NonTrivial.cpp
#include "NonTrivial.h"

NonTrivial::NonTrivial ()
:SumOfCubes(), indexes(0) {}

inline void NonTrivial::produceCombinations(int arr[], int data[], const int &start, const int &end, const int &index, const int &combinations){
    //array to hold copy of range

    if(index == combinations){
        if(data[0] != data[1] && data[0] != data[2] && data[1] != data[2]){
            kSetter(data);
        }
    }

    // replace index with all possible elements. 
    // The condition "end-i+1 >= r-index" 
    // makes sure that including one element  
    // at index will make a combination with  
    // remaining elements at remaining positions 

    for(unsigned int i = start; i <= end && (end - i + 1 >= combinations - index); ++i){
        data[index] = arr[i];
        produceCombinations(arr, data, i+1, end, index+1, combinations);
    }
}

//Function to set k value 
//Good!
inline void NonTrivial::kSetter(int arr[]) {
    this->k = arr[0];
    xSetter(arr);
}

inline void NonTrivial::xSetter(int arr[]){
    this->x = arr[1];
    nSetter(arr);
}

inline void NonTrivial::nSetter(int arr[]){
    this->n = arr[2];
    if(calc_NBoundaries() == true){
        if(Boundaries() == true){
            if(checkEquality() == true){
            }
        }
    }
}

//Function to test if numbers are correct
inline bool NonTrivial::Boundaries(){

    long double p(GetX_value() + GetK_value() - GetN_value());
        if(GetK_value() != GetN_value()){
            //Removed stipulation that x <= n for testing purposes
            if(GetX_value() != GetN_value()){ //&& GetX_value() <= GetN_value()){
                long double xPlus_K(GetX_value() + GetK_value());
                if(xPlus_K > GetN_value()){
                    if(GetK_value() >= 3){
                        if(GetX_value() >= 5){
                            long double nMinusOne(GetN_value() - 1);
                            if(GetK_value() != nMinusOne){
                                if( p >= 2){
                                    return true;
                                }
                            }
                        }
                    }
                }
             }
        }
    return false;
}

inline bool NonTrivial::calc_NBoundaries(){
    int count(0);
    int q(GetN_value()*GetN_value() + GetN_value() + 1);
    if(q == 0){
        return false;
    }
    if(q == 3){
        return false;
    }
    if(q % 3 == 0){
        return false;
    }
    else{
        return true;
    }

    //     if(q % 7 == 0){
    //     return true;
    // }4
    // else{
    //     return false;
    // }
}

inline bool NonTrivial::checkEquality(){

    long double LHS(Summation_KLS() + X_valueLS() + Summation_NLS());
    if(LHS == Right_HSquare()){
        ListOfSolutions(GetK_value(), GetX_value(), GetN_value());
        return true;
    }
    return false;
    
}

//Function to calculate the sum of k left side
inline unsigned long long int NonTrivial::Summation_KLS(){
    sumK_LS = 0;
    for(unsigned int j = 1; j < GetK_value(); ++j){
        sumK_LS += j*j*j;
    }
    return sumK_LS;
}

//Function to calculate x to thrid power
inline unsigned long long int NonTrivial::X_valueLS(){
    long double x_cubed (GetX_value()*GetX_value()*GetX_value());
    return x_cubed;
}

//Function to calculate the sum of n left-hand side
inline unsigned long long int NonTrivial::Summation_NLS(){
    sumN_LS = 0;
    unsigned int begin (GetK_value() + 1);
    unsigned int condition (GetN_value() + 1);
    for(unsigned int j = begin; j < condition; ++j){
        sumN_LS += j*j*j;
    }
    return sumN_LS;
}

//Function to calculate the sum of K right-hand side
inline unsigned long long int NonTrivial::Summation_KRS(){
    sumK_RS = 0;
    for(unsigned int j = 1; j < GetK_value(); ++j){
        sumK_RS += j;
    }
    return sumK_RS;
}

//Function to calculate the sum of N right-hand Side
inline unsigned long long int NonTrivial::Summation_NRS(){
    sumN_RS = 0;
    unsigned int begin(GetK_value() + 1);
    unsigned int condition(GetN_value() + 1);
    for(unsigned int j = begin; j < condition; ++j){
        sumN_RS += j;
    }
    return sumN_RS;
}

//Returns the size of the vector
int NonTrivial::Amount(){
    indexes = Answerlist.size();
    return indexes;
}

int NonTrivial::Amount2(){
    indexes = correctList.size();
    return indexes;
}
//Returns the results at each index
string NonTrivial::Saved(int index){
    return Answerlist.at(index);
}

int NonTrivial::GetBeginRange(){
    return this->beginRange;
}

int NonTrivial::GetEndRange(){
    return this->endRange;
}

//Function to square right-hand side
//Good!
unsigned long long int NonTrivial::Right_HSquare(){
    long double RHS(Summation_KRS() + GetX_value() + Summation_NRS());
    RHS *= RHS;
    return RHS;
}