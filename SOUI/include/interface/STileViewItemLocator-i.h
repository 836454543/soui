#pragma once
#include <interface/SAdapter-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE ITileViewItemLocator
DECLARE_INTERFACE_(ITileViewItemLocator, IObjRef)
{

    STDMETHOD_(void, SetAdapter)(THIS_ ILvAdapter * pAdapter) PURE;

    STDMETHOD_(void, OnDataSetChanged)(THIS) PURE;

    STDMETHOD_(int, GetItemHeight)(THIS_ int iItem) SCONST PURE;

    STDMETHOD_(void, SetItemHeight)(THIS_ int iItem, int nHeight) PURE;

    //��ȡitem��CRect(�����TileView)
    STDMETHOD_(RECT, GetItemRect)(THIS_ int iItem) PURE;

    //����TileView��ȣ���TileView��OnSize�е��ã�
    STDMETHOD_(void, SetTileViewWidth)(THIS_ int width, BOOL bDpiAware) PURE;

    //��ȡitem���С���λ��
    STDMETHOD_(void, GetItemRowAndColIndex)(THIS_ int iItem, int *row, int *col) PURE;

    //�Ƿ�Ϊÿ�е����һ��Ԫ��
    STDMETHOD_(BOOL, IsLastInRow)(THIS_ int iItem) PURE;

    //��ȡ��һ�У�ͬһ�е�Ԫ��index
    STDMETHOD_(int, GetUpItem)(THIS_ int iItem) PURE;
    //��ȡ��һ�У�ͬһ�е�Ԫ��index
    STDMETHOD_(int, GetDownItem)(THIS_ int iItem) PURE;

    STDMETHOD_(int, GetTotalHeight)(THIS) PURE;

    STDMETHOD_(int, Item2Position)(THIS_ int iItem) PURE;

    STDMETHOD_(int, Position2Item)(THIS_ int position) PURE;

    STDMETHOD_(int, GetScrollLineSize)(THIS) SCONST PURE;

    STDMETHOD_(int, GetMarginSize)(THIS) SCONST PURE;

    STDMETHOD_(int, SetScale)(THIS_ int scale) PURE;

    STDMETHOD_(int, GetCountInRow)(THIS) SCONST PURE;

    STDMETHOD_(int, GetItemLineHeight)(THIS) SCONST PURE;

    STDMETHOD_(int, GetItemWidth)(THIS) SCONST PURE;
};

SNSEND