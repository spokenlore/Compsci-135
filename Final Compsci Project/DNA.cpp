#include "DNA.h"

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <istream>

using namespace std;

// Main call function of class DNA
void DNA::Sequencer(){
    fstream source;
    source.open("sources.txt");

    fstream mutations;
    mutations.open("mutations.txt");

    while (!source.eof()){

        char originalsequence[80];
        char mutatedsequence[80];

        // "Constructor setup functions"

        DNA::cleararray(originalsequence);
        DNA::cleararray(mutatedsequence);

        // Input mutation and original sequence
        source >> originalsequence;
        mutations >> mutatedsequence;

        DNA::mutate(originalsequence, mutatedsequence);

        // For testing
        /*
        Sequencer.displaysequence(originalsequence);
        Sequencer.mutation4(originalsequence);
        Sequencer.displaysequence(originalsequence);
        Sequencer.mutation5(originalsequence);
        Sequencer.displaysequence(originalsequence);
        Sequencer.mutation5(originalsequence);
        Sequencer.displaysequence(originalsequence);
        Sequencer.mutation3(originalsequence);
        Sequencer.displaysequence(originalsequence);
        Sequencer.mutation4(originalsequence);
        Sequencer.displaysequence(originalsequence);
        Sequencer.mutation5(originalsequence);
        Sequencer.displaysequence(originalsequence);
        Sequencer.displaysequence(mutatedsequence);
        */
    }
}

