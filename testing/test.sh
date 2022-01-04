#!/bin/sh
gcc -std=c99 -pedantic -Wvla -Wall -Wshadow -g *.c testing/*c -o pa3
echo "" > testout

for i in "4_5" "5_4" "5_5" "7_7"
do
	#./pa3 examples/$i.b textgridfile.t fastesttimesfile.f fastestpathfile.p
	echo "-----------------------------" >> testout
	echo $i >> testout
	valgrind -s --track-origins=yes --leak-check=full --log-file=temp_out ./pa3 examples/$i.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout
	cat temp_out >> testout
	if diff textgridfile.t examples/$i.t > /dev/null; then
		echo "TextGrid: Pass" >> testout
	else
		echo "TextGrid: Fail" >> testout
	fi
	if diff fastesttimesfile.f examples/$i.f > /dev/null; then
		echo "FastestTimes: Pass" >> testout
	else
		echo "FastestTimes: Fail" >> testout
	fi
	if diff fastestpathfile.p examples/$i.p > /dev/null; then
		echo "FastestPath: Pass" >> testout
	else
		echo "FastestPath: Fail" >> testout
	fi
done

for i in {2..20}
do
	echo "-----------------------------" >> testout
	echo $i"_"$i >> testout
	valgrind -s --track-origins=yes --leak-check=full --log-file=temp_out ./pa3 new_grid/$i"_"$i.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout
	cat temp_out >> testout
	echo "TextGrid:" >> testout
	cat textgridfile.t >> testout
	echo "FastestTimes:" >> testout
	xxd fastesttimesfile.f >> testout
	echo "FastestPath:" >> testout
	xxd fastestpathfile.p >> testout
done
for i in {30..200..10}
do
	echo "-----------------------------" >> testout
	echo $i"_"$i >> testout
	valgrind -s --track-origins=yes --leak-check=full --log-file=temp_out ./pa3 new_grid/$i"_"$i.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout
	cat temp_out >> testout
	echo "TextGrid:" >> testout
	cat textgridfile.t >> testout
	echo "FastestTimes:" >> testout
	xxd fastesttimesfile.f >> testout
	echo "FastestPath:" >> testout
	xxd fastestpathfile.p >> testout
done
for i in {300..2000..100}
do
	echo "-----------------------------" >> testout
	echo $i"_"$i >> testout
	valgrind -s --track-origins=yes --leak-check=full --log-file=temp_out ./pa3 new_grid/$i"_"$i.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout
	cat temp_out >> testout
	echo "TextGrid:" >> testout
	cat textgridfile.t >> testout
	echo "FastestTimes:" >> testout
	xxd fastesttimesfile.f >> testout
	echo "FastestPath:" >> testout
	xxd fastestpathfile.p >> testout
done
for i in {3000..6000..1000}
do
	echo "-----------------------------" >> testout
	echo $i"_"$i >> testout
	valgrind -s --track-origins=yes --leak-check=full --log-file=temp_out ./pa3 new_grid/$i"_"$i.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout
	cat temp_out >> testout
	echo "TextGrid:" >> testout
	cat textgridfile.t >> testout
	echo "FastestTimes:" >> testout
	xxd fastesttimesfile.f >> testout
	echo "FastestPath:" >> testout
	xxd fastestpathfile.p >> testout
done



