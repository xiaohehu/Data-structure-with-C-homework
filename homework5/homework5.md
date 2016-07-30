CS341 Homework Assignment 5A


When building a binary tree, a tree which is as close to perfectly balanced as possible is the most efficient tree possible for a given input data set.

Given a data set which includes the unique first names of the members of our class, we need to construct a binary tree which is as balanced as possible. The unique given (i.e. first) names of the people in our class are:  Scott, Robert, Chad, Natan, Lucas, Long, Joey, Elliot, Kevin, Samson and John.  There are 11 names in this list.  So, it is four names short of the count which is required to produce a perfectly balanced binary tree structure containing four levels in addition to the root node.  Nevertheless, we can create a tree which contains these names and which is as balanced as possible.  To assist your thinking regarding the balancing, I have attached the program findMiddle_rbalter.cpp which demonstrates a binary balancing algorithm.  (Please be aware that I am not asking you to use the AVL height-balancing algorithm to solve this problem.)

Here is an outline of a possible solution:

1. Enter the unsorted list of names into an array and sort this list in the array.  Be sure to retain the count of array elements.  For this problem you may use static arrays which are large enough to handle the sample test data given above.

2. Use the count of array elements and the findMiddle… algorithm to rearrange the sorted array into a second array which contains the middle element in the first position, the elements in the first quarter and third quarter positions in the second and third positions, the elements in the first, third, fifth and seven-eighths positions into the fourth through seventh positions, etc.

3. Move each of the elements of the second array in succession into a binary tree structure.

4. Display the balanced tree using one of the available binary tree display algorithms.