// Mutation Function
int DNA::mutate(char sequence[], char sequence2[]){
char tempsequence[80];

ofstream output;
output.open("output.txt", ios::app);

output << endl;

// Looping for sequence mutations

for (int a = 0; a < 6; a++){
    for (int b = 0; b < 6; b++){
        for (int c = 0; c < 6; c++){DNA::inputsequence(sequence, tempsequence);
            for (int d = 0; d < 6; d++){
                for (int e = 0; e < 6; e++){
                        for(int f = 0; f < 6; f++){
                            for(int g = 0; g < 6; g++){
                                for(int h = 1; h < 6; h++){
                                    DNA::cleararray(tempsequence);
                                    DNA::inputsequence(sequence, tempsequence);
                                    usemutation(a, tempsequence);
                                    usemutation(b, tempsequence);
                                    usemutation(c, tempsequence);
                                    usemutation(d, tempsequence);
                                    usemutation(e, tempsequence);
                                    usemutation(f, tempsequence);
                                    usemutation(g, tempsequence);
                                    usemutation(h, tempsequence);
                                    if (DNA::comparesequences(sequence2, tempsequence)){
                                        output << "Sequence: ";
                                        output.close();
                                        DNA::outputsequence(sequence2);
                                        output.open("output.txt", ios::app);
                                        output << endl << "was mutated to";
                                        output.close();
                                        DNA::outputsequence(tempsequence);
                                        output.open("output.txt", ios::app);
                                        output << endl << "The correct mutation sequence is: "
                                            << a << ' ' << b << ' ' << c << ' ' << d << ' '
                                            << e << ' ' << f << ' ' << g << ' ' << h << endl;
                                        output.close();
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
output.close();
DNA::outputsequence(sequence);
output.open("output.txt", ios::app);
output << endl << "was unable to be mutated to:";
output.close();
DNA::outputsequence(sequence2);

}

//ATTACAG
void DNA::mutation1(char sequence[]){
    char temp = sequence[0];
    int size = DNA::calcsequencelength(sequence);
    for (int i=0; i < (size - 1); i++){
        sequence[i] =  sequence[i+1];
    }
    sequence[size - 1] = temp;
}
//AGATTAC
void DNA::mutation2(char sequence[]){
    int size = DNA::calcsequencelength(sequence);
    char temp = sequence[size-1];
    for (int i = (size-1); i > 0; i--){
        sequence[i] = sequence[i-1];
    }
    sequence[0] = temp;
}

void DNA::mutation3(char sequence[]){
    int size = DNA::calcsequencelength(sequence);
    int TTT1 = -1, TTC1 = -1, TTT2 = -1, TTC2 = -1;
    for (int i = 0; i < (size - 2); i++){
    char temp1 = sequence[i];
    char temp2 = sequence[i+1];
    char temp3 = sequence[i+2];
    if(temp1 == 'T' and temp2 == 'T' and temp3 == 'T' and TTT1 == -1)
        TTT1 = i;
    if(temp1 == 'T' and temp2 == 'T' and temp3 == 'T')
        TTT2 = i;
    if(temp1 == 'T' and temp2 == 'T' and temp3 == 'C' and TTC1 == -1)
        TTC1 = i;
    if(temp1 == 'T' and temp2 == 'T' and temp3 == 'C')
        TTC2 = i;
    }
    if (TTT1 > 0){
        sequence[TTT1] = 'T';
        sequence[TTT1+1] = 'T';
        sequence[TTT1+2] = 'C';
        sequence[TTT2] = 'T';
        sequence[TTT2+1] = 'T';
        sequence[TTT2+2] = 'C';
    }
    if (TTC1 > 0){
        sequence[TTC1] = 'T';
        sequence[TTC1+1] = 'T';
        sequence[TTC1+2] = 'T';
        sequence[TTC2] = 'T';
        sequence[TTC2+1] = 'T';
        sequence[TTC2+2] = 'T';
    }
}

void DNA::mutation4(char sequence[]){
    int size = DNA::calcsequencelength(sequence);
    int GGG1 = -1, GGG2 = -1;
    for (int i = 0; i < (size - 2); i++){
    char temp1 = sequence[i];
    char temp2 = sequence[i+1];
    char temp3 = sequence[i+2];
    if(temp1 == 'G' and temp2 == 'G' and GGG1 == -1)
        GGG1 = i+2;
    if(temp1 == 'G' and temp2 == 'G')
        GGG2 = i+2;
    }
    if (GGG1 > 0 and GGG2 != GGG1 and GGG2 != (GGG1+1)){
        DNA::shiftfor4(sequence, GGG1);
        DNA::shiftfor4(sequence, GGG2-1);
    }
    if (GGG1 > 0 and (GGG2 == GGG1 or GGG2 == GGG1+1)){
        DNA::shiftfor4(sequence, GGG1);
    }
}

// Fixes array after use of mutation 4 (Necessary for 4 to work properly)
void DNA::shiftfor4(char sequence[], int element){
    int size = DNA::calcsequencelength(sequence);
        char temp = sequence[size-1];
    for (int i = element; i < (size - 2); i++)
    {
        sequence[i] = sequence[i+1];
    }
    sequence[size-1] = '\0';
    sequence[size-2] = temp;
}

void DNA::mutation5(char sequence[]){
    int size = DNA::calcsequencelength(sequence);
    int ATX1 = -1, ATX2 = -1;
    for (int i = 0; i < (size - 2); i++){
    char temp1 = sequence[i];
    char temp2 = sequence[i+1];
    char temp3 = sequence[i+2];

    if(temp1 == 'A' and temp2 == 'T' and temp3 != 'G' and ATX1 == -1)
        ATX1 = i+3;
    if(temp1 == 'A' and temp2 == 'T' and temp3 != 'G')
        ATX2 = i+3;
    }
    if (ATX1 > 0 and ATX2 != ATX1){
        DNA::shiftfor5(sequence, ATX1);
        DNA::shiftfor5(sequence, ATX2+1);
    }
    if (ATX1 > 0 and ATX2 == ATX1){
        DNA::shiftfor5(sequence, ATX1);
    }
    }

// Fixes array after use of mutation 5 (Necessary for 5 to work properly)
void DNA::shiftfor5(char sequence[], int element){
    int size = DNA::calcsequencelength(sequence);
    for (int i = size; i > element; i--)
    {
        sequence[i] = sequence[i-1];
    }
    sequence[element] = 'T';
    }

void DNA::displaysequence(char sequence[]){
    cout << endl;
    int i = 0, length = DNA::calcsequencelength(sequence);
    while (i < length){
        cout << sequence[i];
        i++;
    }
    cout << endl;
}

// Tests for equivalency of two arrays
bool DNA::comparesequences(char sequence1[], char sequence2[]){
    int size = DNA::calcsequencelength(sequence1);
    int size2 = DNA::calcsequencelength(sequence2);
    if (size != size2)
        return false;
    for (int i = 0; i < size; i++)
        {
            if (sequence1[i] != sequence2[i])
                return false;
        }
    return true;
}

// Calculates length of char array
int DNA::calcsequencelength(char sequence[]){
    int i = 0;
    while (sequence[i] == 'A' or sequence[i] == 'C' or sequence[i] == 'T' or sequence[i] == 'G')
        i++;
    return i;
    }

// Changes sequence 2 to be equivalent to sequence

void DNA::inputsequence(char sequence[], char sequence2[]){
    int size = DNA::calcsequencelength(sequence);
    for (int i = 0; i < size; i++)
    {
        sequence2[i] = sequence[i];
    }
    }

// Outputs sequence to end of text file
void DNA::outputsequence(char sequence[]){
    ofstream output;
    output.open("output.txt", ios::app);
    output << endl;
    int i = 0, length = DNA::calcsequencelength(sequence);
    while (i < length){
        output << sequence[i];
        i++;
    }
    output.close();
}

// Empties target array
void DNA::cleararray(char sequence[]){
    int size = calcsequencelength(sequence);
    for (int i = 0; i < (size - 1); i++)
        sequence[i] = '\0';
    }

int DNA::usemutation(int mutation, char sequence[]){
    if (mutation == 5){
        DNA::mutation5(sequence);
    }
    if (mutation == 4){
        DNA::mutation4(sequence);
    }
    if (mutation == 3){
        DNA::mutation3(sequence);
    }
    if (mutation == 2){
        DNA::mutation2(sequence);
    }
    if (mutation == 1){
        DNA::mutation1(sequence);
    }
}
