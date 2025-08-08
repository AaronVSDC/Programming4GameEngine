#ifndef TEXTOBJECT_H
#define TEXTOBJECT_H
#include <string>
#include <memory>
#include "GameObject.h"
#include "Transform.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextObject final : public GameObject
	{
	public:
		void update(float deltaTime) override;
		void render() const override;

		void setText(const std::string& text);
		void setPosition(float x, float y);

		TextObject(const std::string& text, Font* font);
		virtual ~TextObject() = default;
		TextObject(const TextObject& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(const TextObject& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;
	private:
		bool m_needsUpdate;
		std::string m_text;
		Transform m_transform{};
		Font* m_font;
		std::unique_ptr<Texture2D> m_textTexture;
	};
}
#endif