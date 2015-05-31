#pragma once
#include <string>
#include <vector>
#include "TextureUVCoordinateSet.h"

class TextureAtlasTextureItem
{
public:
	std::string _name;
	std::vector<TextureUVCoordinateSet> _textureUVs;
	int _uvCount;

	TextureAtlasTextureItem();
	TextureAtlasTextureItem(std::string const&, std::vector<TextureUVCoordinateSet> const&);
	TextureAtlasTextureItem(TextureAtlasTextureItem const&);
	~TextureAtlasTextureItem();

	const std::string& getName();
	const TextureUVCoordinateSet& operator[](const int);
	int uvCount();
	//std::iterator<TextureUVCoordinateSet, > begin();
};
