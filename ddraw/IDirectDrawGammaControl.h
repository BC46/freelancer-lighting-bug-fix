#pragma once

class m_IDirectDrawGammaControl : public IDirectDrawGammaControl, public AddressLookupTableObject
{
private:
	IDirectDrawGammaControl *ProxyInterface;
	REFIID WrapperID = IID_IDirectDrawGammaControl;

public:
	m_IDirectDrawGammaControl(IDirectDrawGammaControl *aOriginal) : ProxyInterface(aOriginal)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IDirectDrawGammaControl()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	DWORD GetDirectXVersion() { return 1; }
	REFIID GetWrapperType() { return WrapperID; }
	IDirectDrawGammaControl *GetProxyInterface() { return ProxyInterface; }
	m_IDirectDrawGammaControl *GetWrapperInterface() { return this; }

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj);
	STDMETHOD_(ULONG, AddRef) (THIS) ;
	STDMETHOD_(ULONG, Release) (THIS);
	/*** IDirectDrawGammaControl methods ***/
	STDMETHOD(GetGammaRamp)(THIS_ DWORD, LPDDGAMMARAMP);
	STDMETHOD(SetGammaRamp)(THIS_ DWORD, LPDDGAMMARAMP);
};
