# Empirical Statistical Verification of the xoshiro256** PRNG

This repository hosts a high-volume collection of independent statistical tests for the **xoshiro256**** pseudo-random number generator.  
Featuring 300 TestU01 BigCrush suites and 10 multi-gigabyte PractRand deployments across randomized seeds, this dataset serves as a robust reference point for PRNG benchmarking and quality comparison.

# TestU01
Number of session tests: 100  
Number of big_crush runs: 300  
Nomber of TestU01 statistics: 48000  
Number of failures: 0  
Number of anomalies: 118  
Number of anomalies expected: 96.0  

|Runs|high32|mid32|low32|**Total**|
|----|------|-----|-----|---------|
|With anomalies|36|29|31|**96**|
|Without anomalies|64|71|69|**204**|
|**Total**|**100**|**100**|**100**|**300**|

### Details of anomalies for each session test
| Test | high32 | mid32 | low32 |
|------|--------|--------|--------|
|00|-|-|-|
|01|-|9 CollisionOver, t = 14 (6.0e-4)|70 MatrixRank, L=5000 (6.9e-5)|
|02|-|-|24 ClosePairs mNP2, t = 9 (0.9997)|
|03|-|56 SampleCorr, k = 2 (7.4e-4);<br>74 RandomWalk1 J (L=50, r=0) (0.9991)|68 MatrixRank, L=1000, r=0 (0.9991)|
|04|-|-|-|
|05|-|-|91 HammingWeight2, r = 27 (4.4e-4)|
|06|-|-|-|
|07|-|-|75 RandomWalk1 C (L=50, r=25) (0.9997)|
|08|75 RandomWalk1 M (L=50, r=25) (0.9994)|21 BirthdaySpacings, t = 16 (1.3e-4)|78 RandomWalk1 H (L=10000, r=0) (0.9999)|
|09|-|-|-|
|10|-|11 CollisionOver, t = 21 (0.9994)|-|
|11|-|-|8 CollisionOver, t = 7 (0.9995)|
|12|79 RandomWalk1 H (L=10000, r=15) (8.6e-4)|-|-|
|13|-|-|-|
|14|-|-|-|
|15|-|-|-|
|16|-|-|-|
|17|11 CollisionOver, t = 21 (0.9999)|-|-|
|18|84 Fourier3, r = 0 (0.9991)|-|-|
|19|-|2 SerialOver, r = 22 (9.6e-4)|50 SampleProd, t = 8 (4.7e-4)|
|20|7 CollisionOver, t = 7 (0.9996)|68 MatrixRank, L=1000, r=0 (0.9991);<br>96 HammingIndep, L=30, r=27 (9.6e-5)|41 Permutation, t = 5 (0.9998)|
|21|99 HammingIndep, L=1200, r=0 (0.9998)|-|-|
|22|-|25 ClosePairs mNP1, t = 16 (9.0e-4);<br>100 HammingIndep, L=1200, r=25 (1 - 1.2e-5)|-|
|23|-|-|77 RandomWalk1 R (L=1000, r=20) (0.9991)|
|24|37 Gap, r = 20 (0.9999)|78 RandomWalk1 M (L=10000, r=0) (7.2e-4)|-|
|25|55 SampleCorr, k = 1 (0.9996)|-|-|
|26|-|78 RandomWalk1 J (L=10000, r=0) (0.9993)|-|
|27|-|-|62 WeightDistrib, r = 0 (9.4e-4)|
|28|-|-|-|
|29|-|-|89 PeriodsInStrings, r = 20 (0.9991)|
|30|-|-|-|
|31|37 Gap, r = 20 (0.9994)|-|-|
|32|-|-|-|
|33|-|-|-|
|34|12 CollisionOver, t = 21 (1 - 3.4e-5)|-|-|
|35|16 BirthdaySpacings, t = 7 (0.9996);<br>28 SimpPoker, r = 0 (0.9997)|-|-|
|36|-|12 CollisionOver, t = 21 (6.7e-5);<br>78 RandomWalk1 R (L=10000, r=0) (0.9995)|-|
|37|-|11 CollisionOver, t = 21 (0.9998)|15 BirthdaySpacings, t = 4 (8.8e-4)|
|38|-|-|-|
|39|-|-|102 Run of bits, r = 27 (0.9992)|
|40|-|-|-|
|41|-|-|-|
|42|19 BirthdaySpacings, t = 8 (9.2e-5)|105 AutoCor, d=1, r=27 (5.5e-4)|-|
|43|64 WeightDistrib, r = 26 (9.3e-4)|-|-|
|44|31 CouponCollector, r = 10 (4.2e-4);<br>79 RandomWalk1 C (L=10000, r=15) (8.7e-4)|-|-|
|45|-|-|86 LongestHeadRun, r = 0 (0.9990)|
|46|-|-|-|
|47|-|-|-|
|48|37 Gap, r = 20 (3.6e-4)|53 SampleMean, r = 0 (0.9991)|3 CollisionOver, t = 2 (4.1e-4)|
|49|25 ClosePairs mNP, t = 16 (5.1e-5)|-|-|
|50|-|74 RandomWalk1 C (L=50, r=0) (4.9e-5)|-|
|51|22 ClosePairs mNP, t = 3 (0.9990)|-|77 RandomWalk1 M (L=1000, r=20) (7.1e-4)|
|52|-|2 SerialOver, r = 22 (1 - 3.8e-5)|42 Permutation, t = 7 (2.0e-4);<br>65 SumCollector (8.0e-4)|
|53|-|76 RandomWalk1 M (L=1000, r=0) (0.9996)|-|
|54|-|-|75 RandomWalk1 M (L=50, r=25) (0.9992)|
|55|-|-|-|
|56|-|-|-|
|57|-|-|-|
|58|81 LinearComp, r = 0 (0.9990)|-|-|
|59|-|-|-|
|60|76 RandomWalk1 M (L=1000, r=0) (0.9997)|-|-|
|61|-|-|77 RandomWalk1 C (L=1000, r=20) (3.3e-5)|
|62|-|-|18 BirthdaySpacings, t = 8 (5.9e-4);<br>52 SampleProd, t = 24 (2.1e-4)|
|63|75 RandomWalk1 C (L=50, r=25) (8.6e-4)|-|31 CouponCollector, r = 10 (6.2e-4)|
|64|79 RandomWalk1 H (L=10000, r=15) (0.9994);<br>88 PeriodsInStrings, r = 0 (1.4e-4)|11 CollisionOver, t = 21 (0.9999);<br>102 Run of bits, r = 27 (4.0e-4)|-|
|65|10 CollisionOver, t = 14 (1 - 5.9e-6)|-|-|
|66|10 CollisionOver, t = 14 (8.6e-4);<br>18 BirthdaySpacings, t = 8 (0.9999);<br>100 HammingIndep, L=1200, r=25 (7.3e-4)|-|-|
|67|77 RandomWalk1 R (L=1000, r=20) (0.9990)|-|-|
|68|-|-|-|
|69|-|-|-|
|70|-|11 CollisionOver, t = 21 (0.9998);<br>68 MatrixRank, L=1000, r=0 (0.9994)|-|
|71|77 RandomWalk1 C (L=1000, r=20) (0.9994)|93 HammingCorr, L = 300 (7.6e-4)|-|
|72|-|-|-|
|73|20 BirthdaySpacings, t = 16 (9.9e-4);<br>62 WeightDistrib, r = 0 (0.9996)|-|-|
|74|24 ClosePairs NP, t = 9 (1.9e-5);<br>87 LongestHeadRun, r = 27 (5.7e-4)|48 MaxOft AD, t = 24 (0.9993)|-|
|75|48 MaxOft, t = 24 (0.9997)|-|-|
|76|-|-|-|
|77|36 Gap, r = 0 (0.9993)|-|17 BirthdaySpacings, t = 7 (0.9994);<br>43 Permutation, t = 10 (1 - 4.1e-5)|
|78|-|-|-|
|79|-|-|24 ClosePairs mNP, t = 9 (0.9993);<br>59 WeightDistrib, r = 0 (7.1e-5)|
|80|-|100 HammingIndep, L=1200, r=25 (2.6e-4)|-|
|81|79 RandomWalk1 M (L=10000, r=15) (1 - 1.7e-5)|-|-|
|82|-|-|79 RandomWalk1 J (L=10000, r=15) (1 - 5.7e-5)|
|83|87 LongestHeadRun, r = 27 (5.3e-4);<br>95 HammingIndep, L=30, r=0 (0.9990)|36 Gap, r = 0 (0.9993)|-|
|84|-|103 AutoCor, d=1, r=0 (3.9e-4)|11 CollisionOver, t = 21 (0.9992)|
|85|-|-|-|
|86|-|74 RandomWalk1 R (L=50, r=0) (0.9997)|-|
|87|-|-|-|
|88|-|-|-|
|89|31 CouponCollector, r = 10 (1.9e-4)|-|-|
|90|-|56 SampleCorr, k = 2 (7.4e-5)|12 CollisionOver, t = 21 (4.1e-4);<br>25 ClosePairs mNP1, t = 16 (0.9998);<br>75 RandomWalk1 M (L=50, r=25) (0.9991)|
|91|-|23 ClosePairs mNP2, t = 5 (0.9992)|22 ClosePairs NP, t = 3 (0.9999);<br>76 RandomWalk1 R (L=1000, r=0) (0.9997)|
|92|77 RandomWalk1 J (L=1000, r=20) (0.9994);<br>94 HammingCorr, L = 1200 (0.9994)|71 MatrixRank, L=5000 (4.0e-4)|-|
|93|74 RandomWalk1 R (L=50, r=0) (5.2e-4)|11 CollisionOver, t = 21 (7.8e-4)|-|
|94|-|-|65 SumCollector (8.9e-4)|
|95|-|-|-|
|96|81 LinearComp, r = 29 (0.9993)|11 CollisionOver, t = 21 (1 - 1.8e-5)|-|
|97|36 Gap, r = 0 (0.9991)|-|12 CollisionOver, t = 21 (9.2e-5)|
|98|-|-|79 RandomWalk1 R (L=10000, r=15) (9.0e-4)|
|99|-|-|-|

