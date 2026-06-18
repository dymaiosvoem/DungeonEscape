// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (ActorThatHasMoverComponent)
	{
		MoverComponent = ActorThatHasMoverComponent->FindComponentByClass<UMoverComponent>();

		if (MoverComponent)
		{
			UE_LOG(LogTemp, Warning, TEXT("Mover component should move"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Actor doesnt have the mover component"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ActorThatHasMoverComponent is nullptr"));
	}

	if (bIsPressurePlate)
	{
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag(PressurePlateActivatorTag))
	{
		ActivatingActors.Add(OtherActor);

		if (!bIsTriggered)
		{
			Trigger(true);
		}
	}
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->ActorHasTag(PressurePlateActivatorTag))
	{
		ActivatingActors.Remove(OtherActor);

		if (bIsTriggered && (ActivatingActors.Num() == 0))
		{
			Trigger(false);
		}
	}
}

void UTriggerComponent::Trigger(bool bNewTriggerValue)
{
	if (!MoverComponent)
	{
		return;
	}

	bIsTriggered = bNewTriggerValue;
	MoverComponent->SetShouldMove(bIsTriggered);
}