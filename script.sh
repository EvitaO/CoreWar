#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
PURPLE='\033[0;35m'
NC='\033[0m'

files=./test_champs/*.cor

for file in $files
do
	output="$(./vm "$file" > ./res)"
	output="$(./corewar_linux "$file" > ./res2)"
	if diff "./res" "./res2" >/dev/null
	then
		printf "${GREEN}%-50s	Passed${NC}\n" $(basename $file)
	else
		printf "${RED}%-50s	Failed${NC}\n" $(basename $file)
	fi
	cnt=100
	while [ $cnt -lt 4000 ]
	do
		output="$(./vm -d $cnt "$file" > ./res)"
		output="$(./corewar_linux -d $cnt "$file" > ./res2)"
		if diff "./res" "./res2" >/dev/null
		then
			printf "${GREEN}%-50s	Passed${NC}\n" "$(basename $file) with -d $cnt"
		else
			printf "${RED}%-50s	Failed${NC}\n" "$(basename $file) with -d $cnt"
		fi
		if [ $cnt -eq 100 ]
		then
			cnt=500
		elif [ $cnt -eq 500 ]
		then
			cnt=1000
		elif [ $cnt -eq 1000 ]
		then
			cnt=1500
		elif [ $cnt -eq 1500 ]
		then
			cnt=3000
		else
			cnt=4000
		fi
	done
done

files=./test_champs/champs/*

for file in $files
do
	files2=./test_champs/champs/*
	for file2 in $files2
	do
		if ! diff "$file" "$file2" >/dev/null
		then	
			output="$(./vm "$file" "$file2" > ./res)"
			output="$(./corewar_linux "$file" "$file2" > ./res2)"
			if diff "./res" "./res2" >/dev/null
			then
				printf "${GREEN}%-30s	vs	%s-50s	Passed${NC}\n" $(basename $file) $(basename $file2)
			else
				printf "${RED}%-30s	vs	%-50s	Failed${NC}\n" $(basename $file) $(basename $file2)
			fi
			cnt=100
			while [ $cnt -lt 4000 ]
			do
				output="$(./vm -d $cnt "$file" "$file2" > ./res)"
				output="$(./corewar_linux -d $cnt "$file" "$file2" > ./res2)"
				if diff "./res" "./res2" >/dev/null
				then
					printf "${GREEN}%-30s	vs	%-50s	Passed${NC}\n" "$(basename $file) $(basename $file2) with -d $cnt"
				else
					printf "${RED}%-30s	vs	%-50s	Failed${NC}\n" "$(basename $file) $(basename $file2) with -d $cnt"
				fi
				if [ $cnt -eq 100 ]
				then
					cnt=500
				elif [ $cnt -eq 500 ]
				then
					cnt=1000
				elif [ $cnt -eq 1000 ]
				then
					cnt=1500
				elif [ $cnt -eq 1500 ]
				then
					cnt=3000
				else
					cnt=4000
				fi
			done
		fi
	done
done

rm res res2