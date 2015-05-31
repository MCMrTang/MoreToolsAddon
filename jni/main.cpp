
/* TODO */
/* - Finish Emerald Pickaxe - */
/* - Add a use to hoes - */
/* - Add a use to axes - */
/* TODO */

#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <string>
#include <time.h>

#include "Substrate.h"

#include "mcpe/customtext/YellowText.h"

#include "mcpe/item/Item.h"
#include "mcpe/item/ArmorItem.h"

#include "mcpe/phys/Vec3.h"
#include "mcpe/texture/TextureUVCoordinateSet.h"

class Player;
class Entity {
	float x;
	float y;
	float z;
};
class Mob : public Entity {
};

const int redstoneSwordId = 460-0x100;
const int redstoneShovelId = 461-0x100;
const int redstonePickAxeId = 462-0x100;
const int redstoneAxeId = 463-0x100;
const int redstoneHoeId = 464-0x100;

const int redstoneHelmetId = 465-0x100;
const int redstoneChestplateId = 466-0x100;
const int redstoneLeggingsId = 467-0x100;
const int redstoneBootsId = 468-0x100;

const int emeraldSwordId = 469-0x100;
const int emeraldShovelId = 470-0x100;
const int emeraldPickAxeId = 471-0x100;
const int emeraldAxeId = 472-0x100;
const int emeraldHoeId = 473-0x100;

const int emeraldHelmetId = 474-0x100;
const int emeraldChestplateId = 475-0x100;
const int emeraldLeggingsId = 476-0x100;
const int emeraldBootsId = 477-0x100;

class RedstoneSwordItem : public Item {
public:
	RedstoneSwordItem(int id): Item(id) {
		setIcon("beef_cooked", 0);
		setNameID("redstoneSword");
		handEquipped();
		maxStack = 1;
		atlas = "icons.png";
	}
	virtual int getAttackDamage(Entity*);
};

int RedstoneSwordItem::getAttackDamage(Entity* entity) {
	return 10;
}

class RedstoneShovelItem : public Item {
public:
	RedstoneShovelItem(int id): Item(id) {
		setIcon("bed", 0);
		setNameID("redstoneShovel");
		handEquipped();
		maxStack = 1;
		atlas = "icons.png";
	}
	virtual float getDestroySpeed(ItemInstance*, Tile*);
	virtual bool canDestroySpecial(const Tile*);
};

float RedstoneShovelItem::getDestroySpeed(ItemInstance* inst, Tile* tile) {
	if (tile==Tile::tiles[2]) { // Grass Block
		return 3.0f;
	} if (tile==Tile::tiles[3]) { // Dirt
		return 3.0f;
	} if (tile==Tile::tiles[12]) { // Sand
		return 3.0f;
	} if (tile==Tile::tiles[13]) { // Gravel
		return 3.0f;
	} if (tile==Tile::tiles[60]) { // Farmland
		return 3.0f;
	} if (tile==Tile::tiles[78]) { // Snow Layer
		return 3.0f;
	} if (tile==Tile::tiles[80]) { // Snow Block
		return 3.0f;
	} if (tile==Tile::tiles[82]) { // Clay Block
		return 3.0f;
	} if (tile==Tile::tiles[110]) { // Mycelium
		return 3.0f;
	} else {
		return 5.0f;
		}
}

bool RedstoneShovelItem::canDestroySpecial(const Tile* tile) {
	if (tile==Tile::tiles[2]) { // Grass Block
		return true;
	} if (tile==Tile::tiles[3]) { // Dirt
		return true;
	} if (tile==Tile::tiles[12]) { // Sand
		return true;
	} if (tile==Tile::tiles[13]) { // Gravel
		return true;
	} if (tile==Tile::tiles[60]) { // Farmland
		return true;
	} if (tile==Tile::tiles[78]) { // Snow Layer
		return true;
	} if (tile==Tile::tiles[80]) { // Snow Block
		return true;
	} if (tile==Tile::tiles[82]) { // Clay Block
		return true;
	} if (tile==Tile::tiles[110]) { // Mycelium
		return true;
	} else {
		return false;
	}
}

