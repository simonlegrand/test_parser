#include "parser.h"


void main(int argc, char* argv[]){
	
	using namespace std;
	try {
		// The parameter file has to passed as a command line option
		if (argc == 1) {
			cout << "Error: You have to pass a parameter file as a command line option." << endl;
			exit(-1);
		}
	
		coefficients cfg; // Struct containing parameters
		init_param(&cfg, argv[1]);
		
		// Access to parameters
		cout << "beta=" << cfg.beta << endl;
	}
	catch (std::exception& E)
	{
		std::cout << E.what() << std::endl;
	}
}