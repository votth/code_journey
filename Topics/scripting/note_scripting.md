# Topics
- external command
- keep files safe from overwriting: noclobber
- exit status: 0 and 1-255
- inc- and decrement
- $#, $@ and $?
- argument list and counter
- trap
- comparision
- limit scripts runtime
- debugging: set
- bash_history maximum size
- quit/exit out of selection scope

# wc - words count
lines	words	bytes

# sort
- option -n for numerical sort
- -r for reverse
- -u for unique

# uniq
- report or omit repeated lines
	- only remove adjacent lines
- using with `sort | uniq` is a bit obsolete since sort has its own `-u`, differences are:
	- `-d` for printing entries that have dups
	- `-u` for printing only unique entries
	- `-c` count appearences

# Variables expansion
Home path: ~ / tilty

Dollar sign expansion variables:
- $PATH
- $USER

Path name expansion:
- * matchs any patterns
- ? matches any single character

Curly braces expansion: {}
- `touch app.{js, py, html}` will create app.js app.py app.html
- `echo {1..9}`

# diff
Find differences between files.

`{lineNumber}{flag}{lineNumber}` where lineNumber are from file1 and file2, and flag is consisted of a(ppend) d(elete) c(hange)

-u showing result similar to git's  
-y showing files content side-by-side

# find
Find files and/or folders, based on name, type, size, modification, etc.

`find {path/location} -{flag_to_search_by} '{regex}'`  
-{flag_to_search_by} lets you search:
- `-type` for d(irectory) or f(ile) or symlink
- `-name` or -iname for case-insensitive
- `-or` with additional condition
- `-size +100k -size -1M` file for bigger than 100kb and smaller than 1 megabyte
- `-mtime` for modified time
- `-exec` defines what command we want to run on the matched find results. Use `\;` to specify termination. Eg. `find . -name 'Peter*' -exec cat {} \;` the {} for replacing result from `find`

`find / -ctime -1 > changesWithin1Day.txt`

# grep
Find text inside of files.

`grep {regex} {location}`
- `-n` to show line numbers
- `-nC {number}` to provide context, also showing {number} of line before and after
- `-r` search recursively

# du - disk usage
Find size of files and dirs.

`du -h | sort -h | tail`

# df - file system space usage
Not to be confused with `du`.  
`lsblk` for partitions and drives.

`df -h {dir}` to tell where the dir is located and its usage.

# history
`!{number}`	to run that numbered command in `history`.
`!!`		to replace for last entered line.

# ps - processes status
Snapshot of current processes.

`ps a`		for current user's processes.  
`ps ax`		for everything  
`ps axww`	to wrap  

# top / htop
List by default most CPU intensive processes.

# kill
With different signal, we can "kill" processes differently.

`kill -l`	to list available signals  
`kill <PID>`  
`pkill`

Common signals/flags: SIGTERM (15) and SIGKILL (9)

`killall <name>`

# jobs / bg / fg
`ctrl+c`	terminate command.  
`ctrl+z`	suspend command.  
& (ampersand) at the end of command specifies that it's running on the background.

`jobs`	list out suspended command.  
`fg <number>` to resume a process. Put them to *foreground*
`bg`	to let the process run in *background*

# sleep - delay process

# gzip
Compress or expand files. But doesn't not bundle them together.

`gzip <file>`  
- `-k` to keep the original, else it'll be replaced by the compressed
- `-g` to unzip or using `gunzip`

# tar
Grouping files/dirs. There's flag for compression.

`tar -cf <saveName>.tar file1 file2`  
- `-c` for create
- `-f` for write the the archive \<saveName>
- `-x` to untar, `-C` to new location
- `-t` to view the *.tar* content

*<name>.tar.gz* is some files being tar'ed then gzip'ed
- you can `tar -xf` then `gzip -k`
- or using `-z` flag for compression operation with `tar`

# alias
`alias`  
`source ~/.bashrc`

Single vs double quotes with $ variables:
- `"..."` will be a const value at the moment the alias is set. Eg. `alias lsHome="ls $PWD"` when uses in ~, if we go anywhere and use `lsHome` it will always list `ls ~`.
- `'...'` has a relative value.

# xargs
Take input from standard input into arguments for another command.

`cat deadPlayers.txt | xargs rm`  
take a list of dead players, and use them as arguments for the `rm` command.

`find . -size +1M | xargs ls -lh`  
find files with 1+ megabyte and put them into `ls` command.

# ln - link
Like a pointer to another files / shortcut for Windows.

## Hard links
`ln <original> <link>`
Bi-directional links, changes to orginal also change link, and changes to link also happend to the original.  
Deleting orignal, then link still have its content since it's pointing to the memory location (?).

This is rarely used cause of its limitation:
- can't link dirs.
- can't link to external filesystems/disks
- doens't have distinsh highlight

## Soft links
`-s` flag for symbolic/soft links.

Differences:
- has highlight and noticable symbol in `ls -l`
- original's deletion breaks the link file

Let you have multiple version of a program, eg. languages like python with 2.7 and 2.6 or 3.8 3.6, using link `/usr/bin/python3->python3.8`

# who
List out logged in users.

# su - switch user
`su <name>` and `exit` or ctrl+d to exit our of that \<name> user's shell.

# passwd - change password
Default to change current user's password.  
`sudo passwd <user>` to change other's password

# chown / chmod
`sudo chown <new_owner> files/dirs`  
`-R` for recursively every sub-files/dirs.

`sudo chown <user>:<group> files/dirs` to change owner group.

# Users/groups permissions and chmod
drwx-r--r--
d/l/-	is type for dir, link, file
r 4		is read
w 2		is write
x 1		is execute
first 3-group is owner, next is group, and others'/world

`chmod` by using number 421 (octal) or by flags  
`chmod 744 files/dirs`  
`chmod ug+rwx files/dirs`  
- `u`	for user/owner
- `g`	for group
- `o`	for others/world
- `a`	for all
- +/-	to add/remove permission
- =		to reset everything to - except for this
