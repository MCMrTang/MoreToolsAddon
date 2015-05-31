#pragma once

enum class TileEntityType
{
	None,
	Furnace,
	Chest,
	NetherReactor,
	Sign,
	MobSpawner,
	Motor
};


enum TileEntityRendererId
{
	TR_DEFAULT_RENDERER,
	TR_CHEST_RENDERER,
	TR_SIGN_RENDERER,
	TR_MOBSPAWNER_RENDERER
};
