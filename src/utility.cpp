/*
 * utility.cpp
 *
 *  Created on: 2015年12月24日
 *      Author: Gimme
 */

#include "utility.h"

#define localtime_s(a, b) localtime_r(b, a)

//////////////////////////////////////////////////////////////////////////////////////////
// class TimeTrans
int TimeTrans::get_day_int(time_t thet)
{
	time_t tt = (thet) ? thet : time(0);
	struct tm lt;
	localtime_s(&lt, &tt);
	return ((lt.tm_year + 1900) * 10000 + (lt.tm_mon + 1) * 100 + lt.tm_mday);
}


time_t TimeTrans::get_zeor_of_theday()
{
	time_t tt = time(0);
	struct tm lt;
	localtime_s(&lt, &tt);
	lt.tm_hour = 0;
	lt.tm_min  = 0;
	lt.tm_sec  = 0;
	return mktime(&lt);
}

time_t TimeTrans::make_time_in_same_day(const char * day, const char * strt)
{
	long llt = atol(day);
	if (!llt)
		return (0);

	struct tm lt;

	lt.tm_year = (int)(llt / 10000) - 1900;
	lt.tm_mon  = (int)(llt - (lt.tm_year + 1900) * 10000)/100 - 1;
	lt.tm_mday = (int)(llt - (lt.tm_year + 1900) * 10000 - (lt.tm_mon + 1) * 100);

	sscanf(strt, "%d:%d:%d", &lt.tm_hour, &lt.tm_min, &lt.tm_sec);

	return mktime(&lt);
}

//12:10:13
time_t TimeTrans::make_time_in_same_day(time_t zero, const char * strt)
{
	int a, b, c;
	char * tmp = strdup(strt);
	char * s = strchr(tmp, ':');
	*s = 0;
	a = atoi(strt);
	char * t = s + 1;
	s = strchr(t, ':');
	*s = 0;
	b = atoi(t);
	t = s + 1;
	c = atoi(t);
	free(tmp);

	return (zero + a * 3600 + b * 60 + c);
}


time_t TimeTrans::make_time_in_same_day(time_t zero, char * strt)
{
	int a, b, c;
	char * s = strchr(strt, ':');
	*s = 0;
	a = atoi(strt);
	*s = ':';
	char * t = s + 1;
	s = strchr(t, ':');
	*s = 0;
	b = atoi(t);
	*s = ':';
	t = s + 1;
	c = atoi(t);

	return (zero + a * 3600 + b * 60 + c);
}

time_t TimeTrans::get_time_from_int_format_day(unsigned int day)
{
	struct tm lt;

	lt.tm_year = (int)(day / 10000) - 1900;
	lt.tm_mon  = (int)(day - (lt.tm_year + 1900) * 10000)/100 - 1;
	lt.tm_mday = (int)(day - (lt.tm_year + 1900) * 10000 - (lt.tm_mon + 1) * 100);
	lt.tm_hour = 0, lt.tm_min = 0, lt.tm_sec  = 1;

	return mktime(&lt);
}



char * TimeTrans::get_timenow(char * buf, int maxlen)
{
	time_t datetime = time(0);
	struct tm lt;
	localtime_s(&lt, &datetime);
	snprintf(buf, maxlen,
		"%04d%02d%02d-%02d%02d%02d",
		lt.tm_year + 1900,
		lt.tm_mon  + 1,
		lt.tm_mday,
		lt.tm_hour,
		lt.tm_min,
		lt.tm_sec);
	return buf;
}

char * TimeTrans::get_time_str(char * buf, int maxlen, double tt)
{
	return TimeTrans::get_time_str(buf, maxlen, (time_t)tt);
}

char * TimeTrans::get_time_str(char * buf, int maxlen, time_t tt)
{
	struct tm lt;
	localtime_s(&lt, &tt);
	snprintf(buf, maxlen,
		"%02d:%02d:%02d",
		//lt.tm_year + 1900,
		//lt.tm_mon  + 1,
		//lt.tm_mday,
		lt.tm_hour,
		lt.tm_min,
		lt.tm_sec);
	return buf;
}

char * TimeTrans::get_today_str(char * buf, int maxlen)
{
	time_t tt = time(0);
	struct tm lt;
	localtime_s(&lt, &tt);
	snprintf(buf, maxlen,
		"%04d%02d%02d",
		lt.tm_year + 1900,
		lt.tm_mon  + 1,
		lt.tm_mday);
	return buf;
}

char * TimeTrans::get_day_str(char * buf, int maxlen, time_t tt)
{
	struct tm lt;
	localtime_s(&lt, &tt);
	snprintf(buf, maxlen,
		//"%04d-%02d-%02d",
		"%04d%02d%02d",
		lt.tm_year + 1900,
		lt.tm_mon  + 1,
		lt.tm_mday);
	return buf;
}