class RedstonePickAxeItem : public Item {
public:
	RedstonePickAxeItem(int id): Item(id) {
		setIcon("axe", 3); // PENDINGGG
		setNameID("redstonePickAxe");
		handEquipped();
		maxStack = 1;
		atlas = "icons.png";
	}
	virtual float getDestroySpeed(ItemInstance*, Tile*);
	virtual bool canDestroySpecial(const Tile*);
};

float RedstonePickAxeItem::getDestroySpeed(ItemInstance* inst, Tile* tile) {
	if (tile==Tile::tiles[1]) {
		return 2.0f;
	} if (tile==Tile::tiles[4]) {
		return 2.0f;
	} if (tile==Tile::tiles[14]) {
		return 2.0f;
	} if (tile==Tile::tiles[15]) {
		return 2.0f;
	} if (tile==Tile::tiles[16]) {
		return 2.0f;
	} if (tile==Tile::tiles[21]) {
		return 2.0f;
	} if (tile==Tile::tiles[22]) {
		return 2.0f;
	} if (tile==Tile::tiles[24]) {
		return 2.0f;
	} if (tile==Tile::tiles[41]) {
		return 2.0f;
	} if (tile==Tile::tiles[42]) {
		return 2.0f;
	} if (tile==Tile::tiles[43]) {
		return 2.0f;
	} if (tile==Tile::tiles[44]) {
		return 2.0f;
	} if (tile==Tile::tiles[45]) {
		return 2.0f;
	} if (tile==Tile::tiles[48]) {
		return 2.0f;
	} if (tile==Tile::tiles[52]) {
		return 2.0f;
	} if (tile==Tile::tiles[56]) {
		return 2.0f;
	} if (tile==Tile::tiles[57]) {
		return 2.0f;
	} if (tile==Tile::tiles[61]) {
		return 2.0f;
	} if (tile==Tile::tiles[62]) {
		return 2.0f;
	} if (tile==Tile::tiles[67]) {
		return 2.0f;
	} if (tile==Tile::tiles[71]) {
		return 2.0f;
	} if (tile==Tile::tiles[73]) {
		return 2.0f;
	} if (tile==Tile::tiles[74]) {
		return 2.0f;
	} if (tile==Tile::tiles[89]) {
		return 2.0f;
	} if (tile==Tile::tiles[97]) {
		return 2.0f;
	} if (tile==Tile::tiles[98]) {
		return 2.0f;
	} if (tile==Tile::tiles[101]) {
		return 2.0f;
	} if (tile==Tile::tiles[108]) {
		return 2.0f;
	} if (tile==Tile::tiles[109]) {
		return 2.0f;
	} if (tile==Tile::tiles[112]) {
		return 2.0f;
	} if (tile==Tile::tiles[114]) {
		return 2.0f;
	} if (tile==Tile::tiles[121]) {
		return 2.0f;
	} if (tile==Tile::tiles[128]) {
		return 2.0f;
	} if (tile==Tile::tiles[129]) {
		return 2.0f;
	} if (tile==Tile::tiles[133]) {
		return 2.0f;
	} if (tile==Tile::tiles[139]) {
		return 2.0f;
	} if (tile==Tile::tiles[152]) {
		return 2.0f;
	} if (tile==Tile::tiles[155]) {
		return 2.0f;
	} if (tile==Tile::tiles[156]) {
		return 2.0f;
	} if (tile==Tile::tiles[159]) {
		return 2.0f;
	} if (tile==Tile::tiles[172]) {
		return 2.0f;
	} if (tile==Tile::tiles[173]) {
		return 2.0f;
	} if (tile==Tile::tiles[245]) {
		return 2.0f;
	} if (tile==Tile::tiles[246]) {
		return 2.0f;
	} if (tile==Tile::tiles[247]) {
		return 2.0f;
	} else {
		return 4.0f;
	}
}