### Ranking by frequency of anomalies
|Anomaly|high32|mid32|low32|
|-------|------|-----|-----|
|11 CollisionOver, t = 21|1|6|1|
|79 RandomWalk1 H (L=10000, r=15)|4|0|2|
|77 RandomWalk1 R (L=1000, r=20)|3|0|3|
|75 RandomWalk1 C (L=50, r=25)|2|0|3|
|74 RandomWalk1 J (L=50, r=0)|1|3|0|
|78 RandomWalk1 H (L=10000, r=0)|0|3|1|
|12 CollisionOver, t = 21|1|1|2|
|24 ClosePairs mNP2, t = 9|1|0|2|
|68 MatrixRank, L=1000, r=0|0|2|1|
|25 ClosePairs mNP1, t = 16|1|1|1|
|100 HammingIndep, L=1200, r=25|1|2|0|
|37 Gap, r = 20|3|0|0|
|31 CouponCollector, r = 10|2|0|1|
|76 RandomWalk1 M (L=1000, r=0)|1|1|1|
|36 Gap, r = 0|2|1|0|
|56 SampleCorr, k = 2|0|2|0|
|2 SerialOver, r = 22|0|2|0|
|62 WeightDistrib, r = 0|1|0|1|
|102 Run of bits, r = 27|0|1|1|
|22 ClosePairs mNP, t = 3|1|0|1|
|65 SumCollector|0|0|2|
|81 LinearComp, r = 0|2|0|0|
|18 BirthdaySpacings, t = 8|1|0|1|
|10 CollisionOver, t = 14|2|0|0|
|87 LongestHeadRun, r = 27|2|0|0|
|48 MaxOft AD, t = 24|1|1|0|
|9 CollisionOver, t = 14|0|1|0|
|70 MatrixRank, L=5000|0|0|1|
|91 HammingWeight2, r = 27|0|0|1|
|21 BirthdaySpacings, t = 16|0|1|0|
|8 CollisionOver, t = 7|0|0|1|
|84 Fourier3, r = 0|1|0|0|
|50 SampleProd, t = 8|0|0|1|
|7 CollisionOver, t = 7|1|0|0|
|96 HammingIndep, L=30, r=27|0|1|0|
|41 Permutation, t = 5|0|0|1|
|99 HammingIndep, L=1200, r=0|1|0|0|
|55 SampleCorr, k = 1|1|0|0|
|89 PeriodsInStrings, r = 20|0|0|1|
|16 BirthdaySpacings, t = 7|1|0|0|
|28 SimpPoker, r = 0|1|0|0|
|15 BirthdaySpacings, t = 4|0|0|1|
|19 BirthdaySpacings, t = 8|1|0|0|
|105 AutoCor, d=1, r=27|0|1|0|
|64 WeightDistrib, r = 26|1|0|0|
|86 LongestHeadRun, r = 0|0|0|1|
|53 SampleMean, r = 0|0|1|0|
|3 CollisionOver, t = 2|0|0|1|
|42 Permutation, t = 7|0|0|1|
|52 SampleProd, t = 24|0|0|1|
|88 PeriodsInStrings, r = 0|1|0|0|
|93 HammingCorr, L = 300|0|1|0|
|20 BirthdaySpacings, t = 16|1|0|0|
|17 BirthdaySpacings, t = 7|0|0|1|
|43 Permutation, t = 10|0|0|1|
|59 WeightDistrib, r = 0|0|0|1|
|95 HammingIndep, L=30, r=0|1|0|0|
|103 AutoCor, d=1, r=0|0|1|0|
|23 ClosePairs mNP2, t = 5|0|1|0|
|94 HammingCorr, L = 1200|1|0|0|
|71 MatrixRank, L=5000|0|1|0|
|**Total**|**45**|**35**|**38**|
|**Expected**|**32.0**|**32.0**|**32.0**|

