#! /bin/bash

# create some foo files with different sizes
for i in {1..5}
do
	dd if=/dev/zero of=file_$i.dat bs=1M count=1$i &> /dev/null
done

# return largest file's name
du -h * | sort -nr | head -n 1 | cut -f 2-
