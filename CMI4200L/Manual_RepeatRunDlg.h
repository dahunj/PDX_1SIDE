#pragma once

#include "Common.h"
#include "AJinDefine.h"
#include "AJinAXL.h"
#include "LogFile.h"


// CManual_RepeatRunDlg ��ȭ �����Դϴ�.

class CManual_RepeatRunDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManual_RepeatRunDlg)

public:
	CManual_RepeatRunDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CManual_RepeatRunDlg();

	CGroupCS	m_Group[1];
	CLabelCS	m_Label[3];
	CComboCS	m_cboPicker;
	CComboCS	m_cboPickNum;
	CEditCS		m_edtDelay;
	CCheckCS	m_chkRepeatRun;

	CEditCS		m_edtMsg;
	CLabelCS    m_lblCase;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MANUAL_REPEAT_RUN_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

private:
	CString m_strLog;
	void Initial_Controls();

	CLogFile *pLogFile;
	CCommon  *pCommon;
	CAJinAXL *pAJinAXL;

protected:
	CString m_strTemp;

	int m_nRepeatCase;

	int m_nPickerSelected;
	int m_nPickerNumSelected;

	int	 m_nPickerSelect;
	int	 m_nPickerNum;
	int	 m_nActionDelay;
	void Repeat_Action();

	BOOL		m_bThreadAction;
	CWinThread* m_pThreadAction;
	static UINT	Thread_ActionRun(LPVOID lpVoid);

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedChkRepeatRun();
	afx_msg void OnCbnSelchangeCboPicker();
	afx_msg void OnCbnSelchangeCboPickNum();
	afx_msg void OnBnClickedBtnResetcase();
};