bool RedstonePickAxeItem::canDestroySpecial(const Tile* tile) {
	if (tile==Tile::tiles[1]) {
		return true;
	} if (tile==Tile::tiles[4]) {
		return true;
	} if (tile==Tile::tiles[14]) {
		return true;
	} if (tile==Tile::tiles[15]) {
		return true;
	} if (tile==Tile::tiles[16]) {
		return true;
	} if (tile==Tile::tiles[21]) {
		return true;
	} if (tile==Tile::tiles[22]) {
		return true;
	} if (tile==Tile::tiles[24]) {
		return true;
	} if (tile==Tile::tiles[41]) {
		return true;
	} if (tile==Tile::tiles[42]) {
		return true;
	} if (tile==Tile::tiles[43]) {
		return true;
	} if (tile==Tile::tiles[44]) {
		return true;
	} if (tile==Tile::tiles[45]) {
		return true;
	} if (tile==Tile::tiles[48]) {
		return true;
	} if (tile==Tile::tiles[52]) {
		return true;
	} if (tile==Tile::tiles[56]) {
		return true;
	} if (tile==Tile::tiles[57]) {
		return true;
	} if (tile==Tile::tiles[61]) {
		return true;
	} if (tile==Tile::tiles[62]) {
		return true;
	} if (tile==Tile::tiles[67]) {
		return true;
	} if (tile==Tile::tiles[71]) {
		return true;
	} if (tile==Tile::tiles[73]) {
		return true;
	} if (tile==Tile::tiles[74]) {
		return true;
	} if (tile==Tile::tiles[89]) {
		return true;
	} if (tile==Tile::tiles[97]) {
		return true;
	} if (tile==Tile::tiles[98]) {
		return true;
	} if (tile==Tile::tiles[101]) {
		return true;
	} if (tile==Tile::tiles[108]) {
		return true;
	} if (tile==Tile::tiles[109]) {
		return true;
	} if (tile==Tile::tiles[112]) {
		return true;
	} if (tile==Tile::tiles[114]) {
		return true;
	} if (tile==Tile::tiles[121]) {
		return true;
	} if (tile==Tile::tiles[128]) {
		return true;
	} if (tile==Tile::tiles[129]) {
		return true;
	} if (tile==Tile::tiles[133]) {
		return true;
	} if (tile==Tile::tiles[139]) {
		return true;
	} if (tile==Tile::tiles[152]) {
		return true;
	} if (tile==Tile::tiles[155]) {
		return true;
	} if (tile==Tile::tiles[156]) {
		return true;
	} if (tile==Tile::tiles[159]) {
		return true;
	} if (tile==Tile::tiles[172]) {
		return true;
	} if (tile==Tile::tiles[173]) {
		return true;
	} if (tile==Tile::tiles[245]) {
		return true;
	} if (tile==Tile::tiles[246]) {
		return true;
	} if (tile==Tile::tiles[247]) {
		return true;
	} else {
		return false;
	}
}

class RedstoneAxeItem : public Item {
public:
	RedstoneAxeItem(int id): Item(id) {
		setIcon("apple", 0);
		setNameID("redstoneAxe");
		handEquipped();
		maxStack = 1;
		atlas = "icons.png";
	}
	virtual float getDestroySpeed(ItemInstance*, Tile*);
};

float RedstoneAxeItem::getDestroySpeed(ItemInstance* inst, Tile* tile) {
	return 4.0f;
}

class RedstoneHoeItem : public Item {
public:
	RedstoneHoeItem(int id): Item(id) {
		setIcon("apple", 0);
		setNameID("redstoneHoe");
		handEquipped();
		maxStack = 1;
		atlas = "icons.png";
	}
};

