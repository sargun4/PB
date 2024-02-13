

- Reference:
1. https://en.wikipedia.org/wiki/Autonomously_replicating_sequence-:~:text=An%20autonomously%20replicating%20sequence%20(ARS,their%20effect%20on%20plasmid%20stability.
2. https://pubmed.ncbi.nlm.nih.gov/9441849/#:~:text=Autonomously%20replicating%20sequence%20(ARS)%20elements%20were%20first%20identified%20in%20the,extrachromosomal%20maintenance%20of%20plasmid%20DNA.
3. https://www.sciencedirect.com/topics/medicine-and-dentistry/autonomously-replicating-sequence

- using the hint given in the q, (S. cerevisiae has an Autonomously Replicating Sequence with features you can search.)
- the ARS that contains the origin of replication in the yeast genome is - "(A/T)TTTA(C/T)(A/G)TTT(A/T)" found in Saccharomyces cerevisiae where 
- the "/" slash shows that it could be either the first base or the second one which will be checked by the code for matching the seq from yeastgenome.gb file.

- "T" is thymine.
- "A" is adenine
- "C" is cytosine (C) 
- "G" is guanine (G)

- So after runnin above code ouput is coming out to be-
 
        Genome sequence downloaded and saved to yeast_genome.gb
        Accession number: NG_047042.3
        ARS sequence ((A/T)TTTA(C/T)(A/G)TTT(A/T)) found at positions(1 based idxing as given in yeastgemone.gb file ): [56946, 65503, 68265]
        Matching entries:
        Sequence: TTTTATGTTTA - Start Index: 56946
        Sequence: TTTTATATTTT - Start Index: 65503
        Sequence: TTTTATATTTT - Start Index: 68265
        First Origin of Replication (ORI) position : 56946




- This means that there are three occurences matching the ars_seq "(A/T)TTTA(C/T)(A/G)TTT(A/T)" and this seq is present in three different chromosomes of the yeast genome, starting at positions 56946, 65503, and 68265.
- The first copy starts at 56946 which after crosschecking from yeast_genome.gb file, is correct- TTTTATGTTTA which matches our ars sequence.
 
 this is a short snippet frm yeast_genome.gb file-

     56941 ctgtat'tttt atgttta'att ataacccctt taggattata atttaaatta atttaaatat
 
 where 56941 denoted the first nucleotides seq starting idx(1 based) and now if we use slicing just to crosscheck our ans 
 "ttttatgttta" is extracted , which starts on the "t" at position 56946.

- Then i used the nt_search function as done in tuts - from Bio.SeqUtils module to search for occurrences of ars_seq "(A/T)TTTA(C/T)(A/G)TTT(A/T)" in the DNA sequence.

- If matches are found, i store them in "matching_entries" list and also their coresponding position from the .gb file

- finally for the ans, I hv taken the first position as the Origin of Replication (ori).
 