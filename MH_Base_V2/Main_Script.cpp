#include "stdafx.h"
bool First_start = true;
void fisrt_start()
{
	using namespace Mod_Hub_Base;
	
	//Set YTD value names
	StreamTexture = "MH_BAse_";// Streaming Texture = Texture File - .ytd so write same name but without .ytd
	StreamTextureFile = StreamTexture + ".ytd";// Texture File (StreamTexture.ytd) //Do NOT TUCH THIS LINE!
	TextureName = "MH_Base_TxName";// Texture name, The name of the picture inside texture file(StreamTextureFile)/StreamTexture

	fstream appDpath(Documents_Patha().c_str());

	if (!fs::exists(Documents_Patha().c_str()))//checking path for ytd file exist or not
		fs::create_directory(Documents_Patha().c_str());
	string DownloadP = Documents_Patha() + string("\\") + StreamTextureFile/*This What the file going to be named when downloaded*/;
	

	g_YtdLoader->init(); // Documents_Patha() = appdata + menu name
	g_YtdLoader->loadYtd(Documents_Patha() + /*this ytd file path*/"\\" + StreamTextureFile, /*this is your file*/StreamTextureFile); // this start/booting upp your ytd file
	/*TO CHANGE THE SETTINGS IN THE MAIN TITLE GO THERE AND YOU WILL FIND
	YTD_Stream_Texture AND YTD_Texture_Name
	AND THERE YOU EDIT IN YOUR CUSTOM NAMES DOME.*/

	//todo: load Settings

	notify_Custom((char*)Mod_Menu_Name"", "~g~Loaded!!\nOpen Menu: F5");
}

