# Description

Piger is a Keyboard Launcher allowing you to run your own commands from your keyboard. Highlight a word hold the caps lock key and simply type 'Google' to search for it in your browser. You can create your own commands, in LUA, Python, C++ and more.

You can start Typing [Caps Lock] + "Wi" and you will have options like ...
 
- Winword
- Wireshark
- Winrar
- ... and whatever else

More importantly, you are in control, you can write scripts for your commands.  

## Install/Setup

- Go grab the [latest release](https://github.com/FFMG/myoddweb.piger/releases/tag/0.4.4.0) and install it.
- Start Piger, (last step of the setup).
- Hold the [Caps Lock] key and type something, like 'this' and see what option appear.
- Select "this.version" and release the [Caps Lock] key.
- Admire the version number...

## Configuration

All the configuration of piger is contained in the profile.xml file.

[Read more](profile.md)

    <?xml version="1.0" encoding="UTF-8" ?>
    <Config>
    ...
    </Config>

### Commandline arguments

- --c [configpath]     
The full path of the config 
- --d [commandspath]    
The full path of the commands directory.

### For extra points...

- Write your own script, (see below).
	- For Python, add the *.py extension
	- For Lua, add the *.lua extension
	- For batch files, add the *.bat extension
- Put it in the Command folders, (select "Rootcommand" as an action).
- Select the "this.reload" action.
- Admire your handy work.

## Remark

Piger is aimed at people that like to write their own plugins, so by default it does not come with a whole lot of actions.

It is up to you, to create awesome plugins that fit **your** needs.

# Usage

Simple create your own actions/plugins and make them behave as you wish, for example, create a "google" command, (see below).

Then, after startup, simply press the [Caps Lock] button and type "go...", (you probably don't need to enter more than 2 letters), and google will pop up...

Of course, the main aim is for you to write your own plugins rather than been spoon-fed actions ...

# Special folders

## Root command
All your commands are located in your rootcommand folder, (%appdata%\myoddweb\ActionMonitor\RootCommands\ by default).

At statup all the actions/plugins are loaded. A file will have the command name.

For example, the file "**google.lua**" will create a command called "**google**" and the code in "google.lua" will be executed when that action is called. 

# Scripting your own commands.
## Python
### Code

import module, **import am**, (only usable within Piger of course).

- say( what, elapse, fade ), display a message
- version, get the LUA version been used.
- getCommand( idx ), get a typed command, if the user selects something like "*google world*", then command #0 is "google" and command #1 is "world".
- getAction, get the selected action.
- getCommandCount, get the number of commands including the action.
- execute, execute a certain app/event/batch file. You can also ask for elevated permission, (if piger is not running elevated).
- getString, get a string that the user might have selected at the time of calling the action.
- getFile, get a file that the user might have selected at the time of calling the action.
- getFolder, get a folder that the user might have selected at the time of calling the action.
- getUrl, get a url that the user might have selected at the time of calling the action.
- addAction, add an action to our current list of actions. (lost when the app restarts!)
- removeAction, remove an action from the list.
- getVersion, get the piger version number.
- findAction, find an action in our list of actions.

### Example
#### Calculator.lua

    import am
    am.say( "Run - calc ...", 400, 10 );
    am.execute( "%SystemRoot%\\system32\\calc.exe" );

## Lua
### Code
- am_say( what, elapse, fade ), display a message
- am_version, get the LUA version been used.
- am_getCommand( idx ), get a typed command, if the user selects something like "*google world*", then command #0 is "google" and command #1 is "world".
- am_getAction, get the selected action.
- am_getCommandCount, get the number of commands including the action.
- am_execute, execute a certain app/event/batch file. You can also ask for elevated permission, (if piger is not running elevated).
- am_getstring, get a string that the user might have selected at the time of calling the action.
- am_getfile, get a file that the user might have selected at the time of calling the action.
- am_getfolder, get a folder that the user might have selected at the time of calling the action.
- am_geturl, get a url that the user might have selected at the time of calling the action.
- am_addAction, add an action to our current list of actions. (lost when the app restarts!)
- am_removeAction, remove an action from the list.
- am_getVersion, get the piger version number.
- am_findAction, find an action in our list of actions.

### Example
#### Calculator.lua

Launch the default calculator.

    am_say( "Run - calc ...", 400, 10 );
    am_execute( "%SystemRoot%\\system32\\calc.exe" );

#### Google.lua

Launch the explorer and navigate to the Google site, if one or more words are highlighted then those words will be searched.

	-- the browser to use
	browser = "iexplore"
    
	-- we need to know the number of arguments.
	sizeOf = am_getCommandCount();

	-- try and get the word that might be highlighted. 
	if sizeOf == 0  then
	  word = am_getstring();
	  if false == word then
	    am_say( "Starting Google.", 400, 10 );
	    am_execute( browser, "http://www.google.com/", false );
	  else
	    am_say( "Starting Google for : " .. word , 400, 10 );
	    am_execute( browser, "http://www.google.com/search?hl=en&q=" .. word, false );
	  end
	else
	  query = ""
	  prettyQuery = "";
	  for count = 1, sizeOf, 1  do
	    -- the numbers are 0 based.
	    -- and we ignore the first one as it is the command itself
	    word = am_getCommand( count )
	    query = query .. word
	    prettyQuery = prettyQuery .. "<b><i>" .. word .. "</i></b>"
	    if count < sizeOf then
	      query = query .. "+"
	      prettyQuery = prettyQuery .. " and "
	    end
	  end
	
	  am_say( "Searching Google for: " .. prettyQuery, 400, 10 );
	  am_execute( browser, "http://www.google.com/search?hl=en&q=" .. query, false );
	end

## Batch files

Windows batch files are just executed, they have no access to any of the plugins functions.

Any arguments given are simply passed.

### Example

#### RootCommands.bat

Navigate to the root commands folder.

    START explorer /e,%appdata%\MyOddWeb\ActionMonitor\RootCommands\

# Debuging

To debug piger you will need a 'debug' action folder, "%appdata%\myoddweb\ActionMonitor_d\RootCommands\"

## Remark

If you are writing your own plugin, note that debug and release versions don't play well together, do be careful when you are trying to mix and match.

As a rule, remove all the actions and just leave your own plugin that you are developing.

## FAQ

### What version of Python is needed?

None, Python **3.5** is embedded in Piger, so it does not matter if you have python or not, it will all work just fine.

### Can I submit scripts/plugins

**Yes!** please, we want as many scripts as possible, we will add the best ones to the setup and have a list of all the scripts, (or maybe have a separate setup with all the plugins/scripts).

Just send us a message with your scripts.


### How to debug

Use the '*%appdata%\myoddweb\ActionMonitor_d\RootCommands\__in*' folder to debug your plugin.

- Stop piger
- Start the debuger
- Remove all plugins from '*%appdata%\myoddweb\ActionMonitor_d\RootCommands\__in*'
- Make sure that you select the correct platform, x86 or x64, that you want to debug.
- Make sure that your compiler copies the file automatically to the __in folder.

### Plugin is not loading

If you get an error loading a plugin, **it is almost certainly** because your plugin was build in x86 and you are trying to debug it with an x64 plugin. 

### Keyboard shortcut is not always picked up.

This happens when you are not debuging in 'Elevated mode', basically you need to debug as an admin.

If you are using visual studio, simply restart the IDE, but be sure to run as Admin. That will launch the app as admin as well.

**NB**: In release mode, the app auto-elevates itself.

### Sub folders

All sub folders are parsed, a file in the folder "**\os\calc.lua**" will create a command "**calc**"

#### __in
Anything in this folder, actions, plugins are loaded/called at startup.    

This allows your plugin to add/remove actions.

#### __out
As with the above, actions listed in that folder are called when piger closes.

This allows for cleanup for example.

#### __plugins

This special folders allows your plugin to save whatever they want to, (and it will not be deleted), for example you could save configuration data.

#### __temp

This is a special folder that is **not** parsed.
You can put your own files, code etc in that folder.
