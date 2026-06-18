// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "MoverComponent.h"

#include "TriggerComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DUNGEONESCAPE_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UTriggerComponent();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void Trigger(bool bNewTriggerValue);
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> ActorThatHasMoverComponent = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UMoverComponent> MoverComponent = nullptr;

	UPROPERTY(EditAnywhere)
	bool bIsPressurePlate = false;

	UPROPERTY(EditAnywhere)
	FName PressurePlateActivatorTag = TEXT("PressurePlateActivator");

	UPROPERTY(VisibleAnywhere)
	bool bIsTriggered = false;

	TSet<AActor*> ActivatingActors;
};
