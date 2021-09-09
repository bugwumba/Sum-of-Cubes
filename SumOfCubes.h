
#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <sstream>

#include "SubSet.h"
using namespace std;

#ifndef _SUMOFCUBES_H_
#define _SUMOFCUBES_H_

class SumOfCubes : public SubSet{
    protected:
        unsigned short int k;
        unsigned short int x;
        unsigned short int n;
        unsigned long long int sumK_LS;
        unsigned long long int sumN_LS;
        unsigned long long int sumK_RS;
        unsigned long long int sumN_RS;
        int beginRange;
        int endRange;
        int combinations;
        int SIZE_OF_ARRAY;
        vector<string> Answerlist;
        int pCount;
        int *range;
        int *rangeDuplicate; 
        short int position;
        vector <SubSet> correctList;
        vector<int> PeeCount;
    public:
        SumOfCubes();
        void DefineRange();
        virtual void produceCombinations(int arr[], int data[], const int &, const int &, const int &, const int &)=0;      
        virtual void kSetter(int arr[]) = 0;
        unsigned short int GetK_value();            
        virtual void xSetter(int arr[]) = 0;
        unsigned short int GetX_value();
        virtual void nSetter(int arr[]) = 0;
        unsigned short int GetN_value();
        virtual bool Boundaries() = 0;
        virtual bool calc_NBoundaries() = 0;
        virtual bool checkEquality() = 0;
        virtual unsigned long long int Summation_NLS() = 0;
        virtual unsigned long long int Summation_KLS() = 0;
        virtual unsigned long long int Summation_KRS() = 0;
        virtual unsigned long long int Summation_NRS() = 0;
        virtual unsigned long long int X_valueLS()=0;
        virtual unsigned long long int Right_HSquare() = 0;
        void ListOfSolutions(const int &, const int &, const int &);
        void Print();
        void GetHighestPCount(unsigned int &);
        int GetPCount(unsigned int &i);
        void EmptyVector();
        void deletePointerArray();
        bool FindPattern(unsigned int &);
};

#endif