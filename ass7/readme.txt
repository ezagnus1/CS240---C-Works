In this assignment you will compare the performance of the STL set<T> class and STL unordered_set<T> class.
In a file named set.cpp write a program that:
reads IP addresses (strings) from a file and adds them to a set<T>.
reads IP addresses from another file and determines how many are bad (known spammers) and how many are good.
reads IP addresses from yet another file and removes them (if found) from the set of known spammers.
The following files contain (one per line) IP addresses.   The second group of files are much larger and should be used only after 
the program works with the first group of files.
spammers1.txt
check1.txt
remove1.txt

spammers2.txt
check2.txt
remove2.txt
The output (to the screen) of your program will be:
the number of known spammer IP addresses
the number of good IP addresses found
the number of bad IP addresses found
the number of IP addresses removed from the set of known spammers
the amount of time taken to run the program, including file input and screen output (refer to Lab5 or Week5 slides)
In a file named oset.cpp write another program that does exactly the same thing as the first program except for using 
the STL unordered_set<T> class.  You can use the default hash function and table size so do not need to change anything in 
the program you wrote for part 1 except the type of the set used.
