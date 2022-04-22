#! /bin/bash

echo "Who are you?"
read name
if [ $name ]; then
	echo $name is you.
else
	echo Name field is empty.
fi
