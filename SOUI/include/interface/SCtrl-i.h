/************************************************************************/
/*   ���ﶨ��ؼ������ӿ�,���нӿڶ���IObjRef�̳�,����ָ���Լ��Ľӿ�ID  */
/************************************************************************/
#pragma once
#include <interface/SWindow-i.h>
#include <interface/SSkinobj-i.h>
#include <interface/SRender-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE ICtrl
DECLARE_INTERFACE_(ICtrl, IObjRef)
{
	STDMETHOD_(IWindow*, GetWindow)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IImageWnd
DECLARE_INTERFACE_IID_(IImageWnd, ICtrl,"42148B05-6223-46f6-B903-D42D84038546")
{

    STDMETHOD_(BOOL, SetSkin)(THIS_ ISkinObj *pSkin, int iFrame /*= 0*/, BOOL bAutoFree /*= TRUE*/) PURE;

    /**
     * SImageWnd::SetImage
     * @param    IBitmap * pBitmap -- ͼƬ����
     * @param    FilterLevel fl -- FilterLevel
     * @return   void
     *
     * Describe  ���û���ͼƬ
     */
    STDMETHOD_(void, SetImage)(THIS_ IBitmap *pBitmap, FilterLevel fl /*= kNone_FilterLevel*/) PURE;

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
    STDMETHOD_(ISkinObj *,GetSkin)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IAnimateImgWnd
DECLARE_INTERFACE_IID_(IAnimateImgWnd, ICtrl,"374A5086-AD38-4f15-83E0-002822E2595A")
{
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
DECLARE_INTERFACE_IID_(IProgress, ICtrl,"77407E2D-582B-4ef2-A33A-427C933BAA8C")
{
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

SNSEND