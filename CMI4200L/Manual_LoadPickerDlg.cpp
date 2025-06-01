// Manual_LoadPickerDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CMI4200L.h"
#include "Manual_LoadPickerDlg.h"
#include "afxdialogex.h"

#include "AJinAXL.h"
#include "DataManager.h"
#include "Common.h"
#include "LogFile.h"
#include "ManualDlg.h"
#include "Math.h"


// CManualPicker2Dlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CManual_LoadPickerDlg, CDialogEx)

CManual_LoadPickerDlg::CManual_LoadPickerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManual_LoadPickerDlg::IDD, pParent)
{

}

CManual_LoadPickerDlg::~CManual_LoadPickerDlg()
{
}

void CManual_LoadPickerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STC_AXIS_POS_0, m_stcAxisPos[0]);
	DDX_Control(pDX, IDC_STC_AXIS_POS_1, m_stcAxisPos[1]);
	DDX_Control(pDX, IDC_STC_AXIS_POS_2, m_stcAxisPos[2]);
	DDX_Control(pDX, IDC_STC_AXIS_POS_3, m_stcAxisPos[3]);
	DDX_Control(pDX, IDC_STC_AXIS_POS_4, m_stcAxisPos[4]);
	DDX_Control(pDX, IDC_STC_AXIS_POS_5, m_stcAxisPos[5]);

	DDX_Control(pDX, IDC_BTN_ML_PICKER_Y1_0, m_btnMLPickY1[0]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Y1_1, m_btnMLPickY1[1]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Y1_2, m_btnMLPickY1[2]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Y1_3, m_btnMLPickY1[3]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Y1_4, m_btnMLPickY1[4]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Y1_5, m_btnMLPickY1[5]);

	DDX_Control(pDX, IDC_BTN_ML_PICKER_Y2_0, m_btnMLPickY2[0]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Y2_1, m_btnMLPickY2[1]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Y2_2, m_btnMLPickY2[2]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Y2_3, m_btnMLPickY2[3]);

	DDX_Control(pDX, IDC_BTN_ML_PICKER_Z_0, m_btnMLPickZ[0]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Z_1, m_btnMLPickZ[1]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Z_2, m_btnMLPickZ[2]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Z_3, m_btnMLPickZ[3]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Z_4, m_btnMLPickZ[4]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Z_5, m_btnMLPickZ[5]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_Z_6, m_btnMLPickZ[6]);

	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_0, m_btnMLPickIO[0]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_1, m_btnMLPickIO[1]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_2, m_btnMLPickIO[2]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_3, m_btnMLPickIO[3]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_4, m_btnMLPickIO[4]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_5, m_btnMLPickIO[5]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_6, m_btnMLPickIO[6]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_7, m_btnMLPickIO[7]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_8, m_btnMLPickIO[8]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_9, m_btnMLPickIO[9]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_10, m_btnMLPickIO[10]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_11, m_btnMLPickIO[11]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_12, m_btnMLPickIO[12]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_13, m_btnMLPickIO[13]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_14, m_btnMLPickIO[14]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_15, m_btnMLPickIO[15]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_16, m_btnMLPickIO[16]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_17, m_btnMLPickIO[17]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_18, m_btnMLPickIO[18]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_19, m_btnMLPickIO[19]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_20, m_btnMLPickIO[20]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_21, m_btnMLPickIO[21]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_22, m_btnMLPickIO[22]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_23, m_btnMLPickIO[23]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_24, m_btnMLPickIO[24]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_25, m_btnMLPickIO[25]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_26, m_btnMLPickIO[26]);
	DDX_Control(pDX, IDC_BTN_ML_PICKER_IO_27, m_btnMLPickIO[27]);

	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_0, m_ledMLPickIO[0]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_1, m_ledMLPickIO[1]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_2, m_ledMLPickIO[2]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_3, m_ledMLPickIO[3]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_4, m_ledMLPickIO[4]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_5, m_ledMLPickIO[5]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_6, m_ledMLPickIO[6]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_7, m_ledMLPickIO[7]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_8, m_ledMLPickIO[8]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_9, m_ledMLPickIO[9]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_10, m_ledMLPickIO[10]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_11, m_ledMLPickIO[11]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_12, m_ledMLPickIO[12]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_13, m_ledMLPickIO[13]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_14, m_ledMLPickIO[14]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_15, m_ledMLPickIO[15]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_16, m_ledMLPickIO[16]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_17, m_ledMLPickIO[17]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_18, m_ledMLPickIO[18]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_19, m_ledMLPickIO[19]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_20, m_ledMLPickIO[20]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_21, m_ledMLPickIO[21]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_22, m_ledMLPickIO[22]);
	DDX_Control(pDX, IDC_LED_ML_PICKER_IO_23, m_ledMLPickIO[23]);

	DDX_Control(pDX, IDC_STC_MOVE_0, m_stcPickerMove[0]);
	DDX_Control(pDX, IDC_STC_MOVE_1, m_stcPickerMove[1]);
	DDX_Control(pDX, IDC_STC_MOVE_2, m_stcPickerMove[2]);
	DDX_Control(pDX, IDC_STC_MOVE_3, m_stcPickerMove[3]);

	DDX_Control(pDX, IDC_BTN_NG_PICKER_MOVE, m_btnNGPickMove);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_MOVE2, m_btnNGPickMoveZ);
}