namespace Mod_Hub_Base
{
	void main() {
		using namespace UserInterface;
		while (true) {
			g_UiManager->OnTick();
			/* Features */
			Function_update_Loop();
			if (First_start)
			{
				fisrt_start();
				First_start = false;
			}
			g_UiManager->AddSubmenu<RegularSubmenu>("Home", Home_Menu, [](RegularSubmenu* sub)
				{
					sub->AddOption<SubOption>("Local", nullptr, Local_Menu);
					sub->AddOption<SubOption>("Protection", nullptr, Protection_Main);
					sub->AddOption<SubOption>("Players", nullptr, Online_P_List);
					sub->AddOption<SubOption>("Settings", nullptr, SubmenuSettings);
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Local", Local_Menu, [](RegularSubmenu* sub)
				{
					sub->AddOption<BoolOption<bool>>("God mode", nullptr, &Godmode, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<bool>>("Money Drop", nullptr, &moneyd, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<bool>>("Invisible", nullptr, &Invisible, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<bool>>("vehicle color", nullptr, &macchina_col, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<bool>>("Vola con la macchina", nullptr, &macchinav, BoolDisplay::OnOff_Icon);
					sub->AddOption<RegularOption>("Max Health", "Maxing Health.", [] { ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 400); });
					sub->AddOption<RegularOption>("Genera ped", "genera ped.", [] { generaped(); });
					sub->AddOption<RegularOption>("Remove Wanted Levels", "Remove Wanted Levels", [] { PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID()), PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_PED_ID()); });
					sub->AddOption<RegularOption>("Fix Car", "Fix Car", [] { VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID())); });
					
					sub->AddOption<SubOption>("Teleport Menu", nullptr, Teleport_Menu);
					g_UiManager->AddSubmenu<RegularSubmenu>("Teleport Menu", Teleport_Menu, [](RegularSubmenu* sub)
						{
							sub->AddOption<RegularOption>("TP to Airport", "TP to Airport.", [] { tp_to_location(0); });
							sub->AddOption<RegularOption>("Tattos Vinewood", "Tattos Vinewood", [] { tp_to_location(1); });
							sub->AddOption<RegularOption>("Polito Bay", "Polito Bay", [] { tp_to_location(2); });
							sub->AddOption<RegularOption>("Mort Mutual Insurance", "Mort Mutual Insurance", [] { tp_to_location(3); });
						});

				});
			g_UiManager->AddSubmenu<RegularSubmenu>("Protection", Protection_Main, [](RegularSubmenu* sub)
				{
					sub->AddOption<BoolOption<bool>>("Anit CEO Kick", nullptr, &Protections::Anti_CEO_Kick, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<bool>>("Anit CEO ban", nullptr, &Protections::Anti_CEO_Ban, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<bool>>("Karma", nullptr, &Protections::g_Karma, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<bool>>("Log Script Events", nullptr, &g_LogScriptEvents, BoolDisplay::OnOff_Icon);
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Players", Online_P_List, [](RegularSubmenu* sub)
				{
					for (std::uint32_t i = 0; i < 32; ++i)
					{
						if (auto ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))
						{
							sub->AddOption<SubOption>(PLAYER::GET_PLAYER_NAME(i), nullptr, Selected_P_Menu, [=]
								{
									g_SelectedPlayer = i;
								});
						}
					}
				});

			g_UiManager->AddSubmenu<RegularSubmenu>(PLAYER::GET_PLAYER_NAME(g_SelectedPlayer), Selected_P_Menu, [](RegularSubmenu* sub)
				{
					sub->AddOption<RegularOption>("CEO Kick Player", "Kicking player from ceo.", [] {
							DWORD64 args[4] = { CEO_KICK/*Event code*/, g_SelectedPlayer, 0, 5 };
							hooks.trigger_script_event(1, args, 4, 1 << g_SelectedPlayer);
							Log::Msg(" || Player got CEO kicked: HAHAHHA");
						});
					sub->AddOption<RegularOption>("CEO ban Player", "ban player from ceo.", [] {
							DWORD64 args[3] = { CEO_BAN/*Event code*/, g_SelectedPlayer, 1 };
							hooks.trigger_script_event(1, args, 3, 1 << g_SelectedPlayer);
							Log::Msg(" || Player got CEO Banned: HAHAHHA");
						});
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Settings", SubmenuSettings, [](RegularSubmenu* sub)
				{
					sub->AddOption<SubOption>("Settings Loader", nullptr, SubmenuSettingsLoader);
					sub->AddOption<SubOption>("Header", nullptr, SubmenuSettingsHeader);
					sub->AddOption<SubOption>("Infobar", nullptr, SubmenuSettingsSubmenuBar);
					sub->AddOption<SubOption>("Options", nullptr, SubmenuSettingsOption);
					sub->AddOption<SubOption>("Footer", nullptr, SubmenuSettingsFooter);
					sub->AddOption<SubOption>("Description", nullptr, SubmenuSettingsDescription);
					sub->AddOption<SubOption>("Input", nullptr, SubmenuSettingsInput);
					sub->AddOption<SubOption>("Toggle Menu", nullptr, Bool_Menu);
					sub->AddOption<NumberOption<float>>("X Position", nullptr, &g_UiManager->m_PosX, 0.f, 1.f, 0.01f, 2);
					sub->AddOption<NumberOption<float>>("Y Position", nullptr, &g_UiManager->m_PosY, 0.f, 1.f, 0.01f, 2);
					sub->AddOption<NumberOption<float>>("Width", nullptr, &g_UiManager->m_Width, 0.01f, 1.f, 0.01f, 2);
					sub->AddOption<BoolOption<bool>>("Controller input", nullptr, &g_UiManager->m_Controllerinput, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<bool>>("Sounds", nullptr, &g_UiManager->m_Sounds, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<bool>>("ImGui Menu", "Start ImGui Menu", &g_UiManager->m_ImGuiActive, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<std::atomic_bool>>("Log Window", nullptr, &g_Settings.m_LogWindow, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<bool>>("Log Script Events", nullptr, &g_LogScriptEvents, BoolDisplay::OnOff_Icon);

					sub->AddOption<RegularOption>("Unload", "Unload the menu.", [] {Mod_running = false; });
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Bool Option", Bool_Menu, [](RegularSubmenu* sub)
				{
					sub->AddOption<BoolOption<bool>>("Toggle Rainbow Bool", nullptr, &g_UiManager->Toggle_RainbowBool, BoolDisplay::OnOff_Icon);
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Infobar", SubmenuSettingsSubmenuBar, [](RegularSubmenu* sub)
				{
					sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_SubmenuBarHeight, 0.01f, 0.1f, 0.001f, 3);
					sub->AddOption<NumberOption<float>>("Text Size", nullptr, &g_UiManager->m_SubmenuBarTextSize, 0.01f, 1.f, 0.01f, 2);

					sub->AddOption<NumberOption<std::uint8_t>>("Background R", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Background G", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Background B", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Background A", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Text R", nullptr, &g_UiManager->m_SubmenuBarTextColor.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Text G", nullptr, &g_UiManager->m_SubmenuBarTextColor.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Text B", nullptr, &g_UiManager->m_SubmenuBarTextColor.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Text A", nullptr, &g_UiManager->m_SubmenuBarTextColor.a, '\0', static_cast<std::uint8_t>(255));
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Options", SubmenuSettingsOption, [](RegularSubmenu* sub)
				{
					sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_OptionHeight, 0.01f, 0.1f, 0.001f, 3);
					sub->AddOption<NumberOption<float>>("Text Size", nullptr, &g_UiManager->m_OptionTextSize, 0.01f, 1.f, 0.01f, 2);

					sub->AddOption<NumberOption<std::uint8_t>>("Selected Background R", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Selected Background G", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Selected Background B", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Selected Background A", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background R", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background G", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background B", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background A", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));

					sub->AddOption<NumberOption<std::uint8_t>>("Selected Text R", nullptr, &g_UiManager->m_OptionSelectedTextColor.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Selected Text G", nullptr, &g_UiManager->m_OptionSelectedTextColor.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Selected Text B", nullptr, &g_UiManager->m_OptionSelectedTextColor.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Selected Text A", nullptr, &g_UiManager->m_OptionSelectedTextColor.a, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text R", nullptr, &g_UiManager->m_OptionUnselectedTextColor.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text G", nullptr, &g_UiManager->m_OptionUnselectedTextColor.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text B", nullptr, &g_UiManager->m_OptionUnselectedTextColor.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text A", nullptr, &g_UiManager->m_OptionUnselectedTextColor.a, '\0', static_cast<std::uint8_t>(255));
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Footer", SubmenuSettingsFooter, [](RegularSubmenu* sub)
				{
					sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_FooterHeight, 0.01f, 0.1f, 0.001f, 3);
					sub->AddOption<NumberOption<float>>("Sprite Size", nullptr, &g_UiManager->m_FooterSpriteSize, 0.01f, 1.f, 0.001f, 3);

					sub->AddOption<NumberOption<std::uint8_t>>("Background R", nullptr, &g_UiManager->m_FooterBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Background G", nullptr, &g_UiManager->m_FooterBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Background B", nullptr, &g_UiManager->m_FooterBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Background A", nullptr, &g_UiManager->m_FooterBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Sprite R", nullptr, &g_UiManager->m_FooterSpriteColor.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Sprite G", nullptr, &g_UiManager->m_FooterSpriteColor.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Sprite B", nullptr, &g_UiManager->m_FooterSpriteColor.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("Sprite A", nullptr, &g_UiManager->m_FooterSpriteColor.a, '\0', static_cast<std::uint8_t>(255));
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Settings Loader", SubmenuSettingsLoader, [](RegularSubmenu* sub)
				{
					sub->AddOption<RegularOption>("Save current menu settings", nullptr, [] { SETTINGS_LOADER::SaveCurrentMenuSettings(); });
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Header", SubmenuSettingsHeader, [](RegularSubmenu* sub)
				{
					sub->AddOption<ChooseOption<const char*, std::size_t>>("Type", nullptr, &Lists::HeaderTypesFrontend, &Lists::HeaderTypesPosition, true, []
						{
							g_UiManager->m_HeaderType = Lists::HeaderTypesBackend[Lists::HeaderTypesPosition];
						});

					switch (g_UiManager->m_HeaderType)
					{
					case HeaderType::Static:
						sub->AddOption<SubOption>("Background", nullptr, SubmenuSettingsHeaderStaticBackground);
						break;
					case HeaderType::Gradient:
						sub->AddOption<SubOption>("Gradient", nullptr, SubmenuSettingsHeaderGradientBackground);
						break;
					case HeaderType::Game_YTD:
						sub->AddOption<SubOption>("Game YTD", nullptr, SubmenuSettingsHeaderGradientBackground);
						break;
					case HeaderType::YTD:
						sub->AddOption<SubOption>("YTD", nullptr, SubmenuSettingsHeaderGradientBackground);
						break;
					}

					sub->AddOption<SubOption>("Text", nullptr, SubmenuSettingsHeaderText);
					sub->AddOption<NumberOption<float>>("Height", nullptr, &g_UiManager->m_HeaderHeight, 0.01f, 0.2f, 0.001f, 3);
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Header Background", SubmenuSettingsHeaderStaticBackground, [](RegularSubmenu* sub)
				{
					sub->AddOption<NumberOption<std::uint8_t>>("R", nullptr, &g_UiManager->m_HeaderBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("G", nullptr, &g_UiManager->m_HeaderBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("B", nullptr, &g_UiManager->m_HeaderBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("A", nullptr, &g_UiManager->m_HeaderBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Header Gradient", SubmenuSettingsHeaderGradientBackground, [](RegularSubmenu* sub)
				{
					sub->AddOption<BoolOption<bool>>("Transparent", nullptr, &g_UiManager->m_HeaderGradientTransparent, BoolDisplay::YesNo);
					sub->AddOption<BoolOption<bool>>("Flip", nullptr, &g_UiManager->m_HeaderGradientFlip, BoolDisplay::YesNo);

					sub->AddOption<NumberOption<std::uint8_t>>("R1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("G1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("B1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("A1", nullptr, &g_UiManager->m_HeaderGradientColorLeft.a, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("R2", nullptr, &g_UiManager->m_HeaderGradientColorRight.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("G2", nullptr, &g_UiManager->m_HeaderGradientColorRight.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("B2", nullptr, &g_UiManager->m_HeaderGradientColorRight.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("A2", nullptr, &g_UiManager->m_HeaderGradientColorRight.a, '\0', static_cast<std::uint8_t>(255));
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Header Text", SubmenuSettingsHeaderText, [](RegularSubmenu* sub)
				{
					sub->AddOption<BoolOption<bool>>("Enable Rainbow Title", nullptr, &g_UiManager->Rainbowmenu_titleBool, BoolDisplay::OnOff_Icon);
					sub->AddOption<BoolOption<bool>>("Enable", nullptr, &g_UiManager->m_HeaderText, BoolDisplay::OnOff_Icon);
					sub->AddOption<NumberOption<float>>("Size", nullptr, &g_UiManager->m_HeaderTextSize, 0.1f, 2.f, 0.01f, 2);
					sub->AddOption<NumberOption<std::uint8_t>>("R", nullptr, &g_UiManager->m_HeaderTextColor.r, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("G", nullptr, &g_UiManager->m_HeaderTextColor.g, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("B", nullptr, &g_UiManager->m_HeaderTextColor.b, '\0', static_cast<std::uint8_t>(255));
					sub->AddOption<NumberOption<std::uint8_t>>("A", nullptr, &g_UiManager->m_HeaderTextColor.a, '\0', static_cast<std::uint8_t>(255));
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Description", SubmenuSettingsDescription, [](RegularSubmenu* sub)
				{
					sub->AddOption<NumberOption<float>>("Padding", "Padding before the description rect.", &g_UiManager->m_DescriptionHeightPadding, 0.01f, 1.f, 0.001f,
					3);
					sub->AddOption<NumberOption<float>>("Height", "Size of the description rect.", &g_UiManager->m_DescriptionHeight, 0.01f, 1.f, 0.001f, 3);
					sub->AddOption<NumberOption<float>>("Text Size", "Size of the description text.", &g_UiManager->m_DescriptionTextSize, 0.1f, 2.f, 0.01f, 2);
				});

			g_UiManager->AddSubmenu<RegularSubmenu>("Input", SubmenuSettingsInput, [](RegularSubmenu* sub)
				{
					sub->AddOption<NumberOption<std::int32_t>>("Open Delay", nullptr, &g_UiManager->m_OpenDelay, 10, 1000, 10, 0);
					sub->AddOption<NumberOption<std::int32_t>>("Back Delay", nullptr, &g_UiManager->m_BackDelay, 10, 1000, 10, 0);
					sub->AddOption<NumberOption<std::int32_t>>("Enter Delay", nullptr, &g_UiManager->m_EnterDelay, 10, 1000, 10, 0);
					sub->AddOption<NumberOption<std::int32_t>>("Vertical Delay", nullptr, &g_UiManager->m_VerticalDelay, 10, 1000, 10, 0);
					sub->AddOption<NumberOption<std::int32_t>>("Horizontal Delay", nullptr, &g_UiManager->m_HorizontalDelay, 10, 1000, 10, 0);
				});

			//here is more test stuff you can look at
			/*g_UiManager->AddSubmenu<RegularSubmenu>(BIG_TRANSLATE("Demo_sub"), SubmenuTest, [](RegularSubmenu* sub)
		{
			sub->AddOption<RegularOption>(BIG_TRANSLATE("RegularOption_demo"), "A regular option.", []
			{
				g_Logger->Info("You pressed the test option");
			});

			static bool testBool1{};
			sub->AddOption<BoolOption<bool>>(BIG_TRANSLATE("BoolOnOff_demo"), nullptr, &testBool1, BoolDisplay::OnOff_Icon);
			static bool testBool2{};
			sub->AddOption<BoolOption<bool>>(BIG_TRANSLATE("BoolYesNo_demo"), nullptr, &testBool2, BoolDisplay::YesNo);

			static std::int32_t int32Test{ 69 };
			sub->AddOption<NumberOption<std::int32_t>>("Int32", nullptr, &int32Test, 0, 100);

			static std::int64_t int64Test{ 420 };
			sub->AddOption<NumberOption<std::int64_t>>("Int64", nullptr, &int64Test, 0, 1000, 10);

			static float floatTest{ 6.9f };
			sub->AddOption<NumberOption<float>>("Float", nullptr, &floatTest, 0.f, 10.f, 0.1f, 1);

			static std::vector<std::uint64_t> vector{ 1, 2, 3 };
			static std::size_t vectorPos{};

			sub->AddOption<ChooseOption<const char*, std::size_t>>("Array", nullptr, &Lists::DemoList, &Lists::DemoListPos);
			sub->AddOption<ChooseOption<std::uint64_t, std::size_t>>("Vector", nullptr, &vector, &vectorPos);
		});*/

			WAIT(0);
		}
	}

	void ScriptMain() {
		srand(GetTickCount());
		main();
	}

	//ImgUi Menu
	void ScriptImGuiMain() {
		//ImGui Menu
		if (g_UiManager->m_Opened && g_UiManager->m_ImGuiActive)
		{
			g_Settings.m_LockMouse = true;

			ImGui::SetNextWindowSize(ImVec2(800, 550), ImGuiCond_FirstUseEver);
			ImGui::SetNextWindowPos(ImVec2(500, 500), ImGuiCond_FirstUseEver);
			if (ImGui::Begin("ImGui Sample : " Mod_Menu_Name)) {

				ImGui::Checkbox("Active ImGui Menu", &g_UiManager->m_ImGuiActive);

				if (ImGui::Button("Print Hello"))
					Log::Msg("Heeelo BROOOOOOOOOOOO");

				ImGui::End();
			}
		}
		else
			g_Settings.m_LockMouse = false;

		//sample
		if (ImGui::Begin("Hello there")) {
			ImGui::Text("Game version: %s", g_GameVariables->m_GameBuild);
			ImGui::End();
		}
	}
}