time_t TimeTrans::make_time_in_same_day(time_t tt, int hour, int min, int sec)
{
	struct tm lt;
	localtime_s(&lt, &tt);
	lt.tm_hour = hour;
	lt.tm_min  = min;
	lt.tm_sec  = sec;
	return mktime(&lt);
}


time_t TimeTrans::make_time_inday(const char * day, int hour, int min, int sec)
{
	/// GET THE first time in YYYYMMDD
	long llt = atol(day);
	if (!llt)
		return (0);

	int y = (int)(llt / 10000);
	int m = (int)(llt - y * 10000)/100;
	int d = (int)(llt - y * 10000 - m * 100);

	struct tm lt;
	lt.tm_year = y - 1900;
	lt.tm_mon  = m - 1;
	lt.tm_mday = d;
	lt.tm_hour = hour;
	lt.tm_min  = min;
	lt.tm_sec  = sec;

	return mktime(&lt);
}

time_t TimeTrans::get_minute(time_t the_time)
{
	struct tm lt;
	localtime_s(&lt, &the_time);
	lt.tm_sec  = 0;
	return mktime(&lt);
}

time_t TimeTrans::make_the_time(time_t tt, int hour, int min, int sec)
{
	struct tm lt;
	localtime_s(&lt, &tt);
	lt.tm_hour = hour;
	lt.tm_min  = min;
	lt.tm_sec  = sec;
	return mktime(&lt);
}


//成交时期	 TradeDate	 20100906	 20100906
//成交时间	 TradeTime	 17:17:27	 17:17:50
time_t TimeTrans::make_the_time(char * day, char * tt)
{
	int llt = atoi(day);
	struct tm lt;

	lt.tm_year = (int)(llt / 10000) - 1900;
	lt.tm_mon  = (int)(llt - (lt.tm_year + 1900) * 10000)/100 - 1;
	lt.tm_mday = (int)(llt - (lt.tm_year + 1900) * 10000 - (lt.tm_mon + 1) * 100);

	char * s = strchr(tt, ':');
	*s = 0;
	lt.tm_hour = atoi(tt);
	*s = ':';
	char * t = s + 1;
	s = strchr(t, ':');
	*s = 0;
	lt.tm_min = atoi(t);
	*s = ':';
	t = s + 1;
	lt.tm_sec = atoi(t);

	return mktime(&lt);
}


char * TimeTrans::time_str_2_excel(char * buf, int maxlen, time_t tt)
{
	struct tm lt;
	localtime_s(&lt, &tt);
	snprintf(buf, maxlen,
		"%04d/%02d/%02d %02d:%02d:%02d",
		lt.tm_year + 1900,
		lt.tm_mon  + 1,
		lt.tm_mday,
		lt.tm_hour,
		lt.tm_min,
		lt.tm_sec);
	return buf;
}

/*
2/23/2012 9:50
2/27/2012 9:40
2/27/2012 14:40
2/29/2012 13:00
*/
time_t TimeTrans::excel_str_2_time(const char* buf)
{
    char* str_time = strdup(buf);
    char* tmp  = str_time;
    char* tmp2 = strchr(tmp, '/'); *tmp2 = 0;
	struct tm lt;

    lt.tm_mon = atoi(tmp) - 1;
    tmp = tmp2 + 1, tmp2 = strchr(tmp, '/'); *tmp2 = 0;
    lt.tm_mday = atoi(tmp);
    tmp = tmp2 + 1, tmp2 = strchr(tmp, ' '); *tmp2 = 0;
    lt.tm_year = atoi(tmp) - 1900;
    tmp = tmp2 + 1, tmp2 = strchr(tmp, ':'); *tmp2 = 0;
    lt.tm_hour = atoi(tmp);
    tmp = tmp2 + 1;
    tmp2 = strchr(tmp, ':');
    if (tmp2) {
        *tmp2 = 0;
        lt.tm_min = atoi(tmp);
        tmp = tmp2 + 1;
        lt.tm_sec = atoi(tmp);
    } else {
        lt.tm_min = atoi(tmp);
        lt.tm_sec = 0;
    }
    free(str_time );
    return mktime(&lt);
}


time_t TimeTrans::get_zeor_of_theday(double tt)
{
	time_t t = (time_t)tt;
	struct tm lt;
	localtime_s(&lt, &t);

	lt.tm_hour = 0;
	lt.tm_min  = 0;
	lt.tm_sec  = 0;
	return mktime(&lt);
}


