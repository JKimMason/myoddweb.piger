#ifndef __Includes_h__
#define __Includes_h__

#pragma once

#include <windows.h>
#include <string>

#ifdef _WIN64
  typedef __int64 MYODD_LPARAM;
  typedef unsigned __int64 MYODD_WPARAM;
#else
  typedef long MYODD_LPARAM;
  typedef unsigned int MYODD_WPARAM;
#endif

#ifndef MYODD_STRING
  #ifdef _UNICODE
    typedef std::wstring MYODD_STRING;
    typedef wchar_t MYODD_CHAR;
  #else
    typedef std::string MYODD_STRING;
    typedef char MYODD_CHAR;
  #endif
#endif  //  MYODD_STRING

#ifndef __AFXWIN_H__


#ifdef _DEBUG
  #define UNUSED(x)
#else
  #define UNUSED(x) x
#endif
#define UNUSED_ALWAYS(x) x

#include <assert.h>
#ifdef _DEBUG
  #define ASSERT(f) assert(f)
#else
  #define ASSERT(f) __noop
#endif

#endif  //  __AFXWIN_H__

#endif  //  __Includes_h__