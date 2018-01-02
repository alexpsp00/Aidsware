typedef void(__fastcall *PaintTraverseFn)(void*, void*, unsigned int, bool, bool);
PaintTraverseFn oPaintTraverse;

unsigned int drawPanel;

void __fastcall PaintTraverse(void* _this, void* _edx, unsigned int panel, bool forceRepaint, bool allowForce)
{
	oPaintTraverse(_this, _edx, panel, forceRepaint, allowForce);

	if (!drawPanel || drawPanel == NULL)
		if (strstr(Interfaces->VPanel->GetName(panel), "MatSystemTopPanel"))
			drawPanel = panel;

	if (panel != drawPanel)
		return;

	CBaseEntity* pLocalPlayer = (CBaseEntity*)Interfaces->ClientEntList->GetClientEntity(Interfaces->Engine->GetLocalPlayer());
	Interfaces->Engine->GetScreenSize(iScreenWidth, iScreenHeight);
	if (Interfaces->Engine->IsConnected() && Interfaces->Engine->IsInGame() && Vars::Visuals::Enabled)
	{
		for (int iPlayerIndex = 0; iPlayerIndex < Interfaces->Engine->GetMaxClients(); iPlayerIndex++)
		{
			CBaseEntity* pEntity = (CBaseEntity*)Interfaces->ClientEntList->GetClientEntity(iPlayerIndex);

			if (!pEntity || pEntity == pLocalPlayer || iPlayerIndex == Interfaces->Engine->GetLocalPlayer() || 0 >= pEntity->health() || pEntity->m_bDormant)
				continue;

			ESP->DrawPlayer(pEntity);
		}
	}

	mHackMenu.Tick();
}