// ManualDlg.h : 헤더 파일
//
#pragma once

#include "Manual_InspectorDlg.h"
#include "Manual_Good_Ng_PickerDlg.h"
#include "Manual_UnloadingDlg.h"
#include "Manual_LoadPickerDlg.h"
#include "Manual_Unload_PickerDlg.h"
#include "Manual_LoadingDlg.h"
#include "Manual_RepeatRunDlg.h"

// CManualDlg 대화 상자입니다.

class CManualDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManualDlg)

public:
	CManualDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CManualDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_MANUAL_DLG };
	CPictureCS	m_picManualBack;
	CRadioCS	m_rdoManualFlow;
	CRadioCS	m_rdoManualElevator;
	CRadioCS	m_rdoManualGripper;
	CRadioCS	m_rdoManualPicker;
	CRadioCS	m_rdoManualInspector;
	CRadioCS    m_rdoManualRepeatRun;
	CRadioCS	m_rdoManualDoorLock;
	CRadioCS	m_rdoManualDoorUnlock;
	CRadioCS	m_rdoManualElevator2;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedRdoManualFlow();
	afx_msg void OnBnClickedRdoManualElevator();
	afx_msg void OnBnClickedRdoManualGripper();
	afx_msg void OnBnClickedRdoManualPicker();
	afx_msg void OnBnClickedRdoManualInspector();
	afx_msg void OnBnClickedRdoManualDoorLock();
	afx_msg void OnBnClickedRdoManualDoorUnlock();

	afx_msg void OnBnClickedRdoManualElevator2();

public:
	CManual_LoadingDlg			*m_pManualLoadingDlg;
	CManual_InspectorDlg		*m_pManualInspectorDlg;
	CManual_Good_Ng_PickerDlg	*m_pManualPickerDlg;
	CManual_UnloadingDlg		*m_pManualUnloadDlg;
	CManual_LoadPickerDlg		*m_pManualLoadPickerDlg;
	CManual_Unload_PickerDlg	*m_pManualPicker3Dlg;
	CManual_RepeatRunDlg		*m_pManualRepeatRunDlg;
	
private:
	void Initial_Controls();
	void Hide_Windows();

public:
	void MainDoor_Lock();
	void MainDoor_Unlock();
	afx_msg void OnBnClickedRdoManualRepeat();
};

extern CManualDlg g_dlgManual;

///////////////////////////////////////////////////////////////////////////////
