#include <stdio.h>

//#include "libs/utils.h"
//#include "libs/callbacks.h"
#include "parser.h"
int main() {
    printf("Hello, World!\n");
        testparcer();
     //test_callback();
    //test_numbers();
    return 0;
}

void test_numbers(){
    long double s_to_us= 1000000;
    long double diff;
    /*long double a=21.0083168;
    long double b=21.0083168;
    diff=(a*s_us-b*s_us-56);*/

    int AIFS=58;
    long double current =20.9982440000000000046;
    long double tx_end =20.9982250000000000047;
    long double tx_interval=545.999999999999061639;

    long double a=20.9982440000000000046;
    long double b=20.9983020000000000053;
    diff=(a/s_to_us-b/s_to_us);

    //std::cout << "diff " << diff << "  a: "<<a <<"  b: "<<b <<std::endl;

    long double gap_after_tx = (current*s_to_us - tx_end*s_to_us - AIFS);
    //std::cout << "gap_after_tx  " << gap_after_tx  <<std::endl;
    //test round
    //std::cout << roundl(2.49) <<std::endl;

    tx_end = current + (tx_interval/s_to_us) ;
    //std::cout << "tx_end  " << tx_end <<std::endl;
}