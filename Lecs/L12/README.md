<!--  
An open reading frame, as related to genomics, is a portion of a DNA sequence that does not include a stop codon (which functions as a stop signal). A codon is a DNA or RNA sequence of three nucleotides (a trinucleotide) that forms a unit of genomic information encoding a particular amino acid or signaling the termination of protein synthesis (stop codon). There are 64 different codons: 61 specify amino acids and 3 are used as stop codons. A long open reading frame is often part of a gene (that is, a sequence directly coding for a protein). -->


# Expect Value (E-value)

E-values represent the number of times an alignment as good or better than that found by BLAST would be expected to occur by chance, considering the size of the searched database.

- **User-Defined Threshold:**
  - The user sets a threshold determining which alignments will be reported.
  - The BLAST default threshold of "10" aims to ensure no biologically significant alignment is overlooked.

- **Commonly Used E-value Ranges:**
  - E-values ranging from 0.001 to 0.0000001 are frequently employed to restrict reported alignments to those of high quality.

# Extreme Value Distribution

Extreme Value Distribution is a statistical concept often used in bioinformatics, particularly in the context of E-values. It represents the distribution of the extreme values from a set of random variables. In BLAST, Extreme Value Distribution helps estimate the significance of reported alignments by assessing the likelihood of obtaining similar or better alignments purely by chance.

E=Kmne^(-lambda*s)


# Molecular Clock Hypothesis

The Molecular Clock Hypothesis posits that for any given gene or protein, the rate of molecular evolution remains relatively constant over time.

- **Originators:**
  - Emil Zuckerkandl, Linus Pauling, and Emanuel Margoliash pioneered this concept.

- **Ideal Scenario:**
  - Ideally, the molecular clock should tick at a constant rate, although this notion is currently debated.

- **Assumption:**
  - The hypothesis assumes that most changes in amino acid and nucleotide sequences are neutral, neither beneficial nor harmful.

## Molecular Clock Development

- In the 1960s, primary amino acid sequence data were gathered for various abundant, soluble proteins across different species.
- Some proteins, like cytochromes c, evolved slowly, while others accumulated numerous substitutions.

## Application of Molecular Clock

- Zuckerkandl, Pauling, and Margoliash examined differences in globins across species.
- By comparing human and gorilla globins, they estimated the divergence time from a common ancestor.
- Fossil evidence suggested that humans and gorillas diverged approximately 11 million years ago.
- Using this calibration point, they estimated the divergence times for gene duplications in different globin families.

## Prevalence of Substitutions

- Not all substitutions occur with equal prevalence:
  - Substitutions are more frequent in introns than in coding regions.
  - They are more common in less vital parts of proteins than in functionally constrained regions.
  - Transitions (A to T or G to C) occur more frequently than transversions.

# Correction for Unseen Substitutions

The original calculations of molecular evolution rates didn't consider unseen substitutions, prompting the need for a correction to account for the relationship between observed changes and actual changes.

## Corrected Number of Amino Acid Changes

The corrected number of amino acid changes per 100 residues, denoted as 'm', was calculated.

## Observations

- **Consistency in Rate of Change:**
  - For each protein, the data points lie on a straight line, indicating a constant rate of change in amino acid sequence over time.
  
- **Distinct Rates of Change:**
  - Different proteins exhibit distinct average rates of change.
  - For example, fibrinopeptides evolve at a much higher rate of substitution compared to cytochrome c and hemoglobin.

- **Time for Evolutionary Change:**
  - The time (in millions of years) for a 1% change in amino acid sequence varies:
    - Cytochrome c: 20.0 MYA
    - Hemoglobin: 5.8 MYA
    - Fibrinopeptides: 1.1 MYA

- **Functional Constraints:**
  - Variations in the rate of change among protein families reflect functional constraints imposed by natural selection.

- **Applicability of the Clock:**
  - The molecular clock hypothesis is applicable only when a gene retains its function over evolutionary time.
 
