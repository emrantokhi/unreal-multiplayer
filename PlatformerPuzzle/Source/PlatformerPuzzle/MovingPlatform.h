// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMERPUZZLE_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

private:
	FVector StartLocation;
	FVector GlobalTargetLoc;

	UPROPERTY(EditAnywhere);
	float Speed = 20.f;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true));
	FVector TargetLocation;

	void SwitchTargetAndStart();
};
