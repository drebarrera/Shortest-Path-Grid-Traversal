#!/bin/sh
gcc -std=c99 -pedantic -Wvla -Wall -Wshadow -g *.c testing/*c -o pa3
echo "" > testout2

RANDOM=$$
ind=0
while true
do
	ind=$(($ind+1))
	cd new_grid
	RAND1=$(($(($RANDOM%5998))+2))
	RAND2=$(($(($RANDOM%5998))+2))
./new_grid << EOF
	1
	$RAND1
	20
	9
	0
EOF
	echo "INDEX: "$ind
	cd ../
	echo "-----------------------------" >> testout2
	echo $RAND"_20,9,0" >> testout2
	./pa3 new_grid/test.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout2
	echo "TextGrid:" >> testout2
	cat textgridfile.t >> testout2
	echo "FastestTimes:" >> testout2
	xxd fastesttimesfile.f >> testout2
	echo "FastestPath:" >> testout2
	xxd fastestpathfile.p >> testout2

	cd new_grid
./new_grid << EOF
	1
	$RAND1
	20
	999
	0
EOF
	echo "INDEX: "$ind
	cd ../
	echo "-----------------------------" >> testout2
	echo $RAND"_20,999,0" >> testout2
	./pa3 new_grid/test.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout2
	echo "TextGrid:" >> testout2
	cat textgridfile.t >> testout2
	echo "FastestTimes:" >> testout2
	xxd fastesttimesfile.f >> testout2
	echo "FastestPath:" >> testout2
	xxd fastestpathfile.p >> testout2

	cd new_grid
./new_grid << EOF
	1
	$RAND1
	20
	32767
	0
EOF
	echo "INDEX: "$ind
	cd ../
	echo "-----------------------------" >> testout2
	echo $RAND"_20,SHRT_MAX,0" >> testout2
	./pa3 new_grid/test.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout2
	echo "TextGrid:" >> testout2
	cat textgridfile.t >> testout2
	echo "FastestTimes:" >> testout2
	xxd fastesttimesfile.f >> testout2
	echo "FastestPath:" >> testout2
	xxd fastestpathfile.p >> testout2
done



