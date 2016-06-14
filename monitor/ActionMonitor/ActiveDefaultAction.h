#pragma once
#include "ActiveAction.h"

class ActiveDefaultAction :
  public ActiveAction
{
public:
  ActiveDefaultAction(const Action& src, HWND hTopHWnd, const STD_TSTRING& szCommandLine, bool isPrivileged);
  virtual ~ActiveDefaultAction();

protected:
  virtual bool OnInitialize();
  virtual bool OnDeInitialize();
  virtual void OnExecuteInThread();
};