#ifndef __UTILITY_DATA_TYPE_H_INCLUDE__
#define __UTILITY_DATA_TYPE_H_INCLUDE__


#include "ThostFtdcUserApiDataType.h"


#define GOOD_AVERAGE_VALUE         .6
#define SERIES_LENGTH            1024
#define PREDICT_LENGTH             90
#define STAT_PREDICT                7
#define PRICE_EXT_APPROX_LEVEL      1
#define PRICE_LOW_APPROX_LEVEL      3
#define PRICE_HEIGH_APPROX_LEVEL    4
#define VOLUME_APPROX_LEVEL         3
#define INTEREST_APPROX_LEVEL       3
#define THE_PREDICT_SLOPE_VALVE     8
#define THE_VALVE_TO_CURVE         15
#define REVERSE_VALVE_POINT        .4
#define CENTRAL_REVERSA_TIMES     1.5
#define GOOD_CLOSE_VALUE            2
#define BAD_CLOSE_VALUE            -8
#define BEST_CENTRAL_MAG_VALUE      9
#define TURN_OVER_VALUE           1.5
#define FIRST_INFL_FUTURE_POSITION  9
#define _NODE_DIR_LOW_TURN_        25
#define _NODE_DIR_HE_TURN_         52
#define _GOOD_OPEN_LOW_SLOPE_      15
#define _GOOD_OPEN_HE_SLOPE_       10
#define _GOOD_CLOSE_LOW_SLOPE_     0
#define _GOOD_CLOSE_HE_SLOPE_      8
#define DBL_MIN_NUM                -1e30
#define DBL_MAX_NUM                1e30
#define FLT_MIN_NUM                -1e30f
#define FLT_MAX_NUM                1e30f

const int MAX_DATA_LENGTH = 32400;

#ifndef PI
#   define PI 3.1415926535897932384
#endif //PI

const double degree_10 = PI / 180 * 10;
const double degree_20 = PI / 180 * 20;


#ifndef SafeDelete
#	define SafeDelete(ptr) \
	{\
		if ((ptr)) {\
			delete (ptr);\
			(ptr) = 0;\
		}\
	}
#endif  //SafeDelete

#ifndef SafeDeleteArray
#	define SafeDeleteArray(ptr) \
	{\
		if ((ptr)) {\
			delete [] (ptr);\
			(ptr) = 0;\
		}\
	}
#endif  //SafeDeleteArray


typedef char           SIGNED_TYPE;
typedef unsigned char  uchar;
typedef unsigned char  uint8;
typedef short          int16;
typedef unsigned short uint16;
typedef unsigned int   uint32;
typedef unsigned char  BOOLT;

const SIGNED_TYPE SIGNED_TYPE_NEGATIVE = -1;
const SIGNED_TYPE SIGNED_TYPE_UNKNOW   = 0;
const SIGNED_TYPE SIGNED_TYPE_POSITIVE = 1;
const BOOLT       _T_ = 1;
const BOOLT       _F_ = 0;

typedef unsigned int EVENT_TYPE;
const EVENT_TYPE EVENT_TYPE_INCISIVE               =  1;
const EVENT_TYPE EVENT_TYPE_FLAT                   =  2;
const EVENT_TYPE EVENT_TYPE_FLAT_DIRCHANGED        =  8;
const EVENT_TYPE EVENT_TYPE_NOFLAT                 = 16;
const EVENT_TYPE EVENT_TYPE_NOFLAT_DIRCHANGED      = 32;
const EVENT_TYPE EVENT_TYPE_LOW_DOUBLE_FLAT        = 64;
const EVENT_TYPE EVENT_TYPE_LOW_DOUBLE_DIRCHANGED  = 128;
const EVENT_TYPE EVENT_TYPE_HIGH_DOUBLE_FLAT       = 256;
const EVENT_TYPE EVENT_TYPE_HIGH_DOUBLE_DIRCHANGED = 512;


