#include <iostream>
using namespace std;
int main() {
    cout << "�߿������磡" << endl;
    int score = 100;
    cout << "�����������˶��ٷ֣�" << endl;
    cin >> score;
    cout << "���ķ����ǣ�" << score << endl;
    if (score >= 600) {
        cout << "��ϲ��������һ����" << endl;
    }
    else {
        cout << "���ź�����û�п���һ����" << endl;
    }

    system("pause");
    getchar();
    // ע��
    return 0;
}
