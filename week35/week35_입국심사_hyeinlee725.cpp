#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end()); //�ִ� �ð� �˱� ���� ����
    long long minTime = 1; //�ּ� �ð�
    long long maxTime = (long long) times[times.size() - 1] * n; //�ִ� �ð�
    long long mid;

    while (minTime <= maxTime) {
        mid = (minTime + maxTime) / 2; //�߾Ӱ�
        long long count = 0; //mid �ð����� �ɻ��� �� �ִ� ��� ��
        for (int i = 0; i < times.size(); i++) {
            count += mid / times[i]; //+�� �ð��� ó���� �� �ִ� ��� ��
        }
        if (count < n) {
            minTime = mid + 1; //�ּҰ��� mid + 1��
        }
        else { //mid �ð� ���� ó���� �� �ִ� ������� n�� �̻�
            if (mid <= maxTime) { // mid�� �ִ�ð������̸�
                answer = mid;
            }
            maxTime = mid - 1; //���� ���̱�(�ִ밪�� mid - 1)
        }
    }
    return answer;
}