# Report 6

## Two dimensional arrays

#### In this laboratory work I created functions for four different tasks about matrices. Each of these function have matrix and sizes as an input and return some values.

#### First of all I have created functions. First find difference between matrix diagonals and return int, second calculate average value of each column and return array of amount of columns size, third find all unique elements, return first one found, and the last one find the median value.

#### After this I created tests for each function in test_lib.c file. Each one has three different cases and chec if everything wors correct. I launch tests from test_main.c file. Functions for tests locate in lib.c file, while in mainWithFunctions.c file I also have their copy wor usual work.

#### So here is my mainWithFunctions.c file output - it contains functions.

>┌──(malex-kali㉿MA)-[~/Programming/Lab09]      
└─$ gcc -g -O0 mainWithFunctions.c -o expr      
>       
>┌──(malex-kali㉿MA)-[~/Programming/Lab09]      
└─$ gdb ./expr      
GNU gdb (Debian 13.2-1+b2) 13.2     
Copyright (C) 2023 Free Software Foundation, Inc.       
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>       
This is free software: you are free to change and redistribute it.  
There is NO WARRANTY, to the extent permitted by law.   
Type "show copying" and "show warranty" for details.    
This GDB was configured as "x86_64-linux-gnu".  
Type "show configuration" for configuration details.        
For bug reporting instructions, please see: 
<https://www.gnu.org/software/gdb/bugs/>.       
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.       
>   
>For help, type "help".     
--Type <RET> for more, q to quit, c to continue without paging--c   
Type "apropos word" to search for commands related to "word"... 
Reading symbols from ./expr...      
(gdb) r     
Starting program: /home/malex-kali/Programming/Lab09/expr       
[Thread debugging using libthread_db enabled]       
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".      
23  45  12          
56  78  34          
89  90  67          
>       
>Testing diagonal difference:        
Main diagonal sum is 168        
Second diagonal sum is 179      
Difference between diagonals is -11         
>       
>Testing column averages:       
Column №1 average value is equal to 56      
Column №2 average value is equal to 71      
Column №3 average value is equal to 37      
>   
>Testing unique elements:       
Unique elements in the matrix are: 23 45 12 56 78 34 89 90 67       
>       
>Testing median value:          
Median value of this matrix is 56           
[Inferior 1 (process 2317) exited normally]     
(gdb)       

#### And my output for tests.

>┌──(malex-kali㉿MA)-[~/Programming/Lab09]          
>└─$ make all       
gcc -Wall -Iinclude -IUnity/src -fprofile-arcs -ftest-coverage -c   main.c -o main.o        
gcc -Wall -Iinclude -IUnity/src -fprofile-arcs -ftest-coverage -c src/lib.c -o src/lib.o        
ar rcs libproject.a src/lib.o       
gcc -Wall -Iinclude -IUnity/src -fprofile-arcs -ftest-coverage -o main main.o libproject.a -L. -fprofile-arcs -ftest-coverage -lm   
>    
>┌──(malex-kali㉿MA)-[~/Programming/Lab09]      
└─$ make test       
gcc -Wall -Iinclude -IUnity/src -fprofile-arcs -ftest-coverage -o run_tests Unity/src/unity.c test/test_lib.c test/test_main.c -L -lproject -L. -fprofile-arcs -ftest-coverage -lm     
./run_tests     
test/test_main.c:11:test_diffBetweenDiag:PASS       
test/test_main.c:12:test_averOfEachColumn:PASS      
test/test_main.c:13:test_uniqueElemFinding:PASS     
test/test_main.c:14:test_findingTheMedian:PASS      
>
>-----------------------
>4 Tests 0 Failures 0 Ignored           
OK
