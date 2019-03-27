/*
 * test.h
 *
 *  Created on: Nov 13, 2018
 *      Author: rodolfo
 */

#ifndef TEST_H_
#define TEST_H_

#define myPI 3
void sig_int();
typedef struct bsm {
	int id;
	long double tx_time;
	long double lat;
	long double lon;
	long double alt;
	long double speed;
	int coll_flag;
	int bkoff_count;
	long double mac_delay;
	double txPower;
	double rxPower;
} my_bsm ;


#ifdef  macro1
printf( "Hello!\n" );
#endif



#endif /* TEST_H_ */