class RedstoneHelmetItem : public ArmorItem {
public:
	RedstoneHelmetItem(int id, const ArmorItem::ArmorMaterial& material, int modelIndex, int slot): ArmorItem(id, material, modelIndex, slot) {
		setIcon("apple", 0);
		setNameID("redstoneHelmet");
		maxStack = 1;
		atlas = "icons.png";
	}
};

class RedstoneChestPlateItem : public ArmorItem {
public:
	RedstoneChestPlateItem(int id, const ArmorItem::ArmorMaterial& material, int modelIndex, int slot): ArmorItem(id, material, modelIndex, slot) {
		setIcon("apple", 0);
		setNameID("redstoneChestPlate");
		maxStack = 1;
		atlas = "icons.png";
	}
};

class RedstonePantsItem : public ArmorItem {
public:
	RedstonePantsItem(int id, const ArmorItem::ArmorMaterial& material, int modelIndex, int slot): ArmorItem(id, material, modelIndex, slot) {
		setIcon("apple", 0);
		setNameID("redstonePants");
		maxStack = 1;
		atlas = "icons.png";
	}
};

class RedstoneBootsItem : public ArmorItem {
public:
	RedstoneBootsItem(int id, const ArmorItem::ArmorMaterial& material, int modelIndex, int slot): ArmorItem(id, material, modelIndex, slot) {
		setIcon("apple", 0);
		setNameID("redstoneBoots");
		maxStack = 1;
		atlas = "icons.png";
	}
};

class EmeraldSwordItem : public Item {
public:
	EmeraldSwordItem(int id): Item(id) {
		setIcon("apple", 0);
		setNameID("emeraldSword");
		handEquipped();
		maxStack = 1;
		atlas = "icons.png";
	}
	virtual int getAttackDamage(Entity*);
};

int EmeraldSwordItem::getAttackDamage(Entity* entity) {
	return 10;
}

class EmeraldShovelItem : public Item {
public:
	EmeraldShovelItem(int id): Item(id) {
		setIcon("apple", 0);
		setNameID("emeraldShovel");
		handEquipped();
		maxStack = 1;
		atlas = "icons.png";
	}
	virtual float getDestroySpeed(ItemInstance*, Tile*);
	virtual bool canDestroySpecial(const Tile*);
};

float EmeraldShovelItem::getDestroySpeed(ItemInstance* inst, Tile* tile) {
	return 3.0f;
}

bool EmeraldShovelItem::canDestroySpecial(const Tile* tileConst) {
	if (tileConst==Tile::tiles[2]) { // Grass Block
		return true;
	} if (tileConst==Tile::tiles[3]) { // Dirt
		return true;
	} if (tileConst==Tile::tiles[243]) { // Podzol
		return true;
	} if (tileConst==Tile::tiles[12]) { // Sand
		return true;
	} if (tileConst==Tile::tiles[13]) { // Gravel
		return true;
	} if (tileConst==Tile::tiles[78]) { // Snow Layer
		return true;
	} if (tileConst==Tile::tiles[80]) { // Snow Block
		return true;
	} if (tileConst==Tile::tiles[82]) { // Clay Block
		return true;
	} if (tileConst==Tile::tiles[110]) { // Mycelium
		return true;
	} else {
		return false;
	}
}

class EmeraldPickAxeItem : public Item {
public:
	EmeraldPickAxeItem(int id): Item(id) {
		setIcon("apple", 0);
		setNameID("emeraldPickAxe");
		handEquipped();
		maxStack = 1;
		atlas = "icons.png";
	}
	virtual float getDestroySpeed(ItemInstance*, Tile*);
	virtual bool canDestroySpecial(const Tile*);
};

float EmeraldPickAxeItem::getDestroySpeed(ItemInstance* inst, Tile* tile) {
	return 2.0f;
}

