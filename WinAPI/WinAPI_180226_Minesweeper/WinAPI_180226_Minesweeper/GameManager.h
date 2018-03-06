#pragma once
#include <Windows.h>
#include <vector>
using namespace std;

#define CARD_WIDTH 26
#define CARD_HEIGHT 26
#define BLOCK 0
#define MINE 1
#define OPEN 2

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
	DIRECTION_LT,
	DIRECTION_T,
	DIRECTION_RT,
	DIRECTION_L,
	DIRECTION_R,
	DIRECTION_LB,
	DIRECTION_B,
	DIRECTION_RB,
	DIRECTION_END
};
class ResManager;
class Block;
class GameManager
{
private:
	static GameManager*		m_pThis;
	ResManager*				m_pResManager;

	vector<Block*>			m_vecBlock;
	Block*					m_pBackGround;

	HWND					m_hWnd;
	GAME_MODE				m_eGameMode;
	GameManager();

	int m_iWidth;
	int m_iHeight;
	int m_iMine[24];
	int m_iMap[16][24];
	struct Point
	{
		int x;
		int y;
	};
	Point ptDir[DIRECTION_END] = { { -1, -1 },{ -1, 0 },{ -1, +1 },{ 0, -1 },{ 0, +1 },{ +1, -1 },{ +1, 0 },{ +1, +1 } };

public:
	static GameManager* GetInstance()
	{
		if (m_pThis == NULL)
			m_pThis = new GameManager();

		return m_pThis;
	}
	void setBackGround(Block* pNew_Block);
	void setBlock(Block* pNew_Block);
	void setMine();

	void Init(HWND hWnd, HINSTANCE hInst, HDC hdc);
	void SetGameMode(GAME_MODE mode);
	void Check(int x, int y);
	void setBlock(Block* pBlock, int count);

	void OnClick(int x, int y);
	void Draw(HDC hdc);
	void Release();
	~GameManager();
};

