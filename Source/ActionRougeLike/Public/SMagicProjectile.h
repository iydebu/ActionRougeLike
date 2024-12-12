// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SMagicProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraComponent;
class UNiagaraSystem;

UCLASS()
class ACTIONROUGELIKE_API ASMagicProjectile : public AActor
{
	GENERATED_BODY()

	void CaptureSimCacheAsync();
	
public:	
	// Sets default values for this actor's properties
	ASMagicProjectile();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Niagara");
	UNiagaraSystem* projectile_begin;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Niagara");
	UNiagaraSystem* projectile_end;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* sphereComp;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* movementComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UNiagaraComponent* effectComp;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
