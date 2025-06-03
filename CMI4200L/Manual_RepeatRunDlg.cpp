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
	DDX_Control(pDX, IDC_LBL_CASE, m_lblCase);
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

	SetWindowPos(this, 150, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	Initial_Controls();

	AddComboListPicker();
	
	m_nPickerSelected = 0;
	m_nPickerNumSelected = 0;

	m_edtDelay.SetWindowText("1000");

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
			
	if (m_chkRepeatRun.GetCheck()) {

		//int nMotionNo = pCommon->Check_MotionPos();//Motion Axis shift 
		//if (nMotionNo < 99) 
		//{
		//	double dCurrentPos = pAJinAXL->Get_pStatus(nMotionNo)->dPos;		
		//	strTemp.Format("Motion(%d Axis) 위치를 Check 하세요.\n이전위치(%0.3lf) != 현재위치(%0.3lf)", nMotionNo + 8, gAlm.dMotionPos[nMotionNo], dCurrentPos);
		//	pLogFile->Save_HandlerLog(strTemp);

		//	pCommon->Show_MsgBox(1, strTemp);		
		//	return;
		//}
		m_nPickerSelect = m_cboPicker.GetCurSel();
		m_nPickerNum = m_cboPickNum.GetCurSel();
		m_edtDelay.GetWindowText(strText);
		m_nActionDelay = atoi(strText);

		m_bThreadAction = TRUE;
		m_pThreadAction = AfxBeginThread(Thread_ActionRun, this);
	} else {
		m_cboPicker.ResetContent();
		AddComboListPicker();

		m_nRepeatCase = 0;
		m_strTemp.Format("%d", m_nRepeatCase);
		m_lblCase.SetWindowText(m_strTemp);
		
		if (!m_pThreadAction) return;
		
		m_bThreadAction = FALSE;
		WaitForSingleObject(m_pThreadAction->m_hThread, INFINITE);

		

		
	}
}

