﻿#include "souistd.h"
#include "core/SWindowMgr.h"

SNSBEGIN

//////////////////////////////////////////////////////////////////////////
SWindowMgr::SWindowMgr()
    : m_hNextWnd(SWND_INVALID)
{
    ::InitializeCriticalSection(&m_lockWndMap);
}

SWindowMgr::~SWindowMgr()
{
    ::DeleteCriticalSection(&m_lockWndMap);
}

// Get SWindow pointer from handle
SWindow *SWindowMgr::GetWindow(SWND swnd)
{
    if (!swnd)
        return NULL;
    SWindow *pRet = NULL;
    ::EnterCriticalSection(&getSingleton().m_lockWndMap);

    getSingleton().GetKeyObject(swnd, pRet);
    ::LeaveCriticalSection(&getSingleton().m_lockWndMap);
    return pRet;
}

bool SWindowMgr::IsWindow(SWND swnd)
{
    return GetWindow(swnd) != NULL;
}

// Specify a handle to a SWindow
SWND SWindowMgr::NewWindow(SWindow *pSwnd)
{
    SASSERT(pSwnd);
    ::EnterCriticalSection(&getSingleton().m_lockWndMap);

    SWND swndNext = ++getSingleton().m_hNextWnd;
    getSingleton().AddKeyObject(swndNext, pSwnd);
    ::LeaveCriticalSection(&getSingleton().m_lockWndMap);

    return swndNext;
}

// Destroy SWindow
BOOL SWindowMgr::DestroyWindow(SWND swnd)
{
    ::EnterCriticalSection(&getSingleton().m_lockWndMap);

    BOOL bRet = getSingleton().RemoveKeyObject(swnd);

    ::LeaveCriticalSection(&getSingleton().m_lockWndMap);

    return bRet;
}

SNSEND