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
	// todo: ���� ����
}

void AERDObject::ClearHighlight()
{
	// todo: ���� ����
}

