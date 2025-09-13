#pragma once

#include "CoreMinimal.h"
#include "ERDObject.h"
#include "ERDDevice.generated.h"

class AERDItem;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FEffectDelegate);

USTRUCT(BlueprintType)
struct FDeviceItemEffect
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AERDItem* Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FEffectDelegate PlayEffect;
};

UCLASS()
class ERD_API AERDDevice : public AERDObject
{
	GENERATED_BODY()

public:
	AERDDevice();

	void Operate(AERDItem* UsedItem);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Device")
	FDeviceItemEffect CorrectEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object|Device")
	TArray<FDeviceItemEffect> WrongEffects;
};
