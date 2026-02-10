# TP 1
## AGGRCOW - Aggressive cows

Farmer John has built a new long barn, with $N$ ($2 \le N \le 100,000$) stalls. The stalls are located along a straight line at positions $x_1 ... x_N$ ($0 \le x_i \le 1,000,000,000$).

His $C$ ($2 \le C \le N$) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

### Input
$t$ – the number of test cases, then $t$ test cases follows.

* **Line 1:** Two space-separated integers: `N` and `C`
* **Lines 2..N+1:** Line $i+1$ contains an integer stall location, $x_i$

### Output
For each test case output one integer: the largest minimum distance.

### Example

**Input:**
```text
1
5 3
1
2
8
4
9
```
**Output:**
```text
3
```
### Explanation

FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.

---

[Ver Solución](./cows.cpp)

## BORW - Black or White

> "It’s Black, It’s White, It’s Tough For You To Get By"
> — Michael Jackson (1958-2009)

You have a sequence of integers. You can paint each of the integers black or white, or leave it unpainted. The black integers must appear in ascending order and the white integers must appear in descending order. The ascending/descending order must be strict, that is, two integers painted with the same color cannot be equal. Paint the sequence so as to minimize the number of unpainted integers.

### Input
The input contains several test cases, each one described in exactly two lines.

* **Line 1:** An integer $N$ indicating the number of elements in the sequence ($1 \le N \le 200$).
* **Line 2:** $N$ integers $X_i$ separated by single spaces, representing the sequence to paint ($1 \le X_i \le 10^6$ for $1 \le i \le N$).
* The last line of the input contains a single $-1$ and should not be processed as a test case.

### Output
For each test case output a single line with an integer representing the minimum number of unpainted elements of the sequence, when the sequence is painted optimally following the rules described above.

### Example

**Input:**
```text
8
1 4 2 3 3 2 4 1
12
7 8 1 2 4 6 3 5 2 1 8 7
-1
```
**Output:**
```text
0
2
```

---

[Ver Solución](./borw.cpp)

## BUSYMAN - I AM VERY BUSY

You are actually very busy man. You have a big schedule of activities. Your aim is to do as much as activities as possible.

In the given figure, if you go to date with crush, you cannot participate in the coding contest and you can't watch the movie. Also if you play DotA, you can't study for the exam. If you study for the exam you can't sleep peacefully. The maximum number of activities that you can do for this schedule is 3.

Either you can:
* watch movie, play DotA and sleep peacefully (or)
* date with crush, play DotA and sleep peacefully

### Input
The first line consists of an integer $T$, the number of test cases. For each test case the first line consists of an integer $N$, the number of activities. Then the next $N$ lines contains two integers $m$ and $n$, the start and end time of each activity.

### Output
For each test case find the maximum number of activities that you can do.

### Constraints
* $1 \le T \le 10$
* $1 \le N \le 100000$
* $0 \le start < end \le 1000000$

### Example

**Input:**
```text
3
3
3 9
2 8
6 9
4
1 7
5 8
7 8
1 8
6
7 9
8 10
4 5
8 9
4 10
5 7
```
**Output:**
```text
1
2
3
```

---

[Ver Solución](./busy.cpp)
