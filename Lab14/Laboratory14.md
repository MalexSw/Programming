# Report 14

#### Single linked list into file

#### In this laboratory work I created a programm, that can create and display linked list. Than it save this list into text file "list.txt" and bin file "list,bin". And finally load them from binary and test files, after what display one time more

### Here is output

>┌──(malex-kali㉿MA)-[~/Programming/Lab14]      
>└─$ gcc -g -O0 main.c -o expr      
>                                                                                                                        
>┌──(malex-kali㉿MA)-[~/Programming/Lab14]      
└─$ gdb ./expr                          
GNU gdb (Debian 13.2-1+b2) 13.2     
Copyright (C) 2023 Free Software Foundation, Inc.       
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>       
This is free software: you are free to change and redistribute it.      
There is NO WARRANTY, to the extent permitted by law.       
--Type <RET> for more, q to quit, c to continue without paging--c       
Type "show copying" and "show warranty" for details.        
This GDB was configured as "x86_64-linux-gnu".      
Type "show configuration" for configuration details.        
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.       
Find the GDB manual and other documentation resources online at:        
    <http://www.gnu.org/software/gdb/documentation/>.       
>       
>For help, type "help".     
Type "apropos word" to search for commands related to "word"...     
Reading symbols from ./expr...      
(gdb) r     
Starting program: /home/malex-kali/Programming/Lab14/expr       
[Thread debugging using libthread_db enabled]       
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".      
Initial List:       
30 -> 20 -> 10 -> NULL      
>       
>List after loading from text file:     
10 -> 20 -> 30 -> NULL      
>           
>List after loading from binary file:       
10 -> 20 -> 30 -> 10 -> 20 -> 30 -> NULL        
[Inferior 1 (process 1041) exited normally]     
(gdb) q     


#### As we can see, loaded lists are similar to thosa, we created, so this mean, that code works correctly.