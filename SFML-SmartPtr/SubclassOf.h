#pragma once
#include "Macro.h"

template <typename Type>
class SubclassOf
{
	Shared<Type> objectRef;

public:
	FORCEINLINE bool IsValid() const
	{
		return objectRef != nullptr;
	}
	FORCEINLINE Type& GetObject() const
	{
		return *objectRef;
	}

public:
	// Constructeur par d�faut
	SubclassOf() = default;
	// Constructeur qui prend une r�f�rence
	explicit SubclassOf(const Type& _objectRef)
	{
		objectRef = MakeShared<Type>(_objectRef);
	}
	// Constructeur qui prend un pointeur
	explicit SubclassOf(const Type* _objectRef)
	{
		objectRef = MakeShared<Type>(*_objectRef);
	}
	// Constructeur par copie
	SubclassOf(const SubclassOf<Type>& _other)
	{
		objectRef = _other.objectRef;
	}
	// Constructeur par d�placement
	SubclassOf(SubclassOf<Type>&& _other) noexcept
	{
		objectRef = move(_other.objectRef);
	}

	// Op�rateur d'affectation par copie
	SubclassOf<Type>& operator=(const SubclassOf<Type>& _other) 
	{
		if (this != &_other) 
		{
			objectRef = _other.objectRef;
		}

		return *this;
	}
	// Op�rateur d'affectation par d�placement
	SubclassOf<Type>& operator=(SubclassOf<Type>&& _other) noexcept 
	{
		if (this != &_other) 
		{
			objectRef = move(_other.objectRef);
		}

		return *this;
	}
};