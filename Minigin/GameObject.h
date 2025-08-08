#ifndef GAME_OBJECT_H 
#define GAME_OBJECT_H
#include "Transform.h"
#include "Texture2D.h"
namespace dae
{
	class Texture2D;

	// todo: this should become final.
	class GameObject 
	{
	public:
		virtual void update(float deltaTime);
		void fixedUpdate(float fixedTimeStep); 
		virtual void render() const;

		void setTexture(const std::string& filename);
		void setPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		Texture2D* m_texture{};
	};
}
#endif