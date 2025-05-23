# 10553번: SILUETA - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10553)


<p>The main hero of this task, painter Vincent, spent a great deal of his youth travelling the world. Sights from numerous voyages have often been the inspiration for his, nowadays highly praised, works of art. On one occasion, Vincent found himself in a metropolis full of skyscrapers so he got down to work right away, intoxicated by the marvelous sight. For a number of reasons, incomprehensible to an average programmer, Vincent decided to paint only the silhouettes of the skyscrapers seen before him. Unfortunately, a week after he finished this masterpiece, the painting spontaneously caught fire.</p>

<p>In order to reconstruct the painting, Vincent sought help in all directions; architects provided him with the exact dimensions of the skyscrapers, physicists ignored air resistance, mathematicians mapped everything onto a plane and now it’s your turn!</p>

<p>From your perspective, Vincent’s skyscrapers are rectangles whose sides are parallel to coordinate axes and with one side that lies on the abscissa. Part of the abscissa on the image should be shown with the characters ‘*’, the silhouettes of the skyscrapers with ‘#’ and fill the rest of the image with ‘.’. The left edge of the image must begin with a skyscraper, whereas the right edge of the image must end with a skyscraper. Additionally, in order to verify the results the mathematicians got, output the perimeter of the given silhouette not calculating the sides that lie on the abscissa.</p>



## 입력


<p>The first line of input contains an integer N (1 ≤ N ≤ 10 000), the number of skyscrapers.</p>

<p>Each of the following N lines contains three integers L<sub>i</sub>, R<sub>i</sub> and H<sub>i</sub> (1 ≤ L<sub>i</sub>, R<sub>i</sub>, H<sub>i</sub> ≤ 1, 000, 3 ≤ R<sub>i</sub> - L<sub>i</sub> ≤ 1, 000) that describe the position of the ith skyscraper. That skyscraper, in a Cartesian coordinate system, is considered a rectangle with its lower left corner in (L<sub>i</sub>, 0) and upper right corner in (R<sub>i</sub>, H<sub>i</sub>).</p>



## 출력


<p>The first line of output must contain the perimeter of Vincent’s silhouette.</p>

<p>The next h+1 lines, where h+1 is the height of the highest skyscraper, must contain Vincent’s drawing as described in the task.</p>



## 소스코드

[소스코드 보기](SILUETA.cpp)