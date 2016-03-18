#pragma once
#include "ActiveAction.h"
class ActiveLuaAction :
  public ActiveAction
{
public:
  ActiveLuaAction(const Action& src, HWND hTopHWnd, const STD_TSTRING& szCommandLine, bool isPrivileged);
  virtual ~ActiveLuaAction();

  virtual void ExecuteInThread();
  
protected:
  virtual bool OnInitialize();
  virtual bool OnDeInitialize();
};
