#include <bits/stdc++.h>
using namespace std;
int n;
int n1,m1;
// int a[4][4] = {90, 75, 75, 80, 35, 85, 55, 65, 125, 95, 90, 105, 45, 110, 95, 115};//90 75 75 80 35 85 55 65 125 95 90 105 45 110 95 115
// int a[5][5]={16,14,18,17,20,14,13,16,15,17,18,16,17,19,20,19,17,15,16,19,17,15,19,18,21};//16 14 18 17 20 14 13 16 15 17 18 16 17 19 20 19 17 15 16 19 17 15 19 18 21
int a[100][100];//Change the definition type according to the matrix element type, and the comment will be represented by 1 later
bool maps[100][100];//1
int minr[100];//1
int minc[100];//1
bool lines_r[100];
bool lines_c[100];
bool step0() {
    int mins = INT_MAX;//1
    int sumr = 0;  //The sum of the minimum number of elements in the row//1
    int sumc = 0;  //The sum of the minimum number of elements in the column//1
    for (int i = 0; i < n; i++) {
        mins = INT_MAX;
        int temp = 0;//1
        for (int j = 0; j < n; j++) {
            if (a[i][j] < mins) {
                mins = a[i][j];
                temp = 1;
            } else if (mins == a[i][j]) {
                temp++;
            }
        }
        sumr += temp;
    }
    for (int i = 0; i < n; i++) {
        mins = INT_MAX;
        int temp = 0;//1
        for (int j = 0; j < n; j++) {
            if (a[j][i] < mins) {
                mins = a[j][i];
                temp = 1;
            } else if (mins == a[j][i]) {
                temp++;
            }
        }
        sumc += temp;
    }
    if (sumr > sumc)
        return true;
    else
        return false;
}
void step1_r_pre() {
    for (int i = 0; i < n1; i++) {
        int temp = INT_MAX;//1
        for (int j = 0; j < m1; j++) {
            if (a[i][j] < temp)
                temp = a[i][j];
        }
        minr[i] = temp;
    }
}
void step1_c_pre() {
    for (int i = 0; i < m1; i++) {
        int temp = INT_MAX;//1
        for (int j = 0; j < n1; j++) {
            if (a[j][i] < temp)
                temp = a[j][i];
        }
        minc[i] = temp;
    }
}
void step1_r() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] -= minr[i];
        }
    }
}
void step1_c() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[j][i] -= minc[i];
        }
    }
}
int step2() {
    int lines = 0;
    memset(maps, false, sizeof(maps));
    memset(lines_r, false, sizeof(lines_r));
    memset(lines_c, false, sizeof(lines_c));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0 && maps[i][j] == false) {
                maps[i][j] = true;
                int sumr = 1, sumc = 1;
                for (int k = j + 1; k < n; k++) {
                    if (a[i][k] == 0 && maps[i][k] == false)
                        sumr++;
                }
                for (int k = i + 1; k < n; k++) {
                    if (a[k][j] == 0 && maps[k][j] == false)
                        sumc++;
                }
                if (sumr >= sumc) {
                    for (int k = 0; k < n; k++) {
                        maps[i][k] = true;
                    }
                    lines_r[i] = true;
                    lines++;
                } else {
                    for (int k = 0; k < n; k++) {
                        maps[k][j] = true;
                    }
                    lines_c[j] = true;
                    lines++;
                }
            }
        }
    }
    return lines;
}
int main() {
    cout<<"please input the matrix order:"<<endl;
    cin>>n;
    cout<<"please input the number of lines excluding dummy lines:"<<endl;
    cin>>n1;
    cout<<"please input the number of columns other than virtual columns:"<<endl;
    cin>>m1;
    cout<<"please input the matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    bool flag = step0();
    if (flag) {
        step1_c_pre();  // step0 优化预处理 Optimize preprocessing
        step1_c();
        step1_r_pre();
        step1_r();
    } else {
        step1_r_pre();
        step1_r();
        step1_c_pre();
        step1_c();
    }                     //行列减去最小值 row column minus minimum value
    int lines = step2();  //划线 line the matrix
    while (lines < n) {   // step3 判优 determine whether it is optimal
        // step4 直线未覆盖区域与覆盖区域处理 Straight line uncovered area and coverage area processing
        int temp = INT_MAX;//1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (maps[i][j] == false) {
                    if (temp > a[i][j])
                        temp = a[i][j];
                }
            }
        }  //从没有被覆盖的元素里面挑出最小的元素 Pick the smallest element from the elements that are not covered
        for (int i = 0; i < n; i++) {
            if (lines_r[i] == false) {
                for (int j = 0; j < n; j++) {
                    a[i][j] -= temp;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (lines_c[i] == true) {
                for (int j = 0; j < n; j++) {
                    a[j][i] += temp;
                }
            }
        }  // step4 finish
        lines = step2();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
