#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <glm.hpp>
namespace dae
{
	class Transform final
	{
	public:
		const glm::vec3& getPosition() const { return m_position; }
		void setPosition(float x, float y, float z);
	private:
		glm::vec3 m_position; 
	};
}
#endif