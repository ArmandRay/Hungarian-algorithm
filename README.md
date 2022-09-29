# Hungarian  algorithm 
The Hungarian algorithm for the assignment problem computes the optimization matrix, the code has been optimized according to the relevant journals

After the algorithm runs, only the optimal matrix is obtained, and the required independent zero-tuples need to be manually extracted.

The input order is
1. Input the order of the square matrix (including the virtual matrix).
2. Input the number of matrix rows excluding the virtual matrix.
3. The input does not include the number of matrix columns of the dummy matrix.
4. Input square matrices (including virtual matrices)

Make sure that the matrix you enter is the one you want to compute directly with the Hungarian algorithm

The default matrix size in the code is 100*100. If you need to change the maximum order of the matrix, find the statement shown below at the top of the code and change the number to your desired number

```cpp
double a[100][100];//Change the definition type according to the matrix element type, and the comment will be represented by 1 later
bool maps[100][100];//1
double minr[100];//1
double minc[100];//1
bool lines_r[100];
bool lines_c[100];
```

The default matrix type in the code is the Double (floating point) type. If you need to change the matrix type in the code to the Int (integer) type according to the actual matrix, please refer to the comments in the code to change the type defined by the corresponding variable. This is the code comment shown below.

```cpp
double a[100][100];//Change the definition type according to the matrix element type, and the comment will be represented by 1 later
```
## References

袁迁,刘舒燕. 关于匈牙利法的优化[J]. 武汉理工大学学报,2007,29(3):146-149. DOI:10.3321/j.issn:1671-4431.2007.03.041.
