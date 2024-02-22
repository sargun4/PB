<!-- https://en.wikipedia.org/wiki/BLOSUM -->
# BLOSUM: Blocks Substitution Matrix

## Scoring Metrics: Statistical versus Biological

When assessing sequence alignments, a scoring matrix is crucial to determining the biological significance of amino acid or nucleotide residue pairs in an alignment. BLOSUM (Blocks Substitution Matrix) matrices provide these scores based on the frequencies of substitutions in local alignments of protein sequences.

## BLOSUM r

- BLOSUM r represents a matrix constructed from blocks with less than r% similarity.
- Example: BLOSUM62 is built from sequences with less than 62% similarity (sequences with ≥ 62% identity were clustered).
- Note: BLOSUM62 is the default matrix for protein BLAST and is known for effectively detecting weak protein similarities.

## Calculating Frequency & Probability

- BLOSUM matrices are derived from a database storing sequence alignments of the most conserved regions of protein families.
- Only sequences with identity lower than a specified threshold are used.
- Frequency calculation involves counting amino acid pairs in each column of multiple alignments.

## Log Odds Ratio

- The log odds ratio measures the ratio of the observed occurrence of an amino acid pair to the expected occurrence, given the background probabilities of each amino acid.
  
  \[ \text{Log Odds Ratio} = 2 \times \log_2 \left( \frac{P(O)}{P(E)} \right) \]

  Where \( P(O) \) is the probability of observing the pair, and \( P(E) \) is the expected probability.

## BLOSUM Matrices

- BLOSUM matrices are calculated from log odds ratios, rounded off to create substitution matrices.
  
## Score of the BLOSUM Matrices

- Scoring matrices are crucial for evaluating the significance of sequence alignments.
- BLOSUM matrices assign log-odds scores based on observed frequencies in alignments of related proteins.
- Positive scores indicate likely substitutions, while negative scores suggest less likely substitutions.

## Calculation Equation for BLOSUM Matrix (Sij)

\[ S_{ij} = \frac{1}{\lambda} \times \log \left( \frac{p_{ij}}{q_i \times q_j} \right) \]

Where \( p_{ij} \) is the probability of amino acids \( i \) and \( j \) replacing each other, and \( q_i \) and \( q_j \) are background probabilities. \( \lambda \) is a scaling factor for integer values.

## Example - BLOSUM62

- BLOSUM80: More related proteins
- BLOSUM62: Midrange
- BLOSUM45: Distantly related proteins

## Accuracy of BLOSUM62

- A Nature Biotechnology article revealed a discrepancy in BLOSUM62 accuracy according to the Henikoff and Henikoff algorithm.
- Despite the discrepancy, BLOSUM62 has shown improved search performance.

*The BLOSUM matrices play a crucial role in sequence alignment, providing scores that help assess the biological significance of alignments.*


# Use of BLOSUM in BLAST

BLOSUM matrices serve as scoring matrices in sequence alignment tools like BLAST for comparing DNA or protein sequences. This scoring system evaluates the quality of alignments and is widely employed in various alignment software, including BLAST.

## Comparing PAM and BLOSUM

PAM (Point Accepted Mutation) and BLOSUM matrices are two approaches to scoring matrices, resulting in comparable scoring outcomes but utilizing different methodologies:

- **BLOSUM Methodology:**
  - Directly examines mutations in motifs of related sequences.

- **PAM Methodology:**
  - Extrapolates evolutionary information based on closely related sequences.

While PAM and BLOSUM yield similar scoring information, they cannot be directly equated. For example, PAM100 does not equate to BLOSUM100.

## Relationship between PAM and BLOSUM

| PAM      | BLOSUM   |
|----------|----------|
| PAM100   | BLOSUM90 |
| PAM120   | BLOSUM80 |
| PAM160   | BLOSUM62 |
| PAM200   | BLOSUM50 |
| PAM250   | BLOSUM45 |

- **To Compare Closely Related Sequences:**
  - PAM matrices with lower numbers are created.

- **To Compare Distantly Related Proteins:**
  - BLOSUM matrices with higher numbers are created.

## Differences between PAM and BLOSUM

| PAM                                        | BLOSUM                                     |
|--------------------------------------------|--------------------------------------------|
| Based on global alignments of closely related proteins. | Based on local alignments.                  |
| PAM1 is the matrix from comparisons of sequences with ≤ 1% divergence, corresponding to 99% sequence identity. | BLOSUM62 is calculated from sequences with pairwise identity ≤ 62%. |
| Other PAM matrices are extrapolated from PAM1. | BLOSUM matrices are based on observed alignments without extrapolation. |
| Higher numbers denote larger evolutionary distance. | Larger numbers denote higher sequence similarity, indicating smaller evolutionary distance. |

https://image1.slideserve.com/3391068/pam-vs-blosum-l.jpg


