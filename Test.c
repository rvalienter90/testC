/*
 ============================================================================
 Name        : Test.c
 Author      : Rodolfo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "test.h"


int main(void) {
	puts("!!!Hello World!!!");
	sig_int();
	//printf("%d", myPI);
	test_sscanf();
	//sprintf_sscanf();
	return EXIT_SUCCESS;
}

void sig_int(){
	printf("Ok\n");
}

void test_sscanf(){
	/*int sscanf ( const char * s, const char * format, ...);
	Read formatted data from string*/

	  char sentence []="Rudolph ss 12 years old";
	  char str [20], str2 [20];
	  int i=0;


	  int convertions=0;
	  convertions=sscanf (sentence +5,"%s %s %d",str,str2, &i);
	  printf("Convertions %d\n",convertions);
	  printf ("%s -> %d\n",str,i);
	  i=0;


	  convertions=sscanf (sentence,"%s %s %d",str,str2, &i);
	  printf("Convertions %d\n",convertions);
	  printf ("%s -> %d\n",str,i);
	  i=0;

	  /*
	  //will wait for assigne a value to str2
	  convertions=sscanf (sentence,"%s %s %d",str, &i);
	  printf("Convertions %d\n",convertions);
	  printf ("%s -> %d\n",str,i);
	  i=0;*/

	  convertions=sscanf (sentence,"%s %d",str,&i);
	  printf("Convertions %d\n",convertions);
	  printf ("%s -> %d\n",str,i);
	  i=0;

	  convertions=sscanf (sentence,"%s %*s %d",str,&i);
	  printf("Convertions %d\n",convertions);
	  printf ("%s -> %d\n",str,i);
}

void test_sprintf(){
	/*
	 int sprintf ( char * str, const char * format, ... );
	Write formatted data to string
*/
	  char buffer [50];
	  int n, a=5, b=3;
	  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
	  printf ("[%s] is a string %d chars long\n",buffer,n);

}

void sprintf_sscanf(){
	  char buffer [50];
	  int n, a=5, b=3;
	  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
	  printf ("[%s] is a string %d chars long\n",buffer,n);


	  int a1,b1,c1,convertions;

	  convertions=sscanf (buffer,"%d %*s %d %*s %d",&a1,&b1,&c1);
	  printf("Convertions %d\n",convertions);
	  printf ("Read from buffer a=%d  b=%d  a+b=%d \sprintf_sscanfn",a1,b1,c1);



}
