# ngs_rescue
Rescue NGS result which failed to sort

## Install

Suppose you have cloned at ~/Downloads

```
$ git clone https://github.com/tahuh/ngs_rescue.git
$ cd ~/Downloads/ngs_rescue
$ make
```

## Usage

```
./rescue_ngs [options] undet1.fq <undet2.fq...>
[Options]
    -e     INT    tolerate untill INT mismatches. Default = 1
    -f     STR    p5_index(fwd in D.Bang's Lab). Required. Always must be set
    -r     STR    p7_index(rev in D. Bang's lab) 
    -u     BOOL   If set, will not apply reverse complement to reverse illumina index ( dfault = ON )
    -o     STR    Output prefix. Deault : <fwd_index>-<rev_index>_1.fq and 2.fq
                  If set as some value OUTPUT then OUTPUT_1.fq and OUTPUT_2.fq will be generated
                  Must be set with FULL PATH
    -s     BOOL   Strictly compare index information. Default = NO
    -S     BOOL   Use single index
    
Example usage
Please check if barcodes 
case A. p5 + p7 style 
case B. p7 + reverse_complement(p5) stype
if case A then add -u on your command line

Here is real life example
Case 1. When one wants to extract NGS reads with barcode sequence p5: ATATATAT and p7: CTCTCTCT without allowing mismatch
If we are in case A then 
./rescue_ngs \
-u \
-e 0 \
-f ATATATATAT -r CTCTCTCTCT \
-o /some/where/your/output/directory/prefix \
undetermined_1.fasta.gz undetermined_read2.fastq.gz

Or in case B
./rescue_ngs \
-e 0 \
-f ATATATATAT -r CTCTCTCTCT \
-o /some/where/your/output/directory/prefix \
undetermined_1.fasta.gz undetermined_read2.fastq.gz

Case 2. Whe one wants to extrac NGS read with barcode sequence p5: ATATATAT and p7: CTCTCTCT without allowing mismatch k
If we are in case A then 
./rescue_ngs \
-u \
-e k \
-f ATATATATAT -r CTCTCTCTCT \
-o /some/where/your/output/directory/prefix \
undetermined_1.fasta.gz undetermined_read2.fastq.gz

Or in case B
./rescue_ngs \
-e k \
-f ATATATATAT -r CTCTCTCTCT \
-o /some/where/your/output/directory/prefix \
undetermined_1.fasta.gz undetermined_read2.fastq.gz
```