bool EmeraldPickAxeItem::canDestroySpecial(const Tile* tileConst) {
	if (tileConst==Tile::rock) { // Stone
		return true;
	} if (tileConst==Tile::stoneBrick) { // Stone Bricks
		return true;
	} if (tileConst==Tile::goldOre) { // Gold Ore
		return true;
	} if (tileConst==Tile::ironOre) { // Iron Ore
		return true;
	} if (tileConst==Tile::coalOre) { // Coal Ore
		return true;
	} if (tileConst==Tile::lapisOre) { // Lapis Ore
		return true;
	} if (tileConst==Tile::lapisBlock) { // Lapis Block
		return true;
	} if (tileConst==Tile::sandStone) { // Sandstone
		return true;
	} if (tileConst==Tile::goldBlock) { // Gold Block
		return true;
	} if (tileConst==Tile::ironBlock) { // Iron Block
		return true;
	} if (tileConst==Tile::stoneSlab) { // Stone Full Slab
		return true;
	} if (tileConst==Tile::stoneSlabHalf) { // Half Stone Slab
		return true;
	} if (tileConst==Tile::redBrick) { // Bricks
		return true;
	} if (tileConst==Tile::mossStone) { // Moss Stone
		return true;
	} if (tileConst==Tile::obsidian) { // Obsidian
		return true;
	} if (tileConst==Tile::mobSpawner) { // Mob Spawner
		return true;
	} if (tileConst==Tile::diamondOre) { // Diamond Ore
		return true;
	} if (tileConst==Tile::diamondBlock) { // Diamond Block
		return true;
	} if (tileConst==Tile::stonecutterBench) { // Stonecutter
		return true;
	} if (tileConst==Tile::furnace) { // Furnace
		return true;
	} if (tileConst==Tile::furnace_lit) { // Lit Furnace
		return true;
	} if (tileConst==Tile::rail) { // Rail
		return true;
	} if (tileConst==Tile::goldenRail) { // Golden Rail
		return true;
	} if (tileConst==Tile::stairs_stone) { // Stone Stairs
		return true;
	} if (tileConst==Tile::door_iron) { // Iron Door
		return true;
	} if (tileConst==Tile::redStoneOre) { // Redstone Ore
		return true;
	} if (tileConst==Tile::redStoneOre_lit) { // Lit Redstone Ore
		return true;
	} if (tileConst==Tile::stairs_brick) {
		return true;
	} if (tileConst==Tile::lightGem) {
		return true;
	} if (tileConst==Tile::monsterStoneEgg) {
		return true;
	} if (tileConst==Tile::stoneBrickSmooth) {
		return true;
	} if (tileConst==Tile::netherReactor) {
		return true;
	} if (tileConst==Tile::glowingObsidian) {
		return true;
	} if (tileConst==Tile::cobbleWall) {
		return true;
	} if (tileConst==Tile::stairs_stoneBrickSmooth) {
		return true;
	} if (tileConst==Tile::netherBrick) {
		return true;
	} if (tileConst==Tile::netherrack) {
		return true;
	} if (tileConst==Tile::ironFence) {
		return true;
	} if (tileConst==Tile::stairs_netherBricks) {
		return true;
	} if (tileConst==Tile::stairs_sandStone) {
		return true;
	} if (tileConst==Tile::quartzBlock) {
		return true;
	} if (tileConst==Tile::stairs_quartz) {
		return true;
	} if (tileConst==Tile::stainedClay) {
		return true;
	} if (tileConst==Tile::hardenedClay) {
		return true;
	} if (tileConst==Tile::endStone) {
		return true;
	} if (tileConst==Tile::emeraldOre) {
		return true;
	} if (tileConst==Tile::emeraldBlock) {
		return true;
	} else {
		return false;
	}
}

class EmeraldAxeItem : public Item {
public:
	EmeraldAxeItem(int id): Item(id) {
		setIcon("apple", 0);
		setNameID("emeraldAxe");
		handEquipped();
		maxStack = 1;
		atlas = "icons.png";
	}
	virtual float getDestroySpeed(ItemInstance*, Tile*);
};

