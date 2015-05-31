#pragma once

#include <unordered_map>
#include <string>

#include "../CommonType.h"
#include "TextureUVCoordinateSet.h"
#include "TextureAtlasTextureItem.h"

class TextureAtlas
{
public:
	std::string _metaFile;
	std::unordered_map<std::string, TextureAtlasTextureItem> _textureItems;
	TextureFile _textureFile;
	int _curIndex;

	TextureAtlas(std::string const&, TextureFile);
	~TextureAtlas();

	void load(MinecraftClient*);
	const TextureAtlasTextureItem& getTextureItem(std::string const&);
	//TextureUVCoordinateSet _parseJSON(Value const&);
};
