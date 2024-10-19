Given below are the raw materials quantities and their respective selling price(if sold as raw).

D --> No of CPUs
E --> No of memory chips
F --> No of boards
d --> Selling price of CPU
e --> Selling price of Memory chips

We are given N Computer configurations like below : 
Di, Ei, Fi, SPi, which are the CPU, Chips, Boards and one unit selling price for ith computer respectively.
Our task is to maximize the final cost.
Constraints:
1. Can use at Max 3 different Configurations
2. We can use 1 configuration multiple times
3. Remaining Inventories can be sold on its selling price

Input:
T --> Number of test cases.
D E F d e --> Inventories
N --> Total Configuration Count
Di Ei Fi SPi
...
Dn En Fn SPn

1<=T<=10
1<= D, E, F <= 100
1<= d, e <=100000
1<=N<=8

Output:
First Line print the Case #testCaseNumber
Second Line Print Maximum Cost per test case in each line.

Sample Input:
1 --> Total Test Case
10 10 10 2 1 --> D E F d e
1 --> PC Configuration Count
1 2 2 3 --> D1 E1 F1 SP1

Sample Output:
Case #1
30


Solution:

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int _cases = 1; _cases <= t; ++_cases) {
        int D, E, F, d, e, config, answer = 0;
        cin >> D >> E >> F >> d >> e;
        cin >> config;

        vector<vector<int>> configs(config, vector<int>(4)); // 2D vector to store Di, Ei, Fi, SPi

        for (int i = 0; i < config; ++i) {
            cin >> configs[i][0] >> configs[i][1] >> configs[i][2] >> configs[i][3];
        }

        stack<vector<int>> st; // stack to simulate recursive exploration
        st.push({0, D, E, F, 0, 0}); // {index, remaining D, remaining E, remaining F, current cost, configurations used}

        while (!st.empty()) {
            auto current = st.top();
            st.pop();

            int index = current[0];
            int remainingD = current[1];
            int remainingE = current[2];
            int remainingF = current[3];
            int cost = current[4];
            int counta = current[5];

            // Base case: no more configurations or 3 different configurations used
            if (index >= config || counta == 3) {
                cost += remainingD * d + remainingE * e;
                answer = max(answer, cost);
                continue;
            }

            // Explore without using current configuration
            st.push({index + 1, remainingD, remainingE, remainingF, cost, counta});

            // Explore using current configuration multiple times
            int i = 1;
            while (true) {
                if (remainingD - configs[index][0] * i >= 0 && 
                    remainingE - configs[index][1] * i >= 0 && 
                    remainingF - configs[index][2] * i >= 0) {
                    
                    st.push({index + 1, 
                             remainingD - configs[index][0] * i, 
                             remainingE - configs[index][1] * i, 
                             remainingF - configs[index][2] * i, 
                             cost + configs[index][3] * i, 
                             counta + 1});
                    ++i;
                } else {
                    break;
                }
            }
        }

        cout << "Case #" << _cases << "\n" << answer << "\n";
    }

    return 0;
}

---------------------------------------------------------------------



You want to cut a piece of paper by a certain fixed rule to make some pieces of white or 
blue colored square paper with various sizes.  
 
If the size of the entire paper is N×N (N = 2^K; 1 <= K <= 7; K = natural number), the cutting rules
are as below.
 
‘If the entire piece of paper is not colored the same, cut the middle part horizontally and vertically 
to divide it into the same sized four pieces of paper, 
(N/2)×(N/2), as with I, II, III, IV in < FIG. 2 >. 

For each I, II, III and IV, cut and divide again in the same way if one entire piece of paper 
is not colored the same, and make them into the same sized four pieces of paper. Continue until each and 
every piece of paper has only one color of white or blue.’
 
When you finish, < FIG. 3 > shows the first division of < FIG. 1 > and < FIG. 4 > 
shows the final version of 9 pieces of white paper and 7 pieces of blue paper of various sizes.
 
If the length of an edge of the first given piece of paper, N, and 
the color information (white or blue) inside each square are given, create a calculation program
 that assesses how many white/blue pieces of paper are.
 
Time limit: 1 second (java: 2 seconds) 
 
[Input]
 
Input may include many test cases. The number of test cases, T, is given on the first line of input and then the amount of T of test cases is given in a line. (T <= 30)
The length of an edge of the first given piece of paper, N, is given for the first line of each test case.
From the next line through to the amount of N lines, the color information is given separately as blanks. 0 indicates white and 1 indicates blue.
 
