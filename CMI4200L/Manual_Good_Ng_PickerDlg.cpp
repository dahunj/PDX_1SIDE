// Manual_Good_Ng_PickerDlg.cpp : 구현 파일입니다.
//
#include "stdafx.h"
#include "CMI4200L.h"
#include "Manual_Good_Ng_PickerDlg.h"
#include "afxdialogex.h"

#include "AJinAXL.h"
#include "DataManager.h"
#include "Common.h"
#include "LogFile.h"
#include "ManualDlg.h"
#include "Math.h"

// CManual_Good_Ng_PickerDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CManual_Good_Ng_PickerDlg, CDialogEx)

CManual_Good_Ng_PickerDlg::CManual_Good_Ng_PickerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManual_Good_Ng_PickerDlg::IDD, pParent)
{
}

CManual_Good_Ng_PickerDlg::~CManual_Good_Ng_PickerDlg()
{
}

void CManual_Good_Ng_PickerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	DDX_Control(pDX, IDC_STC_AXIS_POS_1, m_stcAxisPos[1]);
	DDX_Control(pDX, IDC_STC_AXIS_POS_2, m_stcAxisPos[2]);
	DDX_Control(pDX, IDC_STC_AXIS_POS_3, m_stcAxisPos[3]);
	DDX_Control(pDX, IDC_STC_AXIS_POS_4, m_stcAxisPos[4]);
	
	//CMI3000
	
	for (int i = 0; i < 2; i++) DDX_Control(pDX,  IDC_BTN_PICKER_Y_0 + i, m_btnGoodPickerY[i]);
	DDX_Control(pDX,  IDC_BTN_PICKER_Y_2, m_btnGoodPickerY[2]);
	DDX_Control(pDX,  IDC_BTN_PICKER_Y_3, m_btnGoodPickerY[3]);
	DDX_Control(pDX,  IDC_BTN_PICKER_Y_4, m_btnGoodPickerY[4]);
	DDX_Control(pDX,  IDC_BTN_PICKER_Y_5, m_btnGoodPickerY[5]);
	for (int i = 0; i < 2; i++) DDX_Control(pDX,  IDC_BTN_PICKER_Z_0 + i, m_btnGoodPickerZ[i]);

	for (int i = 0; i < 4; i++) DDX_Control(pDX,  IDC_BTN_GOOD_PICKER1_0 + i, m_btnGoodPicker1[i]);
	for (int i = 0; i < 4; i++) DDX_Control(pDX,  IDC_BTN_GOOD_PICKER2_0 + i, m_btnGoodPicker2[i]);
	for (int i = 0; i < 4; i++) DDX_Control(pDX,  IDC_BTN_GOOD_PICKER3_0 + i, m_btnGoodPicker3[i]);
	for (int i = 0; i < 4; i++) DDX_Control(pDX,  IDC_BTN_GOOD_PICKER4_0 + i, m_btnGoodPicker4[i]);
	for (int i = 0; i < 4; i++) DDX_Control(pDX,  IDC_BTN_GOOD_PICKER5_0 + i, m_btnGoodPicker5[i]);
	for (int i = 0; i < 4; i++) DDX_Control(pDX,  IDC_BTN_GOOD_PICKER6_0 + i, m_btnGoodPicker6[i]);

	DDX_Control(pDX,  IDC_BTN_GOOD_PICKER_0, m_btnGoodPickerAll[0]);
	DDX_Control(pDX,  IDC_BTN_GOOD_PICKER_1, m_btnGoodPickerAll[1]);
	DDX_Control(pDX,  IDC_BTN_GOOD_PICKER_2, m_btnGoodPickerAll[2]);
	DDX_Control(pDX,  IDC_BTN_GOOD_PICKER_3, m_btnGoodPickerAll[3]);

	for (int i = 0; i < 4; i++) DDX_Control(pDX, IDC_LED_GOODPICKER_1_IO_0 + i, m_ledGoogPick1IO[i]);
	for (int i = 0; i < 4; i++) DDX_Control(pDX, IDC_LED_GOODPICKER_2_IO_0 + i, m_ledGoogPick2IO[i]);
	for (int i = 0; i < 4; i++) DDX_Control(pDX, IDC_LED_GOODPICKER_3_IO_0 + i, m_ledGoogPick3IO[i]);
	for (int i = 0; i < 4; i++) DDX_Control(pDX, IDC_LED_GOODPICKER_4_IO_0 + i, m_ledGoogPick4IO[i]);
	for (int i = 0; i < 4; i++) DDX_Control(pDX, IDC_LED_GOODPICKER_5_IO_0 + i, m_ledGoogPick5IO[i]);
	for (int i = 0; i < 4; i++) DDX_Control(pDX, IDC_LED_GOODPICKER_6_IO_0 + i, m_ledGoogPick6IO[i]);

	DDX_Control(pDX, IDC_LED_GOODPICKER_1_IO_0 , m_ledGoogPick1IO[0]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_1_IO_1 , m_ledGoogPick1IO[1]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_1_IO_2 , m_ledGoogPick1IO[2]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_1_IO_3 , m_ledGoogPick1IO[3]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_1_IO_4 , m_ledGoogPick1IO[4]);
	
	DDX_Control(pDX, IDC_LED_GOODPICKER_2_IO_0 , m_ledGoogPick2IO[0]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_2_IO_1 , m_ledGoogPick2IO[1]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_2_IO_2 , m_ledGoogPick2IO[2]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_2_IO_3 , m_ledGoogPick2IO[3]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_2_IO_4 , m_ledGoogPick2IO[4]);

	DDX_Control(pDX, IDC_LED_GOODPICKER_3_IO_0 , m_ledGoogPick3IO[0]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_3_IO_1 , m_ledGoogPick3IO[1]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_3_IO_2 , m_ledGoogPick3IO[2]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_3_IO_3 , m_ledGoogPick3IO[3]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_3_IO_4 , m_ledGoogPick3IO[4]);
	
	DDX_Control(pDX, IDC_LED_GOODPICKER_4_IO_0 , m_ledGoogPick4IO[0]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_4_IO_1 , m_ledGoogPick4IO[1]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_4_IO_2 , m_ledGoogPick4IO[2]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_4_IO_3 , m_ledGoogPick4IO[3]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_4_IO_4 , m_ledGoogPick4IO[4]);
	
	DDX_Control(pDX, IDC_LED_GOODPICKER_5_IO_0 , m_ledGoogPick5IO[0]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_5_IO_1 , m_ledGoogPick5IO[1]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_5_IO_2 , m_ledGoogPick5IO[2]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_5_IO_3 , m_ledGoogPick5IO[3]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_5_IO_4 , m_ledGoogPick5IO[4]);
	
	DDX_Control(pDX, IDC_LED_GOODPICKER_6_IO_0 , m_ledGoogPick6IO[0]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_6_IO_1 , m_ledGoogPick6IO[1]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_6_IO_2 , m_ledGoogPick6IO[2]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_6_IO_3 , m_ledGoogPick6IO[3]);
	DDX_Control(pDX, IDC_LED_GOODPICKER_6_IO_4 , m_ledGoogPick6IO[4]);

	DDX_Control(pDX, IDC_BTN_NG_PICKER_X_0, m_btnNGPickX[0]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_X_1, m_btnNGPickX[1]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_X_2, m_btnNGPickX[2]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_X_3, m_btnNGPickX[3]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_X_4, m_btnNGPickX[4]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_X_5, m_btnNGPickX[5]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_Z_0, m_btnNGPickZ[0]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_Z_1, m_btnNGPickZ[1]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_Z_2, m_btnNGPickZ[2]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_0, m_btnNGPickIO[0]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_1, m_btnNGPickIO[1]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_2, m_btnNGPickIO[2]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_3, m_btnNGPickIO[3]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_4, m_btnNGPickIO[4]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_5, m_btnNGPickIO[5]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_6, m_btnNGPickIO[6]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_7, m_btnNGPickIO[7]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_8, m_btnNGPickIO[8]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_9, m_btnNGPickIO[9]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_10, m_btnNGPickIO[10]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_11, m_btnNGPickIO[11]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_12, m_btnNGPickIO[12]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_13, m_btnNGPickIO[13]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_14, m_btnNGPickIO[14]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_15, m_btnNGPickIO[15]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_16, m_btnNGPickIO[16]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_17, m_btnNGPickIO[17]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_18, m_btnNGPickIO[18]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_19, m_btnNGPickIO[19]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_20, m_btnNGPickIO[20]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_21, m_btnNGPickIO[21]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_22, m_btnNGPickIO[22]);
	DDX_Control(pDX, IDC_BTN_NG_PICKER_IO1_23, m_btnNGPickIO[23]);

	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_0, m_ledNGPickIO[0]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_1, m_ledNGPickIO[1]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_2, m_ledNGPickIO[2]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_3, m_ledNGPickIO[3]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_4, m_ledNGPickIO[4]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_5, m_ledNGPickIO[5]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_6, m_ledNGPickIO[6]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_7, m_ledNGPickIO[7]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_8, m_ledNGPickIO[8]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_9, m_ledNGPickIO[9]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_10, m_ledNGPickIO[10]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_11, m_ledNGPickIO[11]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_12, m_ledNGPickIO[12]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_13, m_ledNGPickIO[13]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_14, m_ledNGPickIO[14]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_15, m_ledNGPickIO[15]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_16, m_ledNGPickIO[16]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_17, m_ledNGPickIO[17]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_18, m_ledNGPickIO[18]);
	DDX_Control(pDX, IDC_LED_NG_PICKER_IO1_19, m_ledNGPickIO[19]);

	
}

