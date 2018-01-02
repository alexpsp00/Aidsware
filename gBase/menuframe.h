class CMenuFrame : public CMenuElement
{
public:
	const char* szText = "Default Frame";
	void SetText(const char*);
	void Center();
	void Paint();
};

void CMenuFrame::SetText(const char* szTextT)
{
	szText = szTextT;
}

void CMenuFrame::Center()
{
	iX = (iScreenWidth / 2) - (iSizeX / 2);
	iY = (iScreenHeight / 2) - (iSizeY / 2);
}

void CMenuFrame::Paint()
{	
	// base frame
	DrawRect(0, 24, iSizeX, iSizeY - 24, Color(255, 190, 200, 255));

	// tab/setting divider
	DrawRect(84, 20, 5, iSizeY - 20, Color(255, 0, 0, 255));

	// vertical lines
	for (int i = 1; i < 13; i++)
		DrawLine(12 - i, i, i - 1, 24, Color(255, 185, 0, 255));

	for (int i = 1; i < 15; i++)
		DrawLine(iSizeX - + (14 - i), 0, iSizeX - (i + 5), 24 - i, Color(60, 60, 60, 255));

	// fill title area
	DrawRect(14, 0, iSizeX - 23, 19, Color(0, 0, 255, 255));

	// title divider
	DrawRect(10, 28, iSizeX - 10, 5, Color(6, 6, 6, 255));

	// roflrainbow
	DrawRectRainbow(iSizeX - 15, 28, 12, iSizeY - 36, true, 255);

	// title
	DrawString(5, szText, iSizeX / 2, 12, Color(255, 255, 255, 255));
}