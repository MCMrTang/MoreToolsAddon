#pragma once

#include "Tile.h"
#include "entity/TileEntity.h"

class EntityTile : public Tile
{
public:
	EntityTile(int, const Material*);
	EntityTile(int, std::string const&, const Material*);
	~EntityTile();

	virtual TileEntity* newTileEntity(const TilePos&);
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int);
	virtual void triggerEvent(TileSource *,int,int,int,int,int);
};
