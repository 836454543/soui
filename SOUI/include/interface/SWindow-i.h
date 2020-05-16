#pragma once

#pragma once
#include <interface/sobject-i.h>
#include <interface/sstring-i.h>
#include <interface/SAnimation-i.h>
#include <interface/SRender-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE IWindow
DECLARE_INTERFACE_(IWindow,IObject)
{
	//!�������
	/*!
	*/
	STDMETHOD_(long,AddRef) (THIS) PURE;

	//!�ͷ�����
	/*!
	*/
	STDMETHOD_(long,Release) (THIS) PURE;

	//!�ͷŶ���
	/*!
	*/
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;

	/**
	* IsClass
	* @brief    �ж�this�ǲ�������ָ��������
	* @param    LPCWSTR lpszName --  ����������
	* @return   BOOL -- true�ǲ�������
	* Describe  
	*/    
	STDMETHOD_(BOOL,IsClass)(THIS_ LPCWSTR lpszName) SCONST PURE;

	/**
	* GetObjectClass
	* @brief    ���������
	* @return   LPCWSTR -- ������
	* Describe  ����һ���麯����ע����GetClassName������
	*/    
	STDMETHOD_(LPCWSTR,GetObjectClass)(THIS_) SCONST PURE;

	/**
	* GetObjectType
	* @brief    ��ö�������
	* @return   int -- ��������
	* Describe  ����һ���麯����ע����GetClassType������
	*/    
	STDMETHOD_(int,GetObjectType)(THIS)  SCONST PURE;

	STDMETHOD_(int,GetID)(THIS) SCONST PURE;
	STDMETHOD_(void,SetID)(THIS_ int nID) PURE;

	STDMETHOD_(LPCWSTR,GetName)(THIS) SCONST PURE;
	STDMETHOD_(void,SetName)(THIS_ LPCWSTR pszName) PURE;


	/**
	* InitFromXml
	* @brief    ��XML��ڳ�ʼ��SObject����
	* @param    SXmlNode --  XML���
	* @return   BOOL -- �ɹ�����TRUE
	* Describe  
	*/    
	STDMETHOD_(BOOL,InitFromXml)(THIS_ IXmlNode * xmlNode ) PURE;

	/**
	* OnInitFinished
	* @brief    ���Գ�ʼ����ɴ���ӿ�
	* @param    SXmlNode xmlNode --  ���Խڵ�
	* @return   void
	* Describe  
	*/    
	STDMETHOD_(void,OnInitFinished)(THIS_ IXmlNode* xmlNode) PURE;

	/**
	* SetAttributeA
	* @brief    ����һ����������
	* @param    const IStringA * strAttribName --  ������
	* @param    const IStringA * strValue --  ����ֵ
	* @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
	* @return   HRESULT -- ��������
	* Describe  
	*/    
	STDMETHOD_(HRESULT,SetAttributeA)(THIS_ const IStringA * strAttribName, const IStringA *  strValue, BOOL bLoading) PURE;

	/**
	* SetAttributeW
	* @brief    ����һ����������
	* @param    const IStringA *strAttribName --  ������
	* @param    const IStringA *strValue --  ����ֵ
	* @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
	* @return   HRESULT -- ��������
	* Describe  
	*/    
	STDMETHOD_(HRESULT,SetAttributeW)(THIS_ const IStringW *  strAttribName, const IStringW *  strValue, BOOL bLoading) PURE;

	/**
	* SetAttribute
	* @brief    ����һ����������
	* @param    LPCWSTR pszAttr --  ������
	* @param    LPCWSTR pszValue --  ����ֵ
	* @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
	* @return   HRESULT -- ��������
	* Describe  
	*/    
	STDMETHOD_(HRESULT,SetAttribute)(THIS_ LPCWSTR pszAttr, LPCWSTR pszValue, BOOL bLoading) PURE;

	/**
	* GetAttribute
	* @brief    ͨ����������ѯ����ֵ
	* @param    const SStringW & strAttr --  ������
	* @param    IStringW * pValue -- ����ֵ
	* @return   BOOL, TRUE:��ȡ�ɹ���FALSE:��ȡʧ�ܣ����Բ�����
	* Describe  Ĭ�Ϸ��ؿ�
	*/    
	STDMETHOD_(BOOL,GetAttribute)(THIS_ const IStringW * strAttr, IStringW * pValue) SCONST PURE;

	/**
	* OnAttribute
	* @brief    ���Դ������õķ���
	* @param    const SStringW & strAttribName --  ������
	* @param    const SStringW & strValue --  ������
	* @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
	* @param    HRESULT hr --  ���Դ�����
	* Describe  ��������ֱ�ӷ���
	*/    
	STDMETHOD_(HRESULT,AfterAttribute)(THIS_ const IStringW * strAttribName,const IStringW * strValue, BOOL bLoading, HRESULT hr) PURE;

	/**
	* DefAttributeProc
	* @brief    Ĭ�����Դ�����
	* @param    const SStringW & strAttribName --  ������
	* @param	 const SStringW & strValue --����ֵ
	* @param    BOOL bLoading -- ��XML��ʼ����־
	* @return   HRESULT -- S_OK:ˢ��UI�� S_FALSE:�ɹ�����ˢ��UI��������ʧ��
	* Describe  ��SetAttribute��û�д���һ������ʱת������������
	*/  
	STDMETHOD_(HRESULT,DefAttributeProc)(THIS_ const IStringW * strAttribName,const IStringW * strValue, BOOL bLoading) PURE;


	STDMETHOD_(BOOL,IsMsgHandled)(THIS) SCONST PURE;

	STDMETHOD_(void,SetMsgHandled)(THIS_ BOOL bHandled) PURE;

	STDMETHOD_(IWindow*,GetIWindow)(THIS) PURE;

	STDMETHOD_(ISwndContainer*,GetContainer)(THIS) PURE;

	STDMETHOD_(SWND,GetSwnd)(THIS) SCONST PURE;

	STDMETHOD_(ILayout *,GetLayout)(THIS) SCONST PURE;

	STDMETHOD_(ILayoutParam *, GetLayoutParam)(THIS) SCONST PURE;

	STDMETHOD_(void,SetLayoutParam)(THIS_ ILayoutParam * pLayoutParam) PURE;

	STDMETHOD_(const IStringW *,GetTrCtx)(THIS) SCONST PURE;

	STDMETHOD_(BOOL,IsFloat)(THIS) SCONST PURE;

	STDMETHOD_(BOOL,IsDisplay)(THIS) SCONST PURE;

	STDMETHOD_(IStringT*,GetWindowTextI)(THIS_ BOOL bRawText) PURE;

	STDMETHOD_(void,SetWindowText)(THIS_ LPCTSTR lpszText) PURE;

	STDMETHOD_(IStringT*, GetToolTipTextI)(THIS) PURE;

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
	STDMETHOD_(BOOL,IsContainPoint)(THIS_ const POINT *pt,BOOL bClientOnly) SCONST PURE;
	STDMETHOD_(void,DoColorize)(THIS_ COLORREF cr) PURE;
	STDMETHOD_(COLORREF,GetColorizeColor)(THIS) SCONST PURE;
	STDMETHOD_(BOOL,DestroyWindow)(THIS) PURE;
	STDMETHOD_(void,BringWindowToTop)(THIS) PURE;
	STDMETHOD_(IWindow*,GetParent_C)(THIS) SCONST PURE;
	STDMETHOD_(IWindow*,FindChildByID_C)(THIS_ int nID, int nDeep) SCONST PURE;
	STDMETHOD_(IWindow*,FindChildByName_C)(THIS_ LPCWSTR strName, int nDeep) SCONST PURE;
	STDMETHOD_(IWindow*,CreateChildren_C)(THIS_ LPCWSTR strXml) PURE;
	STDMETHOD_(UINT,GetChildrenCount)(THIS) SCONST PURE;
	STDMETHOD_(BOOL,DestroyChild)(THIS_ SWND hChild) PURE;
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
	STDMETHOD_(void,UpdateWindow)(THIS) PURE;
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

};

SNSEND