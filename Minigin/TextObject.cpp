#include <stdexcept>
#include <SDL_ttf.h>
#include "TextObject.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"

dae::TextObject::TextObject(const std::string& text, Font* font) 
	: m_needsUpdate(true), m_text(text), m_font(font), m_textTexture(nullptr) 
{ }

void dae::TextObject::update(float )
{
	if (m_needsUpdate)
	{
		const SDL_Color color = { 255,255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_font->getFont(), m_text.c_str(), color);
		if (surf == nullptr) 
		{
			throw std::runtime_error(std::string("render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::getInstance().getSDLRenderer(), surf);
		if (texture == nullptr) 
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_textTexture = std::make_unique<Texture2D>(texture);
		m_needsUpdate = false;
	}
}

void dae::TextObject::render() const
{
	if (m_textTexture != nullptr)
	{
		const auto& pos = m_transform.getPosition();
		Renderer::getInstance().renderTexture(*m_textTexture, pos.x, pos.y);
	}
}

// This implementation uses the "dirty flag" pattern
void dae::TextObject::setText(const std::string& text)
{
	m_text = text;
	m_needsUpdate = true;
}

void dae::TextObject::setPosition(const float x, const float y)
{
	m_transform.setPosition(x, y, 0.0f);
}


