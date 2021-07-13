#include <string>
#include <vector>

using namespace std;


bool check(vector<vector<int>> lock)
{
	int n = lock.size() / 3;

	for (int i = n; i < n * 2; i++)
	{
		for (int j = n; j < n * 2; j++)
		{
			if (lock[i][j] != 1)
				return false;

		}

	}

return true;
}


vector<vector<int>> rorate90(vector<vector<int>> key)
{
	int n = key.size();
	int m = key[0].size();

	vector<vector<int>> result(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j <m; j++)
		{
			result[j][n - i - 1] = key[i][j];

		}
	return result;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int n = lock.size();
    int m = key.size();
    
    //자물쇠 크기 3배로 변환
     vector<vector<int> > newLock(n * 3, vector<int>(n * 3));
    
    //new자물쇠 정가운데 기존 자물쇠 넣기
    for(int i =0 ; i < n; i++)
    {
        for(int j =0; j < n ; j++)
        {
            newLock[n+i][n+j] = lock[i][j];
            
        }
        
    }
    
    //4가지 방향에 대해서 확인
    for(int rot =0 ; rot < 4 ; rot++)
    {
        key = rorate90(key);
        for(int x =0 ; x<n*2 ; x++)
        {
            for(int y =0 ; y<n*2 ; y++)
            {
                //자물쇠에 열쇠 끼워 넣기
                for(int i =0 ; i < m ; i++)
                {
                    for(int j =0 ; j < m ; j++)
                    {
                        newLock[x+i][y+j] += key[i][j];
                        
                    }
                    
                }
                
                //새로운 자물쇠에 열쇠가 정확 맞는지
                if(check(newLock)) return true;
                //자물쇠 열쇠를 다시 빼기
                
                for(int i =0 ; i < m ; i++)
                {
                    for(int j =0; j <m; j++)
                    {
                        newLock[x+i][y+j] -= key[i][j];
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
    return answer;
}
