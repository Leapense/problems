# 31655번: International Dates - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31655)


<p>You read a lot of documents that come from the United States, Europe, and other countries around the world. The issue is that their date formats aren’t consistent! The US formats their dates as MM/DD/YYYY while in Europe they format it as DD/MM/YYYY. That is, in the US the month comes before the day, while in Europe the day comes first. Given a date, can you determine if its <i>definitely</i> the US format, for sure European, or could be either? (Note that there are even more date formats, but luckily since the year is guaranteed to be last in this case, we only have to worry about these 2 formats.)</p>



## 입력


<p>The input consists of a single string comprised of 3 integers separated by forward slashes, as $AA/BB/CCCC$, where $1 \le AA, BB, \le 31$, and $0 \le CCCC \le 9999$. It is guaranteed that the given string will be a valid date for at least one of the formats. You can assume that all $12$ months have exactly $31$ days, so there is no need to worry about months with 30 days, or February.</p>



## 출력


<p>Output either <code>US</code> if the date doesn’t conform to the European format, or <code>EU</code> if the date doesn’t conform to the US format. Otherwise, output <code>either</code> if there is no way to know for sure which format the date follows.</p>



## 소스코드

[소스코드 보기](International%20Dates.py)