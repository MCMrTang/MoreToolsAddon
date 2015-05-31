#pragma once

#include <map>
#include <string>

#include "TileEntityRendererId.h"
#include "../Tile.h"
#include "../../phys/Vec3.h"
#include "../../phys/AABB.h"
#include "../../CommonType.h"

class TileEntity
{
public:
	static int _runningId;
	TileSource* region;
	const TilePos pos;
	AABB bb;
	int data;
	const TileEntityType type;
	int runningId;
	bool clientSideOnly;
	TileEntityRendererId rendererId;
	Tile* tile;
	bool remove;
	float destroyTimer;
	Vec3 destroyDirection;
	float destroyProgress;
	static std::map<std::string, TileEntityType> idClassMap;
	static std::map<TileEntityType, std::string> classIdMap;


	static void setId(TileEntityType, std::string const&);
	static void initTileEntities();

	TileEntity(TileEntityType, TilePos const&, std::string const&);
	virtual ~TileEntity();

	virtual void load(CompoundTag*);
	virtual bool save(CompoundTag*);
	virtual void tick(TileSource*);
	virtual bool isFinished();
	void setRegion(TileSource*);

	static TileEntity* loadStatic(CompoundTag*);

	void setChanged();
	float distanceToSqr(const Vec3&);
	virtual Packet* getUpdatePacket();
	virtual void onUpdatePacket(CompoundTag*);
	bool isRemoved();
	virtual void setRemoved();
	void clearRemoved();
	virtual void triggerEvent(int, int);
	virtual void clearCache();
	void isType(TileEntityType);
	virtual void onNeighborChanged(TileSource&, int, int, int);
	virtual float getShadowRadius(TileSource&) const;
	//virtual void stopDestroy();
	const AABB& getAABB() const;
	TileSource& getRegion() const;
	bool isInWorld() const;
	void _destructionWobble(float&, float&, float&);
	void _resetAABB();

};
