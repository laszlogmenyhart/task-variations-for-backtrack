## Variation 4

There are exactly N candidates to the N jobs and each applicant told us which jobs they are qualified and how much salary would be asked. The boss of the business wants to fill all the jobs but at the least cost to him.

His idea is this: first all possible job fill will be generated (if there is). It means that all applicant will have a serial number of a job with two conditions:
- we can choose a job for him, what he can do (F(i,j)>0);
- we can choose a job for him, what is not given to others (Value of Occured(i,j,x) function is false).

First parameter of AllJob procedure is the serial number of the actual applicant i, the second parameter is the number of the applicants (and so the jobs), it is N.

