#pragma once
#include <interface/obj-ref-i.h>
#include <interface/SResProvider-i.h>
#include <interface/STranslator-i.h>
#include <interface/stooltip-i.h>
#include <interface/slog-i.h>
#include <interface/SAttrStorage-i.h>
#include <interface/smsgloop-i.h>
#include <interface/shostwnd-i.h>
#include <interface/SResProviderMgr-i.h>
#include <interface/SRealWndHandler-i.h>
#include <interface/SRender-i.h>
#include <interface/SScriptModule-i.h>
#include <interface/SAnimation-i.h>
#include <interface/SValueAnimator-i.h>
SNSBEGIN

#undef INTERFACE
#define INTERFACE IApplication
DECLARE_INTERFACE_(IApplication, IObjRef)
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

	//////////////////////////////////////////////////////////////////////////
    STDMETHOD_(HMODULE, GetModule)(THIS) SCONST PURE;
    STDMETHOD_(UINT, LoadSystemNamedResource)(THIS_ IResProvider * pResProvider) PURE;
    STDMETHOD_(ITranslatorMgr *, GetTranslator)(THIS) PURE;
    STDMETHOD_(void, SetTranslator)(THIS_ ITranslatorMgr * pTrans) PURE;
    STDMETHOD_(IToolTipFactory *, GetToolTipFactory)(THIS) PURE;
    STDMETHOD_(void, SetToolTipFactory)(THIS_ IToolTipFactory * pToolTipFac) PURE;

    STDMETHOD_(BOOL, SetMsgLoopFactory)(THIS_ IMsgLoopFactory * pMsgLoopFac) PURE;
    STDMETHOD_(IMsgLoopFactory *, GetMsgLoopFactory)(THIS) PURE;

    STDMETHOD_(void, SetLogManager)(THIS_ ILog4zManager * pLogMgr) PURE;
    STDMETHOD_(ILog4zManager *, GetLogManager)(THIS) PURE;

    STDMETHOD_(void, SetAttrStorageFactory)(THIS_ IAttrStorageFactory * pAttrStorageFactory) PURE;
    STDMETHOD_(IAttrStorageFactory *, GetAttrStorageFactory)(THIS) PURE;

    STDMETHOD_(int, Run)(THIS_ HWND hMainWnd) PURE;
    STDMETHOD_(HWND, GetMainWnd)(THIS) PURE;

    STDMETHOD_(BOOL, AddMsgLoop)(THIS_ IMessageLoop * pMsgLoop) PURE;
    STDMETHOD_(BOOL, RemoveMsgLoop)(THIS) PURE;

    STDMETHOD_(IMessageLoop *, GetMsgLoop)(THIS_ DWORD dwThreadID) SCONST PURE;

    STDMETHOD_(IResProviderMgr *, GetResProviderMgr)(THIS) PURE;

    /**
     * GetRealWndHander
     * @brief    ���RealWndHander
     * @return   IRealWndHandler * -- RealWndHander
     * Describe
     */
    STDMETHOD_(IRealWndHandler *, GetRealWndHander)(THIS) PURE;

    /**
     * SetRealWndHandler
     * @brief    ����RealWnd����ӿ�
     * @param    IRealWndHandler * pRealHandler --  RealWnd����ӿ�
     * @return   void
     * Describe
     */
    STDMETHOD_(void, SetRealWndHandler)(THIS_ IRealWndHandler * pRealHandler) PURE;

    /**
     * GetRenderFactory
     * @brief    ��õ�ǰ����Ⱦģ��
     * @return   IRenderFactory * ��Ⱦģ��ָ��
     *
     * Describe
     */
    STDMETHOD_(IRenderFactory *, GetRenderFactory)(THIS) PURE;

    /**
     * SetScriptModule
     * @brief    ����SOUI��ʹ�õĽű�ģ���೧
     * @param    IScriptFactory *pScriptModule --  �ű�ģ���೧
     * @return   void
     *
     * Describe
     */
    STDMETHOD_(void, SetScriptFactory)(THIS_ IScriptFactory * pScriptModule) PURE;

    /**
     * @brief ��ʼ��XML��Դ��name-idӳ���
     * @param pNames const LPCWSTR *--�ؼ�����
     * @param nIds const int *--�ؼ�ID��
     * @param nCount int--�ؼ�����
     * @return 
     * @remark ���ݱ���residbuilder�����Զ�����
    */
    STDMETHOD_(void, InitXmlNamedID)(THIS_ const LPCWSTR *pNames, const int *nIds, int nCount) PURE;

    /**
     * @brief ����ԴID����XML
     * @param strResId LPCTSTR--��ԴID��Ϊtype:name��ʽ
     * @return IXmlDoc *--XML Doc
     * @remark ʹ����ɺ����Rlease�ͷ�
    */
    STDMETHOD_(IXmlDoc *, LoadXmlDocment)(THIS_ LPCTSTR strResId) PURE;

    /**
     * @brief ����Դ���ض�����Դ
     * @param strResId LPCTSTR--������ԴID
     * @return IAnimation* ��������
     * @remark ʹ����ɺ����Rlease�ͷ�
     */
    STDMETHOD_(IAnimation *, LoadAnimation)(THIS_ LPCTSTR strResId) PURE;

    /**
     * @brief ����Դ������ֵ������Դ
     * @return IValueAnimator* ��ֵ��������
     * @remark ʹ����ɺ����Rlease�ͷ�
     */
    STDMETHOD_(IValueAnimator *, LoadValueAnimator)(THIS_ LPCTSTR strResId) PURE;
};

SNSEND