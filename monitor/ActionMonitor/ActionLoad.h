// Action.h: interface for the Action class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __ActionLoad_h__
#define __ActionLoad_h__
#pragma once

#include "Action.h"

class ActionLoad : public Action
{
public:
  ActionLoad();
	virtual ~ActionLoad();

  virtual ActiveAction* CreateActiveAction(CWnd* pWnd, const MYODD_STRING& szCommandLine, bool isPrivileged) const;
};

#endif // __Action_h__
