#include "stdafx.h"
#include "json.hpp"
#include "SettingsLoader.hpp"

using json = nlohmann::json;




bool SETTINGS_LOADER::LoadSavedMenuSettings()
{
	

	return FALSE;
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
	settings = {
		{"Toggle_Off", {
			{"r", g_UiManager->m_Toggle_Off.r},
			{"g", g_UiManager->m_Toggle_Off.g},
			{"b", g_UiManager->m_Toggle_Off.b},
			{"a", g_UiManager->m_Toggle_Off.a}
		}}
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


	
	std::string filename = Documents_Patha() + string("\\output.json");
	std::ofstream outputFile(filename);

	if (outputFile.is_open()) {
		// Scrivi la rappresentazione JSON dell'oggetto nel file
		outputFile << std::setw(4) << menuSettings << std::endl;

		// Chiudi il file
		outputFile.close();
		return true; // Restituisci true se il salvataggio ha successo
	}
	else {
		Log::Error("Errore nell'apertura del file.");
		return false; // Restituisci false se si verifica un errore nell'apertura del file
	}
	return 0;
}


bool SETTINGS_LOADER::SaveCurrentMenuSettings()
{
	Log::Msg("Entrata.");
	if (!SaveSettings())
	{
		Log::Error("Unable to create the file.");
		return true;
	}
	

	notify_Custom((char*)Mod_Menu_Name"", "~g~Done!\nMenu settings saved");
	

	return false;
}

