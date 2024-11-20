# Report 11

## Structures

#### In this laboratory work I created some structures and functions, which work with these structures

#### In this programm I created a programm for Online Store Management - I have store, product and customer structures and functions, which can add new products, place some orders and read orders for customers

#### Here are my structures: 

>typedef struct {       
    char name[MAX_NAME_LENGTH];     
    float price;            
    int amount;                                     
} product_t;        

>typedef struct {           
    char name[MAX_NAME_LENGTH];         
    int orders[MAX_ORDERS];         
    int ordersAmount;           
} customer_t;       

>typedef struct {       
    product_t products[MAX_PRODUCTS];       
    int productsAmount;     
    customer_t customers[MAX_CUSTOMERS];        
    int customerAmount;     
} store_t;      

#### I also have some checks if such prodect exist and if such customer exist.

#### So here is my output

>┌──(malex-kali㉿MA)-[~/Programming/Lab11]      
└─$ gcc -g -O0 main.c -o expr       
>               
>┌──(malex-kali㉿MA)-[~/Programming/Lab11]       
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
Type "apropos word" to search for commands related to "word"...         
Reading symbols from ./expr...          
(gdb) c     
The program is not being run.       
(gdb) r     
Starting program: /home/malex-kali/Programming/Lab11/expr           
[Thread debugging using libthread_db enabled]       
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".          
Product 'Computer' added        
Product 'Printer' added         
Product 'Scanner' added         
Order placed: Alice ordered 'Computer'.     
Order placed: Alice ordered 'Scanner'.      
Order placed: Bob ordered 'Printer'.        
Order placed: Bob ordered 'Scanner'.        
Customer Angela not found.          
Orders by Bob:              
  -Printer (Price: $250.00)               
  -Scanner (Price: $123.40)              
Orders by Alice:                
  -Computer (Price: $871.20)        
  -Scanner (Price: $123.40)     
[Inferior 1 (process 13044) exited normally]        
(gdb)       