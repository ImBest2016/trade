/*
 * utility.h
 *
 *  Created on: 2015Äê12ÔÂ24ÈÕ
 *      Author: Gimme
 */

#ifndef __UTILITY_H_INCLUDE__
#define __UTILITY_H_INCLUDE__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <math.h>
#include <float.h>
#include <limits.h>

#include <time.h>
#include <errno.h>

#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/types.h>


using namespace std;


class TimeTrans {
public:
	static int    get_day_int(time_t thet = 0);
	static time_t get_zeor_of_theday();
	static time_t make_time_in_same_day(const char * day, const char * strt);
	static time_t make_time_in_same_day(time_t zero, const char * strt);
	static time_t make_time_in_same_day(time_t zero, char * strt);

	static char * get_timenow(char * buf, int maxlen);
	static char * get_time_str(char * buf, int maxlen, time_t tt);
	static char * get_time_str(char * buf, int maxlen, double tt);
	static char * get_day_str(char * buf, int maxlen, time_t tt);

	static char * get_today_str(char * buf, int maxlen);
	static time_t make_the_time(time_t tt, int hour = 0, int min = 0, int sec = 0);
	static time_t make_the_time(char * day, char * tt);

	static time_t make_time_in_same_day(time_t tt, int hour = 0, int min = 0, int sec = 0);
	static time_t make_time_inday(const char * day, int hour = 0, int min = 0, int sec = 0);

	static time_t get_minute(time_t the_time);
	static time_t get_time_from_int_format_day(unsigned int day);

	static char * time_str_2_excel(char * buf, int maxlen, time_t tt);
    static time_t excel_str_2_time(const char* buf);
    static time_t get_zeor_of_theday(double tt);
};




typedef struct TIMESEGMENT {
    time_t st1;
    time_t et1;
    time_t st2;
    time_t et2;

    TIMESEGMENT() : st1(0), et1(0), st2(0), et2(0) {}
    TIMESEGMENT(time_t first) {
        set_time_sec(first);
    }
    bool not_init() { return (et1 == 0); }
    void set_time_sec(time_t t) {
        st1 = TimeTrans::make_time_in_same_day(t,  9, 15),
        et1 = TimeTrans::make_time_in_same_day(t, 11, 30),
        st2 = TimeTrans::make_time_in_same_day(t, 13, 00),
        et2 = TimeTrans::make_time_in_same_day(t, 15, 15);
    }
    bool in_time_sec(time_t t) {
        return ((t >= st1 && t <= et1) || (t >= st2 && t <= et2));
    }
    void operator = (time_t t)
    {
        set_time_sec(t);
    }

} TIMESEGMENT;



#endif /* __UTILITY_H_INCLUDE__ */
