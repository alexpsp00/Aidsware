class CMenu
{
public:
	int iMouseValue = 0;
	bool bMenuOpenTick = false;
	bool bMenuInit = false;

	///////////////////////////////////////////////////////////////////
	// menu defines
	CMenuFrame* mfFrame = new CMenuFrame;

	CMenuTab* mtAimbot = new CMenuTab;
	CMenuTab* mtVisuals = new CMenuTab;
	CMenuTab* mtMisc = new CMenuTab;
	CMenuTab* mtHvH = new CMenuTab;

	CMenuCheckbox* mcAimEnabled = new CMenuCheckbox;
	CMenuCheckbox* mcAimSilent = new CMenuCheckbox;
	CMenuCheckbox* mcAimIgnoreTeam = new CMenuCheckbox;
	CMenuCheckbox* mcAimAutoShoot = new CMenuCheckbox;
	CMenuCheckbox* mcAimAutoStop = new CMenuCheckbox;
	CMenuCheckbox* mcAimAutoCrouch = new CMenuCheckbox;

	CMenuCheckbox* mcVisEnabled = new CMenuCheckbox;
	CMenuCheckbox* mcVisName = new CMenuCheckbox;
	CMenuCheckbox* mcVisBox2D = new CMenuCheckbox;
	CMenuCheckbox* mcVisHealth = new CMenuCheckbox;
	CMenuCheckbox* mcVisChams = new CMenuCheckbox;
	///////////////////////////////////////////////////////////////////

	void Init();
	void Tick();
}; CMenu mHackMenu;

