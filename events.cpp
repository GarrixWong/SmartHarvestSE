#include "PrecompiledHeaders.h"

#include "skse64/PapyrusArgs.h"
#include "events.h"

CritterIngredientEventFunctor::CritterIngredientEventFunctor(TESObjectREFR* refr)
	: m_refr(refr)
{}

bool CritterIngredientEventFunctor::Copy(Output* dst)
{
	VMClassRegistry* registry = (*g_skyrimVM)->GetClassRegistry();
	dst->Resize(1);
	PackValue(dst->Get(0), &m_refr, registry);
	return true;
}

LootEventFunctor::LootEventFunctor(TESObjectREFR* refr, SInt32 type, SInt32 count, bool silent, bool ignoreBlocking)
	: m_refr(refr), m_type(type), m_count(count), m_silent(silent), m_ignoreBlocking(ignoreBlocking)
{}

bool LootEventFunctor::Copy(Output* dst)
{
	VMClassRegistry* registry = (*g_skyrimVM)->GetClassRegistry();
	dst->Resize(5);
	PackValue(dst->Get(0), &m_refr, registry);
	dst->Get(1)->SetInt(m_type);
	dst->Get(2)->SetInt(m_count);
	dst->Get(3)->SetBool(m_silent);
	dst->Get(4)->SetBool(m_ignoreBlocking);
	return true;
}

ObjectGlowEventFunctor::ObjectGlowEventFunctor(TESObjectREFR* refr, const int glowDuration)
	: m_refr(refr), m_glowDuration(glowDuration)
{}

bool ObjectGlowEventFunctor::Copy(Output* dst)
{
	VMClassRegistry* registry = (*g_skyrimVM)->GetClassRegistry();
	dst->Resize(2);
	PackValue(dst->Get(0), &m_refr, registry);
	dst->Get(1)->SetInt(m_glowDuration);

	return true;
}

ObjectGlowStopEventFunctor::ObjectGlowStopEventFunctor(TESObjectREFR* refr)
	: m_refr(refr)
{}

bool ObjectGlowStopEventFunctor::Copy(Output* dst)
{
	VMClassRegistry* registry = (*g_skyrimVM)->GetClassRegistry();
	dst->Resize(1);
	PackValue(dst->Get(0), &m_refr, registry);

	return true;
}

PlayerHouseCheckEventFunctor::PlayerHouseCheckEventFunctor(TESForm* location)
	: m_location(location)
{}

bool PlayerHouseCheckEventFunctor::Copy(Output* dst)
{
	VMClassRegistry* registry = (*g_skyrimVM)->GetClassRegistry();
	dst->Resize(1);
	PackValue(dst->Get(0), &m_location, registry);

	return true;
}

CarryWeightDeltaEventFunctor::CarryWeightDeltaEventFunctor(const int delta) : m_delta(delta)
{}

bool CarryWeightDeltaEventFunctor::Copy(Output* dst)
{
	VMClassRegistry* registry = (*g_skyrimVM)->GetClassRegistry();
	dst->Resize(1);
	dst->Get(0)->SetInt(m_delta);

	return true;
}
