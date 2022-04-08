﻿#pragma once

#include <utilities-def.h>

#ifdef __cplusplus
#define DEF_VAL(x) =x
#else
#define DEF_VAL(x)
#endif//__cplusplus

#undef INTERFACE
#define INTERFACE IObjRef
DECLARE_INTERFACE(IObjRef)
{
	//!添加引用
	/*!
	*/
	STDMETHOD_(long,AddRef) (THIS) PURE;

	//!释放引用
	/*!
	*/
	STDMETHOD_(long,Release) (THIS) PURE;

	//!释放对象
	/*!
	*/
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
};
