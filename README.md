# linux-shell<br />
Pre-requisite in order to perform error free compilation (Make sure that there is enough memory present to fork a child process)<br />
1.)See the headers included in file. Make sure that you have installed all the required modules/packages before including them else it would give error that module not found below are the all headers that included in file<br />
#include<stdio.h><br />
#include<string.h><br />
#include<stdlib.h><br />
#include<unistd.h><br />
#include<sys/types.h><br />
#include<sys/wait.h><br />
make sure that make is installed sudo apt-get install make<br />
2.)If the packages are not installed then the program won’t compile<br />
3.)Upon extracting the zipped file open the folder 2018391_CAOS_Shell it would be containing<br />
a.basicFunctions.c<br />
b.basicFunctions.h<br />
c.OuterCommandHandler.c<br />
d.OuterCommandHandler.h<br />
e.shell.c<br />
f.Makefile<br />
4.)Open terminal here and execute command “make”<br />
5.)Upon executing command if you have installed all packages correctly it would have created a file “Shell” without extension file<br />
6.)Execute Shell file by typing ./Shell<br />
7.)now Shell is running…<br />
<br />
Assumption is that you’re executing make file in same directory.<br />
COMMANDS DESCRIPTION<br />
COMMAND NAME	FLAGS					DESCRIPTION<br />
echo		\\n					New line<br />
		\\b					Backspace<br />
		\\c 					Suppress Output<br />
history		-c					Clear history<br />
		-l					First 5 commands<br />
pwd		Flags not available			Current working directory<br />
exit		Flags not available			Exit from shell<br />
cd		Flags not available			Changes directory<br />
ls		-l					Shows list of all files present<br />
		-a					Show all files (hidden too)<br />
cat		--help 	(No other flag available)	Opens help<br />
		--version (No other flag available)	Opens Version of current cat<br />
date		--date={option} (multiple)		Displays date according to option<br />
		--help 	Opens help<br />
		--version				Opens Version of date<br />
rm		-i					Asks before deleting<br />
		-r					Deletes recursively<br />
mkdir		--help 					(Flags not available)	Display help<br />
		--version 				(Flags not available)	Display version<br />
clear		No flags available			Clear output screen<br />
<br />
Test cases<br />
1.)	echo apple<br />
2.)	echo apple\\nbanana<br />
3.)	echo appe\\ble<br />
4.)	history<br />
5.)	history -l<br />
6.)	history -c<br />
7.)	pwd<br />
8.)	cd /bin<br />
9.)	exit<br />
10.)	 ls <br />
11.)	 ls -l<br />
12.)	 ls -a<br />
13.)	 ls /<br />
14.)	 clear<br />
15.)	 cd /<br />
16.)	 cat /etc/apt/sources.list<br />
17.)	cat --help<br />
18.)	cat --version<br />
19.)	date --date=yesterday<br />
20.)	date --date=tomorrow<br />
21.)	date --date=1 month ago<br />
22.)	date --date=1 year ago<br />
23.)	date --date=1 year<br />
24.)	date --help<br />
25.)	date --version<br />
26.)	 mkdir 1<br />
27.)	 mkdir 1/2<br />
28.)	 mkdir 1/2/3<br />
29.)	 rm 1	(Error)<br />
30.)	 rm -r 1	(Will delete directories recursively)<br />
31.)	 rm {file name}<br />
32.)	 rm -i {filename}<br />
<br />
<br />
Protection & defenses<br />
I HAVE CREATED SHELL IN SUCH A WAY THAT IF USER EXECUTES SOMES UNKNOWN COMMAND THE SHELL WON’T CRASH RATHER WILL PRINT THE MESSAGE UNKNOWN COMMAND<br />
PROTECTION AGAINST WRONG COMMAND <br />
Example : ls cat<br />
Error directory not found<br />

