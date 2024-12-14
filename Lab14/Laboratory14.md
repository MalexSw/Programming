# Report 14

#### Single linked list into file

#### In this laboratory work I created a programm, that can create and display linked list. Than it save this list into text file "list.txt" and bin file "list.bin". And finally load them from binary and test files, after what display one time more

### Here is output

>┌──(malex-kali㉿MA)-[~/Programming/Lab14]      
>└─$ gcc -o store_app main.c store.c      
>                                              
>──(malex-kali㉿MA)-[~/Programming/Lab14]       
└─$ gdb ./store_app                             
GNU gdb (Debian 13.2-1+b2) 13.2     
Copyright (C) 2023 Free Software Foundation, Inc.       
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>           
This is free software: you are free to change and redistribute it.      
There is NO WARRANTY, to the extent permitted by law.   
Type "show copying" and "show warranty" for details.    
This GDB was configured as "x86_64-linux-gnu".  
Type "show configuration" for configuration details.    
--Type <RET> for more, q to quit, c to continue without paging--c       
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.       
Find the GDB manual and other documentation resources online at:            
    <http://www.gnu.org/software/gdb/documentation/>.
>
>For help, type "help".
Type "apropos word" to search for commands related to "word"...     
Reading symbols from ./store_app...     
(No debugging symbols found in ./store_app)
(gdb) r     
Starting program: /home/malex-kali/Programming/Lab14/store_app          
[Thread debugging using libthread_db enabled]   
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".          
Product 'Computer' added to the store.      
Product 'Printer' added to the store.       
Product 'Scanner' added to the store.       
Products in the store:      
Product: Scanner, Price: $123.40, Stock: 50     
Product: Printer, Price: $250.00, Stock: 20     
Product: Computer, Price: $871.20, Stock: 10        
Store saved to text file 'list.txt'.        
Store saved to binary file 'list.bin'.      
>
>Reading from text file:        
Product 'Scanner' added to the store.       
Product 'Printer' added to the store.       
Product 'Computer' added to the store.      
Store loaded from text file 'list.txt'.     
Product: Computer, Price: $871.20, Stock: 10        
Product: Printer, Price: $250.00, Stock: 20     
Product: Scanner, Price: $123.40, Stock: 50     
>       
>Reading from binary file:      
Product 'Scanner' added to the store.       
Product 'Printer' added to the store.       
Product 'Computer' added to the store.      
Store loaded from binary file 'list.bin'.       
Product: Computer, Price: $871.20, Stock: 10        
Product: Printer, Price: $250.00, Stock: 20     
Product: Scanner, Price: $123.40, Stock: 50     
[Inferior 1 (process 968) exited normally]      
(gdb) q         
                                                    

#### As we can see, loaded lists are similar to thoes, which we created, so this mean, that code works correctly.