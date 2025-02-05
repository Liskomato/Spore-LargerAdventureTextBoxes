#pragma once

#include <Spore\BasicIncludes.h>

#define ChatterBubbleWidenerPtr intrusive_ptr<ChatterBubbleWidener>

// To avoid repeating UTFWin:: all the time.
using namespace UTFWin;

class ChatterBubbleWidener 
	: public App::IUpdatable
	, public DefaultRefCounted
{
public:
	static const uint32_t TYPE = id("ChatterBubbleWidener");
	
	ChatterBubbleWidener();
	~ChatterBubbleWidener();

	int AddRef() override;
	int Release() override;
	void Update();
	
	
};
