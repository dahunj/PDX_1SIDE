// ManualDlg.h : 헤더 파일
//
#pragma once

#include "ManualInspectorDlg.h"
#include "ManualPickerDlg.h"
#include "ManualUnloadDlg.h"
#include "ManualPicker2Dlg.h"
#include "ManualPicker3Dlg.h"
#include "ManualLotDataDlg.h"
#include "ManualLoadingDlg.h"

// CManualDlg 대화 상자입니다.

class CManualDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManualDlg)

private:
	static CManualDlg *m_pInstance;

public:
	static CManualDlg *Get_Instance(CWnd *pParent = NULL);
	void Delete_Instance();

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
	CRadioCS	m_rdoManualDoorLock;
	CRadioCS	m_rdoManualDoorUnlock;
	
	CRadioCS	m_rdoManualPicker2;
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

	afx_msg void OnBnClickedRdoManualPicker2();
	afx_msg void OnBnClickedRdoManualElevator2();

public:
	

	CManualLoadingDlg	*m_pManualLoadingDlg;
	CManualInspectorDlg	*m_pManualInspectorDlg;
	CManualPickerDlg	*m_pManualPickerDlg;
	CManualUnloadDlg	*m_pManualUnloadDlg;
	CManualLoadPickerDlg	*m_pManualLoadPickerDlg;
	CManualPicker3Dlg	*m_pManualPicker3Dlg;
	
private:
	void Initial_Controls();
	void Hide_Windows();

public:
	void MainDoor_Lock();
	void MainDoor_Unlock();
};

///////////////////////////////////////////////////////////////////////////////
