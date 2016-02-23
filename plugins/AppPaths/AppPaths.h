// AppPaths.h : main header file for the AppPaths DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

// support for PluginAPI
#include "../amplugin.h"

// add the libs
#ifdef _DEBUG
# ifdef _WIN64
#   pragma comment(lib, "../amplugin64d.lib" )
#else
#   pragma comment(lib, "../amplugind.lib" )
# endif
#else
# ifdef _WIN64
#   pragma comment(lib, "../amplugin64.lib" )
# else
#   pragma comment(lib, "../amplugin.lib" )
# endif
#endif

class AppPaths
{
public:
  AppPaths();
  ~AppPaths();

  void Init( amplugin& am );

protected:
  std::wstring lower( const std::wstring& s) const;
  void strip_quotes( std::wstring& s) const;
  bool file_exists( const std::wstring& s) const;

protected:
  typedef std::map<std::wstring, std::wstring> REG_VALUES;
  typedef std::map<std::wstring, REG_VALUES> REG_NAMES;

  void QueryRegistry( amplugin& am );
  void QueryKeyValues(HKEY hKey, const std::wstring& sFullKey, REG_VALUES& values ) ;
  void QueryKey( HKEY hKey, const std::wstring& sFullKey, REG_NAMES& values ) ;
};