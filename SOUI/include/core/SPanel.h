﻿/**
 * Copyright (C) 2014-2050
 * All rights reserved.
 *
 * @file       SPanel.h
 * @brief
 * @version    v1.0
 * @author     SOUI group
 * @date       2014/08/02
 *
 * Describe    SOUI的窗口面板，实现在非客户区的滚动条支持
 */

#pragma once

#include <core/SWnd.h>
#include <core/SScrollBarHandler.h>
#include <interface/SCtrl-i.h>

namespace SOUI
{

enum SbID
{
    SSB_NULL = 0,
    SSB_HORZ = 1,
    SSB_VERT = 2,
    SSB_BOTH = (SSB_HORZ | SSB_VERT),
};

class SOUI_EXP SPanel
    : public TWindowProxy<IPanel>
    , protected IScrollBarHost {
    SOUI_CLASS_NAME(SWindow, L"div")

  public:
    SPanel();
    virtual ~SPanel()
    {
    }

  public:
    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) OVERRIDE;

    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) OVERRIDE;

    STDMETHOD_(BOOL, IsScrollBarEnable)(THIS_ BOOL bVertical) SCONST OVERRIDE;

    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) OVERRIDE;

    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) OVERRIDE;

    STDMETHOD_(int, GetScrollPos)(THIS_ BOOL bVertical) SCONST OVERRIDE;

    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) OVERRIDE;

    STDMETHOD_(BOOL, GetScrollRange)
    (THIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST OVERRIDE;

    STDMETHOD_(BOOL, HasScrollBar)(THIS_ BOOL bVertical) SCONST OVERRIDE;

  public:
    virtual void WINAPI GetClientRect(LPRECT pRect) const;
    virtual CRect GetClientRect() const;

  protected:
    // 通过 IScrollBarHost 继承
    virtual CRect GetScrollBarRect(bool bVert) const override;
    virtual ISkinObj *GetScrollBarSkin(bool bVert) const override;
    virtual const SCROLLINFO *GetScrollBarInfo(bool bVert) const override;
    virtual int GetScrollBarArrowSize(bool bVert) const override;
    virtual void OnScrollUpdatePart(bool bVert, int iPart) override;
    virtual ISwndContainer *GetScrollBarContainer() override;
    virtual bool IsScrollBarEnable(bool bVert) const override;
    virtual void OnScrollUpdateThumbTrack(bool bVert, int nPos) override;
    virtual void OnScrollCommand(bool bVert, int iCmd, int nPos) override;
    virtual void OnScrollSetTimer(bool bVert, char id, UINT uElapse) override;
    virtual void OnScrollKillTimer(bool bVert, char id) override;
    virtual const IInterpolator *GetScrollInterpolator() const override;
    virtual int GetScrollFadeFrames() const override;
    virtual BYTE GetScrollThumbTrackMinAlpha() const override;

  protected:
    virtual int GetScrollLineSize(BOOL bVertical);
    virtual BOOL OnScroll(BOOL bVertical, UINT uCode, int nPos);
    virtual void OnColorize(COLORREF cr);
    virtual void OnScaleChanged(int nScale);

    virtual void OnContainerChanged(ISwndContainer *pOldContainer, ISwndContainer *pNewContainer);

  protected:
    int GetSbWidth() const;

    void ScrollUpdate();

    HRESULT OnAttrScrollbarSkin(SStringW strValue, BOOL bLoading);

    SCROLLINFO m_siVer, m_siHoz;
    SAutoRefPtr<SSkinScrollbar> m_pSkinSb;

  private: //修改为私有，派生类只能使用GetSbArrowSize(),GetSbWidth()获取
    SLayoutSize m_nSbArrowSize;
    SLayoutSize m_nSbWid;

  protected:
    CRect m_rcClient;

    SLayoutSize m_nSbLeft;   //滚动条距离左边距离
    SLayoutSize m_nSbRight;  //滚动条距离边边距离
    SLayoutSize m_nSbTop;    //滚动条距离上边距离
    SLayoutSize m_nSbBottom; //滚动条距离下边距离

    SbID m_dragSb, m_hitSb;

    UINT m_wBarVisible; //滚动条显示信息
    UINT m_wBarEnable;  //滚动条可操作信息
    SScrollBarHandler m_sbVert;
    SScrollBarHandler m_sbHorz;

    DWORD m_dwUpdateTime; //记录调用UpdateSWindow的时间
    DWORD m_dwUpdateInterval;

    short m_zDelta;
    int m_nScrollSpeed;

    mutable SAutoRefPtr<IInterpolator> m_fadeInterpolator;
    int m_fadeFrames;
    BYTE m_bySbThumbTrackMinAlpha;

    SOUI_ATTRS_BEGIN()
    ATTR_CUSTOM(L"sbSkin", OnAttrScrollbarSkin)
    ATTR_LAYOUTSIZE(L"sbArrowSize", m_nSbArrowSize, FALSE)
    ATTR_LAYOUTSIZE(L"sbWid", m_nSbWid, TRUE)
    ATTR_INT(L"sbEnable", m_wBarEnable, TRUE)
    ATTR_UINT(L"updateInterval", m_dwUpdateInterval, FALSE)
    ATTR_UINT(L"scrollSpeed", m_nScrollSpeed, FALSE)

    ATTR_LAYOUTSIZE(L"sbLeft", m_nSbLeft, TRUE)
    ATTR_LAYOUTSIZE(L"sbRight", m_nSbRight, TRUE)
    ATTR_LAYOUTSIZE(L"sbTop", m_nSbTop, TRUE)
    ATTR_LAYOUTSIZE(L"sbBottom", m_nSbBottom, TRUE)

    ATTR_INT(L"sbFadeFrames", m_fadeFrames, FALSE)
    ATTR_INT(L"sbTrumbTrackMinAlpha", m_bySbThumbTrackMinAlpha, FALSE)
    ATTR_INTERPOLATOR(L"sbFadeInterpolator", m_fadeInterpolator, FALSE)
    ATTR_CHAIN_PTR(m_fadeInterpolator, 0)
    SOUI_ATTRS_END()

  protected:
    int OnCreate(LPVOID);

    void OnDestroy();

    void OnNcPaint(IRenderTarget *pRT);

    virtual BOOL OnNcHitTest(CPoint pt);

    void OnNcLButtonDown(UINT nFlags, CPoint point);

    void OnNcLButtonUp(UINT nFlags, CPoint pt);

    void OnNcMouseMove(UINT nFlags, CPoint point);

    void OnNcMouseLeave();

    //滚动条显示或者隐藏时发送该消息
    LRESULT OnNcCalcSize(BOOL bCalcValidRects, LPARAM lParam);

    BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);

    void OnTimer(char cTimerID);

    void OnShowWindow(BOOL bShow, UINT nStatus);

    void OnEnable(BOOL bEnable, UINT uStatus);

    void OnVScroll(UINT nSBCode, UINT nPos, HWND);
    void OnHScroll(UINT nSBCode, UINT nPos, HWND);

    SOUI_MSG_MAP_BEGIN()
    MSG_WM_CREATE(OnCreate)
    MSG_WM_DESTROY(OnDestroy)
    MSG_WM_NCPAINT_EX(OnNcPaint)
    MSG_WM_NCCALCSIZE(OnNcCalcSize)
    MSG_WM_NCLBUTTONDOWN(OnNcLButtonDown)
    MSG_WM_NCLBUTTONUP(OnNcLButtonUp)
    MSG_WM_NCLBUTTONDBLCLK(OnNcLButtonDown)
    MSG_WM_NCMOUSEMOVE(OnNcMouseMove)
    MSG_WM_NCMOUSELEAVE(OnNcMouseLeave)
    MSG_WM_MOUSEWHEEL(OnMouseWheel)
    MSG_WM_TIMER_EX(OnTimer)
    MSG_WM_SHOWWINDOW(OnShowWindow)
    MSG_WM_ENABLE_EX(OnEnable)
    MSG_WM_VSCROLL(OnVScroll)
    MSG_WM_HSCROLL(OnHScroll)
    SOUI_MSG_MAP_END()
};