BEGIN_MESSAGE_MAP(CManual_Good_Ng_PickerDlg, CDialogEx)
	ON_WM_DESTROY()
	ON_WM_SHOWWINDOW()

	//CIM3000L	
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_PICKER_Y_0, IDC_BTN_PICKER_Y_1, OnBtnPickerYClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_PICKER_Y_2, IDC_BTN_PICKER_Y_2, OnBtnPickerYClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_PICKER_Y_3, IDC_BTN_PICKER_Y_3, OnBtnPickerYClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_PICKER_Y_4, IDC_BTN_PICKER_Y_4, OnBtnPickerYClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_PICKER_Y_5, IDC_BTN_PICKER_Y_5, OnBtnPickerYClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_PICKER_Z_0, IDC_BTN_PICKER_Z_1, OnBtnPickerZClick)

	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_GOOD_PICKER1_0, IDC_BTN_GOOD_PICKER1_3, OnBtnPicker1Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_GOOD_PICKER2_0, IDC_BTN_GOOD_PICKER2_3, OnBtnPicker2Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_GOOD_PICKER3_0, IDC_BTN_GOOD_PICKER3_3, OnBtnPicker3Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_GOOD_PICKER4_0, IDC_BTN_GOOD_PICKER4_3, OnBtnPicker4Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_GOOD_PICKER5_0, IDC_BTN_GOOD_PICKER5_3, OnBtnPicker5Click)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_GOOD_PICKER6_0, IDC_BTN_GOOD_PICKER6_3, OnBtnPicker6Click)

	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_GOOD_PICKER_0, IDC_BTN_GOOD_PICKER_0, OnBtnPickerAClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_GOOD_PICKER_1, IDC_BTN_GOOD_PICKER_1, OnBtnPickerAClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_GOOD_PICKER_2, IDC_BTN_GOOD_PICKER_2, OnBtnPickerAClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_GOOD_PICKER_3, IDC_BTN_GOOD_PICKER_3, OnBtnPickerAClick)

	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_X_0, IDC_BTN_NG_PICKER_X_0, OnBtnNGPickXClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_X_1, IDC_BTN_NG_PICKER_X_1, OnBtnNGPickXClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_X_2, IDC_BTN_NG_PICKER_X_2, OnBtnNGPickXClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_X_3, IDC_BTN_NG_PICKER_X_3, OnBtnNGPickXClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_X_4, IDC_BTN_NG_PICKER_X_4, OnBtnNGPickXClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_X_5, IDC_BTN_NG_PICKER_X_5, OnBtnNGPickXClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_Z_0, IDC_BTN_NG_PICKER_Z_0, OnBtnNGPickZClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_Z_1, IDC_BTN_NG_PICKER_Z_1, OnBtnNGPickZClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_Z_2, IDC_BTN_NG_PICKER_Z_2, OnBtnNGPickZClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_0, IDC_BTN_NG_PICKER_IO1_0, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_1, IDC_BTN_NG_PICKER_IO1_1, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_2, IDC_BTN_NG_PICKER_IO1_2, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_3, IDC_BTN_NG_PICKER_IO1_3, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_4, IDC_BTN_NG_PICKER_IO1_4, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_5, IDC_BTN_NG_PICKER_IO1_5, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_6, IDC_BTN_NG_PICKER_IO1_6, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_7, IDC_BTN_NG_PICKER_IO1_7, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_8, IDC_BTN_NG_PICKER_IO1_8, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_9, IDC_BTN_NG_PICKER_IO1_9, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_10, IDC_BTN_NG_PICKER_IO1_10, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_11, IDC_BTN_NG_PICKER_IO1_11, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_12, IDC_BTN_NG_PICKER_IO1_12, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_13, IDC_BTN_NG_PICKER_IO1_13, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_14, IDC_BTN_NG_PICKER_IO1_14, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_15, IDC_BTN_NG_PICKER_IO1_15, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_16, IDC_BTN_NG_PICKER_IO1_16, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_17, IDC_BTN_NG_PICKER_IO1_17, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_18, IDC_BTN_NG_PICKER_IO1_18, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_19, IDC_BTN_NG_PICKER_IO1_19, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_20, IDC_BTN_NG_PICKER_IO1_20, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_21, IDC_BTN_NG_PICKER_IO1_21, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_22, IDC_BTN_NG_PICKER_IO1_22, OnBtnNGPickIOClick)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BTN_NG_PICKER_IO1_23, IDC_BTN_NG_PICKER_IO1_23, OnBtnNGPickIOClick)


END_MESSAGE_MAP()

// CManual_Good_Ng_PickerDlg 메시지 처리기입니다.

