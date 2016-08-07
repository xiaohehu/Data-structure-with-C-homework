CS341 Homework Assignment 5A

When building a binary tree, a tree which is as close to perfectly balanced as possible is the most efficient tree possible for a given input data set.

Given a data set which includes the unique first names of the members of a previous class, we need to construct a binary tree which is as balanced as possible. The unique given (i.e. first) names of the people in the class were:  William, Ben, Edward, Kevin, Greer, Tim, Nate, John, Raziel, Rongjuan, Ofer, Steve, and Ian.  There are 13 names in this list.  So, it is two names short of the count which is required to produce a perfectly balanced binary tree structure which contains four levels.  Nevertheless, we can create a tree which contains these names and which is as balanced as possible, by using the binary balancing algorithm which is shown in the program findMiddlerbalter.cpp.  (Please be aware that I am not asking you to use the AVL height-balancing algorithm.)

Here is an outline of a possible solution:

1. Enter the unsorted list of names into an array and sort this list in the array.  Be sure to retain the count of array elements.  For this problem you may use a static array which is at least large enough to handle the sample test data given above, preferably twenty-five or so.
2. Use the count of array elements and the findMiddle… algorithm to select the entries of the sorted array in the appropriate order to create the optimum balanced binary tree for the list of names which is provided above.  According to that algorithm you find the midpoint of the list, which is the location of the first node in the tree, then find the first-quarter and third-quarter locations which provide the second-level nodes, then the first-, third-, fifth and seventh-eighth locations which will be the third-level nodes, etc.
3. Display the balanced tree using one of the available binary tree display algorithms.