void CManual_RepeatRunDlg::AddComboListPicker()
{
	m_cboPicker.AddString("Load Picker (Tray)");
		m_cboPicker.AddString("Load Picker (Index)");
		/*m_cboPicker.AddString("NG Picker (Index)");
		m_cboPicker.AddString("NG Picker (Tray)");
		m_cboPicker.AddString("Good Picker (Index)");*/
		m_cboPicker.AddString("Unload Picker (Index)");
		m_cboPicker.AddString("Unload Picker (Tray)");

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
	//index Align Out 이어야 함 - interlock 
	
	m_strTemp.Format("%d", m_nRepeatCase);
	m_lblCase.SetWindowText(m_strTemp);

	if(m_nRepeatCase / 100 == 1)
	{
		if(!pCommon->Get_IndexAlignOut(1)) 
		{
			m_bThreadAction = FALSE;
			m_pThreadAction = NULL;
			AfxMessageBox("Index Load 부분 Align Out 아닙니다");
			return;
		}
	}

	if(m_nRepeatCase / 100 == 3)
	{
		if(!pCommon->Get_IndexAlignOut(4)) 
		{
			m_bThreadAction = FALSE;
			m_pThreadAction = NULL;
			AfxMessageBox("Index Unload 부분 Align Out 아닙니다");
			return;
		}
	}


	switch(m_nRepeatCase)
	{
	case 0:
		break;
		
	//"Load Picker (Tray)"
	case 100:
		if(!pCommon->Check_Position(AX_LOAD_PICKER_Y1, 0)
			&& !pCommon->Check_Position(AX_LOAD_PICKER_Y1, 1))
		{
			m_bThreadAction = FALSE;
			m_pThreadAction = NULL;
			AfxMessageBox("Load Picker (Tray) Position 아닙니다.");
			return;
		}

		if(pCommon->Check_Position(AX_LOAD_PICKER_Z, 0))
		{
			pCommon->Move_Position(AX_LOAD_PICKER_Z, 1); // tray down 
			m_nRepeatCase = 110;
		}
		break;
	case 110:
		if(pCommon->Check_Position(AX_LOAD_PICKER_Z, 1))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Set_LoadPickerClose(m_nPickerNumSelected); //Close 
			m_nRepeatCase = 120;
		}
		break;
	case 120:
		if(pCommon->Get_LoadPickerClose(m_nPickerNumSelected))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_LOAD_PICKER_Z, 0); // Ready Up 
			m_nRepeatCase = 130;
		}
		break;
	case 130:
		if(pCommon->Check_Position(AX_LOAD_PICKER_Z, 0) && pCommon->Get_LoadPickerClose(m_nPickerNumSelected) )
		{		
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_LOAD_PICKER_Z, 1); // tray down 
			m_nRepeatCase = 140;
		}
		break;
	case 140:
		if(pCommon->Check_Position(AX_LOAD_PICKER_Z, 1))
		{		
			theApp.uSleep(m_nActionDelay);
			pCommon->Set_LoadPickerOpen(m_nPickerNumSelected);//Open 
			m_nRepeatCase = 150;
		}
		break;
	case 150:
		if(pCommon->Get_LoadPickerOpen(m_nPickerNumSelected))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_LOAD_PICKER_Z, 0); // Ready Up 
			m_nRepeatCase = 100;
		}
		break;

	//Load Picker (Index)		
	case 200:
		if(!pCommon->Check_Position(AX_LOAD_PICKER_Y1, 2))
		{
			m_bThreadAction = FALSE;
			m_pThreadAction = NULL;
			AfxMessageBox("Load Picker (Index) Position 아닙니다.");
			return;
		}

		if(pCommon->Check_Position(AX_LOAD_PICKER_Z, 0))
		{
			pCommon->Move_Position(AX_LOAD_PICKER_Z, 3); // Index down 
			m_nRepeatCase = 210;
		}
		break;
	case 210:
		if(pCommon->Check_Position(AX_LOAD_PICKER_Z, 3))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Set_LoadPickerClose(m_nPickerNumSelected); //Close 
			m_nRepeatCase = 220;
		}
		break;
	case 220:
		if(pCommon->Get_LoadPickerClose(m_nPickerNumSelected))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_LOAD_PICKER_Z, 0); // Ready Up 
			m_nRepeatCase = 230;
		}
		break;
	case 230:
		if(pCommon->Check_Position(AX_LOAD_PICKER_Z, 0) && pCommon->Get_LoadPickerClose(m_nPickerNumSelected) )
		{		
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_LOAD_PICKER_Z, 3); // index down 
			m_nRepeatCase = 240;
		}
		break;
	case 240:
		if(pCommon->Check_Position(AX_LOAD_PICKER_Z, 3))
		{		
			theApp.uSleep(m_nActionDelay);
			pCommon->Set_LoadPickerOpen(m_nPickerNumSelected);//Open 
			m_nRepeatCase = 250;
		}
		break;
	case 250:
		if(pCommon->Get_LoadPickerOpen(m_nPickerNumSelected))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_LOAD_PICKER_Z, 0); // Ready Up 
			m_nRepeatCase = 200;
		}
		break;
	
	//"Unload Picker (Index)"		
	case 300:
		if(!pCommon->Check_Position(AX_UNLOAD_PICKER_X1, 0))
		{
			m_bThreadAction = FALSE;
			m_pThreadAction = NULL;
			AfxMessageBox("Unload Picker Index (Load) Position 아닙니다.");
			return;
		}

		if(pCommon->Check_Position(AX_UNLOAD_PICKER_Z, 0))
		{
			pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 1); // Index down 
			m_nRepeatCase = 310;
		}
		break;
	case 310:
		if(pCommon->Check_Position(AX_UNLOAD_PICKER_Z, 1))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Set_UnloadPickerClose(m_nPickerNumSelected); //Close 
			m_nRepeatCase = 320;
		}
		break;
	case 320:
		if(pCommon->Get_UnloadPickerClose(m_nPickerNumSelected))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 0); // Ready Up 
			m_nRepeatCase = 330;
		}
		break;
	case 330:
		if(pCommon->Check_Position(AX_UNLOAD_PICKER_Z, 0) && pCommon->Get_UnloadPickerClose(m_nPickerNumSelected) )
		{		
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 1); // index down 
			m_nRepeatCase = 340;
		}
		break;
	case 340:
		if(pCommon->Check_Position(AX_UNLOAD_PICKER_Z, 1))
		{		
			theApp.uSleep(m_nActionDelay);
			pCommon->Set_UnloadPickerOpen(m_nPickerNumSelected);//Open 
			m_nRepeatCase = 350;
		}
		break;
	case 350:
		if(pCommon->Get_UnloadPickerOpen(m_nPickerNumSelected))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 0); // Ready Up 
			m_nRepeatCase = 300;
		}
		break;

	//"Unload Picker (Tray)"
	case 400:
		if(!pCommon->Check_Position(AX_UNLOAD_PICKER_X1, 1) 
			&& !pCommon->Check_Position(AX_UNLOAD_PICKER_X1, 2))
		{
			m_bThreadAction = FALSE;
			m_pThreadAction = NULL;
			AfxMessageBox("Unload Picker Tray (Unload) Position 아닙니다.");
			return;
		}
		if(pCommon->Check_Position(AX_UNLOAD_PICKER_Z, 0))
		{
			pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 2); // Tray down 
			m_nRepeatCase = 410;
		}
		break;
	case 410:
		if(pCommon->Check_Position(AX_UNLOAD_PICKER_Z, 2))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Set_UnloadPickerClose(m_nPickerNumSelected); //Close 
			m_nRepeatCase = 420;
		}
		break;
	case 420:
		if(pCommon->Get_UnloadPickerClose(m_nPickerNumSelected))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 0); // Ready Up 
			m_nRepeatCase = 430;
		}
		break;
	case 430:
		if(pCommon->Check_Position(AX_UNLOAD_PICKER_Z, 0) && pCommon->Get_UnloadPickerClose(m_nPickerNumSelected) )
		{		
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 2); // Tray down 
			m_nRepeatCase = 440;
		}
		break;
	case 440:
		if(pCommon->Check_Position(AX_UNLOAD_PICKER_Z, 2))
		{		
			theApp.uSleep(m_nActionDelay);
			pCommon->Set_UnloadPickerOpen(m_nPickerNumSelected);//Open 
			m_nRepeatCase = 450;
		}
		break;
	case 450:
		if(pCommon->Get_UnloadPickerOpen(m_nPickerNumSelected))
		{
			theApp.uSleep(m_nActionDelay);
			pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 0); // Ready Up 
			m_nRepeatCase = 400;
		}
		break;
	

	}

}

