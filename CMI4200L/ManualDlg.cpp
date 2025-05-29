// ManualDlg.cpp : 구현 파일입니다.
//
#include "stdafx.h"
#include "CMI4200L.h"
#include "ManualDlg.h"
#include "afxdialogex.h"

#include "CMI4200LDlg.h"
#include "LogFile.h"

// CManualDlg 대화 상자입니다.

CManualDlg g_dlgManual;

IMPLEMENT_DYNAMIC(CManualDlg, CDialogEx)


CManualDlg::CManualDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManualDlg::IDD, pParent)
{
}

CManualDlg::~CManualDlg()
{
}

void CManualDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC_MANUAL_BACK, m_picManualBack);
	DDX_Control(pDX, IDC_RDO_MANUAL_FLOW, m_rdoManualFlow);
	DDX_Control(pDX, IDC_RDO_MANUAL_ELEVATOR, m_rdoManualElevator);
	DDX_Control(pDX, IDC_RDO_MANUAL_GRIPPER, m_rdoManualGripper);
	DDX_Control(pDX, IDC_RDO_MANUAL_PICKER, m_rdoManualPicker);
	DDX_Control(pDX, IDC_RDO_MANUAL_INSPECTOR, m_rdoManualInspector);
	DDX_Control(pDX, IDC_RDO_MANUAL_REPEAT, m_rdoManualRepeatRun);
	DDX_Control(pDX, IDC_RDO_MANUAL_DOOR_LOCK, m_rdoManualDoorLock);
	DDX_Control(pDX, IDC_RDO_MANUAL_DOOR_UNLOCK, m_rdoManualDoorUnlock);

	
	
	DDX_Control(pDX, IDC_RDO_MANUAL_ELEVATOR2, m_rdoManualElevator2);
}

BEGIN_MESSAGE_MAP(CManualDlg, CDialogEx)
	ON_WM_DESTROY()
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RDO_MANUAL_FLOW, &CManualDlg::OnBnClickedRdoManualFlow)
	ON_BN_CLICKED(IDC_RDO_MANUAL_ELEVATOR, &CManualDlg::OnBnClickedRdoManualElevator)
	ON_BN_CLICKED(IDC_RDO_MANUAL_GRIPPER, &CManualDlg::OnBnClickedRdoManualGripper)
	ON_BN_CLICKED(IDC_RDO_MANUAL_PICKER, &CManualDlg::OnBnClickedRdoManualPicker)
	ON_BN_CLICKED(IDC_RDO_MANUAL_INSPECTOR, &CManualDlg::OnBnClickedRdoManualInspector)
	ON_BN_CLICKED(IDC_RDO_MANUAL_DOOR_LOCK, &CManualDlg::OnBnClickedRdoManualDoorLock)
	ON_BN_CLICKED(IDC_RDO_MANUAL_DOOR_UNLOCK, &CManualDlg::OnBnClickedRdoManualDoorUnlock)
		
	ON_BN_CLICKED(IDC_RDO_MANUAL_ELEVATOR2, &CManualDlg::OnBnClickedRdoManualElevator2)
	ON_BN_CLICKED(IDC_RDO_MANUAL_REPEAT, &CManualDlg::OnBnClickedRdoManualRepeat)
END_MESSAGE_MAP()

// CManualDlg 메시지 처리기입니다.

