#include "parser.h"

using namespace std;


void print_parameters(boost::program_options::variables_map varmap) {
	
	cout << "**** Parameters list ****" << endl;
	for (const auto& it : varmap) {
		cout << it.first.c_str() << "=";
		auto& value = it.second.value();
		if (auto v = boost::any_cast<double>(&value))
			cout << *v << endl;
		else if (auto v = boost::any_cast<string>(&value))
			cout << *v << endl;
		else if (auto v = boost::any_cast<int>(&value))
			cout << *v << endl;
		else if (auto v = boost::any_cast<unsigned int>(&value))
			cout << *v << endl;
		else if (auto v = boost::any_cast<bool>(&value))
			cout << *v << endl;
		else
			cout << "error" << endl;
	}
	cout << "**** End of parameters list ****" << endl;
}


void init_param(coefficients *coeff, const char *filename){
	
	ifstream Config_File(filename);
	if(!Config_File){
		cout << "Error: The program failed opening the file." << endl;
		exit(-1);
	}

	namespace po = boost::program_options;
	po::options_description config;
	config.add_options()
		("nb_test", po::value<int>(&coeff->nb_test))
		("sizex", po::value<int>(&coeff->sizex))
		("sizey", po::value<int>(&coeff->sizey))
		("sizez", po::value<int>(&coeff->sizez))
		("dx", po::value<double>(&coeff->dx))
		("dy", po::value<double>(&coeff->dy))
		("dz", po::value<double>(&coeff->dz))
		("correl_type", po::value<int>(&coeff->correl_type))
		("generation_type", po::value<int>(&coeff->generation_type))
		("correlation_length", po::value<double>(&coeff->correlation_length))
		("length_x", po::value<double>(&coeff->length_x))
		("length_y", po::value<double>(&coeff->length_y))
		("length_z", po::value<double>(&coeff->length_z))
		("beta", po::value<double>(&coeff->beta))
		("cutoff_scale", po::value<double>(&coeff->cutoff_scale))
		("periodic", po::value<bool>(&coeff->periodic))
		("directory", po::value<string>(&coeff->directory))
		("write_field", po::value<unsigned int>(&coeff->write_field))
		;

	po::variables_map vm;
	store(po::parse_config_file(Config_File, config), vm);
	print_parameters(vm);
	notify(vm);
}