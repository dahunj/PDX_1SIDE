#pragma once


// CFloatingMsgBoxDlg 대화 상자입니다.

class CFloatingMsgBoxDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFloatingMsgBoxDlg)

public:
	CFloatingMsgBoxDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFloatingMsgBoxDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MSG_FLOATING_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

public:
	BOOL m_bDragging;
	CPoint m_ptDragStart;

	CStaticCS	m_stcMsg;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
