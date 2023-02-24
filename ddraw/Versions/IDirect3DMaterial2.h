#pragma once

class m_IDirect3DMaterial2 : public IDirect3DMaterial2, public AddressLookupTableObject
{
private:
	std::unique_ptr<m_IDirect3DMaterialX> ProxyInterface;
	IDirect3DMaterial2 *RealInterface;
	REFIID WrapperID = IID_IDirect3DMaterial2;

public:
	m_IDirect3DMaterial2(IDirect3DMaterial2 *aOriginal) : RealInterface(aOriginal)
	{
		ProxyInterface = std::make_unique<m_IDirect3DMaterialX>((IDirect3DMaterial3*)RealInterface, 2, (m_IDirect3DMaterial3*)this);
		ProxyAddressLookupTable.SaveAddress(this, RealInterface);
	}
	~m_IDirect3DMaterial2()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	DWORD GetDirectXVersion() { return 2; }
	REFIID GetWrapperType() { return WrapperID; }
	IDirect3DMaterial2 *GetProxyInterface() { return RealInterface; }
	m_IDirect3DMaterialX *GetWrapperInterface() { return ProxyInterface.get(); }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	/*** IDirect3DMaterial2 methods ***/
	STDMETHOD(SetMaterial)(THIS_ LPD3DMATERIAL);
	STDMETHOD(GetMaterial)(THIS_ LPD3DMATERIAL);
	STDMETHOD(GetHandle)(THIS_ LPDIRECT3DDEVICE2, LPD3DMATERIALHANDLE);
};
