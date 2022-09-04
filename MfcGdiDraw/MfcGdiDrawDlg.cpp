#include "pch.h"
#include "framework.h"
#include "MfcGdiDraw.h"
#include "MfcGdiDrawDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMfcGdiDrawDlg::CMfcGdiDrawDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCGDIDRAW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcGdiDrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CMfcGdiDrawDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	return TRUE;
}

BEGIN_MESSAGE_MAP(CMfcGdiDrawDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()

void CMfcGdiDrawDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	if (this->GetSafeHwnd())
	{
		this->DrawObject();
	}
}

HCURSOR CMfcGdiDrawDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMfcGdiDrawDlg::DrawObject()
{
	// デバイスコンテキスト取得
	CDC* pDC = this->GetDC();

	CPen pen;
	CPen* pOldPen;
	CBrush brs;
	CBrush* pOldBrs;
	HGDIOBJ hBrs, hOldBrs;
	COLORREF oldColor;
	int iOldBkMode;
	CFont* pOldFont;

#pragma region 線の描画
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(50, 50);
	pDC->LineTo(150, 50);
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();

	pen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
	pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(200, 50);
	pDC->LineTo(300, 50);
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();

	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(350, 50);
	pDC->LineTo(450, 50);
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
#pragma endregion

#pragma region 矩形の描画
	pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	brs.CreateSolidBrush(RGB(255, 255, 0));
	pOldPen = pDC->SelectObject(&pen);
	pOldBrs = pDC->SelectObject(&brs);
	pDC->Rectangle(CRect(50, 200, 150, 300));
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrs);
	pen.DeleteObject();
	brs.DeleteObject();

	pDC->FillSolidRect(CRect(200, 200, 300, 300), RGB(0, 0, 255));

	pen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	hBrs = ::GetStockObject(NULL_BRUSH);
	pOldPen = pDC->SelectObject(&pen);
	hOldBrs = pDC->SelectObject(hBrs);
	pDC->Rectangle(CRect(350, 200, 450, 300));
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(hOldBrs);
	pen.DeleteObject();
#pragma endregion

#pragma region 角丸矩形の描画
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	brs.CreateSolidBrush(RGB(0, 255, 0));
	pOldPen = pDC->SelectObject(&pen);
	pOldBrs = pDC->SelectObject(&brs);
	pDC->RoundRect(CRect(50, 350, 150, 450), CPoint(20, 20));
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrs);
	pen.DeleteObject();
	brs.DeleteObject();

	pen.CreatePen(PS_NULL, 0, RGB(0, 0, 0));
	brs.CreateSolidBrush(RGB(255, 0, 0));
	pOldPen = pDC->SelectObject(&pen);
	pOldBrs = pDC->SelectObject(&brs);
	pDC->RoundRect(CRect(200, 350, 300, 450), CPoint(20, 20));
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrs);
	pen.DeleteObject();
	brs.DeleteObject();

	pen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	hBrs = ::GetStockObject(NULL_BRUSH);
	pOldPen = pDC->SelectObject(&pen);
	hOldBrs = pDC->SelectObject(hBrs);
	pDC->RoundRect(CRect(350, 350, 450, 450), CPoint(20, 20));
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(hOldBrs);
	pen.DeleteObject();
#pragma endregion

#pragma region 円の描画
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	brs.CreateSolidBrush(RGB(0, 0, 255));
	pOldPen = pDC->SelectObject(&pen);
	pOldBrs = pDC->SelectObject(&brs);
	pDC->Ellipse(CRect(50, 500, 150, 600));
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrs);
	pen.DeleteObject();
	brs.DeleteObject();

	pen.CreatePen(PS_NULL, 0, RGB(0, 0, 0));
	brs.CreateSolidBrush(RGB(0, 255, 127));
	pOldPen = pDC->SelectObject(&pen);
	pOldBrs = pDC->SelectObject(&brs);
	pDC->Ellipse(CRect(200, 500, 300, 600));
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrs);
	pen.DeleteObject();
	brs.DeleteObject();

	pen.CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
	hBrs = ::GetStockObject(NULL_BRUSH);
	pOldPen = pDC->SelectObject(&pen);
	hOldBrs = pDC->SelectObject(hBrs);
	pDC->Ellipse(CRect(350, 500, 450, 600));
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(hOldBrs);
	pen.DeleteObject();
#pragma endregion

#pragma region 文字列の描画
	pDC->FillSolidRect(CRect(50, 650, 150, 700), RGB(255, 255, 0));
	oldColor = pDC->SetTextColor(RGB(255, 0, 0));
	iOldBkMode = pDC->SetBkMode(TRANSPARENT);
	pOldFont = pDC->SelectObject(this->GetFont());
	pDC->DrawText(_T("Draw Text"), CRect(50, 650, 150, 700), DT_LEFT | DT_TOP);
	pDC->SetTextColor(oldColor);
	pDC->SetBkMode(iOldBkMode);
	pDC->SelectObject(pOldFont);

	pDC->FillSolidRect(CRect(200, 650, 300, 700), RGB(255, 255, 0));
	oldColor = pDC->SetTextColor(RGB(0, 0, 255));
	iOldBkMode = pDC->SetBkMode(TRANSPARENT);
	pOldFont = pDC->SelectObject(this->GetFont());
	pDC->DrawText(_T("Draw Text"), CRect(200, 650, 300, 700), DT_RIGHT | DT_SINGLELINE | DT_BOTTOM);
	pDC->SetTextColor(oldColor);
	pDC->SetBkMode(iOldBkMode);
	pDC->SelectObject(pOldFont);

	pDC->FillSolidRect(CRect(350, 650, 450, 700), RGB(255, 255, 0));
	oldColor = pDC->SetTextColor(RGB(255, 0, 255));
	iOldBkMode = pDC->SetBkMode(TRANSPARENT);
	pOldFont = pDC->SelectObject(this->GetFont());
	pDC->DrawText(_T("Draw Text"), CRect(350, 650, 450, 700), DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	pDC->SetTextColor(oldColor);
	pDC->SetBkMode(iOldBkMode);
	pDC->SelectObject(pOldFont);
#pragma endregion


	// デバイスコンテキスト破棄
	this->ReleaseDC(pDC);
}