BOOL CManual_Good_Ng_PickerDlg::OnInitDialog() 
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetWindowPos(this, 150, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	Initial_Controls();

#ifdef PICKER_3
	for (int i=3; i<6; i++) m_btnGoodPickerY[i].ShowWindow(FALSE);
	for (int i=0; i<4; i++) m_btnGoodPicker4[i].ShowWindow(FALSE);
	for (int i=0; i<4; i++) m_btnGoodPicker5[i].ShowWindow(FALSE);
	for (int i=0; i<4; i++) m_btnGoodPicker6[i].ShowWindow(FALSE);
	for (int i=0; i<5; i++) m_ledGoogPick4IO[i].ShowWindow(FALSE);
	for (int i=0; i<5; i++) m_ledGoogPick5IO[i].ShowWindow(FALSE);
	for (int i=0; i<5; i++) m_ledGoogPick6IO[i].ShowWindow(FALSE);

	for (int i=3; i<6; i++) m_btnNGPickX[i].ShowWindow(FALSE);
	for (int i=16;i<24;i++) m_btnNGPickIO[i].ShowWindow(FALSE);
	for (int i=12;i<20;i++) m_ledNGPickIO[i].ShowWindow(FALSE);
#endif

#ifdef PICKER_5
	for (int i=0; i<4; i++) m_btnGoodPicker6[i].ShowWindow(FALSE);
	for (int i=0; i<5; i++) m_ledGoogPick6IO[i].ShowWindow(FALSE);
#endif

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CManual_Good_Ng_PickerDlg::OnDestroy() 
{
	CDialogEx::OnDestroy();
}

BOOL CManual_Good_Ng_PickerDlg::PreTranslateMessage(MSG* pMsg) 
{
	if ((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE))
		return TRUE;

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CManual_Good_Ng_PickerDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	if (bShow) {
		Display_Status();
	}
}



void CManual_Good_Ng_PickerDlg::OnBtnPickerYClick(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_4 *pDX4 = pAJinAXL->Get_pDX4();
	CCommon *pCommon = CCommon::Get_Instance();

	if (!pCommon->Check_MainDoor()) return;
	if (!pAJinAXL->Is_Home(AX_GOOD_PICKER_Y)) return;

#ifdef PICKER_3
	if (!pDX4->iGoodPicker1Up || !pDX4->iGoodPicker2Up || !pDX4->iGoodPicker3Up || 
		pDX4->iGoodPicker1Down || pDX4->iGoodPicker2Down || pDX4->iGoodPicker3Down )
#endif
#ifdef PICKER_5
	if (!pDX4->iGoodPicker1Up || !pDX4->iGoodPicker2Up || !pDX4->iGoodPicker3Up || 
		!pDX4->iGoodPicker4Up || !pDX4->iGoodPicker5Up ||
		pDX4->iGoodPicker1Down || pDX4->iGoodPicker2Down || pDX4->iGoodPicker3Down || 
		pDX4->iGoodPicker4Down || pDX4->iGoodPicker5Down )
#endif
#ifdef PICKER_6
	if (!pDX4->iGoodPicker1Up || !pDX4->iGoodPicker2Up || !pDX4->iGoodPicker3Up || 
		!pDX4->iGoodPicker4Up || !pDX4->iGoodPicker5Up || !pDX4->iGoodPicker6Up ||
		pDX4->iGoodPicker1Down || pDX4->iGoodPicker2Down || pDX4->iGoodPicker3Down || 
		pDX4->iGoodPicker4Down || pDX4->iGoodPicker5Down || pDX4->iGoodPicker6Down)
#endif
	{
		AfxMessageBox(_T("Good Picker Up후 진행하세요............."));
		return;
	}

	if (nID == IDC_BTN_PICKER_Y_0) {
		pCommon->Move_Position(AX_GOOD_PICKER_Y, 1);
	} else if (nID == IDC_BTN_PICKER_Y_1) {
		pCommon->Move_Position(AX_GOOD_PICKER_Y, 2);
	} else if (nID == IDC_BTN_PICKER_Y_2) {
		pCommon->Move_Position(AX_GOOD_PICKER_Y, 3);
	} else if (nID == IDC_BTN_PICKER_Y_3) {
		pCommon->Move_Position(AX_GOOD_PICKER_Y, 4);
	} else if (nID == IDC_BTN_PICKER_Y_4) {
		pCommon->Move_Position(AX_GOOD_PICKER_Y, 5);
	} else if (nID == IDC_BTN_PICKER_Y_5) {
		pCommon->Move_Position(AX_GOOD_PICKER_Y, 6);
	}

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnPickerYClick.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}

void CManual_Good_Ng_PickerDlg::OnBtnPickerZClick(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	CCommon *pCommon = CCommon::Get_Instance();

	if (!pCommon->Check_MainDoor()) return;
	if (!pAJinAXL->Is_Home(AX_GOOD_PICKER_Z) ) return;

	if (nID == IDC_BTN_PICKER_Z_0) {
		pCommon->Move_Position(AX_GOOD_PICKER_Z, 1);
	} else if (nID == IDC_BTN_PICKER_Z_1) {
		pCommon->Move_Position(AX_GOOD_PICKER_Z, 2);
	}

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnPickerZClick.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}

void CManual_Good_Ng_PickerDlg::OnBtnNGPickXClick(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	CCommon *pCommon = CCommon::Get_Instance();
	DX_DATA_3 *pDX3 = pAJinAXL->Get_pDX3();

	if (!pAJinAXL->Is_Home(AX_NG_PICKER_X)) return;
	if (!pCommon->Check_MainDoor()) return;

#ifdef NG_PICKER_3
	if (!pDX3->iNGPicker1Up || !pDX3->iNGPicker2Up || !pDX3->iNGPicker3Up ||
		pDX3->iNGPicker1Down || pDX3->iNGPicker2Down || pDX3->iNGPicker3Down ) {
			AfxMessageBox(_T("NG Picker Z Up후에 진행하세요....."));
			return;
	}
#else
	if (!pDX3->iNGPicker1Up || !pDX3->iNGPicker2Up || !pDX3->iNGPicker3Up || !pDX3->iNGPicker4Up || !pDX3->iNGPicker5Up ||
		pDX3->iNGPicker1Down || pDX3->iNGPicker2Down || pDX3->iNGPicker3Down || pDX3->iNGPicker4Down || pDX3->iNGPicker5Down ) {
		AfxMessageBox(_T("NG Picker Z Up후에 진행하세요....."));
		return;
	}
#endif

	if (/*!pCommon->Check_Position(AX_NG_PICKER_Z, 0) && */!pCommon->Check_Position(AX_NG_PICKER_Z, 1)) {
		AfxMessageBox(_T("NG Picker Z축 NG Position 위치후에 진행하세요....."));
		return;
	}

	if (nID == IDC_BTN_NG_PICKER_X_0) {
		pCommon->Move_Position(AX_NG_PICKER_X, 0);
	} else if (nID == IDC_BTN_NG_PICKER_X_1) {
		pCommon->Move_Position(AX_NG_PICKER_X, 1);
	} else if (nID == IDC_BTN_NG_PICKER_X_2) {
		pCommon->Move_Position(AX_NG_PICKER_X, 2);
	} else if (nID == IDC_BTN_NG_PICKER_X_3) {
		pCommon->Move_Position(AX_NG_PICKER_X, 3);
	} else if (nID == IDC_BTN_NG_PICKER_X_4) {
		pCommon->Move_Position(AX_NG_PICKER_X, 4);
	} else if (nID == IDC_BTN_NG_PICKER_X_5) {
		pCommon->Move_Position(AX_NG_PICKER_X, 5);
	}

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnNGPickXClick.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}

void CManual_Good_Ng_PickerDlg::OnBtnNGPickZClick(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	CCommon *pCommon = CCommon::Get_Instance();

	if (!pAJinAXL->Is_Home(AX_NG_PICKER_Z)) return;
	if (!pCommon->Check_MainDoor()) return;

	if (nID == IDC_BTN_NG_PICKER_Z_0) {
		pCommon->Move_Position(AX_NG_PICKER_Z, 0);
	} else if (nID == IDC_BTN_NG_PICKER_Z_1) {
		pCommon->Move_Position(AX_NG_PICKER_Z, 1);
	} else if (nID == IDC_BTN_NG_PICKER_Z_2) {
		pCommon->Move_Position(AX_NG_PICKER_Z, 2);
	}

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnNGPickZClick.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}

void CManual_Good_Ng_PickerDlg::OnBtnNGPickIOClick(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_2 *pDX2 = pAJinAXL->Get_pDX2();
	DX_DATA_3 *pDX3 = pAJinAXL->Get_pDX3();
	DY_DATA_3 *pDY3 = pAJinAXL->Get_pDY3();

	CCommon *pCommon = CCommon::Get_Instance();
	if (!pCommon->Check_MainDoor()) return;

	if (nID == IDC_BTN_NG_PICKER_IO1_0) {
		pDY3->oNGPicker1Open = TRUE;
		pDY3->oNGPicker1Close = FALSE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_1) {
		pDY3->oNGPicker1Open = FALSE;
		pDY3->oNGPicker1Close = TRUE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_2) {
		pDY3->oNGPicker1Up = TRUE;
		pDY3->oNGPicker1Down = FALSE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_3) {
		if (pDX2->i_IndexAlignNG_In && pCommon->Check_Position(AX_NG_PICKER_X, 0) && pDX3->iNGPicker1CMCheck) {
			AfxMessageBox(_T("Can not move......(NG Picker1 CM Check And Align 2 In)"));
			return;
		}
		if((!pDX3->iNGPicker1Open && !pDX3->iNGPicker1CMCheck) ) {
			AfxMessageBox(_T("Can not move......(NG Picker1 Close And CM Check Off)"));
			return;
		}

		pDY3->oNGPicker1Up = FALSE;
		pDY3->oNGPicker1Down = TRUE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_4) {
		pDY3->oNGPicker2Open = TRUE;
		pDY3->oNGPicker2Close = FALSE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_5) {
		pDY3->oNGPicker2Open = FALSE;
		pDY3->oNGPicker2Close = TRUE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_6) {
		pDY3->oNGPicker2Up = TRUE;
		pDY3->oNGPicker2Down = FALSE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_7) {
		if (pDX2->i_IndexAlignNG_In && pCommon->Check_Position(AX_NG_PICKER_X, 0) && pDX3->iNGPicker2CMCheck) {
			AfxMessageBox(_T("Can not move......(NG Picker2 CM Check And Align 2 In)"));
			return;
		}
		if((!pDX3->iNGPicker2Open && !pDX3->iNGPicker2CMCheck) ) {
			AfxMessageBox(_T("Can not move......(NG Picker2 Close And CM Check Off)"));
			return;
		}

		pDY3->oNGPicker2Up = FALSE;
		pDY3->oNGPicker2Down = TRUE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_8) {
		pDY3->oNGPicker3Open = TRUE;
		pDY3->oNGPicker3Close = FALSE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_9) {
		pDY3->oNGPicker3Open = FALSE;
		pDY3->oNGPicker3Close = TRUE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_10) {
		pDY3->oNGPicker3Up = TRUE;
		pDY3->oNGPicker3Down = FALSE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_11) {
		if (pDX2->i_IndexAlignNG_In && pCommon->Check_Position(AX_NG_PICKER_X, 0) && pDX3->iNGPicker3CMCheck) {
			AfxMessageBox(_T("Can not move......(NG Picker3 CM Check And Align 2 In)"));
			return;
		}
		if((!pDX3->iNGPicker3Open && !pDX3->iNGPicker3CMCheck) ) {
			AfxMessageBox(_T("Can not move......(NG Picker3 Close And CM Check Off)"));
			return;
		}

		pDY3->oNGPicker3Up = FALSE;
		pDY3->oNGPicker3Down = TRUE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_12) {
		pDY3->oNGPicker1Open = TRUE;
		pDY3->oNGPicker1Close = FALSE;
		pDY3->oNGPicker2Open = TRUE;
		pDY3->oNGPicker2Close = FALSE;
		pDY3->oNGPicker3Open = TRUE;
		pDY3->oNGPicker3Close = FALSE;
#ifndef NG_PICKER_3
		pDY3->oNGPicker4Open = TRUE;
		pDY3->oNGPicker4Close = FALSE;
		pDY3->oNGPicker5Open = TRUE;
		pDY3->oNGPicker5Close = FALSE;
#endif
	} else if (nID == IDC_BTN_NG_PICKER_IO1_13) {
		pDY3->oNGPicker1Open = FALSE;
		pDY3->oNGPicker1Close = TRUE;
		pDY3->oNGPicker2Open = FALSE;
		pDY3->oNGPicker2Close = TRUE;
		pDY3->oNGPicker3Open = FALSE;
		pDY3->oNGPicker3Close = TRUE;
#ifndef NG_PICKER_3
		pDY3->oNGPicker4Open = FALSE;
		pDY3->oNGPicker4Close = TRUE;
		pDY3->oNGPicker5Open = FALSE;
		pDY3->oNGPicker5Close = TRUE;
#endif
	} else if (nID == IDC_BTN_NG_PICKER_IO1_14) {
		pDY3->oNGPicker1Up = TRUE;
		pDY3->oNGPicker1Down = FALSE;
		pDY3->oNGPicker2Up = TRUE;
		pDY3->oNGPicker2Down = FALSE;
		pDY3->oNGPicker3Up = TRUE;
		pDY3->oNGPicker3Down = FALSE;
#ifndef NG_PICKER_3
		pDY3->oNGPicker4Up = TRUE;
		pDY3->oNGPicker4Down = FALSE;
		pDY3->oNGPicker5Up = TRUE;
		pDY3->oNGPicker5Down = FALSE;
#endif
	} else if (nID == IDC_BTN_NG_PICKER_IO1_15) {
#ifdef NG_PICKER_3
		if (pDX2->i_IndexAlignNG_In && pCommon->Check_Position(AX_NG_PICKER_X, 0) &&
			(pDX3->iNGPicker1CMCheck || pDX3->iNGPicker2CMCheck || pDX3->iNGPicker3CMCheck)) {
				AfxMessageBox(_T("Can not move......(NG Picker CM Check And Align 2 In)"));
				return;
		}
		if((!pDX3->iNGPicker1Open && !pDX3->iNGPicker1CMCheck) || (!pDX3->iNGPicker2Open && !pDX3->iNGPicker2CMCheck) || (!pDX3->iNGPicker3Open && !pDX3->iNGPicker3CMCheck) ) {
				AfxMessageBox(_T("Can not move......(NG Picker Close And CM Check Off)"));
				return;
		}
#else
		if (pDX2->i_IndexAlignNG_In && pCommon->Check_Position(AX_NG_PICKER_X, 0) &&
		   (pDX3->iNGPicker1CMCheck || pDX3->iNGPicker2CMCheck || pDX3->iNGPicker3CMCheck || pDX3->iNGPicker4CMCheck || pDX3->iNGPicker5CMCheck)) {
			AfxMessageBox(_T("Can not move......(NG Picker CM Check And Align 2 In)"));
			return;
		}
		if((!pDX3->iNGPicker1Open && !pDX3->iNGPicker1CMCheck) || (!pDX3->iNGPicker2Open && !pDX3->iNGPicker2CMCheck) || (!pDX3->iNGPicker3Open && !pDX3->iNGPicker3CMCheck) ||
		   (!pDX3->iNGPicker4Open && !pDX3->iNGPicker4CMCheck) || (!pDX3->iNGPicker5Open && !pDX3->iNGPicker5CMCheck) ) {
			AfxMessageBox(_T("Can not move......(NG Picker Close And CM Check Off)"));
			return;
		}
#endif

		pDY3->oNGPicker1Up = FALSE;
		pDY3->oNGPicker1Down = TRUE;
		pDY3->oNGPicker2Up = FALSE;
		pDY3->oNGPicker2Down = TRUE;
		pDY3->oNGPicker3Up = FALSE;
		pDY3->oNGPicker3Down = TRUE;
#ifndef NG_PICKER_3
		pDY3->oNGPicker4Up = FALSE;
		pDY3->oNGPicker4Down = TRUE;
		pDY3->oNGPicker5Up = FALSE;
		pDY3->oNGPicker5Down = TRUE;
#endif

	} else if (nID == IDC_BTN_NG_PICKER_IO1_16) {
		pDY3->oNGPicker4Open = TRUE;
		pDY3->oNGPicker4Close = FALSE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_17) {
		pDY3->oNGPicker4Open = FALSE;
		pDY3->oNGPicker4Close = TRUE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_18) {
		pDY3->oNGPicker4Up = TRUE;
		pDY3->oNGPicker4Down = FALSE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_19) {
		if (pDX2->i_IndexAlignNG_In && pCommon->Check_Position(AX_NG_PICKER_X, 0) && pDX3->iNGPicker4CMCheck) {
			AfxMessageBox(_T("Can not move......(NG Picker4 CM Check And Align 2 In)"));
			return;
		}
		if((!pDX3->iNGPicker4Open && !pDX3->iNGPicker4CMCheck) ) {
			AfxMessageBox(_T("Can not move......(NG Picker4 Close And CM Check Off)"));
			return;
		}

		pDY3->oNGPicker4Up = FALSE;
		pDY3->oNGPicker4Down = TRUE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_20) {
		pDY3->oNGPicker5Open = TRUE;
		pDY3->oNGPicker5Close = FALSE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_21) {
		pDY3->oNGPicker5Open = FALSE;
		pDY3->oNGPicker5Close = TRUE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_22) {
		pDY3->oNGPicker5Up = TRUE;
		pDY3->oNGPicker5Down = FALSE;
	} else if (nID == IDC_BTN_NG_PICKER_IO1_23) {
		if (pDX2->i_IndexAlignNG_In && pCommon->Check_Position(AX_NG_PICKER_X, 0) && pDX3->iNGPicker5CMCheck) {
			AfxMessageBox(_T("Can not move......(NG Picker5 CM Check And Align 2 In)"));
			return;
		}
		if((!pDX3->iNGPicker5Open && !pDX3->iNGPicker5CMCheck) ) {
			AfxMessageBox(_T("Can not move......(NG Picker5 Close And CM Check Off)"));
			return;
		}

		pDY3->oNGPicker5Up = FALSE;
		pDY3->oNGPicker5Down = TRUE;
	}

	pAJinAXL->Write_Output(3);

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnNGPickIOClick.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}

void CManual_Good_Ng_PickerDlg::OnBtnPicker1Click(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_2 *pDX2 = pAJinAXL->Get_pDX2();
	DX_DATA_4 *pDX4 = pAJinAXL->Get_pDX4();

	CCommon *pCommon = CCommon::Get_Instance();
	if (!pCommon->Check_MainDoor()) return;

	DY_DATA_4 *pDY4 = pAJinAXL->Get_pDY4();
	
	if (nID == IDC_BTN_GOOD_PICKER1_0) {			// Picker1 Up
		pDY4->oGoodPicker1Down = FALSE;
		pDY4->oGoodPicker1Up = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER1_1) {		// Picker1 Down
		if (pDX2->i_IndexAlignGood_In && pDX4->iGoodPicker1CMCheck) {
			AfxMessageBox(_T("Can not move......(Good Picker1 CM Check And Align 3 In)"));
			return;
		}
		if((!pDX4->iGoodPicker1Open && !pDX4->iGoodPicker1CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Good Picker1 Close And CM Check Off)"));
			return;
		}

		pDY4->oGoodPicker1Up = FALSE;
		pDY4->oGoodPicker1Down = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER1_2) {	    // Grip Open
		pDY4->oGoodPicker1Close = FALSE;
		pDY4->oGoodPicker1Open = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER1_3){      // Grip Close
		pDY4->oGoodPicker1Open = FALSE;
		pDY4->oGoodPicker1Close = TRUE;
	}

	pAJinAXL->Write_Output(4);

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnPicker1Click.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}

void CManual_Good_Ng_PickerDlg::OnBtnPicker2Click(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_2 *pDX2 = pAJinAXL->Get_pDX2();
	DX_DATA_4 *pDX4 = pAJinAXL->Get_pDX4();

	CCommon *pCommon = CCommon::Get_Instance();
	if (!pCommon->Check_MainDoor()) return;

	DY_DATA_4 *pDY4 = pAJinAXL->Get_pDY4();
	
	if (nID == IDC_BTN_GOOD_PICKER2_0) {			// Picker1 Up
		pDY4->oGoodPicker2Down = FALSE;
		pDY4->oGoodPicker2Up = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER2_1) {		// Picker1 Down
		if (pDX2->i_IndexAlignGood_In && pDX4->iGoodPicker2CMCheck) {
			AfxMessageBox(_T("Can not move......(Good Picker2 CM Check And Align 3 In)"));
			return;
		}
		if((!pDX4->iGoodPicker2Open && !pDX4->iGoodPicker2CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Good Picker2 Close And CM Check Off)"));
			return;
		}

		pDY4->oGoodPicker2Up = FALSE;
		pDY4->oGoodPicker2Down = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER2_2) {	    // Grip Open
		pDY4->oGoodPicker2Close = FALSE;
		pDY4->oGoodPicker2Open = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER2_3){      // Grip Close
		pDY4->oGoodPicker2Open = FALSE;
		pDY4->oGoodPicker2Close = TRUE;
	}

	pAJinAXL->Write_Output(4);

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnPicker2Click.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}

void CManual_Good_Ng_PickerDlg::OnBtnPicker3Click(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_2 *pDX2 = pAJinAXL->Get_pDX2();
	DX_DATA_4 *pDX4 = pAJinAXL->Get_pDX4();

	CCommon *pCommon = CCommon::Get_Instance();
	if (!pCommon->Check_MainDoor()) return;

	DY_DATA_4 *pDY4 = pAJinAXL->Get_pDY4();
	
	if (nID == IDC_BTN_GOOD_PICKER3_0) {			// Picker1 Up
		pDY4->oGoodPicker3Down = FALSE;
		pDY4->oGoodPicker3Up = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER3_1) {		// Picker1 Down
		if (pDX2->i_IndexAlignGood_In && pDX4->iGoodPicker3CMCheck) {
			AfxMessageBox(_T("Can not move......(Good Picker3 CM Check And Align 3 In)"));
			return;
		}
		if((!pDX4->iGoodPicker3Open && !pDX4->iGoodPicker3CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Good Picker3 Close And CM Check Off)"));
			return;
		}

		pDY4->oGoodPicker3Up = FALSE;
		pDY4->oGoodPicker3Down = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER3_2) {	    // Grip Open
		pDY4->oGoodPicker3Close = FALSE;
		pDY4->oGoodPicker3Open = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER3_3){      // Grip Close
		pDY4->oGoodPicker3Open = FALSE;
		pDY4->oGoodPicker3Close = TRUE;
	}

	pAJinAXL->Write_Output(4);

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnPicker3Click.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}

void CManual_Good_Ng_PickerDlg::OnBtnPicker4Click(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_2 *pDX2 = pAJinAXL->Get_pDX2();
	DX_DATA_4 *pDX4 = pAJinAXL->Get_pDX4();

	CCommon *pCommon = CCommon::Get_Instance();
	if (!pCommon->Check_MainDoor()) return;

	DY_DATA_4 *pDY4 = pAJinAXL->Get_pDY4();
	
	if (nID == IDC_BTN_GOOD_PICKER4_0) {			// Picker1 Up
		pDY4->oGoodPicker4Down = FALSE;
		pDY4->oGoodPicker4Up = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER4_1) {		// Picker1 Down
		if (pDX2->i_IndexAlignGood_In && pDX4->iGoodPicker4CMCheck) {
			AfxMessageBox(_T("Can not move......(Good Picker4 CM Check And Align 3 In)"));
			return;
		}
		if((!pDX4->iGoodPicker4Open && !pDX4->iGoodPicker4CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Good Picker4 Close And CM Check Off)"));
			return;
		}

		pDY4->oGoodPicker4Up = FALSE;
		pDY4->oGoodPicker4Down = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER4_2) {	    // Grip Open
		pDY4->oGoodPicker4Close = FALSE;
		pDY4->oGoodPicker4Open = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER4_3){      // Grip Close
		pDY4->oGoodPicker4Open = FALSE;
		pDY4->oGoodPicker4Close = TRUE;
	}

	pAJinAXL->Write_Output(4);

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnPicker4Click.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}

void CManual_Good_Ng_PickerDlg::OnBtnPicker5Click(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_2 *pDX2 = pAJinAXL->Get_pDX2();
	DX_DATA_4 *pDX4 = pAJinAXL->Get_pDX4();

	CCommon *pCommon = CCommon::Get_Instance();
	if (!pCommon->Check_MainDoor()) return;

	DY_DATA_4 *pDY4 = pAJinAXL->Get_pDY4();
	
	if (nID == IDC_BTN_GOOD_PICKER5_0) {			// Picker1 Up
		pDY4->oGoodPicker5Down = FALSE;
		pDY4->oGoodPicker5Up = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER5_1) {		// Picker1 Down
		if (pDX2->i_IndexAlignGood_In && pDX4->iGoodPicker5CMCheck) {
			AfxMessageBox(_T("Can not move......(Good Picker5 CM Check And Align 3 In)"));
			return;
		}
		if((!pDX4->iGoodPicker5Open && !pDX4->iGoodPicker5CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Good Picker5 Close And CM Check Off)"));
			return;
		}

		pDY4->oGoodPicker5Up = FALSE;
		pDY4->oGoodPicker5Down = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER5_2) {	    // Grip Open
		pDY4->oGoodPicker5Close = FALSE;
		pDY4->oGoodPicker5Open = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER5_3){      // Grip Close
		pDY4->oGoodPicker5Open = FALSE;
		pDY4->oGoodPicker5Close = TRUE;
	}

	pAJinAXL->Write_Output(4);

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnPicker5Click.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}

void CManual_Good_Ng_PickerDlg::OnBtnPicker6Click(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_2 *pDX2 = pAJinAXL->Get_pDX2();
	DX_DATA_4 *pDX4 = pAJinAXL->Get_pDX4();

	CCommon *pCommon = CCommon::Get_Instance();
	if (!pCommon->Check_MainDoor()) return;

	DY_DATA_4 *pDY4 = pAJinAXL->Get_pDY4();
	
	if (nID == IDC_BTN_GOOD_PICKER6_0) {			// Picker1 Up
		pDY4->oGoodPicker6Down = FALSE;
		pDY4->oGoodPicker6Up = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER6_1) {		// Picker1 Down
		if (pDX2->i_IndexAlignGood_In && pDX4->iGoodPicker6CMCheck) {
			AfxMessageBox(_T("Can not move......(Good Picker6 CM Check And Align 3 In)"));
			return;
		}
		if((!pDX4->iGoodPicker6Open && !pDX4->iGoodPicker6CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Good Picker6 Close And CM Check Off)"));
			return;
		}

		pDY4->oGoodPicker6Up = FALSE;
		pDY4->oGoodPicker6Down = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER6_2) {	    // Grip Open
		pDY4->oGoodPicker6Close = FALSE;
		pDY4->oGoodPicker6Open = TRUE;
	} else if (nID == IDC_BTN_GOOD_PICKER6_3){      // Grip Close
		pDY4->oGoodPicker6Open = FALSE;
		pDY4->oGoodPicker6Close = TRUE;
	}

	pAJinAXL->Write_Output(4);

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnPicker6Click.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}

void CManual_Good_Ng_PickerDlg::OnBtnPickerAClick(UINT nID)
{
	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_2 *pDX2 = pAJinAXL->Get_pDX2();
	DX_DATA_4 *pDX4 = pAJinAXL->Get_pDX4();

	CCommon *pCommon = CCommon::Get_Instance();
	if (!pCommon->Check_MainDoor()) return;

	DY_DATA_4 *pDY4 = pAJinAXL->Get_pDY4();
	
	if (nID == IDC_BTN_GOOD_PICKER_0) {			// Picker1 Up
		pDY4->oGoodPicker1Down = FALSE;
		pDY4->oGoodPicker1Up = TRUE;
		pDY4->oGoodPicker2Down = FALSE;
		pDY4->oGoodPicker2Up = TRUE;
		pDY4->oGoodPicker3Down = FALSE;
		pDY4->oGoodPicker3Up = TRUE;
#ifdef PICKER_5
		pDY4->oGoodPicker4Down = FALSE;
		pDY4->oGoodPicker4Up = TRUE;
		pDY4->oGoodPicker5Down = FALSE;
		pDY4->oGoodPicker5Up = TRUE;
#endif
#ifdef PICKER_6
		pDY4->oGoodPicker4Down = FALSE;
		pDY4->oGoodPicker4Up = TRUE;
		pDY4->oGoodPicker5Down = FALSE;
		pDY4->oGoodPicker5Up = TRUE;
		pDY4->oGoodPicker6Down = FALSE;
		pDY4->oGoodPicker6Up = TRUE;
#endif
	} else if (nID == IDC_BTN_GOOD_PICKER_1) {		// Picker1 Down
#ifdef PICKER_3
		if (pDX2->i_IndexAlignGood_In &&
		   (pDX4->iGoodPicker1CMCheck || pDX4->iGoodPicker2CMCheck || pDX4->iGoodPicker3CMCheck)) {
			AfxMessageBox(_T("Can not move......(Good Picker CM Check And Align 3 In)"));
			return;
		}
		if((!pDX4->iGoodPicker1Open && !pDX4->iGoodPicker1CMCheck) || (!pDX4->iGoodPicker2Open && !pDX4->iGoodPicker2CMCheck) || (!pDX4->iGoodPicker3Open && !pDX4->iGoodPicker3CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Good Picker Close And CM Check Off)"));
			return;
		}
#endif
#ifdef PICKER_5
		if (pDX2->i_IndexAlignGood_In &&
		   (pDX4->iGoodPicker1CMCheck || pDX4->iGoodPicker2CMCheck || pDX4->iGoodPicker3CMCheck || pDX4->iGoodPicker4CMCheck || pDX4->iGoodPicker5CMCheck)) {
			AfxMessageBox(_T("Can not move......(Good Picker CM Check And Align 3 In)"));
			return;
		}
		if((!pDX4->iGoodPicker1Open && !pDX4->iGoodPicker1CMCheck) || (!pDX4->iGoodPicker2Open && !pDX4->iGoodPicker2CMCheck) || (!pDX4->iGoodPicker3Open && !pDX4->iGoodPicker3CMCheck) ||
		   (!pDX4->iGoodPicker4Open && !pDX4->iGoodPicker4CMCheck) || (!pDX4->iGoodPicker5Open && !pDX4->iGoodPicker5CMCheck) ) {
			AfxMessageBox(_T("Can not move......(Good Picker Close And CM Check Off)"));
			return;
		}
#endif
#ifdef PICKER_6
		if (pDX2->i_IndexAlignGood_In &&
			(pDX4->iGoodPicker1CMCheck || pDX4->iGoodPicker2CMCheck || pDX4->iGoodPicker3CMCheck || pDX4->iGoodPicker4CMCheck || pDX4->iGoodPicker5CMCheck || pDX4->iGoodPicker6CMCheck)) {
				AfxMessageBox(_T("Can not move......(Good Picker CM Check And Align 3 In)"));
				return;
		}
		if((!pDX4->iGoodPicker1Open && !pDX4->iGoodPicker1CMCheck) || (!pDX4->iGoodPicker2Open && !pDX4->iGoodPicker2CMCheck) || (!pDX4->iGoodPicker3Open && !pDX4->iGoodPicker3CMCheck) ||
			(!pDX4->iGoodPicker4Open && !pDX4->iGoodPicker4CMCheck) || (!pDX4->iGoodPicker5Open && !pDX4->iGoodPicker5CMCheck) || (!pDX4->iGoodPicker6Open && !pDX4->iGoodPicker6CMCheck)) {
				AfxMessageBox(_T("Can not move......(Good Picker Close And CM Check Off)"));
				return;
		}
#endif

		pDY4->oGoodPicker1Up = FALSE;
		pDY4->oGoodPicker1Down = TRUE;
		pDY4->oGoodPicker2Up = FALSE;
		pDY4->oGoodPicker2Down = TRUE;
		pDY4->oGoodPicker3Up = FALSE;
		pDY4->oGoodPicker3Down = TRUE;
#ifdef PICKER_5
		pDY4->oGoodPicker4Up = FALSE;
		pDY4->oGoodPicker4Down = TRUE;
		pDY4->oGoodPicker5Up = FALSE;
		pDY4->oGoodPicker5Down = TRUE;
#endif
#ifdef PICKER_6
		pDY4->oGoodPicker4Up = FALSE;
		pDY4->oGoodPicker4Down = TRUE;
		pDY4->oGoodPicker5Up = FALSE;
		pDY4->oGoodPicker5Down = TRUE;
		pDY4->oGoodPicker6Up = FALSE;
		pDY4->oGoodPicker6Down = TRUE;
#endif
	} else if (nID == IDC_BTN_GOOD_PICKER_2) {	    // Grip Open
		pDY4->oGoodPicker1Close = FALSE;
		pDY4->oGoodPicker1Open = TRUE;
		pDY4->oGoodPicker2Close = FALSE;
		pDY4->oGoodPicker2Open = TRUE;
		pDY4->oGoodPicker3Close = FALSE;
		pDY4->oGoodPicker3Open = TRUE;
#ifdef PICKER_5
		pDY4->oGoodPicker4Close = FALSE;
		pDY4->oGoodPicker4Open = TRUE;
		pDY4->oGoodPicker5Close = FALSE;
		pDY4->oGoodPicker5Open = TRUE;
#endif
#ifdef PICKER_6
		pDY4->oGoodPicker4Close = FALSE;
		pDY4->oGoodPicker4Open = TRUE;
		pDY4->oGoodPicker5Close = FALSE;
		pDY4->oGoodPicker5Open = TRUE;
		pDY4->oGoodPicker6Close = FALSE;
		pDY4->oGoodPicker6Open = TRUE;
#endif
	} else if (nID == IDC_BTN_GOOD_PICKER_3){      // Grip Close
		pDY4->oGoodPicker1Open = FALSE;
		pDY4->oGoodPicker1Close = TRUE;
		pDY4->oGoodPicker2Open = FALSE;
		pDY4->oGoodPicker2Close = TRUE;
		pDY4->oGoodPicker3Open = FALSE;
		pDY4->oGoodPicker3Close = TRUE;
#ifdef PICKER_5
		pDY4->oGoodPicker4Open = FALSE;
		pDY4->oGoodPicker4Close = TRUE;
		pDY4->oGoodPicker5Open = FALSE;
		pDY4->oGoodPicker5Close = TRUE;
#endif
#ifdef PICKER_6
		pDY4->oGoodPicker4Open = FALSE;
		pDY4->oGoodPicker4Close = TRUE;
		pDY4->oGoodPicker5Open = FALSE;
		pDY4->oGoodPicker5Close = TRUE;
		pDY4->oGoodPicker6Open = FALSE;
		pDY4->oGoodPicker6Close = TRUE;
#endif
	}

	pAJinAXL->Write_Output(4);

	CString sLog;
	CLogFile *pLogFile = CLogFile::Get_Instance();
	sLog.Format("[Manual Mode] CManual_Good_Ng_PickerDlg.OnBtnPickerAClick.  LotID[%s] CM[%d] Data[%d]", gData.sLotID, gData.nCMJobCount, nID);
	pLogFile->Save_HandlerLog(sLog);
}


///////////////////////////////////////////////////////////////////////////////
// User Functions

void CManual_Good_Ng_PickerDlg::Initial_Controls() 
{

	for (int i = 1; i < 5; i++) m_stcAxisPos[i].Init_Ctrl("바탕", 11, TRUE, RGB(0xFF, 0xFF, 0xFF), RGB(0x00, 0x10, 0xB0));
/*
	for (int i = 0; i < 3; i++) m_btnGoodPickerX[i].Init_Ctrl("바탕", 11, TRUE, COLOR_DEFAULT, COLOR_DEFAULT, 0, 0);
	for (int i = 0; i < 5; i++) m_btnGoodPickerY[i].Init_Ctrl("바탕", 11, TRUE, COLOR_DEFAULT, COLOR_DEFAULT, 0, 0);
	for (int i = 0; i < 2; i++) m_btnGoodPickerZ[i].Init_Ctrl("바탕", 11, TRUE, COLOR_DEFAULT, COLOR_DEFAULT, 0, 0);

	for (int i = 0; i < 4; i++) m_btnGoodPicker1[i].Init_Ctrl("바탕", 11, TRUE, COLOR_DEFAULT, COLOR_DEFAULT, 0, 0);
	for (int i = 0; i < 4; i++) m_btnGoodPicker2[i].Init_Ctrl("바탕", 11, TRUE, COLOR_DEFAULT, COLOR_DEFAULT, 0, 0);
	for (int i = 0; i < 4; i++) m_btnGoodPicker3[i].Init_Ctrl("바탕", 11, TRUE, COLOR_DEFAULT, COLOR_DEFAULT, 0, 0);
	for (int i = 0; i < 4; i++) m_btnGoodPicker4[i].Init_Ctrl("바탕", 11, TRUE, COLOR_DEFAULT, COLOR_DEFAULT, 0, 0);
	for (int i = 0; i < 4; i++) m_btnGoodPicker5[i].Init_Ctrl("바탕", 11, TRUE, COLOR_DEFAULT, COLOR_DEFAULT, 0, 0);
	for (int i = 0; i < 4; i++) m_btnGoodPicker6[i].Init_Ctrl("바탕", 11, TRUE, COLOR_DEFAULT, COLOR_DEFAULT, 0, 0);
*/
	for (int i = 0; i < 5; i++) m_ledGoogPick1IO[i].Init_Ctrl("바탕", 11, FALSE, COLOR_DEFAULT, COLOR_DEFAULT, CLedCS::emGreen, CLedCS::em16);
	for (int i = 0; i < 5; i++) m_ledGoogPick2IO[i].Init_Ctrl("바탕", 11, FALSE, COLOR_DEFAULT, COLOR_DEFAULT, CLedCS::emGreen, CLedCS::em16);
	for (int i = 0; i < 5; i++) m_ledGoogPick3IO[i].Init_Ctrl("바탕", 11, FALSE, COLOR_DEFAULT, COLOR_DEFAULT, CLedCS::emGreen, CLedCS::em16);
	for (int i = 0; i < 5; i++) m_ledGoogPick4IO[i].Init_Ctrl("바탕", 11, FALSE, COLOR_DEFAULT, COLOR_DEFAULT, CLedCS::emGreen, CLedCS::em16);
	for (int i = 0; i < 5; i++) m_ledGoogPick5IO[i].Init_Ctrl("바탕", 11, FALSE, COLOR_DEFAULT, COLOR_DEFAULT, CLedCS::emGreen, CLedCS::em16);
	for (int i = 0; i < 5; i++) m_ledGoogPick6IO[i].Init_Ctrl("바탕", 11, FALSE, COLOR_DEFAULT, COLOR_DEFAULT, CLedCS::emGreen, CLedCS::em16);

	for (int i = 0; i < 20; i++) m_ledNGPickIO[i].Init_Ctrl("바탕", 11, FALSE, COLOR_DEFAULT, COLOR_DEFAULT, CLedCS::emGreen, CLedCS::em16);

#ifdef NG_PICKER_3
	for (int i = 16; i < 20; i++) { m_ledNGPickIO[i].ShowWindow(FALSE); }
	for (int i = 20; i < 24; i++) { m_btnNGPickIO[i].ShowWindow(FALSE); }
	m_btnNGPickX[4].ShowWindow(FALSE);
	m_btnNGPickX[5].ShowWindow(FALSE);
#endif
}

void CManual_Good_Ng_PickerDlg::Display_Status()
{

	CAJinAXL *pAJinAXL = CAJinAXL::Get_Instance();
	DX_DATA_3 *pDX3 = pAJinAXL->Get_pDX3();
	DX_DATA_4 *pDX4 = pAJinAXL->Get_pDX4();

	CString strPos;
	AXIS_STATUS *pStatus = pAJinAXL->Get_pStatus(AX_GOOD_PICKER_Y);
	strPos.Format("%0.3lf", pStatus->dPos);
	m_stcAxisPos[1].SetWindowText(strPos);

	pStatus = pAJinAXL->Get_pStatus(AX_GOOD_PICKER_Z);
	strPos.Format("%0.3lf", pStatus->dPos);
	m_stcAxisPos[2].SetWindowText(strPos);

	pStatus = pAJinAXL->Get_pStatus(AX_NG_PICKER_X);
	strPos.Format("%0.3lf", pStatus->dPos);
	m_stcAxisPos[3].SetWindowText(strPos);

	pStatus = pAJinAXL->Get_pStatus(AX_NG_PICKER_Z);
	strPos.Format("%0.3lf", pStatus->dPos);
	m_stcAxisPos[4].SetWindowText(strPos);
	

	//Picker 1
	if (pDX4->iGoodPicker1Up) m_ledGoogPick1IO[0].Set_On(TRUE);
	else m_ledGoogPick1IO[0].Set_On(FALSE);

	if (pDX4->iGoodPicker1Down) m_ledGoogPick1IO[1].Set_On(TRUE);
	else m_ledGoogPick1IO[1].Set_On(FALSE);

	if (pDX4->iGoodPicker1Open) m_ledGoogPick1IO[2].Set_On(TRUE);
	else m_ledGoogPick1IO[2].Set_On(FALSE);

	if (pDX4->iGoodPicker1CMCheck) m_ledGoogPick1IO[4].Set_On(TRUE);
	else m_ledGoogPick1IO[4].Set_On(FALSE);


	//Picker 2
	if (pDX4->iGoodPicker2Up) m_ledGoogPick2IO[0].Set_On(TRUE);
	else m_ledGoogPick2IO[0].Set_On(FALSE);

	if (pDX4->iGoodPicker2Down) m_ledGoogPick2IO[1].Set_On(TRUE);
	else m_ledGoogPick2IO[1].Set_On(FALSE);

	if (pDX4->iGoodPicker2Open) m_ledGoogPick2IO[2].Set_On(TRUE);
	else m_ledGoogPick2IO[2].Set_On(FALSE);

	if (pDX4->iGoodPicker2CMCheck) m_ledGoogPick2IO[4].Set_On(TRUE);
	else m_ledGoogPick2IO[4].Set_On(FALSE);


	//Picker 3
	if (pDX4->iGoodPicker3Up) m_ledGoogPick3IO[0].Set_On(TRUE);
	else m_ledGoogPick3IO[0].Set_On(FALSE);

	if (pDX4->iGoodPicker3Down) m_ledGoogPick3IO[1].Set_On(TRUE);
	else m_ledGoogPick3IO[1].Set_On(FALSE);

	if (pDX4->iGoodPicker3Open) m_ledGoogPick3IO[2].Set_On(TRUE);
	else m_ledGoogPick3IO[2].Set_On(FALSE);

	if (pDX4->iGoodPicker3CMCheck) m_ledGoogPick3IO[4].Set_On(TRUE);
	else m_ledGoogPick3IO[4].Set_On(FALSE);


	//Picker 4
	if (pDX4->iGoodPicker4Up) m_ledGoogPick4IO[0].Set_On(TRUE);
	else m_ledGoogPick4IO[0].Set_On(FALSE);

	if (pDX4->iGoodPicker4Down) m_ledGoogPick4IO[1].Set_On(TRUE);
	else m_ledGoogPick4IO[1].Set_On(FALSE);

	if (pDX4->iGoodPicker4Open) m_ledGoogPick4IO[2].Set_On(TRUE);
	else m_ledGoogPick4IO[2].Set_On(FALSE);

	if (pDX4->iGoodPicker4CMCheck) m_ledGoogPick4IO[4].Set_On(TRUE);
	else m_ledGoogPick4IO[4].Set_On(FALSE);


	//Picker 5
	if (pDX4->iGoodPicker5Up) m_ledGoogPick5IO[0].Set_On(TRUE);
	else m_ledGoogPick5IO[0].Set_On(FALSE);

	if (pDX4->iGoodPicker5Down) m_ledGoogPick5IO[1].Set_On(TRUE);
	else m_ledGoogPick5IO[1].Set_On(FALSE);

	if (pDX4->iGoodPicker5Open) m_ledGoogPick5IO[2].Set_On(TRUE);
	else m_ledGoogPick5IO[2].Set_On(FALSE);

	if (pDX4->iGoodPicker5CMCheck) m_ledGoogPick5IO[4].Set_On(TRUE);
	else m_ledGoogPick5IO[4].Set_On(FALSE);


	//Picker 6
	if (pDX4->iGoodPicker6Up) m_ledGoogPick6IO[0].Set_On(TRUE);
	else m_ledGoogPick6IO[0].Set_On(FALSE);

	if (pDX4->iGoodPicker6Down) m_ledGoogPick6IO[1].Set_On(TRUE);
	else m_ledGoogPick6IO[1].Set_On(FALSE);

	if (pDX4->iGoodPicker6Open) m_ledGoogPick6IO[2].Set_On(TRUE);
	else m_ledGoogPick6IO[2].Set_On(FALSE);

	if (pDX4->iGoodPicker6CMCheck) m_ledGoogPick6IO[4].Set_On(TRUE);
	else m_ledGoogPick6IO[4].Set_On(FALSE);


	if (pDX3->iNGPicker1Open) m_ledNGPickIO[0].Set_On(TRUE);
	else m_ledNGPickIO[0].Set_On(FALSE);
	if (pDX3->iNGPicker1Up) m_ledNGPickIO[1].Set_On(TRUE);
	else m_ledNGPickIO[1].Set_On(FALSE);
	if (pDX3->iNGPicker1Down) m_ledNGPickIO[2].Set_On(TRUE);
	else m_ledNGPickIO[2].Set_On(FALSE);
	if (pDX3->iNGPicker1CMCheck) m_ledNGPickIO[3].Set_On(TRUE);
	else m_ledNGPickIO[3].Set_On(FALSE);
	if (pDX3->iNGPicker2Open) m_ledNGPickIO[4].Set_On(TRUE);
	else m_ledNGPickIO[4].Set_On(FALSE);
	if (pDX3->iNGPicker2Up) m_ledNGPickIO[5].Set_On(TRUE);
	else m_ledNGPickIO[5].Set_On(FALSE);
	if (pDX3->iNGPicker2Down) m_ledNGPickIO[6].Set_On(TRUE);
	else m_ledNGPickIO[6].Set_On(FALSE);
	if (pDX3->iNGPicker2CMCheck) m_ledNGPickIO[7].Set_On(TRUE);
	else m_ledNGPickIO[7].Set_On(FALSE);
	if (pDX3->iNGPicker3Open) m_ledNGPickIO[8].Set_On(TRUE);
	else m_ledNGPickIO[8].Set_On(FALSE);
	if (pDX3->iNGPicker3Up) m_ledNGPickIO[9].Set_On(TRUE);
	else m_ledNGPickIO[9].Set_On(FALSE);
	if (pDX3->iNGPicker3Down) m_ledNGPickIO[10].Set_On(TRUE);
	else m_ledNGPickIO[10].Set_On(FALSE);
	if (pDX3->iNGPicker3CMCheck) m_ledNGPickIO[11].Set_On(TRUE);
	else m_ledNGPickIO[11].Set_On(FALSE);
	if (pDX3->iNGPicker4Open) m_ledNGPickIO[12].Set_On(TRUE);
	else m_ledNGPickIO[12].Set_On(FALSE);
	if (pDX3->iNGPicker4Up) m_ledNGPickIO[13].Set_On(TRUE);
	else m_ledNGPickIO[13].Set_On(FALSE);
	if (pDX3->iNGPicker4Down) m_ledNGPickIO[14].Set_On(TRUE);
	else m_ledNGPickIO[14].Set_On(FALSE);
	if (pDX3->iNGPicker4CMCheck) m_ledNGPickIO[15].Set_On(TRUE);
	else m_ledNGPickIO[15].Set_On(FALSE);
	if (pDX3->iNGPicker5Open) m_ledNGPickIO[16].Set_On(TRUE);
	else m_ledNGPickIO[16].Set_On(FALSE);
	if (pDX3->iNGPicker5Up) m_ledNGPickIO[17].Set_On(TRUE);
	else m_ledNGPickIO[17].Set_On(FALSE);
	if (pDX3->iNGPicker5Down) m_ledNGPickIO[18].Set_On(TRUE);
	else m_ledNGPickIO[18].Set_On(FALSE);
	if (pDX3->iNGPicker5CMCheck) m_ledNGPickIO[19].Set_On(TRUE);
	else m_ledNGPickIO[19].Set_On(FALSE);

	CDataManager *pDataManager = CDataManager::Get_Instance();
	EQUIP_DATA *pEquipData = pDataManager->Get_pEquipData();
	BOOL bShow = FALSE;

	if (pEquipData->bUseManagerMode) bShow = TRUE;
	for(int i=0; i<2; i++) {
//		m_btnGoodPickerX[i].ShowWindow(bShow);
		m_btnGoodPickerAll[i].ShowWindow(bShow);
		m_btnGoodPickerZ[i].ShowWindow(bShow);
		m_btnNGPickZ[i].ShowWindow(bShow);
	}
	for(int i=0; i<gData.nPickCnt; i++) {
		m_btnGoodPickerY[i].ShowWindow(bShow);
	}
#ifdef NG_PICKER_3
	for(int i=0; i<4; i++) {
		m_btnNGPickX[i].ShowWindow(bShow);
	}
#else
	for(int i=0; i<6; i++) {
		m_btnNGPickX[i].ShowWindow(bShow);
	}
#endif
	m_btnNGPickIO[14].ShowWindow(bShow);
	m_btnNGPickIO[15].ShowWindow(bShow);
}

///////////////////////////////////////////////////////////////////////////////
