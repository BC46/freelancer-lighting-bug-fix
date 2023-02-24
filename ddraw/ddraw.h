#pragma once

#define INITGUID

#include <ddraw.h>
#include <ddrawex.h>
#include <d3d.h>

class m_IDirect3D;
class m_IDirect3D2;
class m_IDirect3D3;
class m_IDirect3D7;
class m_IDirect3DX;
class m_IDirect3DDevice;
class m_IDirect3DDevice2;
class m_IDirect3DDevice3;
class m_IDirect3DDevice7;
class m_IDirect3DDeviceX;
class m_IDirect3DMaterial;
class m_IDirect3DMaterial2;
class m_IDirect3DMaterial3;
class m_IDirect3DMaterialX;
class m_IDirect3DTexture;
class m_IDirect3DTexture2;
class m_IDirect3DTextureX;
class m_IDirect3DVertexBuffer;
class m_IDirect3DVertexBuffer7;
class m_IDirect3DVertexBufferX;
class m_IDirect3DViewport;
class m_IDirect3DViewport2;
class m_IDirect3DViewport3;
class m_IDirect3DViewportX;
class m_IDirectDraw;
class m_IDirectDraw2;
class m_IDirectDraw3;
class m_IDirectDraw4;
class m_IDirectDraw7;
class m_IDirectDrawX;
class m_IDirectDrawSurface;
class m_IDirectDrawSurface2;
class m_IDirectDrawSurface3;
class m_IDirectDrawSurface4;
class m_IDirectDrawSurface7;
class m_IDirectDrawSurfaceX;

#include "AddressLookupTable.h"
#include "..\Common\Logging.h"

#define DDWRAPPER_TYPEX 0x80

typedef HRESULT(WINAPI *AcquireDDThreadLockProc)();
typedef DWORD(WINAPI *CompleteCreateSysmemSurfaceProc)(DWORD);
typedef HRESULT(WINAPI *D3DParseUnknownCommandProc)(LPVOID lpCmd, LPVOID *lpRetCmd);
typedef HRESULT(WINAPI *DDGetAttachedSurfaceLclProc)(DWORD, DWORD, DWORD);
typedef DWORD(WINAPI *DDInternalLockProc)(DWORD, DWORD);
typedef DWORD(WINAPI *DDInternalUnlockProc)(DWORD);
typedef HRESULT(WINAPI *DSoundHelpProc)(DWORD, DWORD, DWORD);
typedef HRESULT(WINAPI *DirectDrawCreateProc)(GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, IUnknown FAR *pUnkOuter);
typedef HRESULT(WINAPI *DirectDrawCreateClipperProc)(DWORD dwFlags, LPDIRECTDRAWCLIPPER *lplpDDClipper, LPUNKNOWN pUnkOuter);
typedef HRESULT(WINAPI *DirectDrawEnumerateAProc)(LPDDENUMCALLBACKA lpCallback, LPVOID lpContext);
typedef HRESULT(WINAPI *DirectDrawEnumerateExAProc)(LPDDENUMCALLBACKEXA lpCallback, LPVOID lpContext, DWORD dwFlags);
typedef HRESULT(WINAPI *DirectDrawEnumerateExWProc)(LPDDENUMCALLBACKEXW lpCallback, LPVOID lpContext, DWORD dwFlags);
typedef HRESULT(WINAPI *DirectDrawEnumerateWProc)(LPDDENUMCALLBACKW lpCallback, LPVOID lpContext);
typedef HRESULT(WINAPI *DirectDrawCreateExProc)(GUID FAR *lpGUID, LPVOID *lplpDD, REFIID riid, IUnknown FAR *pUnkOuter);
typedef HRESULT(WINAPI *DllCanUnloadNowProc)();
typedef HRESULT(WINAPI *DllGetClassObjectProc)(REFCLSID rclsid, REFIID riid, LPVOID *ppv);
typedef HRESULT(WINAPI *GetDDSurfaceLocalProc)(DWORD, DWORD, DWORD);
typedef DWORD(WINAPI *GetOLEThunkDataProc)(DWORD index);
typedef HRESULT(WINAPI *GetSurfaceFromDCProc)(HDC hdc, LPDIRECTDRAWSURFACE7 *lpDDS, DWORD);
typedef HRESULT(WINAPI *RegisterSpecialCaseProc)(DWORD, DWORD, DWORD, DWORD);
typedef HRESULT(WINAPI *ReleaseDDThreadLockProc)();
typedef HRESULT(WINAPI *SetAppCompatDataProc)(DWORD Type, DWORD Value);

DWORD GetIIDVersion(REFIID CalledID);
HRESULT ProxyQueryInterface(LPVOID ProxyInterface, REFIID CalledID, LPVOID * ppvObj, REFIID CallerID, LPVOID WrapperInterface);
void genericQueryInterface(REFIID riid, LPVOID * ppvObj);
extern AddressLookupTable<void> ProxyAddressLookupTable;

// Direct3D Version Wrappers
#include "Versions\IDirect3D.h"
#include "Versions\IDirect3D2.h"
#include "Versions\IDirect3D3.h"
#include "Versions\IDirect3D7.h"
#include "Versions\IDirect3DDevice.h"
#include "Versions\IDirect3DDevice2.h"
#include "Versions\IDirect3DDevice3.h"
#include "Versions\IDirect3DDevice7.h"
#include "Versions\IDirect3DMaterial.h"
#include "Versions\IDirect3DMaterial2.h"
#include "Versions\IDirect3DMaterial3.h"
#include "Versions\IDirect3DTexture.h"
#include "Versions\IDirect3DTexture2.h"
#include "Versions\IDirect3DVertexBuffer.h"
#include "Versions\IDirect3DVertexBuffer7.h"
#include "Versions\IDirect3DViewport.h"
#include "Versions\IDirect3DViewport2.h"
#include "Versions\IDirect3DViewport3.h"
// Direct3D Interfaces
#include "IDirect3DX.h"
#include "IDirect3DDeviceX.h"
#include "IDirect3DExecuteBuffer.h"
#include "IDirect3DLight.h"
#include "IDirect3DMaterialX.h"
#include "IDirect3DTextureX.h"
#include "IDirect3DVertexBufferX.h"
#include "IDirect3DViewportX.h"
// DirectDraw Version Wrappers
#include "Versions\IDirectDraw.h"
#include "Versions\IDirectDraw2.h"
#include "Versions\IDirectDraw3.h"
#include "Versions\IDirectDraw4.h"
#include "Versions\IDirectDraw7.h"
#include "Versions\IDirectDrawSurface.h"
#include "Versions\IDirectDrawSurface2.h"
#include "Versions\IDirectDrawSurface3.h"
#include "Versions\IDirectDrawSurface4.h"
#include "Versions\IDirectDrawSurface7.h"
// DirectDraw Interfaces
#include "IDirectDrawX.h"
#include "IDirectDrawClipper.h"
#include "IDirectDrawColorControl.h"
#include "IDirectDrawFactory.h"
#include "IDirectDrawGammaControl.h"
#include "IDirectDrawPalette.h"
#include "IDirectDrawSurfaceX.h"
