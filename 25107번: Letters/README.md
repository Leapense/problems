# 25107번: Letters - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25107)


<p>Martin is attending a lecture on linear algebra. It is needless to say that the professor who is giving the lecture is the most boring person in the entire universe. There is a $N × M$ matrix written on the blackboard. Some of the entries in the matrix are letters (of the English alphabet) while some other entries are blank. Here is an example of such a matrix of size $6 × 8$:</p>

<p>$$\begin{bmatrix} k &amp; &amp; l &amp; &amp; n &amp; d &amp; i &amp; \\ &amp; &amp; &amp; &amp; &amp; c &amp; &amp; \\ &amp; &amp; &amp; &amp; &amp; &amp; i &amp; h \\ j &amp; &amp; &amp; a &amp; &amp; &amp; &amp; \\ &amp; &amp; c &amp; b &amp; &amp; &amp; &amp; \\ &amp; &amp; c &amp; &amp; &amp; &amp; e &amp; f \end{bmatrix} \text{.}$$</p>

<p>Martin has absolutely no idea what this matrix represents. He is so bored that he has not been following the lecture anymore for the last $30$ minutes. However, Martin has an extremely vivid imagination. He is imagining that the matrix is suddenly influenced by gravity and all the letters in it are sliding downwards until each letter either ‘reaches the bottom’ or ‘hits the letter that is below it’. In the first phase, the above matrix becomes:</p>

<p>$$\begin{bmatrix} &amp; &amp; &amp; &amp; &amp; &amp; &amp; \\ &amp; &amp; &amp; &amp; &amp; &amp; &amp; \\ &amp; &amp; &amp; &amp; &amp; &amp; &amp; \\ &amp; &amp; l&amp; &amp; &amp; &amp;i &amp; \\ k &amp; &amp; c&amp; a&amp; &amp; d&amp; i&amp; h\\ j &amp; &amp; c &amp; b &amp; n &amp; c &amp; e &amp; f \end{bmatrix} \text{.}$$</p>

<p>After that, gravity changes direction and is now pulling the letters to the left. We are now in the second phase. Again, all the letters are sliding to the left until each letter either ‘reaches the left bracket’ or ‘hits the letter on its left’. The previous matrix thus becomes:</p>

<p>$$\begin{bmatrix} &amp; &amp; &amp; &amp; &amp; &amp; &amp; \\ &amp; &amp; &amp; &amp; &amp; &amp; &amp; \\ &amp; &amp; &amp; &amp; &amp; &amp; &amp; \\ l&amp; i&amp; &amp; &amp; &amp; &amp; &amp; \\ k &amp; c&amp; a&amp; d&amp; i&amp; h&amp; &amp; \\ j &amp; c &amp; b &amp; n &amp; c &amp; e &amp; f &amp; \end{bmatrix} \text{.}$$</p>

<p>Martin is carrying out this procedure in his head until the very end of the boring lecture. Of course, after each phase, i.e. after all the letters land at their respective destinations, gravity may change its direction (there are four possibilities for the direction: left, right, up and down).</p>

<p>Write a program that determines the final positions of all letters in the matrix given the precise sequence of the gravity direction changes.</p>



## 입력


<p>The first line contains three integers $N$, $M$ and $K$ where $N × M$ is the size of the matrix and $K$ is the number of phases.</p>

<p>The second line contains a string of length $K$ that consists of letters <code>L</code>, <code>R</code>, <code>U</code> and <code>D</code> that represent the direction of gravity in each phase (left, right, up and down, respectively).</p>

<p>The final $N$ lines represent the matrix. Each of the lines contains $M$ characters. The characters are lowercase letters of the English alphabet and ‘<code>.</code>’ (dot) which represents a blank entry.</p>



## 출력


<p>Output the matrix which Martin obtained at the end of the lecture. The format of the matrix is identic to the one in the input data.</p>



## 소스코드

[소스코드 보기](Letters.py)