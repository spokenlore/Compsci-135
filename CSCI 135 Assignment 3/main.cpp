#include "DNA.h"

int main(int argc, char* argv[]){

    //DNA Sequencer;
    // To test mutation 1 and 2
    //char sequence[10] = {'G','A','T','T','A','C','A'};
    // To test mutation 3
    //char sequence[20] = {'G','A','T','T','T','A','T','T','C','A','T','T','T'};
    // To Test mutation 4
    // char sequence[20] = {'G','A','G','G','G','T','T','T','C','G','G','G','A','A'};
    // To Test Mutation 5
    //char sequence[20] = {'G','G','A','T','C','A','T','A','T','C'};

    DNA Sequencer;

    std::string inputname = argv[1];
    std::string mutationsname = argv[2];
    std::string outputname = argv[3];


      Sequencer.Sequencer(inputname, mutationsname, outputname);



    // Sequencer.displaysequence(sequence);
    // Sequencer.getoriginalsequence(sequence);
    // Sequencer.displaysequence(sequence);
    // Sequencer.mutation4(sequence);
    // Sequencer.displaysequence(sequence);
    // cout << Sequencer.comparesequences(sequence, sequence);

    return 1;
}
