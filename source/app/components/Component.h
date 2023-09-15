#ifndef APP_COMPONENTS_COMPONENT_H_
#define APP_COMPONENTS_COMPONENT_H_

class Component
{
protected:
	Component();

public:
	virtual ~Component();

	virtual void Update(int32_t dt);
	virtual const String& GetName() const = 0;

private:
};

#endif // !APP_COMPONENTS_COMPONENT_H_