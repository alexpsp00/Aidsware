// thanks to my good friend liquid obsidian for some of this :p

class CMenuElement
{
public:
	int iX, iY, iSizeX, iSizeY;
	bool bVisible;
	void SetPos(int, int);
	void GetPos(int &, int &);
	void SetSize(int, int);
	void GetSize(int &, int &);
	void DrawRect(int, int, int, int, Color);
	void DrawRectRainbow(int, int, int, int, bool, int);
	void DrawOutlinedRect(int, int, int, int, Color);
	void DrawLine(int, int, int, int, Color);
	void DrawString(HFont, const char*, int, int, Color);
	void DrawString2(HFont, const char*, int, int, Color);
	void SetVisible(bool);
	void Tick();
	virtual void Paint() {};
	virtual void Think() {};

	CMenuElement()
	{
		iX = 0;
		iY = 0;
		iSizeX = 50;
		iSizeY = 50;
		bVisible = true;
	}
};

void CMenuElement::SetPos(int iXT, int iYT)
{
	iX = iXT;
	iY = iYT;
}

void CMenuElement::GetPos(int &iXT, int &iXY)
{
	iXT = iX;
	iXY = iY;
}

void CMenuElement::SetSize(int iSizeXT, int iSizeXY)
{
	iSizeX = iSizeXT;
	iSizeY = iSizeXY;
}

void CMenuElement::GetSize(int &iSizeXT, int &iSizeXY)
{
	iSizeXT = iSizeX;
	iSizeXY = iSizeY;
}

void CMenuElement::DrawRect(int iDrawX, int iDrawY, int iWidth, int iHeight, Color colDraw)
{
	Draw::DrawRect(iX + iDrawX, iY + iDrawY, clamp(iWidth, 1, iX + iSizeX), clamp(iHeight, 1, iY + iSizeY), colDraw);
}

void CMenuElement::DrawRectRainbow(int iDrawX, int iDrawY, int iWidth, int iHeight, bool bVertical = false, int iAlpha = 255)
{
	Draw::DrawRectRainbow(iX + iDrawX, iY + iDrawY, clamp(iWidth, 1, iX + iSizeX), clamp(iHeight, 1, iY + iSizeY), bVertical, iAlpha);
}

void CMenuElement::DrawOutlinedRect(int iDrawX, int iDrawY, int iWidth, int iHeight, Color colDraw)
{
	Draw::DrawOutlinedRect(iX + iDrawX, iY + iDrawY, clamp(iWidth, 1, iX + iSizeX), clamp(iHeight, 1, iY + iSizeY), colDraw);
}

void CMenuElement::DrawLine(int iStartX, int iStartY, int iEndX, int iEndY, Color colDraw)
{
	Interfaces->Surface->DrawSetColor(colDraw);
	Interfaces->Surface->DrawLine(iX + iStartX, iY + iStartY, clamp(iX + iEndX, 1, iX + iSizeX), clamp(iY + iEndY, 1, iY + iSizeY));
}

void CMenuElement::DrawString(HFont hfFont, const char* szText, int iStringX, int iStringY, Color colDraw)
{
	Draw::DrawStringA(hfFont, clamp(iX + iStringX, 1, iX + iSizeX), clamp(iY + iStringY, 1, iY + iSizeY), colDraw, szText);
}

void CMenuElement::DrawString2(HFont hfFont, const char* szText, int iStringX, int iStringY, Color colDraw)
{
	Draw::DrawStringB(hfFont, clamp(iX + iStringX, 1, iX + iSizeX), clamp(iY + iStringY, 1, iY + iSizeY), colDraw, szText);
}

void CMenuElement::SetVisible(bool bVisibleT)
{
	bVisible = bVisibleT;
}

void CMenuElement::Tick()
{
	if (!bVisible)
		return;

	Paint();
	Think();
}