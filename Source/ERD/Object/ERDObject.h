#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ERDObject.generated.h"

class UStaticMeshComponent;

UCLASS(Abstract)
class AERDObject : public AActor
{
	GENERATED_BODY()

public:
	AERDObject();

	virtual bool Select();
	virtual bool Deselect();

protected:
	void SetHighlight();
	void ClearHighlight();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"), Category = "ERDObject")
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ERDObject")
	bool bEnableSelect = false;
};