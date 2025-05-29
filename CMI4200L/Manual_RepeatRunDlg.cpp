// Manual_RepeatRunDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CMI4200L.h"
#include "Manual_RepeatRunDlg.h"
#include "afxdialogex.h"

#include "ManualDlg.h"
#include "CMI4200LDlg.h"

// CManual_RepeatRunDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CManual_RepeatRunDlg, CDialogEx)

CManual_RepeatRunDlg::CManual_RepeatRunDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManual_RepeatRunDlg::IDD, pParent)
{

}

CManual_RepeatRunDlg::~CManual_RepeatRunDlg()
{
}

void CManual_RepeatRunDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_GROUP_0, m_Group[0]);
	for(int i = 0; i < 3; i++) DDX_Control(pDX, IDC_LABEL_0 + i, m_Label[i]);
	DDX_Control(pDX, IDC_CBO_PICKER, m_cboPicker);
	DDX_Control(pDX, IDC_CBO_PICK_NUM, m_cboPickNum);
	DDX_Control(pDX, IDC_EDT_DELAY, m_edtDelay);
	DDX_Control(pDX, IDC_CHK_REPEAT_RUN, m_chkRepeatRun);
	DDX_Control(pDX, IDC_EDT_MSG, m_edtMsg);
}


BEGIN_MESSAGE_MAP(CManual_RepeatRunDlg, CDialogEx)
	ON_WM_SHOWWINDOW()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_CHK_REPEAT_RUN, &CManual_RepeatRunDlg::OnBnClickedChkRepeatRun)
	ON_CBN_SELCHANGE(IDC_CBO_PICKER, &CManual_RepeatRunDlg::OnCbnSelchangeCboPicker)
	ON_CBN_SELCHANGE(IDC_CBO_PICK_NUM, &CManual_RepeatRunDlg::OnCbnSelchangeCboPickNum)
END_MESSAGE_MAP()


// CManual_RepeatRunDlg 메시지 처리기입니다.


BOOL CManual_RepeatRunDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	pLogFile = CLogFile::Get_Instance();
	pCommon = CCommon::Get_Instance();
	pAJinAXL = CAJinAXL::Get_Instance();

	SetWindowPos(this, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	Initial_Controls();

	m_cboPicker.AddString("Load Picker (Tray)");
	m_cboPicker.AddString("Load Picker (Index)");
	m_cboPicker.AddString("NG Picker (Index)");
	m_cboPicker.AddString("NG Picker (Tray)");
	m_cboPicker.AddString("Good Picker (Index)");
	m_cboPicker.AddString("Unload Picker (Index)");
	m_cboPicker.AddString("Unload Picker (Tray)");
	
	m_nPickerSelected = 0;
	m_nPickerNumSelected = 0;

	return TRUE;  
}


BOOL CManual_RepeatRunDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE))
		return TRUE;

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CManual_RepeatRunDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	if (!bShow) return;

	CString strMsg;
	strMsg = "1. 각 Picker Z Ready Up 시작할것 (아닐시 정지)\r\n";
	strMsg += "2. 정지시 (Repeat Stop) 후 해당 부분 센서 점검필요 \r\n";
	m_edtMsg.SetWindowText(strMsg);

	//Display_Status();

	m_strLog.Format("[Manual Repeat] Show Window");

	
	pLogFile->Save_HandlerLog(m_strLog);
}


void CManual_RepeatRunDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CManual_RepeatRunDlg::Initial_Controls()
{
	m_Group[0].Init_Ctrl("Arial", 11, TRUE, COLOR_DEFAULT, COLOR_DEFAULT);
	for (int i = 0; i < 3; i++) m_Label[i].Init_Ctrl("Arial", 10, FALSE, COLOR_DEFAULT, COLOR_DEFAULT);
	m_cboPicker.Init_Ctrl("Arial", 10, FALSE, COLOR_DEFAULT, COLOR_DEFAULT);
	m_cboPickNum.Init_Ctrl("Arial", 10, FALSE, COLOR_DEFAULT, COLOR_DEFAULT);
	m_edtDelay.Init_Ctrl("Arial", 10, FALSE, COLOR_DEFAULT, COLOR_DEFAULT);
	m_edtMsg.Init_Ctrl("Arial", 11, TRUE, COLOR_DEFAULT, COLOR_DEFAULT);
	m_chkRepeatRun.Init_Ctrl("Arial", 10, TRUE, COLOR_DEFAULT, COLOR_DEFAULT, 0, 0);
}



