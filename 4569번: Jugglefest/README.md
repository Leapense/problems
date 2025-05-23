# 4569번: Jugglefest - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4569)


<p>Many people are familiar with a standard 3-ball juggling pattern in which you throw ball&nbsp;A, then ball&nbsp;B, then ball&nbsp;C, then ball&nbsp;A, then ball&nbsp;B, then ball&nbsp;C, and so on. Assuming we keep a regular rhythm of throws, a ball that is thrown higher into the air will take longer to return, and therefore will take longer before the next time it gets thrown. We say that a ball thrown to height&nbsp;<em>h</em> will not be thrown again until precisely <em>h</em> steps later in the pattern. For example, in the standard 3-ball pattern, we say that each ball is thrown to a height of 3, and therefore thrown again 3-steps later in the pattern. For example, ball&nbsp;A that we throw at time&nbsp;1 of the process will be next thrown at time&nbsp;4.</p>

<p><img src="https://www.acmicpc.net/upload/images2/example3.png"></p>

<p>By convention, we label the first ball thrown as&nbsp;A, and each time we introduce a new ball into the pattern, we label it with the next consecutive uppercase letter (hence B and then C in the classic pattern).</p>

<p>There exist more complex juggling patterns. Within the community of jugglers, a standard way to describe a pattern is through a repeating sequence of numbers that describe the height of each successive throw. This is known as the <strong><em>siteswap</em></strong> notation.</p>

<p>To demonstrate the notation, we first consider the "3 4 5" siteswap pattern. This describes an infinite series of throws based on the repeating series "3 4 5 3 4 5 3 4 5 ...". The first throw the juggler makes will be to a height of 3, the second throw will be to a height of 4, the third throw to a height of 5, the fourth throw to a height of 3 (as the pattern repeats), and so forth.</p>

<p>While the siteswap pattern describes the heights of the throws, the actual movement of individual balls does not follow as obvious a pattern. The following diagram illustrates the beginning of the "3 4 5" pattern.</p>

<p><img src="https://www.acmicpc.net/upload/images2/example345.png"></p>

<p>The first throw is ball&nbsp;A, thrown to a height of 3, and thus ball&nbsp;A is not thrown again until time&nbsp;4. At time&nbsp;2, we must make a throw with height&nbsp;4; since ball&nbsp;A has not yet come back, we introduce a second ball, conventionally labeled&nbsp;B. Because ball&nbsp;B is thrown at time&nbsp;2 with a height of 4, it will not be thrown again until time&nbsp;6. At time&nbsp;3, we introduce yet another ball, labeled&nbsp;C, and throw it to height&nbsp;5 (thus it will next be thrown at time&nbsp;8). Our next throw, at time&nbsp;4, is to have height&nbsp;3. However, since ball&nbsp;A has returned (from its throw at time&nbsp;1), we do not introduce a new ball; we throw&nbsp;A. At time&nbsp;5, we are to make a throw with height&nbsp;4, yet we must introduce a new ball,&nbsp;D, because balls A, B, and C are all still up in the air. (Ball&nbsp;D is the last ball to be introduced for this particular pattern.) The juggling continues with ball&nbsp;B being thrown to height&nbsp;5 at time&nbsp;6, and so on.</p>

<p>The "3 4 5" siteswap pattern works out nicely. It happens to be a 4-ball pattern, because after introducing ball&nbsp;D, the juggler can now continue until his or her arms get tired. Unfortunately, not all siteswap sequences are legitimate!</p>

<p>Consider an attempt to use a siteswap pattern "3 5 4". If we were only interested in making six throws, everything works well. But a problem arises at time 7, as shown in the following diagram.</p>

<p><img src="https://www.acmicpc.net/upload/images2/example354.png"></p>

<p>Ball&nbsp;B was thrown at time&nbsp;2 with a height of 5. Therefore, it should get its next turn to be thrown at time&nbsp;7. However, ball&nbsp;C was thrown at time&nbsp;3 with a height of 4, and so it too should get its next turn at time&nbsp;7. (To add insult to injury, ball&nbsp;A gets thrown at time&nbsp;4 with height of 3, also suggesting it get its next turn at time&nbsp;7.) What we have here is a problem, resulting in a lot of balls crashing to the ground.</p>



## 입력


<p>Each line represents a separate trial. It starts with the number <em>1 ≤ P ≤ 7</em> which represents the period of the repeating pattern, followed by <em>P</em> positive numbers that represent the throw heights in the pattern. An individual throw height will be at most 19. The input is terminated with a single line containing the value&nbsp;0.</p>



## 출력


<p>For each pattern, output a single line describing the first 20 throws for the given pattern, if 20 throws can be legally made. Otherwise, output the word <code>CRASH</code>. You need not be concerned with any crashes due to balls landing strictly after time&nbsp;20.</p>



## 소스코드

[소스코드 보기](Jugglefest.py)