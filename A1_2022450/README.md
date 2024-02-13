

- Reference:
1. https://en.wikipedia.org/wiki/Autonomously_replicating_sequence-:~:text=An%20autonomously%20replicating%20sequence%20(ARS,their%20effect%20on%20plasmid%20stability.
2. https://pubmed.ncbi.nlm.nih.gov/9441849/#:~:text=Autonomously%20replicating%20sequence%20(ARS)%20elements%20were%20first%20identified%20in%20the,extrachromosomal%20maintenance%20of%20plasmid%20DNA.
3. https://www.sciencedirect.com/topics/medicine-and-dentistry/autonomously-replicating-sequence
4. https://en.wikipedia.org/wiki/Baker%27s_yeast
5. https://en.wikipedia.org/wiki/Autonomously_replicating_sequence
6. https://www.ncbi.nlm.nih.gov/search/all/?term=Saccharomyces+cerevisiae
7. https://www.ncbi.nlm.nih.gov/genome/?term=Saccharomyces%20cerevisiae%5BOrganism%5D&cmd=DetailsSearch#:~:text=The%20Saccharomyces%20cerevisiae%20genome%20is,Mb%2C%20organized%20in%2016%20chromosomes.



1.Download and save genome sequences

- i used the the Entrez and SeqIO modules from Bio library, to download and save the genome sequences 
of baker's yeast by taking the list of accession numbers for the 16 chromosomes which i found after refering to the above links and saved the corresponding sequences to a bakersyeast.fasta file
    
        
2.Origin of replication (ORI) for each chromosome

- using the hint given in the q, (S. cerevisiae has an Autonomously Replicating Sequence(ARS) with features you can search.)
- the ARS that contains the origin of replication(ori) in the yeast genome is - "(A/T)TTTA(C/T)(A/G)TTT(A/T)" found in Saccharomyces cerevisiae which i found from the sequence given from the above links
 where 
- "T" is thymine.
- "A" is adenine
- "C" is cytosine
- "G" is guanine
and 
- the "/" slash shows that it could be either the first base or the second one within the brackets around it, which 
will be checked by the code for matching the seq "(A/T)TTTA(C/T)(A/G)TTT(A/T)"  from bakersyeast.fasta file.

so i set ars_seq="(A/T)TTTA(C/T)(A/G)TTT(A/T)"

and usedd regex module for the matching since we hv to detect this kind of pattern from the bakersyeast.fasta file.

- now to search for the seqs in chromosomes' sequence, i used 

        ars_matches = [match.start() for match in ars_pattern.finditer(dna_seq)]

in order to find all occurrences of the ARS sequence in the dna_seq
and get their start pos using start()func

then an arr matching_entries to store information about each matching sequence, if incase that particular sequence matches the ars_seq i had set initialy and first_ori_position to store the position of the first ori.
and i also stored total_entries which would simply be the len(matching_entries) that match the ars_seq.


for this part of the code-
                if ars_matches:
                        for ori_posn in ars_matches:
                        matching_entry = record[ori_posn : ori_posn + 11] #11 is the len of the ars_seq that i hv chosen as mentioned in readme
                        matching_entries.append((matching_entry.id, str(matching_entry.seq), ori_posn))

                        if first_ori_position is None: #first ori ocuuring for a chromosme for a matching seq to arsseq stored
                                first_ori_position = ori_posn 
i have put a check if ars_matches(which is a list that i stored above) is not None, then we'll go inside the if condn to extract the matching entries from the list.

So in this, the length of ars_seq is 11 since ars_seq="(A/T)TTTA(C/T)(A/G)TTT(A/T)" and total bases that can come in the matching entry bracket would be of size 11.
then once all matching entries are found, i append them to matching_entries along with their id and startingidx in the dna sequence.

- finally for the ans, I hv taken the first elmmnt from  
        start_idxs=[entry[2] for entry in matching_entries]

which would be start_idxs[0] as the ori for each of the chromosome

 
- So after runnin the code, the ouput for the first chromosome is coming out to be-


            Chromosome NC_001133.9: Matching entries:
            all the  entries matcjhing to arsseq:   [('NC_001133.9', 'ATTTATGTTTA', 17149), ('NC_001133.9', 'ATTTATATTTA', 159953), ('NC_001133.9', 'ATTTACGTTTA', 171816), ('NC_001133.9', 'TTTTATGTTTT', 176236), ('NC_001133.9', 'ATTTATATTTA', 176522), ('NC_001133.9', 'TTTTATATTTA', 208605), ('NC_001133.9', 'TTTTATATTTA', 229450)]
            Sequence: ATTTATGTTTA - Start Index: 17149
            Sequence: ATTTATATTTA - Start Index: 159953
            Sequence: ATTTACGTTTA - Start Index: 171816
            Sequence: TTTTATGTTTT - Start Index: 176236
            Sequence: ATTTATATTTA - Start Index: 176522
            Sequence: TTTTATATTTA - Start Index: 208605
            Sequence: TTTTATATTTA - Start Index: 229450
            First Origin of Replication (ORI) position: 17149


- This means that there are total 7 occurences matching the ars_seq "(A/T)TTTA(C/T)(A/G)TTT(A/T)" and this seq is
 present in 7 different chromosomes of the yeast genome, starting at 
 positions: 17149, 159953, 171816, 176236, 176522, 208605, 229450

- for the first chromosome, using normal slicing,the 17149th idx is the first position observed that matches ars_seq - 
which after crosschecking from bakersyeast.fasta file, is correct- ATTTATGTTTA which matches our ars sequence ars_seq
  therfore i use this as my ori positiion for the 1st chromosome

- similalry, for all the other 15 chromosomes, the ouput is printed as matching seq and the starting idx for that
 patticulr sequence that has matched ars_seq.and then the first posn i take as the first entry(0th idx) in matching 
 entries from the ori_posn from matching_entries list of tuples. 
  
- and finally i store all the ori positions in out.txt file

