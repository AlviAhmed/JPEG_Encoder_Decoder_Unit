#include "systemc.h"
#include <math.h>

#ifndef IDCT_H
#define IDCT_H

struct idct : sc_module{ 

	sc_out<char> out64_idct[8][8]; // the idct transformed 8x8 block
	sc_in<double> fcosine[8][8]; // same cosine table as before
	sc_in<bool> clk; // clock signal 
	
	//sc_out<FILE *> sc_output_idct; // as the IDCT finishes will need to output a file

	char output_data[8][8]; // the data outputed to the file

	sc_in<double>  input_64[8][8];


	void calculate_idct( void ); // perform idct transform 

	// define idct as a constructor
	SC_CTOR( idct ) { 
          //NOTE, DOUBLE CHECK WHETHER OR NOT CLOCK HAS TO BE OPPOSITE OF FDCT
		// make read_data method sensitive to the positive clock edge, and
		// the calculate_dct method sensitive to the negative clock edge
		// this way, the entire read and performing dct takes only one clock cycle
		// as apposed to two
		

		SC_METHOD( calculate_idct ); // define calculate_dct as a method
		dont_initialize();
		sensitive << clk.pos();
	}






};

#endif
