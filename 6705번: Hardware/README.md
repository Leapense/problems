# 6705번: Hardware - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6705)


<p>Ola Clason’s Hardware store is an old company where most work is done “the old way”. Among other things, the company is the one and only provider of marble house numbers. These house numbers have become extremely popular among construction companies, especially the ones building luxury estates. This is of course great for Ola Clason, but also a small problem. Nisse, who has been managing the incoming orders has turned out to be a bottleneck in Ola’s business. Most orders are on the form “Coconut Drive 200, 202, 204, ..., 220”. This means every even number between 200 and 220. Nisse’s work is to transfer an order to a list of necessary digits and other symbols.</p>

<p>Your assignment is to write a program that automates Nisse’s work with orders containing only positive integer house numbers. Nisse will still in the future process all special orders (those including non digit symbols) by hand.</p>



## 입력


<p>On the first line of input is a single positive integer n, specifying the number of orders that follow. The first line of each order contains the road name for that order. No road name is longer than 50 characters. The second line states the total number of buildings needing new marble numbers on that order. Then follows the different house number specifications on several lines. These lines are of two kinds: single number lines and multiple number lines. A single number line simply consists of the house number by itself, while a multiple number line starts with a “+”-sign, followed by three positive integer numbers: first number, last number and the interval between the house numbers. The distance between the first and last house number will always be a multiple of the house number interval. A house number will never have more than five digits. After the last house number specification line, the next order follows, if there is any</p>



## 출력


<p>For each order, the output consists of 13 lines. The first and second lines should be identical with the first two input lines. Then, there follows 10&nbsp;lines with information on how many marble digits of each kind the order consists of. These rows are on the format “Make X digit Y” where X is how many copies of digit Y they need to make. The last row states the total number Z of digits needed, on the format “In total Z digits”. If there is only one digit to produce, it should say “In total 1 digit”, in order to be grammatically correct.</p>



## 소스코드

[소스코드 보기](Hardware.cpp)