이진 암호화
====================================

이진 압축이란 {0, 1}로 이루어진 길이가 <span> 2<sup>k </span> 인 문자열에 대해서, 모두 같은 문자가 될 때까지 크기가 <span>2<sup>k-1 </span>인 두 그룹으로 분할하여 모두 같은 문자가 되도록 하는 과정 으로 암호화를 한다. 만약 주어진 원문이 길이가 4인 “0000”라면, 암호문은 “0”이다.
만약 주어진 암호문이 길이가 4인 “1101”이라면 모든 문자가 같지 않기 때문에 “11 01”로 일단 한 번 분할하고 다시 뒷부분은 “01”로 같지 않으니 “11 0 1”로 분할 한다.

입력으로 주어진 영역의 한 변의 길이 n과 각 정사각형 칸의 색 (하얀색 또는 회 색)이 주어질 때 잘라진 하얀색 영역과 회색 영역의 개수를 구하는 프로그램을 작성 하시오.          


즉 이로써 만들어진 암호문은 “-1-01”이 된다. “-1-01” 의 의미는       

    - : 먼저 전체를 분할하고 
    1 : 분할된 왼쪽 부분은 모두 1이고 - : 오른쪽 분할은 다시 분할하며,
    01 : 분할된 결과는 0과 1이라는 의미이다.

길이가 n인 원문을 입력받아서 암호문을 출력하는 프로그램을 작성하시오.         



**입력** 


첫 번째 줄에 암호문의 길이 n이 입력된다.
두 번째 줄에 길이가 n인 0, 1로 구성된 암호문이 입력된다. (단, 1 <= n <= <span> 2<sup>18 </span> (단, n은 모두 <span> 2<sup>k </span>(k는 자연수))                                       


**출력**  

위 원리로 만들어진 암호문을 출력한다.       

| 입력 예                    |      출력 예                |
|---------------------------|-----------------------------|
|4 <br> 0000                | 0                           |
|4 <br> 1101                | -1-01                           |