BEGIN_MESSAGE_MAP(CManual_LoadPickerDlg, CDialogEx)
	ON_WM_DESTROY()
	ON_WM_SHOWWINDOW()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Y1_0, IDC_BTN_ML_PICKER_Y1_0, OnBtnMLNGPickY1Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Y1_1, IDC_BTN_ML_PICKER_Y1_1, OnBtnMLNGPickY1Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Y1_2, IDC_BTN_ML_PICKER_Y1_2, OnBtnMLNGPickY1Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Y1_3, IDC_BTN_ML_PICKER_Y1_3, OnBtnMLNGPickY1Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Y1_4, IDC_BTN_ML_PICKER_Y1_4, OnBtnMLNGPickY1Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Y1_5, IDC_BTN_ML_PICKER_Y1_5, OnBtnMLNGPickY1Click)

	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Y2_0, IDC_BTN_ML_PICKER_Y2_0, OnBtnMLNGPickY2Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Y2_1, IDC_BTN_ML_PICKER_Y2_1, OnBtnMLNGPickY2Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Y2_2, IDC_BTN_ML_PICKER_Y2_2, OnBtnMLNGPickY2Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Y2_3, IDC_BTN_ML_PICKER_Y2_3, OnBtnMLNGPickY2Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Z_0, IDC_BTN_ML_PICKER_Z_0, OnBtnMLNGPickZClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Z_1, IDC_BTN_ML_PICKER_Z_1, OnBtnMLNGPickZClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Z_2, IDC_BTN_ML_PICKER_Z_2, OnBtnMLNGPickZClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Z_3, IDC_BTN_ML_PICKER_Z_3, OnBtnMLNGPickZClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Z_4, IDC_BTN_ML_PICKER_Z_4, OnBtnMLNGPickZClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Z_5, IDC_BTN_ML_PICKER_Z_5, OnBtnMLNGPickZClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_Z_6, IDC_BTN_ML_PICKER_Z_6, OnBtnMLNGPickZClick)

	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_0, IDC_BTN_ML_PICKER_IO_0, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_1, IDC_BTN_ML_PICKER_IO_1, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_2, IDC_BTN_ML_PICKER_IO_2, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_3, IDC_BTN_ML_PICKER_IO_3, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_4, IDC_BTN_ML_PICKER_IO_4, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_5, IDC_BTN_ML_PICKER_IO_5, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_6, IDC_BTN_ML_PICKER_IO_6, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_7, IDC_BTN_ML_PICKER_IO_7, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_8, IDC_BTN_ML_PICKER_IO_8, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_9, IDC_BTN_ML_PICKER_IO_9, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_10, IDC_BTN_ML_PICKER_IO_10, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_11, IDC_BTN_ML_PICKER_IO_11, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_12, IDC_BTN_ML_PICKER_IO_12, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_13, IDC_BTN_ML_PICKER_IO_13, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_14, IDC_BTN_ML_PICKER_IO_14, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_15, IDC_BTN_ML_PICKER_IO_15, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_16, IDC_BTN_ML_PICKER_IO_16, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_17, IDC_BTN_ML_PICKER_IO_17, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_18, IDC_BTN_ML_PICKER_IO_18, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_19, IDC_BTN_ML_PICKER_IO_19, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_20, IDC_BTN_ML_PICKER_IO_20, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_21, IDC_BTN_ML_PICKER_IO_21, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_22, IDC_BTN_ML_PICKER_IO_22, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_23, IDC_BTN_ML_PICKER_IO_23, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_24, IDC_BTN_ML_PICKER_IO_24, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_25, IDC_BTN_ML_PICKER_IO_25, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_26, IDC_BTN_ML_PICKER_IO_26, OnBtnMLPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_ML_PICKER_IO_27, IDC_BTN_ML_PICKER_IO_27, OnBtnMLPickIOClick)

	ON_CONTROL_RANGE(BN_CLICKED, IDC_STC_MOVE_0, IDC_STC_MOVE_0, OnBtnNGPickMovePosClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_STC_MOVE_1, IDC_STC_MOVE_1, OnBtnNGPickMovePosClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_STC_MOVE_2, IDC_STC_MOVE_2, OnBtnNGPickMovePosClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_STC_MOVE_3, IDC_STC_MOVE_3, OnBtnNGPickMovePosClick)

	ON_BN_CLICKED(IDC_BTN_NG_PICKER_MOVE, &CManual_LoadPickerDlg::OnBtnNGPickMoveClick)
	ON_BN_CLICKED(IDC_BTN_NG_PICKER_MOVE2, &CManual_LoadPickerDlg::OnBnClickedBtnNgPickerMove2)
END_MESSAGE_MAP()


// CManualPicker2Dlg 메시지 처리기입니다.

