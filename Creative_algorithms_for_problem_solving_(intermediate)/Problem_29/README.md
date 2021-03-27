돌다리 건너기(S) - [문제 26]
====================================
절대반지를 얻기 위하여 반지원정대가 출발한다. 원정대가 지나가야할 다리는 두
개의 인접한 돌다리로 구성되어 있다. 하나는 <악마의 돌다리>이고 다른 하나는
<천사의 돌다리>이다. 아래 그림 1은 길이가 6인 다리의 한 가지 모습을 보여준다.

그림에서 위의 가로줄은 <악마의 돌다리>를 표시하는 것이고 아래의 가로줄은 <천
사의 돌다리>를 표시한다. 두 돌다리의 길이는 항상 동일하며, 각 칸의 문자는 해당 돌에 새겨진 문자를 나타낸다. 두 다리에 새겨진 각 문자는 {R, I, N, G, S} 중 하나이다. 

<br>
<div align="center">
<img src="./img/figure1.png" align="center">
</div>
<br>

반지원정대가 소유하고 있는 마법의 두루마리에는 <악마의 돌다리>와 <천사의 돌
다리>를 건너갈 때 반드시 순서대로 밟고 지나가야할 문자들이 적혀있다. 이 순서대로 지나가지 않으면 돌다리는 무너져, 반지원정대는 화산 속으로 떨어지게 된다. 다리를 건널 때 다음의 제한조건을 모두 만족하면서 건너야 한다.

(1) 왼쪽(출발지역)에서 오른쪽(도착지역)으로 다리를 지나가야 하며, 반드시 마법의 두루마리에 적힌 문자열의 순서대로 모두 밟고 지나가야 한다.

(2) 반드시 <악마의 돌다리>와 <천사의 돌다리>를 번갈아가면서 돌을 밟아야 한다.
단, 출발은 어떤 돌다리에서 시작해도 된다.

(3) 반드시 한 칸 이상 오른쪽으로 전진해야하며, 건너뛰는 칸의 수에는 상관이 없다.

만일 돌다리의 모양이 그림 1과 같고 두루마리의 문자열이 “RGS”라면 돌다리를 건
너갈 수 있는 경우는 다음의 3가지뿐이다(아래 그림에서 큰 문자는 밟고 지나가는
돌다리를 나타낸다.

<br>
<div align="center">
<img src="./img/figure2.png" align="center">
</div>
<br>

아래의 세 방법은 실패한 방법이다

<br>
<div align="center">
<img src="./img/figure3.png" align="center">
</div>
<br>

왜냐하면 첫 번째는 문자열 “RGS”를 모두 밟고 지나가야 하는 조건 (1)을 만족하
지 않으며, 두 번째는 번갈아가면서 돌을 밟아야 하는 조건 (2)를, 세 번째는 앞으로 전진을 하여야하는 조건 (3)을 만족하지 않기 때문이다.

마법의 두루마리에 적힌 문자열과 두 다리의 돌에 새겨진 문자열이 주어졌을 때,
돌다리를 통과할 수 있는 모든 가능한 방법의 수를 계산하는 프로그램을 작성하시오.

예를 들어, 그림 1의 경우는 통과하는 방법이 3가지가 있으므로 3을 출력해야 한다.

**입력** 

첫째 줄에는 마법의 두루마리에 적힌 문자열(R, I, N, G, S로만 구성된)이 주어진다.

이 문자열의 길이는 최소 2, 최대 10이다. 그 다음 두 줄에는 각각 <악마의 돌다리>와 <천사의 돌다리>를 나타내는 같은 길이의 문자열이 주어진다. 그 길이는 5 이상, 20 이하이다.

**출력**  

출력 파일에 마법의 두루마리에 적힌 문자열의 순서대로 다리를 건너갈 수 있는
방법의 수를 출력한다. 그러한 방법이 없으면 0을 출력한다. 모든 테스트 데이터에 대한 출력결과는 2^31 - 1 이하이다.

| 입력 예 | 출력 예     |
|---|---|
| RGS <br> RINGSR <br> GRGGNS | 3 |
| RINGS <br> SGNIRSGNIR <br> GNIRSGNIRS | 0 |
| GG <br> GGGGRRRR <br> IIIIGGGG | 16 |