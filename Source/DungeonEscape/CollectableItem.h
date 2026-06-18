// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"

#include "CollectableItem.generated.h"

UCLASS()
class DUNGEONESCAPE_API ACollectableItem : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableItem();

	FName GetItemId() const;

	virtual void Interact_Implementation(AActor* Interactor) override;

private:
	UPROPERTY(EditAnywhere, Category = "Item")
	FName ItemId;
};
