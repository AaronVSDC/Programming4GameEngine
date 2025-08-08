#ifndef SCENE_H
#define SCENE_H
#include <memory>
#include <vector>

#include "GameObject.h"

namespace dae
{
	class SceneManager; 
	class Scene final
	{
		friend class SceneManager;
	public:
		void add(std::unique_ptr<GameObject> object);
		void remove(std::unique_ptr<GameObject> object);
		void removeAll();

		void update(float deltaTime);
		void fixedUpdate(float fixedTimeStep); 
		void render() const;

		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		explicit Scene(const std::string& name);

		std::string m_name;
		std::vector<std::unique_ptr<GameObject>> m_pObjects{};

		static unsigned int m_idCounter; 
	};

}
#endif SCENE_H