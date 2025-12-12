# Group Project
**Author:** Andrew Yip, Nichole Lin, Victor Cheng\
**Language:** C++

## Program Package
- main.cpp FIFO.cpp RandomlyUsed.cpp LeastFrequentlyUsed.cpp - main source code
- Makefile - builds the program into an executable named "submission" and runs it
- Large_inptus.txt small_inputs.txt - a sample for problem 1 without spaces inbetween
- fifo.txt lfu.txt rand.txt - generated output file for each algorithm custom input files
## How to Run
- make - compile the program
- make run - runs program and output the results into an output file for each algorithm
- make all - cleans everything then compiles and runs the program
- make clean - removes the submission executable

In the make file we have to output the large_inputs.txt since that would be better for testing, and the small input can be tested if you just change it from Large_inputs.txt to small_inputs.txt

------------
Fifo Output Format:\
Total Cost: ___\
Time: __ ms
------------
lfu.txt Output:\
Final total cost: ___\
Time: ___ ms
------------
rand.txt Output:\
TotalCost: ___\
Time: ___ ms
------------