BOOL CManualDlg::OnInitDialog() 
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetWindowPos(this, 0, 60, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	Initial_Controls();

	

	m_pManualInspectorDlg = new CManual_InspectorDlg(this);
	m_pManualInspectorDlg->Create(IDD_MANUAL_INSPECTOR_DLG, this);

	m_pManualPickerDlg = new CManual_Good_Ng_PickerDlg(this);
	m_pManualPickerDlg->Create(IDD_MANUAL_GOOD_NG_PICKER_DLG, this);

	m_pManualUnloadDlg = new CManual_UnloadingDlg(this);
	m_pManualUnloadDlg->Create(IDD_MANUAL_UNLOAD_DLG, this);

	m_pManualLoadPickerDlg = new CManual_LoadPickerDlg(this);
	m_pManualLoadPickerDlg->Create(IDD_MANUAL_LOADPICKER_DLG, this);

	m_pManualPicker3Dlg = new CManual_Unload_PickerDlg(this);
	m_pManualPicker3Dlg->Create(IDD_MANUAL_UNLOAD_PICKER_DLG, this);	

	m_pManualLoadingDlg = new CManual_LoadingDlg(this);
	m_pManualLoadingDlg->Create(IDD_MANUAL_LOADING_DLG, this);

	m_pManualRepeatRunDlg = new CManual_RepeatRunDlg(this);
	m_pManualRepeatRunDlg->Create(IDD_MANUAL_REPEAT_RUN_DLG, this);

	// Inspector Dlg Visible
	m_rdoManualInspector.SetCheck(TRUE);
	m_rdoManualInspector.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);



	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CManualDlg::OnDestroy() 
{
	CDialogEx::OnDestroy();

	m_pManualUnloadDlg->DestroyWindow();
	m_pManualPickerDlg->DestroyWindow();
	m_pManualInspectorDlg->DestroyWindow();	
	m_pManualLoadingDlg->DestroyWindow();
	m_pManualLoadPickerDlg->DestroyWindow();
	m_pManualPicker3Dlg->DestroyWindow();
	m_pManualRepeatRunDlg->DestroyWindow();

	if (m_pManualUnloadDlg) delete m_pManualUnloadDlg;
	if (m_pManualPickerDlg) delete m_pManualPickerDlg;
	if (m_pManualInspectorDlg) delete m_pManualInspectorDlg;
	if (m_pManualLoadPickerDlg) delete m_pManualLoadPickerDlg;
	if (m_pManualPicker3Dlg) delete m_pManualPicker3Dlg;
	if (m_pManualRepeatRunDlg) delete m_pManualRepeatRunDlg;

	m_pManualUnloadDlg = NULL;
	m_pManualPickerDlg = NULL;
	m_pManualInspectorDlg = NULL;	
	m_pManualLoadPickerDlg = NULL;
	m_pManualPicker3Dlg = NULL;	
	m_pManualLoadingDlg = NULL;
	m_pManualRepeatRunDlg = NULL;
}

BOOL CManualDlg::PreTranslateMessage(MSG* pMsg) 
{
	if ((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE))
		return TRUE;

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CManualDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	if (bShow) {
		if (m_rdoManualFlow.GetCheck()) m_pManualLoadingDlg->ShowWindow(SW_SHOW);

		//if (m_rdoManualElevator.GetCheck()) m_pManualElevatorDlg->ShowWindow(SW_SHOW);
		if (m_rdoManualElevator.GetCheck()) m_pManualLoadPickerDlg->ShowWindow(SW_SHOW);
		if (m_rdoManualElevator2.GetCheck()) m_pManualPicker3Dlg->ShowWindow(SW_SHOW);
		if (m_rdoManualGripper.GetCheck()) m_pManualInspectorDlg->ShowWindow(SW_SHOW);
		if (m_rdoManualPicker.GetCheck()) m_pManualPickerDlg->ShowWindow(SW_SHOW);
		if (m_rdoManualInspector.GetCheck()) m_pManualUnloadDlg->ShowWindow(SW_SHOW);
		if (m_rdoManualRepeatRun.GetCheck()) m_pManualRepeatRunDlg->ShowWindow(SW_SHOW);
		

//		m_rdoManualDoorLock.SetCheck(TRUE);
//		m_rdoManualDoorUnlock.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
//		m_rdoManualDoorLock.Set_Color(RGB(0x00, 0x00, 0xFF), COLOR_DEFAULT);

		SetTimer(0, 100, NULL);

	} else {
		KillTimer(0);

//		m_rdoManualDoorUnlock.SetCheck(TRUE);
//		m_rdoManualDoorLock.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
//		m_rdoManualDoorUnlock.Set_Color(RGB(0x00, 0x00, 0xFF), COLOR_DEFAULT);

		if (m_rdoManualFlow.GetCheck()) m_pManualLoadingDlg->ShowWindow(SW_HIDE);
		//if (m_rdoManualElevator.GetCheck()) m_pManualElevatorDlg->ShowWindow(SW_HIDE);
		//if (m_rdoManualGripper.GetCheck()) m_pManualGripperDlg->ShowWindow(SW_HIDE);
		if (m_rdoManualElevator.GetCheck()) m_pManualLoadPickerDlg->ShowWindow(SW_HIDE);
		if (m_rdoManualElevator2.GetCheck()) m_pManualPicker3Dlg->ShowWindow(SW_HIDE);
		if (m_rdoManualGripper.GetCheck()) m_pManualInspectorDlg->ShowWindow(SW_HIDE);
		if (m_rdoManualPicker.GetCheck()) m_pManualPickerDlg->ShowWindow(SW_HIDE);
		if (m_rdoManualInspector.GetCheck()) m_pManualUnloadDlg->ShowWindow(SW_HIDE);
		if (m_rdoManualRepeatRun.GetCheck()) m_pManualRepeatRunDlg->ShowWindow(SW_HIDE);
		
	}
}

