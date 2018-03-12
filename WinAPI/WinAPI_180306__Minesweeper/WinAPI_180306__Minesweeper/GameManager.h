#pragma once
#include <Windows.h>
#include <vector>
using namespace std;

#define CARD_WIDTH 26
#define CARD_HEIGHT 26

struct Point
{
	int x;
	int y;
};
enum GAME_MODE
{
	GAME_MODE_EASY,
	GAME_MODE_NORMAL,
	GAME_MODE_HARD
};
enum DIRECTION
{
	DIRECTION_LT,	//0
	DIRECTION_T,	//1
	DIRECTION_RT,	//2
	DIRECTION_L,	//3
	DIRECTION_R,	//4
	DIRECTION_LB,	//5
	DIRECTION_B,	//6
	DIRECTION_RB,	//7
	DIRECTION_END	//8
};
class ResManager;
class BitMap;
class Block;
class GameManager
{
private:
	static GameManager*		m_pThis;
	ResManager*				m_pResManager;

	BitMap*					m_pBackGround;

	HWND					m_hWnd;
	GAME_MODE				m_eGameMode;
	GameManager();

	int m_iWidth;
	int m_iHeight;
	int m_iMine[24];
	Block* m_iMap[16][24];

	struct Point
	{
		int x;
		int y;
	};
	Point ptDir[DIRECTION_END] = { { -1, -1 },{ -1, 0 },{ -1, +1 },{ 0, +1 },{ +1, +1 },{ +1, 0 },{ +1, -1 },{ 0, -1 } };

	int m_nFlag_Count;
	int m_nMine_Count;

	int m_nTimeCount;
	TCHAR sTime[128];
public:
	static GameManager* GetInstance()
	{
		if (m_pThis == NULL)
			m_pThis = new GameManager();

		return m_pThis;
	}
	void setBlock();
	void setMine();
	void Init(HWND hWnd, HINSTANCE hInst, HDC hdc);
	void SetGameMode(GAME_MODE mode);


	void Check(int x, int y);
	bool Check_Range(int x, int y);

	void M_Button_Check(int x, int y);
	void Open_Surroundings(int x, int y);

	int get_Surround_MineCount(int x, int y);
	int get_Surround_FlagCount(int x, int y);

	void setBlock(int count, int x, int y);

	void TimerStart();

	void OnClickL(int x, int y);
	void OnClickR(int x, int y);
	void OnClickM(int x, int y);

	void Victory();
	void GameOver();
	void Reset();

	void Draw(HDC hdc);
	void Release();
	~GameManager();
};

