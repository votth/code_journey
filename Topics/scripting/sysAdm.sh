#!/bin/bash

PS3="Your choice: "

# choices
select ITEM in "Add User" "List all Processes" "Kill Process" "Install Program" "Quit"
do

	if [[ $REPLY -eq 1 ]]
	then
		read -p "Enter new username: " username
		# check if username already exists
		output="$(grep -w $username /etc/passwd)"
		if [[ -n "$output" ]]
		then
			echo "The user $username already exists."
		else
			sudo useradd -m -s /bin/bash "$username"
			# check if last used command was successful
			if [[ $? -eq 0 ]]
			then
				echo "The user $username was added sucessfully."
				tail -n 1 /etc/passwd
				read -p "Set the password for user $username: "
				sleep 1
				sudo passwd $username
			else
				echo "There was an error adding the user $username."
			fi
		fi

	elif [[ $REPLY -eq 2 ]]
	then
		echo "Listing all processes..."
		sleep 1
		ps -ef

	elif [[ $REPLY -eq 3 ]]
	then
		read -p "Enter the process to kill: " process
		pkill $process

	elif [[ $REPLY -eq 4 ]]
	then
		read -p "Enter the program to install: " app
		sudo pacman -Syu && sudo pacman -S $app

	elif [[ $REPLY -eq 5 ]]
	then
		echo "Quitting..."
		sleep 1
		exit

	else
		echo "Invalid menu selection."
	fi

done