void CManualDlg::OnTimer(UINT nIDEvent) 
{
	KillTimer(0);

	CCommon *pCommon = CCommon::Get_Instance();
	if (!gData.m_bErrorShow) {
		pCommon->Check_MainEmgAir();	// Emg & Main Air
	}

	if (m_pManualInspectorDlg->IsWindowVisible()) {
		m_pManualInspectorDlg->Display_Status();
	} else if (m_pManualPickerDlg->IsWindowVisible()) {
		m_pManualPickerDlg->Display_Status();
	} else if (m_pManualLoadPickerDlg->IsWindowVisible()) {
		m_pManualLoadPickerDlg->Display_Status();
	} else if (m_pManualPicker3Dlg->IsWindowVisible()) {
		m_pManualPicker3Dlg->Display_Status();
	} else if (m_pManualUnloadDlg->IsWindowVisible()) {
		m_pManualUnloadDlg->Display_Status();
	} else if (m_pManualLoadingDlg->IsWindowVisible()) {
		m_pManualLoadingDlg->Display_Status();
	}
	else if (m_pManualRepeatRunDlg->IsWindowVisible()) {
		//m_pManualRepeatRunDlg->Display_Status();
	}

	SetTimer(0, 100, NULL);
	CDialogEx::OnTimer(nIDEvent);
}

void CManualDlg::OnBnClickedRdoManualFlow()
{
	if (m_pManualLoadingDlg->IsWindowVisible()) return;
	Hide_Windows();
	CLogFile *pLogFile = CLogFile::Get_Instance();
	pLogFile->Save_HandlerLog("[Manual - Flow] Start");
	m_rdoManualFlow.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);
	m_pManualLoadingDlg->ShowWindow(SW_SHOW);
}

void CManualDlg::OnBnClickedRdoManualElevator()
{
	if (m_pManualLoadPickerDlg->IsWindowVisible()) return;
	Hide_Windows();
	CLogFile *pLogFile = CLogFile::Get_Instance();
	pLogFile->Save_HandlerLog("[Manual - Picker2] Start");
	m_rdoManualElevator.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);
	m_pManualLoadPickerDlg->ShowWindow(SW_SHOW);
/*
	if (m_pManualElevatorDlg->IsWindowVisible()) return;
	Hide_Windows();
	CLogFile *pLogFile = CLogFile::Get_Instance();
	pLogFile->Save_HandlerLog("[Manual - Elevator] Start");
	m_rdoManualElevator.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);
	m_pManualElevatorDlg->ShowWindow(SW_SHOW);
*/
}

void CManualDlg::OnBnClickedRdoManualGripper()
{
	if (m_pManualInspectorDlg->IsWindowVisible()) return;
	Hide_Windows();
	CLogFile *pLogFile = CLogFile::Get_Instance();
	pLogFile->Save_HandlerLog("[Manual - Elevator] Start");
	m_rdoManualGripper.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);
	m_pManualInspectorDlg->ShowWindow(SW_SHOW);
