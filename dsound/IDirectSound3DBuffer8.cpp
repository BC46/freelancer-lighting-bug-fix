/**
* Copyright (C) 2020 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "dsound.h"

HRESULT m_IDirectSound3DBuffer8::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	if ((riid == IID_IDirectSound3DBuffer || riid == IID_IDirectSound3DBuffer8 || riid == IID_IUnknown) && ppvObj)
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	HRESULT hr = ProxyInterface->QueryInterface(riid, ppvObj);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, ppvObj);
	}

	return hr;
}

ULONG m_IDirectSound3DBuffer8::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectSound3DBuffer8::Release()
{
	ULONG ref = ProxyInterface->Release();

	if (ref == 0)
	{
		delete this;
	}

	return ref;
}

// IDirectSound3DBuffer methods
HRESULT m_IDirectSound3DBuffer8::GetAllParameters(LPDS3DBUFFER pDs3dBuffer)
{
	return ProxyInterface->GetAllParameters(pDs3dBuffer);
}

HRESULT m_IDirectSound3DBuffer8::GetConeAngles(LPDWORD pdwInsideConeAngle, LPDWORD pdwOutsideConeAngle)
{
	return ProxyInterface->GetConeAngles(pdwInsideConeAngle, pdwOutsideConeAngle);
}

HRESULT m_IDirectSound3DBuffer8::GetConeOrientation(D3DVECTOR* pvOrientation)
{
	return ProxyInterface->GetConeOrientation(pvOrientation);
}

HRESULT m_IDirectSound3DBuffer8::GetConeOutsideVolume(LPLONG plConeOutsideVolume)
{
	return ProxyInterface->GetConeOutsideVolume(plConeOutsideVolume);
}

HRESULT m_IDirectSound3DBuffer8::GetMaxDistance(D3DVALUE* pflMaxDistance)
{
	return ProxyInterface->GetMaxDistance(pflMaxDistance);
}

HRESULT m_IDirectSound3DBuffer8::GetMinDistance(D3DVALUE* pflMinDistance)
{
	return ProxyInterface->GetMinDistance(pflMinDistance);
}

HRESULT m_IDirectSound3DBuffer8::GetMode(LPDWORD pdwMode)
{
	return ProxyInterface->GetMode(pdwMode);
}

HRESULT m_IDirectSound3DBuffer8::GetPosition(D3DVECTOR* pvPosition)
{
	return ProxyInterface->GetPosition(pvPosition);
}

HRESULT m_IDirectSound3DBuffer8::GetVelocity(D3DVECTOR* pvVelocity)
{
	return ProxyInterface->GetVelocity(pvVelocity);
}

HRESULT m_IDirectSound3DBuffer8::SetAllParameters(LPCDS3DBUFFER pcDs3dBuffer, DWORD dwApply)
{
	return ProxyInterface->SetAllParameters(pcDs3dBuffer, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetConeAngles(DWORD dwInsideConeAngle, DWORD dwOutsideConeAngle, DWORD dwApply)
{
	return ProxyInterface->SetConeAngles(dwInsideConeAngle, dwOutsideConeAngle, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetConeOrientation(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
	return ProxyInterface->SetConeOrientation(x, y, z, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetConeOutsideVolume(LONG lConeOutsideVolume, DWORD dwApply)
{
	return ProxyInterface->SetConeOutsideVolume(lConeOutsideVolume, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetMaxDistance(D3DVALUE flMaxDistance, DWORD dwApply)
{
	return ProxyInterface->SetMaxDistance(flMaxDistance, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetMinDistance(D3DVALUE flMinDistance, DWORD dwApply)
{
	return ProxyInterface->SetMinDistance(flMinDistance, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetMode(DWORD dwMode, DWORD dwApply)
{
	return ProxyInterface->SetMode(dwMode, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetPosition(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
	return ProxyInterface->SetPosition(x, y, z, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetVelocity(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
	return ProxyInterface->SetVelocity(x, y, z, dwApply);
}
