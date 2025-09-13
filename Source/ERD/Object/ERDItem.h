#pragma once

#include "CoreMinimal.h"
#include "ERDObject.h"
#include "Components/TimelineComponent.h"
#include "ERDItem.generated.h"

enum class EItemState : uint8
{
	Idle,
	Selected,
	PickedUp,
	Equipped,
	Aimed,
	Detaile,
	Used
};

UCLASS()
class AERDItem : public AERDObject
{
	GENERATED_BODY()

public:
	AERDItem();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ERDObject")
	UTimelineComponent* TimelineComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ERDObject")
	float ThrowStrength = 1000.0f;

private:
	EItemState ItemState;

public:
	virtual bool Select() override;
	virtual bool Deselect() override;
	bool PickUp(const FVector& TargetLocation);
	bool Equip(const FVector& TargetLocation);
	bool Aim(const FVector& TargetLocation);
	bool Drop();
	bool Expire();
	bool Use(const FVector& TargetLocation);
	bool ThrowAway(const FVector& Direction);
	bool ShowDetaile();
	bool CloseDetaile();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void PlayPickUpEffect(const FVector& TargetLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayEquipEffect(const FVector& TargetLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayAimEffect(const FVector& TargetLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayUseEffect(const FVector& TargetLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayExpireEffect();
};