template <class T>
class TPanelProxy
    : public T
    , public SPanel {
  public:
    STDMETHOD_(long, AddRef)(THIS) OVERRIDE
    {
        return SPanel::AddRef();
    }
    STDMETHOD_(long, Release)(THIS) OVERRIDE
    {
        return SPanel::Release();
    }
    STDMETHOD_(void, OnFinalRelease)(THIS) OVERRIDE
    {
        SPanel::OnFinalRelease();
    }

    STDMETHOD_(IWindow *, ToIWindow)(THIS) OVERRIDE
    {
        return (SPanel *)this;
    }

    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) OVERRIDE
    {
        return SPanel::ShowScrollBar(wBar, bShow);
    }

    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) OVERRIDE
    {
        return SPanel::EnableScrollBar(wBar, bEnable);
    }

    STDMETHOD_(BOOL, IsScrollBarEnable)(THIS_ BOOL bVertical) SCONST OVERRIDE
    {
        return SPanel::IsScrollBarEnable(bVertical);
    }

    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) OVERRIDE
    {
        return SPanel::SetScrollInfo(si, bVertical);
    }

    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) OVERRIDE
    {
        return SPanel::SetScrollPos(bVertical, nNewPos, bRedraw);
    }

    STDMETHOD_(int, GetScrollPos)(THIS_ BOOL bVertical) SCONST OVERRIDE
    {
        return SPanel::GetScrollPos(bVertical);
    }

    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) OVERRIDE
    {
        return SPanel::SetScrollRange(bVertical, nMinPos, nMaxPos, bRedraw);
    }

    STDMETHOD_(BOOL, GetScrollRange)
    (THIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST OVERRIDE
    {
        return SPanel::GetScrollRange(bVertical, lpMinPos, lpMaxPos);
    }

    STDMETHOD_(BOOL, HasScrollBar)(THIS_ BOOL bVertical) SCONST OVERRIDE
    {
        return SPanel::HasScrollBar(bVertical);
    }

    STDMETHOD_(HRESULT, QueryInterface)(REFGUID id, IObjRef **ppRet) OVERRIDE
    {
        if (id == __uuidof(T))
        {
            *ppRet = (T *)this;
            AddRef();
            return S_OK;
        }
        else
        {
            return SPanel::QueryInterface(id, ppRet);
        }
    }
};

