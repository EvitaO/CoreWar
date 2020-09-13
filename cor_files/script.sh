#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
PURPLE='\033[0;35m'
NC='\033[0m'

###############################################################################################

#path to valid '.cor' files
files=./valid/*.cor

#checking if output of your vm the same is as original vm
#if its the same filename and passed is printed
#if not filename and failed is printed
#file is first checked without dump (-d) flag
#after that file is tested with dump flag and following values: 100 500 1000 1500 3000

for file in $files
do
	output="$(./vm "$file" > ./res)"
	output="$(./corewar_mac "$file" > ./res2)"
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
		output="$(./corewar_mac -d $cnt "$file" > ./res2)"
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
rm res res2


########################################################################################################


#path to invalid '.cor' files
#files=./invalid_cor/*.cor

#first line prints filename
#second line your error message
#third line original corewar error message

# for file in $files
# do
# 	printf "%s\n" $(basename $file)
# 	output="$(./vm "$file" > ./res)"
# 	cat ./res
# 	output2="$(./corewar_linux "$file" > ./res2)"
# 	cat ./res2
# 	printf "\n"
# done
# rm res res2

###########################################################################################33########

#path to valid '.cor' files
#files=valid/*.cor

#runs 2 champs from $files against each other
#first without dump flag
#after that with dump flag and following values: 100 500 1000 1500 3000

# for file in $files
# do
# 	files2=./valid/*.cor
# 	for file2 in $files2
# 	do
# 		if ! diff "$file" "$file2" >/dev/null
# 		then	
# 			output="$(./vm "$file" "$file2" > ./res)"
# 			output="$(./corewar_linux "$file" "$file2" > ./res2)"
# 			if diff "./res" "./res2" >/dev/null
# 			then
# 				printf "${GREEN}%-30s	vs	%-10s	Passed${NC}\n" $(basename $file) $(basename $file2)
# 			else
# 				printf "${RED}%-30s	vs	%-10s	Failed${NC}\n" $(basename $file) $(basename $file2)
# 			fi
# 			cnt=100
# 			while [ $cnt -lt 4000 ]
# 			do
# 				output="$(./vm -d $cnt "$file" "$file2" > ./res)"
# 				output="$(./corewar_linux -d $cnt "$file" "$file2" > ./res2)"
# 				if diff "./res" "./res2" >/dev/null
# 				then
# 					printf "${GREEN}%-20s	vs	%-10s	with -d %i	Passed${NC}\n" $(basename $file) $(basename $file2) $cnt
# 				else
# 					printf "${RED}%-20s	vs	%-10s	with -d %i	Failed${NC}\n" $(basename $file) $(basename $file2) $cnt
# 				fi
# 				if [ $cnt -eq 100 ]
# 				then
# 					cnt=500
# 				elif [ $cnt -eq 500 ]
# 				then
# 					cnt=1000
# 				elif [ $cnt -eq 1000 ]
# 				then
# 					cnt=1500
# 				elif [ $cnt -eq 1500 ]
# 				then
# 					cnt=3000
# 				else
# 					cnt=4000
# 				fi
# 			done
# 		fi
# 	done
# done
# rm res res2
