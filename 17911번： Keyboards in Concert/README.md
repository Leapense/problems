# 17911번: Keyboards in Concert - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17911)


<p>Olav has some electronic keyboards and would like to play a tune. Unfortunately all of Olav’s keyboards are broken so each of them can only play some of the notes. By switching which instrument he is using he will be able to play the whole tune, but moving keyboards around is annoying so he would like to minimize the amount of times he has to switch. Can you help Olav figure out the minimum number of keyboard switches needed to play the entire song?</p>



## 입력


<p>The first line of input is two space separated integers; n (1 ≤ n ≤ 1 000) the number of instruments, and m (1 ≤ m ≤ 1 000), the number of notes in the tune. This is followed by n lines, each starting with an integer k<sub>i</sub> (1 ≤ k<sub>i</sub> ≤ 1 000), the number of notes playable by instrument i, followed by k<sub>i</sub> pairwise distinct integers ℓ<sub>1</sub>, ℓ<sub>2</sub>, . . . , ℓ<sub>k<sub>i</sub></sub> , the notes that instrument i can play (0 ≤ ℓ<sub>j</sub> ≤ 1 000). Finally, there is a line with m space-separated integers – the notes of the tune in order.</p>



## 출력


<p>The minimum number of times Olav needs to switch the instrument he is using during the tune.</p>



## 소스코드

[소스코드 보기](Keyboards%20in%20Concert.cpp)