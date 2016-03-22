#include "stdafx.h"
#include "ActivePluginAction.h"
#include "ActionMonitor.h"

/**
 * The plugin contructor
 * @param const Action& src the action that is now active.
 * @param HWND hTopHWnd the window that was on top at the time the command was given.
 * @param const STD_TSTRING& szCommandLine the given command line that is, the words after the command itself
 * @param bool isPrivileged if this action is privileged or not.
 */
ActivePluginAction::ActivePluginAction(const Action& src, HWND hTopHWnd, const STD_TSTRING& szCommandLine, bool isPrivileged) :
  ActiveAction( src, hTopHWnd, szCommandLine, isPrivileged )
{
}

ActivePluginAction::~ActivePluginAction()
{
}

bool ActivePluginAction::OnDeInitialize()
{
  // nothing to do.
  return true;
}

bool ActivePluginAction::OnInitialize()
{
  //  all good
  return true;
}

void ActivePluginAction::ExecuteInThread()
{
  //  the file.
  const STD_TSTRING& szFile = File();

  // create the Python Api.
  PluginVirtualMachine* pvm = App().GetPluginVirtualMachine();
  PluginApi* api = new PluginApi( *this );

  //add it to the list
  pvm->AddApi(api);
  
  //  save it.
  // we can now execute the thread.
  pvm->ExecuteInThread( szFile.c_str() );

  // we can now dispose of the lua
  pvm->DisposeApi();
  delete api;
}