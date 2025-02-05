// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <Spore/UTFWin/IText.h>
#include "ChatterBubbleWidener.h"

void Initialize()
{
	// This method is executed when the game starts, before the user interface is shown
	// Here you can do things such as:
	//  - Add new cheats
	//  - Add new simulator classes
	//  - Add new game modes
	//  - Add new space tools
	//  - Change materials
	App::AddUpdateFunction(new ChatterBubbleWidener());
}

//member_detour(UILayout_load_dtr,UTFWin::UILayout,bool(const ResourceKey&, bool, uint32_t)) { 
//	
//	bool detoured(const ResourceKey & key, bool b, uint32_t parameter) {
//
//		bool ogFunc = original_function(this, key, b, parameter);
//
//		if (key.instanceID == id("SpeechBubble") && this->FindWindowByID(0x073926F8) != nullptr) {
//			IWindowPtr win = this->FindWindowByID(0x073926F8);
//			ChatterBubbleWidener* ptr = new ChatterBubbleWidener();
//			win->AddWinProc(ptr);
//		}
//		return ogFunc;
//	}
//
//};



void Dispose()
{
	// This method is called when the game is closing
}

void AttachDetours()
{
	// Call the attach() method on any detours you want to add
	// For example: cViewer_SetRenderType_detour::attach(GetAddress(cViewer, SetRenderType));

//	UILayout_load_dtr::attach(GetAddress(UTFWin::UILayout,Load));

}


// Generally, you don't need to touch any code here
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		ModAPI::AddPostInitFunction(Initialize);
		ModAPI::AddDisposeFunction(Dispose);

		PrepareDetours(hModule);
		AttachDetours();
		CommitDetours();
		break;

	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

