#pragma once

#include "Item.h"
#include "../Tile/Tile.h"

class Item;
class Tile;

class ItemInstance {
public:
	ItemInstance();
	ItemInstance(bool);
	ItemInstance(const Tile*);
	ItemInstance(const Tile*, int);
	ItemInstance(const Tile*, int, int);
	ItemInstance(const Item*);
	ItemInstance(const Item*, int);
	ItemInstance(const Item*, int, int);
	ItemInstance(const ItemInstance&);
	ItemInstance(int, int, int);
	
	int count;
	int auxValue;
	Item* item;
	Tile* tile;
	bool valid;
};
