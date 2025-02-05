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
	if (Simulator::IsScenarioMode() && ScenarioMode.GetMode() == App::cScenarioMode::Mode::PlayMode && WindowManager.GetMainWindow()->FindWindowByID(0x3f608b3e) != nullptr) {
		for (IWindow* window : WindowManager.GetMainWindow()->FindWindowByID(0x3f608b3e)->children()) {
			if (window->GetControlID() == 0x073926F8) {
				
				Math::Rectangle rect = window->GetRealArea();
				rect.x2 = rect.x1 + 294;

				if (rect.x1 >= 20000 && rect.y1 >= 20000) {
					rect.x1 -= 20000;
					rect.x2 -= 20000;
					rect.y1 -= 20000;
					rect.y2 -= 20000;
				}

				window->SetLayoutArea(rect);

				if (window->FindWindowByID(0x07392DD8) != nullptr) {
					ITextPtr text = object_cast<IText>(window->FindWindowByID(0x07392DD8));
					Math::Rectangle rect2 = text->GetTextBounds(true, true);

					if (rect2.GetHeight() > 250) {
						rect.x2 = rect.x1 + 390;
						rect.y2 = rect.y1 + rect2.GetHeight() - 50;
					}
					else if (rect2.GetHeight() > 41) {
						rect.x2 = rect.x1 + 294;
						rect.y2 = rect.y1 + rect2.GetHeight();
					}
					else {
						rect.x2 = rect.x1 + 196;
					}
					window->SetLayoutArea(rect);
				}
			}
		}
	}
}