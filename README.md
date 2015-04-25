# adaptivejoin
Motivation: Making JOIN operation adaptive to input.

Problem definition
While dealing with data sets we come across various situations which can be classified into following cases.
1. Joining sets of comparable size.
2. Joining set with very large different is size. 1 : 1000

Understanding JOIN.
The naive the implementation of JOIN is M x N algorithm. Optimized without taking benefits of hash will MlogM + NlogN. Merging two sorted data set. What we find over here is that No matter which technique we use for joining data set the performance will be dependent on larger data set.

Where is the opportunity for improvement.
Many time what happens the one data set is very small in comparison to the other data set, but sufficiently large not to fit in one machines memory or use of some direct use of hash for joining.

Now this situation 2 mentioned in problem definition can be reduced to situation 1 under following condition,
1. If Data set2 is sub set of data set1.
2. and data set2 is very very small in relation to data set1.

Idea.
use bloom filter to filter out the data from set1 i.e larger set and reduce it to small data set. Which will help in reducing input to JOIN operation.
