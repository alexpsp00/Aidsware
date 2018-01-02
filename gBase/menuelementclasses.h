int iCurrentTab = 1;

class CMenuTab : public CMenuElement
{
public:
	int iTabIndex;
	const char* szText;
	void SetTab(int);
	void SetText(const char*);
	void Paint();
	void Think();
};

void CMenuTab::SetTab(int iTabIndexT)
{
	iTabIndex = iTabIndexT;
}

void CMenuTab::SetText(const char* szTextT)
{
	szText = szTextT;
}

void CMenuTab::Paint()
{
	DrawRect(5, 0, iSizeX - 5, iSizeY, Color(0, 0, 255, 255));
	DrawString2(5, szText, (iCurrentTab == iTabIndex) ? 13 : 9, (iSizeY / 2) + 2, Color(rand() % 255, rand() % 255, rand() % 255, 255));
	if (iCurrentTab == iTabIndex)
		DrawRect(0, 0, 4, iSizeY, Color(0, 255, 255, 255));
	else
		DrawRect(0, 0, 4, iSizeY, Color(255, 185, 0, 255));

	if (iCurrentTab != iTabIndex && pMenuInput->MouseIn(iX, iY, iX + iSizeX, iY + iSizeY))
		DrawRect(0, 0, 4, iSizeY, Color(70, 60, 150, 125));
}

void CMenuTab::Think()
{
	if (pMenuInput->Clicked(iX, iY, iX + iSizeX, iY + iSizeY))
		iCurrentTab = iTabIndex;
}

class CMenuCheckbox : public CMenuElement
{
public:
	int iTab;
	bool* bVar;
	const char* szText;
	void SetTab(int);
	void SetVar(bool*);
	void SetText(const char*);
	void Paint();
	void Think();
};

void CMenuCheckbox::SetTab(int iTabT)
{
	iTab = iTabT;
}

void CMenuCheckbox::SetVar(bool* bVarT)
{
	bVar = bVarT;
}

void CMenuCheckbox::SetText(const char* szTextT)
{
	szText = szTextT;
}

void CMenuCheckbox::Paint()
{
	if (iTab != iCurrentTab)
		return;

	DrawOutlinedRect(0, 0, iSizeY, iSizeY, Color(125, 39, 85, 255));
	if (*bVar)
		DrawRect(1, 1, iSizeY - 2, iSizeY - 2, Color(90, 200, 69, 255));

	DrawString2(5, szText, iSizeY + 4, iSizeY / 2 + 1, Color(255, 185, 0, 255));
}

void CMenuCheckbox::Think()
{
	if (iTab != iCurrentTab)
		return;

	if (pMenuInput->Clicked(iX, iY, iX + iSizeY, iY + iSizeY))
		*bVar = !*bVar;
}

class CMenuSlider : public CMenuElement
{
public:

};

class CMenuDropdown : public CMenuElement
{
public:

};