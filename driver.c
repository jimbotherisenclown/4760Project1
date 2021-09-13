//Benjamin West 
//4760Project 1
//Fall Semester 2021

#include <stdlib.h>       //Basic library
#include <stdio.h>        //Used for print functions
#include <stdbool.h>      //Used for bool expressions
#include <getopt.h>       //Used for getopt codes
#include <ctype.h>        //Used for isdigit function


const char *programName = NULL;

/**************************************
* FUNC - testOptCode                  *
* Takes in opcodes and evaluates them *
**************************************/
void testOptCode(int argc, char *argv[]) {

	bool testBool = true;
	
	//Process opcodes
	while (testBool) {

		//Take in user arguments, and break when all opcodes and corresponding options have been processed	
		int userArg = getopt(argc, argv, "ht:");
		if (userArg == -1) break;
		
		switch(userArg) {
			case 'h':
				helpMessage(EXIT_SUCCESS); 
			case 't':
				if (isdigit(*optarg)) {
					//Zhu Li, do the thing!
				} else {
					//print an error
				}
				break;
			default:
				testBool = false;
		}
	}
}

/************************
* Sets the program name *
************************/
void setProgramName(const char *passedArg) {
	programName = passedArg;
}

/************************************************
* Prints the help message and exits the program *
************************************************/
int helpMessage(int exitStatus) {
	if (exitStatus == EXIT_SUCCESS) {
		printf("\ndriver.c\n");
		printf("Sends log messages to an output file. By default, the output file\n");
		printf("is titled messages.log and can be parsed as plain text.\n");
		printf("USAGE:\n");
		printf("   -h         : Produces this help message\n");
		printf("   -t sec     : Prints messages with an average delay of sec seconds\n");
		printf("   [filename] : Saves output log messages to given filename\n");			
	} else {
		perror("Invalid input. Use '%s -h' for help info.");
	}	
	exit(exitStatus);

}

/*******
* MAIN *
*******/
int main(int argc, char **argv) {
    setProgramName(argv[0]);

    //char tempInputFile[40];

    //Checks that multiple arguments have been presented
    switch(argc) {
        case 1 :
            //Send messages to logger and save messages in file called messages.log
            printf("No arguments detected.\n");
            break;
        case 2 :
			printf("1 argument detected. Parsing arguments...\n");
			testOptCode(argc, argv);
            break;
        case 3 :
			printf("2 arguments detected. Parsing arguments...\n");
            testOptCode(argc, argv);
            break;
        case 4 :
			printf("3 arguments detected. Parsing arguments...\n");
            testOptCode(argc, argv);
            break;
        case 5 :
			printf("4 arguments detected. Parsing arguments...\n");
            testOptCode(argc, argv);
            break;
        default:
            perror("Too many arguments presented to properly parse.");
			exit(EXIT_FAILURE);
    }
	
	printf("Reached the end of main\n");
	printf("Main end:", argv[0], argv[1]);
	return 0;
}

