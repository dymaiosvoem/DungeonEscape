// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UInventoryComponent::AddItem(FName ItemId)
{
	if (ItemId.IsNone() || Items.Contains(ItemId))
	{
		return false;
	}

	Items.Add(ItemId);
	return true;
}

bool UInventoryComponent::HasItem(FName ItemId) const
{
	return Items.Contains(ItemId);
}

bool UInventoryComponent::RemoveItem(FName ItemId)
{
	if (ItemId.IsNone() || !Items.Contains(ItemId))
	{
		return false;
	}

	Items.Remove(ItemId);
	return true;
}

