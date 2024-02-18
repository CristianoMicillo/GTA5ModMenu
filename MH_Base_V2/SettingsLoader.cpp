#include "stdafx.h"
#include "json.hpp"
#include "SettingsLoader.hpp"

using json = nlohmann::json;




bool SETTINGS_LOADER::LoadSavedMenuSettings()
{
	

	return FALSE;
}




bool SETTINGS_LOADER::SaveCurrentMenuSettings()
{
	json deafultMenuSettings;

	notify_Custom((char*)Mod_Menu_Name"", "~g~Done!\nMenu settings saved");
	

	return FALSE;
}

