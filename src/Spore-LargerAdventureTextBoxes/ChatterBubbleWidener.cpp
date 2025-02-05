#include "stdafx.h"
#include "ChatterBubbleWidener.h"
#include <Spore/UTFWin/IText.h>

ChatterBubbleWidener::ChatterBubbleWidener()
{
}


ChatterBubbleWidener::~ChatterBubbleWidener()
{
}

// For internal use, do not modify.
int ChatterBubbleWidener::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int ChatterBubbleWidener::Release()
{
	return DefaultRefCounted::Release();
}

// You can extend this function to return any other types your class implements.
void ChatterBubbleWidener::Update() {
	if (Simulator::IsScenarioMode() && ScenarioMode.GetMode() == App::cScenarioMode::Mode::PlayMode && WindowManager.GetMainWindow()->FindWindowByID(0x073926F8) != nullptr) {
		IWindowPtr window = WindowManager.GetMainWindow()->FindWindowByID(0x073926F8);
		Math::Rectangle rect = window->GetRealArea();
		rect.x2 = rect.x1 + 390;
		window->SetLayoutArea(rect);
		
	}
}