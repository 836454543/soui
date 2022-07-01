#include "stdafx.h"
#include "SRoundImage.h"

namespace SOUI
{
	SRoundImage::SRoundImage()
	{
	}


	SRoundImage::~SRoundImage()
	{
	}

	SAutoRefPtr<IBitmapS> SRoundImage::GetRoundImage() const
	{
		if (!m_pSkin) return NULL;
		SAutoRefPtr<IRenderTarget> pRT; 
		CRect rc = GetClientRect();
		GETRENDERFACTORY->CreateRenderTarget(&pRT, rc.Width(), rc.Height());
		rc.MoveToXY(0, 0);
		pRT->ClearRect(&rc, 0);
		SAutoRefPtr<IBrushS> br;
		pRT->CreateSolidColorBrush(RGBA(0xBA, 0xB3, 0x99, 0xFF), &br);
		pRT->SelectObject(br,NULL);
		pRT->FillEllipse(&rc);
		pRT->SetXfermode(kSrcIn_Mode,NULL);
		m_pSkin->DrawByIndex(pRT, rc, 0);
		return (IBitmapS*)pRT->GetCurrentObject(OT_BITMAP);
	}

	void SRoundImage::OnPaint(IRenderTarget * pRT)
	{
		if (!m_img) return;
		CRect rc = GetClientRect();
		pRT->DrawBitmap(&rc, m_img, 0, 0,0xff);
	}

	void SRoundImage::OnSize(UINT nType, CSize size)
	{
		__baseCls::OnSize(nType, size);
		m_img = GetRoundImage();
	}

}