typedef struct MyMarketData {
	///交易日
	TThostFtdcDateType	TradingDay;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///最新价
	TThostFtdcPriceType	LastPrice;
	///上次结算价
	TThostFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TThostFtdcPriceType	PreClosePrice;
	///昨持仓量
	TThostFtdcLargeVolumeType	PreOpenInterest;
	///今开盘
	TThostFtdcPriceType	OpenPrice;
	///最高价
	TThostFtdcPriceType	HighestPrice;
	///最低价
	TThostFtdcPriceType	LowestPrice;
	///数量
	TThostFtdcVolumeType	Volume;
	///成交金额
	TThostFtdcMoneyType	Turnover;
	///持仓量
	TThostFtdcLargeVolumeType	OpenInterest;
	///今收盘
	TThostFtdcPriceType	ClosePrice;
	///本次结算价
	TThostFtdcPriceType	SettlementPrice;
	///涨停板价
	TThostFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TThostFtdcPriceType	LowerLimitPrice;
	///昨虚实度
	TThostFtdcRatioType	PreDelta;
	///今虚实度
	TThostFtdcRatioType	CurrDelta;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TThostFtdcMillisecType	UpdateMillisec;
	///申买价一
	TThostFtdcPriceType	BidPrice1;
	///申买量一
	TThostFtdcVolumeType	BidVolume1;
	///申卖价一
	TThostFtdcPriceType	AskPrice1;
	///申卖量一
	TThostFtdcVolumeType	AskVolume1;
	///申买价二
	TThostFtdcPriceType	BidPrice2;
	///申买量二
	TThostFtdcVolumeType	BidVolume2;
	///申卖价二
	TThostFtdcPriceType	AskPrice2;
	///申卖量二
	TThostFtdcVolumeType	AskVolume2;
	///申买价三
	TThostFtdcPriceType	BidPrice3;
	///申买量三
	TThostFtdcVolumeType	BidVolume3;
	///申卖价三
	TThostFtdcPriceType	AskPrice3;
	///申卖量三
	TThostFtdcVolumeType	AskVolume3;
	///申买价四
	TThostFtdcPriceType	BidPrice4;
	///申买量四
	TThostFtdcVolumeType	BidVolume4;
	///申卖价四
	TThostFtdcPriceType	AskPrice4;
	///申卖量四
	TThostFtdcVolumeType	AskVolume4;
	///申买价五
	TThostFtdcPriceType	BidPrice5;
	///申买量五
	TThostFtdcVolumeType	BidVolume5;
	///申卖价五
	TThostFtdcPriceType	AskPrice5;
	///申卖量五
	TThostFtdcVolumeType	AskVolume5;
	///当日均价
	TThostFtdcPriceType	AveragePrice;

	double m_time;
} MyMarketData;

typedef struct CTPMMD {
	float  fIndex;
	float  LastPrice;	///最新价
    float  difPrice;    ///价格跳动
	float  Volume;		///数量
    float  relVolume;   ///相对成交量
	float  OpenInterest;///持仓量
    //float  relInterest; ///相对持仓
    float  difInterest; ///持仓变化
    float  open_intr;   ///开仓量
    float  cover_intr;  ///平仓量
    float  Turnover;    ///成交金额
	float  BidPrice1;	///申买价一
	float  BidVolume1;	///申买量一
	float  AskPrice1;	///申卖价一
	float  AskVolume1;	///申卖量一
    float  weightPrice; ///权重价
	double m_time;		///时间
} CTPMMD;


#define DBL_MAX_LIMIT DBL_MAX
#define DBL_MIN_LIMIT   -1E20
#define FLT_MAX_LIMIT FLT_MAX
#define FLT_MIN_LIMIT   -1E10

typedef struct PRICE_SERIES{
    double * PriceSeries;
    int      datalen;
} PRICE_SERIES;

typedef std::vector<double> vecPrice;


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
    

extern MyMarketData * ReadMarketDataFromFile(const char  * filename, int * nCount);
extern CTPMMD* ReadCTPDataFromFile(const char * filename, int * nCount);
extern void    printf_ctpmmd(CTPMMD* ctpmmd);
extern void    ConvertMmd2Ctpmmd(MyMarketData* mmd, CTPMMD* ctpmmd);
extern float   Time2Index(TIMESEGMENT* timeseg, double time);
extern void    ConvertOneMmd2Ctpmmd(MyMarketData* mmd, TIMESEGMENT* timeseg, CTPMMD* ctpmmd);
extern char*   Index2Time(char* buf, int len, float index);


#ifdef __cplusplus
}
#endif //_cplusplus

#endif //__UTILITY_DATA_TYPE_H_INCLUDE__
