// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TriggerComponent.h"
#include "Interactable.h"

#include "Lock.generated.h"

UCLASS()
class DUNGEONESCAPE_API ALock : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALock();

	bool GetIsKeyPlaced() const;
	void SetIsKeyPlaced(bool bNewIsKeyPlaced);
	FName GetRequiredItemId()const;

	virtual void Interact_Implementation(AActor* Interactor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> RootComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UTriggerComponent> TriggerComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> KeyItemMeshComp;

	UPROPERTY(EditAnywhere)
	FName RequiredItemId;

	UPROPERTY(VisibleAnywhere)
	bool bIsKeyPlaced = false;
};
