#!/bin/bash
if [ ! -f Makefile ]; then
	echo "[ERROR]Makefile not found!"
fi
echo "[INFO]make bsq"
rm -f bsq
rm -rf results
make fclean && make re && make clean
if [ -f bsq ]; then
	echo "[INFO]Binary was found!"
else
	echo "[ERROR]Binary not found!"
	exit 84
fi
if [ -d maps/mouli_maps ]; then
	echo "[INFO]Computable map directory was found!"
else
	echo "[ERROR]Computable map directory was not found!"
	exit 84
fi
if [ -d maps/mouli_maps_solved ]; then
	echo "[INFO]Solved map directory was found!"
else
	echo "[ERROR]Solved map directory was not found!"
	exit 84
fi
echo "[INFO]Starting tests:"
mkdir results
echo -e "-----TRACE BSQ-----\n\n" >> results/trace 
for entry in maps/mouli_maps/*
do
	name="${entry##*/}"
	if [ ! -f maps/mouli_maps_solved/$name ]; then
		echo "[ERROR]Could not found the solution of $name in the folder /maps/mouli_maps_solved/"
		exit 84
	else
		echo "[INFO]Testing $name"
		time=$( time ( ./bsq $entry 2>tmp 1>&2 ) 2>&1 )
		if [ $? -eq 0 ]; then
			diff -s tmp maps/mouli_maps_solved/$name >> diff
			if [ $? -eq 0 ]; then
				echo "[SUCCESS] The map printed was correct!" >> results/$name
				echo $name >> results/trace
				echo -e "    [SUCCESS] The map printed was correct!\n" >> results/trace
			else
				echo -e "[FAILURE] The map printed was incorrect!\nExpected:\n" >> results/$name
				cat maps/mouli_maps_solved/$name >> results/$name
				echo -e "\n\nBut got:\n" >> results/$name
				cat tmp >> results/$name
				echo -e "\n\nDifference:\n" >> results/$name
				cat diff >> results/$name
				echo $name >> results/trace
				echo -e "    [FAILURE] The map printed was incorrect!\nDifference:\n" >> results/trace
				cat diff >> results/trace
				echo -e "    For more infos see file trace.\n" >> results/trace
			fi
			rm -f diff
		else if [ $? -eq 84 ]; then
			echo "[FAILURE] bsq return with code 84 (0 expected)" >> results/$name
			echo $name >> results/trace
			echo -e "    [FAILURE] bsq return with code 84 (0 expected)\n" >> results/trace
		else if [ $? -eq 139 ]; then
			echo "[FAILURE] SEGMENTATION FAULT (core dumped)" >> results/$name
			echo $name >> results/trace
			echo -e "    [FAILURE] SEGMENTATION FAULT (core dumped)\n" >> results/trace
		else
			echo -e "[WTF] Wtf did you do bro? I don't know this return type value!\nSuch noob wow" >> results/$name
			echo $name >> results/trace
			echo -e "    [WTF] Wtf did you do bro? I don't know this return type value!\nSuch noob wow\n" >> results/trace
		fi
		fi
		fi
		echo "[$name]Finished in $time"
		rm -f tmp
	fi
done