BOOL CManual_LoadPickerDlg::OnInitDialog() 
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetWindowPos(this, 150, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	//Load Picker
	Initial_Controls();

#ifdef PICKER_3
	for (int i=6; i<12; i++) {
		m_btnMLPickIO[i].ShowWindow(FALSE);
		m_ledMLPickIO[i].ShowWindow(FALSE);
	}
	for (int i=18; i<24; i++) {
		m_btnMLPickIO[i].ShowWindow(FALSE);
		m_ledMLPickIO[i].ShowWindow(FALSE);
	}
#endif

#ifdef PICKER_5
	for (int i=10; i<12; i++) {
		m_btnMLPickIO[i].ShowWindow(FALSE);
		m_ledMLPickIO[i].ShowWindow(FALSE);
	}
	for (int i=22; i<24; i++) {
		m_btnMLPickIO[i].ShowWindow(FALSE);
		m_ledMLPickIO[i].ShowWindow(FALSE);
	}
#endif

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CManual_LoadPickerDlg::OnDestroy() 
{
	CDialogEx::OnDestroy();
}

BOOL CManual_LoadPickerDlg::PreTranslateMessage(MSG* pMsg) 
{
	if ((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE))
		return TRUE;

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CManual_LoadPickerDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialogEx::OnShowWindow(bShow, nStatus);
}

void CManual_LoadPickerDlg::Initial_Controls() 
{
	for (int i = 0; i < 6; i++) m_stcAxisPos[i].Init_Ctrl("바탕", 11, TRUE, RGB(0xFF, 0xFF, 0xFF), RGB(0x00, 0x10, 0xB0));
	for (int i = 0; i < 24; i++) m_ledMLPickIO[i].Init_Ctrl("바탕", 11, FALSE, COLOR_DEFAULT, COLOR_DEFAULT, CLedCS::emGreen, CLedCS::em16);
}

void CManual_LoadPickerDlg::Display_Status()
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_2 *pDX2 = pAJinAXL->Get_pDX2();
	DX_DATA_5 *pDX5 = pAJinAXL->Get_pDX5();

	CString strPos;
	AXIS_STATUS *pStatus = pAJinAXL->Get_pStatus(AX_LOAD_PICKER_Y1);
	strPos.Format("%0.3lf", pStatus->dPos);
	m_stcAxisPos[0].SetWindowText(strPos);

	pStatus = pAJinAXL->Get_pStatus(AX_LOAD_PICKER_Y2);
	strPos.Format("%0.3lf", pStatus->dPos);
	m_stcAxisPos[1].SetWindowText(strPos);

	pStatus = pAJinAXL->Get_pStatus(AX_LOAD_PICKER_Z);
	strPos.Format("%0.3lf", pStatus->dPos);
	m_stcAxisPos[2].SetWindowText(strPos);

	pStatus = pAJinAXL->Get_pStatus(AX_UNLOAD_PICKER_X1);
	strPos.Format("%0.3lf", pStatus->dPos);
	m_stcAxisPos[3].SetWindowText(strPos);

	pStatus = pAJinAXL->Get_pStatus(AX_UNLOAD_PICKER_X2);
	strPos.Format("%0.3lf", pStatus->dPos);
	m_stcAxisPos[4].SetWindowText(strPos);

	pStatus = pAJinAXL->Get_pStatus(AX_UNLOAD_PICKER_Z);
	strPos.Format("%0.3lf", pStatus->dPos);
	m_stcAxisPos[5].SetWindowText(strPos);


	if (pDX2->iMLPicker1Open) m_ledMLPickIO[0].Set_On(TRUE);
	else m_ledMLPickIO[0].Set_On(FALSE);
	if (pDX2->iMLPicker1CMCheck) m_ledMLPickIO[1].Set_On(TRUE);
	else m_ledMLPickIO[1].Set_On(FALSE);
	if (pDX2->iMLPicker2Open) m_ledMLPickIO[2].Set_On(TRUE);
	else m_ledMLPickIO[2].Set_On(FALSE);
	if (pDX2->iMLPicker2CMCheck) m_ledMLPickIO[3].Set_On(TRUE);
	else m_ledMLPickIO[3].Set_On(FALSE);
	if (pDX2->iMLPicker3Open) m_ledMLPickIO[4].Set_On(TRUE);
	else m_ledMLPickIO[4].Set_On(FALSE);
	if (pDX2->iMLPicker3CMCheck) m_ledMLPickIO[5].Set_On(TRUE);
	else m_ledMLPickIO[5].Set_On(FALSE);
	if (pDX2->iMLPicker4Open) m_ledMLPickIO[6].Set_On(TRUE);
	else m_ledMLPickIO[6].Set_On(FALSE);
	if (pDX2->iMLPicker4CMCheck) m_ledMLPickIO[7].Set_On(TRUE);
	else m_ledMLPickIO[7].Set_On(FALSE);
	if (pDX2->iMLPicker5Open) m_ledMLPickIO[8].Set_On(TRUE);
	else m_ledMLPickIO[8].Set_On(FALSE);
	if (pDX2->iMLPicker5CMCheck) m_ledMLPickIO[9].Set_On(TRUE);
	else m_ledMLPickIO[9].Set_On(FALSE);
	if (pDX2->iMLPicker6Open) m_ledMLPickIO[10].Set_On(TRUE);
	else m_ledMLPickIO[10].Set_On(FALSE);
	if (pDX2->iMLPicker6CMCheck) m_ledMLPickIO[11].Set_On(TRUE);
	else m_ledMLPickIO[11].Set_On(FALSE);

	if (pDX5->iMUPicker1Open) m_ledMLPickIO[12].Set_On(TRUE);
	else m_ledMLPickIO[12].Set_On(FALSE);
	if (pDX5->iMUPicker1CMCheck) m_ledMLPickIO[13].Set_On(TRUE);
	else m_ledMLPickIO[13].Set_On(FALSE);
	if (pDX5->iMUPicker2Open) m_ledMLPickIO[14].Set_On(TRUE);
	else m_ledMLPickIO[14].Set_On(FALSE);
	if (pDX5->iMUPicker2CMCheck) m_ledMLPickIO[15].Set_On(TRUE);
	else m_ledMLPickIO[15].Set_On(FALSE);
	if (pDX5->iMUPicker3Open) m_ledMLPickIO[16].Set_On(TRUE);
	else m_ledMLPickIO[16].Set_On(FALSE);
	if (pDX5->iMUPicker3CMCheck) m_ledMLPickIO[17].Set_On(TRUE);
	else m_ledMLPickIO[17].Set_On(FALSE);
	if (pDX5->iMUPicker4Open) m_ledMLPickIO[18].Set_On(TRUE);
	else m_ledMLPickIO[18].Set_On(FALSE);
	if (pDX5->iMUPicker4CMCheck) m_ledMLPickIO[19].Set_On(TRUE);
	else m_ledMLPickIO[19].Set_On(FALSE);
	if (pDX5->iMUPicker5Open) m_ledMLPickIO[20].Set_On(TRUE);
	else m_ledMLPickIO[20].Set_On(FALSE);
	if (pDX5->iMUPicker5CMCheck) m_ledMLPickIO[21].Set_On(TRUE);
	else m_ledMLPickIO[21].Set_On(FALSE);
	if (pDX5->iMUPicker6Open) m_ledMLPickIO[22].Set_On(TRUE);
	else m_ledMLPickIO[22].Set_On(FALSE);
	if (pDX5->iMUPicker6CMCheck) m_ledMLPickIO[23].Set_On(TRUE);
	else m_ledMLPickIO[23].Set_On(FALSE);

	CDataManager *pDataManager = CDataManager::Get_Instance();
	EQUIP_DATA *pEquipData = pDataManager->Get_pEquipData();
	BOOL bShow = FALSE;

	if (pEquipData->bUseManagerMode) bShow = TRUE;
	m_btnMLPickY1[0].ShowWindow(bShow);
	m_btnMLPickY1[1].ShowWindow(bShow);
	m_btnMLPickY1[4].ShowWindow(bShow);
	m_btnMLPickY2[0].ShowWindow(bShow);
	m_btnMLPickY2[1].ShowWindow(bShow);
	m_btnMLPickZ[0].ShowWindow(bShow);
	m_btnMLPickZ[1].ShowWindow(bShow);
	m_btnMLPickZ[2].ShowWindow(bShow);
}

