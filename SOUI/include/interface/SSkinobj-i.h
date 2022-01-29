﻿/**
 * Copyright (C) 2014-2050
 * All rights reserved.
 *
 * @file       SSkinobj-i.h
 * @brief
 * @version    v1.0
 * @author     SOUI group
 * @date       2014/08/01
 *
 * Describe    interface of SSkinObj
 */
#pragma once

#include <core/sobjType.h>
#include <interface/obj-ref-i.h>
#include <interface/SRender-i.h>

SNSBEGIN

/**
 * @struct     ISkinObj
 * @brief      Skin 对象
 *
 * Describe
 */
#undef INTERFACE
#define INTERFACE ISkinObj
DECLARE_INTERFACE_(ISkinObj, IObject)
{
    //!添加引用
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!释放引用
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!释放对象
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    /**
     * IsClass
     * @brief    判断this是不是属于指定的类型
     * @param    LPCWSTR lpszName --  测试类型名
     * @return   BOOL -- true是测试类型
     * Describe
     */
    STDMETHOD_(BOOL, IsClass)(THIS_ LPCWSTR lpszName) SCONST PURE;

    /**
     * GetObjectClass
     * @brief    获得类型名
     * @return   LPCWSTR -- 类型名
     * Describe  这是一个虚函数，注意与GetClassName的区别。
     */
    STDMETHOD_(LPCWSTR, GetObjectClass)(THIS) SCONST PURE;

    /**
     * GetObjectType
     * @brief    获得对象类型
     * @return   int -- 对象类型
     * Describe  这是一个虚函数，注意与GetClassType的区别。
     */
    STDMETHOD_(int, GetObjectType)(THIS) SCONST PURE;

    STDMETHOD_(int, GetID)(THIS) SCONST PURE;
    STDMETHOD_(void, SetID)(THIS_ int nID) PURE;

    STDMETHOD_(LPCWSTR, GetName)(THIS) SCONST PURE;
    STDMETHOD_(void, SetName)(THIS_ LPCWSTR pszName) PURE;

    /**
     * InitFromXml
     * @brief    从XML结节初始化SObject对象
     * @param    SXmlNode --  XML结节
     * @return   BOOL -- 成功返回TRUE
     * Describe
     */
    STDMETHOD_(BOOL, InitFromXml)(THIS_ IXmlNode * xmlNode) PURE;

    /**
     * OnInitFinished
     * @brief    属性初始化完成处理接口
     * @param    SXmlNode xmlNode --  属性节点
     * @return   void
     * Describe
     */
    STDMETHOD_(void, OnInitFinished)(THIS_ IXmlNode * xmlNode) PURE;

    /**
     * SetAttributeA
     * @brief    设置一个对象属性
     * @param    const IStringA * strAttribName --  属性名
     * @param    const IStringA * strValue --  属性值
     * @param    BOOL bLoading --  对象创建时由系统调用标志
     * @return   HRESULT -- 处理处理结果
     * Describe
     */
    STDMETHOD_(HRESULT, ISetAttribute)
    (THIS_ const IStringA *strAttribName, const IStringA *strValue, BOOL bLoading) PURE;

    /**
     * SetAttributeW
     * @brief    设置一个对象属性
     * @param    const IStringA *strAttribName --  属性名
     * @param    const IStringA *strValue --  属性值
     * @param    BOOL bLoading --  对象创建时由系统调用标志
     * @return   HRESULT -- 处理处理结果
     * Describe
     */
    STDMETHOD_(HRESULT, ISetAttributeW)
    (THIS_ const IStringW *strAttribName, const IStringW *strValue, BOOL bLoading) PURE;

    /**
     * SetAttribute
     * @brief    设置一个对象属性
     * @param    LPCWSTR pszAttr --  属性名
     * @param    LPCWSTR pszValue --  属性值
     * @param    BOOL bLoading --  对象创建时由系统调用标志
     * @return   HRESULT -- 处理处理结果
     * Describe
     */
    STDMETHOD_(HRESULT, SetAttribute)(THIS_ LPCSTR pszAttr, LPCSTR pszValue, BOOL bLoading) PURE;

	/**
     * SetAttribute
     * @brief    设置一个对象属性
     * @param    LPCWSTR pszAttr --  属性名
     * @param    LPCWSTR pszValue --  属性值
     * @param    BOOL bLoading --  对象创建时由系统调用标志
     * @return   HRESULT -- 处理处理结果
     * Describe
     */
    STDMETHOD_(HRESULT, SetAttributeW)(THIS_ LPCWSTR pszAttr, LPCWSTR pszValue, BOOL bLoading) PURE;

    /**
     * GetAttribute
     * @brief    通过属性名查询属性值
     * @param    const SStringW & strAttr --  属性名
     * @param    IStringW * pValue -- 属性值
     * @return   BOOL, TRUE:获取成功，FALSE:获取失败，属性不存在
     * Describe  默认返回空
     */
    STDMETHOD_(BOOL, GetAttribute)(THIS_ const IStringW *strAttr, IStringW *pValue) SCONST PURE;

    /**
     * OnAttribute
     * @brief    属性处理后调用的方法
     * @param    const SStringW & strAttribName --  属性名
     * @param    const SStringW & strValue --  属性名
     * @param    BOOL bLoading --  对象创建时由系统调用标志
     * @param    HRESULT hr --  属性处理结果
     * Describe  不做处理，直接返回
     */
    STDMETHOD_(HRESULT, AfterAttribute)
    (THIS_ const IStringW *strAttribName, const IStringW *strValue, BOOL bLoading, HRESULT hr) PURE;

    /**
     * DrawByState
     * @brief    将this绘制到RenderTarget上去
     * @param    IRenderTarget * pRT --  绘制用的RenderTarget
     * @param    LPCRECT rcDraw --  绘制位置
     * @param    DWORD dwState --  绘制状态
     * @param    BYTE byAlpha --  绘制透明度
     * @return   void
     * Describe
     */
    STDMETHOD_(void, DrawByState2)
    (THIS_ IRenderTarget * pRT, LPCRECT rcDraw, DWORD dwState, BYTE byAlpha) SCONST PURE;

    /**
     * DrawByState
     * @brief    将this绘制到RenderTarget上去
     * @param    IRenderTarget * pRT --  绘制用的RenderTarget
     * @param    LPCRECT rcDraw --  绘制位置
     * @param    DWORD dwState --  绘制状态
     * @return   void
     * Describe  使用SkinObj的GetAlpha属性绘制
     */
    STDMETHOD_(void, DrawByState)
    (THIS_ IRenderTarget * pRT, LPCRECT rcDraw, DWORD dwState) SCONST PURE;

    /**
     * DrawByIndex
     * @brief    将this绘制到RenderTarget上去
     * @param    IRenderTarget * pRT --  绘制用的RenderTarget
     * @param    LPCRECT rcDraw --  绘制位置
     * @param    int iState --  绘制Index
     * @param    BYTE byAlpha --  绘制透明度
     * @return   void
     * Describe
     */
    STDMETHOD_(void, DrawByIndex2)
    (THIS_ IRenderTarget * pRT, LPCRECT rcDraw, int iState, BYTE byAlpha) SCONST PURE;

    /**
     * DrawByIndex
     * @brief    将this绘制到RenderTarget上去
     * @param    IRenderTarget * pRT --  绘制用的RenderTarget
     * @param    LPCRECT rcDraw --  绘制位置
     * @param    int iState --  绘制Index
     * @return   void
     * Describe  使用SkinObj的GetAlpha属性绘制
     */
    STDMETHOD_(void, DrawByIndex)
    (THIS_ IRenderTarget * pRT, LPCRECT rcDraw, int iState) SCONST PURE;

    /**
     * GetSkinSize
     * @brief    获得Skin的默认大小
     * @return   SIZE -- Skin的默认大小
     * Describe  派生类应该根据skin的特点实现该接口
     */
    STDMETHOD_(SIZE, GetSkinSize)(THIS) SCONST PURE;

    /**
     * GetStates
     * @brief    获得skin对象包含的状态数量
     * @return   int -- 状态数量
     * Describe  默认为1
     */
    STDMETHOD_(int, GetStates)(THIS) SCONST PURE;

    /**
     * GetAlpha
     * @brief    获得skin对象包含透明度
     * @return   BYTE -- 透明度
     * Describe  [0-255]
     */
    STDMETHOD_(BYTE, GetAlpha)(THIS) SCONST PURE;

    /**
     * SetAlpha
     * @brief    设定skin对象包含透明度
     * @param    BYTE byAlpha-- 透明度
     * @return   void
     * Describe
     */
    STDMETHOD_(void, SetAlpha)(THIS_ BYTE byAlpha) PURE;

    /**
     * OnColorize
     * @brief    调整皮肤对象色调
     * @param    COLORREF cr -- 参考颜色
     * @return   void
     * Describe  默认不处理
     */
    STDMETHOD_(void, OnColorize)(THIS_ COLORREF cr) PURE;

    /**
     * GetScale
     * @brief    获取放大比例
     * @return   int 放大比例
     * Describe
     */
    STDMETHOD_(int, GetScale)(THIS) SCONST PURE;

    /**
     * Scale
     * @brief    将当前Skin按照指定比例缩放
     * @param    int nScale -- 放大比例
     * @return   ISkinObj * -- 缩放后的SkinObj
     * Describe
     */
    STDMETHOD_(ISkinObj *, Scale)(THIS_ int nScale) PURE;
};

SNSEND