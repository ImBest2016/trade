#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "utility.h"
#include "datatype.h"

/*
unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}
*/


TEST_CASE( "Teset for class TimeTrans", "TimeTrans") {
    {//test time trans
        struct tm thet;
        time_t t = time(0);

        struct tm * stm = localtime(&t);    

        //1900-01-01 00:00:00
        thet.tm_year = 2016 - 1900;
        thet.tm_mon  = 0;
        thet.tm_mday = 1;
        thet.tm_sec = 0;
        thet.tm_min = 0;
        thet.tm_hour = 0;
        thet.tm_wday = 5;
        thet.tm_yday = 0;
        
        t = mktime(&thet);
        
        REQUIRE( t ==  1451577600 );
        
        std::cout << "test for get day int\n";
        int a = TimeTrans::get_day_int(t);
        REQUIRE( a == 20160101 );
        a = TimeTrans::get_day_int(t + 10023);
        REQUIRE( a == 20160101 );
        a = TimeTrans::get_day_int(t + 1243);
        REQUIRE( a == 20160101 );
        a = TimeTrans::get_day_int(t + 100);
        REQUIRE( a == 20160101 );
    }    
    
    {//test read market data
        
    }
}