/*
	//if (m_pManualGripperDlg->IsWindowVisible()) return;
	//Hide_Windows();
	//CLogFile *pLogFile = CLogFile::Get_Instance();
	//pLogFile->Save_HandlerLog("[Manual - Gripper] Start");
	//m_rdoManualGripper.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);
	//m_pManualGripperDlg->ShowWindow(SW_SHOW);

	if (m_pManualPicker2Dlg->IsWindowVisible()) return;
	Hide_Windows();
	CLogFile *pLogFile = CLogFile::Get_Instance();
	pLogFile->Save_HandlerLog("[Manual - Picker2] Start");
	m_rdoManualPicker2.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);
	m_pManualPicker2Dlg->ShowWindow(SW_SHOW);
*/
}

void CManualDlg::OnBnClickedRdoManualPicker()
{
	if (m_pManualPickerDlg->IsWindowVisible()) return;
	Hide_Windows();
	CLogFile *pLogFile = CLogFile::Get_Instance();
	pLogFile->Save_HandlerLog("[Manual - Picker] Start");
	m_rdoManualPicker.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);
	m_pManualPickerDlg->ShowWindow(SW_SHOW);
}

void CManualDlg::OnBnClickedRdoManualInspector()
{
	if (m_pManualUnloadDlg->IsWindowVisible()) return;
	Hide_Windows();
	CLogFile *pLogFile = CLogFile::Get_Instance();
	pLogFile->Save_HandlerLog("[Manual - Inspector] Start");
	m_rdoManualInspector.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);
	m_pManualUnloadDlg->ShowWindow(SW_SHOW);
}




void CManualDlg::OnBnClickedRdoManualElevator2()
{
	if (m_pManualPicker3Dlg->IsWindowVisible()) return;
	Hide_Windows();
	CLogFile *pLogFile = CLogFile::Get_Instance();
	pLogFile->Save_HandlerLog("[Manual - Picker3] Start");
	m_rdoManualElevator2.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);
	m_pManualPicker3Dlg->ShowWindow(SW_SHOW);

/*
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_pManualElevator2Dlg->IsWindowVisible()) return;
	Hide_Windows();
	CLogFile *pLogFile = CLogFile::Get_Instance();
	pLogFile->Save_HandlerLog("[Manual - Elevator2] Start");
	m_rdoManualElevator2.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);
	m_pManualElevator2Dlg->ShowWindow(SW_SHOW);
*/
}

void CManualDlg::OnBnClickedRdoManualDoorLock()
{
/*
	if (m_rdoManualDoorLock.GetCheck()) {
		CLogFile *pLogFile = CLogFile::Get_Instance();
		pLogFile->Save_HandlerLog("[Manual] Door Lock button push");
//		CCommon *pCommon = CCommon::Get_Instance();
//		pCommon->Locking_MainDoor(TRUE);
		m_rdoManualDoorUnlock.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
		m_rdoManualDoorLock.Set_Color(RGB(0x00, 0x00, 0xFF), COLOR_DEFAULT);
	}
*/
}

void CManualDlg::OnBnClickedRdoManualDoorUnlock()
{
/*
	if (m_rdoManualDoorUnlock.GetCheck()) {
		CLogFile *pLogFile = CLogFile::Get_Instance();
		pLogFile->Save_HandlerLog("[Manual] Door Unlock button push");
		m_rdoManualDoorLock.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
		m_rdoManualDoorUnlock.Set_Color(RGB(0x00, 0x00, 0xFF), COLOR_DEFAULT);
//		CCommon *pCommon = CCommon::Get_Instance();
//		pCommon->Locking_MainDoor(FALSE);
	}
*/
}

///////////////////////////////////////////////////////////////////////////////
// User Functions

