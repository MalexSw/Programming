# Report 13

## Single and doubly linked lists

#### In this laboratory work I created two linked lists, single and doubly, close to that one that was create during the lab class. In base they have my work from Lab 11.

#### Single linked list. It includes some structures, functions and a head pointer, that points to a node.

### Here is it's output


>┌──(malex-kali㉿MA)-[~/Programming/Lab13/singleLinkedList]     
└─$ gcc -o store_app main.c store.c                              
>                       
>┌──(malex-kali㉿MA)-[~/Programming/Lab13/singleLinkedList]     
└─$ gdb ./store_app                     
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
--Type <RET> for more, q to quit, c to continue without paging--c       
>       
>For help, type "help".         
Type "apropos word" to search for commands related to "word"...         
Reading symbols from ./store_app...     
(No debugging symbols found in ./store_app)     
(gdb) r     
Starting program: /home/malex-kali/Programming/Lab13/singleLinkedList/store_app             
[Thread debugging using libthread_db enabled]           
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".          
Product 'Computer' added to the store.      
Product 'Printer' added to the store.       
Product 'Scanner' added to the store.       
Products in the store:      
Product: Scanner, Price: $123.40, Stock: 50     
Product: Printer, Price: $250.00, Stock: 20     
Product: Computer, Price: $871.20, Stock: 10        
Order placed for product 'Computer'. Remaining stock: 9     
Order placed for product 'Printer'. Remaining stock: 19     
Product 'Nonexistent' not found in the store!       
>       
>Products after orders:     
Product: Scanner, Price: $123.40, Stock: 50     
Product: Printer, Price: $250.00, Stock: 19     
Product: Computer, Price: $871.20, Stock: 9     
[Inferior 1 (process 13251) exited normally]        
(gdb)           

#### Doubly linked list. It includes more high-level and difficult components, requires more memory, but can be used better

### Here is it's output

>┌──(malex-kali㉿MA)-[~/Programming/Lab13/doublyLinkedList]         
└─$ gcc -o store_app main.c store.c                             
>               
>┌──(malex-kali㉿MA)-[~/Programming/Lab13/doublyLinkedList]         
└─$ gdb ./store_app                                            
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
--Type <RET> for more, q to quit, c to continue without paging--c       
>       
>For help, type "help".         
Type "apropos word" to search for commands related to "word"...     
Reading symbols from ./store_app...     
(No debugging symbols found in ./store_app)     
(gdb) r     
Starting program: /home/malex-kali/Programming/Lab13/doublyLinkedList/store_app 
[Thread debugging using libthread_db enabled]           
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".          
Product 'Computer' added to the store.      
Product 'Printer' added to the store.       
Product 'Scanner' added to the store.       
Available products:         
Product: Computer | Price: $871.20 | Stock: 10          
Product: Printer | Price: $250.00 | Stock: 20           
Product: Scanner | Price: $123.40 | Stock: 50           
>           
>Placing an order for 'Computer':           
Order placed for product 'Computer'. Remaining stock: 9         
>       
>Available products after order:        
Product: Computer | Price: $871.20 | Stock: 9       
Product: Printer | Price: $250.00 | Stock: 20       
Product: Scanner | Price: $123.40 | Stock: 50       
>
>Removing 'Printer' from the store:     
Product 'Printer' removed from the store.       
>       
>Available products after removal:      
Product: Computer | Price: $871.20 | Stock: 9       
Product: Scanner | Price: $123.40 | Stock: 50       
Store memory freed.     
[Inferior 1 (process 13970) exited normally]        
(gdb)       