void CManual_RepeatRunDlg::OnBnClickedChkRepeatRun()
{
	CString strText, strTemp;

	CCMI4200LDlg *pMainDlg = (CCMI4200LDlg*)AfxGetApp()->GetMainWnd();

	m_cboPicker.EnableWindow(!m_chkRepeatRun.GetCheck());
	m_cboPickNum.EnableWindow(!m_chkRepeatRun.GetCheck());
	m_edtDelay.EnableWindow(!m_chkRepeatRun.GetCheck());

	pMainDlg->Enable_ModeButton(!m_chkRepeatRun.GetCheck());
	pMainDlg->m_btnMainOperator.EnableWindow(!m_chkRepeatRun.GetCheck());

	g_dlgManual.m_rdoManualFlow.EnableWindow(!m_chkRepeatRun.GetCheck());
	g_dlgManual.m_rdoManualElevator.EnableWindow(!m_chkRepeatRun.GetCheck());
	g_dlgManual.m_rdoManualGripper.EnableWindow(!m_chkRepeatRun.GetCheck());
	g_dlgManual.m_rdoManualPicker.EnableWindow(!m_chkRepeatRun.GetCheck());
	g_dlgManual.m_rdoManualInspector.EnableWindow(!m_chkRepeatRun.GetCheck());
	
	int nMotionNo = pCommon->Check_MotionPos();//Motion Axis shift 
	if (nMotionNo < 99) 
	{
		double dCurrentPos = pAJinAXL->Get_pStatus(nMotionNo)->dPos;		
		strTemp.Format("Motion(%d Axis) 위치를 Check 하세요.\n이전위치(%0.3lf) != 현재위치(%0.3lf)", nMotionNo + 8, gAlm.dMotionPos[nMotionNo], dCurrentPos);
		pLogFile->Save_HandlerLog(strTemp);

		pCommon->Show_MsgBox(1, strTemp);			
		return;
	}
		
	if (m_chkRepeatRun.GetCheck()) {

		m_nPickerSelect = m_cboPicker.GetCurSel();
		m_nPickerNum = m_cboPickNum.GetCurSel();
		m_edtDelay.GetWindowText(strText);
		m_nActionDelay = atoi(strText);

		m_bThreadAction = TRUE;
		m_pThreadAction = AfxBeginThread(Thread_ActionRun, this);
	} else {
		if (!m_pThreadAction) return;
		m_bThreadAction = FALSE;
		WaitForSingleObject(m_pThreadAction->m_hThread, INFINITE);
	}
}


UINT CManual_RepeatRunDlg::Thread_ActionRun(LPVOID lpVoid)
{
	CManual_RepeatRunDlg* pOwner = (CManual_RepeatRunDlg*)lpVoid;

	while (pOwner->m_bThreadAction) {
		pOwner->Repeat_Action();
	} 
	pOwner->m_bThreadAction = FALSE;
	pOwner->m_pThreadAction = NULL;

	return 0;
}


void CManual_RepeatRunDlg::Repeat_Action()
{

	switch(m_nRepeatCase)
	{
	case 0:
		break;

	}

}

void CManual_RepeatRunDlg::OnCbnSelchangeCboPicker()
{
	m_cboPickNum.ResetContent();

	
}


void CManual_RepeatRunDlg::OnCbnSelchangeCboPickNum()
{
	m_nPickerNumSelected = m_cboPickNum.GetCurSel() + 1;
}
