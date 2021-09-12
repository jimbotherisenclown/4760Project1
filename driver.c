//Benjamin West 
//4760Project 1
//Fall Semester 2021
#include <stdlib.h>       //Basic library
#include <stdio.h>        //Used for print functions
#include <stdbool.h>      //Used for bool expressions
#include <getopt.h>       //Used for getopt codes
#include <ctype.h>        //Used for isdigit function

int main(int argc, char **argv) { 
	bool testBool = true;
	
	while (testBool) {			
		int userArg = getopt(argc, argv, "ht:");
		if (userArg == -1) break;		
		switch(userArg) {
			case 'h':
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

int helpMessage(int exitStatus) {
	if (exitStatus == EXIT_SUCCESS) {
		printf("driver.c\n");
		printf("Sends ");
		printf("   -h     : Produces this help message\n");
		printf("   -t sec : Prints messages with an average delay of sec seconds\n");
		printf("   ");
			
	} else {

	}
	exit(exitStatus);

}
