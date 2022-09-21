#line 1 "/home/pop-os/Interactivos/Unidad2/sf1-unidad2-ev-2022-20-aaaaaaaaas/sf1-unidad2-ev-2022-20-aaaaaaaaas/LedButtonApp/Library/PackageCache/com.unity.ide.visualstudio@2.0.16/Editor/COMIntegration/COMIntegration~/BStrHolder.h"
#pragma once
#include <OleAuto.h>

struct BStrHolder
{
	BStrHolder() :
		m_Str(NULL)
	{
	}

	BStrHolder(const wchar_t* str) :
		m_Str(SysAllocString(str))
	{
	}

	~BStrHolder()
	{
		if (m_Str != NULL)
			SysFreeString(m_Str);
	}

	operator BSTR() const
	{
		return m_Str;
	}

	BSTR* operator&()
	{
		if (m_Str != NULL)
		{
			SysFreeString(m_Str);
			m_Str = NULL;
		}

		return &m_Str;
	}

private:
	BSTR m_Str;
};
