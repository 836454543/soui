#pragma once

#include <interface/sobject-i.h>
#include <interface/sstring-i.h>
#include <interface/SAnimation-i.h>
#include <interface/SRender-i.h>

SNSBEGIN

interface ISwndContainer;

#undef INTERFACE
#define INTERFACE IWindow
DECLARE_INTERFACE_(IWindow,IObject)
{
	STDMETHOD_(SWND,GetSwnd)(THIS) SCONST PURE;

	STDMETHOD_(ILayout *,GetLayout)(THIS) PURE;

	STDMETHOD_(const ILayoutParam *, GetLayoutParam2)(THIS) SCONST PURE;

	STDMETHOD_(ILayoutParam *, GetLayoutParam)(THIS) PURE;

	STDMETHOD_(BOOL,SetLayoutParam)(THIS_ ILayoutParam * pLayoutParam) PURE;

	STDMETHOD_(BOOL,IsFloat)(THIS) SCONST PURE;

	STDMETHOD_(BOOL,IsDisplay)(THIS) SCONST PURE;

	STDMETHOD_(void,SetWindowText)(THIS_ LPCTSTR lpszText) PURE;

	STDMETHOD_(void,SetToolTipText)(THIS_ LPCTSTR pszText) PURE;

	STDMETHOD_(BOOL,IsChecked)(THIS) SCONST PURE;
	STDMETHOD_(void,SetCheck)(THIS_ BOOL bCheck) PURE;

	STDMETHOD_(BOOL,IsDisabled)(THIS_ BOOL bCheckParent) SCONST PURE;
	STDMETHOD_(void,EnableWindow)(THIS_ BOOL bEnable,BOOL bUpdate) PURE;

	STDMETHOD_(BOOL,IsVisible)(THIS_ BOOL bCheckParent) SCONST PURE;
	STDMETHOD_(void,SetVisible)(THIS_ BOOL bVisible,BOOL bUpdate) PURE;

	STDMETHOD_(BOOL,IsMsgTransparent)(THIS) SCONST PURE;

	STDMETHOD_(ULONG_PTR,GetUserData)(THIS) SCONST PURE;
	STDMETHOD_(ULONG_PTR,SetUserData)(THIS_ ULONG_PTR uData) PURE;
	STDMETHOD_(void,GetWindowRect)(THIS_ LPRECT prect) SCONST PURE;
	STDMETHOD_(void,GetClientRect)(THIS_ LPRECT prect) SCONST PURE;
	STDMETHOD_(BOOL,IsContainPoint)(THIS_ POINT pt,BOOL bClientOnly) SCONST PURE;
	STDMETHOD_(void,DoColorize)(THIS_ COLORREF cr) PURE;
	STDMETHOD_(COLORREF,GetColorizeColor)(THIS) SCONST PURE;
	STDMETHOD_(BOOL,Destroy)(THIS) PURE;
	STDMETHOD_(void,BringWindowToTop)(THIS) PURE;
	STDMETHOD_(UINT,GetChildrenCount)(THIS) SCONST PURE;
	STDMETHOD_(LRESULT,SSendMessage)(THIS_ UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL *pbMsgHandled) PURE;
	STDMETHOD_(void,SDispatchMessage)(THIS_ UINT uMsg, WPARAM wParam, LPARAM lParam) PURE;

	STDMETHOD_(void,SetFocus)(THIS) PURE;
	STDMETHOD_(void,KillFocus)(THIS) PURE;
	STDMETHOD_(BOOL,IsFocused)(THIS) SCONST PURE;

	STDMETHOD_(void,Invalidate)(THIS) PURE;
	STDMETHOD_(void,InvalidateRect)(THIS_ LPCRECT lprect) PURE;

	STDMETHOD_(void,LockUpdate)(THIS) PURE;
	STDMETHOD_(void,UnlockUpdate)(THIS) PURE;
	STDMETHOD_(BOOL,IsUpdateLocked)(THIS) SCONST PURE;
	STDMETHOD_(void,Update)(THIS) PURE;
	STDMETHOD_(void,Move)(THIS_ LPCRECT prect) PURE;
	STDMETHOD_(void,SetWindowRgn)(THIS_ IRegion *pRgn,BOOL bRedraw) PURE;
	STDMETHOD_(IRegion*,GetWindowRgn)(THIS) SCONST PURE;
	STDMETHOD_(void,SetWindowPath)(THIS_ IPath *pPath,BOOL bRedraw) PURE;

	STDMETHOD_(BOOL,SetTimer)(THIS_ char id,UINT uElapse) PURE;
	STDMETHOD_(void,KillTimer)(THIS_ char id) PURE;

	STDMETHOD_(SWND,GetCapture)(THIS) PURE;
	STDMETHOD_(SWND,SetCapture)(THIS) PURE;
	STDMETHOD_(BOOL,ReleaseCapture)(THIS) PURE;

	STDMETHOD_(void,SetAnimation)(THIS_ IAnimation * animation) PURE;

	STDMETHOD_(IAnimation *,GetAnimation)(THIS) PURE;

	STDMETHOD_(void,StartAnimation)(THIS_ IAnimation * animation) PURE;

	STDMETHOD_(void,ClearAnimation)(THIS) PURE;

	STDMETHOD_(void,SetAlpha)(THIS_ BYTE byAlpha) PURE;

	STDMETHOD_(BYTE,GetAlpha)(THIS) SCONST PURE;

	STDMETHOD_(int,GetScale)(THIS) SCONST PURE;

	STDMETHOD_(BOOL,IsSiblingsAutoGroupped)(THIS) SCONST PURE;

	STDMETHOD_(void,RequestRelayout)(THIS) PURE;
	STDMETHOD_(void,UpdateLayout)(THIS) PURE;

	STDMETHOD_(UINT,OnGetDlgCode)(THIS) SCONST PURE;

	STDMETHOD_(BOOL,IsFocusable)(THIS) SCONST PURE;

	STDMETHOD_(BOOL,IsClipClient)(THIS) SCONST PURE;
	STDMETHOD_(BOOL,IsLayoutDirty)(THIS) SCONST PURE;
	STDMETHOD_(void,UpdateChildrenPosition)(THIS) PURE;

	STDMETHOD_(IWindow *,GetIWindow)(THIS_ int uCode)  PURE;

	STDMETHOD_(IWindow *,GetIChild)(THIS_ int iChild)  PURE;

	STDMETHOD_(IWindow *,GetIParent)(THIS)  PURE;

	STDMETHOD_(IWindow *,GetIRoot)(THIS)  PURE;

	STDMETHOD_(const IWindow*,GetNextLayoutIChild2)(THIS_ const IWindow* pCurChild) SCONST PURE;
	STDMETHOD_(IWindow*,GetNextLayoutIChild)(THIS_ IWindow* pCurChild) PURE;

	STDMETHOD_(BOOL,IsIDescendant)(THIS_ const IWindow *pTest) SCONST PURE;

	
		/**
         * AdjustZOrder
         * @brief    ��������Z��
		 * @param    SWindow *pInsertAfter --  �������������֮��
         * @return   bool,  pInsertAfter��this��ͬ�����ڷ���ʧ��
         *
         * Describe  pInsertAfter����ΪNULL��������thisͬһ�����ֵܴ���
         */
		STDMETHOD_(BOOL,AdjustIZOrder)(THIS_ IWindow *pInsertAfter) PURE;

		        /**
         * InsertChild
         * @brief    �ڴ������в���һ���Ӵ���
         * @param    SWindow * pNewChild --  �Ӵ��ڶ���
         * @param    SWindow * pInsertAfter --  ����λ��
         * @return   void 
         *
         * Describe  һ������UI��ʼ����ʱ�򴴽�������Ĵ��ڲ����Զ����벼������
         */
        STDMETHOD_(void,InsertIChild)(THIS_ IWindow *pNewChild,IWindow *pInsertAfter) PURE;

        /**
         * RemoveChild
         * @brief    �Ӵ��������Ƴ�һ���Ӵ��ڶ���
         * @param    SWindow * pChild --  �Ӵ��ڶ���
         * @return   BOOL 
         *
         * Describe  �Ӵ��ڲ����Զ��ͷ�
         */
        STDMETHOD_(BOOL,RemoveIChild)(THIS_ IWindow *pChild) PURE;
        
        /**
         * DestroyChild
         * @brief    ����һ���Ӵ���
         * @param    SWindow * pChild --  �Ӵ��ڶ���
         * @return   BOOL 
         *
         * Describe  �ȵ���RemoveChild���ٵ���pChild->Release���ͷ��Ӵ��ڶ���
         */
        STDMETHOD_(BOOL,DestroyIChild)(THIS_ IWindow *pChild) PURE;
        
		STDMETHOD_(void,DestroyAllChildren)(THIS) PURE;

		STDMETHOD_(ISwndContainer*,GetContainer)(THIS) PURE;
		STDMETHOD_(void,SetContainer)(THIS_ ISwndContainer *pContainer) PURE;


        /**
        * GetChildrenLayoutRect
        * @brief    ����Ӵ��ڵĲ��ֿռ�
        * @return   CRect 
        *
        * Describe  ͨ���ǿͻ���������tab,group�����Ŀؼ���һ��
        */
		STDMETHOD_(RECT,GetChildrenLayoutRect)(THIS) SCONST PURE;

        /**
        * GetDesiredSize
        * @brief    ��û��ָ�����ڴ�Сʱ��ͨ����Ƥ�����㴰�ڵ�������С
        * @param    int nParentWid -- ������ȣ�<0�����������������ǰ���ڿ��
        * @param    int nParentHei -- �����߶ȣ�<0���������߶�������ǰ���ڸ߶�
        * @return   CSize 
        *
        * Describe  
        */
		STDMETHOD_(SIZE,GetDesiredSize)(THIS_ int nParentWid, int nParentHei) PURE;

		STDMETHOD_(BOOL,OnRelayout)(THIS_ RECT rcWnd) PURE;

};

SNSEND