[Output]
 
For each test case, you should print "Case #T" in the first line where T means the case number. 
 
For each test case, you should output the number of white pieces of paper and blue pieces of paper separately as blanks on the first line of each test case.
 
[I/O Example]
Input 
2
8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1 
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
 
 
16
1 0 0 1 0 0 0 0 0 0 1 1 0 1 1 1
1 1 0 1 0 1 1 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 1 1 1 0 0 1 0 0 1
1 1 0 0 1 0 0 1 0 0 1 0 1 1 1 0
0 1 1 1 0 0 1 1 0 0 1 0 0 1 1 1
1 0 1 1 0 0 0 1 0 1 0 1 0 0 1 1
1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 0
1 1 0 1 0 1 0 0 1 0 1 1 1 0 0 1
1 1 1 1 1 1 0 0 1 0 1 1 0 1 1 0
1 0 0 1 1 1 0 0 0 0 1 1 1 1 0 0
1 0 0 1 1 1 1 0 0 0 1 1 0 1 0 1
1 1 1 0 1 1 0 0 1 1 1 1 1 1 0 1
1 1 1 1 1 1 0 0 0 0 1 1 1 1 0 0
1 1 1 1 1 1 0 1 1 1 1 1 1 1 0 0
1 1 0 0 0 0 0 0 1 1 0 1 1 0 0 0
1 1 0 0 1 1 0 0 0 1 1 1 1 0 0 0
 
 
 
Output
 
Case #1
9 7
 
Case #2
88 99



Solution : 
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 129;

bool checkSame(const vector<vector<bool>>& arr, int sti, int stj, int size) {
    bool color = arr[sti][stj];
    for (int i = sti; i < sti + size; i++) {
        for (int j = stj; j < stj + size; j++) {
            if (arr[i][j] != color) {
                return false;
            }
        }
    }
    return true;
}

void solve(const vector<vector<bool>>& arr, int size, int sti, int stj, int& white, int& blue) {
    bool same = checkSame(arr, sti, stj, size);
    
    if (!same) {
        int newSize = size / 2;
        solve(arr, newSize, sti, stj, white, blue);
        solve(arr, newSize, sti + newSize, stj, white, blue);
        solve(arr, newSize, sti, stj + newSize, white, blue);
        solve(arr, newSize, sti + newSize, stj + newSize, white, blue);
    } else {
        (arr[sti][stj]) ? ++blue : ++white;
    }
}

int main() {
    int test;
    cin >> test;
    for (int l = 1; l <= test; l++) {
        int white = 0, blue = 0;
        int size;
        cin >> size;
        vector<vector<bool>> arr(size, vector<bool>(size));
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cin >> arr[i][j];
            }
        }
        
        solve(arr, size, 0, 0, white, blue);
        
        cout << "Case #" << l << endl;
        cout << white << " " << blue << endl;
    }
    return 0;
}

// optimized approach using prefix sum of matrix

#include <iostream>
using namespace std;

const int maxn = 129;

void solve(int arr[maxn][maxn], int size, int si, int sj, int& white, int& blue) {
    if (size == 0) return;

    int sum = arr[size + si - 1][size + sj - 1];
    if (sj - 1 >= 0) sum -= arr[size + si - 1][sj - 1];
    if (si - 1 >= 0) sum -= arr[si - 1][sj + size - 1];
    if (si - 1 >= 0 && sj - 1 >= 0) sum += arr[si - 1][sj - 1];

    if (sum == 0) {
        white++;
        return;
    }
    if (sum == size * size) {
        blue++;
        return;
    }

    int newSize = size / 2;
    solve(arr, newSize, si, sj, white, blue);
    solve(arr, newSize, si + newSize, sj, white, blue);
    solve(arr, newSize, si, sj + newSize, white, blue);
    solve(arr, newSize, si + newSize, sj + newSize, white, blue);
}

int main() {
    int test;
    cin >> test;

    for (int l = 1; l <= test; l++) {
        int white = 0, blue = 0;
        int size;
        cin >> size;
        int arr[maxn][maxn] = {0};

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int a;
                cin >> a;
                arr[i][j] = a + (i > 0 ? arr[i - 1][j] : 0) + (j > 0 ? arr[i][j - 1] : 0) - (i > 0 && j > 0 ? arr[i - 1][j - 1] : 0);
            }
        }

        solve(arr, size, 0, 0, white, blue);

        cout << "Case #" << l << endl;
        cout << white << " " << blue << endl;
    }
    return 0;
}
