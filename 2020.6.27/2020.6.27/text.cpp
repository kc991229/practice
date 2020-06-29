#if 0
/*
���������������ֱ��ʾ��λ�������������������������Ӧ�����飬���е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·.
���ݱ�֤��Ψһ��,�������ж�����������Թ�ֻ��һ��ͨ����

�������:
���Ͻǵ����½ǵ����·������ʽ��������ʾ��

ʾ��1
����
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
���
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)
*/
#include<iostream>
#include<vector>
using namespace std;

int N, M; //�ֱ�����к���
vector<vector<int>> maze;//�Թ�����
vector<vector<int>> path_temp;//�洢��ǰ·������һά��ʾλ��
vector<vector<int>> path_best;//�洢���·��

void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//��ʾ��ǰ�ڵ����ߣ���������
	path_temp.push_back({ i, j });//����ǰ�ڵ���뵽·����

	if (i == N - 1 && j == M - 1) //�ж��Ƿ񵽴��յ�
	if (path_best.empty() || path_temp.size() < path_best.size())
		path_best = path_temp;

	if (i - 1 >= 0 && maze[i - 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j + 1);
	maze[i][j] = 0;         //�ָ��ֳ�����Ϊδ��
	path_temp.pop_back();
}
int main()
{
	while (cin >> N >> M)
	{
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto &i : maze)
		for (auto &j : i)
			cin >> j;
		MazeTrack(0, 0);//����Ѱ���Թ����ͨ·
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//���ͨ·
	}
	return 0;
}
#endif


#if 0
/*


С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ��
��Ϸ��һ��6*6�������Ͻ��У��������36����ֵ���ȵ����ÿ��С���������������һ�����
����Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ�����������½�ֹͣ��һ·�ϵĸ����������С�������õ���
�����һ���㷨ʹС���õ���ֵ��ߵ����

����һ��6*6�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ,���Ͻ�Ϊ[0,0],�뷵���ܻ�õ�����ֵ��
��֤ÿ�������ֵ����100С��1000��
*/
class Bonus {
public:
	int dp[6][6];
	int getMost(vector<vector<int> > board) 
	{
		memset(dp, 0, sizeof(dp));
		dp[0][0] = board[0][0];
		for (int i = 1; i < 6; i++) 
			dp[0][i] = dp[0][i - 1] + board[0][i];
		for (int i = 1; i < 6; i++) 
			dp[i][0] = dp[i - 1][0] + board[i][0];
		for (int i = 1; i < 6; i++)
		for (int j = 1; j < 6; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
		}
		return dp[5][5];
	}
};
#endif