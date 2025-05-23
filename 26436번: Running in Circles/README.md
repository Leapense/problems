# 26436번: Running in Circles - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26436)


<p>Ada has decided that this year, she will take part in the annual marathon that takes place in her city. Since this is the first time she would be running such a long distance, she has decided to start practising for it by running in the circular track of length $\mathbf{L}$ units near her house.</p>

<p>Ada wants to focus only on running, so she decides to use a machine to count the number of laps she has run. The machine is placed at the starting line of the circular track and starts the count from $0$. Every time Ada arrives at the starting line running in the same direction as the last time she departed from the starting line, the machine increases the number of laps that Ada has run by $1$. If she crosses the starting line or changes direction at the starting line, the machine considers the new direction as the direction she last touched the starting line. The machine only remembers the last direction in which Ada touched the starting line. During a lap, Ada can change directions any number of times, but as long as she eventually touches the starting line in the same direction as she last touched it, the count of laps in the machine increases by $1$.</p>

<p>This is the first time Ada has practised running long distances, so she cannot run continuously. She runs some distance, then takes a break to regain her energy. However, when she starts running again after taking a break, she cannot remember which direction she was running in previously. So she picks one of the directions, clockwise or anticlockwise, and starts running from the same position where she stopped.</p>

<p>Ada begins at the starting line and is initially facing in the direction of her first run. She runs a total of $\mathbf{N}$ times, taking breaks in between. Given the information of the distance $\mathbf{D_i}$ units Ada has run, and the direction $\mathbf{C_i}$ she has taken (clockwise or anticlockwise) when she ran the $i$-th time, for all $i$ from $1, \dots, \mathbf{N}$, can you tell the number of laps that would be reported by the machine at the end?</p>



## 입력


<p>The first line of the input gives the number of test cases, $\mathbf{T}$. $\mathbf{T}$ test cases follow.</p>

<p>The first line of each test case contains two positive integers $\mathbf{L}$ and $\mathbf{N}$, the length of the circular track in units, and the number of times Ada has run respectively.</p>

<p>The next $\mathbf{N}$ lines describe Ada's runs. The $i$-th line contains a positive integer $\mathbf{D_i}$ and a character $\mathbf{C_i}$, the distance in units Ada has run and the direction she has taken (clockwise or anticlockwise) respectively during the $i$-th run. $\mathbf{C_i}$ will always be either <code>'C'</code> (denoting clockwise direction) or <code>'A'</code> (denoting anticlockwise direction).</p>



## 출력


<p>For each test case, output one line containing <code>Case #x: y</code>, where $x$ is the test case number (starting from 1) and $y$ is a non negative integer denoting the number of laps reported by the machine at the end.</p>



## 소스코드

[소스코드 보기](Running%20in%20Circles.py)