void CManual_LoadPickerDlg::OnBtnMLNGPickY1Click(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	CCommon *pCommon = CCommon::Get_Instance();

	if (!pCommon->Check_MainDoor()) return;

	if (nID == IDC_BTN_ML_PICKER_Y1_0) {
		if (!pAJinAXL->Is_Home(AX_LOAD_PICKER_Y1)) return;
		if (!pCommon->Check_Position(AX_LOAD_PICKER_Z, 0)) {
			AfxMessageBox(_T("Load Picker Z Ready Position 위치후에 진행하세요....."));
			return;
		}
		if ((pCommon->Check_Position(AX_LOAD_TRAY_Z1, 0) || pCommon->Check_Position(AX_LOAD_TRAY_Z1, 1)) &&
			(pCommon->Check_Position(AX_LOAD_TRAY_Z2, 0) || pCommon->Check_Position(AX_LOAD_TRAY_Z2, 1)) ) {
			pCommon->Move_Position(AX_LOAD_PICKER_Y1, 0);
		} else {
			AfxMessageBox(_T("Load Tray 1,2 Z Move (Up/Down) Position 위치후에 진행하세요....."));
		}
	} else if (nID == IDC_BTN_ML_PICKER_Y1_4) {
		if (!pCommon->Check_Position(AX_LOAD_PICKER_Z, 0)) {
			AfxMessageBox(_T("Load Picker Z Ready Position 위치후에 진행하세요....."));
			return;
		}
		if (!pAJinAXL->Is_Home(AX_LOAD_PICKER_Y1)) return;
		if ((pCommon->Check_Position(AX_LOAD_TRAY_Z1, 0) || pCommon->Check_Position(AX_LOAD_TRAY_Z1, 1)) &&
			(pCommon->Check_Position(AX_LOAD_TRAY_Z2, 0) || pCommon->Check_Position(AX_LOAD_TRAY_Z2, 1)) ) {
			pCommon->Move_Position(AX_LOAD_PICKER_Y1, 1);
		} else {
			AfxMessageBox(_T("Load Tray 1,2 Z Move (Up/Down) Position 위치후에 진행하세요....."));
		}

	} else if (nID == IDC_BTN_ML_PICKER_Y1_1) {
		if (!pCommon->Check_Position(AX_LOAD_PICKER_Z, 0)) {
			AfxMessageBox(_T("Load Picker Z Ready Position 위치후에 진행하세요....."));
			return;
		}
		if (!pAJinAXL->Is_Home(AX_LOAD_PICKER_Y1)) return;
		if ((pCommon->Check_Position(AX_LOAD_TRAY_Z1, 0) || pCommon->Check_Position(AX_LOAD_TRAY_Z1, 1)) &&
			(pCommon->Check_Position(AX_LOAD_TRAY_Z2, 0) || pCommon->Check_Position(AX_LOAD_TRAY_Z2, 1)) ) {
			pCommon->Move_Position(AX_LOAD_PICKER_Y1, 2);
		} else {
			AfxMessageBox(_T("Load Tray 1,2 Z Move (Up/Down) Position 위치후에 진행하세요....."));
		}

	} else if (nID == IDC_BTN_ML_PICKER_Y1_2) {
		if (!pAJinAXL->Is_Home(AX_UNLOAD_PICKER_X1)) return;
		if (!pCommon->Check_Position(AX_UNLOAD_PICKER_Z, 0)) {
			AfxMessageBox(_T("Unload Picker Z Ready Position 위치후에 진행하세요....."));
			return;
		}
		if ((pCommon->Check_Position(AX_UNLOAD_TRAY_Z1, 0) || pCommon->Check_Position(AX_UNLOAD_TRAY_Z1, 1)) &&
			(pCommon->Check_Position(AX_UNLOAD_TRAY_Z2, 0) || pCommon->Check_Position(AX_UNLOAD_TRAY_Z2, 1)) ) {
			pCommon->Move_Position(AX_UNLOAD_PICKER_X1, 0);
		} else {
			AfxMessageBox(_T("Unload Tray 1,2 Z Move (Up/Down) Position 위치후에 진행하세요....."));
		}

	} else if (nID == IDC_BTN_ML_PICKER_Y1_3) {
		if (!pAJinAXL->Is_Home(AX_UNLOAD_PICKER_X1)) return;
		if (!pCommon->Check_Position(AX_UNLOAD_PICKER_Z, 0)) {
			AfxMessageBox(_T("Unload Picker Z Ready Position 위치후에 진행하세요....."));
			return;
		}
		if ((pCommon->Check_Position(AX_UNLOAD_TRAY_Z1, 0) || pCommon->Check_Position(AX_UNLOAD_TRAY_Z1, 1)) &&
			(pCommon->Check_Position(AX_UNLOAD_TRAY_Z2, 0) || pCommon->Check_Position(AX_UNLOAD_TRAY_Z2, 1)) ) {
			pCommon->Move_Position(AX_UNLOAD_PICKER_X1, 1);
		} else {
			AfxMessageBox(_T("Unload Tray 1,2 Z Move (Up/Down) Position 위치후에 진행하세요....."));
		}

	} else if (nID == IDC_BTN_ML_PICKER_Y1_5) {
		if (!pAJinAXL->Is_Home(AX_UNLOAD_PICKER_X1)) return;
		if (!pCommon->Check_Position(AX_UNLOAD_PICKER_Z, 0)) {
			AfxMessageBox(_T("Unload Picker Z Ready Position 위치후에 진행하세요....."));
			return;
		}
		if ((pCommon->Check_Position(AX_UNLOAD_TRAY_Z1, 0) || pCommon->Check_Position(AX_UNLOAD_TRAY_Z1, 1)) &&
			(pCommon->Check_Position(AX_UNLOAD_TRAY_Z2, 0) || pCommon->Check_Position(AX_UNLOAD_TRAY_Z2, 1)) ) {
			pCommon->Move_Position(AX_UNLOAD_PICKER_X1, 2);
		} else {
			AfxMessageBox(_T("Unload Tray 1,2 Z Move (Up/Down) Position 위치후에 진행하세요....."));
		}

	}
}

