#!/bin/bash

if [ $1 = "--clean" ]; then
	rm -r CMakeCache.txt MakeFile CMakeFiles cmake_install.cmake Day_1
	exit
fi

if [ $1 = "--help" ]; then
	echo "Run with no flags for ordinary compilation."
	echo "--clean: for removing compiled files."
	echo "--help: for help"
	exit
fi

if [ $1 != "" ]; then
	echo "Invalid argument. See --help for more info"
	exit
fi

clear;
cmake CMakeLists.txt 
make
