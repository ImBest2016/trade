#include "utility.h"
#include "datatype.h"


#define _FOR_STOCK_INDEX_FUTURES_

#define Is_MarketData_Time(t) (((t >= stQ1) && (t < etQ1)) || ((t >= stQ2) && (t < etQ2)))
//|| ((t >= stQ3) && (t < etQ3)))


MyMarketData * ReadMarketDataFromFile(const char  * filename, int * nCount)
{
    FILE * fp;
    if (NULL == (fp = fopen(filename, "rb")))
        return NULL;

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint32 datasize = sizeof(MyMarketData);
    int nMaxCount = fsize / datasize;
    MyMarketData * Data = new MyMarketData[nMaxCount];
    if (!Data)
        return NULL;
    MyMarketData mmd, *p = Data;

    int n = 0;

    if (fread(&mmd, datasize, 1, fp) != 1) {
        delete Data;
        fclose(fp);
        return NULL;
    }

    time_t stQ1 = TimeTrans::make_time_in_same_day((time_t)mmd.m_time,  9, 15);
    time_t etQ1 = TimeTrans::make_time_in_same_day((time_t)mmd.m_time, 11, 30);
    time_t stQ2 = TimeTrans::make_time_in_same_day((time_t)mmd.m_time, 13, 00);
    time_t etQ2 = TimeTrans::make_time_in_same_day((time_t)mmd.m_time, 15, 15);

    if (Is_MarketData_Time(mmd.m_time)) {
        memcpy(p, &mmd, datasize);
        p++, n++;
    }

    for (int i = 1; i < nMaxCount; i++) {
        if (fread(&mmd, datasize, 1, fp) != 1) {
            delete Data;
            fclose(fp);
            return NULL;
        }

        memcpy(p, &mmd, datasize);
        p++, n++;
    }

    fclose(fp);

    *nCount = n;
    return Data;
}

CTPMMD* ReadCTPDataFromFile(const char * filename, int * nCount, int offset/* = 0*/)
{
    FILE * fp;
    if (NULL == (fp = fopen(filename, "rb")))
        return (0);

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint32 datasize = sizeof(CTPMMD);
    uint32 nMaxCount = fsize / datasize;
    CTPMMD* Data = (CTPMMD*) new char[sizeof(CTPMMD) * nMaxCount + offset];
    if (!Data) return (0);

    if (fread((char*)Data + offset, datasize, nMaxCount, fp) != nMaxCount) {
        delete Data;
        fclose(fp);
        return (0);
    }

    fclose(fp);

    *nCount = nMaxCount;
    return Data;
}

void printf_ctpmmd(CTPMMD* ctpmmd)
{
    char buf[64];
    printf("%.02f %.02f %.02f %s\n",
        ctpmmd->LastPrice,
        ctpmmd->Volume,
        ctpmmd->OpenInterest,
        TimeTrans::get_time_str(buf, 64, ctpmmd->m_time));
}

void ConvertMmd2Ctpmmd(MyMarketData* mmd, CTPMMD* ctpmmd)
{
    ctpmmd->AskPrice1    = static_cast<float>(mmd->AskPrice1),
    ctpmmd->AskVolume1   = static_cast<float>(mmd->AskVolume1),
    ctpmmd->BidPrice1    = static_cast<float>(mmd->BidPrice1),
    ctpmmd->BidVolume1   = static_cast<float>(mmd->BidVolume1),
    ctpmmd->LastPrice    = static_cast<float>(mmd->LastPrice),
    ctpmmd->m_time       = mmd->m_time,
    ctpmmd->OpenInterest = static_cast<float>(mmd->OpenInterest),
    ctpmmd->Volume       = static_cast<float>(mmd->Volume);
    ctpmmd->fIndex = ctpmmd->relVolume
        = ctpmmd->difInterest = ctpmmd->difPrice
        = ctpmmd->open_intr   = ctpmmd->cover_intr = 0.0f;
}


float Time2Index(TIMESEGMENT* timeseg, double time)
{
    if (time >= timeseg->st1 && time <= timeseg->et1)
        return static_cast<float>((time - static_cast<double>(timeseg->st1)) / 0.5);
    else if (time >= timeseg->st2 && time <= timeseg->et2)
        return static_cast<float>((time - static_cast<double>(timeseg->st2)) / 0.5 + (120 + 15) * 60 * 2);
    else
        return -1.0f;
}

void ConvertOneMmd2Ctpmmd(MyMarketData* mmd, TIMESEGMENT* timeseg, CTPMMD* ctpmmd)
{
    ctpmmd->AskPrice1    = static_cast<float>(mmd->AskPrice1),
    ctpmmd->AskVolume1   = static_cast<float>(mmd->AskVolume1),
    ctpmmd->BidPrice1    = static_cast<float>(mmd->BidPrice1),
    ctpmmd->BidVolume1   = static_cast<float>(mmd->BidVolume1),
    ctpmmd->LastPrice    = static_cast<float>(mmd->LastPrice),
    ctpmmd->m_time       = mmd->m_time,
    ctpmmd->OpenInterest = static_cast<float>(mmd->OpenInterest),
    ctpmmd->Volume       = static_cast<float>(mmd->Volume);
    ctpmmd->relVolume = ctpmmd->difInterest
        = ctpmmd->difPrice = ctpmmd->open_intr = ctpmmd->cover_intr = 0.0f;
    ctpmmd->fIndex = Time2Index(timeseg, ctpmmd->m_time);
}

static const double start_time = 9 * 3600 + 15 * 60;
static const float noon_time  = (float)((11 * 3600 + 30 * 60 - (9 * 3600 + 15 * 60)) * 2);
static const float noon_delta = (float)((13 * 3600 - (11 * 3600 + 30 * 60)) * 2);


char* Index2Time(char* buf, int len, float index)
{
    double theindex = ((index > noon_time) ? (index) + noon_delta : index) / 2 + TimeTrans::get_zeor_of_theday(time(0)) + start_time;
        
    return TimeTrans::get_time_str(buf, len, theindex);
}
