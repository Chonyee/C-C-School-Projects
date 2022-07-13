//Author: Tony Pham, Date: 07/29/2021, Main Function
#include "functions.h"

int main(int argc, char** argv) {
  FILE *inputFilePointer;
  int inputFileCharacter;

//If just ./stats display usage menu
  if(argc == 1){
    helpme();
    return 0;

  } else if (argc == 2){
//If has infile argument, call function
    parseCommands(argc, argv, &inputFilePointer);
    return 0;

    } else if (argc == 3){
//if has outfile argument as well, call function
      parseCommands2(argc, argv, &inputFilePointer);
      return 0;
//catches anything else
      } else {
          printf("Error Try Again!");
          return 0;
      }
}

//difference between parseCommands and parseCommands2 is printf vs fprintf