void CMenu::Init()
{
	// base frame
	mfFrame->SetText("ayimwear v2 kool kids klub edition :^)))");
	mfFrame->SetSize(500, 350);
	mfFrame->SetVisible(true);
	mfFrame->Center();

	// tabs
	int iMenuX, iMenuY;
	mfFrame->GetPos(iMenuX, iMenuY);
	mtAimbot->SetTab(1);
	mtAimbot->SetText("aymbot");
	mtAimbot->SetSize(84, 24);
	mtAimbot->SetVisible(true);
	mtAimbot->SetPos(iMenuX, iMenuY + 28);

	mtVisuals->SetTab(2);
	mtVisuals->SetText("vizuals");
	mtVisuals->SetSize(84, 24);
	mtVisuals->SetVisible(true);
	mtVisuals->SetPos(iMenuX, iMenuY + 54);

	mtMisc->SetTab(3);
	mtMisc->SetText("misculaneous");
	mtMisc->SetSize(84, 24);
	mtMisc->SetVisible(true);
	mtMisc->SetPos(iMenuX, iMenuY + 80);

	mtHvH->SetTab(4);
	mtHvH->SetText("hake vs heke");
	mtHvH->SetSize(84, 24);
	mtHvH->SetVisible(true);
	mtHvH->SetPos(iMenuX, iMenuY + 106);

	// tab contents
	int iY = 38;
	int iAdd = 18;
	mcAimEnabled->SetVar(&Vars::Aimbot::Enabled);
	mcAimEnabled->SetTab(1);
	mcAimEnabled->SetText("ineabld");
	mcAimEnabled->SetSize(128, 16);
	mcAimEnabled->SetVisible(true);
	mcAimEnabled->SetPos(iMenuX + 94, iMenuY + iY);

	mcAimSilent->SetVar(&Vars::Aimbot::Silent);
	mcAimSilent->SetTab(1);
	mcAimSilent->SetText("selente ayme");
	mcAimSilent->SetSize(128, 16);
	mcAimSilent->SetVisible(true);
	mcAimSilent->SetPos(iMenuX + 94, iMenuY + (iY += iAdd));

	mcAimIgnoreTeam->SetVar(&Vars::Aimbot::IgnoreTeam);
	mcAimIgnoreTeam->SetTab(1);
	mcAimIgnoreTeam->SetText("ignoer teme");
	mcAimIgnoreTeam->SetSize(128, 16);
	mcAimIgnoreTeam->SetVisible(true);
	mcAimIgnoreTeam->SetPos(iMenuX + 94, iMenuY + (iY += iAdd));

	mcAimAutoShoot->SetVar(&Vars::Aimbot::AutoShoot);
	mcAimAutoShoot->SetTab(1);
	mcAimAutoShoot->SetText("uatoshooote");
	mcAimAutoShoot->SetSize(128, 16);
	mcAimAutoShoot->SetVisible(true);
	mcAimAutoShoot->SetPos(iMenuX + 94, iMenuY + (iY += iAdd));

	mcAimAutoStop->SetVar(&Vars::Aimbot::AutoStop);
	mcAimAutoStop->SetTab(1);
	mcAimAutoStop->SetText("atuostope");
	mcAimAutoStop->SetSize(128, 16);
	mcAimAutoStop->SetVisible(true);
	mcAimAutoStop->SetPos(iMenuX + 94, iMenuY + (iY += iAdd));

	mcAimAutoCrouch->SetVar(&Vars::Aimbot::AutoStop);
	mcAimAutoCrouch->SetTab(1);
	mcAimAutoCrouch->SetText("cool crouch automatic XD");
	mcAimAutoCrouch->SetSize(128, 16);
	mcAimAutoCrouch->SetVisible(true);
	mcAimAutoCrouch->SetPos(iMenuX + 94, iMenuY + (iY += iAdd));

	iY = 38;
	mcVisEnabled->SetVar(&Vars::Visuals::Enabled);
	mcVisEnabled->SetTab(2);
	mcVisEnabled->SetText("eynablead");
	mcVisEnabled->SetSize(128, 16);
	mcVisEnabled->SetVisible(true);
	mcVisEnabled->SetPos(iMenuX + 94, iMenuY + iY);

	mcVisName->SetVar(&Vars::Visuals::Name);
	mcVisName->SetTab(2);
	mcVisName->SetText("nayme");
	mcVisName->SetSize(128, 16);
	mcVisName->SetVisible(true);
	mcVisName->SetPos(iMenuX + 94, iMenuY + (iY += iAdd));

	mcVisBox2D->SetVar(&Vars::Visuals::Box2D);
	mcVisBox2D->SetTab(2);
	mcVisBox2D->SetText("two de baxes");
	mcVisBox2D->SetSize(128, 16);
	mcVisBox2D->SetVisible(true);
	mcVisBox2D->SetPos(iMenuX + 94, iMenuY + (iY += iAdd));

	mcVisHealth->SetVar(&Vars::Visuals::Health);
	mcVisHealth->SetTab(2);
	mcVisHealth->SetText("helth");
	mcVisHealth->SetSize(128, 16);
	mcVisHealth->SetVisible(true);
	mcVisHealth->SetPos(iMenuX + 94, iMenuY + (iY += iAdd));

	mcVisChams->SetVar(&Vars::Visuals::Chams);
	mcVisChams->SetTab(2);
	mcVisChams->SetText("chems");
	mcVisChams->SetSize(128, 16);
	mcVisChams->SetVisible(true);
	mcVisChams->SetPos(iMenuX + 94, iMenuY + (iY += iAdd));
}

void CMenu::Tick()
{
	if (!bMenuInit)
	{
		bMenuInit = true;
		Init();
	}

	static ConVar* cvMouseEnabled = Interfaces->Cvar->FindVar("cl_mouseenable");

	if (!bMenuOpen)
	{
		if (bMenuOpenTick)
		{
			bMenuOpenTick = false;
			cvMouseEnabled->SetValue(iMouseValue);
		}

		return;
	}

	if (!bMenuOpenTick)
	{
		bMenuOpenTick = true;
		iMouseValue = cvMouseEnabled->GetRawValue().m_nValue;
	}

	cvMouseEnabled->SetValue(0);
	pMenuInput->GetMouse();
	pMenuInput->bHoldingO = pMenuInput->bHolding;

	///////////////////////////////////////////////////////////////////
	// tick menu frame && tabs
	mfFrame->Tick();
	mtAimbot->Tick();
	mtVisuals->Tick();
	mtMisc->Tick();
	mtHvH->Tick();

	// tick tab contents
	mcAimEnabled->Tick();
	mcAimSilent->Tick();
	mcAimIgnoreTeam->Tick();
	mcAimAutoShoot->Tick();
	mcAimAutoStop->Tick();
	mcAimAutoCrouch->Tick();

	mcVisEnabled->Tick();
	mcVisName->Tick();
	mcVisBox2D->Tick();
	mcVisHealth->Tick();
	mcVisChams->Tick();
}