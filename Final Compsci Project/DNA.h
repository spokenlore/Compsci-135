#ifndef DNA_H_INCLUDED
#define DNA_H_INCLUDED

#include "DNA.h"

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <istream>

class DNA
    {
    private:
        void inputsequence(char sequence[], char sequence2[]);
        void mutation1(char sequence[]);
        void mutation2(char sequence[]);
        void mutation3(char sequence[]);
        void mutation4(char sequence[]);
        void shiftfor4(char sequence[], int element);
        void mutation5(char sequence[]);
        void shiftfor5(char sequence[], int element);
        bool comparesequences(char sequence1[], char sequence2[]);
        int calcsequencelength(char sequence[]);
        int usemutation(int mutation, char sequence[]);
    public:
        void Sequencer();
        void displaysequence(char sequence[]);
        void outputsequence(char sequence[]);
        void cleararray(char sequence[]);
        int mutate(char sequence[], char sequence2[]);
    };

#endif // DNA_H_INCLUDED
