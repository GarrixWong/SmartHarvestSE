#pragma once

#include <vector>

inline bool IsBookObject(ObjectType objType)
{
	return objType >= ObjectType::books && objType <= ObjectType::skillbookRead;
}

class TESObjectREFRHelper : public IHasValueWeight
{
public:
	explicit TESObjectREFRHelper(const RE::TESObjectREFR* ref);

	RE::TESObjectREFR* GetAshPileRefr(void);
	SInt16 GetItemCount();
	RE::NiTimeController* GetTimeController(void);
	bool IsQuestItem(const bool requireFullQuestFlags);
	double GetPosValue(void);
	RE::TESContainer * GetContainer() const;
	std::vector<RE::TESObjectREFR*> GetLinkedRefs(RE::BGSKeyword* keyword);
	bool IsPlayerOwned(void);

	const RE::TESForm* GetLootable() const;
	void SetLootable(const RE::TESForm* lootable);
	virtual double GetWeight(void) const override;
	virtual double GetWorth(void) const override;

	const RE::TESObjectREFR* m_ref;

protected:
	virtual const char* GetName() const;
	virtual UInt32 GetFormID() const;

private:
	const RE::TESForm* m_lootable;
};

class ActorHelper
{
public:
	ActorHelper(RE::Actor* actor) : m_actor(actor) {}
	bool IsSneaking(void);
	bool IsPlayerAlly(void);
	bool IsEssential(void);
	bool IsSummonable(void);
private:
	RE::Actor* m_actor;
};

RE::TESObjectREFR* GetAshPile(const RE::TESObjectREFR* refr);
bool IsBossContainer(const RE::TESObjectREFR * refr);
bool IsContainerLocked(const RE::TESObjectREFR * refr);
ObjectType ClassifyType(const RE::TESObjectREFR* refr, bool ignoreUserlist = false);
ObjectType ClassifyType(const RE::TESForm* baseForm, bool ignoreUserlist = false);
std::string GetObjectTypeName(SInt32 num);
std::string GetObjectTypeName(const RE::TESObjectREFR* refr);
std::string GetObjectTypeName(RE::TESForm* pForm);
std::string GetObjectTypeName(const RE::TESForm* pForm);
std::string GetObjectTypeName(ObjectType type);
ObjectType GetObjectTypeByTypeName(const std::string& name);

inline bool ValueWeightExempt(ObjectType objectType)
{
	return objectType == ObjectType::ammo ||
		objectType == ObjectType::lockpick ||
		objectType == ObjectType::keys ||
		objectType == ObjectType::oreVein ||
		objectType == ObjectType::septims;
}
bool IsPlayable(const RE::TESForm * pForm);
