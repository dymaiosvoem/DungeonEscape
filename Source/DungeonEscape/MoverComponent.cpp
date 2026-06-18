// Fill out your copyright notice in the Description page of Project Settings.


#include "MoverComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMoverComponent::UMoverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoverComponent::BeginPlay()
{
	Super::BeginPlay();
	
	AActor* Owner = GetOwner();

	if (!Owner)
	{
		return;
	}

	StartLocation = Owner->GetActorLocation();

	if (MoveTime <= KINDA_SMALL_NUMBER)
	{
		UE_LOG(LogTemp, Warning, TEXT("MoverComponent: MoveTime must be greater than zero"));
		SetShouldMove(false);
		return;
	}

	InterpSpeed = MoveOffset.Length() / MoveTime;
	SetShouldMove(false);
}


// Called every frame
void UMoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector CurrentLocation = GetOwner()->GetActorLocation();
	bReachedTarget = CurrentLocation.Equals(TargetLocation);

	if (!bReachedTarget)
	{
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, InterpSpeed);
		GetOwner()->SetActorLocation(NewLocation);
	}
}

bool UMoverComponent::GetShouldMove() const
{
	return bShouldMove;
}

void UMoverComponent::SetShouldMove(bool bNewShouldMove)
{
	bShouldMove = bNewShouldMove;

	if (bShouldMove)
	{
		TargetLocation = StartLocation + MoveOffset;
	} else
	{
		TargetLocation = StartLocation;
	}
}