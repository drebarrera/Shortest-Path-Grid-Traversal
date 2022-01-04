#!/bin/sh
gcc -std=c99 -pedantic -Wvla -Wall -Wshadow -g *.c testing/*c -o pa3
echo "" > testout3

for i in {2..20}
do
	echo "-----------------------------" >> testout3
	echo $i"_"$i >> testout3
	./pa3 new_grid/$i"_"$i.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout3
done
for i in {30..200..10}
do
	echo "-----------------------------" >> testout3
	echo $i"_"$i >> testout3
	./pa3 new_grid/$i"_"$i.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout3
done
for i in {300..2000..100}
do
	echo "-----------------------------" >> testout3
	echo $i"_"$i >> testout3
	./pa3 new_grid/$i"_"$i.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout3
done
for i in {3000..6000..1000}
do
	echo "-----------------------------" >> testout3
	echo $i"_"$i >> testout3
	./pa3 new_grid/$i"_"$i.b textgridfile.t fastesttimesfile.f fastestpathfile.p >> testout3
done



