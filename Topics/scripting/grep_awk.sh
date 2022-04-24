#! /bin/bash

echo $(ip a | grep /24 | awk '{print $2}')
