#ifndef RENDERER_H 
#define RENDERER_H 
#include <SDL.h>
#include "Singleton.h"

namespace dae
{
	class Texture2D;
	/**
	 * Simple RAII wrapper for the SDL renderer
	 */
	class Renderer final : public Singleton<Renderer>
	{
		SDL_Renderer* m_renderer{};
		SDL_Window* m_window{};
		SDL_Color m_clearColor{};	
	public:
		void init(SDL_Window* window);
		void render() const;
		void destroy();

		void renderTexture(const Texture2D& texture, float x, float y) const;
		void renderTexture(const Texture2D& texture, float x, float y, float width, float height) const;

		SDL_Renderer* getSDLRenderer() const;

		const SDL_Color& getBackgroundColor() const { return m_clearColor; }
		void setBackgroundColor(const SDL_Color& color) { m_clearColor = color; }
	};
}

#endif