void CManual_LoadPickerDlg::OnBtnMLNGPickY2Click(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	CCommon *pCommon = CCommon::Get_Instance();

	if (!pCommon->Check_MainDoor()) return;

	if (nID == IDC_BTN_ML_PICKER_Y2_0) {
		if (!pAJinAXL->Is_Home(AX_LOAD_PICKER_Y2)) return;
		pCommon->Move_Position(AX_LOAD_PICKER_Y2, 0);
	} else if (nID == IDC_BTN_ML_PICKER_Y2_1) {
		if (!pAJinAXL->Is_Home(AX_LOAD_PICKER_Y2)) return;
		pCommon->Move_Position(AX_LOAD_PICKER_Y2, 1);

	} else if (nID == IDC_BTN_ML_PICKER_Y2_2) {
		if (!pAJinAXL->Is_Home(AX_UNLOAD_PICKER_X2)) return;
		pCommon->Move_Position(AX_UNLOAD_PICKER_X2, 0);
	} else if (nID == IDC_BTN_ML_PICKER_Y2_3) {
		if (!pAJinAXL->Is_Home(AX_UNLOAD_PICKER_X2)) return;
		pCommon->Move_Position(AX_UNLOAD_PICKER_X2, 1);
	}
}

void CManual_LoadPickerDlg::OnBtnMLNGPickZClick(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_2 *pDX2 = pAJinAXL->Get_pDX2();
	CCommon *pCommon = CCommon::Get_Instance();

	if (!pCommon->Check_MainDoor()) return;

	if (nID == IDC_BTN_ML_PICKER_Z_0) {
		if (!pAJinAXL->Is_Home(AX_LOAD_PICKER_Z)) return;
		pCommon->Move_Position(AX_LOAD_PICKER_Z, 0);
	} else if (nID == IDC_BTN_ML_PICKER_Z_1) {
		if (!pAJinAXL->Is_Home(AX_LOAD_PICKER_Z)) return;

#ifdef PICKER_3
		if (pDX2->i_IndexAlignLoad_In && pCommon->Check_Position(AX_LOAD_PICKER_Y1, 2) &&
		   (pDX2->iMLPicker1CMCheck || pDX2->iMLPicker2CMCheck || pDX2->iMLPicker3CMCheck)) {
			AfxMessageBox(_T("Can not move......(Load Picker CM Check And Align 1 In)"));
			return;
		}
		if((!pDX2->iMLPicker1Open && !pDX2->iMLPicker1CMCheck) || (!pDX2->iMLPicker2Open && !pDX2->iMLPicker2CMCheck) || (!pDX2->iMLPicker3Open && !pDX2->iMLPicker3CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Load Picker Close And CM Check Off)"));
			return;
		}
#endif
#ifdef PICKER_5
		if (pDX2->i_IndexAlignLoad_In && pCommon->Check_Position(AX_LOAD_PICKER_Y1, 2) &&
		   (pDX2->iMLPicker1CMCheck || pDX2->iMLPicker2CMCheck || pDX2->iMLPicker3CMCheck || pDX2->iMLPicker4CMCheck || pDX2->iMLPicker5CMCheck)) {
			AfxMessageBox(_T("Can not move......(Load Picker CM Check And Align 1 In)"));
			return;
		}
		if((!pDX2->iMLPicker1Open && !pDX2->iMLPicker1CMCheck) || (!pDX2->iMLPicker2Open && !pDX2->iMLPicker2CMCheck) || (!pDX2->iMLPicker3Open && !pDX2->iMLPicker3CMCheck) ||
		   (!pDX2->iMLPicker4Open && !pDX2->iMLPicker4CMCheck) || (!pDX2->iMLPicker5Open && !pDX2->iMLPicker5CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Load Picker Close And CM Check Off)"));
			return;
		}
#endif
#ifdef PICKER_6
		if (pDX2->i_IndexAlignLoad_In && pCommon->Check_Position(AX_LOAD_PICKER_Y1, 2) &&
			(pDX2->iMLPicker1CMCheck || pDX2->iMLPicker2CMCheck || pDX2->iMLPicker3CMCheck || pDX2->iMLPicker4CMCheck || pDX2->iMLPicker5CMCheck || pDX2->iMLPicker6CMCheck)) {
				AfxMessageBox(_T("Can not move......(Load Picker CM Check And Align 1 In)"));
				return;
		}
		if((!pDX2->iMLPicker1Open && !pDX2->iMLPicker1CMCheck) || (!pDX2->iMLPicker2Open && !pDX2->iMLPicker2CMCheck) || (!pDX2->iMLPicker3Open && !pDX2->iMLPicker3CMCheck) ||
			(!pDX2->iMLPicker4Open && !pDX2->iMLPicker4CMCheck) || (!pDX2->iMLPicker5Open && !pDX2->iMLPicker5CMCheck) || (!pDX2->iMLPicker6Open && !pDX2->iMLPicker6CMCheck) ) {
				AfxMessageBox(_T("Can not move......(Load Picker Close And CM Check Off)"));
				return;
		}
#endif

		pCommon->Move_Position(AX_LOAD_PICKER_Z, 1);
	} else if (nID == IDC_BTN_ML_PICKER_Z_2) {
		if (!pAJinAXL->Is_Home(AX_LOAD_PICKER_Z)) return;

#ifdef PICKER_3
		if (pDX2->i_IndexAlignLoad_In && pCommon->Check_Position(AX_LOAD_PICKER_Y1, 2) &&
		   (pDX2->iMLPicker1CMCheck || pDX2->iMLPicker2CMCheck || pDX2->iMLPicker3CMCheck)) {
			AfxMessageBox(_T("Can not move......(Load Picker CM Check And Align 1 In)"));
			return;
		}
		if((!pDX2->iMLPicker1Open && !pDX2->iMLPicker1CMCheck) || (!pDX2->iMLPicker2Open && !pDX2->iMLPicker2CMCheck) || (!pDX2->iMLPicker3Open && !pDX2->iMLPicker3CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Load Picker Close And CM Check Off)"));
			return;
		}
#endif
#ifdef PICKER_5
		if (pDX2->i_IndexAlignLoad_In && pCommon->Check_Position(AX_LOAD_PICKER_Y1, 2) &&
		   (pDX2->iMLPicker1CMCheck || pDX2->iMLPicker2CMCheck || pDX2->iMLPicker3CMCheck || pDX2->iMLPicker4CMCheck || pDX2->iMLPicker5CMCheck)) {
			AfxMessageBox(_T("Can not move......(Load Picker CM Check And Align 1 In)"));
			return;
		}
		if((!pDX2->iMLPicker1Open && !pDX2->iMLPicker1CMCheck) || (!pDX2->iMLPicker2Open && !pDX2->iMLPicker2CMCheck) || (!pDX2->iMLPicker3Open && !pDX2->iMLPicker3CMCheck) ||
		   (!pDX2->iMLPicker4Open && !pDX2->iMLPicker4CMCheck) || (!pDX2->iMLPicker5Open && !pDX2->iMLPicker5CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Load Picker Close And CM Check Off)"));
			return;
		}
#endif
#ifdef PICKER_6
		if (pDX2->i_IndexAlignLoad_In && pCommon->Check_Position(AX_LOAD_PICKER_Y1, 2) &&
			(pDX2->iMLPicker1CMCheck || pDX2->iMLPicker2CMCheck || pDX2->iMLPicker3CMCheck || pDX2->iMLPicker4CMCheck || pDX2->iMLPicker5CMCheck || pDX2->iMLPicker6CMCheck)) {
				AfxMessageBox(_T("Can not move......(Load Picker CM Check And Align 1 In)"));
				return;
		}
		if((!pDX2->iMLPicker1Open && !pDX2->iMLPicker1CMCheck) || (!pDX2->iMLPicker2Open && !pDX2->iMLPicker2CMCheck) || (!pDX2->iMLPicker3Open && !pDX2->iMLPicker3CMCheck) ||
			(!pDX2->iMLPicker4Open && !pDX2->iMLPicker4CMCheck) || (!pDX2->iMLPicker5Open && !pDX2->iMLPicker5CMCheck) || (!pDX2->iMLPicker6Open && !pDX2->iMLPicker6CMCheck) ) {
				AfxMessageBox(_T("Can not move......(Load Picker Close And CM Check Off)"));
				return;
		}
#endif
		pCommon->Move_Position(AX_LOAD_PICKER_Z, 3);

	} else if (nID == IDC_BTN_ML_PICKER_Z_3) {
		if (!pAJinAXL->Is_Home(AX_UNLOAD_PICKER_Z)) return;
		pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 0);
	} else if (nID == IDC_BTN_ML_PICKER_Z_4) {
		if (!pAJinAXL->Is_Home(AX_UNLOAD_PICKER_Z)) return;
		pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 1);
	} else if (nID == IDC_BTN_ML_PICKER_Z_5) {
		if (!pAJinAXL->Is_Home(AX_UNLOAD_PICKER_Z)) return;
		pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 2);
	} else if (nID == IDC_BTN_ML_PICKER_Z_6) {
		if (!pAJinAXL->Is_Home(AX_UNLOAD_PICKER_Z)) return;
		pCommon->Move_Position(AX_UNLOAD_PICKER_Z, 3);
	}
}

