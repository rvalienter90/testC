//
// Created by nsl on 11/12/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

//cfp_open
# define MAX_LINE_LENGTH 100
FILE *fptr;
char *sep = "=;, ";
char * token[5];
int  tokens[20];
/* Removes all whitespace from a string.
 * Used by readConfig()
 */
void strip_whitespace(char * str)
{
    char *writeptr = str, *readptr = str;

    for (readptr = writeptr = str; *readptr; ++readptr)
    {
        if (*readptr != ' ' && *readptr != '\n'&& *readptr != '\t')
        {
            *writeptr = *readptr;
            ++writeptr;
        }
    }
    *writeptr = 0;
}

void testparcer(){
    printf("Hi there! How are you doing?");
    char z[MAX_LINE_LENGTH] = "I am learning C programming language.";

    printf("%s\n", z);

    fptr = fopen("/home/nsl/CLionProjects/testC/conf.txt","r");
    char buf[100];
    if(fptr == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }
    int token_number=0;
    memset(tokens, '\0', sizeof(tokens));
    while (!feof(fptr)) {
        // read the current line
        char * x = fgets((char *)buf, MAX_LINE_LENGTH - 1, fptr);
        if (x == NULL)
        {
            continue;
        }
        // Remove comments
        char * poundpos = index((char *) buf, '#');
        if (poundpos)
            *poundpos = '\0';


        // Remove spaces
        strip_whitespace((char *)buf);

        // If this is an empty line then skip it
        if (*buf == '\0')
            continue;


        int i = 0;


        memset(token, '\0', sizeof(token));
        // Get the first token
        token[i] = strtok(buf, sep);

        printf("%s\n",x);

        // If its NULL we have reached the end of the line
        while (token[i] != NULL)
        {
            // safely copy the data into the allocated buffer
            //strncpy(cur->item[i], token[i], strlen(token[i]));

            i++;

            // generate the next token in the line
            token[i] = strtok(NULL, sep);

        }
        tokens[token_number]=atoi(token[1]);
        token_number++;

    }
    printf("end");
}
