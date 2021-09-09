//*Used to find soltuion for user determined (k, x, n)

#include "SumOfCubes.h"

#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

class Individual : public SumOfCubes{
    public:
        Individual();
        void kSetter(int arr[])override;
        void xSetter(int arr[])override;  
        void nSetter(int arr[])override; 
        bool calc_NBoundaries()override;
        bool Boundaries()override;
        bool checkEquality()override;
        unsigned long long int Summation_NLS()override;
        unsigned long long int Summation_KLS()override;
        unsigned long long int Summation_KRS()override;
        unsigned long long int Summation_NRS()override;
        unsigned long long int X_valueLS()override;
        unsigned long long int Right_HSquare()override;
        void produceCombinations(int arr[], int data[], const int &, const int &, const int &, const int &)override;
};

#endif