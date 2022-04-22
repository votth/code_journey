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
- ~
- $PATH
- $USER
- * matchs any patterns, ? matches any single character