void CManual_LoadPickerDlg::OnBtnMLPickIOClick(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DY_DATA_2 *pDY2 = pAJinAXL->Get_pDY2();
	DY_DATA_5 *pDY5 = pAJinAXL->Get_pDY5();

	CCommon *pCommon = CCommon::Get_Instance();
	if (!pCommon->Check_MainDoor()) return;

	if (nID == IDC_BTN_ML_PICKER_IO_0) {
		pDY2->oMLPicker1Open = TRUE;
		pDY2->oMLPicker1Close = FALSE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_1) {
		pDY2->oMLPicker1Open = FALSE;
		pDY2->oMLPicker1Close = TRUE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_2) {
		pDY2->oMLPicker2Open = TRUE;
		pDY2->oMLPicker2Close = FALSE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_3) {
		pDY2->oMLPicker2Open = FALSE;
		pDY2->oMLPicker2Close = TRUE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_4) {
		pDY2->oMLPicker3Open = TRUE;
		pDY2->oMLPicker3Close = FALSE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_5) {
		pDY2->oMLPicker3Open = FALSE;
		pDY2->oMLPicker3Close = TRUE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_6) {
		pDY2->oMLPicker4Open = TRUE;
		pDY2->oMLPicker4Close = FALSE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_7) {
		pDY2->oMLPicker4Open = FALSE;
		pDY2->oMLPicker4Close = TRUE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_8) {
		pDY2->oMLPicker5Open = TRUE;
		pDY2->oMLPicker5Close = FALSE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_9) {
		pDY2->oMLPicker5Open = FALSE;
		pDY2->oMLPicker5Close = TRUE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_10) {
		pDY2->oMLPicker6Open = TRUE;
		pDY2->oMLPicker6Close = FALSE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_11) {
		pDY2->oMLPicker6Open = FALSE;
		pDY2->oMLPicker6Close = TRUE;
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_24) {
		pDY2->oMLPicker1Open = TRUE;
		pDY2->oMLPicker1Close = FALSE;
		pDY2->oMLPicker2Open = TRUE;
		pDY2->oMLPicker2Close = FALSE;
		pDY2->oMLPicker3Open = TRUE;
		pDY2->oMLPicker3Close = FALSE;
#ifdef PICKER_5
		pDY2->oMLPicker4Open = TRUE;
		pDY2->oMLPicker4Close = FALSE;
		pDY2->oMLPicker5Open = TRUE;
		pDY2->oMLPicker5Close = FALSE;
#endif
#ifdef PICKER_6
		pDY2->oMLPicker4Open = TRUE;
		pDY2->oMLPicker4Close = FALSE;
		pDY2->oMLPicker5Open = TRUE;
		pDY2->oMLPicker5Close = FALSE;
		pDY2->oMLPicker6Open = TRUE;
		pDY2->oMLPicker6Close = FALSE;
#endif
		pAJinAXL->Write_Output(2);
	} else if (nID == IDC_BTN_ML_PICKER_IO_25) {
		pDY2->oMLPicker1Open = FALSE;
		pDY2->oMLPicker1Close = TRUE;
		pDY2->oMLPicker2Open = FALSE;
		pDY2->oMLPicker2Close = TRUE;
		pDY2->oMLPicker3Open = FALSE;
		pDY2->oMLPicker3Close = TRUE;
#ifdef PICKER_5
		pDY2->oMLPicker4Open = FALSE;
		pDY2->oMLPicker4Close = TRUE;
		pDY2->oMLPicker5Open = FALSE;
		pDY2->oMLPicker5Close = TRUE;
#endif
#ifdef PICKER_6
		pDY2->oMLPicker4Open = FALSE;
		pDY2->oMLPicker4Close = TRUE;
		pDY2->oMLPicker5Open = FALSE;
		pDY2->oMLPicker5Close = TRUE;
		pDY2->oMLPicker6Open = FALSE;
		pDY2->oMLPicker6Close = TRUE;
#endif
		pAJinAXL->Write_Output(2);

	} else if (nID == IDC_BTN_ML_PICKER_IO_12) {
		pDY5->oMUPicker1Open = TRUE;
		pDY5->oMUPicker1Close = FALSE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_13) {
		pDY5->oMUPicker1Open = FALSE;
		pDY5->oMUPicker1Close = TRUE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_14) {
		pDY5->oMUPicker2Open = TRUE;
		pDY5->oMUPicker2Close = FALSE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_15) {
		pDY5->oMUPicker2Open = FALSE;
		pDY5->oMUPicker2Close = TRUE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_16) {
		pDY5->oMUPicker3Open = TRUE;
		pDY5->oMUPicker3Close = FALSE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_17) {
		pDY5->oMUPicker3Open = FALSE;
		pDY5->oMUPicker3Close = TRUE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_18) {
		pDY5->oMUPicker4Open = TRUE;
		pDY5->oMUPicker4Close = FALSE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_19) {
		pDY5->oMUPicker4Open = FALSE;
		pDY5->oMUPicker4Close = TRUE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_20) {
		pDY5->oMUPicker5Open = TRUE;
		pDY5->oMUPicker5Close = FALSE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_21) {
		pDY5->oMUPicker5Open = FALSE;
		pDY5->oMUPicker5Close = TRUE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_22) {
		pDY5->oMUPicker6Open = TRUE;
		pDY5->oMUPicker6Close = FALSE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_23) {
		pDY5->oMUPicker6Open = FALSE;
		pDY5->oMUPicker6Close = TRUE;
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_26) {
		pDY5->oMUPicker1Open = TRUE;
		pDY5->oMUPicker1Close = FALSE;
		pDY5->oMUPicker2Open = TRUE;
		pDY5->oMUPicker2Close = FALSE;
		pDY5->oMUPicker3Open = TRUE;
		pDY5->oMUPicker3Close = FALSE;
#ifdef PICKER_5
		pDY5->oMUPicker4Open = TRUE;
		pDY5->oMUPicker4Close = FALSE;
		pDY5->oMUPicker5Open = TRUE;
		pDY5->oMUPicker5Close = FALSE;
#endif
#ifdef PICKER_6
		pDY5->oMUPicker4Open = TRUE;
		pDY5->oMUPicker4Close = FALSE;
		pDY5->oMUPicker5Open = TRUE;
		pDY5->oMUPicker5Close = FALSE;
		pDY5->oMUPicker6Open = TRUE;
		pDY5->oMUPicker6Close = FALSE;
#endif
		pAJinAXL->Write_Output(5);
	} else if (nID == IDC_BTN_ML_PICKER_IO_27) {
		pDY5->oMUPicker1Open = FALSE;
		pDY5->oMUPicker1Close = TRUE;
		pDY5->oMUPicker2Open = FALSE;
		pDY5->oMUPicker2Close = TRUE;
		pDY5->oMUPicker3Open = FALSE;
		pDY5->oMUPicker3Close = TRUE;
#ifdef PICKER_5
		pDY5->oMUPicker4Open = FALSE;
		pDY5->oMUPicker4Close = TRUE;
		pDY5->oMUPicker5Open = FALSE;
		pDY5->oMUPicker5Close = TRUE;
#endif
#ifdef PICKER_6
		pDY5->oMUPicker4Open = FALSE;
		pDY5->oMUPicker4Close = TRUE;
		pDY5->oMUPicker5Open = FALSE;
		pDY5->oMUPicker5Close = TRUE;
		pDY5->oMUPicker6Open = FALSE;
		pDY5->oMUPicker6Close = TRUE;
#endif
		pAJinAXL->Write_Output(5);
	}
}


