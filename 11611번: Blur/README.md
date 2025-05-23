# 11611번: Blur - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11611)


<p>You have a black and white image that is w pixels wide and h pixels high. You decide to represent this image with one number per pixel: black is 0, and white is 1. Your friend asks you to blur the image, resulting in various shades of gray. The way you decide to blur the image is as follows: You create a new image that is the same size as the old one, and each pixel in the new image has a value equal to the average of the 9 pixels in the 3 × 3 square centered at the corresponding old pixel. When doing this average, wrap around the edges, so the left neighbor of a leftmost pixel is in the rightmost column of the same row, and the top neighbor of an uppermost pixel is on the bottom in the same column. This way, the 3 × 3 square always gives you exactly 9 pixels to average together. If you want to make the image blurrier, you can take the blurred image and blur it again using the exact same process.</p>

<p>Given an input image and a fixed number of times to blur it, how many distinct shades of gray does the final image have, if all the arithmetic is performed exactly?</p>

<p>Warning: Floating point numbers can be finicky; you might be surprised to learn, for example, that 2/9 + 5/9 may not equal 3/9 + 4/9 if you represent the fractions with floating point numbers! Can you figure out how to solve this problem without using floating point arithmetic?</p>



## 입력


<p>The first line of input contains three space-separated integers w, h, and b (3 ≤ w, h ≤ 100, 0 ≤ b ≤ 9), denoting the width and height of the image, and the number of times to blur the image, respectively. The following h lines of w space-separated integers describe the original image, with each integer being either 0 or 1, corresponding to the color of the pixel.</p>



## 출력


<p>Output, on a single line, a single integer equal to the number of distinct shades of gray in the final image.</p>



## 소스코드

[소스코드 보기](Blur.py)