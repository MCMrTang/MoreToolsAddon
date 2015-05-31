#pragma once

enum class TextureFile : int
{
	TILES,
	ITEM
};

struct TextureUVCoordinateSet {
	TextureUVCoordinateSet(float, float, float, float, float, float, int, TextureFile);

	TextureUVCoordinateSet();

	float _u0;
	float _v0;
	float _u1;
	float _v1;
	float _texSizeW;
	float _texSizeH;
	int _index;
	TextureFile _file;
	float width() const;
	float height() const;

	void shrink(float);
	float offsetWidth(float, float) const;
	float offsetHeight(float, float) const;
	float offsetWidthPixel(float, float) const;
	float offsetHeightPixel(float, float) const;
	float inverseOffsetWidth(float, float) const;
	float inverseOffsetHeight(float, float) const;

	TextureUVCoordinateSet getFlippedHorizontal() const;
	TextureUVCoordinateSet getFlippedVertically() const;
	TextureUVCoordinateSet offset(float) const;
	TextureUVCoordinateSet subTexture(float, float, int, int) const;

	float asPixelU0() const;
	float asPixelV0() const;
	float asPixelU1() const;
	float asPixelV1() const;
	float pixelSizeVerticalpixelWidth() const;
	float pixelWidth() const;
	float pixelHeight() const;
	float pixelSizeHorizontal() const;
	float pixelSizeVertical() const;
	bool operator<(const TextureUVCoordinateSet&) const;
	int getGlobalIndex() const;
	void fix();

	static TextureUVCoordinateSet fromOldSystem(int);
};
