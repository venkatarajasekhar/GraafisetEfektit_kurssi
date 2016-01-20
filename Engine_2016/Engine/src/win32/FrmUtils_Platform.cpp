//--------------------------------------------------------------------------------------
// File: FrmUtils_Win32.cpp
// Desc: Win32 implementation of the graphics utility helper functions
//
// Author:     QUALCOMM, Advanced Content Group - Snapdragon SDK
//
//               Copyright (c) 2013 QUALCOMM Technologies, Inc. 
//                         All Rights Reserved. 
//                      QUALCOMM Proprietary/GTDR
//--------------------------------------------------------------------------------------
#include <graphics/win32/FrmPlatform.h>
#include <graphics/FrmUtils.h>

#include <EASTL/string.h>
#include <es_assert.h>

eastl::string g_strMessageLog;


//--------------------------------------------------------------------------------------
// Name: FrmAssert()
// Desc: Platform-dependent assert function.
//--------------------------------------------------------------------------------------
VOID FrmAssert( INT32 nExpression )
{
    assert( nExpression );
}

/*
//--------------------------------------------------------------------------------------
// Name: FrmLogMessage()
// Desc: Platform-dependent debug spew functions
//--------------------------------------------------------------------------------------
VOID FrmLogMessage( const CHAR* strPrefix, const CHAR* strMessage,
                    const CHAR* strPostFix )
{
    if( strPrefix )  OutputDebugStringA( strPrefix );
    if( strMessage ) OutputDebugStringA( strMessage );
    if( strPostFix ) OutputDebugStringA( strPostFix );

    if( strPrefix )  g_strMessageLog.append( strPrefix );
    if( strMessage ) g_strMessageLog.append( strMessage );
    if( strPostFix ) g_strMessageLog.append( strPostFix );
}*/


//--------------------------------------------------------------------------------------
// Name: FrmGetTime()
// Desc: Platform-dependent function to get the current time (in seconds).
//--------------------------------------------------------------------------------------
FLOAT32 FrmGetTime()
{
    static BOOL     bInitialized = FALSE;
    static LONGLONG m_llQPFTicksPerSec;
    static LONGLONG m_llBaseTime;
    if( FALSE == bInitialized )
    {
        LARGE_INTEGER qwTicksPerSec;
        QueryPerformanceFrequency( &qwTicksPerSec );
        m_llQPFTicksPerSec = qwTicksPerSec.QuadPart;

        LARGE_INTEGER qwTime;
        QueryPerformanceCounter( &qwTime );
        m_llBaseTime = qwTime.QuadPart;

        bInitialized = TRUE;
        return 0.0f;
    }

    // Get the current time
    LARGE_INTEGER qwTime;
    QueryPerformanceCounter( &qwTime );
    FLOAT64 fAppTime = (FLOAT64)( qwTime.QuadPart - m_llBaseTime ) / (FLOAT64) m_llQPFTicksPerSec;
    return (FLOAT32)fAppTime;
}

