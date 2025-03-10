# 11259번: Travel of alphabets - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11259)


<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11259/1.png" style="float:left; height:174px; width:267px">John Corner demands to generate words from his alphabet table. Each word is composed by traveling of alphabets in four directions (← le*, ↑ up, → right, and ↓ down), star/ng from first alphabet (‘i’) un/l last alphabet (‘r’). When all words have been created, he would like to know how many words he has. Of course, it is possible to have some duplicated words and he also needs to know how many unique words he got. Please help him to finish these funny tasks.</p>

<p><strong>Moving step explanation:</strong></p>

<p>From the Figure above presented alphabet table that has the 3 row x 4 column.</p>

<p>Case: word length = 1,</p>

<p>Regarding to the alphabet table, take each alphabet starting from ‘i’ (top-left) to ‘r’ (rightdown), then there are 12 result words (i c p c h i j k a c m r). Length =1, one alphabet means one word. In this case, there is no traveling in four directions (← ↑ → ↓) since the word is ended by the length (length = 1).</p>

<p>Case: word length = 2,</p>

<p>Take ‘i’ (top-left corner) from the alphabet table. ‘i’ cannot move left or up since there is no adjacent alphabets. ‘i’ can only move right and move down. Then, let move ‘i' to the right, the word will be “ic”. Let move ‘i’ down, the word will be “ih”.</p>

<p>Next step, take another adjacent alphabet ‘c’. ‘c’ can move in ordered left, right and down. The words will be “ci, cp, ci”. He repeats these steps until reaching the last alphabet (‘r’).</p>

<p>Case: word length = 3,</p>

<p>Use the previous travel steps. Thus, let move ‘i’ to the right, the word will be “ic”. (length = 2).</p>

<p>Then, continue to move for the word with length = 3</p>

<ul>
<li>move left (from ‘c’) to the last alphabet back to itself. “ic” -&gt; ‘i’.</li>
<li>CANNOT move up. (There is no an adjacent alphabet above)</li>
<li>move right (from ‘c’) “ic” -&gt; ‘p’</li>
<li>move down (from ‘c’) “ic” -&gt; ‘i’</li>
</ul>

<p>Then, all summarized words starting from the first alphabet will be “ici”, “icp”, “ici”, …. , then, repeat until reaching the last alphabet (‘r’)</p>

<p><strong>Alphabet traveling restriction:</strong></p>

<p>John has been participated ACM ICPC Thailand and he loves it very much. Therefore, he prefers to define “<span style="color:#FF0000">acm</span>” as <strong>THREE</strong> forbidden alphabets. Any word contains any forbidden alphabets (‘a’ OR ‘c’ OR ‘m’ <em><strong>LOWERCASE only</strong></em>) will be discarded (examples: i<span style="color:#FF0000"><u>c</u></span>i, <span style="color:#FF0000"><u>a</u></span>hi, and <span style="color:#FF0000"><u>m</u></span>rk will be rejected)&nbsp;</p>

<p><strong>Remark:</strong> When he moves an alphabet to another alphabet, it can be moved back to a previous selected alphabet if it still satisfies the policy (moving four directions, word lengths and forbidden alphabets).</p>

<p>Since John applies the moving steps including his traveling restriction, the generated words will be minor changed as illustrated in these 3 examples:&nbsp;</p>



## 입력


<p>The first line of input contains three unsigned integers: the row “R” (0 &lt; R &lt; 11), the column “C” (0 &lt; C &lt; 11) of the alphabet table and the word length “L” (0 &lt; L &lt; 7) consecutively.</p>

<p>The following R lines represent the alphabet table. Each line is a row containing C characters without space. All given characters are smaller letters.&nbsp;</p>



## 출력


<p>The first line is an integer calculated from the number of generated words with the length of L, and the second line is an integer calculated from the number of unique words of all words generated.&nbsp;</p>



## 소스코드

[소스코드 보기](Main.java)