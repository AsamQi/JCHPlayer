#pragma once
#include "player/AVPlayer.h"
#include "Duilib.h"
#include <vector>
#include<iostream>

using namespace std;

const int MAX_PLANE = 1;

class CDuiFrameDlg : public CXMLWnd
{
public:
	explicit CDuiFrameDlg(LPCTSTR pszXMLName);
	~CDuiFrameDlg();


	DUI_DECLARE_MESSAGE_MAP()
	virtual void InitWindow();
	virtual CControlUI* CreateControl(LPCTSTR pstrClassName);
	virtual void Notify(TNotifyUI& msg);
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual void OnClick(TNotifyUI& msg);
	void OnMouseMove();
	LRESULT OnPlaying(HWND hwnd, WPARAM wParam, LPARAM lParam);     // �ļ�ͷ��ȡ��ϣ���ʼ����
	LRESULT OnPosChanged(HWND hwnd, WPARAM wParam, LPARAM lParam);  // ���ȸı䣬�������������Ľ���
	LRESULT OnEndReached(HWND hwnd, WPARAM wParam, LPARAM lParam);  // �ļ��������
	void OnGetMinMaxInfo(HWND hwnd, LPMINMAXINFO lpMinMaxInfo);
	bool    OnPosChanged(void* param);                              // ���ȸı䣬�û������ı����
	bool    OnVolumeChanged(void* param);                           // �����ı�
	
private:
	void ShowPlayWnd(BOOL show);
	void OpenFolderDlg();
	void ShowPlaylist(BOOL show);
	void SetFullScreen(BOOL full);
	BOOL IsPointAtRect(POINT p, int rcl, int rct, int rcr, int rcb);
	BOOL AddPlayFile(WCHAR *folder);
	int  GetPlayerNum();
	int  MinUnPlayerNum();
	int  GetMouseClickPlayer();

private:
	vector<wstring>   m_vcPlayFile;			//�����ļ�
	wstring m_strFolderName;				//�����ļ���
	BOOL m_bPingPong;
	BOOL m_bIsFullScreen;					//ȫ����־
	BOOL m_bIsShowPlaylist;					//�����б���ʾ��ʶ
	int m_iMonitorWidth;					//��ʾ�����
	int m_iMonitorHeight;
	CSliderUI       *m_pSliderPlay;			// �ļ����Ž���
	CLabelUI        *m_pLabelTime;			// �ļ�����ʱ��
	WINDOWPLACEMENT m_OldWndPlacement;		// ���洰��ԭ����λ��
	CAVPlayer m_myPlayer;		//	������
};