/************************************************************************/
/*   ���ﶨ��ؼ������ӿ�,���нӿڶ���IObjRef�̳�,����ָ���Լ��Ľӿ�ID  */
/************************************************************************/
#pragma once
#include <interface/SWindow-i.h>
#include <interface/SSkinobj-i.h>
#include <interface/SRender-i.h>
#include <interface/sstring-i.h>
#include <interface/SAdapter-i.h>
#include <interface/SListViewItemLocator-i.h>
#include <interface/STreeViewItemLocator-i.h>
#include <interface/STileViewItemLocator-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE ICtrl
DECLARE_INTERFACE_(ICtrl, IObjRef)
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IItemPanel
DECLARE_INTERFACE_IID_(IItemPanel, ICtrl, "176CDF98-260E-4070-91B5-E6E163F909A4")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
    STDMETHOD_(LPARAM, GetItemIndex)(THIS) SCONST PURE;
    STDMETHOD_(void, SetSkin)(THIS_ ISkinObj * pSkin) PURE;
    STDMETHOD_(void, SetColor)(THIS_ COLORREF crBk, COLORREF crSelBk) PURE;
    STDMETHOD_(void, SetItemData)(THIS_ LPARAM dwData) PURE;
    STDMETHOD_(LPARAM, GetItemData)(THIS) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IImageWnd
DECLARE_INTERFACE_IID_(IImageWnd, ICtrl, "42148B05-6223-46f6-B903-D42D84038546")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////

    STDMETHOD_(BOOL, SetSkin)
    (THIS_ ISkinObj * pSkin, int iFrame /*= 0*/, BOOL bAutoFree /*= TRUE*/) PURE;

    /**
     * SImageWnd::SetImage
     * @param    IBitmap * pBitmap -- ͼƬ����
     * @param    FilterLevel fl -- FilterLevel
     * @return   void
     *
     * Describe  ���û���ͼƬ
     */
    STDMETHOD_(void, SetImage)
    (THIS_ IBitmap * pBitmap, FilterLevel fl /*= kNone_FilterLevel*/) PURE;

    STDMETHOD_(IBitmap *, GetImage)(THIS) PURE;

    /**
     * SImageWnd::SetIcon
     * @param    int nSubID -- ��ԴID
     * @brief    ����ͼ��
     * @return   ����ֵBOOL �ɹ�--TRUE ʧ��--FALSE
     *
     * Describe  ����ͼ��
     */
    STDMETHOD_(BOOL, SetIcon)(THIS_ int nSubID) PURE;

    /**
     * SImageWnd::GetSkin
     * @brief    ��ȡ��Դ
     * @return   ����ֵISkinObjָ��
     *
     * Describe  ��ȡ��Դ
     */
    STDMETHOD_(ISkinObj *, GetSkin)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IAnimateImgWnd
DECLARE_INTERFACE_IID_(IAnimateImgWnd, ICtrl, "374A5086-AD38-4f15-83E0-002822E2595A")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
    /**
     * SAnimateImgWnd::Start
     * @brief    ��������
     *
     * Describe  ��������
     */
    STDMETHOD_(void, Start)(THIS) PURE;
    /**
     * SAnimateImgWnd::Stop
     * @brief    ֹͣ����
     *
     * Describe  ֹͣ����
     */
    STDMETHOD_(void, Stop)(THIS) PURE;

    /**
     * SAnimateImgWnd::IsPlaying
     * @brief    �ж϶�������״̬
     * @return   ����ֵ�Ƕ���״̬ TRUE -- ������
     *
     * Describe  �ж϶�������״̬
     */
    STDMETHOD_(BOOL, IsPlaying)(THIS) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IProgress
DECLARE_INTERFACE_IID_(IProgress, ICtrl, "77407E2D-582B-4ef2-A33A-427C933BAA8C")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
    /**
     * SProgress::SetValue
     * @brief    ���ý���������ֵ
     * @param    int nValue  --  ����ֵ
     * @return   ����ֵ�� TRUE -- ���óɹ�
     *
     * Describe  ���ý���������ֵ
     */
    STDMETHOD_(BOOL, SetValue)(THIS_ int nValue) PURE;
    /**
     * SProgress::GetValue
     * @brief    ��ȡ����ֵ
     * @return   ����ֵ��int
     *
     * Describe  ��ȡ����ֵ
     */
    STDMETHOD_(int, GetValue)(THIS) SCONST PURE;

    /**
     * SProgress::SetRange
     * @param    int nMin  --  ������Сֵ
     * @param    int nMax  --  �������ֵ
     * @brief    ���ý���ֵ��С��ֵ
     *
     * Describe  ���ý���ֵ
     */
    STDMETHOD_(void, SetRange)(THIS_ int nMin, int nMax) PURE;
    /**
     * SProgress::GetRange
     * @param    int nMin  --  ������Сֵ
     * @param    int nMax  --  �������ֵ
     * @brief    ��ȡ����ֵ��С��ֵ
     *
     * Describe  ��ȡ����ֵ
     */
    STDMETHOD_(void, GetRange)(THIS_ int *pMin, int *pMax) SCONST PURE;
    /**
     * SProgress::IsVertical
     * @brief    �жϽ������Ƿ�Ϊ��ֱ״̬
     * @return   ����ֵ�� TRUE -- ��ֱ״̬
     *
     * Describe  ��ȡ����ֵ
     */
    STDMETHOD_(BOOL, IsVertical)(THIS) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IPanel
