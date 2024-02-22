#include "stdafx.h"
#include "json.hpp"
#include "SettingsLoader.hpp"

using json = nlohmann::json;




bool SETTINGS_LOADER::LoadSavedMenuSettings()
{
	std::string filename = Documents_Patha() + string("\\savedSettings.json");
	std::ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		notify_Custom((char*)Mod_Menu_Name"", "~r~ERROR!\nSave settings first!");
		return true;
	}
	std::string jsonString((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	inputFile.close();

	json menuSettings;
	inputFile >> menuSettings;
	//////////SETTINGS
	g_UiManager->m_ImGuiActive = menuSettings["Settings"]["ImGuiActive"];
	g_UiManager->m_Opened = menuSettings["Settings"]["Opened"];
	g_UiManager->m_MouseLocked = menuSettings["Settings"]["MouseLocked"];

	std::string PosXString = menuSettings["Settings"]["PosX"];
	float PosX = std::stof(PosXString);
	g_UiManager->m_PosX = PosX;

	std::string PosYString = menuSettings["Settings"]["PosY"];
	float PosY = std::stof(PosYString);
	g_UiManager->m_PosX = PosY;

	std::string WidthString = menuSettings["Settings"]["Width"];
	float Width = std::stof(WidthString);
	g_UiManager->m_PosX = Width;

	g_UiManager->m_OptionsPerPage = menuSettings["Settings"]["OptionsPerPage"];
	g_UiManager->m_Sounds = menuSettings["Settings"]["Sounds"];
	g_UiManager->m_Controllerinput = menuSettings["Settings"]["ControllerInput"];
	g_UiManager->Toggle_RainbowBool = menuSettings["Settings"]["Toggle_RainbowBool"];

	g_UiManager->m_Toggle_Off.r = menuSettings["Settings"]["Toggle_Off"]["r"];
	g_UiManager->m_Toggle_Off.g = menuSettings["Settings"]["Toggle_Off"]["g"];
	g_UiManager->m_Toggle_Off.b = menuSettings["Settings"]["Toggle_Off"]["b"];
	g_UiManager->m_Toggle_Off.a = menuSettings["Settings"]["Toggle_Off"]["a"];


	///////////INPUT
	g_UiManager->m_OpenDelay = menuSettings["Input"]["OpenDelay"];
	g_UiManager->m_BackDelay = menuSettings["Input"]["BackDelay"];
	g_UiManager->m_EnterDelay = menuSettings["Input"]["EnterDelay"];
	g_UiManager->m_VerticalDelay = menuSettings["Input"]["VerticalDelay"];
	g_UiManager->m_HorizontalDelay = menuSettings["Input"]["HorizontalDelay"];

	//////////////Header
	g_UiManager->m_HeaderType = menuSettings["Header"]["HeaderType"];

	std::string HeaderHeightString = menuSettings["Header"]["HeaderHeight"];
	float HeaderHeight = std::stof(HeaderHeightString);
	g_UiManager->m_HeaderHeight = HeaderHeight;

	g_UiManager->m_HeaderText = menuSettings["Header"]["HeaderText"];
	g_UiManager->Rainbowmenu_titleBool = menuSettings["Header"]["Rainbowmenu_titleBool"];

	std::string HeaderTextSizeString = menuSettings["Header"]["HeaderTextSize"];
	float HeaderTextSize = std::stof(HeaderTextSizeString);
	g_UiManager->m_HeaderTextSize = HeaderTextSize;

	g_UiManager->m_HeaderFont = menuSettings["Header"]["HeaderFont"];
	g_UiManager->m_HeaderTextColor.r = menuSettings["Header"]["HeaderTextColor"]["r"];
	g_UiManager->m_HeaderTextColor.g = menuSettings["Header"]["HeaderTextColor"]["g"];
	g_UiManager->m_HeaderTextColor.b = menuSettings["Header"]["HeaderTextColor"]["b"];
	g_UiManager->m_HeaderTextColor.a = menuSettings["Header"]["HeaderTextColor"]["a"];


	//////Static
	g_UiManager->m_HeaderBackgroundColor.r = menuSettings["Header"]["StaticHeader"]["HeaderBackgroundColor"]["r"];
	g_UiManager->m_HeaderBackgroundColor.g = menuSettings["Header"]["StaticHeader"]["HeaderBackgroundColor"]["g"];
	g_UiManager->m_HeaderBackgroundColor.b = menuSettings["Header"]["StaticHeader"]["HeaderBackgroundColor"]["b"];
	g_UiManager->m_HeaderBackgroundColor.a = menuSettings["Header"]["StaticHeader"]["HeaderBackgroundColor"]["a"];

	////gradient
	std::string HeaderGradientFillerString = menuSettings["GradientHeader"]["HeaderGradientFiller"];
	float HeaderGradientFiller = std::stof(HeaderGradientFillerString);
	g_UiManager->m_HeaderGradientFiller = HeaderGradientFiller;
	g_UiManager->m_HeaderGradientFlip = menuSettings["GradientHeader"]["HeaderGradientFlip"];
	std::string HeaderGradientStretchString = menuSettings["GradientHeader"]["HeaderGradientStretch"];
	float HeaderGradientStretch = std::stof(HeaderGradientStretchString);
	g_UiManager->m_HeaderGradientStretch = HeaderGradientStretch;
	g_UiManager->m_HeaderGradientTransparent = menuSettings["GradientHeader"]["HeaderGradientTransparent"];

	g_UiManager->m_HeaderGradientColorLeft.r = menuSettings["Header"]["GradientHeader"]["r"];
	g_UiManager->m_HeaderGradientColorLeft.g = menuSettings["Header"]["GradientHeader"]["g"];
	g_UiManager->m_HeaderGradientColorLeft.b = menuSettings["Header"]["GradientHeader"]["b"];
	g_UiManager->m_HeaderGradientColorLeft.a = menuSettings["Header"]["GradientHeader"]["a"];

	g_UiManager->m_HeaderGradientColorRight.r = menuSettings["Header"]["GradientHeader"]["r"];
	g_UiManager->m_HeaderGradientColorRight.g = menuSettings["Header"]["GradientHeader"]["g"];
	g_UiManager->m_HeaderGradientColorRight.b = menuSettings["Header"]["GradientHeader"]["b"];
	g_UiManager->m_HeaderGradientColorRight.a = menuSettings["Header"]["GradientHeader"]["a"];

	////////SUBMENU
	std::string SubmenuBarHeightString = menuSettings["SubMenu"]["SubmenuBarHeight"];
	float SubmenuBarHeight = std::stof(SubmenuBarHeightString);
	g_UiManager->m_SubmenuBarHeight = SubmenuBarHeight;

	std::string SubmenuBarTextSizeString = menuSettings["SubMenu"]["SubmenuBarTextSize"];
	float SubmenuBarTextSize = std::stof(SubmenuBarTextSizeString);
	g_UiManager->m_SubmenuBarTextSize = SubmenuBarTextSize;

	g_UiManager->m_SubmenuBarFont = menuSettings["SubMenu"]["SubmenuBarFont"];

	std::string SubmenuBarPaddingString = menuSettings["SubMenu"]["SubmenuBarPadding"];
	float SubmenuBarPadding = std::stof(SubmenuBarPaddingString);
	g_UiManager->m_SubmenuBarPadding = SubmenuBarPadding;

	g_UiManager->m_SubmenuBarBackgroundColor.r = menuSettings["SubMenu"]["SubmenuBarBackgroundColor"]["r"];
	g_UiManager->m_SubmenuBarBackgroundColor.g = menuSettings["SubMenu"]["SubmenuBarBackgroundColor"]["g"];
	g_UiManager->m_SubmenuBarBackgroundColor.b = menuSettings["SubMenu"]["SubmenuBarBackgroundColor"]["b"];
	g_UiManager->m_SubmenuBarBackgroundColor.a = menuSettings["SubMenu"]["SubmenuBarBackgroundColor"]["a"];

	g_UiManager->m_SubmenuBarTextColor.r = menuSettings["SubMenu"]["SubmenuBarTextColor"]["r"];
	g_UiManager->m_SubmenuBarTextColor.g = menuSettings["SubMenu"]["SubmenuBarTextColor"]["g"];
	g_UiManager->m_SubmenuBarTextColor.b = menuSettings["SubMenu"]["SubmenuBarTextColor"]["b"];
	g_UiManager->m_SubmenuBarTextColor.a = menuSettings["SubMenu"]["SubmenuBarTextColor"]["a"];

	//////Options
	std::string OptionHeightString = menuSettings["Options"]["OptionHeight"];
	float OptionHeight = std::stof(OptionHeightString);
	g_UiManager->m_OptionHeight = OptionHeight;

	std::string OptionTextSizeString = menuSettings["Options"]["OptionTextSize"];
	float OptionTextSize = std::stof(OptionTextSizeString);
	g_UiManager->m_OptionTextSize = OptionTextSize;

	g_UiManager->m_OptionFont = menuSettings["Options"]["OptionFont"];

	std::string OptionPaddingString = menuSettings["Options"]["OptionPadding"];
	float OptionPadding = std::stof(OptionPaddingString);
	g_UiManager->m_OptionPadding = OptionPadding;


	g_UiManager->m_SubmenuBarTextColor.r = menuSettings["Options"]["SubmenuBarTextColor"]["r"];
	g_UiManager->m_SubmenuBarTextColor.g = menuSettings["Options"]["SubmenuBarTextColor"]["g"];
	g_UiManager->m_SubmenuBarTextColor.b = menuSettings["Options"]["SubmenuBarTextColor"]["b"];
	g_UiManager->m_SubmenuBarTextColor.a = menuSettings["Options"]["SubmenuBarTextColor"]["a"];

	g_UiManager->m_SubmenuBarTextColor.r = menuSettings["Options"]["SubmenuBarTextColor"]["r"];
	g_UiManager->m_SubmenuBarTextColor.g = menuSettings["Options"]["SubmenuBarTextColor"]["g"];
	g_UiManager->m_SubmenuBarTextColor.b = menuSettings["Options"]["SubmenuBarTextColor"]["b"];
	g_UiManager->m_SubmenuBarTextColor.a = menuSettings["Options"]["SubmenuBarTextColor"]["a"];

	g_UiManager->m_SubmenuBarTextColor.r = menuSettings["Options"]["SubmenuBarTextColor"]["r"];
	g_UiManager->m_SubmenuBarTextColor.g = menuSettings["Options"]["SubmenuBarTextColor"]["g"];
	g_UiManager->m_SubmenuBarTextColor.b = menuSettings["Options"]["SubmenuBarTextColor"]["b"];
	g_UiManager->m_SubmenuBarTextColor.a = menuSettings["Options"]["SubmenuBarTextColor"]["a"];

	g_UiManager->m_SubmenuBarTextColor.r = menuSettings["Options"]["SubmenuBarTextColor"]["r"];
	g_UiManager->m_SubmenuBarTextColor.g = menuSettings["Options"]["SubmenuBarTextColor"]["g"];
	g_UiManager->m_SubmenuBarTextColor.b = menuSettings["Options"]["SubmenuBarTextColor"]["b"];
	g_UiManager->m_SubmenuBarTextColor.a = menuSettings["Options"]["SubmenuBarTextColor"]["a"];

	g_UiManager->m_SubmenuBarTextColor.r = menuSettings["Options"]["SubmenuBarTextColor"]["r"];
	g_UiManager->m_SubmenuBarTextColor.g = menuSettings["Options"]["SubmenuBarTextColor"]["g"];
	g_UiManager->m_SubmenuBarTextColor.b = menuSettings["Options"]["SubmenuBarTextColor"]["b"];
	g_UiManager->m_SubmenuBarTextColor.a = menuSettings["Options"]["SubmenuBarTextColor"]["a"];



	/////////FOOTER
	std::string FooterHeightString = menuSettings["Footer"]["FooterHeight"];
	float FooterHeight = std::stof(FooterHeightString);
	g_UiManager->m_FooterHeight = FooterHeight;

	std::string FooterSpriteSizeString = menuSettings["Footer"]["FooterSpriteSize"];
	float FooterSpriteSize = std::stof(FooterSpriteSizeString);
	g_UiManager->m_FooterSpriteSize = FooterSpriteSize;

	g_UiManager->m_FooterBackgroundColor.r = menuSettings["Footer"]["FooterBackgroundColor"]["r"];
	g_UiManager->m_FooterBackgroundColor.g = menuSettings["Footer"]["FooterBackgroundColor"]["g"];
	g_UiManager->m_FooterBackgroundColor.b = menuSettings["Footer"]["FooterBackgroundColor"]["b"];
	g_UiManager->m_FooterBackgroundColor.a = menuSettings["Footer"]["FooterBackgroundColor"]["a"];

	g_UiManager->m_FooterSpriteColor.r = menuSettings["Footer"]["FooterSpriteColor"]["r"];
	g_UiManager->m_FooterSpriteColor.g = menuSettings["Footer"]["FooterSpriteColor"]["g"];
	g_UiManager->m_FooterSpriteColor.b = menuSettings["Footer"]["FooterSpriteColor"]["b"];
	g_UiManager->m_FooterSpriteColor.a = menuSettings["Footer"]["FooterSpriteColor"]["a"];


	////////DESCRIPTION
	std::string DescriptionHeightPaddingString = menuSettings["Description"]["DescriptionHeightPadding"];
	float DescriptionHeightPadding = std::stof(DescriptionHeightPaddingString);
	g_UiManager->m_DescriptionHeightPadding = DescriptionHeightPadding;

	std::string DescriptionHeightString = menuSettings["Description"]["DescriptionHeight"];
	float DescriptionHeight = std::stof(DescriptionHeightString);
	g_UiManager->m_DescriptionHeight = DescriptionHeight;

	std::string DescriptionTextSizeString = menuSettings["Description"]["DescriptionTextSize"];
	float DescriptionTextSize = std::stof(DescriptionTextSizeString);
	g_UiManager->m_DescriptionTextSize = DescriptionTextSize;

	g_UiManager->m_DescriptionFont = menuSettings["Description"]["DescriptionFont"];

	g_UiManager->m_DescriptionBackgroundColor.r = menuSettings["Description"]["DescriptionBackgroundColor"]["r"];
	g_UiManager->m_DescriptionBackgroundColor.g = menuSettings["Description"]["DescriptionBackgroundColor"]["g"];
	g_UiManager->m_DescriptionBackgroundColor.b = menuSettings["Description"]["DescriptionBackgroundColor"]["b"];
	g_UiManager->m_DescriptionBackgroundColor.a = menuSettings["Description"]["DescriptionBackgroundColor"]["a"];

	g_UiManager->m_DescriptionTextColor.r = menuSettings["Description"]["DescriptionTextColor"]["r"];
	g_UiManager->m_DescriptionTextColor.g = menuSettings["Description"]["DescriptionTextColor"]["g"];
	g_UiManager->m_DescriptionTextColor.b = menuSettings["Description"]["DescriptionTextColor"]["b"];
	g_UiManager->m_DescriptionTextColor.a = menuSettings["Description"]["DescriptionTextColor"]["a"];

	std::string DescriptionSpriteSizeString = menuSettings["Description"]["DescriptionSpriteSize"];
	float DescriptionSpriteSize = std::stof(DescriptionSpriteSizeString);
	g_UiManager->m_DescriptionSpriteSize = DescriptionSpriteSize;

	std::string DescriptionPaddingString = menuSettings["Description"]["DescriptionPadding"];
	float DescriptionPadding = std::stof(DescriptionPaddingString);
	g_UiManager->m_DescriptionPadding = DescriptionPadding;


	g_UiManager->m_DescriptionSpriteColor.r = menuSettings["Description"]["DescriptionSpriteColor"]["r"];
	g_UiManager->m_DescriptionSpriteColor.g = menuSettings["Description"]["DescriptionSpriteColor"]["g"];
	g_UiManager->m_DescriptionSpriteColor.b = menuSettings["Description"]["DescriptionSpriteColor"]["b"];
	g_UiManager->m_DescriptionSpriteColor.a = menuSettings["Description"]["DescriptionSpriteColor"]["a"];

	return false;
}


bool SaveSettings()
{
	json menuSettings; //GENERAL

	
	////////////////
	json settings;
	settings["ImGuiActive"] = g_UiManager->m_ImGuiActive;
	settings["Opened"] = g_UiManager->m_Opened;
	settings["MouseLocked"] = g_UiManager->m_MouseLocked;
	std::string m_PosXString = std::to_string(g_UiManager->m_PosX);
	settings["PosX"] = m_PosXString;
	std::string m_PosYString = std::to_string(g_UiManager->m_PosY);
	settings["PosY"] = m_PosYString;
	std::string m_WidthString = std::to_string(g_UiManager->m_Width);
	settings["Width"] = m_WidthString;
	settings["OptionsPerPage"] = g_UiManager->m_OptionsPerPage;
	settings["Sounds"] = g_UiManager->m_Sounds;
	settings["ControllerInput"] = g_UiManager->m_Controllerinput;
	settings["Toggle_RainbowBool"] = g_UiManager->Toggle_RainbowBool;
	settings["Toggle_Off"] = {
		{"r", g_UiManager->m_Toggle_Off.r},
		{"g", g_UiManager->m_Toggle_Off.g},
		{"b", g_UiManager->m_Toggle_Off.b},
		{"a", g_UiManager->m_Toggle_Off.a}
	};

	///////////////////
	json input;
	input["OpenDelay"] = g_UiManager->m_OpenDelay;
	input["BackDelay"] = g_UiManager->m_BackDelay;
	input["EnterDelay"] = g_UiManager->m_EnterDelay;
	input["VerticalDelay"] = g_UiManager->m_VerticalDelay;
	input["HorizontalDelay"] = g_UiManager->m_HorizontalDelay;

	///////////////////
	json header;
	header["HeaderType"] = g_UiManager->m_HeaderType;
	header["HeaderHeight"] = g_UiManager->m_HeaderHeight;
	header["HeaderText"] = g_UiManager->m_HeaderText;
	header["Rainbowmenu_titleBool"] = g_UiManager->Rainbowmenu_titleBool;
	std::string m_HeaderTextSizeString = std::to_string(g_UiManager->m_HeaderTextSize);
	header["HeaderTextSize"] = m_HeaderTextSizeString;
	header["HeaderFont"] = g_UiManager->m_HeaderFont;
	header["HeaderTextColor"] = {
		{"r", g_UiManager->m_HeaderTextColor.r},
		{"g", g_UiManager->m_HeaderTextColor.g},
		{"b", g_UiManager->m_HeaderTextColor.b},
		{"a", g_UiManager->m_HeaderTextColor.a}
	};
						////////////
	json staticHeader = {
		{"HeaderBackgroundColor", {
			{"r", g_UiManager->m_HeaderBackgroundColor.r},
			{"g", g_UiManager->m_HeaderBackgroundColor.g},
			{"b", g_UiManager->m_HeaderBackgroundColor.b},
			{"a", g_UiManager->m_HeaderBackgroundColor.a}
		}}
	};

	header["StaticHeader"] = staticHeader;
					////////////////

	json gradientHeader;
	gradientHeader["HeaderGradientTransparent"] = g_UiManager->m_HeaderGradientTransparent;
	gradientHeader["HeaderGradientFlip"] = g_UiManager->m_HeaderGradientFlip;
	std::string m_HeaderGradientStretchString = std::to_string(g_UiManager->m_HeaderGradientStretch);
	gradientHeader["HeaderGradientStretch"] = m_HeaderGradientStretchString;
	std::string m_HeaderGradientFillerString = std::to_string(g_UiManager->m_HeaderGradientFiller);
	gradientHeader["HeaderGradientFiller"] = m_HeaderGradientFillerString;
	gradientHeader["HeaderGradientColorLeft"] = {

		{"r", g_UiManager->m_HeaderGradientColorLeft.r},
		{"g", g_UiManager->m_HeaderGradientColorLeft.g},
		{"b", g_UiManager->m_HeaderGradientColorLeft.b},
		{"a", g_UiManager->m_HeaderGradientColorLeft.a}
	};
	gradientHeader["HeaderGradientColorLeft"] = {
		{"r", g_UiManager->m_HeaderGradientColorRight.r},
		{"g", g_UiManager->m_HeaderGradientColorRight.g},
		{"b", g_UiManager->m_HeaderGradientColorRight.b},
		{"a", g_UiManager->m_HeaderGradientColorRight.a}
	};

	header["GradientHeader"] = gradientHeader;

	///////////////
	json subMenuBar;
	std::string m_SubmenuBarHeightString = std::to_string(g_UiManager->m_SubmenuBarHeight);
	subMenuBar["SubmenuBarHeight"] = m_SubmenuBarHeightString;
	std::string m_SubmenuBarTextSizeString = std::to_string(g_UiManager->m_SubmenuBarTextSize);
	subMenuBar["SubmenuBarTextSize"] = m_SubmenuBarTextSizeString;
	subMenuBar["SubmenuBarFont"] = g_UiManager->m_SubmenuBarFont;
	std::string m_SubmenuBarPaddingString = std::to_string(g_UiManager->m_SubmenuBarPadding);
	subMenuBar["SubmenuBarPadding"] = m_SubmenuBarPaddingString;
	subMenuBar["SubmenuBarBackgroundColor"] = {

		{"r", g_UiManager->m_SubmenuBarBackgroundColor.r},
		{"g", g_UiManager->m_SubmenuBarBackgroundColor.g},
		{"b", g_UiManager->m_SubmenuBarBackgroundColor.b},
		{"a", g_UiManager->m_SubmenuBarBackgroundColor.a}

	};
	subMenuBar["SubmenuBarTextColor"] = {

		{"r", g_UiManager->m_SubmenuBarTextColor.r},
		{"g", g_UiManager->m_SubmenuBarTextColor.g},
		{"b", g_UiManager->m_SubmenuBarTextColor.b},
		{"a", g_UiManager->m_SubmenuBarTextColor.a}
	};
	//////////
	json options;
	std::string m_OptionHeightString = std::to_string(g_UiManager->m_OptionHeight);
	options["OptionHeight"] = m_OptionHeightString;
	std::string m_OptionTextSizeString = std::to_string(g_UiManager->m_OptionTextSize);
	options["OptionTextSize"] = m_OptionTextSizeString;
	options["OptionFont"] = g_UiManager->m_OptionFont;
	std::string m_OptionPaddingString = std::to_string(g_UiManager->m_OptionPadding);
	options["OptionPadding"] = m_OptionPaddingString;
	options["OptionSelectedTextColor"] = {

		{"r", g_UiManager->m_OptionSelectedTextColor.r},
		{"g", g_UiManager->m_OptionSelectedTextColor.g},
		{"b", g_UiManager->m_OptionSelectedTextColor.b},
		{"a", g_UiManager->m_OptionSelectedTextColor.a}

	};
	options["OptionUnselectedTextColor"] = {

		{"r", g_UiManager->m_OptionUnselectedTextColor.r},
		{"g", g_UiManager->m_OptionUnselectedTextColor.g},
		{"b", g_UiManager->m_OptionUnselectedTextColor.b},
		{"a", g_UiManager->m_OptionUnselectedTextColor.a}
	};
	options["OptionSelectedBackgroundColor"] = {

		{"r", g_UiManager->m_OptionSelectedBackgroundColor.r},
		{"g", g_UiManager->m_OptionSelectedBackgroundColor.g},
		{"b", g_UiManager->m_OptionSelectedBackgroundColor.b},
		{"a", g_UiManager->m_OptionSelectedBackgroundColor.a}

	};
	options["OptionUnselectedBackgroundColor"] = {
		{"r", g_UiManager->m_OptionUnselectedBackgroundColor.r},
		{"g", g_UiManager->m_OptionUnselectedBackgroundColor.g},
		{"b", g_UiManager->m_OptionUnselectedBackgroundColor.b},
		{"a", g_UiManager->m_OptionUnselectedBackgroundColor.a}
	};
	options["OptionNOTHING"] = {

		{"r", g_UiManager->m_OptionNOTHING.r},
		{"g", g_UiManager->m_OptionNOTHING.g},
		{"b", g_UiManager->m_OptionNOTHING.b},
		{"a", g_UiManager->m_OptionNOTHING.a}
	};
	//////////////////////////////////////////
	json footer;
	std::string m_FooterHeightString = std::to_string(g_UiManager->m_FooterHeight);
	footer["FooterHeight"] = m_FooterHeightString;
	std::string m_FooterSpriteSizeString = std::to_string(g_UiManager->m_FooterSpriteSize);
	footer["FooterSpriteSize"] = m_FooterSpriteSizeString;
	footer["FooterBackgroundColor"] = {
		{"r", g_UiManager->m_FooterBackgroundColor.r},
		{"g", g_UiManager->m_FooterBackgroundColor.g},
		{"b", g_UiManager->m_FooterBackgroundColor.b},
		{"a", g_UiManager->m_FooterBackgroundColor.a}
	};
	footer["FooterSpriteColor"] = {
		{"r", g_UiManager->m_FooterSpriteColor.r},
		{"g", g_UiManager->m_FooterSpriteColor.g},
		{"b", g_UiManager->m_FooterSpriteColor.b},
		{"a", g_UiManager->m_FooterSpriteColor.a}
	};
	/////////
	json description;
	std::string m_DescriptionHeightPaddingString = std::to_string(g_UiManager->m_DescriptionHeightPadding);
	description["DescriptionHeightPadding"] = m_DescriptionHeightPaddingString;
	std::string m_DescriptionHeightString = std::to_string(g_UiManager->m_DescriptionHeight);
	description["DescriptionHeight"] = m_DescriptionHeightString;
	std::string m_DescriptionTextSizeString = std::to_string(g_UiManager->m_DescriptionTextSize);
	description["DescriptionTextSize"] = m_DescriptionTextSizeString;
	description["DescriptionFont"] = g_UiManager->m_DescriptionFont;
	description["DescriptionBackgroundColor"] = {
		{"r", g_UiManager->m_DescriptionBackgroundColor.r},
		{"g", g_UiManager->m_DescriptionBackgroundColor.g},
		{"b", g_UiManager->m_DescriptionBackgroundColor.b},
		{"a", g_UiManager->m_DescriptionBackgroundColor.a}
	};
	description["DescriptionTextColor"] = {
		{"r", g_UiManager->m_DescriptionTextColor.r},
		{"g", g_UiManager->m_DescriptionTextColor.g},
		{"b", g_UiManager->m_DescriptionTextColor.b},
		{"a", g_UiManager->m_DescriptionTextColor.a}

	};

	std::string m_DescriptionSpriteSizeString = std::to_string(g_UiManager->m_DescriptionSpriteSize);
	description["DescriptionSpriteSize"] = m_DescriptionSpriteSizeString;
	std::string m_DescriptionPaddingString = std::to_string(g_UiManager->m_DescriptionPadding);
	description["DescriptionPadding"] = m_DescriptionPaddingString;
	
	description["DescriptionSpriteColor"] = {

		{"r", g_UiManager->m_DescriptionSpriteColor.r},
		{"g", g_UiManager->m_DescriptionSpriteColor.g},
		{"b", g_UiManager->m_DescriptionSpriteColor.b},
		{"a", g_UiManager->m_DescriptionSpriteColor.a}
	};

	menuSettings["Settings"] = settings;
	menuSettings["Input"] = input;
	menuSettings["Header"] = header;
	menuSettings["SubMenu"] = subMenuBar;
	menuSettings["Options"] = options;
	menuSettings["Footer"] = footer;
	menuSettings["Description"] = description;


	
	std::string filename = Documents_Patha() + string("\\savedSettings.json");
	std::ofstream outputFile(filename);

	if (outputFile.is_open()) {
		
		outputFile << std::setw(4) << menuSettings << std::endl;
		outputFile.close();
		return false;
	}
	else {
		return true;
	}
}


bool SETTINGS_LOADER::SaveCurrentMenuSettings()
{
	if (SaveSettings())
	{
		return true;
	}

	return false;
}