float EmeraldAxeItem::getDestroySpeed(ItemInstance* inst, Tile* tile) {
	return 4.0f;
}

class EmeraldHoeItem : public Item {
public:
	EmeraldHoeItem(int id): Item(id) {
		setIcon("apple_golden", 0);
		setNameID("emeraldHoe");
		handEquipped();
		maxStack = 1;
		atlas = "icons.png";
	}
};

class EmeraldHelmetItem : public ArmorItem {
public:
	EmeraldHelmetItem(int id, const ArmorItem::ArmorMaterial& material, int modelIndex, int slot): ArmorItem(id, material, modelIndex, slot) {
		setIcon("apple", 0);
		setNameID("emeraldHelmet");
		maxStack = 1;
		atlas = "icons.png";
	}
};

class EmeraldChestPlateItem : public ArmorItem {
public:
	EmeraldChestPlateItem(int id, const ArmorItem::ArmorMaterial& material, int modelIndex, int slot): ArmorItem(id, material, modelIndex, slot) {
		setIcon("apple", 0);
		setNameID("emeraldChestPlate");
		maxStack = 1;
		atlas = "icons.png";
	}
};

class EmeraldPantsItem : public ArmorItem {
public:
	EmeraldPantsItem(int id, const ArmorItem::ArmorMaterial& material, int modelIndex, int slot): ArmorItem(id, material, modelIndex, slot) {
		setIcon("apple", 0);
		setNameID("emeraldPants");
		maxStack = 1;
		atlas = "icons.png";
	}
};

class EmeraldBootsItem : public ArmorItem {
public:
	EmeraldBootsItem(int id, const ArmorItem::ArmorMaterial& material, int modelIndex, int slot): ArmorItem(id, material, modelIndex, slot) {
		setIcon("apple", 0);
		setNameID("emeraldBoots");
		maxStack = 1;
		atlas = "icons.png";
	}
};

static void (*Item$initItems_real)();

static void Item$initItems_hook() {
	RedstoneSwordItem* redstoneSwordItem = new RedstoneSwordItem(redstoneSwordId);
	Item::items[redstoneSwordId] = redstoneSwordItem;
	RedstoneShovelItem* redstoneShovelItem = new RedstoneShovelItem(redstoneShovelId);
	Item::items[redstoneShovelId] = redstoneShovelItem;
	RedstonePickAxeItem* redstonePickAxeItem = new RedstonePickAxeItem(redstonePickAxeId);
	Item::items[redstonePickAxeId] = redstonePickAxeItem;
	RedstoneAxeItem* redstoneAxeItem = new RedstoneAxeItem(redstoneAxeId);
	Item::items[redstoneAxeId] = redstoneAxeItem;
	RedstoneHoeItem* redstoneHoeItem = new RedstoneHoeItem(redstoneHoeId);
	Item::items[redstoneHoeId] = redstoneHoeItem;
	RedstoneHelmetItem* redstoneHelmetItem = new RedstoneHelmetItem(redstoneHelmetId, ArmorItem::ArmorMaterial(80, 10, 20, 15, 10), 42, 0);
	Item::items[redstoneHelmetId] = redstoneHelmetItem;
	EmeraldSwordItem* emeraldSwordItem = new EmeraldSwordItem(emeraldSwordId);
	Item::items[emeraldSwordId] = emeraldSwordItem;
	EmeraldShovelItem* emeraldShovelItem = new EmeraldShovelItem(emeraldShovelId);
	Item::items[emeraldShovelId] = emeraldShovelItem;
	EmeraldPickAxeItem* emeraldPickAxeItem = new EmeraldPickAxeItem(emeraldPickAxeId);
	Item::items[emeraldPickAxeId] = emeraldPickAxeItem;
	EmeraldAxeItem* emeraldAxeItem = new EmeraldAxeItem(emeraldAxeId);
	Item::items[emeraldAxeId] = emeraldAxeItem;
	EmeraldHoeItem* emeraldHoeItem = new EmeraldHoeItem(emeraldHoeId);
	Item::items[emeraldHoeId] = emeraldHoeItem;
	EmeraldHelmetItem* emeraldHelmetItem = new EmeraldHelmetItem(emeraldHelmetId, ArmorItem::ArmorMaterial(80, 10, 20, 15, 10), 42, 0);
	Item::items[emeraldHelmetId] = emeraldHelmetItem;
	Item$initItems_real();
}

