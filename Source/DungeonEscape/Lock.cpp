// Fill out your copyright notice in the Description page of Project Settings.


#include "Lock.h"
#include "InventoryComponent.h"

static const FName LockItemTag = TEXT("Lock");

// Sets default values
ALock::ALock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComp = CreateDefaultSubobject<USceneComponent>(FName(TEXT("RootComponent")));
	SetRootComponent(RootComp);

	TriggerComp = CreateDefaultSubobject<UTriggerComponent>(FName(TEXT("TriggerComponent")));
	TriggerComp->SetupAttachment(RootComp);

	KeyItemMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("KeyItemMeshComponent")));
	KeyItemMeshComp->SetupAttachment(RootComp);

	Tags.Add(LockItemTag);
}

bool ALock::GetIsKeyPlaced() const
{
	return bIsKeyPlaced;
}

void ALock::SetIsKeyPlaced(bool bNewIsKeyPlaced)
{
	bIsKeyPlaced = bNewIsKeyPlaced;

	TriggerComp->Trigger(GetIsKeyPlaced());
	KeyItemMeshComp->SetVisibility(GetIsKeyPlaced());
}

// Called when the game starts or when spawned
void ALock::BeginPlay()
{
	Super::BeginPlay();

	SetIsKeyPlaced(false);
}

FName ALock::GetRequiredItemId()const
{
	return RequiredItemId;
}

void ALock::Interact_Implementation(AActor* Interactor)
{
	if (!Interactor)
	{
		return;
	}

	UInventoryComponent* InventoryComponent = Interactor->FindComponentByClass<UInventoryComponent>();

	if (!InventoryComponent)
	{
		return;
	}

	if (!GetIsKeyPlaced())
	{
		bool bWasItemRemoved = InventoryComponent->RemoveItem(RequiredItemId);

		if (!bWasItemRemoved)
		{
			return;
		}

		SetIsKeyPlaced(true);
	}
	else
	{
		bool bWasItemAdded = InventoryComponent->AddItem(RequiredItemId);

		if (!bWasItemAdded)
		{
			return;
		}

		SetIsKeyPlaced(false);
	}
}