#include <stdexcept>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "ResourceManager.h"
#include "Renderer.h"


namespace fs = std::filesystem;

void dae::ResourceManager::init(const std::filesystem::path& dataPath)
{
	m_dataPath = dataPath;

	if (TTF_Init() != 0)
	{
		throw std::runtime_error(std::string("Failed to load support for fonts: ") + SDL_GetError());
	}
}

dae::Texture2D* dae::ResourceManager::loadTexture(const std::string& file)
{
	const auto fullPath = m_dataPath/file;
	const auto filename = fs::path(fullPath).filename().string();
	if(m_pLoadedTextures.find(filename) == m_pLoadedTextures.end())
		m_pLoadedTextures.insert(std::pair(filename,std::make_unique<Texture2D>(fullPath.string())));

	return m_pLoadedTextures.at(filename).get();
}

dae::Font* dae::ResourceManager::loadFont(const std::string& file, uint8_t size)
{
	const auto fullPath = m_dataPath/file;
	const auto filename = fs::path(fullPath).filename().string();
	const auto key = std::pair<std::string, uint8_t>(filename, size);
	if(m_loadedFonts.find(key) == m_loadedFonts.end())
		m_loadedFonts.insert(std::pair(key,std::make_unique<Font>(fullPath.string(), size)));
	return m_loadedFonts.at(key).get();
}