DECLARE_INTERFACE_IID_(IPanel, ICtrl, "B1A97BB7-64BE-408f-AC7C-2197CC2F4DD0")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

    STDMETHOD_(BOOL, IsScrollBarEnable)(THIS_ BOOL bVertical) SCONST PURE;

    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

    STDMETHOD_(int, GetScrollPos)(THIS_ BOOL bVertical) SCONST PURE;

    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

    STDMETHOD_(BOOL, GetScrollRange)
    (THIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;

    STDMETHOD_(BOOL, HasScrollBar)(THIS_ BOOL bVertical) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IScrollView
DECLARE_INTERFACE_IID_(IScrollView, IPanel, "49B024D6-221D-42d4-902B-AFAAC5AFFE41")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
	STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

	STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

	STDMETHOD_(BOOL, IsScrollBarEnable)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

	STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

	STDMETHOD_(int, GetScrollPos)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(BOOL, SetScrollRange)
		(THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

	STDMETHOD_(BOOL, GetScrollRange)
		(THIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;

	STDMETHOD_(BOOL, HasScrollBar)(THIS_ BOOL bVertical) SCONST PURE;
	//////////////////////////////////////////////////////////////////////////

    STDMETHOD_(SIZE, GetViewSize)(THIS) SCONST PURE;

    STDMETHOD_(void, SetViewSize)(THIS_ SIZE szView) PURE;

    STDMETHOD_(POINT, GetViewOrigin)(THIS) SCONST PURE;

    STDMETHOD_(void, SetViewOrigin)(THIS_ POINT pt) PURE;
};

enum
{
    SHDI_WIDTH = 0x0001,
    SHDI_TEXT = 0x0002,
    SHDI_FORMAT = 0x0004,
    SHDI_LPARAM = 0x0008,
    SHDI_ORDER = 0x0010,
    SHDI_VISIBLE = 0x0020,
    SHDI_WEIGHT = 0x0040,
    SHDI_ALL = 0xffff,
};

/**
 * @struct    _SHDITEM
 * @brief     �б�ͷ��
 *
 * Describe   �б�ͷ��
 */
typedef struct SHDITEM
{
    UINT mask;
    int cx;
    UINT fmt;
    UINT state;
    int iOrder;
    LPTSTR pszText;
    int cchMaxText;
    LPARAM lParam;
    BOOL bDpiAware;
    BOOL bVisible;
    float fWeight;
}SHDITEM, * LPSHDITEM;

#undef INTERFACE
#define INTERFACE IHeaderCtrl
DECLARE_INTERFACE_IID_(IHeaderCtrl, ICtrl, "60A8788F-C775-424f-AA82-DCA9CECE3D45")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////

    /**
     * SHeaderCtrl::InsertItem
     * @brief    ��������
     * @param    int iItem --  ��������
     * @param    LPCTSTR pszText  --  �������
     * @param    int nWidth  -- ���
     * @param    BOOL bDpiAware -- dpi aware
     * @param    UINT fmt -- format flag
     * @param    LPARAM lParam -- ���Ӳ���
     * @return   ����int
     *
     * Describe  ��������
     */
    STDMETHOD_(int, InsertItem)
    (THIS_ int iItem, LPCTSTR pszText, int nWidth, UINT fmt, LPARAM lParam,
     BOOL bDpiAware /*=FALSE*/, float fWeight /*=0.0f*/) PURE;

    /**
     * SHeaderCtrl::GetItem
     * @brief    �������
     * @param    int iItem  --  ����
     * @param    SHDITEM *pItem  -- �����б���ṹ
     * @return   ����BOOL
     *
     * Describe  �������
     */
    STDMETHOD_(BOOL, GetItem)(THIS_ int iItem, SHDITEM *pItem) SCONST PURE;

    STDMETHOD_(BOOL, SetItem)(THIS_ int iItem, const SHDITEM *pItem) PURE;

    /**
     * SHeaderCtrl::GetItemCount
     * @brief    ��ȡ�б������
     * @return   ����int
     *
     * Describe  ��ȡ�б������
     */
    STDMETHOD_(UINT, GetItemCount)(THIS) SCONST PURE;
    /**
     * SHeaderCtrl::GetTotalWidth
     * @brief    ������п��
     * @return   ����int
     *
     * Describe  ������п��
     */
    STDMETHOD_(int, GetTotalWidth)(THIS_ BOOL bMinWid /*= FALSE*/) SCONST PURE;

    STDMETHOD_(BOOL, IsAutoResize)(THIS) SCONST PURE;

    /**
     * SHeaderCtrl::GetItemWidth
     * @brief    ���ָ������
     * @param    int iItem  --  ����
     * @return   ����int
     *
     * Describe  �������
     */
    STDMETHOD_(int, GetItemWidth)(THIS_ int iItem) SCONST PURE;

    /**
     * SHeaderCtrl::DeleteItem
     * @brief    ɾ��ָ����
     * @param    int iItem  --  ����
     * @return   ����BOOL
     *
     * Describe  ɾ��ָ����
     */
    STDMETHOD_(BOOL, DeleteItem)(THIS_ int iItem) PURE;

    /**
     * SHeaderCtrl::DeleteAllItems
     * @brief    ɾ��������
     *
     * Describe  �������
     */
    STDMETHOD_(void, DeleteAllItems)(THIS) PURE;

    STDMETHOD_(void, SetItemSort)(THIS_ int iItem, UINT sortFlag) PURE;

    STDMETHOD_(void, SetItemVisible)(THIS_ int iItem, BOOL visible) PURE;

    STDMETHOD_(BOOL, IsItemVisible)(THIS_ int iItem) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IListView
DECLARE_INTERFACE_IID_(IListView, IPanel, "E584B16A-6BDB-4afb-8BCC-3A1ABACD2FE2")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
	STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

	STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

	STDMETHOD_(BOOL, IsScrollBarEnable)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

	STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

	STDMETHOD_(int, GetScrollPos)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(BOOL, SetScrollRange)
		(THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

	STDMETHOD_(BOOL, GetScrollRange)
		(THIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;
	STDMETHOD_(BOOL, HasScrollBar)(THIS_ BOOL bVertical) SCONST PURE;

	//////////////////////////////////////////////////////////////////////////
    STDMETHOD_(BOOL, SetAdapter)(THIS_ ILvAdapter * adapter) PURE;

    STDMETHOD_(ILvAdapter *, GetAdapter)(THIS) SCONST PURE;

    STDMETHOD_(IListViewItemLocator *, GetItemLocator)(THIS) SCONST PURE;

    STDMETHOD_(void, SetItemLocator)(THIS_ IListViewItemLocator * pItemLocator) PURE;

    STDMETHOD_(void, EnsureVisible)(THIS_ int iItem) PURE;

    STDMETHOD_(void, SetSel)(THIS_ int iItem, BOOL bNotify /*= FALSE*/) PURE;

    STDMETHOD_(int, GetSel)(THIS) SCONST PURE;

    STDMETHOD_(IItemPanel *, HitTest)(THIS_ const POINT *pt) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IMcListView
DECLARE_INTERFACE_IID_(IMcListView, IPanel, "E584B16A-6BDB-4afb-8BCC-3A1ABACD2FE2")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
	STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

	STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

	STDMETHOD_(BOOL, IsScrollBarEnable)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

	STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

	STDMETHOD_(int, GetScrollPos)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(BOOL, SetScrollRange)
		(THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

	STDMETHOD_(BOOL, GetScrollRange)
		(THIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;
	STDMETHOD_(BOOL, HasScrollBar)(THIS_ BOOL bVertical) SCONST PURE;
	//////////////////////////////////////////////////////////////////////////
    STDMETHOD_(BOOL, SetAdapter)(THIS_ IMcAdapter * adapter) PURE;

    STDMETHOD_(IMcAdapter *, GetAdapter)(THIS) SCONST PURE;

    STDMETHOD_(IListViewItemLocator *, GetItemLocator)(THIS) SCONST PURE;

    STDMETHOD_(void, SetItemLocator)(THIS_ IListViewItemLocator * pItemLocator) PURE;

    STDMETHOD_(void, EnsureVisible)(THIS_ int iItem) PURE;

    STDMETHOD_(void, SetSel)(THIS_ int iItem, BOOL bNotify /*= FALSE*/) PURE;

    STDMETHOD_(int, GetSel)(THIS) SCONST PURE;

    STDMETHOD_(IItemPanel *, HitTest)(THIS_ const POINT *pt) SCONST PURE;

    STDMETHOD_(IHeaderCtrl *, GetIHeaderCtrl)(THIS) SCONST PURE;

    STDMETHOD_(int, InsertColumn)
    (THIS_ int nIndex, LPCTSTR pszText, int nWidth, UINT fmt, LPARAM lParam /*= 0*/,
     BOOL bDpiAware /*=TRUE*/, float fWeight /*=0.0f*/) PURE;

    STDMETHOD_(void, DeleteColumn)(THIS_ int iCol) PURE;

    STDMETHOD_(int, GetColumnCount)(THIS) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE ITreeView
DECLARE_INTERFACE_IID_(ITreeView, IPanel, "4FB8BF5D-950C-4f05-861C-FBEB119E4C2B")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
	STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

	STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

	STDMETHOD_(BOOL, IsScrollBarEnable)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

	STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

	STDMETHOD_(int, GetScrollPos)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(BOOL, SetScrollRange)
		(THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

	STDMETHOD_(BOOL, GetScrollRange)
		(THIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;
	STDMETHOD_(BOOL, HasScrollBar)(THIS_ BOOL bVertical) SCONST PURE;
	//////////////////////////////////////////////////////////////////////////
    STDMETHOD_(BOOL, SetAdapter)(THIS_ ITvAdapter * adapter) PURE;

    STDMETHOD_(ITvAdapter *, GetAdapter)(THIS) SCONST PURE;

    STDMETHOD_(void, SetItemLocator)(THIS_ ITreeViewItemLocator * pItemLocator) PURE;

    STDMETHOD_(ITreeViewItemLocator *, GetItemLocator)(THIS) SCONST PURE;

    STDMETHOD_(void, SetSel)(THIS_ HSTREEITEM hItem, BOOL bNotify /*= FALSE*/) PURE;

    STDMETHOD_(HSTREEITEM, GetSel)(THIS) SCONST PURE;

    STDMETHOD_(void, EnsureVisible)(THIS_ HSTREEITEM hItem) PURE;

    STDMETHOD_(IItemPanel *, HitTest)(THIS_ const POINT *pt) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE ITileView
DECLARE_INTERFACE_IID_(ITileView, IPanel, "3718C98E-9177-4afb-986F-94B03A78F2C3")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
	STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

	STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

	STDMETHOD_(BOOL, IsScrollBarEnable)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

	STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

	STDMETHOD_(int, GetScrollPos)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(BOOL, SetScrollRange)
		(THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

	STDMETHOD_(BOOL, GetScrollRange)
		(THIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;
	STDMETHOD_(BOOL, HasScrollBar)(THIS_ BOOL bVertical) SCONST PURE;
	//////////////////////////////////////////////////////////////////////////
    STDMETHOD_(BOOL, SetAdapter)(THIS_ ILvAdapter * adapter) PURE;

    STDMETHOD_(ILvAdapter *, GetAdapter)(THIS) SCONST PURE;

    STDMETHOD_(void, SetItemLocator)(THIS_ ITileViewItemLocator * pItemLocator) PURE;

    STDMETHOD_(ITileViewItemLocator *, GetItemLocator)(THIS) SCONST PURE;

    STDMETHOD_(void, SetSel)(THIS_ int iItem, BOOL bNotify /*= FALSE*/) PURE;

    STDMETHOD_(int, GetSel)(THIS) SCONST PURE;

    STDMETHOD_(void, EnsureVisible)(THIS_ int iItem) PURE;

    STDMETHOD_(IItemPanel *, HitTest)(THIS_ const POINT *pt) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IListBox
DECLARE_INTERFACE_IID_(IListBox, IPanel, "4A36DC8A-7378-4a2d-A3AF-D04B0712ACCD")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
	STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

	STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

	STDMETHOD_(BOOL, IsScrollBarEnable)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

	STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

	STDMETHOD_(int, GetScrollPos)(THIS_ BOOL bVertical) SCONST PURE;

	STDMETHOD_(BOOL, SetScrollRange)
		(THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

	STDMETHOD_(BOOL, GetScrollRange)
		(THIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;
	STDMETHOD_(BOOL, HasScrollBar)(THIS_ BOOL bVertical) SCONST PURE;
	//////////////////////////////////////////////////////////////////////////
    /**
     * SListBox::GetCount
     * @brief    ��ȡ�����
     * @return   ����int
     *
     * Describe  ��ȡ�����
     */
    STDMETHOD_(int, GetCount)(THIS) SCONST PURE;

    /**
     * SListBox::GetCurSel
     * @brief    ��ȡ��ǰѡ��������
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ��������
     */
    STDMETHOD_(int, GetCurSel)(THIS) SCONST PURE;

    /**
     * SListBox::SetCurSel
     * @brief    ����ѡ����
     * @param    int nIndex -- ��ѡ������
     *
     * Describe  ����ѡ����
     */
    STDMETHOD_(BOOL, SetCurSel)(THIS_ int nIndex, BOOL bNotifyChange /* = FALSE*/) PURE;

    /**
     * SListBox::GetTopIndex
     * @brief    ��ȡ��һ���ɼ���¼����
     * @return   ����int
     *
     * Describe
     */
    STDMETHOD_(int, GetTopIndex)(THIS) SCONST PURE;

    /**
     * SListBox::SetTopIndex
     * @brief    ���õ�һ���ɼ���¼����
     * @param    int nIndex -- ��һ���ɼ���¼����
     *
     * Describe
     */
    STDMETHOD_(BOOL, SetTopIndex)(THIS_ int nIndex) PURE;

    /**
     * SListBox::GetItemHeight
     * @brief    ��ȡ�߶�
     * @return   ����int
     *
     * Describe  ��ȡ�߶�
     */
    STDMETHOD_(int, GetItemHeight)(THIS) SCONST PURE;

    /**
     * SListBox::SetItemHeight
     * @brief    ����ָ����߶�
     * @param    int cyItemHeight -- �߶�
     * @return   ����
     *
     * Describe  ����ָ����߶�
     */
    STDMETHOD_(void, SetItemHeight)(THIS_ int nItemHeight) PURE;

    /**
     * SListBox::GetItemData
     * @brief    ��ȡ��������
     * @param    int nIndex -- ѡ������
     * @return   ����LPARAM
     *
     * Describe  ��ȡ��������
     */
    STDMETHOD_(LPARAM, GetItemData)(THIS_ int nIndex) SCONST PURE;

    /**
     * SListBox::SetItemData
     * @brief    ����ѡ�������
     * @param    int nIndex -- ѡ������
     * @param    LPARAM lParam  -- ��������
     * @return   ����BOOL
     *
     * Describe  ����ѡ�������
     */
    STDMETHOD_(BOOL, SetItemData)(THIS_ int nIndex, LPARAM lParam) PURE;

    /**
     * SListBox::GetText
     * @brief    ��ȡָ�����ı�
     * @param    int nIndex -- ѡ������
     * @param    BOOL bRawText -- ԭʼ���ݱ�־
     * @return   SStringT,�б����ԭʼ�ַ���
     *
     * Describe  ��ȡָ�����ı�
     */
    STDMETHOD_(BOOL, GetIText)
    (THIS_ int nIndex, BOOL bRawText /*= FALSE*/, IStringT *str) SCONST PURE;

    /**
     * SListBox::DeleteAll
     * @brief    ɾ������
     *
     * Describe  ɾ������
     */
    STDMETHOD_(void, DeleteAll)(THIS) PURE;

    /**
     * SListBox::DeleteString
     * @brief    ����ָ�����ı�
     * @param    int nIndex -- ѡ������
     * @return   ����BOOL
     *
     * Describe  ����ָ�����ı�
     */
    STDMETHOD_(BOOL, DeleteString)(THIS_ int nIndex) PURE;

    /**
     * SListBox::AddString
     * @brief    ����ı�
     * @param    LPCTSTR lpszItem -- �ı�
     * @param    int nImage -- ͼ��
     * @param    LPARAM lParam -- ��������
     * @return   ����int ����
     *
     * Describe  ����ı�
     */
    STDMETHOD_(int, AddString)
    (THIS_ LPCTSTR lpszItem, int nImage /*= -1*/, LPARAM lParam /*= 0*/) PURE;

    /**
     * SListBox::InsertString
     * @brief    �����ı�
     * @param    int nIndex  -- ����
     * @param    LPCTSTR lpszItem -- �ı�
     * @param    int nImage -- ͼ��
     * @param    LPARAM lParam -- ��������
     * @return   ����int ����
     *
     * Describe  ��ĳ������ı�
     */
    STDMETHOD_(int, InsertString)
    (THIS_ int nIndex, LPCTSTR lpszItem, int nImage /*= -1*/, LPARAM lParam /*= 0*/) PURE;

    /**
     * SListBox::EnsureVisible
     * @brief    ����ĳ����ʾ
     * @param    int nIndex  -- ����
     *
     * Describe  ����ĳ����ʾ
     */
    STDMETHOD_(void, EnsureVisible)(THIS_ int nIndex) PURE;

    STDMETHOD_(int, FindString)(THIS_ int iFindAfter, LPCTSTR pszText) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IComboBase
DECLARE_INTERFACE_IID_(IComboBase, ICtrl, "2BF10693-BEBD-4497-B6B5-5380BA8401EC")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
    /**
     * SComboBoxBase::GetCurSel
     * @brief    ��ȡѡ��ֵ����
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ������
     */
    STDMETHOD_(int, GetCurSel)(THIS) SCONST PURE;

    /**
     * SComboBoxBase::GetCount
     * @brief    ��ȡ���������
     * @return   ����int
     *
     * Describe  ��ȡ���������
     */
    STDMETHOD_(int, GetCount)(THIS) SCONST PURE;

    /**
     * SComboBoxBase::SetCurSel
     * @brief    ���õ�ǰѡ��
     * @param    int iSel -- ѡ������
     *
     * Describe  ���õ�ǰѡ��
     */
    STDMETHOD_(BOOL, SetCurSel)(THIS_ int iSel) PURE;

    STDMETHOD_(BOOL, GetItemText)(THIS_ int iItem, BOOL bRawText, IStringT *str) SCONST PURE;

    /**
     * FindString
     * @brief    �����ַ���λ��
     * @param    LPCTSTR pszFind --  ����Ŀ��
     * @param    int nAfter --  ��ʼλ��
     * @return   int -- Ŀ��������ʧ�ܷ���-1��
     * Describe
     */
    STDMETHOD_(int, FindString)
    (THIS_ LPCTSTR pszFind, int nAfter /* = -1*/, BOOL bPartMatch /* = TRUE*/) PURE;

    /**
     * SComboBoxBase::DropDown
     * @brief    �����¼�
     *
     * Describe  �����¼�
     */
    STDMETHOD_(void, DropDown)(THIS) PURE;

    /**
     * SComboBoxBase::CloseUp
     * @brief    �����ر�
     *
     * Describe  �����ر�
     */
    STDMETHOD_(void, CloseUp)(THIS) PURE;

    STDMETHOD_(BOOL, IsDropdown)(THIS) SCONST PURE;

    STDMETHOD_(void, SetDropdown)(THIS_ BOOL bDropdown) PURE;
};

#undef INTERFACE
#define INTERFACE IComboBox
DECLARE_INTERFACE_IID_(IComboBox, IComboBase, "AC6C72BB-51BE-4216-ADA5-B394283DC9CF")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
    /**
     * SComboBoxBase::GetCurSel
     * @brief    ��ȡѡ��ֵ����
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ������
     */
    STDMETHOD_(int, GetCurSel)(THIS) SCONST PURE;

    /**
     * SComboBoxBase::GetCount
     * @brief    ��ȡ���������
     * @return   ����int
     *
     * Describe  ��ȡ���������
     */
    STDMETHOD_(int, GetCount)(THIS) SCONST PURE;

    /**
     * SComboBoxBase::SetCurSel
     * @brief    ���õ�ǰѡ��
     * @param    int iSel -- ѡ������
     *
     * Describe  ���õ�ǰѡ��
     */
    STDMETHOD_(BOOL, SetCurSel)(THIS_ int iSel) PURE;

    STDMETHOD_(BOOL, GetItemText)(THIS_ int iItem, BOOL bRawText, IStringT *str) SCONST PURE;

    /**
     * FindString
     * @brief    �����ַ���λ��
     * @param    LPCTSTR pszFind --  ����Ŀ��
     * @param    int nAfter --  ��ʼλ��
     * @return   int -- Ŀ��������ʧ�ܷ���-1��
     * Describe
     */
    STDMETHOD_(int, FindString)
    (THIS_ LPCTSTR pszFind, int nAfter /* = -1*/, BOOL bPartMatch /* = TRUE*/) PURE;

    /**
     * SComboBoxBase::DropDown
     * @brief    �����¼�
     *
     * Describe  �����¼�
     */
    STDMETHOD_(void, DropDown)(THIS) PURE;

    /**
     * SComboBoxBase::CloseUp
     * @brief    �����ر�
     *
     * Describe  �����ر�
     */
    STDMETHOD_(void, CloseUp)(THIS) PURE;

    STDMETHOD_(BOOL, IsDropdown)(THIS) SCONST PURE;

    STDMETHOD_(void, SetDropdown)(THIS_ BOOL bDropdown) PURE;
	//////////////////////////////////////////////////////////////////////////

    /**
     * SComboBox::GetItemData
     * @brief    ��ȡ��������
     * @param    UINT iItem -- ѡ��ֵ
     *
     * Describe  ��ȡ��������
     */
    STDMETHOD_(LPARAM, GetItemData)(THIS_ UINT iItem) SCONST PURE;

    /**
     * SComboBox::SetItemData
     * @brief    ���ø�������
     * @param    UINT iItem -- ����ֵ
     * @param    LPARAM lParam -- ����ֵ
     *
     * Describe  ���ø�������
     */
    STDMETHOD_(BOOL, SetItemData)(THIS_ UINT iItem, LPARAM lParam) PURE;

    /**
     * SComboBox::InsertItem
     * @brief    ��������
     * @param    UINT iPos -- λ��
     * @param    LPCTSTR pszText -- �ı�ֵ
     * @param    int iIcon -- ͼ��
     * @param    LPARAM lParam -- ����ֵ
     *
     * Describe  ��������
     */
    STDMETHOD_(int, InsertItem)(THIS_ int iPos, LPCTSTR pszText, int iIcon, LPARAM lParam) PURE;
    /**
     * SComboBox::DeleteString
     * @brief    ɾ��ĳһ��
     * @param    UINT iItem -- ����ֵ
     *
     * Describe  ɾ��ĳһ��
     */
    STDMETHOD_(BOOL, DeleteString)(THIS_ int iPos) PURE;
    /**
     * SComboBox::ResetContent
     * @brief    ɾ��������
     *
     * Describe  ���ø�������
     */
    STDMETHOD_(void, ResetContent)(THIS) PURE;

    STDMETHOD_(IListBox *, GetIListBox)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IComboView
DECLARE_INTERFACE_IID_(IComboView, IComboBase, "EADE040E-0D6A-47a3-882F-F70A94FC253D")
{
		STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
    /**
     * SComboBoxBase::GetCurSel
     * @brief    ��ȡѡ��ֵ����
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ������
     */
    STDMETHOD_(int, GetCurSel)(THIS) SCONST PURE;

    /**
     * SComboBoxBase::GetCount
     * @brief    ��ȡ���������
     * @return   ����int
     *
     * Describe  ��ȡ���������
     */
    STDMETHOD_(int, GetCount)(THIS) SCONST PURE;

    /**
     * SComboBoxBase::SetCurSel
     * @brief    ���õ�ǰѡ��
     * @param    int iSel -- ѡ������
     *
     * Describe  ���õ�ǰѡ��
     */
    STDMETHOD_(BOOL, SetCurSel)(THIS_ int iSel) PURE;

    STDMETHOD_(BOOL, GetItemText)(THIS_ int iItem, BOOL bRawText, IStringT *str) SCONST PURE;

    /**
     * FindString
     * @brief    �����ַ���λ��
     * @param    LPCTSTR pszFind --  ����Ŀ��
     * @param    int nAfter --  ��ʼλ��
     * @return   int -- Ŀ��������ʧ�ܷ���-1��
     * Describe
     */
    STDMETHOD_(int, FindString)
    (THIS_ LPCTSTR pszFind, int nAfter /* = -1*/, BOOL bPartMatch /* = TRUE*/) PURE;

    /**
     * SComboBoxBase::DropDown
     * @brief    �����¼�
     *
     * Describe  �����¼�
     */
    STDMETHOD_(void, DropDown)(THIS) PURE;

    /**
     * SComboBoxBase::CloseUp
     * @brief    �����ر�
     *
     * Describe  �����ر�
     */
    STDMETHOD_(void, CloseUp)(THIS) PURE;

    STDMETHOD_(BOOL, IsDropdown)(THIS) SCONST PURE;

    STDMETHOD_(void, SetDropdown)(THIS_ BOOL bDropdown) PURE;
	//////////////////////////////////////////////////////////////////////////
    STDMETHOD_(IListView *, GetIListView)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IDateTimePicker
DECLARE_INTERFACE_IID_(IDateTimePicker, ICtrl, "6DB1EF42-AED7-4a36-8011-BE2AD7B45953")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////

    STDMETHOD_(void, SetTime)
    (THIS_ WORD wYear, WORD wMonth, WORD wDay, WORD wHour, WORD wMinute, WORD wSecond) PURE;
    STDMETHOD_(void, GetTime)
    (THIS_ WORD * wYear, WORD * wMonth, WORD * wDay, WORD * wHour, WORD * wMinute, WORD * wSecond)
        SCONST PURE;
    STDMETHOD_(void, CloseUp)(THIS) PURE;
    STDMETHOD_(void, DropDown)(THIS) PURE;
    STDMETHOD_(void, Clear)(THIS) PURE;
};

typedef int(__cdecl *FunTreeSortCallback)(void *pCtx, const void *phItem1, const void *phItem2);

#undef INTERFACE
#define INTERFACE ITreeCtrl
DECLARE_INTERFACE_IID_(ITreeCtrl, ICtrl, "8FACB4B5-DD66-4755-AFD0-7DA8BB15611A")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////

    STDMETHOD_(HSTREEITEM, InsertItem)
    (THIS_ LPCTSTR lpszItem, int nImage, int nSelectedImage, LPARAM lParam,
     HSTREEITEM hParent /*= STVI_ROOT*/, HSTREEITEM hInsertAfter /*= STVI_LAST*/) PURE;

    STDMETHOD_(BOOL, RemoveItem)(THIS_ HSTREEITEM hItem) PURE;
    STDMETHOD_(void, RemoveAllItems)(THIS) PURE;

    STDMETHOD_(HSTREEITEM, GetRootItem)(THIS) SCONST PURE;

    STDMETHOD_(HSTREEITEM, GetNextSiblingItem)(THIS_ HSTREEITEM hItem) SCONST PURE;
    STDMETHOD_(HSTREEITEM, GetPrevSiblingItem)(THIS_ HSTREEITEM hItem) SCONST PURE;
    STDMETHOD_(HSTREEITEM, GetChildItem)
    (THIS_ HSTREEITEM hItem, BOOL bFirst /*= TRUE*/) SCONST PURE;
    STDMETHOD_(HSTREEITEM, GetParentItem)(THIS_ HSTREEITEM hItem) SCONST PURE;
    STDMETHOD_(HSTREEITEM, GetSelectedItem)(THIS) SCONST PURE;
    STDMETHOD_(HSTREEITEM, GetNextItem)(THIS_ HSTREEITEM hItem) SCONST PURE;

    STDMETHOD_(void, SortChildren)
    (THIS_ HSTREEITEM hItem, FunTreeSortCallback sortFunc, void *pCtx) PURE;

    STDMETHOD_(BOOL, SelectItem)(THIS_ HSTREEITEM hItem, BOOL bEnsureVisible /* = TRUE*/) PURE;

    STDMETHOD_(BOOL, GetItemText)(THIS_ HSTREEITEM hItem, IStringT * strText) SCONST PURE;
    STDMETHOD_(BOOL, SetItemText)(THIS_ HSTREEITEM hItem, LPCTSTR lpszItem) PURE;
    STDMETHOD_(BOOL, GetItemImage)
    (THIS_ HSTREEITEM hItem, int *nImage, int *nSelectedImage) SCONST PURE;
    STDMETHOD_(BOOL, SetItemImage)(THIS_ HSTREEITEM hItem, int nImage, int nSelectedImage) PURE;
    STDMETHOD_(LPARAM, GetItemData)(THIS_ HSTREEITEM hItem) SCONST PURE;
    STDMETHOD_(BOOL, SetItemData)(THIS_ HSTREEITEM hItem, LPARAM lParam) PURE;
    STDMETHOD_(BOOL, ItemHasChildren)(THIS_ HSTREEITEM hItem) PURE;

    STDMETHOD_(BOOL, GetCheckState)(THIS_ HSTREEITEM hItem) SCONST PURE;
    STDMETHOD_(BOOL, SetCheckState)(THIS_ HSTREEITEM hItem, BOOL bCheck) PURE;

    STDMETHOD_(BOOL, Expand)(THIS_ HSTREEITEM hItem, UINT nCode /*= TVE_EXPAND*/) PURE;
    STDMETHOD_(BOOL, EnsureVisible)(THIS_ HSTREEITEM hItem) PURE;
};

#undef INTERFACE
#define INTERFACE IHotKeyCtrl
DECLARE_INTERFACE_IID_(IHotKeyCtrl, ICtrl, "8839DDF0-84CE-4bca-8BE4-FF55928E3A55")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////

    /**
     * SHotKeyCtrl::SetRule
     * @brief    ���ù���
     * @param    WORD wInvalidComp --
     * @param    WORD wModifier  --
     *
     * Describe  ���ù���
     */
    STDMETHOD_(void, SetRule)(THIS_ WORD wInvalidComp, WORD wModifier) PURE;

    /**
     * SHotKeyCtrl::SetHotKey
     * @brief    �����ȼ�
     * @param    WORD vKey --
     * @param    WORD wModifiers  --
     *
     * Describe  �����ȼ�
     */
    STDMETHOD_(void, SetHotKey)(THIS_ WORD wKey, WORD wModifiers) PURE;

    /**
     * SHotKeyCtrl::GetHotKey
     * @brief    ��ȡ�ȼ�
     * @param    WORD &vKey --
     * @param    WORD wModifiers  --
     *
     * Describe  ��ȡ�ȼ�
     */
    STDMETHOD_(void, GetHotKey)(THIS_ WORD * wKey, WORD * wModifers) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IRichEdit
DECLARE_INTERFACE_IID_(IRichEdit, ICtrl, "6B72BCCE-9D42-4fb8-9CF4-F8F9605ACA9A")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////

    STDMETHOD_(DWORD, SaveRtf)(THIS_ LPCTSTR pszFileName) PURE;

    STDMETHOD_(DWORD, LoadRtf)(THIS_ LPCTSTR pszFileName) PURE;

    /**
     * SRichEdit::GetWindowTextLength
     * @brief     ��ȡ���ڱ��ⳤ��
     * @return    ����int
     *
     * Describe   ��ȡ���ڱ��ⳤ��
     */
    STDMETHOD_(int, GetWindowTextLength)(THIS) SCONST PURE;

    /**
     * SRichEdit::SetSel
     * @brief     ����ѡ��
     * @param     long nStartChar --
     * @param     long nEndChar --
     * @param     BOOL bNoScroll --
     *
     * Describe   ����ѡ��, ֧�ֳ����ı�
     */
    STDMETHOD_(void, SetSel)(THIS_ long nStartChar, long nEndChar, BOOL bNoScroll) PURE;
    /**
     * SRichEdit::ReplaceSel
     * @brief     �滻ѡ����
     * @param     LPCWSTR pszText --
     * @param     BOOL bCanUndo --
     *
     * Describe   �滻ѡ����
     */
    STDMETHOD_(void, ReplaceSel)(THIS_ LPCTSTR pszText, BOOL bCanUndo /*= TRUE*/) PURE;
    /**
     * SRichEdit::GetWordWrap
     * @brief
     * @return   ����BOOL
     *
     * Describe
     */
    STDMETHOD_(BOOL, GetWordWrap)(THIS) SCONST PURE;
    /**
     * SRichEdit::SetWordWrap
     * @brief
     * @param     BOOL fWordWrap --
     *
     * Describe
     */
    STDMETHOD_(void, SetWordWrap)(THIS_ BOOL fWordWrap) PURE;

    /**
     * SRichEdit::GetReadOnly
     * @brief    �ж��Ƿ�ֻ��
     * @return   ����BOOL
     *
     * Describe  �ж��Ƿ�ֻ��
     */
    STDMETHOD_(BOOL, GetReadOnly)(THIS) SCONST PURE;

    /**
     * SRichEdit::SetReadOnly
     * @brief     ����ֻ��
     * @param     BOOL bReadOnly -- �Ƿ�ֻ��
     * @return    ����BOOL
     *
     * Describe   ����ֻ��
     */
    STDMETHOD_(BOOL, SetReadOnly)(THIS_ BOOL bReadOnly) PURE;

    /**
     * SRichEdit::GetLimitText
     * @brief     ��ȡ��С�ı�����
     * @return    ����BOOL
     *
     * Describe   ��ȡ��С�ı�����
     */
    STDMETHOD_(LONG, GetLimitText)(THIS) SCONST PURE;

    /**
     * SRichEdit::SetLimitText
     * @brief     ������С�ı�����
     * @param     int nLength -- ����
     * @return    ����BOOL
     *
     * Describe   ������С�ı�����
     */
    STDMETHOD_(BOOL, SetLimitText)(THIS_ int nLength) PURE;

    /**
     * SRichEdit::GetDefaultAlign
     * @brief     ��ȡ���뷽ʽ
     * @return    ����WORD
     *
     * Describe   ������С�ı�����
     */
    STDMETHOD_(WORD, GetDefaultAlign)(THIS) SCONST PURE;

    /**
     * SRichEdit::SetDefaultAlign
     * @brief     ����Ĭ�϶��뷽ʽ
     * @param     WORD wNewAlign -- ���뷽ʽ
     *
     * Describe   ����Ĭ�϶��뷽ʽ
     */
    STDMETHOD_(void, SetDefaultAlign)(THIS_ WORD wNewAlign) PURE;

    /**
     * SRichEdit::GetRichTextFlag
     * @brief     ��ȡ��־
     * @return    ����BOOL
     *
     * Describe   ��ȡ��־
     */
    STDMETHOD_(BOOL, GetRichTextFlag)(THIS) SCONST PURE;

    /**
     * SRichEdit::SetRichTextFlag
     * @brief     ���ñ�־
     * @param     BOOL fRich -- ��־
     *
     * Describe   ���ñ�־
     */
    STDMETHOD_(void, SetRichTextFlag)(THIS_ BOOL fRich) PURE;

    /**
     * SRichEdit::SetRichTextFlag
     * @brief     ���ñ�־
     * @param     BOOL fRich -- ��־
     * @return    ����LONG
     *
     * Describe   ���ñ�־
     */
    STDMETHOD_(LONG, GetDefaultLeftIndent)(THIS) SCONST PURE;

    /**
     * SRichEdit::SetDefaultLeftIndent
     * @brief     ��������
     * @param     LONG lNewIndent -- �����ַ���
     *
     * Describe   ��������
     */
    STDMETHOD_(void, SetDefaultLeftIndent)(THIS_ LONG lNewIndent) PURE;

    /**
     * SRichEdit::SetSaveSelection
     * @brief
     * @param     BOOL fSaveSelection
     * @return    ����BOOL
     *
     * Describe
     */
    STDMETHOD_(BOOL, SetSaveSelection)(THIS_ BOOL fSaveSelection) PURE;

    /**
     * SRichEdit::SetDefaultTextColor
     * @brief     Ĭ���ı���ɫ
     * @param     COLORREF cr -- ��ɫ
     * @return    ����COLORREF
     *
     * Describe   ����Ĭ���ı���ɫ
     */
    STDMETHOD_(COLORREF, SetDefaultTextColor)(THIS_ COLORREF cr) PURE;
};

#undef INTERFACE
#define INTERFACE ITabCtrl
DECLARE_INTERFACE_IID_(ITabCtrl, ICtrl, "CAD40CB4-A0E5-4bea-9CE6-8DFC45DEFFD4")
{
	STDMETHOD_(long,AddRef) (THIS) PURE;
	STDMETHOD_(long,Release) (THIS) PURE;
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
	//////////////////////////////////////////////////////////////////////////

    /**
     * STabCtrl::GetCurSel
     * @brief    ��ȡ��ǰѡ��
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ��
     */
    STDMETHOD_(int, GetCurSel)(THIS) SCONST PURE;

    /**
     * STabCtrl::SetCurSel
     * @brief    ���õ�ǰѡ��
     * @param    int nIndex -- ����
     * @return   ����BOOL
     *
     * Describe  ��ȡ��ǰѡ��
     */
    STDMETHOD_(BOOL, SetCurSel)(THIS_ int nIndex) PURE;

    /**
     * STabCtrl::SetItemTitle
     * @brief    ���ñ���
     * @param    int nIndex  -- ����
     * @param    LPCTSTR lpszTitle  -- ����
     * @return   ����BOOL
     *
     * Describe  ��ȡ��ǰѡ��
     */
    STDMETHOD_(BOOL, SetItemTitle)(THIS_ int nIndex, LPCTSTR lpszTitle) PURE;

    /**
     * STabCtrl::InsertItem
     * @brief    ����tabҳ��
     * @param    LPCWSTR lpContent  -- XML������page��Ϣ
     * @param    int iInsert  -- λ��
     * @return   ���ز���λ��
     *
     * Describe  ����tabҳ��
     */
    STDMETHOD_(int, InsertItem)(THIS_ LPCWSTR lpContent, int iInsert /* = -1*/) PURE;

    /**
     * STabCtrl::GetItemCount
     * @brief    ��ȡtabҳ����
     * @return   ����int
     *
     * Describe  ��ȡtabҳ����
     */
    STDMETHOD_(int, GetItemCount)(THIS) SCONST PURE;

    /**
     * STabCtrl::GetItem
     * @brief    ��ȡָ��tabҳ��
     * @param    int nIndex -- ����
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ��
     */
    STDMETHOD_(IWindow *, GetPage)(THIS_ int nIndex) PURE;

    /**
     * STabCtrl::RemoveItem
     * @brief    ɾ��ָ��tabҳ��
     * @param    int nIndex -- ����
     * @param    int nSelPage -- ѡ��ҳ��
     * @return   ɾ��ָ��tabҳ��
     *
     * Describe  ��ȡ��ǰѡ��
     */
    STDMETHOD_(BOOL, RemoveItem)(THIS_ int nIndex, int iSelPage /*= 0*/) PURE;

    /**
     * STabCtrl::RemoveAllItems
     * @brief    ɾ������ҳ��
     *
     * Describe  ɾ������ҳ��
     */
    STDMETHOD_(void, RemoveAllItems)(THIS) PURE;

    /**
     * STabCtrl::GetPageIndex
     * @brief    ��ȡָ��ҳ�������
     * @param    LPCTSTR pszName -- ��ѯ�ַ���
     * @param    BOOL bTitle --
     * TRUE:pszName�������page��title����,FALSE��pszName�������page��name����
     * @return   �ҵ���ҳ��������
     *
     * Describe
     */
    STDMETHOD_(int, GetPageIndex)(THIS_ LPCTSTR pszName, BOOL bTitle) PURE;
};

SNSEND