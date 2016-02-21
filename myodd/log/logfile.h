#pragma once
#ifndef _LogFile_h
#define _LogFile_h

#include "../string/string.h"
#include "../threads/threads.h"

namespace myodd{ namespace log{
  class LogFile : myodd::threads::CritSection
  {
  public:
    LogFile();
    virtual ~LogFile();

    bool Close();
    bool SetLogDirectory( LPCTSTR lpPath, LPCTSTR lpPrefix = NULL, LPCTSTR lpExtention = _T("log") );
    bool IsOpen() const;
    bool LogToFile( unsigned int uiType, LPCTSTR pszLine );
    const STD_TSTRING& GetCurrentLogFile() const{
      return m_sCurrentFile;
    }
  protected:

    bool Open();
    bool Create();

    STD_TSTRING m_sPrefix;
    STD_TSTRING m_sExtention;
    STD_TSTRING m_sDirectory;
    STD_TSTRING m_sCurrentFile;
    bool m_bInOpenCall;
    FILE* m_fp;
    __int64 m_uCurrentSize;
  };
} //  log
} //  myodd
#endif // _LogFile_h