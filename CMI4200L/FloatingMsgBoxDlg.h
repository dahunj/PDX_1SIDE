#pragma once


// CFloatingMsgBoxDlg ��ȭ �����Դϴ�.

class CFloatingMsgBoxDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFloatingMsgBoxDlg)

public:
	CFloatingMsgBoxDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFloatingMsgBoxDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MSG_FLOATING_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
