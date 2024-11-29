# Report 10

## Dynamically Allocated Arrays

#### In this laboratory work I rewrited some of my algoritms with a usage of Dynamically Allocated Arrays principles

#### In this programm I have main function, and seven other. Five of them, which are operating with arrays, send info about of needed amount of symbols, abd two other, which work with matrices, send size of matrix. It of these functions use dynamically allocating principles with a command "malloc".

#### So here is the output of all this seven functions. As we can see, all of them are working and give some output, so programm works correctly.

>┌──(malex-kali㉿MA)-[~/Programming/Lab10]      
└─$ gcc -g -O0 main.c -o expr
>
>┌──(malex-kali㉿MA)-[~/Programming/Lab10]      
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
--Type <RET> for more, q to quit, c to continue without paging--c           
    <http://www.gnu.org/software/gdb/documentation/>.
>
>For help, type "help".     
Type "apropos word" to search for commands related to "word"...     
Reading symbols from ./expr...      
(gdb) r     
Starting program: /home/malex-kali/Programming/Lab10/expr       `
[Thread debugging using libthread_db enabled]       
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".      
Array: -6 -4 -6 10 6 -5 -10 15 12 13    
Average of negative elements in this array is -6.20 
>
>Array: -6 -4 -6 10 6 -5 -10 15 12 13   
Second greatest element is 13   
>
>Old array:         
-6 -4 -6 10 6 -5 -10 15 12 13       
New array:      
-3 -1 -3 13 9 -2 -7 18 15 16        
>
>First array:       
-10 -9 -9 -8 -6 -6 -1 6 8 12        
Second array:       
-5 -4 0 0 0 3 10 11 13 15       
Merged array:       
-10 -9 -9 -8 -6 -6 -5 -4 -1 0 0 0 3 6 8 10 11 12 13 15 
>
>Original array:            
-6 -4 -6 10 6 -5 -10 15 12 13       
Even elements:      
-6 -4 -6 10 6 -10 12        
Odd elements:       
-5 15 13        
>
>26  89  26  70  72  53  85  22  37  21  
48  85  19  18  32  38  79  23  80  56  
68  84  10  2  74  76  24  96  71  90  
17  48  30  42  17  53  94  1  74  82  
21  73  66  92  91  50  81  21  72  60  
76  91  43  37  92  68  64  15  63  34  
56  31  81  38  72  97  90  17  98  64  
98  70  88  16  13  78  65  93  50  88  
4  25  78  46  13  69  65  76  36  79  
9  91  9  89  28  32  38  18  48  87  
>
>Main diagonal sum is 628       
Second diagonal sum is 593      
Difference between diagonals is 35      
>
>33  98  56  20  65  21  50  29  13  99  
68  17  76  45  14  88  65  79  64  100  
57  24  43  18  65  22  49  2  39  97  
40  23  46  95  95  10  67  44  90  80  
94  9  48  21  5  61  9  69  91  24  
21  48  47  63  17  63  84  65  64  75  
13  3  49  10  50  43  19  68  38  60  
47  84  68  94  4  72  55  64  93  45  
87  13  44  86  27  12  48  62  77  64  
88  41  18  37  51  19  79  21  87  69  
>
>
> Unique elements in the matrix are: 33 98 56 20 29 99 76 14 100 57 22 2 39 97 40 23 46 67 90 80 5 61 91 75 3 38 60 4 72 55 93 86 27 12 62 77 41 37 51 
>
>[Inferior 1 (process 21660) exited normally]   
(gdb) 