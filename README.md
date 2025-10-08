# My Octave
## Copyright 2021 Nedelcu Andrei-David
___________________________________________________________________________________________

### Iterative Algorithm
The function represents an implementation of the Iterative algorithm. It receives as arguments: the name of the file from which the graph is read, the coefficient d, and the error. The function then returns the vector P.

After extracting the necessary information from the file, we found the number of web resources (N) from the first position of the file matrix. We initialized the adjacency matrix, A, and the neighbor vector, Q, with 0. Then we went through the information in the file and built the neighbor matrix and the adjacency matrix.

After finishing the construction of the adjacency matrix and neighbor vector, we bring Q to a diagonal form and calculate the degree matrix, M, using the formula:
```
M = (inv(Q) * A)'
```
The calculation of the vector P is done until the norm of the current P vector and the previous P vector is smaller than eps. The vector P is calculated using the formula:
```
R = d * M * P + (1 - d) / N * ones(N, 1)
```

### Algebraic Algorithm
The function represents an implementation of the Algebraic algorithm. The function receives as arguments: the name of the file from which the graph is read, the coefficient d, and the error that appears in the calculation of the P vector. The function returns the vector P.

The implementation of the function is similar to the implementation of the Iterative function. The only difference between the two functions is the calculation of the vector P.

The vector P is calculated using the formula:
```
R = GramSchm(I - d * M) * (1 - d) / N * ones(N, 1)
```

where the GramSchm() function is a function that calculates the inverse of a matrix using the Gram-Schmidt method. The implementation of the Gram-Schmidt algorithm is the one from the class.

### Membership Degree
The PageRank function receives as arguments the name of a file and the parameters d and eps. The function outputs to a new file: the number of analyzed web pages, N, the vector P calculated with the Iterative algorithm, the vector P calculated with the Algebraic algorithm, and a ranking of the most important pages, with the first column showing the obtained place, the second column showing the page number that obtained this place, and the last column showing the membership degree of this page in the set of important pages.

At the beginning of the function, we open the file received as a parameter and read the number of web resources to obtain the two values v1 and v2.

After obtaining the necessary values, we close the input file and create the output file. We open it, write N, write the PR1 vector obtained with the Iterative algorithm, write the vector calculated with the Algebraic algorithm. We sort the PR1 vector obtained with the Algebraic algorithm in descending order using the sort() function, and we also sort an index vector, idx, which shows the arrangement of the elements in the vector.

Membership is calculated in a function with the same name. The function receives as a parameter a number x, which represents an element from the sorted PR vector, val1, and val2, and calculates the value of the membership function at point x. After finishing writing everything to the file, we close it.
