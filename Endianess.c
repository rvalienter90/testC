/*
 * Endianess.c
 *
 *  Created on: Nov 15, 2018
 *      Author: rodolfo
 */

#include <stdio.h>
#include <byteswap.h>
#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#define swap(a) bswap_16(a)

#define mytype int
#define specifier "%d"

double ReverseDouble( double indouble );
long int ReverseLong( long int  indouble );
mytype ReverseType( mytype  value );
void check_endian();
int main(int argc, char **argv) {


   mytype  ili=-1;
   printf("data li "specifier ", %X\n",ili,ili);

   mytype  ibi=ReverseType(ili) ;
   printf("data bi "specifier ", %X\n",ibi,ibi);

   int m =2147483648;
   printf("unsigned %u\n",m);
   printf("signed %d\n",m);

   /*
   u_int16_t i=1;
   printf("data %d\n",i);
   u_int16_t j= swap(i);
   printf("data %d\n",j);

   double x=log(2.7);
   printf("size of double %lu\n",sizeof(x));
   printf("data%lf\n",x);
   unsigned long p=(unsigned long )x;
   printf("size of unsig long %lu\n",sizeof(p));
   printf("data%lf\n",p);



   double li=log(2.7);
   printf("data li %lf\n",li);

   double bi=ReverseDouble(li);
   printf("data bi %lf\n",bi);




   float x1=log(2.7);
   printf("size%lu\n",sizeof(x1));
   printf("data%f\n",x);
   unsigned int p1=(unsigned int )x1;
   printf("size%lu\n",sizeof(p1));
   printf("data%u\n",p1);


*/

   exit(0);
}


double ReverseDouble( double indouble )
{
   double retVal;
   char *doubleToConvert = ( char* ) & indouble;
   char *returndouble = ( char* ) & retVal;

   // swap the bytes into a temporary buffer
   int i;
   for (i=0; i<8 ;i++)
   returndouble[i] = doubleToConvert[8-i-1];

   return retVal;
}

long int ReverseLong( long int  value )
{
	long int  retVal;
   char *doubleToConvert = ( char* ) & value;
   char *returndouble = ( char* ) & retVal;

   // swap the bytes into a temporary buffer
   int i;
   for (i=0; i<sizeof(value) ;i++)
   returndouble[i] = doubleToConvert[8-i-1];

  return  retVal;
}


mytype ReverseType( mytype  value )
{
	printf("Size %d\n",sizeof(value));
	mytype  retVal;
   char *doubleToConvert = ( char* ) & value;
   char *returndouble = ( char* ) & retVal;

   // swap the bytes into a temporary buffer
   int i;
   for (i=0; i<sizeof(value) ;i++)
   returndouble[i] = doubleToConvert[sizeof(value) -i-1];

  return  retVal;
}

void check_endian(){
	  union {
	      short s;
	      char c[sizeof(short)];
	   }un;

	   un.s = 0x0102;

	   if (sizeof(short) == 2) {
	      if (un.c[0] == 1 && un.c[1] == 2)
	         printf("big-endian\n");

	      else if (un.c[0] == 2 && un.c[1] == 1)
	         printf("little-endian\n");

	      else
	         printf("unknown\n");
	   }
	   else {
	      printf("sizeof(short) = %d\n", sizeof(short));
	   }


}
