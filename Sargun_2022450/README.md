# q1 -Access the NCBI database (https://www.ncbi.nlm.nih.gov/)
#  and download the DNA sequence of the Saccharomyces cerevisiae PDC gene. 

 
- I hv written the code to access ncbi databse and dowlnoad the pdc file in fasta format similar to what was taught in the tuts.

- I am accessing the gene based on accesion no. "MK868028.1" which is the "Saccharomyces cerevisiae strain A1 pyruvate decarboxylase (pdc) gene"
and storing it in pdc.fasta file after downloading it.


 
# q2- Use BLAST (Basic Local Alignment Search Tool) to compare the 
# PDC gene sequence across different Saccharomyces cerevisiae strains and identify SNPs

- i performed blast  on the sequence that i dowlonaded in q1 which had accno  "MK868028.1" using blast tool on ncbi website. 
- then i selected 10 strains for blast analysis which i saved in blast_results.txt -
- the 10 strains which are saved in blast_results.txt are:

Sequences producing significant alignments:
                                                                  Scientific      Common                     Max    Total Query   E   Per.   Acc.                        
Description                                                       Name            Name            Taxid      Score  Score cover Value Ident  Len        Accession        
Saccharomyces cerevisiae strain A1 pyruvate decarboxylase (pdc... Saccharomyce... brewer's yeast  4932       3125   3125  100%  0.0   100.00 1692       MK868028.1       
Saccharomyces cerevisiae strain ySR128 chromosome XII, complet... Saccharomyce... brewer's yeast  4932       3009   4977  100%  0.0   98.76  1076801    CP036478.1       
Saccharomyces cerevisiae strain SY14 chromosome I, complete...    Saccharomyce... brewer's yeast  4932       3009   4977  100%  0.0   98.76  11848804   CP029160.1       
Saccharomyces cerevisiae strain BY4742 chromosome XII, complet... Saccharomyce... brewer's yeast  4932       3009   4977  100%  0.0   98.76  1104511    CP026300.1       
Saccharomyces cerevisiae strain DBVPG6765 chromosome XII sequence Saccharomyce... brewer's yeast  4932       3009   4982  100%  0.0   98.76  1022186    CP020168.1       
Saccharomyces cerevisiae strain S288c chromosome XII sequence     Saccharomyce... brewer's yeast  4932       3009   4977  100%  0.0   98.76  1075542    CP020134.1       
Saccharomyces cerevisiae strain HB_S_GIMBLETTROAD_14 chromosom... Saccharomyce... brewer's yeast  4932       3009   4982  100%  0.0   98.76  1077529    CP008264.1       
Saccharomyces cerevisiae strain HB_C_TUKITUKI1_16 chromosome X... Saccharomyce... brewer's yeast  4932       3009   4982  100%  0.0   98.76  1077438    CP008400.1       
Saccharomyces cerevisiae strain HB_C_TUKITUKI2_10 chromosome X... Saccharomyce... brewer's yeast  4932       3009   4982  100%  0.0   98.76  1077494    CP008383.1       
Saccharomyces cerevisiae strain WI_S_JASA_5 chromosome XII...     Saccharomyce... brewer's yeast  4932       3009   4982  100%  0.0   98.76  1076962    CP008349.1       

- This section lists the strains from the database that produced significant alignments with the query sequence. It includes details such as the scientific name, common name, taxonomic identifier (Taxid), maximum score, total score, query coverage, E-value, percentage identity, alignment length, and accession number.


- then the section 'Alignments' in blast_results.txt file:
provides alignment details between the query sequence and the matching sequences from the database strains.
-It includes information such as the sequence ID, length, score, E-value, identities, gaps, and strand.
The alignment shows the regions between the query sequence and the subject sequence, with '|' representing matching nucleotides, ' ' (empty space) denoting that there is mismatch between the two sequences for the query and the subject and '-' representing that there is gap in either the query or the subject sequence in whichever sequence '-' exists.





### `extract_snps` Function: 

to extract single nucleotide polymorphisms (SNPs) and subject sequences from a BLAST output file.

- **Input**: `blast_file` (path to the BLAST output file)

- **Output**: Two main outputs:
  - `snps`: A list of dictionaries containing information about identified SNPs, including position, query base, and subject base.
  - `subject_sequences_list`: A list of dictionaries containing subject IDs and their corresponding sequences.


- It opens the BLAST output file and reads its content line by line.

- For each line, it checks if it starts with "Query" or "Sbjct". 
  - If it starts with "Query", it extracts the query sequence.
  - If it starts with "Sbjct", it extracts the subject sequence and the subject ID.

- It then compares the query and subject sequences character by character. if the nucleotide bases are different, it indicates a SNP. The position, query base, and subject base are recorded in a dictionary and added to the `snps` list.

-  Subject sequences are stored in a dictionary (`subject_sequences`) with subject IDs as keys. If a subject ID already exists, the sequence is appended to the existing sequence.
- Finally, the `subject_sequences` dictionary is converted into a list of dictionaries, where each dictionary contains a subject ID and its corresponding sequence.
  
- It returns two lists: `identified_snps` containing information about identified SNPs, and `subject_sequences` containing subject IDs and their sequences.

 

# q3 Use an translation tool (e.g., ExPASy Translate tool) to translate the normal 
# and SNP-containing PDC gene sequences into amino acid sequences.

## `translate_dna_to_protein`   
 
- it takes a DNA sequence as input and sends a POST request to the expasy Translate tool's URL
(https://web.expasy.org/cgi-bin/translate/dna2aa.cgi) with the DNA squence and the desired output format ('fasta') as parameters. 
      params = {
              'dna_sequence': dna_sequence,
              'output_format': 'fasta'
          }
- then it sends the POST request using the requests library.
- Finally, it returns the stripped text of the response using 'response.text.strip()', which contains the translated protein sequence from that response

 
## `read_dna_sequence_from_file(fname)`:
This function reads a DNA sequence from a file specified by fname.
It opens the file in read mode and skips the header line using next(file) to get to the sequence.
It then reads and concatenates the DNA sequence lines from the file.
Finally, it returns the concatenated DNA sequence.

## `write_protein_sequence_to_file(protein_sequence, out_file)`:

def write_protein_sequence_to_file(protein_sequence, out_file):
    with open(out_file, 'w') as file:
        file.write(f"  Normal PDC gene translated using ExPASy\n{protein_sequence}")

- write_protein_sequence_to_file function takes the translated protein sequence and the output file path as input arguments and writes the sequence to the specified file. After calling this function, the translated protein sequence will be saved in the "normal_pdctranslated_using_expasy.fasta" file.






### `perform_expasy` Function:
 
it performs expasy analysis on the subject sequences translated into protein.

- it takes `subject_sequences` (a list of dictionaries containing subject IDs and sequences) as input. 

- then i hv initialized an empty list to store protein sequences.

- then i iterate over the sequences and translate each DNA sequence to a protein sequence using the "translate_dna_to_protein" func 
whcih i explained above- 

    for sequence in subject_sequences:
        dna_sequence = sequence["sequence"]
        protein_sequence = translate_dna_to_protein(dna_sequence)
        print(protein_sequence) #add to lsit
        protein_sequences.append(protein_sequence)

- and also i hv included error handling to handle cases where translation fails or invalid characters are present in the protein sequence.

finally, after error handling, i print out the translated protein sequence using-

      print("SNP-containing PDC gene seqs translatedd into amino acid seqs: ",protein_sequence)

# output explanation

- Each entry starts with a header line, indicated by the ">" symbol, followed by a description of the sequence. 

- For example, "VIRT-38694:3'5' Frame 1" indicates that the sequence belongs to the entry with ID "VIRT-38694", it was translated from the 3' to 5' direction, and it corresponds to frame 1 (reading frame).

- Following the header line, there are three lines containing the translated protein sequence, each representing a different reading frame (1, 2, or 3) for the given DNA sequence. The reading frame determines the grouping of nucleotides into codons, which are then translated into amino acids.

- Similarly, there are entries for the 5' to 3' direction, indicated by "VIRT-38694:5'3' Frame 1" for example, and followed by the translated protein sequences in three reading frames.

- The sequences themselves are represented by a series of letters, where each three-letter combination (codon) corresponds to a specific amino acid. These sequences represent the protein sequences translated from the respective DNA sequences.

Each frame provides a different reading of the DNA sequence, starting from a different position, to capture all possible open reading frames for translation.

- and for each alternate line ,the translated fragment of a protein sequence performed by the expasy tool from the code. 
 
- Each amino acid is represented by their corespponding alphabet given below, and gaps ("-") may indicate alignment gaps or regions where the sequence couldn't be confidently translated. 

for example, The sequence "VNVDLL-SFEQIFTQSNFRH" represents a fragment of a protein sequence where each letter corresponds to one of the 20 standard amino acids commonly found in proteins.  

A: Alanine (Ala)
C: Cysteine (Cys)
D: Aspartic acid (Asp)
E: Glutamic acid (Glu)
F: Phenylalanine (Phe)
G: Glycine (Gly)
H: Histidine (His)
I: Isoleucine (Ile)
K: Lysine (Lys)
L: Leucine (Leu)
M: Methionine (Met)
N: Asparagine (Asn)
P: Proline (Pro)
Q: Glutamine (Gln)
R: Arginine (Arg)
S: Serine (Ser)
T: Threonine (Thr)
V: Valine (Val)
W: Tryptophan (Trp)
Y: Tyrosine (Tyr)
-: Gap or alignment character


- 'invalid_chars = set(protein_sequence) - set("ACDEFGHIKLMNPQRSTVWY")' is the set that contains characters found in the protein_sequence that are not part of the 20 amino acids.

- Basically, i have created a set containing the single-letter codes of the 20 amino acids using 'set("ACDEFGHIKLMNPQRSTVWY")' in which each letter represents a specific amino acid acc to above table i gave.

- then 'set(protein_sequence)' converts the 'protein_sequence' string (which contains the translated amino acid sequence) into a set of characters.

- then , i used 'set(protein_sequence) - set("ACDEFGHIKLMNPQRSTVWY")' expression to do set subtraction inorder to remove the set of valid amino acid codes from the set of characters in the protein_sequence.

- and finalyy in invalid_chars, i hv stored the resulting set of characters obtained from the set subtraction. These characters represent any non-standard or unexpected characters found in the protein_sequence. 

- so these invalid chars i skip using- 

          if invalid_chars:
            print(f"Skipping sequence {sequence['subj_id']} if invalid: {invalid_chars}")
            continue



## q4
q4: Performing SIFT Analysis on SNP at Position 233637

- i selected the SNP located at position 233637 of the PDC gene. 
The SNP involves a change from G (guanine) in the query sequence to A (adenine) in the subject sequence.

- then, we need to obtain the normal and SNP-containing protein sequences corresponding to the SNP position. These sequences will be used for SIFT analysis.

- finally-The protein sequences are submitted to the SIFT web server for analysis. This involves formatting the sequences properly and sending them to the SIFT server for prediction.
 
## functgion- 'run_sift_analysis' 
- to perform SIFT analysis on the normal and SNP-containing sequences.
- i sent POST requests to the SIFT web server with the normal and SNP-containing sequences as parameters.
- Then i hv printed SIFT results for both the normal and SNP-containing sequences.
- We extract the normal and SNP-containing sequences around the SNP position.


# References
1. https://www.ncbi.nlm.nih.gov/nuccore/1774854476
2. https://blast.ncbi.nlm.nih.gov/Blast.cgi
3. https://blast.ncbi.nlm.nih.gov/Blast.cgi
4. https://web.expasy.org/translate/
5. https://sift.bii.a-star.edu.sg/
6. https://www.genome.gov/#main-content
7. https://www.genome.gov/genetics-glossary/Single-Nucleotide-Polymorphisms#:~:text=Definition&text=A%20single%20nucleotide%20polymorphism%20abbreviated,drug%20response%20and%20other%20traits.
8. https://www.ebmconsult.com/articles/single-nucleotide-polymorphism-snp-drug-therapy
9. https://www.youtube.com/watch?v=CvaMmJ02ubM
10. https://www.youtube.com/watch?v=WRKQGwh_Mw0
11. https://www.liebertpub.com/doi/full/10.1089/gtmb.2010.0036
12. https://bio.tools/sift


 