static std::string (*Common$getGameVersionString_real)();

static std::string Common$getGameVersionString_hook() {
	return "More Tools v1 beta 2 by @joepaleto";
}

static char** gSplashes;

static void (*Touch$StartMenuScreen$chooseRandomSplash_real)(Touch::StartMenuScreen*);

static void Touch$StartMenuScreen$chooseRandomSplash_hook(Touch::StartMenuScreen* screen) {
	gSplashes[0] = "Use wisely.";
	gSplashes[1] = "ModPE? Peach, please.";
	gSplashes[2] = "Gives emeralds a use!";
	gSplashes[3] = "#FuckModPE!";
	gSplashes[4] = "Flammable!";

	screen->currentSplash = rand() % 5;
}

static std::string (*I18n$get_real)(std::string const&);

static std::string I18n$get_hook(std::string const& key) {
	if (key=="item.redstoneSword.name") {
		return "Redstone Sword";
	} if (key=="item.redstoneShovel.name") {
		return "Redstone Shovel";
	} if (key=="item.redstonePickAxe.name") {
		return "Redstone Pickaxe";
	} if (key=="item.redstoneAxe.name") {
		return "Redstone Axe";
	} if (key=="item.redstoneHoe.name") {
		return "Redstone Hoe";
	} if (key=="item.redstoneHelmet.name") {
		return "Redstone Helmet";
	} if (key=="item.redstoneChestPlate.name") {
		return "Redstone Chestplate";
	} if (key=="item.redstonePants.name") {
		return "Redstone Pants";
	} if (key=="item.redstoneBoots.name") {
		return "Redstone Boots";
	} if (key=="item.emeraldSword.name") {
		return "Emerald Sword";
	} if (key=="item.emeraldShovel.name") {
		return "Emerald Shovel";
	} if (key=="item.emeraldPickAxe.name") {
		return "Emerald Pickaxe";
	} if (key=="item.emeraldAxe.name") {
		return "Emerald Axe";
	} if (key=="item.emeraldHoe.name") {
		return "Emerald Hoe";
	} if (key=="item.emeraldHelmet.name") {
		return "Emerald Helmet";
	} if (key=="item.emeraldChestPlate.name") {
		return "Emerald Chestplate";
	} if (key=="item.emeraldPants.name") {
		return "Emerald Pants";
	} if (key=="item.emeraldBoots.name") {
		return "Emerald Boots";
	} else {
		return I18n$get_real(key);
	}
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems_hook, (void**) &Item$initItems_real);
	
	void* Common$getGameVersionString = dlsym(RTLD_DEFAULT, "_ZN6Common20getGameVersionStringEv");
	MSHookFunction(Common$getGameVersionString, (void*) &Common$getGameVersionString_hook, (void**) &Common$getGameVersionString_real);
	
	gSplashes = (char**) dlsym(RTLD_DEFAULT, "gSplashes");
	MSHookFunction((void*) &Touch::StartMenuScreen::chooseRandomSplash, (void*) &Touch$StartMenuScreen$chooseRandomSplash_hook, (void**) &Touch$StartMenuScreen$chooseRandomSplash_real);
	srand(time(0));
	
	void* I18n$get = dlsym(RTLD_DEFAULT, "_ZN4I18n3getERKSs");
    MSHookFunction(I18n$get, (void*) &I18n$get_hook, (void**) &I18n$get_real);
	return JNI_VERSION_1_2;
}
