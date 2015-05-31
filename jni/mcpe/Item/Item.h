#pragma once

#include <string>
#include <memory>

#include "UseAnim.h"

#include "ItemInstance.h"
#include "../CommonType.h"
#include "../Tile/Tile.h"
#include "../Texture/TextureAtlas.h"
#include "../Texture/TextureUVCoordinateSet.h"

class ItemInstance;
class Tile;
class Item {
public:

	int maxStack;
	std::string atlas;
	const int id;
	int frames;
	int maxDamage;
	TextureUVCoordinateSet icon;
	int creativeTab;
	bool toolRenderer;
	
    Item(int);

    virtual ~Item();
	virtual void setIcon(std::string const&, int);
	virtual float getDestroySpeed(ItemInstance*, Tile*);
	virtual bool canDestroySpecial(const Tile*) const;
	virtual int getAttackDamage(Entity*);
	virtual void handEquipped();
	virtual void setNameID(std::string const&);

	static Item* items[512];

	static void initItems();
};
