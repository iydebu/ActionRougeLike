// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "SItemChest.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
UCLASS()
class ACTIONROUGELIKE_API ASItemChest : public AActor,public ISGameplayInterface
{
	GENERATED_BODY()
	
	void Interact_Implementation(APawn* InstigatorPawn) override;
	
	
	

	
	
public:	
	// Sets default values for this actor's properties
	ASItemChest();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Chest Parameters")
	float chestOpenDegree = -60.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* chestBaseComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* chestLidComp;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
