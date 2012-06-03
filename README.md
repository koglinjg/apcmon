apcmon
======

Nagios plugin for monitoring PHP APC

WARNING:
=====
This is still alpha code and its structure will inevitably change. I am sorry to anyone who write modules for this and I
then change my structure. I will release a version 1.0 when I am satisfied with the codes extensibility and security.
Please help me improve the code, instructions and add modules for this.

How it works:
=====
The check_apc file is actually a php-cli script that connects to the apc_mon on the server and passes a check argument
to the server. The server then looks through the include files in apc_mon/includes/*.inc for a file named after the
check argument .inc. If it finds one it then loads that file and executes that function and returns those results to the
check script. The check script then takes the results and based on the warning and critical values and determines if
that should be OK, WARN or CRITICAL. apc_mon is a folder on the remote server that contains all the code for the server
to be monitored that actually runs the checks on apc.

Installation:
=====
1. Edit the apc_mon/config.php file and add your ip(s) and any other settings (these ips are the only ones the server will respond to)
2. Add your includes, if you have any, to apc_mon/includes/*.inc
3. Copy apc_mon folder to the server(s) to be monitored somewhere that is accessible by the webserver.
4. Copy the check_apc to your nagios plugins directory (/usr/lib/nagios/plugins)
5. Look at the commands.cfg.example and add that or something similar to your commands.cfg for nagios. (/etc/nagios/)
6. Look at the services.cfg.example and add something similar to your nagios configuration (/etc/nagios/)
7. Reload nagios and check your apc stats

Included Plugins:
====

expunges
==
Returns the amount of times apc cache has been flushed.

Example service command: check_apc!expunges!1!10

Example result: "expunges OK - expunges=0"

fragments
==
Returns the number of excess fragments. There is 1 chunk per segment that is not counted as a fragment but all others past the first are.

Example service command: check_apc!fragments!1!10

Example result: "fragments OK - fragments=0"

hit_percent
==
Returns the percentage of cache hits.

Example service command: check_apc!hit_percent!80!60

Example result: "hit_percent OK - HITS 99%"

list_valid_checks
==
Internal plugin that lists all other valid plugins


Make your own plugins:
=====
WARNING: this is still alpha code, don't write a plugin if you care about the api changing in the next few days.
I already have plans for allowing the plugins to do more.

1. Copy one of the apc_mon/includes/*.inc files
2. Call it check_name.inc where check_name is the parameter to pass in your 'check_apc!check_name!10!100' command
3. Inside this php file define a function called check_name that returns an integer (or float)
4. the comparison of that return value and returning ok,warn,crit is handled by my code