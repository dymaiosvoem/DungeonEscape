// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoverComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONESCAPE_API UMoverComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoverComponent();

	bool GetShouldMove() const;
	void SetShouldMove(bool bNewShouldMove);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	FVector StartLocation = FVector::ZeroVector;
	FVector TargetLocation = FVector::ZeroVector;

	float InterpSpeed = 0.0f;

	UPROPERTY(EditAnywhere)
	FVector MoveOffset = FVector::ZeroVector;

	UPROPERTY(EditAnywhere)
	float MoveTime = 1.0f;

	UPROPERTY(EditAnywhere)
	bool bShouldMove = false;

	UPROPERTY(VisibleAnywhere)
	bool bReachedTarget = false;
};
