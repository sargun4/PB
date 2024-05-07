# PSI-BLAST Simplified Steps

PSI-BLAST (Position-Specific Iterative BLAST) can be understood as a series of iterative steps, which are repeated until convergence is achieved:

## Step 1: Initial BLAST Search
- Perform a blastp search using the query sequence against a chosen database.
- Use a standard scoring matrix such as BLOSUM62.

## Step 2: Identification of Significant Hits
- Identify the most significant hits obtained from the initial BLAST search.

## Step 3: Multiple Sequence Alignment (MSA)
- Build a multiple sequence alignment (MSA) using the significant hits.
- This MSA captures the similarities and differences among the sequences.

## Step 4: Generation of Position-Specific Scoring Matrix (PSSM)
- Use the MSA to generate a position-specific scoring matrix (PSSM).
- Move along each position in the MSA, counting the presence or absence of different residues.
- Highly conserved residues in the alignment are assigned high scores, while less conserved residues receive lower scores.
- This PSSM represents a customized scoring matrix based on the observed conservation patterns.

## Step 5: Iterative Similarity Searching
- Perform another round of similarity searching using the newly generated PSSM.
- This time, the search is conducted using the customized scoring matrix.
- The PSSM is more effective at identifying sequences similar to those found in the initial search.
- Steps 2-4 are repeated iteratively until no new sequences are found in successive rounds of searching, leading to convergence.
