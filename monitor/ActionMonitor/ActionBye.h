// Action.h: interface for the Action class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __ActionBye_h__
#define __ActionBye_h__
#pragma once

#include "Action.h"

class ActionBye : public Action
{
public:
  ActionBye();
	virtual ~ActionBye();

  virtual ActiveAction* CreateActiveAction(CWnd* pWnd, const MYODD_STRING& szCommandLine, bool isPrivileged) const;
};

#endif // __Action_h__
