# echo/ cat


# File redirecting
`>` `>>`	override and append

`1>` `2>`	stdout and stderr


# if else fi
``` bash
#! /bin/bash
count=10
age=13

# if (( $count < 10 ))
if [ $count -gt 10 ]; then
	echo "True"
elif [ $count -e 10 ];
	echo "Equal"
else
	echo "False"
fi

# && operator
# if [[ "$age" -gt 18 && "$age" -lt 40 ]]
# if [ "$age" -gt 18 -a "$age" -lt 40 ]
# || operator
# if [[ "$age" -gt 18 || "$age" -lt 40 ]]
# if [ "$age" -gt 18 -o "$age" -lt 40 ]
if [ "$age" -gt 18 ] && [ "$age" -lt 40]; then
	echo "Age is valid"
else
	echo "Age is invalid"
fi
```


# case
``` bash
#! /bin/bash
car=$1
case $car in
	"BMW" )
		echo "It's a $1" ;;
	"Mercedes" )
		echo "It's a $1" ;;
	"Toyota" )
		echo "It's a $1" ;;
	* )
		echo "Unknown car name" ;;
esac
```


# while
``` bash
#! /bin/bash
number=1
# until [ true ]
while [ $number -lt 10 ]
do
	echo "$number"
	number=$(( number+1 ))
done
```


# for
``` bash
#! /bin/bash
# for i in {start..end..incre}
# for (( i=0; i<=5; i++ ))
for i in 1 2 3 4 5
do
	echo $i
done
```
`break` and `continue`


# Terminal arguments
`$0`	is the program name

`$1` `$2` `$3` is corresponding arg

`$@`	is the argv

`$#`	is the argc

``` bash
#! /bin/bash
args=("#@")
echo ${args[0]} ${args[1]} ${args[2]}
echo $@
```


# Read line
``` bash
#! /bin/bash
while read line
do
	echo $line
done < "${1:-/dev/stdin}"
# without argument, /dev/stdin will be used instead, which is the terminal
```

## STDIN /dev/stdin

## STDOUT and STDERR
`1>` and `2>`

`>&` output both stdout and stderr

``` bash
#! /bin/bash
ls -al 1> file1.txt 2> file2.txt
```


# Pipes, script to another script
``` bash
#! /bin/bash
MESSAGE="Hello from script1"
export MESSAGE
./script2.sh
```

``` bash
#! /bin/bash
echo "The message from the other script is: $MESSAGE"
```


# String
``` bash
#! /bin/bash
echo "1st tring: "
read str1
echo "2st tring: "
read str2
if [ "$str1" == "$str2" ]; then
	echo "Strings match"
else
	echo "Strings don't match"
fi
# Concatinate
c=$str1$str2
# miniscule and maniscule
echo ${str1^} "and" ${str2^^}
echo ${str1^l} "uppercase a specific letter"
```

equal:		`==`  
shorter:	`<`  
longer:		`>`  


# Numbers and Arithmetic
``` bash
#! /bin/bash
echo 31+21
n1=31
nc=21
echo $(( n1 + n2 )) # - * / %
echo $(expr $n1 + $n2 ) # - \* / %
```


# Hex
``` bash
#! /bin/bash
echo "Enter hex number: "
read hex
echo -n "The decimal value of $hex is: "
echo "obase=10; ibase=16; $hex" | bc
```


# Declare variable
``` bash
#! /bin/bash
declare -p
declare myVar=22
# read-only
declare -r pwdFile=/etc/passwd
echo $pwdFile
```


# Arrays
``` bash
#! /bin/bash
car=('BMW' 'Toyota' 'Honda')
unset car[2]
car[2]='Mercedes'
echo "${car[@]}"
echo "${!car[@]}" # showing index
echo "${#car[@]}" # array length
```


# Function
``` bash
#! /bin/bash
function funcName() {
	echo $1
}
# call with argument
funcName hi
#
function iLove() {
	returning="I love Linux"
}
$returning="I love MAC"
echo $returning
iLove
# returning is now Linux
echo $returning
```


# Files and Dirs
``` bash
#! /bin/bash
echo "Check existing dir: "
read dir1
if [ -d "$dir1" ]; then
	echo "Exist"
else
	echo "Doesn't exist"
fi
#
echo "Check if file exists: "
read file1
if [ -f "$file1" ]; then
fi
```

## Append to file
``` bash
#! /bin/bash
echo "File to write to: "
read file
if [ -f "$file" ]; then
	echo "Text to append: "
	read text
	echo $text >> $file
	# read lines from file
	while IFS="" read -r line
	do
		echo "$line"
	done < $file
	rm $file
	echo "Deleted $file"
else
	echo "$file doens't exist"
fi
```


# Sending email
- google account: "Less secure app access: on"
- install smtp: `sudo pacman -S smtp`
- `sudo -e /etc/ssmtp/ssmtp.conf`
``` bash
root={emailAddress}@gmail.com
mailhub=smtp.gmail.com:587 #SSL is 465
AuthUser={emailAddress}@gmail.com
AuthPass={passwd}
UseSTARTLS=yes
```

From your script
``` bash
#! /bin/bash
ssmtp {emailAddress}@gmail.com
```

Within the terminal
```
To: email
From: email
Cc: someone else
Subject: TEST
This is body
```

To exit: ctrl+d


# curl
``` bash
#! /bin/bash
url=
# -O output to original file's name
curl ${url} -O
# to custom name
curl ${url} -o newName
curl ${url} > toFile
# check header
curl -I ${url}
```


# Professional menus
``` bash
#! /bin/bash
select car in BMW Mercedes Tesla
do
	case $car in
	BMW)
		echo "BMW selected";;
	Mercedes)
		echo "BMW selected";;
	Tesla)
		echo "BMW selected";;
	*)
		echo "Error";;
	esac
done
```

``` bash
#! /bin/bash
echo "Press any key to continue..."
while [ true ]
do
	read -t 3 -n 1
	if [ $? = 0 ]; then
		echo "You have terminated the script."
		exit;
	else
		echo "Waiting for next action..."
	fi
done
```


# Wait for filesystem events with `man inotify`


# grep
``` bash
#! /bin/bash
echo "File to search and search string"
read file
if [ -f "$file" ]; then
	read str
	# -i ignorecase, -n line no, -c count appearance, -v show reverse
	# -e regular expression
	grep -i $str $file
else
	echo "$file doesn't exist"
fi
```


# awk
scan file  
split line into views/column  
aciton on mashed line  
transform datafile, report  

``` bash
#! /bin/bash
echo "File to awk"
read file
if [ -f "$file" ]; then
	awk '{print}' $file # print all
	awk '/linux/ {print}' $file # print line with /{}/
	awk '/linux/ {print $2, $3}' $file # print only "2nd" column
else
	echo "$file doesn't exist"
fi
```


# sed - subtitude
``` bash
#! /bin/bash
echo "File to sed"
read file
if [ -f "$file" ]; then
	# change first appearence
	cat sedfile.txt | sed '$/i/I/'
	# chagne apply globally
	cat sedfile.txt | sed '$/i/I/g'
	# -i actually apply the changes
	sed '$/i/I/g' $file
else
	echo "No file"
fi
```


# Debugging
`bash -x ./yourScript.sh` shows executing lines by lines

add -x to the shebang `#! /bin/bash -x`

`set -x` and `set +x` to pinpoint codeblock to debug
