#include "ERDObject.h"
#include "Components/StaticMeshComponent.h"

AERDObject::AERDObject()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;
}

bool AERDObject::Select()
{
	if (bEnableSelect)
	{
		SetHighlight();
		return true;
	}
	return false;
}

bool AERDObject::Deselect()
{
	ClearHighlight();
	return true;
}

void AERDObject::SetHighlight()
{
	// todo: 추후 구현
}

void AERDObject::ClearHighlight()
{
	// todo: 추후 구현
}

