# Profile / Configuration

The configuration of piger are all in this xml, if the file does not exist, piger will not start, (or will not be very happy).

Piger does not use any registry data.

Those values are loaded once, (and once only), at run time.

    <?xml version="1.0" encoding="UTF-8" ?>
    <Config>
    ...
    </Config>
    
## Commands

Those are specific to the look and feel of the command window.

	<?xml version="1.0" encoding="UTF-8" ?>
	<Config>
    ...
	  <commands>
	    <current.bold type="8">0</current.bold>
	    <current.color type="1">000000</current.color>
	    <current.italic type="8">0</current.italic>
	    <default.bold type="8">0</default.bold>
	    <default.color type="1">000000</default.color>
	    <default.italic type="8">0</default.italic>
	    <left type="8">5</left>
	    <max.x type="8">99</max.x>
	    <max.y type="8">99</max.y>
	    <pad.x type="8">2</pad.x>
	    <pad.y type="8">2</pad.y>
	    <selected.bold type="8">1</selected.bold>
	    <selected.color type="1">808000</selected.color>
	    <selected.italic type="8">1</selected.italic>
	    <show.extentions type="8">0</show.extentions>
	    <show.time type="8">1</show.time>
	    <top type="8">5</top>
	    <transparency type="8">127</transparency>
	  </commands>
	...
    </Config>

## Paths

The paths contains the location used in by Piger.

You should not really change those as they are used internally, but you can name them something else, (if the code is too long for example). 

    <?xml version="1.0" encoding="UTF-8" ?>
    <Config>
    ...
	  <paths>
	    <commands type="1">%appdata%\myoddweb\ActionMonitor\RootCommands</commands>
	    <in type="1">%appdata%\myoddweb\ActionMonitor\RootCommands\__in</in>
	    <maxcommand type="8">2048</maxcommand>
	    <out type="1">%appdata%\myoddweb\ActionMonitor\RootCommands\__out</out>
	    <plugin type="1">%appdata%\myoddweb\ActionMonitor\RootCommands\__plugins</plugin>
	    <tmp type="1">%appdata%\myoddweb\ActionMonitor\RootCommands\__tmp</tmp>
      </paths>
	...
    </Config>

### Paths

* **commands** - where all the commands are located.
* **in** - the commands that will be run when piger stars.
* **out** - the commands that will be run when piger exists.
* **plugins** - the location of the plugins that will be loaded at start time.
* **tmp** - the temp folder that will not be parsed at load time.

### MaxCommand 

The maximum number of commands we will load in memory.   
The commands are loaded in order.

## Clipboard

Set the max number of bits we want to load from the clipboard.
The default value is **0**, meaning that everything will be loaded in memory.

This can be important in case you have very large useless data in memory, (something like Excel data for example, or Paint.NET images).

    <?xml version="1.0" encoding="UTF-8" ?>
    <Config>
    ...
	  <clipboard>
		<maxmemory type="8">1024</maxmemory>
      </clipboard>
	...
    </Config>

## Python

You might want to execute your own python code using your own modules and so on. 

The default value is **1**, meaning we will **always** use the built in python version.

    <?xml version="1.0" encoding="UTF-8" ?>
    <Config>
    ...
	  <python>
		<useembedded type="8">1</useembedded>
      </python>
    </Config>

If your command requires a certain module and/or version of python, be sure to tell your users about this flag.