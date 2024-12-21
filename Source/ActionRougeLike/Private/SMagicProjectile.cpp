// Fill out your copyright notice in the Description page of Project Settings.


#include "SMagicProjectile.h"
#include "SMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"




// Sets default values
ASMagicProjectile::ASMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sphereComp = CreateDefaultSubobject<USphereComponent>("ShereComp");
	sphereComp->SetCollisionProfileName("Projectile");
	sphereComp->OnComponentHit.AddDynamic(this,&ASMagicProjectile::OnHit);
	RootComponent = sphereComp;

	effectComp = CreateDefaultSubobject<UNiagaraComponent>("EffectComp");
	effectComp->SetupAttachment(sphereComp);
	effectComp->SetAsset(projectileEffect);
	

	movementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	movementComp->InitialSpeed = 1000.0f;
	movementComp->bRotationFollowsVelocity = true;
	movementComp->bInitialVelocityInLocalSpace = true;

 }

// Called when the game starts or when spawned
void ASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		[this]()
		{
			Destroy();
		},
		10.0f,
		false
		);
}

// Called every frame
void ASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ASMagicProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp,Warning,TEXT("Projectile Hit"));

	effectComp->SetAsset(hitEffect);
	effectComp->Activate();
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		[this]()
		{
			Destroy();
		},
		1.0f,
		false
		);
	

}







