// Manual_InspectorDlg.h : ��� ����
//
#pragma once

#define SCAN_INSPECT	0
#define SCAN_CALIBRATE	1
#define SCAN_LASER		2

// CManual_InspectorDlg ��ȭ �����Դϴ�.

class CManual_UnloadingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManual_UnloadingDlg)

public:
	CManual_UnloadingDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CManual_UnloadingDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MANUAL_UNLOAD_DLG };
	CStaticCS	m_stcAxisPos[4];
	CButtonCS	m_btnTR1Y[3];
	CButtonCS	m_btnTR1Z[4];
	CButtonCS	m_btnTR2Y[3];
	CButtonCS	m_btnTR2Z[4];

	CButtonCS	m_btnTR1IO[6];
	CButtonCS	m_btnShuttleIO[2];
	CButtonCS	m_btnTR2IO[6];
	CButtonCS	m_btnShuttleIO2[2];

	CLedCS		m_ledTR1[6];
	CLedCS		m_ledTR2[6];
	CLedCS		m_ledShuttle[6];
	CLedCS		m_ledShuttle2[6];

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);

	afx_msg void OnBtnShuttleIOClick(UINT nID);
	afx_msg void OnBtnShuttleIO2Click(UINT nID);
	afx_msg void OnBtnTR1YClick(UINT nID);
	afx_msg void OnBtnTR1ZClick(UINT nID);
	afx_msg void OnBtnTR1IOClick(UINT nID);
	afx_msg void OnBtnTR2YClick(UINT nID);
	afx_msg void OnBtnTR2ZClick(UINT nID);
	afx_msg void OnBtnTR2IOClick(UINT nID);
	
private:
	void Initial_Controls();


public:
	void Display_Status();


};

///////////////////////////////////////////////////////////////////////////////
