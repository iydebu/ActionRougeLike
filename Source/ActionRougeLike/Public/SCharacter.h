// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USInteractionComponent;
class UAnimMontage;

UCLASS()
class ACTIONROUGELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere,Category="Attacking")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere,Category="Attacking")
	UAnimMontage* attackAnim;

	FTimerHandle TimerHandle_PrimaryAttack;
	

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere);
	UCameraComponent* cameraComp;

	UPROPERTY(VisibleAnywhere);
	USpringArmComponent* springArmComp;

	UPROPERTY(VisibleAnywhere)
	USInteractionComponent* interactionComp;

	void MoveForward(float value);
	void MoveRight(float value);
	void PrimaryAttack();
	void PrimaryAttack_TimeElapsed();
	void PrimaryInteract();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
