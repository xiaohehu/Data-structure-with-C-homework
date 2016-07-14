##Supplementary Homework Problem 1

There is a special type of square matrix which is known as a determinant.  If you have a determinant which has three elements on a side, such as

| a11   a12   a13 |

| a21   a22   a23 |

| a31   a32   a33 |

You can evaluate the determinant using the following expression:  
```
a11a22a33 + a12a23a31 + a13a21a32 – a11a23a32 – a12a21a33 – a13a22a31
```
Please write a C++ program, including your own C++ class, as follows.  The program accepts integer data for the determinant and uses your C++ class to find the evaluation of the input determinant.  Then, it displays the value of the determinant and terminates.  Please note, that if the user enters invalid data for any of the entries of the determinant, the program will display an error message and terminate without attempting accept more input and will not attempt to evaluate the determinant.