void CManual_LoadPickerDlg::OnBtnNGPickMoveClick()
{

}

void CManual_LoadPickerDlg::OnBtnNGPickMovePosClick(UINT nID)
{

 	int ID; 
	CCommon *pCommon = CCommon::Get_Instance();
	CString strOld, strNew;

	if (nID == IDC_STC_MOVE_0) 
	{
		ID = 0;
	}

	if (nID == IDC_STC_MOVE_1) 
	{
		ID = 1;
	}

	if (nID == IDC_STC_MOVE_2) 
	{
		ID = 2;
	}
	if (nID == IDC_STC_MOVE_3) 
	{
		ID = 3;
	}

	m_stcPickerMove[ID].GetWindowText(strOld);
	if (pCommon->Show_NumPad(strOld, strNew) == IDOK) {
		m_stcPickerMove[ID].SetWindowText(strNew);
	}

}



void CManual_LoadPickerDlg::OnBnClickedBtnNgPickerMove2()
{
	CString sTmp[4];
	int xx, yy, zz;

	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	CCommon *pCommon = CCommon::Get_Instance();

	for(int i = 0; i< 4; i++){
		m_stcPickerMove[i].GetWindowText(sTmp[i]);
	}
	if(sTmp[0] != "1" && sTmp[0] != "2" && sTmp[0] != "3" && sTmp[0] != "4"){
		AfxMessageBox(_T("Picker Type (1~4) 입력 Error..................."));
		return;
	}

	zz = atoi(sTmp[1]);	//No
	xx = atoi(sTmp[2]);	//x
	yy = atoi(sTmp[3]);	//y

	if(xx < 1 || xx > 2){
		AfxMessageBox(_T("Tray No 입력(1~2) Error..................."));
		return;
	}
	if(yy < 1 || yy > 6){
		AfxMessageBox(_T("Tray Array No 입력(1~6) Error..................."));
		return;
	}
	if(zz < 1 || zz > 6){
		AfxMessageBox(_T("Picker No (1~6) 입력 Error..................."));
		return;
	}

	CString sLog;
	if(sTmp[0] == "1"){ 
		pCommon->PickerLoad_Move(1, yy, xx);

		pAJinAXL->Move_Absolute(AX_LOAD_PICKER_Z, pCommon->m_dP1Z);
		sLog.Format("dZ Position[%0.3lf]", pCommon->m_dP1Z);
	} 
	if(sTmp[0] == "2"){	
		pCommon->PickerLoad_Move(2, yy, xx);

		pAJinAXL->Move_Absolute(AX_LOAD_PICKER_Z, pCommon->m_dP1Z);
		sLog.Format("dZ Position[%0.3lf]", pCommon->m_dP1Z);
	} 
	if(sTmp[0] == "3"){	
		pCommon->PickerUnload_Move(1, yy, xx);

		pAJinAXL->Move_Absolute(AX_UNLOAD_PICKER_Z, pCommon->m_dP2Z);
		sLog.Format("dZ Position[%0.3lf]", pCommon->m_dP2Z);
	} 
	if(sTmp[0] == "4"){	

		pCommon->PickerUnload_Move(2, yy, xx);

		pAJinAXL->Move_Absolute(AX_UNLOAD_PICKER_Z, pCommon->m_dP2Z);
		sLog.Format("dZ Position[%0.3lf]", pCommon->m_dP2Z);
	} 
	AfxMessageBox(_T(sLog));

}

