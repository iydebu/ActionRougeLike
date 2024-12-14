// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SExplosiveBarrel.generated.h"

class URadialForceComponent;
class UStaticMeshComponent;

UCLASS()
class ACTIONROUGELIKE_API ASExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASExplosiveBarrel();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Explosion Parameters")
	bool isExplode = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Explosion Parameters")
	float impulseForce = 2000.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Explosion Parameters")
	float impulseRadius = 1000.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Explosion Parameters")
	float destroyDelay = 5.0f;
	
	

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	URadialForceComponent* radialForceComp;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* meshComp;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit );

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
