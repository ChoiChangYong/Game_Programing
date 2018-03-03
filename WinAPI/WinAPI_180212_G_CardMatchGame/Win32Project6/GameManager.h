#pragma once
#include <Windows.h>
#include <vector>
using namespace std;

enum GAME_STATE
{
	GAME_STATE_WAIT,
	GAME_STATE_SELECT,
	GAME_STATE_SHOW
};

class ResManager;
class Card;
class GameManager
{
private:
	static GameManager* m_pThis;
	ResManager*			m_pResManager;
	vector<Card*>		m_vecCard;
	Card*				m_pSelectOne;
	Card*				m_pSelectTwo;
	HWND				m_hWnd;
	GAME_STATE			m_eGameState;
	DWORD				m_dwCount;
	GameManager();
public:
	static GameManager* GetInstance()
	{
		if (m_pThis == NULL)
			m_pThis = new GameManager();

		return m_pThis;
	}

	void Init(HWND hWnd , HINSTANCE hInst , HDC hdc);
	void Update();
	void OnClick(int x, int y);
	void Draw(HDC hdc);

	void Release();

	~GameManager();
};

