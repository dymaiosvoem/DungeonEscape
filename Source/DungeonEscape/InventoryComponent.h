// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Containers/Set.h"

#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONESCAPE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	bool AddItem(FName ItemId);
	bool HasItem(FName ItemId) const;
	bool RemoveItem(FName ItemId);

private:
	UPROPERTY(VisibleAnywhere, Category="Inventory")
	TSet<FName> Items;
};
