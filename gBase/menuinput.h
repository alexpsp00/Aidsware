class CMenuInput
{
public:
	int iMouseX, iMouseY = 0;
	bool bClicked, bHolding, bHoldingO = false;
	void GetMouse();
	bool MouseIn(int, int, int, int);
	bool Clicked(int, int, int, int);
	bool Holding(int, int, int, int);
}; CMenuInput* pMenuInput = new CMenuInput;

void CMenuInput::GetMouse()
{
	POINT ptMouse;
	if (GetCursorPos(&ptMouse))
		if (ScreenToClient(hwCSGO, &ptMouse))
		{
			iMouseX = clamp(ptMouse.x, 1, iScreenWidth);
			iMouseY = clamp(ptMouse.y, 1, iScreenHeight);
		}

	if (GetAsyncKeyState(VK_LBUTTON))
		bHolding = true;
	else
		bHolding = false;

	if (!bHoldingO && bHolding)
		bClicked = true;
	else
		bClicked = false;
}

bool CMenuInput::MouseIn(int iStartX, int iStartY, int iEndX, int iEndY)
{
	if (iMouseX > iStartX && iMouseX < iEndX)
		if (iMouseY > iStartY && iMouseY < iEndY)
			return true;

	return false;
}

bool CMenuInput::Clicked(int iStartX, int iStartY, int iEndX, int iEndY)
{
	if (bClicked && MouseIn(iStartX, iStartY, iEndX, iEndY))
		return true;

	return false;
}

bool CMenuInput::Holding(int iStartX, int iStartY, int iEndX, int iEndY)
{
	if (bHolding && MouseIn(iStartX, iStartY, iEndX, iEndY))
		return true;

	return false;
}