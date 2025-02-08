#include "Object.h"
#include "CoreMinimal.h"

Object::Object(string _name)
{
	ID = GetUniqueID();
	name = _name += "_" + to_string(ID);
	isUpdated = true;
}
