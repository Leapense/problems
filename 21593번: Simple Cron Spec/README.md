# 21593번: Simple Cron Spec - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21593)


<p>A <em>Cron Spec</em> is used by Linux to specify when to repeatedly execute a certain job. For this problem, consider a <em>Simple Cron Spec</em> that defines when a job needs to be run within a single day. A <em>Simple Cron Spec</em> has three space separated tokens:</p>

<p style="text-align: center;"><code>hours minutes seconds</code></p>

<p>that specify at which hours/minutes/seconds a job will be run. Hour values are 0-23, minute and second values are 0-59.</p>

<p>Each token consists of a single integer value, a value range (two values separated by a dash ‘<code>-</code>’), a comma-separated list of multiple values and/or value ranges, or an asterisk (‘<code>*</code>’). A value range represents all integer values between the low and high value, inclusive. An asterisk is a special token that represents all possible values. The specified values in any comma separated list must be non-overlapping.</p>

<p>For example, the specification:</p>

<p style="text-align: center;"><code>* 30 20,25,30-33</code></p>

<p>says the job will be run every hour, at minute 30, and second 20, 25, 30, 31, 32, and 33, for a total of 24 × 1 × 6 = 144 times each day.</p>

<p>Given a list of <em>Simple Cron Specs</em>, determine two things: First, the number of seconds in the day that at least one job will start, and second, the total number of job starts during the day. Note that if a single job starts 24 times in a day, that counts as 24 job starts.</p>



## 입력


<p>The first line of input contains a single integer $n$ ($1 \le n \le 100$), which is the number of <em>Simple Cron Specs</em> that follow.</p>

<p>Each of the next $n$ lines contains three strings $h$, $m$ and $s$. These are the hours, minutes, and seconds specifications of the <em>Simple Cron Specs</em>. Each $h$, $m$ and $s$ consists of either a single star (‘<code>*</code>’), or a comma-separated list of one or more values or value ranges (two values separated by ‘<code>-</code>’). The values/ranges are guaranteed to be within the appropriate limits (0 to 23 for hours, 0 to 59 for minutes and seconds), and are guaranteed to not overlap. All range specifications are guaranteed to consist of two distinct values, smallest first. All values specified in a comma-separated list are guaranteed to be in strictly increasing order. The whole is guaranteed to be a legitimate <em>Simple Cron Spec</em>. The only spaces in the line will be a single space between $h$ and $m$, and a single space between $m$ and $s$.</p>



## 출력


<p>Output two space separated integers. The first is the number of seconds in the 24 hour day with at least one job start, and the second is the total number of job starts.</p>



## 소스코드

[소스코드 보기](Simple%20Cron%20Spec.cpp)