# xoshiro256** statistical tests
Comprehensive benchmark of xoshiro256** 

## TestU01 crush
Low32 with anomalies: 30  
Low32 without anomalies: 70  
Mid32 with anomalies: 26  
Mid32 without anomalies: 74  
High32 with anomalies: 35  
High32 without anomalies: 65  

Total low32 anomalies: 34  
Total mid32 anomalies: 28  
Total high32 anomalies: 41  


| Test | high32 | mid32 | low32 |
|------|--------|--------|--------|
|00|-|10 CollisionOver, t = 20 (4.3e-4)|-|
|01|-|-|-|
|02|71 LinearComp, r = 0 (1.5e-4)|-|15 BirthdaySpacings, t = 7 (0.9999)|
|03|21 ClosePairsBitMatch, t = 2 (4.4e-4)|-|-|
|04|-|-|-|
|05|-|-|-|
|06|-|68 RandomWalk1 C (L = 1000) (3.9e-4)<br>69 RandomWalk1 C (L = 10000) (3.9e-4)<br>91 Run of bits, r = 0 (0.9996)|9 CollisionOver, t = 20 (8.0e-4)|
|07|-|-|-|
|08|-|14 BirthdaySpacings, t = 7 (8.0e-4)|-|
|09|1 SerialOver, t = 2 (4.6e-4)|54 WeightDistrib, r = 24 (5.8e-5)|19 ClosePairs mNP1, t = 3 (0.9994)|
|10|-|-|-|
|11|61 MatrixRank, 1200 x 1200 (8.8e-4)|-|-|
|12|46 SampleProd, t = 30 (0.9998)|-|-|
|13|-|-|3 CollisionOver, t = 2 (9.3e-4)|
|14|-|-|-|
|15|-|-|-|
|16|-|-|-|
|17|-|-|37 Permutation, r = 0 (0.9998)<br>70 RandomWalk1 M (L = 10000) (0.9997)|
|18|33 Gap, r = 0 (8.1e-4)|65 RandomWalk1 J (L = 90) (3.2e-4)|-|
|19|-|19 ClosePairs mNP2, t = 3 (4.8e-5)|-|
|20|-|-|91 Run of bits, r = 0 (6.7e-5)|
|21|59 MatrixRank, 300 x 300 (0.9998)|89 HammingIndep, L = 1200 (6.6e-4)|65 RandomWalk1 J (L = 90) (9.4e-4)|
|22|-|-|-|
|23|-|-|-|
|24|-|54 WeightDistrib, r = 24 (0.9997)|-|
|25|51 WeightDistrib, r = 0 (0.9990)<br>72 LinearComp, r = 29 (0.9993)|-|31 Gap, r = 0 (1.0e-3)|
|26|-|-|-|
|27|85 HammingIndep, L = 30 (1 - 3.1e-5)|-|9 CollisionOver, t = 20 (1.0e-5)|
|28|-|-|-|
|29|-|37 Permutation, r = 0 (0.9991)|-|
|30|-|9 CollisionOver, t = 20 (6.9e-4)|18 ClosePairs mNP1, t = 2 (9.9e-4)|
|31|28 CouponCollector, d = 4 (5.6e-4)|9 CollisionOver, t = 20 (1.1e-4)|-|
|32|-|85 HammingIndep, L = 30 (0.9998)|-|
|33|-|-|-|
|34|66 RandomWalk1 M (L = 90) (1.1e-4)|-|85 HammingIndep, L = 30 (1.0e-3)|
|35|-|92 Run of bits, r = 20 (6.3e-4)|-|
|36|10 CollisionOver, t = 20 (0.9998)|41 MaxOft, t = 5 (0.9995)|-|
|37|-|-|-|
|38|-|-|-|
|39|-|-|-|
|40|-|48 SampleCorr (5.0e-4)|19 ClosePairs mNP, t = 3 (8.4e-4)<br>63 GCD, r = 0 (0.9997)|
|41|7 CollisionOver, t = 8 (8.0e-4)|90 HammingIndep, L = 1200 (7.4e-4)|-|
|42|9 CollisionOver, t = 20 (8.0e-4)<br>68 RandomWalk1 M (L = 1000) (0.9992)|-|-|
|43|36 Run of U01, r = 15 (8.6e-4)<br>77 LongestHeadRun, r = 20 (1.7e-4)|-|54 WeightDistrib, r = 24 (0.9995)<br>69 RandomWalk1 R (L = 10000) (0.9997)|
|44|-|-|2 SerialOver, t = 4 (8.6e-4)<br>54 WeightDistrib, r = 24 (0.9996)|
|45|-|-|-|
|46|10 CollisionOver, t = 20 (3.7e-6)|-|-|
|47|-|-|9 CollisionOver, t = 20 (1 - 4.3e-5)|
|48|-|-|-|
|49|-|-|-|
|50|-|-|80 HammingWeight2, r = 0 (0.9993)|
|51|-|-|23 SimpPoker, d = 16 (0.9996)|
|52|70 RandomWalk1 H (L = 10000) (8.2e-4)|-|-|
|53|61 MatrixRank, 1200 x 1200 (6.1e-4)|-|62 Savir2 (3.4e-4)|
|54|52 WeightDistrib, r = 8 (9.0e-4)|-|-|
|55|-|-|-|
|56|-|-|-|
|57|-|-|47 SampleMean (8.8e-4)|
|58|66 RandomWalk1 R (L = 90) (7.9e-4)|-|-|
|59|-|-|-|
|60|13 BirthdaySpacings, t = 4 (2.3e-4)|-|-|
|61|18 ClosePairs mNP2, t = 2 (0.9996)|60 MatrixRank, 1200 x 1200 (3.8e-5)|-|
|62|-|-|-|
|63|-|-|-|
|64|-|13 BirthdaySpacings, t = 4 (1.4e-4)|69 RandomWalk1 J (L = 10000) (0.9991)|
|65|25 SimpPoker, d = 64 (7.3e-4)|-|-|
|66|2 SerialOver, t = 4 (8.7e-4)<br>52 WeightDistrib, r = 8 (2.7e-4)<br>67 RandomWalk1 M (L = 1000) (0.9997)|-|-|
|67|-|1 SerialOver, t = 2 (0.9998)|-|
|68|9 CollisionOver, t = 20 (8.0e-4)|6 CollisionOver, t = 4 (0.9999)|69 RandomWalk1 C (L = 10000) (1 - 9.2e-5)|
|69|-|-|4 CollisionOver, t = 2 (0.9996)|
|70|65 RandomWalk1 R (L = 90) (4.9e-4)|47 SampleMean (6.8e-4)|-|
|71|-|-|-|
|72|45 SampleProd, t = 10 (1.6e-5)<br>91 Run of bits, r = 0 (0.9992)|-|-|
|73|-|-|-|
|74|25 SimpPoker, d = 64 (2.2e-4)|-|-|
|75|-|-|-|
|76|83 HammingCorr, L = 300 (2.0e-4)|-|-|
|77|33 Gap, r = 0 (0.9991)|-|-|
|78|-|7 CollisionOver, t = 8 (0.9998)|-|
|79|-|28 CouponCollector, d = 4 (1.6e-4)|-|
|80|-|-|67 RandomWalk1 M (L = 1000) (0.9994)|
|81|-|-|41 MaxOft, t = 5 (0.9992)|
|82|-|-|-|
|83|-|-|66 RandomWalk1 R (L = 90) (0.9991)|
|84|-|66 RandomWalk1 M (L = 90) (6.2e-4)|61 MatrixRank, 1200 x 1200 (8.6e-4)|
|85|-|-|-|
|86|91 Run of bits, r = 0 (8.3e-4)|-|-|
|87|86 HammingIndep, L = 30 (5.3e-4)|-|-|
|88|29 CouponCollector, d = 16 (0.9998)|-|-|
|89|-|-|56 MatrixRank, 60 x 60 (5.4e-4)|
|90|-|-|-|
|91|-|43 MaxOft, t = 20 (0.9995)|-|
|92|-|-|-|
|93|-|-|79 PeriodsInStrings, r = 15 (4.4e-4)|
|94|20 ClosePairs NP, t = 7 (1.2e-4)|-|-|
|95|-|-|20 ClosePairs NP, t = 7 (0.9991)|
|96|-|-|-|
|97|-|-|-|
|98|-|-|5 CollisionOver, t = 4 (0.9994)|
|99|76 LongestHeadRun, r = 0 (0.9999)|93 AutoCor, d = 1 (3.7e-4)|-|

