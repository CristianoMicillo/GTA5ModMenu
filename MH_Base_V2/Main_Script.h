#pragma once
namespace Mod_Hub_Base
{
	void ScriptMain();
	void ScriptImGuiMain();
}
enum Submenu : std::uint32_t
{
	Home_Menu,
	Local_Menu,
	Teleport_Menu,
	Vehicle_Menu,

	Protection_Main,

	Online_P_List,
	Selected_P_Menu,

	SubmenuSettings,
	SubmenuSettingsLoader,
	SubmenuSettingsHeader,
	SubmenuSettingsHeaderStaticBackground,
	SubmenuSettingsHeaderGradientBackground,
	SubmenuSettingsHeaderText,
	SubmenuSettingsSubmenuBar,
	SubmenuSettingsOption,
	SubmenuSettingsFooter,
	SubmenuSettingsDescription,
	SubmenuSettingsInput,
	Bool_Menu
};