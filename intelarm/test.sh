#!/bin/bash
if [ "$(uname -p)" = "x86_64" ]; then
	make intel
	./test_intel.exe arm.txt > intel.txt
	kompare arm.txt intel.txt &
else
	make
	./test_arm.exe > arm.txt
fi

