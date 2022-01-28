﻿/**
* Copyright (C) 2014-2050
* All rights reserved.
*
* @file       Sobject.hpp
* @brief
* @version    v1.0
* @author     SOUI group
* @date       2014/08/01
*
* Describe    the base class used in SOUI, which provides type identify of class in runtime
*             and implement attributes dispatcher described in XML.
*/

#pragma once
#include <interface/sobject-i.h>
#include <string/strcpcvt.h>
#include <xml/SXml.h>

SNSBEGIN


template<class T>
class SObjectImpl : public T
{
public:
	static void MarkAttributeHandled(SXmlAttr xmlAttr, bool bHandled)
	{
		xmlAttr.set_userdata(bHandled?1:0);
	}

	static bool IsAttributeHandled(SXmlAttr xmlAttr)
	{
		return xmlAttr.get_userdata()==1?true:false;
	}


	STDMETHOD_(BOOL,InitFromXml)(THIS_ IXmlNode * pXmlNode ) OVERRIDE
	{
		SXmlNode xmlNode(pXmlNode);

		if (!xmlNode) return FALSE;
#if defined(_DEBUG) && defined(PUGIXML_WCHAR_MODE)
		{
			IStringW *pStr = pXmlNode->ToString();
			m_strXml=SStringW(pStr);
			pStr->Release();
		}
#endif

		//设置当前对象的属性

		for (SXmlAttr attr = xmlNode.first_attribute(); attr; attr = attr.next_attribute())
		{
			if (IsAttributeHandled(attr)) continue;   //忽略已经被预处理的属性
			SetAttribute(attr.name(), attr.value(), TRUE);
		}
		//调用初始化完成接口
		OnInitFinished(pXmlNode);
		return TRUE;
	}

	STDMETHOD_(LPCWSTR,GetName)(THIS) SCONST OVERRIDE
	{
		return NULL;
	}
	STDMETHOD_(void,SetName)(THIS_ LPCWSTR pszName) OVERRIDE
	{
	}

	
	STDMETHOD_(int,GetID)(THIS) SCONST OVERRIDE
	{
		return 0;
	}

	STDMETHOD_(void,SetID)(THIS_ int nID) OVERRIDE
	{
	}

	STDMETHOD_(HRESULT,AfterAttribute)(THIS_ const IStringW * strAttribName,const IStringW * strValue, BOOL bLoading, HRESULT hr) OVERRIDE
	{
		UNREFERENCED_PARAMETER(strAttribName);
		UNREFERENCED_PARAMETER(strValue);
		UNREFERENCED_PARAMETER(bLoading);
		return hr;
	}

	STDMETHOD_(HRESULT,SetAttribute)(THIS_ LPCSTR  pszAttr, LPCSTR  pszValue, BOOL bLoading) OVERRIDE
	{
		return SetAttribute(S_CA2W(pszAttr,CP_UTF8),S_CA2W(pszValue,CP_UTF8),bLoading);
	}

	STDMETHOD_(HRESULT,SetAttributeW)(THIS_ LPCWSTR  pszAttr, LPCWSTR  pszValue, BOOL bLoading) OVERRIDE
	{
		return SetAttribute(SStringW(pszAttr),SStringW(pszValue),bLoading);
	}

	STDMETHOD_(HRESULT,ISetAttribute)(THIS_ const IStringA * strAttribName, const IStringA *  strValue, BOOL bLoading) OVERRIDE
	{
		SStringA strNameA(strAttribName);
		SStringA strValueA(strValue);
		SStringW strNameW=S_CA2W(strNameA);
		SStringW strValueW=S_CA2W(strValueA);
		return SetAttribute(strNameW, strValueW, bLoading);
	}

	STDMETHOD_(HRESULT,ISetAttributeW)(THIS_ const IStringW *  strAttr, const IStringW *  strValue, BOOL bLoading) OVERRIDE
	{
		return SetAttribute(SStringW(strAttr),SStringW(strValue),bLoading);
	}

	STDMETHOD_(LPCWSTR,GetObjectClass)(THIS_) SCONST OVERRIDE
	{
		return NULL;
	}

	STDMETHOD_(int,GetObjectType)(THIS)  SCONST OVERRIDE
	{
		return 0;
	}


	STDMETHOD_(BOOL,IsClass)(THIS_ LPCWSTR lpszName) SCONST OVERRIDE
	{
		UNREFERENCED_PARAMETER(lpszName);
		return FALSE;
	}

	STDMETHOD_(BOOL,GetAttribute)(THIS_ const IStringW * strAttr, IStringW * pValue) SCONST OVERRIDE
	{
		UNREFERENCED_PARAMETER(strAttr);
		UNREFERENCED_PARAMETER(pValue);
		return FALSE;
	}

	/**
	* OnInitFinished
	* @brief    属性初始化完成处理接口
	* @param    IXmlNode * xmlNode --  属性节点
	* @return   void
	* Describe
	*/ 
	STDMETHOD_(void,OnInitFinished)(THIS_ IXmlNode * xmlNode) OVERRIDE
	{
		UNREFERENCED_PARAMETER(xmlNode);
	}

	virtual HRESULT SetAttribute(const SStringW &strAttr,const SStringW & strValue,BOOL bLoading)
	{
		return DefAttributeProc(strAttr, strValue, bLoading);
	}

	virtual HRESULT DefAttributeProc(const SStringW &strAttr,const SStringW & strValue,BOOL bLoading)
	{
		return E_FAIL;
	}

#ifdef    _DEBUG
public:
	SStringW m_strXml;  //<** XML字符串，用于在调试时观察对象*/
#endif//_DEBUG
};


typedef SObjectImpl<IObject> SObject;

SNSEND