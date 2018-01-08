# ngs_rescue
Rescue NGS result which failed to sort

## Install

Suppose you have cloned at ~/Downloads

```
$ git clone https://github.com/tahuh/ngs_rescue.git
$ cd ~/Downloads/ngs_rescue
# make
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
    -s     BOOL   Strictly compare index information. Default = NO
    -S     BOOL   Use single index
```
