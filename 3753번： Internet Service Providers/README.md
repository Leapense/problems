# 3753번: Internet Service Providers - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/3753)


<p>A group of N Internet Service Provider companies (ISPs) use a private communication channel that has a maximum capacity of C traffic units per second. Each company transfers T traffic units per second through the channel and gets a profit that is directly proportional to the factor T(C - T N). The problem is to compute T_optim, the smallest value of T that maximizes the total profit the N ISPs can get from using the channel. Notice that N, C, T, and T_optim are integer numbers.</p>

<p>Write a program that reads sets of data from an input text file.&nbsp;</p>



## 입력


<p>Each data set corresponds to an instance of the problem above and contains two integral numbers – N and C – with values in the range from 0 to 10<sup>9</sup>. The input data are separated by white spaces, are correct, and terminate with an end of file.&nbsp;</p>



## 출력


<p>For each data set the program computes the value of T_optim according to the problem instance that corresponds to the data set. The result is printed on the standard output from the beginning of a line. There must be no empty lines on the output. An example of input/output is shown below.</p>



## 소스코드

[소스코드 보기](Internet%20Service%20Providers.cpp)