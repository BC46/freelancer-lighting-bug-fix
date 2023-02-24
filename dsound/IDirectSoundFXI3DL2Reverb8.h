#pragma once

class m_IDirectSoundFXI3DL2Reverb8 : public IDirectSoundFXI3DL2Reverb8, public AddressLookupTableObject
{
private:
	LPDIRECTSOUNDFXI3DL2REVERB8 ProxyInterface;

public:
	m_IDirectSoundFXI3DL2Reverb8(LPDIRECTSOUNDFXI3DL2REVERB8 pSound8) : ProxyInterface(pSound8)
	{
		ProxyAddressLookupTable.SaveAddress(this, ProxyInterface);
	}
	~m_IDirectSoundFXI3DL2Reverb8()
	{
		ProxyAddressLookupTable.DeleteAddress(this);
	}

	LPDIRECTSOUNDFXI3DL2REVERB8 GetProxyInterface() { return ProxyInterface; }

	// IUnknown methods
	STDMETHOD(QueryInterface)(THIS_ _In_ REFIID, _Outptr_ LPVOID*);
	STDMETHOD_(ULONG, AddRef)(THIS);
	STDMETHOD_(ULONG, Release)(THIS);

	// IDirectSoundFXI3DL2Reverb methods
	STDMETHOD(SetAllParameters)(THIS_ _In_ LPCDSFXI3DL2Reverb pcDsFxI3DL2Reverb);
	STDMETHOD(GetAllParameters)(THIS_ _Out_ LPDSFXI3DL2Reverb pDsFxI3DL2Reverb);
	STDMETHOD(SetPreset)(THIS_ DWORD dwPreset);
	STDMETHOD(GetPreset)(THIS_ _Out_ LPDWORD pdwPreset);
	STDMETHOD(SetQuality)(THIS_ LONG lQuality);
	STDMETHOD(GetQuality)(THIS_ _Out_ LONG *plQuality);
};
