// Fill out your copyright notice in the Description page of Project Settings.


#include "SItemChest.h"


void ASItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	ISGameplayInterface::Interact_Implementation(InstigatorPawn);

	chestLidComp->SetRelativeRotation(FRotator(0,0,chestOpenDegree));
}

// Sets default values
ASItemChest::ASItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	chestBaseComp = CreateDefaultSubobject<UStaticMeshComponent>("BaseComp");
	RootComponent = chestBaseComp;

	chestLidComp = CreateDefaultSubobject<UStaticMeshComponent>("LidComp");
	chestLidComp->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void ASItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

