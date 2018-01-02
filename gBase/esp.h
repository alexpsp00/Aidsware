class CESP
{
public:
	void DrawPlayer(CBaseEntity*);
}; CESP* ESP = new CESP;

void CESP::DrawPlayer(CBaseEntity* pEntity)
{
	if (!Vars::Visuals::Enabled)
		return;

	player_info_t pInfo;
	Interfaces->Engine->GetPlayerInfo(pEntity->index, &pInfo);

	Vector vecMax = pEntity->GetCollideable()->OBBMaxs();
	Vector vecPos, vecPos3D;
	Vector vecTop, vecTop3D;
	vecPos3D = pEntity->m_vecOrigin;
	vecTop3D = vecPos3D + Vector(0, 0, vecMax.z);
	if (!WorldToScreen(vecPos3D, vecPos, iScreenWidth, iScreenHeight) || !WorldToScreen(vecTop3D, vecTop, iScreenWidth, iScreenHeight))
		return;

	Color colDraw;
	colDraw = (pEntity->team() == 3) ? Color(0, 75, 255, 255) : Color(255, 190, 70, 255);

	int iAdd = 13;
	int iMiddle = (vecPos.y - vecTop.y) + 4;
	int iWidth = iMiddle / 3.5;

	if (Vars::Visuals::Name)
	{
		Draw::DrawStringB(4, vecTop.x + iWidth + 4, vecTop.y + iAdd, Color(255, 255, 255, 255), pInfo.name);
		iAdd = iAdd + 17;
	}

	if (Vars::Visuals::Box2D)
		Draw::DrawOutlinedRect(vecTop.x - iWidth + (iMiddle / 16), vecTop.y, iWidth * 2 - (iWidth / 10), iMiddle + 4, colDraw);

	if (Vars::Visuals::Health)
	{
		int iClampedHealth = pEntity->health();
		if (iClampedHealth >= 101)
			iClampedHealth = 100;

		int iHealthG = iClampedHealth * 2.55;
		int iHealthR = 255 - iHealthG;
		int iHeight = (int)((float)iMiddle * 0.01f * (float)iClampedHealth);

		Draw::DrawRect(vecTop.x - iWidth - 8 - (2), vecTop.y, 2, iHeight, Color(0, 255, 0, 255));
		Draw::DrawStringB(4, vecTop.x + iWidth + 4, vecTop.y + iAdd, Color(iHealthR, iHealthG, 0, 255), "HELTHE|| %s", std::to_string(pEntity->health()).c_str());
		iAdd = iAdd + 12;
	}
}