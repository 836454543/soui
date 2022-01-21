#pragma once
#include <interface/sobject-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE ICaret
DECLARE_INTERFACE_(ICaret, IObject)
{
    //!�������
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!�ͷ�����
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!�ͷŶ���
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    /**
     * IsClass
     * @brief    �ж�this�ǲ�������ָ��������
     * @param    LPCWSTR lpszName --  ����������
     * @return   BOOL -- true�ǲ�������
     * Describe
     */
    STDMETHOD_(BOOL, IsClass)(THIS_ LPCWSTR lpszName) SCONST PURE;

    /**
     * GetObjectClass
     * @brief    ���������
     * @return   LPCWSTR -- ������
     * Describe  ����һ���麯����ע����GetClassName������
     */
    STDMETHOD_(LPCWSTR, GetObjectClass)(THIS_) SCONST PURE;

    /**
     * GetObjectType
     * @brief    ��ö�������
     * @return   int -- ��������
     * Describe  ����һ���麯����ע����GetClassType������
     */
    STDMETHOD_(int, GetObjectType)(THIS) SCONST PURE;

    STDMETHOD_(int, GetID)(THIS) SCONST PURE;
    STDMETHOD_(void, SetID)(THIS_ int nID) PURE;

    STDMETHOD_(LPCWSTR, GetName)(THIS) SCONST PURE;
    STDMETHOD_(void, SetName)(THIS_ LPCWSTR pszName) PURE;

    /**
     * InitFromXml
     * @brief    ��XML��ڳ�ʼ��SObject����
     * @param    SXmlNode --  XML���
     * @return   BOOL -- �ɹ�����TRUE
     * Describe
     */
    STDMETHOD_(BOOL, InitFromXml)(THIS_ IXmlNode * xmlNode) PURE;

    /**
     * OnInitFinished
     * @brief    ���Գ�ʼ����ɴ���ӿ�
     * @param    SXmlNode xmlNode --  ���Խڵ�
     * @return   void
     * Describe
     */
    STDMETHOD_(void, OnInitFinished)(THIS_ IXmlNode * xmlNode) PURE;

    /**
     * SetAttributeA
     * @brief    ����һ����������
     * @param    const IStringA * strAttribName --  ������
     * @param    const IStringA * strValue --  ����ֵ
     * @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
     * @return   HRESULT -- ��������
     * Describe
     */
    STDMETHOD_(HRESULT, SetAttributeA)
    (THIS_ const IStringA *strAttribName, const IStringA *strValue, BOOL bLoading) PURE;

    /**
     * SetAttributeW
     * @brief    ����һ����������
     * @param    const IStringA *strAttribName --  ������
     * @param    const IStringA *strValue --  ����ֵ
     * @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
     * @return   HRESULT -- ��������
     * Describe
     */
    STDMETHOD_(HRESULT, SetAttributeW)
    (THIS_ const IStringW *strAttribName, const IStringW *strValue, BOOL bLoading) PURE;

    /**
     * SetAttribute
     * @brief    ����һ����������
     * @param    LPCWSTR pszAttr --  ������
     * @param    LPCWSTR pszValue --  ����ֵ
     * @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
     * @return   HRESULT -- ��������
     * Describe
     */
    STDMETHOD_(HRESULT, SetAttribute)(THIS_ LPCSTR pszAttr, LPCSTR pszValue, BOOL bLoading) PURE;

    /**
     * GetAttribute
     * @brief    ͨ����������ѯ����ֵ
     * @param    const SStringW & strAttr --  ������
     * @param    IStringW * pValue -- ����ֵ
     * @return   BOOL, TRUE:��ȡ�ɹ���FALSE:��ȡʧ�ܣ����Բ�����
     * Describe  Ĭ�Ϸ��ؿ�
     */
    STDMETHOD_(BOOL, GetAttribute)(THIS_ const IStringW *strAttr, IStringW *pValue) SCONST PURE;

    /**
     * OnAttribute
     * @brief    ���Դ������õķ���
     * @param    const SStringW & strAttribName --  ������
     * @param    const SStringW & strValue --  ������
     * @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
     * @param    HRESULT hr --  ���Դ�����
     * Describe  ��������ֱ�ӷ���
     */
    STDMETHOD_(HRESULT, AfterAttribute)
    (THIS_ const IStringW *strAttribName, const IStringW *strValue, BOOL bLoading, HRESULT hr) PURE;

    STDMETHOD_(BOOL, Init)(THIS_ HBITMAP hBmp, int nWid, int nHei) PURE;

    STDMETHOD_(void, SetPosition)(THIS_ int x, int y) PURE;

    STDMETHOD_(BOOL, SetVisible)(THIS_ BOOL bVisible, SWND owner) PURE;

    STDMETHOD_(BOOL, IsVisible)(THIS) SCONST PURE;

    STDMETHOD_(void, Draw)(THIS_ IRenderTarget * pRT) PURE;

    STDMETHOD_(RECT, GetRect)(THIS) SCONST PURE;
};

SNSEND