#pragma once
#include <Windows.h>
#include <vector>
using namespace std;

#define CARD_WIDTH 126
#define CARD_HEIGHT 126
#define BLACK 1
#define WHITE 2

enum GAME_STATE
{
	GAME_STATE_WAIT,
	GAME_STATE_SELECT,
	GAME_STATE_MOVE
};
class ResManager;
class Chessman;
class Block;
class Move_Range;
class GameManager
{
private:
	static GameManager*		m_pThis;
	ResManager*				m_pResManager;

	vector<Chessman*>		m_vecChessman;
	Chessman*				m_pChessman_Select;

	vector<Chessman*>		m_vecBlock;
	vector<Chessman*>		m_vecMove_Range;

	HWND					m_hWnd;
	GAME_STATE				m_eGameState;
	BOOL					m_bTurn;
	vector<POINT>			m_vecMoveable;
	int						m_aiMap[8][8];
	GameManager();
public:
	static GameManager* GetInstance()
	{
		if (m_pThis == NULL)
			m_pThis = new GameManager();

		return m_pThis;
	}
	void Init(HWND hWnd, HINSTANCE hInst, HDC hdc);
	void Catch(int Color);
	void Update();
	void OnClick(int x, int y);
	void Draw(HDC hdc);
	void Release();
	~GameManager();
};

