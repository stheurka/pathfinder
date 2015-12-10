/*
 * L293D.h
 *
 *  Created on: 06-Dec-2015
 *      Author: sagar
 */

#ifndef L293D_H_
#define L293D_H_

#define ENABLE_P12  "L293D_EN12"
#define ENABLE_P34	"L293D_EN34"
#define INP1 		"L293D_A1"
#define INP2 		"L293D_A2"
#define INP3 		"L293D_A3"
#define INP4 		"L293D_A4"

#define L293D_NORMALMODE 0
#define L293D_PWMMODE 	 1

#define MAX_CHARS_PER_LINE = 512
#define  DELIMITER  = " "

class L293D
{
private:
	//String constants to be used for parsing the configuration file.
	int enable_p12;
	int inp_p1;
	int inp_p1_state;
	int inp_p2;
	int inp_p2_state;

	int enable_p34;
	int inp_p3;
	int inp_p3_state;
	int inp_p4;
	int inp_p4_state;

	int range1;
	int range2;
	L293D();
public:
	//Constructors

	//unit : 0 - Use 1,2EN, 1A and 2A pins.
	//unit : 0 - Use 3,4EN, 3A and 4A pins.
	//Refer L293D manual to know what are EN and A pins.
	L293D(int enable, int inp1, int inp2, int unit, int mode);

	L293D(int en12, int inp1, int inp2, int mode12, int en34, int inp3, int inp4, int mode34);

	//filepath - absolute/relative path to the config file.
	//the file must contain pin configuration following the nomenclature defined in the constants region
	L293D(char * filepath);
	//Constructors end

	//Initializers
	void initialize_unit1(int en12, int inp1, int inp2, int mode);
	void initialize_unit2(int en34, int inp3, int inp4, int mode);
	void intialize(int en12, int inp1, int inp2, int mode12, int en34, int inp3, int inp4, int mode34);
	void intialize(char * filepath);

	//Access functions

	//Only for normal mode
	void enable_unit1();
	void enable_unit2();
	void disable_unit1();
	void disable_unit2();
	//

	//Only for pwm mode
	void set_range_unit1(int range);
	void set_range_unit2(int range);
	//

	void set_pin1();
	void set_pin2();
	void set_pin3();
	void set_pin4();

	void reset_pin1();
	void reset_pin2();
	void reset_pin3();
	void reset_pin4();

	int read_pin1();
	int read_pin2();
	int read_pin3();
	int read_pin4();
	int get_range1();
	int get_range2();

	virtual ~L293D();
};

#endif /* L293D_H_ */
