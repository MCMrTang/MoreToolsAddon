#pragma once

#include "Item.h"

class ArmorItem : public Item {
public:
	static const int SLOT_HEAD = 0;
	static const int SLOT_TORSO = 1;
	static const int SLOT_LEGS = 2;
	static const int SLOT_FEET = 3;

	static const int healthPerSlot[];
class ArmorMaterial {
public:
	ArmorMaterial(int, int, int, int, int);

	int getHealthForSlot(int) const;
	int getDefenseForSlot(int) const;
private:
	int durabilityMultiplier;
	int slotProtections[4];
};

	static const ArmorItem::ArmorMaterial CLOTH;
	static const ArmorItem::ArmorMaterial CHAIN;
	static const ArmorItem::ArmorMaterial IRON;
	static const ArmorItem::ArmorMaterial GOLD;
	static const ArmorItem::ArmorMaterial DIAMOND;

	const int slot;
	const int defense;
	const int modelIndex;
	const ArmorItem::ArmorMaterial& armorType;

	ArmorItem(int, const ArmorItem::ArmorMaterial&, int, int);

	virtual bool isArmor() const;
};
