typedef bool(__stdcall *CreateMoveFn)(float, CUserCmd*); // define createmove meme
CreateMoveFn oCreateMove; // make createmove backup

bool __stdcall CreateMove(float flInputSampleTime, CUserCmd* cmd)
{
	oCreateMove(flInputSampleTime, cmd);
	if (cmd->command_number == 0)
		return true;

	pLocalPlayer = (CBaseEntity*)Interfaces->ClientEntList->GetClientEntity(Interfaces->Engine->GetLocalPlayer());
	return true; 
}