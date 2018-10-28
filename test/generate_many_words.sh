#!/bin/bash

# Make sure number is provided that specifies the amount of characters to print
re='^[0-9]+$'
if ! [[ "$1" =~ $re ]] ; then
   echo "Usage: ./generate_many_words <amount of characters>" >&2
   exit 1
fi

# Define the alphabet and get the length of the alphabet
CHARS=$'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,!? \n'
LENGTH=${#CHARS}
AMOUNT=$[${1} - 1]

# Print out $1 (first argument) - 1 (to make space for the final newline) amount of characters
for ((i=0; i < $AMOUNT; i++)); do
	index=$[$RANDOM % $LENGTH]
	printf "%c" "${CHARS:$index:1}"
done
printf "\n"