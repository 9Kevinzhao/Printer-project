# Printer Project
The main goal of this program is to simulate a program that uses multiple structs (aka objects) that communicate together to simulate a network printer.  Here is an overview of how to attack the program in a succinct efficient order.

-  Complete the struct files.  Complete the user file, the copyJob file, and the paperTray file.  There are header files (example.h) for each struct/typedef.  These get imported into the main Printer.c file.

-  Start working on the Printer File.
    -  Create the printer struct
    -  fill in the printer functions

-  Create a main method in the printer file.
    -  Create 3 users
    -  create 8 copy jobs
    -  Have the printer run all of the copy jobs.
    -  use a printf to show the user's history
    -  use printf to show the printer's history

## Instructions
There are more detailed instructions in each file to help guide you through developing the program.  Do not delete the comments until you complete a whole file.  Use them as guide posts to type underneath.

## User
The user only holds two pieces of information.  The name property, which is a string for the username.  In C we call this a char array (aka char[20]).  And the user keeps track of a variable named pageCount.  We want to know at the end of the year which employees are blowing up the printing queue, so we would like to know how many pages they reach in total.  Make that variable a long.

## CopyJob
This object is very similar to the user struct.  A copy job keeps track of 4 variables: name, pages, quantity, and content.  Name is the name of the file, let that be a character string that is 40 to be safe.  Pages represents the number of pages in the copy job, an int will suffice.  And finally content is a much longer character array.  In reality this would be like a docx/word file, but for us we will make it a large piece of text, so char[512].

## PaperTray
A printer has many different paper trays; different sizes and different quantities.  For simplicity we will assume all paper trays are the same size of paper, but they have different quantities of paper.  Our machine will have 6 trays: 2 small and 4 large.
-  Small Tray: 1000 pieces of paper.
-  Large Tray: 2000 pieces of paper.

Paper trays also keep track of 3 variables
-  name:  just give it a SHORT number 1,2,3,4,5,6
-  quantity: an int showing the current amount
-  total:  an int displaying either 1000 or 2000 depending on the tray.

## Printer
The printer struct combines all of the paper tray structs together and has built in functions which run the copy jobs and update the machine.  To make the program more efficient, rather than passing the information around, we will use pointers as inputs and output to the printer struct.

#### Printer Struct definition
-  name: some char array with 32 characters
-  trays: an int array with length 6.  This array stores the pointers (aka int* ) to each of the paper trays.
-  userDB: an integer pointer array which stores the int* of each user of the printer.  For simplicity we will only create 3 users in the future.
-  totalPagesPrinted:  a number that keeps track of the total number of copy jobs sent to the printer.

#### Printer functions
These functions will take multiple inputs - including the printer - and change the state of the trays, the users, and the printer.  For each function, read the signature before trying to implement the program.  In particular make note of the parameters provided for you.

-  trayStatus:  returns an integer which is the number of pieces of paper left in the paper tray.  This function accepts two inputs.  The first input is a paper tray pointer (there are 6 pointers to choose from) and a pointer to the printer, used for double checking the pointer the printer has is the same as the one you typed in.

-  reloadTray:  returns the integer 1.  This function accepts two inputs.  The first is the pointer to the printer while the second is an int which corresponds to the number of the correct paper tray.  You should reset the paper tray to 1000 or 2000 depending on the tray selected.  Again, just return 1 after that, it just means "success"!

-  printerStatus: returns an integer which is the total amount of paper in the printer.  This accepts only one input, the pointer to the printer.  Loop through all of the trays, create a total and return that total.

-  print: returns an int which is the total number of pages from the current print job.  The inputs are the printer, the user pointer (who is requesting the print job), and a copy job pointer (reference to what is being printed).  This function should update many pieces of information.
    -  The user: his page count should be increased.
    -  The printer: the totalPagesPrinted should be increased by the same amount.
    -  A tray:  start from tray 1 and then decrease the number of pages in the tray. (assume for now you have enough pages and we will worry about what happens when there in not enough paper in one tray later.)

## The main method
So at this point you should be ready to "turn on" the printer and watch it print.  You will need to initialize (create) many structs to get this up and running.
-  Make 3 user structs... u1, u2, ...
-  Make 8 copyJobs ... cj1, cj2, ...
-  Make 6 paper trays t1, t2, ...
-  Save a pointer for each struct, u1_ptr, cj1_ptr, t1_ptr
-  Only make one printer.

Then...let it rip.  Make some prints, then ask the printer for a status update.  Refill an empty tray and ask for another status to confirm it went back up.  Also ask for the totalPagesPrinted to see that it also keeps going up.
