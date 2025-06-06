# 5006번: Horror List - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/5006)


<p>It was time for the 7th Nordic Cinema Popcorn Convention, and this year the manager Ian had a brilliant idea. In addition to the traditional film program, there would be a surprise room where a small group of people could stream a random movie from a large collection, while enjoying popcorn and martinis.</p>

<p>However, it turned out that some people were extremely disappointed, because they got to see movies like Ghosts of Mars, which instead caused them to tear out their hair in despair and horror.</p>

<p>To avoid this problem for the next convention, Ian has come up with a solution, but he needs your help to implement it. When the group enters the surprise room, they will type in a list of movies in a computer. This is the so-called horror list, which consists of bad movies that no one in the group would ever like to see. Of course, this list varies from group to group.</p>

<p>You also have access to the database Awesome Comparison of Movies which tells you which movies are directly similar to which. You can assume that movies that are similar to bad movies will be almost as bad. More specificly, we define the Horror index as follows:</p>

<p>HI = 0 (if movie is on horror list. This overrides the other definitions.)<br>
&nbsp; &nbsp;= Q+1 (if the worst directly similar movie has HI = Q)<br>
&nbsp; &nbsp;= +∞ (if not similar at all to a horrible movie)</p>

<p>&nbsp;</p>



## 입력


<p>The first line of input contains three positive integers N, H, L (1 ≤ H &lt; N ≤ 1000, 0 ≤ L ≤ 10000), where N is the number of movies (represented by IDs, ranging from 0 to N − 1), H is the number of movies on the horror list and L is the number of similarities in the database.</p>

<p>The second line contains H unique space-separated integers x<sub>i</sub> (0 ≤ x<sub>i</sub> &lt; N) denoting the ID of the movies on the horror list.</p>

<p>The following L lines contains two space-separated integers a<sub>i</sub>, b<sub>i</sub> (0 ≤ a<sub>i</sub> &lt; b<sub>i</sub> &lt; N), denoting that movie with ID a<sub>i</sub> is similar to movie with ID b<sub>i</sub> (and vice verca).</p>



## 출력


<p>Output the ID of the best movie in the collection (highest Horror Index). In case of a tie, output the movie with the lowest ID.</p>



## 소스코드

[소스코드 보기](Horror%20List.cpp)