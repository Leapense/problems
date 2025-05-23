# 32668번: Expected Flight Delay - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32668)


<p>Once upon a time, there was a businesswoman named Grace who lived in New York City, New York and frequently traveled to Des Moines, Iowa on a regular daily flight for work. Unfortunately, there was one big problem: Flights from New York to Des Moines were notoriously unreliable, especially on weekends.  The weather, maintenance issues, and other unpredictable factors always seemed to interfere.</p>

<p>Grace knew from her previous experiences that it would be very handy to have an app that would let her enter the day of the week of an upcoming meeting, the importance of arriving on time (she arrives on time if she successfully departs the day before, at the latest), and the probabilities of successfully flying out on weekdays (Monday-Friday) and on weekends (Saturday-Sunday). This would help her decide what day to schedule her flight in order to have confidence that she could reach Des Moines on time. Since her skills in programming and knowledge of probability are somewhat lacking, she is asking you to come up with the app.</p>

<p>As an example, suppose the meeting date is a Monday. Let the chance of success on weekdays be $p_{\mathrm{wday}}=80\%$, and on weekends be $p_{\mathrm{wend}}=60\%$. Let the importance of getting to the meeting on time be $90\%$ certainty. If Grace tries to fly on Sunday, the chance of her making it on time would simply be $60\%$. Not great, and not the $90\%$ assurance she wants, either. Perhaps flying on Saturday instead will work. This way, if Saturday's flight is canceled, she could still try again on Sunday.</p>

<p>The probability of her leaving by Sunday in this case would be $60\%\ \textrm{(chance of Saturday's flight being good)} + 40\%\ \textrm{(chance of Saturday's flight being bad)} \cdot 60\%\ \textrm{(chance of Sunday's flight being good)} = 84\%$. That's still not good enough.</p>

<p>If we add Friday as an option and calculate the probability Grace leaves by Sunday given the weekday $80\%$ chance of success, we will get $0.8 + 0.2 \cdot 0.6 + 0.2 \cdot 0.4 \cdot 0.6 = 96.8\%$. That is quite sufficient for Grace!</p>



## 입력


<p>The only line of input contains four space-separated integers. The first is in the range $[1,7]$ inclusive and indicates the meeting day of the week, with $1$ designating Sunday, $2$ Monday, and so forth. The next two integers are the percentage chances of successful flights on weekdays and weekends $p_{\mathrm{wday}}$ and $p_{\mathrm{wend}}$ $(0 \leq p_{\mathrm{wday}}, p_{\mathrm{wend}} \leq 100)$. At least one of $p_{\mathrm{wday}}$ and $p_{\mathrm{wend}}$ is nonzero. The fourth is the importance factor of making the meeting on time $p_{\mathrm{imp}}$, expressed as a percentage $(1 \leq p_{\mathrm{imp}} \leq 99)$.</p>

<p>Let $p(i)$ be the percent chance that Grace makes it to her meeting on time if she starts trying to fly there $i$ days before the meeting. It is guaranteed that $\min_{i \geq 1} |p(i) - p_{\mathrm{imp}}| &gt; 10^{-6}$.</p>



## 출력


<p>Print a string of the form <code>Try to leave on DEPDAY, N days before the MEETDAY meeting.</code> In this string, <code>DEPDAY</code> is the day of the week (Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday) closest to the meeting date on which to schedule the flight to guarantee that the percent chance of Grace making the meeting is at least $p_{\mathrm{imp}}$. <code>N</code> is the number of days to leave before the day of the meeting: note that Grace may need to leave more than $7$ days early to meet her importance factor requirement. Finally, <code>MEETDAY</code> is the day of the week of the meeting. Print <code>day</code> instead of <code>days</code> if <code>N</code> is $1$. See the sample output for examples of how to format this string.</p>



## 소스코드

[소스코드 보기](Main.java)