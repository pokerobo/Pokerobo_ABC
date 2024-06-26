#ifndef __POKEROBO_ABC_DEBUG_LOGGER_H__
#define __POKEROBO_ABC_DEBUG_LOGGER_H__

#include <Arduino.h>

class AbcDebugLogger {
  public:
    static void debug(char* s0,
        char* s1=NULL,
        char* s2=NULL,
        char* s3=NULL,
        char* s4=NULL,
        char* s5=NULL,
        char* s6=NULL,
        char* s7=NULL,
        char* s8=NULL,
        char* s9=NULL,
        char* s10=NULL,
        char* s11=NULL,
        char* s12=NULL,
        char* s13=NULL,
        char* s14=NULL,
        char* s15=NULL,
        char* s16=NULL,
        char* s17=NULL,
        char* s18=NULL,
        char* s19=NULL);
};

class AbcDebugLoggable {
  public:
    void setDebugEnabled(bool enabled);
    void setDebugLogger(AbcDebugLogger* logger);
  protected:
    virtual bool isDebugEnabled();
    virtual AbcDebugLogger* getLogger();
  private:
    bool _debugEnabled = true;
    AbcDebugLogger* _logger = NULL;
};

#endif