class SOUI_EXP SScrollView : public TPanelProxy<IScrollView> {
    SOUI_CLASS_NAME(SPanel, L"scrollview")
  public:
    SScrollView();
    virtual ~SScrollView()
    {
    }

  public:
    STDMETHOD_(SIZE, GetViewSize)(THIS) SCONST OVERRIDE;

    STDMETHOD_(void, SetViewSize)(THIS_ SIZE szView) OVERRIDE;

    STDMETHOD_(POINT, GetViewOrigin)(THIS) SCONST OVERRIDE;

    STDMETHOD_(void, SetViewOrigin)(THIS_ POINT pt) OVERRIDE;

  protected:
    virtual void OnViewSizeChanged(CSize szOld, CSize szNew);
    virtual void OnViewOriginChanged(CPoint ptOld, CPoint ptNew);

  protected:
    STDMETHOD_(RECT, GetChildrenLayoutRect)(THIS) SCONST OVERRIDE;
    STDMETHOD_(void, UpdateChildrenPosition)(THIS) OVERRIDE;

    virtual BOOL OnScroll(BOOL bVertical, UINT uCode, int nPos);

    virtual void UpdateScrollBar();

  protected:
    HRESULT OnAttrViewSize(const SStringW &strValue, BOOL bLoading);

    SOUI_ATTRS_BEGIN()
    ATTR_INT(L"origin-x", m_ptOrigin.x, FALSE)
    ATTR_INT(L"origin-y", m_ptOrigin.y, FALSE)
    ATTR_CUSTOM(L"viewSize", OnAttrViewSize)
    SOUI_ATTRS_END()

  protected:
    void UpdateViewSize();
    void OnSize(UINT nType, CSize size);

    SOUI_MSG_MAP_BEGIN()
    MSG_WM_SIZE(OnSize)
    SOUI_MSG_MAP_END()
  protected:
    SLayoutSize m_viewSize[2];
    POINT m_ptOrigin;
    SIZE m_szView;
};

} // namespace SOUI