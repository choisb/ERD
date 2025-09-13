#include "ERDItem.h"
#include "Components/TimelineComponent.h"

AERDItem::AERDItem()
	: ItemState(EItemState::Idle)
{
	bEnableSelect = true;
	TimelineComponent = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineComponent"));

	StaticMesh->SetSimulatePhysics(true);
	StaticMesh->SetEnableGravity(true);

}

bool AERDItem::Select()
{
	if (bEnableSelect && ItemState == EItemState::Idle)
	{
		ItemState = EItemState::Selected;
		SetHighlight();
		return true;
	}
	return false;
}

bool AERDItem::Deselect()
{
	if (ItemState == EItemState::Selected)
	{
		ItemState = EItemState::Idle;
		ClearHighlight();
		return true;
	}
	return false;
}

bool AERDItem::PickUp(const FVector& TargetLocation)
{
	if (ItemState == EItemState::Selected)
	{
		StaticMesh->SetSimulatePhysics(false);
		StaticMesh->SetEnableGravity(false);
		ItemState = EItemState::PickedUp;
		PlayPickUpEffect(TargetLocation);
		return true;
	}
	return false;
}

bool AERDItem::Equip(const FVector& TargetLocation)
{
	if (ItemState == EItemState::PickedUp || ItemState == EItemState::Used)
	{
		ItemState = EItemState::Equipped;
		PlayEquipEffect(TargetLocation);
		return true;
	}
	return false;
}

bool AERDItem::Aim(const FVector& TargetLocation)
{
	if (ItemState == EItemState::Equipped)
	{
		ItemState = EItemState::Aimed;
		PlayAimEffect(TargetLocation);
		return true;
	}
	return false;
}

bool AERDItem::Use(const FVector& TargetLocation)
{
	if (ItemState == EItemState::Aimed)
	{
		ItemState = EItemState::Used;
		PlayUseEffect(TargetLocation);
		return true;
	}
	return false;
}

bool AERDItem::Drop()
{
	if (ItemState == EItemState::Aimed)
	{
		StaticMesh->SetSimulatePhysics(true);
		StaticMesh->SetEnableGravity(true);
		ItemState = EItemState::Idle;
		return true;
	}
	return false;
}

bool AERDItem::ThrowAway(const FVector& Direction)
{
	if (ItemState == EItemState::PickedUp)
	{
		StaticMesh->SetSimulatePhysics(true);
		StaticMesh->SetEnableGravity(true);
		StaticMesh->AddImpulse(Direction * ThrowStrength, NAME_None, true);
		ItemState = EItemState::Idle;
		return true;
	}
	return false;
}

bool AERDItem::ShowDetaile()
{
	if (ItemState == EItemState::Used)
	{
		ItemState = EItemState::Detaile;
		return true;
	}
	return false;
}

bool AERDItem::CloseDetaile()
{
	if (ItemState == EItemState::Detaile)
	{
		ItemState = EItemState::Used;
		return true;
	}
	return false;
}

bool AERDItem::Expire()
{
	if (ItemState == EItemState::Used)
	{
		Destroy();
		return true;
	}
	return false;
}
