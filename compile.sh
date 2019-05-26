#!/bin/bash
g++ -I /home/ruiyi/exerice_QM_cpp/Eigen/ -c test_read_molecule.cpp 
g++ molecule.o read_molecule.o tool.o topic_1.o -o topic1

