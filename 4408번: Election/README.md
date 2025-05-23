# 4408번: Election - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4408)


<p>Canada has a multi-party system of government. Each candidate is generally associated with a party, and the party whose candidates win the most ridings generally forms the government. Some candidates run as independents, meaning they are not associated with any party. Your job is to count the votes for a particular riding and to determine the party with which the winning candidate is associated.</p>



## 입력


<p>The first line of input contains a positive integer n satisfying 2 &lt;= n &lt;= 20, the number of candidates in the riding. n pairs of lines follow: the first line in each pair is the name of the candidate, up to 80 characters; the second line is the name of the party, up to 80 characters, or the word "independent" if the candidate has no party. No candidate name is repeated and no party name is repeated in the input. No lines contain leading or trailing blanks.</p>

<p>The next line contains a positive integer m &lt;= 10000, and is followed by m lines each indicating the name of a candidate for which a ballot is cast. Any names not in the list of candidates should be ignored.</p>



## 출력


<p>Output consists of a single line containing one of:</p>

<ul>
<li>The name of the party with whom the winning candidate is associated, if there is a winning candidate and that candidate is associated with a party.</li>
<li>The word "independent" if there is a winning candidate and that candidate is not associated with a party.</li>
<li>The word "tie" if there is no winner; that is, if no candidate receives more votes than every other candidate.</li>
</ul>



## 소스코드

[소스코드 보기](Election.cpp)