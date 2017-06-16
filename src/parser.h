#ifndef _PARSER
#define _PARSER

#include <iostream>
#include <string>
#include <fstream>
#include <boost/program_options.hpp>


typedef struct {
	/* Parameters contained in the parameters file. */
	int nb_test;
	int sizex;
	int sizey;
	int sizez;
	double dx;
	double dy;
	double dz;
	int correl_type;
	int generation_type;
	double correlation_length;
	double length_x;
	double length_y;
	double length_z;
	double beta;
	double cutoff_scale;
	bool periodic;
	std::string directory;
	unsigned int write_field;
} coefficients;


void print_parameters(boost::program_options::variables_map varmap);


void init_param(coefficients *coeff, const char *filename);


#endif