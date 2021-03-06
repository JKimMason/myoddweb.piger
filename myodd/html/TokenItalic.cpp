#include "TokenItalic.h"
#include "../string/string.h"

TokenItalic::TokenItalic() : 
  Token()
{
}

TokenItalic::~TokenItalic()
{
}

// if this is the token we are looking for.
bool TokenItalic::OnIsToken(const MYODD_CHAR* lpString, __int64 nLen ) const
{
  if( nLen == 1 )
  {
    return (_tcsnicmp(lpString , _T("i"),	1 ) ==0);
  }
  if( nLen == 2 )
  {
    return (_tcsnicmp(lpString , _T("em"),	1 ) ==0);
  }
  return false;
}

// apply the style
void TokenItalic::OnPush( LOGFONT& logFont )
{
  logFont.lfItalic = 1;
}

// remove the style
void TokenItalic::OnPop( LOGFONT& logFont )
{
  logFont.lfItalic = 0;
}
