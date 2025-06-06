# 6455번: Transaction Processing - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6455)


<p>You have been called upon to write a program which performs one of the initial steps in posting transactions to a general ledger. The central principle of double-entry bookkeeping is that the sum of all debits must equal the sum of all credits. This is true for each transaction. For the purposes of your program, positive numbers represent debits and negative numbers represent credits. That is, 2.00 is a two dollar debit, and -2.00 is a two dollar credit. The purpose of your program is to check that each transaction balances, and to report it if it doesn't.</p>



## 입력


<p>You have been called upon to write a program which performs one of the initial steps in posting transactions to a general ledger. The central principle of double-entry bookkeeping is that the sum of all debits must equal the sum of all credits. This is true for each transaction. For the purposes of your program, positive numbers represent debits and negative numbers represent credits. That is, 2.00 is a two dollar debit, and -2.00 is a two dollar credit. The purpose of your program is to check that each transaction balances, and to report it if it doesn't.</p>

<p>Input data to your program will come in two sections. The first&nbsp;<br>
section is a list of up to 100 accounts in the general ledger. It consists&nbsp;<br>
of lines in the format:</p>

<pre>nnnxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx</pre>

<p>where nnn is a three-digit account number and xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx is a 1--30 character account name string. This section is terminated by a record starting with 000, which is not used as an account number.</p>

<p>The second section of the input data consists of 15-character records, one per line in the format</p>

<pre>sssnnnxxxxxxxxx</pre>

<p>where sss is a three-digit sequence number, nnn is a three-digit account number, and xxxxxxxxx is a nine-digit amount in dollars and cents (without the decimal point). Each of these records is one entry of a transaction. A transaction consists of between two and ten entries with identical sequence numbers. Each transaction will be contiguous within the input data. This section of input data is terminated by a record which has a sequence number of 000.</p>



## 출력


<p>Nothing is to be printed for transactions which balance. For transactions which do not balance, an exception report is to be printed in the form:</p>

<pre>*** Transaction sss is out of balance ***
nnn xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx vvvvvvv.vv
nnn xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx vvvvvvv.vv
.
.
.
999 Out of Balance                 vvvvvvv.vv</pre>

<p>where nnn is an account number, xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx is the corresponding account name, and vvvvvvv.vv is the amount. Print a space between the above fields. The entries should be listed in the order that they were received in the input. The last entry in the report is one you will create to make the transaction balance, using the special account number 999 (the suspense account). Print a blank line after each exception report.</p>



## 소스코드

[소스코드 보기](Transaction%20Processing.cpp)