// Fill out your copyright notice in the Description page of Project Settings.


#include "SInteractionComponent.h"

#include "SGameplayInterface.h"

// Sets default values for this component's properties
USInteractionComponent::USInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



// Called when the game starts
void USInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USInteractionComponent::PrimaryInteract()
{
	float offsetLength =1000.0f;
	FVector end,eyeLocation;
	FRotator eyeRotation;
	FCollisionObjectQueryParams objectQueryParams;
	objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	AActor* myOwner = GetOwner();

	myOwner->GetActorEyesViewPoint(eyeLocation,eyeRotation);

	end = eyeLocation + (eyeRotation.Vector() * offsetLength);

	//FHitResult hit;
	//GetWorld()->LineTraceSingleByObjectType(hit,eyeLocation,end,objectQueryParams);

	TArray<FHitResult> hits;
	float radius = 30.f;
	FCollisionShape shape;
	shape.SetSphere(radius);
	
	bool bBlockingHit = GetWorld()->SweepMultiByObjectType(hits,eyeLocation,end,FQuat::Identity,objectQueryParams,shape);

	FColor color = bBlockingHit?FColor::Green:FColor::Red;
	
	for (FHitResult hit : hits)
	{
		AActor* hitActor = hit.GetActor();
		DrawDebugSphere(GetWorld(),hit.ImpactPoint,radius,32,color,false,2.0f);
		if (hitActor)
		{
			if (hitActor->Implements<USGameplayInterface>())
			{
				APawn* Mypawn = Cast<APawn>(myOwner);
				ISGameplayInterface::Execute_Interact(hitActor,Mypawn);
				break;
			}
		}
		
	}

	DrawDebugLine(GetWorld(),eyeLocation,end,color,false,
		2.0f,0,2.0f);
}