void CManual_RepeatRunDlg::OnCbnSelchangeCboPicker()
{
	m_cboPickNum.ResetContent();
	int PickerCnt = 0;

#ifdef PICKER_3
	PickerCnt = 3;
#endif	

	if(m_cboPicker.GetCurSel() == 0) // Load picker - Tray 
	{
		m_nRepeatCase = 100;
		for(int i = 1; i < PickerCnt+1 ; i++)
		{	
			m_strLog.Format("Load CM No.: %d", i);
			m_cboPickNum.AddString(m_strLog);
		}
		
	}
	else if(m_cboPicker.GetCurSel() == 1) // Load Picker - Index 
	{
		m_nRepeatCase = 200;
		for(int i = 1; i < PickerCnt+1 ; i++)
		{	
			m_strLog.Format("Load CM No.: %d", i);
			m_cboPickNum.AddString(m_strLog);
		}
		
	}
	else if(m_cboPicker.GetCurSel() == 2) //Unload Picker - Index 
	{
		m_nRepeatCase = 300;
		for(int i = 1; i < PickerCnt+1 ; i++)
		{	
			m_strLog.Format("Unload CM No.: %d", i);
			m_cboPickNum.AddString(m_strLog);
		}

	}
	else if(m_cboPicker.GetCurSel() == 3) //Unload Picker - Tray 
	{
		m_nRepeatCase = 400;
		for(int i = 1; i < PickerCnt+1 ; i++)
		{	
			m_strLog.Format("Unload CM No.: %d", i);
			m_cboPickNum.AddString(m_strLog);
		}

	}

	
}


void CManual_RepeatRunDlg::OnCbnSelchangeCboPickNum()
{
	m_nPickerNumSelected = m_cboPickNum.GetCurSel() + 1;
}



