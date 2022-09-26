#include <bits/stdc++.h>
using namespace std;
int n = 5;
// int a[4][4] = {90, 75, 75, 80, 35, 85, 55, 65, 125, 95, 90, 105, 45, 110, 95, 115};
int a[5][5]={16,14,18,17,20,14,13,16,15,17,18,16,17,19,20,19,17,15,16,19,17,15,19,18,21};
bool maps[5][5];
int minr[5];
int minc[5];
int lines_r[5];
int lines_c[5];
bool step0() {
    int mins = INT_MAX;
    int sumr = 0;  //行优先
    int sumc = 0;  //列优先
    for (int i = 0; i < n; i++) {
        mins = INT_MAX;
        int temp = 0;
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
        int temp = 0;
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
    for (int i = 0; i < n; i++) {
        int temp = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (a[i][j] < temp)
                temp = a[i][j];
        }
        minr[i] = temp;
    }
}
void step1_c_pre(){
    for (int i = 0; i < n; i++) {
        int temp = INT_MAX;
        for (int j = 0; j < n; j++) {
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
                maps[i][j]=true;
                int sumr = 1, sumc = 1;
                for (int k = j + 1; k < n; k++) {
                    if (a[i][k] == 0&&maps[i][k]==false)
                        sumr++;
                }
                for (int k = i + 1; k < n; k++) {
                    if (a[k][j] == 0&&maps[k][j]==false)
                        sumc++;
                }
                if (sumr >= sumc) {
                    for (int k = 0; k < n; k++) {
                        maps[i][k] = true;
                    }
                    lines_r[i]=true;
                    lines++;
                } else {
                    for (int k = 0; k < n; k++) {
                        maps[k][j] = true;
                    }
                    lines_c[j]=true;
                    lines++;
                }
            }
        }
    }
    return lines;
}
int main() {
    bool flag = step0();
    if (flag) {
        step1_c_pre();//step0 优化预处理
        step1_c();
        step1_r_pre();
        step1_r();
    } else {
        step1_r_pre();
        step1_r();
        step1_c_pre();
        step1_c();
    }//行列减去最小值
    int lines=step2();//划线
    while(lines<n){//step3 判优
        //step4 直线未覆盖区域与覆盖区域处理
        int temp=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(maps[i][j]==false){
                    if(temp>a[i][j]) temp=a[i][j];
                }
            }
        }//从没有被覆盖的元素里面挑出最小的元素
        for(int i=0;i<n;i++){
            if(lines_r[i]==false){
                for(int j=0;j<n;j++){
                    a[i][j]-=temp;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(lines_c[i]==true){
                for(int j=0;j<n;j++){
                    a[j][i]+=temp;
                }
            }
        }//step4 finish
        lines=step2();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}