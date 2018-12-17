bash script
#points	times(s)	est.	dev.	%error
10	0m0.185s	3.6	0.46	%14.65
100	0m2.093s	3.0	0.14	%4.46
1000	0m20.592s	3.244	0.104	%3.31
10000	3m16.166s	3.172	0.032	%1.02

c program
#points	times(s)	est.	dev.	%error
10	0m9.404s	3.6	0.458	%14.59
100	1m39.722s	2.8	0.26	%8.32
1000	16m39.334s	3.18	0.04	%1.39
10000	N/A		N/A	N/A	N/A
(It took 16 minutes to get 1000 points and it's 9am now so I can't test my c program for 10000 points)

1.1 My compiled program is capable of running 101 points in 100 seconds
My bash script can generate as many as 5140 points (give or take) within 100 seconds

1.2 My bash file is clearly much faster. I was expecting that the compiled version would be faster,
but the way I have my gsl_rng seeded (with time(NULL)) made it so I effectively need to wait some time
to get unique random numbers. This makes the run time much more longer.

1.3 While my compiled program takes much more time, the most points I was able to make returned a percentage 
error lower than my bash script returned at 10000 points. The cause of this difference is most likely a result 
of the differences between awk rng and gsl rng

