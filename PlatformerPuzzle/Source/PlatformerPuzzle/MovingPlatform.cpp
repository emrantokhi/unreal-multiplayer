// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (HasAuthority())
	{
		FVector ActorLocation = GetActorLocation();
		FVector Direction = (GlobalTargetLoc - StartLocation).GetSafeNormal();

		//Check to switch the start and target value
		float JourneyLength = (GlobalTargetLoc - StartLocation).Size();
		float JourneyTraveled = (ActorLocation - StartLocation).Size();
		if (JourneyTraveled > JourneyLength)
		{
			SwitchTargetAndStart();
		}

		FVector MoveTo = Direction * Speed * DeltaSeconds;

		SetActorLocation(MoveTo + ActorLocation);
	}
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
		StartLocation = GetActorLocation();
		GlobalTargetLoc = GetTransform().TransformPosition(TargetLocation);
	}
}

void AMovingPlatform::SwitchTargetAndStart()
{
	FVector Holder = GlobalTargetLoc;
	GlobalTargetLoc = StartLocation;
	StartLocation = Holder;
}


