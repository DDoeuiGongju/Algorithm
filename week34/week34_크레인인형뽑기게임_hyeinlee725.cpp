#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;//������ �̾Ƽ� ������ �ٱ���(stack)
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i] - 1] != 0) {//board�� ������ ������ �̱�
                if (!basket.empty()) {//stack�� ������ ������ ������ Ȯ�� X
                    //stack�� ������� ������, �ֻ�ܿ� ���� ������ �ִ��� Ȯ��
                    if (basket.top() == board[j][moves[i] - 1]) {//���� ���
                        answer += 2;//2���� �����Ƿ� +2
                        basket.pop();//���� ���� pop
                    }
                    else {//�ٸ� ���
                        basket.push(board[j][moves[i] - 1]);
                    }
                }
                else {
                    basket.push(board[j][moves[i] - 1]);
                }
                board[j][moves[i] - 1] = 0;//board���� ����
                break;
            }
        }
    }
    return answer;
}