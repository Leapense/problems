# 26424번: Coloring Game - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26424)


<p>John loves to play computer games. He recently discovered an interesting game. In the game there are $\mathbf{N}$ cells, which are aligned in a row from left to right and are numbered with consecutive integers starting from $1$. Initially, all cells are coloured <i>white</i>. A cell is valid if it has <i>white</i> color and it does not have any adjacent <i>red</i> colored cell. On each turn, a player paints any valid cell with the <i>red</i> color. The game ends when no valid cells are present. The score of the player is equal to the number of cells they paint.</p>

<p>To master the game, John is practicing against a bot. The bot is poorly trained and it always paints the first valid cell from the left. John on the other hand is playing the game very carefully and he can choose any valid cell. The bot makes the first move and the players take turns alternately.</p>

<p>Find the <i>maximum</i> achievable score by the bot, assuming that John is playing optimally to minimize the score of his opponent.</p>



## 입력


<p>The first line of the input gives the number of test cases, $\mathbf{T}$. $\mathbf{T}$ test cases follow.</p>

<p>The only line of each test case contains an integer $\mathbf{N}$ representing the number of cells in the game.</p>



## 출력


<p>For each test case, output one line containing <code>Case #x: y</code>, where $x$ is the test case number (starting from 1) and $y$ is the <i>maximum</i> achievable score by the bot given that John is playing optimally.</p>



## 소스코드

[소스코드 보기](Coloring%20Game.cpp)