#include "Durazno.h"
#include "Plugin.h"

void __fastcall DrawDesktopText(LPCWSTR text)
{
	// Get desktop DC
	HDC hdc = GetWindowDC(NULL);
	
	// Calculate large font size
	long lfHeight = -MulDiv(36, GetDeviceCaps(hdc, LOGPIXELSY), 72);

	// Create new large font
	HFONT hNewFont = CreateFont(lfHeight, 0, 0, 0, 0, TRUE, 0, 0, 0, 0, 0, 0, 0, L"Times New Roman");
	HFONT hOldFont = (HFONT)SelectObject(hdc, hNewFont);

	// Location
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = 500;
	rc.bottom = 300;

	// Do text drawing
	DrawText(hdc, text, -1, &rc, DT_LEFT);

	// Always select the old font back into the DC
	SelectObject(hdc, hOldFont);

	// Release the font if created
	if (hNewFont)
	{
		DeleteObject(hNewFont);
	}

	// Release desktop DC
	ReleaseDC(NULL, hdc);
}

void __fastcall PluginSetState(f64 rumble, XINPUT_VIBRATION* pVibration)
{
	//pVibration->wLeftMotorSpeed = Clamp(pVibration->wLeftMotorSpeed * rumble);
	//pVibration->wRightMotorSpeed = Clamp(pVibration->wRightMotorSpeed * rumble);

	// Draw text
	DrawDesktopText(L"Working");
}