void CManualDlg::Initial_Controls() 
{
	m_picManualBack.Init_Ctrl(RGB(0x00, 0x00, 0x00), RGB(0xE0, 0xFF, 0xE0));
	m_rdoManualFlow.Init_Ctrl("바탕", 12, TRUE, RGB(0x00, 0x00, 0x00), COLOR_DEFAULT, 0, 0);
	m_rdoManualElevator.Init_Ctrl("바탕", 12, TRUE, RGB(0x00, 0x00, 0x00), COLOR_DEFAULT, 0, 0);
	m_rdoManualGripper.Init_Ctrl("바탕", 12, TRUE, RGB(0x00, 0x00, 0x00), COLOR_DEFAULT, 0, 0);
	m_rdoManualPicker.Init_Ctrl("바탕", 12, TRUE, RGB(0x00, 0x00, 0x00), COLOR_DEFAULT, 0, 0);
	m_rdoManualInspector.Init_Ctrl("바탕", 12, TRUE, RGB(0x00, 0x00, 0x00), COLOR_DEFAULT, 0, 0);
	m_rdoManualRepeatRun.Init_Ctrl("바탕", 12, TRUE, RGB(0x00, 0x00, 0x00), COLOR_DEFAULT, 0, 0);
	//	m_rdoManualDoorLock.Init_Ctrl("바탕", 12, TRUE, RGB(0x00, 0x00, 0x00), COLOR_DEFAULT, 0, 0);
//	m_rdoManualDoorUnlock.Init_Ctrl("바탕", 12, TRUE, RGB(0x00, 0x00, 0x00), COLOR_DEFAULT, 0, 0);

	m_rdoManualElevator2.Init_Ctrl("바탕", 12, TRUE, RGB(0x00, 0x00, 0x00), COLOR_DEFAULT, 0, 0);	
	
}

void CManualDlg::Hide_Windows()
{	
	m_pManualInspectorDlg->ShowWindow(SW_HIDE);
	m_pManualPickerDlg->ShowWindow(SW_HIDE);
	m_pManualLoadPickerDlg->ShowWindow(SW_HIDE);
	m_pManualPicker3Dlg->ShowWindow(SW_HIDE);
	m_pManualUnloadDlg->ShowWindow(SW_HIDE);	
	m_pManualLoadingDlg->ShowWindow(SW_HIDE);
	m_pManualRepeatRunDlg->ShowWindow(SW_HIDE);

	m_rdoManualFlow.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
	m_rdoManualElevator.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
	m_rdoManualGripper.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
	m_rdoManualPicker.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
	m_rdoManualElevator2.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);	
	m_rdoManualInspector.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
	m_rdoManualRepeatRun.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
}

void CManualDlg::MainDoor_Lock()
{
//	CLogFile *pLogFile = CLogFile::Get_Instance();
//	pLogFile->Save_HandlerLog("[Manual] Door Lock cmd exec");
//	m_rdoManualDoorLock.SetCheck(TRUE);
//	m_rdoManualDoorUnlock.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
//	m_rdoManualDoorLock.Set_Color(RGB(0x00, 0x00, 0xFF), COLOR_DEFAULT);
}

void CManualDlg::MainDoor_Unlock()
{
//	CLogFile *pLogFile = CLogFile::Get_Instance();
//	pLogFile->Save_HandlerLog("[Manual] Door Unlock cmd exec");
//	m_rdoManualDoorUnlock.SetCheck(TRUE);
//	m_rdoManualDoorLock.Set_Color(RGB(0x00, 0x00, 0x00), COLOR_DEFAULT);
//	m_rdoManualDoorUnlock.Set_Color(RGB(0x00, 0x00, 0xFF), COLOR_DEFAULT);
}

///////////////////////////////////////////////////////////////////////////////


void CManualDlg::OnBnClickedRdoManualRepeat()
{
	if (m_pManualRepeatRunDlg->IsWindowVisible()) return;
	Hide_Windows();
	CLogFile *pLogFile = CLogFile::Get_Instance();
	pLogFile->Save_HandlerLog("[Manual - Repeat Run] Start");
	m_rdoManualRepeatRun.Set_Color(RGB(0xFF, 0x00, 0x00), COLOR_DEFAULT);
	m_pManualRepeatRunDlg->ShowWindow(SW_SHOW);
}
