# adaptivejoin
Motivation: Making JOIN operation adaptive to input.

Problem definition
While dealing with data sets we come across various situations which can be classified into following cases.
1. Joining sets of comparable size.
2. Joining set with very large different in size. 1 : 1000

Understanding JOIN.
The naive the implementation of JOIN is M x N algorithm. Optimized without taking benefits of hash will MlogM + NlogN. Merging two sorted data set. What we find over here is that No matter which technique we use for joining data set the performance will be dependent on larger data set.

Where is the opportunity for improvement.
Many time what happens the one data set is very small in comparison to the other data set, but sufficiently large not to fit in one machines memory or use of some direct use of hash for joining.

Now this situation 2 mentioned in problem definition can be reduced to situation 1 under following condition,
1. If Data set2 is sub set of data set1.
2. and data set2 is very very small in relation to data set1.

Idea.
use bloom filter to filter out the data from set1 i.e larger set and reduce it to small data set. Which will help in reducing input to JOIN operation.

Understating different files.
1. MurmurHash2.cpp :  MurmurHash2, by Austin Appleby. This code it used to convert string to hash. Used by generate_test_data.cpp and generate_random_test_data.cpp.

2. generate_test_data.cpp: This code is used to generate data for testing in string and id form, id is used to set hash map in hashset of 10^6 size map.
    compile: gcc generate_test_data.cpp MurmurHash2.cpp
    Usage : Usage: ./a.out number [skiplength -- optional]
    Example
    ./a.out 100 > bigset.txt
    ./a.out 100 10 > smallset.txt 
    Testing :    vimdiff bigset.txt smallset.txt
skiplength is used to generate subset for a given set, which is defined by number.
    
3. join.pig:  It loads big and small set and join them, after that it divide it into two set one containing left elements for small set and one not.

4. adaptive_join.pig:  It uses the knowledge available about the small set and filtes the large set before joining which results in efficient join.

5. Hfilter.java: It contains code for filter. Which filters a set based on filter_set. Which is some bloom filter.

6. pig.jar: It contains pig udf.

7. compile.sh: It contains commands used for compiling udf.
 
Testing this code:
