#!/bin/bash

CHARS=$'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,!? \n'
LENGTH=${#CHARS}

for x in {0..1000000}; do
	index=$[$RANDOM % $LENGTH]
	printf "%c" ${CHARS:$index:$[$index + 1]}
done
