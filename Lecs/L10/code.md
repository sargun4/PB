## Needleman-Wunsch Algorithm Pseudo-Code

To find the alignment with the highest score, a two-dimensional array (or matrix) F is allocated. The entry in row i and column j is denoted here by \(F_{ij}\). There is one row for each character in sequence A, and one column for each character in sequence B. Thus, if aligning sequences of sizes n and m, the amount of memory used is in \(O(nm)\). Hirschberg's algorithm only holds a subset of the array in memory and uses \(\Theta(\min\{n, m\})\) space, but is otherwise similar to Needleman-Wunsch (and still requires \(O(nm)\) time).

As the algorithm progresses, the \(F_{ij}\) will be assigned to be the optimal score for the alignment of the first \(i=0, \ldots, n\) characters in A and the first \(j=0, \ldots, m\) characters in B. The principle of optimality is then applied as follows:

### Basis:
- \(F_{0j} = d \cdot j\)
- \(F_{i0} = d \cdot i\)

### Recursion, based on the principle of optimality:
\[ F_{ij} = \max\left(F_{i-1,j-1} + S(A_{i}, B_{j}),\; F_{i,j-1} + d,\; F_{i-1,j} + d\right) \]

### Pseudo-code:
```python
d ← Gap penalty score
for i = 0 to length(A)
    F(i,0) ← d * i
for j = 0 to length(B)
    F(0,j) ← d * j
for i = 1 to length(A)
    for j = 1 to length(B)
    {
        Match ← F(i−1, j−1) + S(Ai, Bj)
        Delete ← F(i−1, j) + d
        Insert ← F(i, j−1) + d
        F(i,j) ← max(Match, Insert, Delete)
    }
AlignmentA ← ""
AlignmentB ← ""
i ← length(A)
j ← length(B)
while (i > 0 or j > 0)
{
    if (i > 0 and j > 0 and F(i, j) == F(i−1, j−1) + S(Ai, Bj))
    {
        AlignmentA ← Ai + AlignmentA
        AlignmentB ← Bj + AlignmentB
        i ← i − 1
        j ← j − 1
    }
    else if (i > 0 and F(i, j) == F(i−1, j) + d)
    {
        AlignmentA ← Ai + AlignmentA
        AlignmentB ← "−" + AlignmentB
        i ← i − 1
    }
    else
    {
        AlignmentA ← "−" + AlignmentA
        AlignmentB ← Bj + AlignmentB
        j ← j − 1
    }
}
```
Once the F matrix is computed, the entry  F nm
​
  gives the maximum score among all possible alignments. To compute an alignment that actually gives this score, you start from the bottom right cell and compare the value with the three possible sources (Match, Insert, and Delete above) to see which it came from.