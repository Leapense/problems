# 10195번: Underwater Trip - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10195)


<p>Lucy has kidnapped Gru and two minions in order to take them to the secret underwater headquarters of the Anti-Villain League. She has converted her car into a submarine for the last part of the trip. Along the way her car passes through an underwater tunnel.</p>

<p>Lucy deploys her car’s sonar to detect the depth and length of the tunnel, as well as the size and distance of several stalagmites sticking up from the bottom of the tunnel. There is a strong current flowing through the tunnel that is carrying Lucy’s car 1 meter forward each second. She can steer the car to either move up 1 meter, stay at the same depth, or move down 1 meter each second.</p>

<p>You are given several possible action sequences Lucy can follow for steering her car through the tunnel. Your goal is to decide for each sequence whether her car will hit the tunnel roof, tunnel wall, a stalagmite, or safely pass through the tunnel.</p>

<p>Lucy’s car starts at the top left corner of the tunnel (distance = 0, depth = 0). It travels to the right, and is considered to have safely reached the end of the tunnel if it travels n − 1 meters into a tunnel of length n. Each action sequence will thus consist of n − 1 actions for a tunnel of length n.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/fc9628c3-3d67-4ce8-a5c3-5c6e2f6b6ac7/-/crop/608x409/14,32/-/preview/" style="width: 304px; height: 205px;"></p>

<p>In the example above, Lucy is trying to travel through a tunnel of depth 3 and length 5. There are two stalagmites. One is 1 meter high and 2 meters distant. The second is 2 meters high and 3 meters distant. When considering the action sequence &gt;v&gt;&gt;, Lucy’s car starts from the top left corner, moves 1 meter right, 1 meter down and to the right, then crashes into a stalagmite when it tries to move 1 meter right. If the second stalagmite was not present then the action sequence would have reached the end of the tunnel.</p>



## 입력


<p>The first line in the test data file contains the number of test cases. Each test case begins with a description of the depth and length of the tunnel. After that is the number of stalagmites, followed by the size and distance of each stalagmite on a separate line.</p>

<p>Next is the number of action sequences to analyze, followed by each sequence on a separate line. Each sequence is a string composed of the characters ∧, &gt;, and v, indicating whether Lucy should steer the car up (decrease depth by 1 meter), keep it at the same depth, or steer the car down (increase depth by 1 meter).</p>



## 출력


<p>For each test case, you are to output the input action sequence, followed by the expected outcome of following the sequence. There are four possible outcomes:</p>

<ul>
<li>Reached end of tunnel</li>
<li>Crashed into stalagmite</li>
<li>Crashed into tunnel floor</li>
<li>Crashed into tunnel ceiling</li>
</ul>

<p>The exact desired input/output format is shown below in the examples.</p>



## 소스코드

[소스코드 보기](Main.java)