// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectableItem.h"
#include "InventoryComponent.h"

static const FName CollectableItemTag = TEXT("CollectableItem");

// Sets default values
ACollectableItem::ACollectableItem()
{
	PrimaryActorTick.bCanEverTick = false;

	Tags.Add(CollectableItemTag);
}

FName ACollectableItem::GetItemId() const
{
	return ItemId;
}

void ACollectableItem::Interact_Implementation(AActor* Interactor)
{
	UE_LOG(LogTemp, Display, TEXT("Collectable Item Id is %s"), *ItemId.ToString());

	if (!Interactor)
	{
		return;
	}

	UInventoryComponent* InventoryComponent = Interactor->FindComponentByClass<UInventoryComponent>();
		
	if (!InventoryComponent)
	{
		return;
	}

	bool bWasAddedToInventory = InventoryComponent->AddItem(ItemId);

	if (bWasAddedToInventory)
	{
		this->Destroy();
	}
}

