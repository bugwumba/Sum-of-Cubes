
//*Used to find non-trivial soltuions for user determined range for (k, x, n)

#include "SumOfCubes.h"

#ifndef _NONTRIVIAL_H_
#define _NONTRIVIAL_H_

class NonTrivial : public SumOfCubes{
    private:
        int indexes;

    public:
        NonTrivial();
        void produceCombinations(int arr[], int data[], const int &, const int &, const int &, const int &)override; 
        void kSetter(int arr[])override;
        void xSetter(int arr[])override;
        void nSetter(int arr[])override;
        int Amount();
        int Amount2();
        string Saved(int);
        int GetBeginRange();
        int GetEndRange();
        bool checkEquality()override;
        unsigned long long int Summation_NLS()override;
        unsigned long long int Summation_KLS()override;
        unsigned long long int Summation_KRS()override;
        unsigned long long int Summation_NRS()override;
        unsigned long long int X_valueLS()override;
        unsigned long long int Right_HSquare()override;
        bool Boundaries()override;
        bool calc_NBoundaries()override;
};

#endif