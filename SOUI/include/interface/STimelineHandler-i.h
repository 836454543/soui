#pragma once
#include <utilities-def.h>

SNSBEGIN
/**
 * @struct     ITimelineHandler
 * @brief      ʱ���ᴦ��ӿ�
 *
 * Describe
 */
#undef INTERFACE
#define INTERFACE ITimelineHandler
DECLARE_INTERFACE(ITimelineHandler)
{
    STDMETHOD_(void, OnNextFrame)(THIS_) PURE;
};

#undef INTERFACE
#define INTERFACE ITimelineHandlersMgr
DECLARE_INTERFACE(ITimelineHandlersMgr)
{
    STDMETHOD_(BOOL, RegisterTimelineHandler)(THIS_ ITimelineHandler * pHandler) PURE;

    STDMETHOD_(BOOL, UnregisterTimelineHandler)(THIS_ ITimelineHandler * pHandler) PURE;
};
SNSEND