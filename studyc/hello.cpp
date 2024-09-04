#include <iostream>
using namespace std;
int main() {
    cout << "高考的世界！" << endl;
    int score = 100;
    cout << "请输入您考了多少分：" << endl;
    cin >> score;
    cout << "您的分数是：" << score << endl;
    if (score >= 600) {
        cout << "恭喜您考上了一本！" << endl;
    }
    else {
        cout << "很遗憾，您没有考上一本！" << endl;
    }

    system("pause");
    getchar();
    // 注释
    return 0;
}
