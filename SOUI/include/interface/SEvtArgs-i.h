#pragma once

#include <interface/sobject-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE IEvtArgs
DECLARE_INTERFACE_(IEvtArgs, IObject)
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
    STDMETHOD_(LPCWSTR, GetObjectClass)(THIS) SCONST PURE;

    /**
     * GetObjectType
     * @brief    ��ö�������
     * @return   int -- ��������
     * Describe  ����һ���麯����ע����GetClassType������
     */
    STDMETHOD_(int, GetObjectType)(THIS) SCONST PURE;

    /**
     * GetID
     * @brief    ��ȡ����ID
     * @return   int -- ����ID
     * Describe
     */
    STDMETHOD_(int, GetID)(THIS) SCONST PURE;

    /**
     * @brief ���ö���ID
     * @param nID int--����ID
     * @return
     */
    STDMETHOD_(void, SetID)(THIS_ int nID) PURE;

    /**
     * GetName
     * @brief    ��ȡ����Name
     * @return   LPCWSTR -- ����Name
     * Describe
     */
    STDMETHOD_(LPCWSTR, GetName)(THIS) SCONST PURE;

    /**
     * @brief ���ö���Name
     * @param pszName LPCWSTR -- ����Name
     * @return
     */
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
    STDMETHOD_(HRESULT, ISetAttribute)
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
    STDMETHOD_(HRESULT, ISetAttributeW)
    (THIS_ const IStringW *strAttribName, const IStringW *strValue, BOOL bLoading) PURE;

    /**
     * SetAttribute
     * @brief    ����һ����������
     * @param    LPCSTR pszAttr --  ������
     * @param    LPCSTR pszValue --  ����ֵ
     * @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
     * @return   HRESULT -- ��������
     * Describe
     */
    STDMETHOD_(HRESULT, SetAttribute)(THIS_ LPCSTR pszAttr, LPCSTR pszValue, BOOL bLoading) PURE;

    /**
     * SetAttribute
     * @brief    ����һ����������
     * @param    LPCWSTR pszAttr --  ������
     * @param    LPCWSTR pszValue --  ����ֵ
     * @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
     * @return   HRESULT -- ��������
     * Describe
     */
    STDMETHOD_(HRESULT, SetAttributeW)(THIS_ LPCWSTR pszAttr, LPCWSTR pszValue, BOOL bLoading) PURE;

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

    //-------------------------------------------------------------------------------------------

    /**
     * @brief ��ȡ�¼����Ͷ���
     * @return IObject *--�¼����Ͷ���
     */
    STDMETHOD_(IObject *, Sender)(THIS) PURE;

    /**
     * @brief ��ȡ�¼����Ͷ���ID
     * @return int--�¼����Ͷ���ID
     */
    STDMETHOD_(int, IdFrom)(THIS) SCONST PURE;

    /**
     * @brief �����¼��ķ��Ͷ���ID
     * @param id int--���Ͷ���ID
     * @return
     */
    STDMETHOD_(void, SetIdFrom)(THIS_ int id) PURE;

    /**
     * @brief ��ȡ�¼����Ͷ���Name
     * @return LPCWSTR--�¼����Ͷ���Name
     */
    STDMETHOD_(LPCWSTR, NameFrom)(THIS) SCONST PURE;

    /**
     * @brief �����¼����Ͷ���Name
     * @param name LPCWSTR--�¼����Ͷ���Name
     * @return
     */
    STDMETHOD_(void, SetNameFrom)(THIS_ LPCWSTR name) PURE;

    /**
     * @brief ��ȡ�¼��Ƿ���Ҫð�ݴ���
     * @return BOOL TRUE--ð�ݴ���
     */
    STDMETHOD_(BOOL, IsBubbleUp)(THIS) SCONST PURE;

    /**
     * @brief �����¼���ð�ݴ���
     * @param bBubbleUp BOOL, FALSE--��ֹ����
     * @return
     */
    STDMETHOD_(void, SetBubbleUp)(THIS_ BOOL bBubbleUp) PURE;

    /**
     * @brief ��ȡ�¼��������
     * @return UINT �¼��������
     */
    STDMETHOD_(UINT, HandleCount)(THIS) SCONST PURE;

    /**
     * @brief �����¼��������
     * @return
     */
    STDMETHOD_(void, IncreaseHandleCount)(THIS) PURE;

    /**
     * @brief ��ȡ�¼�������������ݽṹ��ָ��
     * @return �¼�������������ݽṹ��ָ��
     * @remark ��ͬ�¼����������ͬ�����ݣ���ȡָ����ת��Ϊ�ṹ��ָ�롣��Ҫ��C�ӿ�ʹ�á�
     */
    STDMETHOD_(LPVOID, Data)(THIS) PURE;
};

/*!
\brief
    Defines abstract interface which will be used when constructing various
    functor objects that bind slots to signals (or in CEGUI terms, handlers to
    events).
*/
#undef INTERFACE
#define INTERFACE IEvtSlot
DECLARE_INTERFACE_(IEvtSlot, IObjRef)
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
     * @brief ִ���¼�
     * @param pArg IEvtArgs* �¼�����
     * @return BOOL TRUE--��Ӧ���¼����¼���������ʹ�ü���, FALSE--�¼�û����Ӧ
     */
    STDMETHOD_(BOOL, Run)(THIS_ IEvtArgs * pArg) PURE;

    /**
     * @brief cloneһ���¼���
     * @return IEvtSlot * clone�����Ķ���
     */
    STDMETHOD_(IEvtSlot *, Clone)(THIS) SCONST PURE;

    /**
     * @brief �ж�����IEvtSlot�Ƿ����
     * @param sour IEvtSlot * �Ƚϵ�IEvtSlot
     * @return
     */
    STDMETHOD_(BOOL, Equal)(THIS_ const IEvtSlot *sour) SCONST PURE;

    /**
     * @brief ��ȡIEvtSlot����
     * @return UINT IEvtSlot����
     */
    STDMETHOD_(UINT, GetSlotType)(THIS) SCONST PURE;
};

/**
 * @brief �¼�����ص�
 * @param pEvt IEvtArgs * �¼�����
 * @param Ctx void * �¼�����������
 * @return BOOL TRUE--�¼����������Ӵ������
 */
typedef BOOL (*FunCallback)(IEvtArgs *pEvt, void *Ctx);

#define EventArgs IEvtArgs
SNSEND