|Anomaly | high32 | mid32 | low32 |
|----|-------|-------|-------|
|9 CollisionOver, t = 20|2|2|3|
|69 RandomWalk1 C (L = 10000)|0|1|3|
|91 Run of bits, r = 0|2|1|1|
|54 WeightDistrib, r = 24|0|2|2|
|66 RandomWalk1 M (L = 90)|2|1|1|
|10 CollisionOver, t = 20|2|1|0|
|19 ClosePairs mNP1, t = 3|0|1|2|
|61 MatrixRank, 1200 x 1200|2|0|1|
|65 RandomWalk1 J (L = 90)|1|1|1|
|85 HammingIndep, L = 30|1|1|1|
|68 RandomWalk1 C (L = 1000)|1|1|0|
|1 SerialOver, t = 2|1|1|0|
|37 Permutation, r = 0|0|1|1|
|70 RandomWalk1 M (L = 10000)|1|0|1|
|33 Gap, r = 0|2|0|0|
|18 ClosePairs mNP1, t = 2|1|0|1|
|28 CouponCollector, d = 4|1|1|0|
|41 MaxOft, t = 5|0|1|1|
|7 CollisionOver, t = 8|1|1|0|
|2 SerialOver, t = 4|1|0|1|
|52 WeightDistrib, r = 8|2|0|0|
|47 SampleMean|0|1|1|
|13 BirthdaySpacings, t = 4|1|1|0|
|25 SimpPoker, d = 64|2|0|0|
|67 RandomWalk1 M (L = 1000)|1|0|1|
|20 ClosePairs NP, t = 7|1|0|1|
|71 LinearComp, r = 0|1|0|0|
|15 BirthdaySpacings, t = 7|0|0|1|
|21 ClosePairsBitMatch, t = 2|1|0|0|
|14 BirthdaySpacings, t = 7|0|1|0|
|46 SampleProd, t = 30|1|0|0|
|3 CollisionOver, t = 2|0|0|1|
|19 ClosePairs mNP2, t = 3|0|1|0|
|91 Run of bits, r = 0|0|0|1|
|59 MatrixRank, 300 x 300|1|0|0|
|89 HammingIndep, L = 1200|0|1|0|
|65 RandomWalk1 J (L = 90)|0|0|1|
|54 WeightDistrib, r = 24|0|1|0|
|51 WeightDistrib, r = 0|1|0|0|
|72 LinearComp, r = 29|1|0|0|
|31 Gap, r = 0|0|0|1|
|9 CollisionOver, t = 20|0|0|1|
|37 Permutation, r = 0|0|1|0|
|9 CollisionOver, t = 20|0|1|0|
|9 CollisionOver, t = 20|0|1|0|
|85 HammingIndep, L = 30|0|1|0|
|85 HammingIndep, L = 30|0|0|1|
|92 Run of bits, r = 20|0|1|0|
|10 CollisionOver, t = 20|1|0|0|
|48 SampleCorr|0|1|0|
|19 ClosePairs mNP, t = 3|0|0|1|
|63 GCD, r = 0|0|0|1|
|90 HammingIndep, L = 1200|0|1|0|
|9 CollisionOver, t = 20|1|0|0|
|68 RandomWalk1 M (L = 1000)|1|0|0|
|36 Run of U01, r = 15|1|0|0|
|77 LongestHeadRun, r = 20|1|0|0|
|54 WeightDistrib, r = 24|0|0|1|
|69 RandomWalk1 R (L = 10000)|0|0|1|
|54 WeightDistrib, r = 24|0|0|1|
|10 CollisionOver, t = 20|1|0|0|
|9 CollisionOver, t = 20|0|0|1|
|80 HammingWeight2, r = 0|0|0|1|
|23 SimpPoker, d = 16|0|0|1|
|70 RandomWalk1 H (L = 10000)|1|0|0|
|61 MatrixRank, 1200 x 1200|1|0|0|
|62 Savir2|0|0|1|
|66 RandomWalk1 R (L = 90)|1|0|0|
|18 ClosePairs mNP2, t = 2|1|0|0|
|60 MatrixRank, 1200 x 1200|0|1|0|
|13 BirthdaySpacings, t = 4|0|1|0|
|69 RandomWalk1 J (L = 10000)|0|0|1|
|2 SerialOver, t = 4|1|0|0|
|52 WeightDistrib, r = 8|1|0|0|
|1 SerialOver, t = 2|0|1|0|
|9 CollisionOver, t = 20|1|0|0|
|6 CollisionOver, t = 4|0|1|0|
|69 RandomWalk1 C (L = 10000)|0|0|1|
|4 CollisionOver, t = 2|0|0|1|
|65 RandomWalk1 R (L = 90)|1|0|0|
|47 SampleMean|0|1|0|
|45 SampleProd, t = 10|1|0|0|
|91 Run of bits, r = 0|1|0|0|
|25 SimpPoker, d = 64|1|0|0|
|83 HammingCorr, L = 300|1|0|0|
|33 Gap, r = 0|1|0|0|
|7 CollisionOver, t = 8|0|1|0|
|28 CouponCollector, d = 4|0|1|0|
|67 RandomWalk1 M (L = 1000)|0|0|1|
|41 MaxOft, t = 5|0|0|1|
|66 RandomWalk1 R (L = 90)|0|0|1|
|66 RandomWalk1 M (L = 90)|0|1|0|
|61 MatrixRank, 1200 x 1200|0|0|1|
|91 Run of bits, r = 0|1|0|0|
|86 HammingIndep, L = 30|1|0|0|
|29 CouponCollector, d = 16|1|0|0|
|56 MatrixRank, 60 x 60|0|0|1|
|43 MaxOft, t = 20|0|1|0|
|79 PeriodsInStrings, r = 15|0|0|1|
|20 ClosePairs NP, t = 7|0|0|1|
|5 CollisionOver, t = 4|0|0|1|
|76 LongestHeadRun, r = 0|1|0|0|
|93 AutoCor, d = 1|0|1|0|

### P-value distribuition
|Side|high32 | mid32 | low32 |
|----|-------|-------|-------|
|Top|13|9|19|
|Bottom|28|19|15|

|Side|high32 | mid32 | low32 |
|----|-------|-------|-------|
|Top average|0.9996|0.9996|0.9995|
|Bottom average|5.17e-4|4.09e-4|7.0e-4|
