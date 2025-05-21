// FloatingMsgBoxDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CMI4200L.h"
#include "FloatingMsgBoxDlg.h"
#include "afxdialogex.h"


// CFloatingMsgBoxDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFloatingMsgBoxDlg, CDialogEx)

CFloatingMsgBoxDlg::CFloatingMsgBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFloatingMsgBoxDlg::IDD, pParent)
{

}

CFloatingMsgBoxDlg::~CFloatingMsgBoxDlg()
{
}

void CFloatingMsgBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STC_MSG_VISION, m_stcMsg);
}


BEGIN_MESSAGE_MAP(CFloatingMsgBoxDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CFloatingMsgBoxDlg �޽��� ó�����Դϴ�.


BOOL CFloatingMsgBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	m_bDragging = FALSE;

	LONG lStyle = GetWindowLong(m_hWnd, GWL_EXSTYLE);
	lStyle |= WS_EX_LAYERED;
	SetWindowLong(m_hWnd, GWL_EXSTYLE, lStyle);

	SetWindowPos(&wndTop, 0,0,0,0, SWP_NOSIZE);

	// ���� ���� (0 = ��������, 255 = ������)
	SetLayeredWindowAttributes(0, 180, LWA_ALPHA);

	m_stcMsg.Init_Ctrl("����", 30, TRUE, RGB(0xFF, 0x00, 0x00), RGB(0x00, 0x10, 0xC0));

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CFloatingMsgBoxDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_bDragging = TRUE;
	::SetCapture(m_hWnd);

	// ���콺 ��ġ ��� (ȭ�� ���� ��ǥ�� ��ȯ)
	ClientToScreen(&point);
	CRect wndRect;
	GetWindowRect(&wndRect);
	m_ptDragStart = point - wndRect.TopLeft();

	CDialogEx::OnLButtonDown(nFlags, point);

}


void CFloatingMsgBoxDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_bDragging)
	{
		m_bDragging = FALSE;
		::ReleaseCapture();
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CFloatingMsgBoxDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_bDragging)
	{
		ClientToScreen(&point);
		CPoint newTopLeft = point - m_ptDragStart;
		SetWindowPos(nullptr, newTopLeft.x, newTopLeft.y, 0, 0,
			SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE);
	}


	CDialogEx::OnMouseMove(nFlags, point);
}
