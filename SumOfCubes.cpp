
#include "SumOfCubes.h"

SumOfCubes::SumOfCubes() 
: SubSet(0, 0, 0), k(0), x(0), n(0), sumK_LS(0), 
sumN_LS(0), sumK_RS(0), sumN_RS(0), 
beginRange(0), endRange(0), combinations(3), 
SIZE_OF_ARRAY(0), Answerlist(0), pCount(2), range(nullptr), 
rangeDuplicate(nullptr), position(0) {}

//Function to define range of numbers
//Good!
void SumOfCubes::DefineRange(){
    cout << "Please enter the low-end of the range: ";
    cin >> this->beginRange;
    cout << endl;
    cout << "Please enter the high-end of the range: ";
    cin >> this->endRange;
    cout << endl;
    long double size = ((this->endRange - this->beginRange) + 1);
    SIZE_OF_ARRAY = size;
    range = new int[SIZE_OF_ARRAY];
    for(unsigned int i = 0; i < SIZE_OF_ARRAY; ++i){
        range[i] = this->beginRange;
        this->beginRange++;
    }
    cout << endl;
    rangeDuplicate = new int[combinations];
    size = SIZE_OF_ARRAY - 1;        
    produceCombinations(range, rangeDuplicate, 0, size, 0, combinations);
}

//Function to return k value
unsigned short int SumOfCubes::GetK_value(){
    return this->k;
}

//Function to return x value
unsigned short int SumOfCubes::GetX_value(){
    return this->x;
}

//Function to get n value
unsigned short int SumOfCubes::GetN_value(){
    return this->n;
}

//Function to store correct answers in vector
void SumOfCubes::ListOfSolutions(const int &k_value, const int &x_value, const int &n_value){

    SubSet correct(k_value, x_value, n_value);
    correctList.push_back(correct);

}

void SumOfCubes::Print(){

    int iPCount;
    int jPCount;
    int location;
    int HighestPCount;
    int tabSpaces(1);

    ostringstream str1;
    string finalString;

    for(unsigned int i = 0; i < correctList.size(); ++i){
        GetHighestPCount(i);;
    }

    HighestPCount = pCount;
    pCount = 2;

    while(pCount < HighestPCount){
        cout << "When p = " << pCount << endl;
        str1 << "When p = " << pCount << endl;
        for(unsigned int i = 0; i < correctList.size(); ++i){
            if(GetPCount(i) == pCount){
                cout << "(" << correctList.at(i).KC << ", " << correctList.at(i).XC << ", " << correctList.at(i).NC << ")" << "\t";
                str1 << "(" << correctList.at(i).KC << ", " << correctList.at(i).XC << ", " << correctList.at(i).NC << ")" << "\t";
                if(tabSpaces % 5 == 4){
                    cout << endl;
                    str1 << endl;
                    ++tabSpaces;
                }
                    ++tabSpaces;                
            }
        }
        ++pCount;
        tabSpaces = 1;
        cout << endl;
        str1 << endl;
    }
    
    finalString = str1.str();
    Answerlist.push_back(finalString);

}

inline void SumOfCubes::GetHighestPCount(unsigned int &i){

    int count = correctList.at(i).XC+correctList.at(i).KC - correctList.at(i). NC;
    if(count > pCount){
        pCount = count;
    } 
}

inline int SumOfCubes::GetPCount(unsigned int &i){

    int count = correctList.at(i).XC+correctList.at(i).KC - correctList.at(i). NC;
    return count;
}

void SumOfCubes::EmptyVector(){
    pCount = 0;
    correctList.clear();
    Answerlist.clear();
}

void SumOfCubes::deletePointerArray(){
    delete [] range;
    range = nullptr;
    delete [] rangeDuplicate;
    rangeDuplicate = nullptr;
}

inline bool SumOfCubes::FindPattern(unsigned int &s){
    int checkN = correctList.at(s).NC;
    int theorem = (checkN*checkN+checkN + 1);
    if(theorem % 7 == 0){
        return true;
    }
    else{
        return false;
    }
}