### Interval p-value distribution
|p-value Interval|Found|**Expected**|
|----------------|-----|--------|
|[1.0e-4, 1.0e-3)|93|**86.4**|
|[1.0e-5, 1.0e-4)|24|**8.6**|
|[1.0e-6, 1.0e-5)|1|**0.9**|
|[1.0e-7, 1.0e-6)|0|**0.1**|
|[1.0e-8, 1.0e-7)|0|**0.0**|
|[0, 1.0e-7)     |0|**0.0**|
|**Total**       |**118**|**96.0**|

### Top/Bottom p-value distribuition
This table displays the breakdown of p-values ​​close to 1 (top) and close to 0 (bottom); in an ideal uniform distribution the values ​​should be equal.  
|    |high32 | mid32 | low32 |**Total**|
|----|-------|-------|-------|---------|
|Top |28|18|20|**66**|
|Bottom|17|17|18|**52**|
|**Total**|**45**|**35**|**38**|**118**|

### Statistical of p-values
|    |high32 | mid32 | low32 |
|----|-------|-------|-------|
|Top Average|0.9995|0.9995|0.9995|
|Top Max Value|1 - 5.9e-6|1 - 1.2e-5|1 - 4.1e-5|
|Top Min Value|0.9990|0.9991|0.9990|
|Top Standard Deviation|0.001698|0.001332|0.001493|
|Bottom Average|5.29e-4|4.63e-4|4.85e-4|
|Bottom Max Value|9.9e-4|9.6e-4|9.4e-4|
|Bottom Min Value|1.9e-5|4.9e-5|3.3e-5|
|Bottom Standard Deviation|0.001359|0.001255|0.001324|


