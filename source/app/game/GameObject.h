#ifndef APP_GAME_GAMEOBJECT_H_
#define APP_GAME_GAMEOBJECT_H_

struct GameObjectConfig;
class Component;

class GameObject
{
public:
	GameObject();
	~GameObject();

	bool				Init(const GameObjectConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);

public:
	template<typename T>
	void AddComponent();

	template<typename T>
	T* GetComponent() const;

	//std::unordered_map<Hash32, Component*>& GetAllComponents();
	std::vector<Component*>& GetAllComponents();

private:
	//std::unordered_map<Hash32, Component*> m_Components;
	std::vector<Component*> m_Components;
};

// =============================================================================
template<typename T>
void GameObject::AddComponent()
{
	const auto& componentName = T::m_Name;

	/*auto it = m_Components.find(componentName.m_Hash);
	AssertReturnIf(it != m_Components.end(), void(),
		"Error, game object does not have " + componentName.m_String);

	m_Components[componentName.m_Hash] = new T;*/

	for (const auto& component : m_Components)
	{
		AssertReturnIf(componentName == component->GetName(), void(),
			"Error, game object does not have " + componentName.m_String);
	}

	m_Components.emplace_back(new T);
}

// =============================================================================
template<typename T>
T* GameObject::GetComponent() const
{
	//TODO instead of this way to check if it has the component, maybe use some mask/flags
	const auto& componentName = T::m_Name;

	/*auto it = m_Components.find(componentName.m_Hash);
	AssertReturnIf(it == m_Components.end(), nullptr,
		"Error, game object does not have " + componentName.m_String);

	return static_cast<T*>(it->second);*/

	for (const auto& component : m_Components)
	{
		if (componentName == component->GetName())
		{
			return static_cast<T*>(component);
		}
	}

	Assert::Assert("Error, game object does not have " + componentName.m_String);
	return nullptr;
}

#endif // !APP_GAME_GAMEOBJECT_H_