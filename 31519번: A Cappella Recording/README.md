# 31519번: A Cappella Recording - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31519)


<p>Geoffry is preparing an a cappella composition where he sings the entire song by himself.</p>

<p>Each note of the song has a pitch between $0$ and $10^9$. Because of the varying pitches in the song, Geoffry will record himself singing multiple times. In a single recording, he will pick some subset of the notes to sing and he will sing exactly those notes. To avoid straining his voice too much, within a single recording, there is a limit to the difference between the maximum pitch and the minimum pitch among the notes he sings.</p>

<p>Compute the minimum number of times that Geoffry can record himself singing the song and each note is sung in at least one of the recordings.</p>



## 입력


<p>The first line contains two integers $n$ and $d$ ($1 \le n \le 10^5, 0 \le d \le 10^9$), where $n$ is the number of notes in Geoffry's song, and $d$ is the largest difference between the minimum pitch and the maximum pitch that Geoffry can handle.</p>

<p>Each of the next $n$ lines contains a single integer $p$ ($0 \le p \le 10^9$). These are the pitches of the notes in Geoffry's song, in the order that they are to be sung.</p>



## 출력


<p>Output a single integer, which is the minimum number of times that Geoffry can record himself singing the song and each note is sung in at least one of the recordings.</p>



## 소스코드

[소스코드 보기](Main.java)