# Travelling Salesman Problem Solver

This project provides a solution to the Travelling Salesman Problem (TSP) implemented in C++ using dynamic programming.

## Introduction

The Travelling Salesman Problem is a classic problem in computer science and operations research. Given a list of cities and the distances between each pair of cities, the task is to find the shortest possible route that visits each city exactly once and returns to the original city. In other words finding Hamiltonian Cycle.

This project aims to solve the TSP using dynamic programming techniques, which can efficiently handle small-medium instances of the problem in ***O(n^2 * 2^n)*** where O(n * 2^n) are maximum number of unique subproblems/states and O(n) for transition (through for loop as in code) in every states.

## Video Explanation

For a detailed explanation of the Travelling Salesman Problem, you can watch the following video:
[Travelling Salesman Problem Explanation](https://www.youtube.com/watch?v=1pmBjIZ20pE)

## Test runs
<pre>
```C++ Code Output
LinkedIn @danildenha $ ./test
Enter the filename: graph15Names.txt
Optimal Tour Cost = [56, NYC,LA,SF,SEATTLE,BOSTON,PHILADELPHIA,D.C.,ATLANTA,MIAMI,VEGAS,DALLAS,NASHVILLE,CHICAGO,DETROIT,DENVER,NYC]
Algorithm execution time: 2 milliseconds
LinkedIn @danildenha $ ./test
Enter the filename: graph10.txt
Optimal Tour Cost = [36, ROSSI,JEFFERY,BROWN,SCHAFFER,JENSEN,LAWERENCE,GOPAL,CRAWFORD,KLIEN,GHANE,ROSSI]
Algorithm execution time: 0 milliseconds
LinkedIn @danildenha $ ./test
Enter the filename: graph4Names.txt
Optimal Tour Cost = [40, Chicago,NewYork,Kyiv,London,Chicago]
Algorithm execution time: 0 milliseconds
```
</pre>
